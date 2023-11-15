// game_of_life.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "game_of_life.h"

#include "game.hpp"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <commdlg.h>
#include <stb_image.h>
#include <stb_image_write.h>

#include <string>
#include <memory>
#include <format>
#include <utility>
#include <optional>
#include <iostream>

struct resources { 
    HINSTANCE hInstance{};
    std::wstring 
        window_title{},
        window_class{};
};
static float target_fps = 30;
static resources win_resources{};
static game_of_life game{};

static auto grab_resources(HINSTANCE hInstance) -> resources {
    resources res{.hInstance = hInstance};
    int constexpr buffer_max = 32;
    WCHAR buf[buffer_max]{};

    LoadStringW(hInstance, IDS_APP_TITLE,
        buf, buffer_max);
    res.window_title = buf;

    LoadStringW(hInstance, IDC_GAMEOFLIFE, 
        buf, buffer_max);
    res.window_class = buf;

    return res;
}
static auto register_class(HINSTANCE hInstance, WCHAR const* class_name, WNDPROC window_proc) -> ATOM {
    WNDCLASSEX const wcex{
         .cbSize        /**/ = sizeof(WNDCLASSEX),
         .style         /**/ = CS_HREDRAW | CS_VREDRAW,
         .lpfnWndProc   /**/ = window_proc,
         .cbClsExtra    /**/ = 0,
         .cbWndExtra    /**/ = 0,
         .hInstance     /**/ = hInstance,
         .hIcon         /**/ = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_GAMEOFLIFE)),
         .hCursor       /**/ = LoadCursor(nullptr, IDC_ARROW),
         .hbrBackground /**/ = (HBRUSH)(COLOR_WINDOW + 1),
         .lpszMenuName  /**/ = MAKEINTRESOURCEW(IDC_GAMEOFLIFE),
         .lpszClassName /**/ = class_name,
         .hIconSm       /**/ = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL))
    };
    return RegisterClassExW(&wcex);
}
static auto setup_pixel_format(HDC hdc) -> BOOL {
    PIXELFORMATDESCRIPTOR const pfd{
        .nSize = sizeof(pfd),
        .nVersion = 1,
        .dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        .iPixelType = PFD_TYPE_RGBA,
        .cColorBits = 24,
        .cDepthBits = 16,
    };
    int const pf = ChoosePixelFormat(hdc, &pfd);
    return SetPixelFormat(hdc, pf, &pfd);
}
static auto setup_opengl_context(HDC hdc) -> void {
    HGLRC const hglrc = wglCreateContext(hdc);
    wglMakeCurrent(hdc, hglrc);
    gl::set_load_proc([](char const* name) {
        PROC proc = wglGetProcAddress(name);
        printf("Loaded at %p %s\n", proc, name);
        return reinterpret_cast<gl::proc_t>(proc);
    });
}
static auto create_console() -> HWND {
    if (!AllocConsole()) 
        return nullptr;
    FILE* discard_result[1];
    (void)freopen_s(discard_result, "CONIN$", "r", stdin);
    (void)freopen_s(discard_result, "CONOUT$", "w", stdout);
    (void)freopen_s(discard_result, "CONOUT$", "w", stderr);
    puts("Created Console");
    return GetConsoleWindow();
}
static auto reset_game(HWND hwnd) -> void {
    game = { hwnd, game.width, game.height };
    game.build();

    constinit static UINT_PTR timer = 0;
    timer = SetTimer(
        hwnd,
        timer,
        UINT(1'000.0f / target_fps), 
        [](HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
            game.update();
            printf("tik: %d\r", game.tik);
            InvalidateRect(hwnd, nullptr, false);
        });

    puts("Rebuild");
}

using hwnd_deleter = decltype([](HWND hwnd) { return DestroyWindow(hwnd); });
using unique_hwnd = std::unique_ptr<std::remove_pointer_t<HWND>, hwnd_deleter>;
static auto make_hwnd(HINSTANCE hInstance, WCHAR const* window_class, WCHAR const* window_title) -> unique_hwnd {
    return unique_hwnd{ CreateWindowExW(0,
        window_class,
        window_title,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        256 * 2,
        256 * 2,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    ) };
}

// Message handler for about box. generated by vs2022
static auto CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) noexcept -> INT_PTR {
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

static auto APIENTRY opengl_debug(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* message, const void* userParam) noexcept -> void {
    using namespace std::literals;
    if (severity == GL_DEBUG_SEVERITY_NOTIFICATION) return;
    std::string_view const str_source   /**/{ 
        [source] { switch (source) {
        case GL_DEBUG_SOURCE_API:             /**/ return "API"sv;
        case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   /**/ return "Window System"sv;
        case GL_DEBUG_SOURCE_SHADER_COMPILER: /**/ return "Shader Compiler"sv;
        case GL_DEBUG_SOURCE_THIRD_PARTY:     /**/ return "Third Party"sv;
        case GL_DEBUG_SOURCE_APPLICATION:     /**/ return "Application"sv;
        case GL_DEBUG_SOURCE_OTHER:           /**/ return "Other"sv;
        default: return "???"sv;
        } }() 
    };
    std::string_view const str_type     /**/{ 
        [type] { switch (type) {
        case GL_DEBUG_TYPE_ERROR:               /**/ return "Error"sv;
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: /**/ return "Deprecated Behavior"sv;
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  /**/ return "Undefined Behavior"sv;
        case GL_DEBUG_TYPE_PORTABILITY:         /**/ return "Portability"sv;
        case GL_DEBUG_TYPE_PERFORMANCE:         /**/ return "Performance"sv;
        case GL_DEBUG_TYPE_MARKER:              /**/ return "Marker"sv;
        case GL_DEBUG_TYPE_PUSH_GROUP:          /**/ return "Push Group"sv;
        case GL_DEBUG_TYPE_POP_GROUP:           /**/ return "Pop Group"sv;
        case GL_DEBUG_TYPE_OTHER:               /**/ return "Other"sv;
        default: return "???"sv;
        } }() 
    };
    std::string_view const str_severity /**/{ 
        [severity] { switch (severity) {
        case GL_DEBUG_SEVERITY_HIGH:         /**/ return "High"sv;
        case GL_DEBUG_SEVERITY_MEDIUM:       /**/ return "Medium"sv;
        case GL_DEBUG_SEVERITY_LOW:          /**/ return "Low"sv;
        case GL_DEBUG_SEVERITY_NOTIFICATION: /**/ return "Notification"sv;
        default: return "???"sv;
        } }() 
    };
    std::string_view const str_message  /**/{ 
        message, static_cast<size_t>(length) 
    };
    std::string      const error        /**/{ std::format("|"
        "| GL Error : {:<8} |"
        "| Source   : {:<8} |"
        "| Type     : {:<8} |"
        "| Severity : {:<8} |"
        "| Message  : {:<8} |"
        "|\n",
        id,
        str_source,
        str_type,
        str_severity,
        str_message
    ) };
    static no_repeat no_repeat{};
    std::cerr << no_repeat(error);
}
static auto APIENTRY wm_command(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) noexcept -> LRESULT {
    switch (LOWORD(wparam)) {
    case IDM_ABOUT: {
        DialogBox(win_resources.hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), hwnd, About);
    } break;
    case IDM_DEBUG_CONSOLE: {
        (void)create_console();

        HWND console = GetConsoleWindow();
        BOOL shown = !IsWindowVisible(console);
        HMENU menu = GetMenu(hwnd);

        ShowWindow(console, shown ? SW_SHOW : SW_HIDE);
        CheckMenuItem(menu, IDM_DEBUG_CONSOLE, shown ? MF_CHECKED : MF_UNCHECKED);
        printf("%s console\n", shown ? "Show" : "Hide");
    } break;
    case IDM_DEBUG_LOADIMAGE: {
        std::string const path = [&]() -> std::string {
            WCHAR lpstrFile[MAX_PATH]{ L'\0' };
            OPENFILENAME ofn{
                .lStructSize = sizeof(ofn),
                .hwndOwner = hwnd,
                .lpstrFilter = L"Image Files (*.bmp; *.jpg; *.jpeg; *.png)\0*.bmp;*.jpg;*.jpeg;*.png\0All Files (*.*)\0*.*\0",
                .nFilterIndex = 1,
                .lpstrFile = lpstrFile,
                .nMaxFile = MAX_PATH,
                .lpstrFileTitle = nullptr,
                .nMaxFileTitle = 0,
                .lpstrInitialDir = nullptr,
                .Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST,
            };
            if (!GetOpenFileName(&ofn))
                return "";
            return std::ranges::to<std::string>(lpstrFile);
        }();
        if (path.empty()) {
            puts("Open file dialog canceled");
            break;
        }

        int width{}, height{}, comp{};
        using unique_image = std::unique_ptr < stbi_uc, decltype([](auto* p) { return stbi_image_free(p); }) > ;
        unique_image const image{ 
            stbi_load(path.c_str(), &width, &height, &comp, 1) 
        };
        static constexpr char error_fmt[] = "Failed to load image '%s' because '%s'\n";
        if (!image) {
            printf(error_fmt, path.c_str(), "stbi_load returned null");
            break;
        }
        if (comp != 1) {
            printf(error_fmt, path.c_str(), "Image did not have exactly 1 pixel component");
            break;
        }

        game.width = width;
        game.height = height;
        game.build_textures();
        try { 
            std::span const pixels{ image.get(), static_cast<size_t>(width) * height };
            game.upload_image(pixels); 
        }
        catch (std::range_error error) { 
            printf(error_fmt, path.c_str(), error.what());
            break;
        }

        printf("Loaded image '%s'\n", path.c_str());
    } break;
    case IDM_DEBUG_SAVEIMAGE: {
        std::string const path = [&]() -> std::string {
            WCHAR lpstrFile[MAX_PATH]{ L'\0' };
            OPENFILENAME ofn{
                .lStructSize = sizeof(ofn),
                .hwndOwner = NULL,
                .lpstrFilter = L"BMP Files (*.bmp)\0*.bmp\0All Files (*.*)\0*.*\0",
                .lpstrFile = lpstrFile,
                .nMaxFile = MAX_PATH,
                .Flags = OFN_EXPLORER | OFN_OVERWRITEPROMPT,
            };
            if (!GetSaveFileNameW(&ofn))
                return "";
            return std::ranges::to<std::string>(lpstrFile);
        }();
        if (path.empty()) {
            puts("Save file dialog canceled");
            break;
        }

        static constexpr char error_fmt[] = "Failed to save image '%s' because '%s'\n";
        if (std::vector const pixels = game.download_image();
            !stbi_write_bmp(path.c_str(), static_cast<int>(game.width), static_cast<int>(game.height), 1, pixels.data())) {
            printf(error_fmt, path.c_str(), "stbi_write_bmp returned false");
            break;
        }

        printf("Saved image '%s'\n", path.c_str());
    } break;
    case IDM_DEBUG_REBUILD_ALL: {
        reset_game(hwnd);
    } break;
    case IDM_DEBUG_REBUILD_SHADERS: {
        game.build_shaders();
        puts("Build shader");
    } break;
    case IDM_DEBUG_REBUILD_TEXTURES: {
        game.build_textures();
        game.upload_noise_image();
        puts("Build texture");
    } break;
    case IDM_DEBUG_SETVALUE_UPS: {
        // TODO
    } break;
    case IDM_DEBUG_SETVALUE_GRIDSIZE: {
        // TODO
    } break;
    case IDM_EXIT: {
        DestroyWindow(hwnd);
    } break;
    default: return DefWindowProc(hwnd, message, wparam, lparam);
    }
    return 0;
}
static auto APIENTRY window_proc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) noexcept -> LRESULT {
    switch (message) {
    case WM_CREATE: {
        HDC const hdc = GetDC(hwnd);
        setup_pixel_format(hdc);
        setup_opengl_context(hdc);
        ReleaseDC(hwnd, hdc);
        puts("OpenGL context ready");

        gl::glEnable(GL_DEBUG_OUTPUT);
        gl::glDebugMessageCallback(opengl_debug, hwnd);

        reset_game(hwnd);
    } break;
    case WM_CLOSE: {
        game = {};
        wglMakeCurrent(nullptr, nullptr);
        wglDeleteContext(wglGetCurrentContext());
        DestroyWindow(hwnd);
    } break;
    case WM_DESTROY: {
        PostQuitMessage(0);
    } break;
    case WM_COMMAND: {
        return wm_command(hwnd, message, wparam, lparam);
    } break;
    case WM_ERASEBKGND: {
        return TRUE;
    } break;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        game.draw();
        SwapBuffers(hdc);
        EndPaint(hwnd, &ps);
    } break;
    case WM_SIZE: {
        auto const w = LOWORD(lparam);
        auto const h = HIWORD(lparam);
        gl::glViewport(0, 0, w, h);
    } break;
    default: return DefWindowProc(hwnd, message, wparam, lparam);
    }
    return 0;
}

int APIENTRY wWinMain(_In_     HINSTANCE hInstance,
    [[maybe_unused ]] _In_opt_ HINSTANCE hPrevInstance,
    [[maybe_unused ]] _In_     LPWSTR    lpCmdLine,
    /*             */ _In_     int       nCmdShow) {

    (void)create_console();
    puts("Program Start!");

    win_resources = grab_resources(hInstance);
    register_class(hInstance, win_resources.window_class.c_str(), window_proc);
    auto hwnd = make_hwnd(hInstance, win_resources.window_class.c_str(), win_resources.window_title.c_str());
    if (!hwnd.get())
        return EXIT_FAILURE;

    ShowWindow(hwnd.get(), nCmdShow);
    UpdateWindow(hwnd.get());

    auto const hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GAMEOFLIFE));

    MSG msg{};
    while (GetMessage(&msg, nullptr, 0, 0))
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
            if (msg.message == WM_QUIT) 
                exit(0);
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

    return static_cast<int>(msg.wParam);
}
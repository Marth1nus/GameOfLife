#ifndef GL_H
#define GL_H

#include <cstdint>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <GL/gl.h>

#ifndef GLF_IMPLIMENT_FUNC
#define GLF_IMPLIMENT_FUNC(name)
#endif // GLF_IMPLIMENT_FUNC

// define a opengl extention func
#define GLF_(name, ...)       \
using name##_t = __VA_ARGS__; \
extern name##_t name;         \
GLF_IMPLIMENT_FUNC(name);     \

// define a opengl 1 func
#define GLD_(name, ...)       \
using name##_t = __VA_ARGS__; \
using ::name;                 \

namespace gl {

	using proc_t = void(APIENTRY*)(void);
	using load_proc_t = proc_t(APIENTRY*)(char const* proc_name);
	extern load_proc_t load_proc;

	void set_load_proc(load_proc_t load_proc);

    using ::GLenum;
    using ::GLboolean;
    using ::GLbitfield;
    using ::GLbyte;
    using ::GLshort;
    using ::GLint;
    using ::GLsizei;
    using ::GLubyte;
    using ::GLushort;
    using ::GLuint;
    using ::GLfloat;
    using ::GLclampf;
    using ::GLdouble;
    using ::GLclampd;
    using ::GLvoid;

    using GLchar 	 /**/ = char;
    using GLint64 	 /**/ = int64_t;
    using GLuchar 	 /**/ = unsigned char;
    using GLuint64 	 /**/ = uint64_t;
    using GLfixed 	 /**/ = int32_t;
    using GLintptr 	 /**/ = size_t;
    using GLuintptr	 /**/ = size_t;
    using GLsizeiptr /**/ = size_t;
    using GLsync 	 /**/ = size_t;
    using GLbitfield /**/ = uint32_t;
    using GLhalf 	 /**/ = uint16_t;

    using DEBUGPROC = void (APIENTRY*)(
        GLenum source,
        GLenum type,
        GLuint id,
        GLenum severity,
        GLsizei length,
        const GLchar* message,
        const void* userParam);





    /// Textures                                   


    /// https://docs.gl/gl4/glActiveTexture        
    GLF_(glActiveTexture,                               /**/ void(APIENTRY*)(GLenum texture))
    /// https://docs.gl/gl4/glBindImageTexture     
    GLF_(glBindImageTexture,                            /**/ void(APIENTRY*)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format))
    /// https://docs.gl/gl4/glBindImageTextures    
    GLF_(glBindImageTextures,                           /**/ void(APIENTRY*)(GLuint first, GLsizei count, const GLuint* textures))
    /// https://docs.gl/gl4/glBindTexture          
    GLF_(glBindTexture,                                 /**/ void(APIENTRY*)(GLenum target, GLuint texture))
    /// https://docs.gl/gl4/glBindTextureUnit      
    GLF_(glBindTextureUnit,                             /**/ void(APIENTRY*)(GLuint unit, GLuint texture))
    /// https://docs.gl/gl4/glBindTextures         
    GLF_(glBindTextures,                                /**/ void(APIENTRY*)(GLuint first, GLsizei count, const GLuint* textures))
    /// https://docs.gl/gl4/glClearTexImage        
    GLF_(glClearTexImage,                               /**/ void(APIENTRY*)(GLuint texture, GLint level, GLenum format, GLenum type, const void* data))
    /// https://docs.gl/gl4/glClearTexSubImage     
    GLF_(glClearTexSubImage,                            /**/ void(APIENTRY*)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data))
    /// https://docs.gl/gl4/glCompressedTexImage1D 
    GLF_(glCompressedTexImage1D,                        /**/ void(APIENTRY*)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid* data))
    /// https://docs.gl/gl4/glCompressedTexImage2D 
    GLF_(glCompressedTexImage2D,                        /**/ void(APIENTRY*)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data))
    /// https://docs.gl/gl4/glCompressedTexImage3D 
    GLF_(glCompressedTexImage3D,                        /**/ void(APIENTRY*)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* data))
    /// https://docs.gl/gl4/glCompressedTexSubImage1D
    GLF_(glCompressedTexSubImage1D,                     /**/ void(APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* data))
    GLF_(glCompressedTextureSubImage1D,                 /**/ void(APIENTRY*)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data))
    /// https://docs.gl/gl4/glCompressedTexSubImage2D
    GLF_(glCompressedTexSubImage2D,                     /**/ void(APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data))
    GLF_(glCompressedTextureSubImage2D,                 /**/ void(APIENTRY*)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data))
    /// https://docs.gl/gl4/glCompressedTexSubImage3D
    GLF_(glCompressedTexSubImage3D,                     /**/ void(APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* data))
    GLF_(glCompressedTextureSubImage3D,                 /**/ void(APIENTRY*)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data))
    /// https://docs.gl/gl4/glCopyImageSubData     
    GLF_(glCopyImageSubData,                            /**/ void(APIENTRY*)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth))
    /// https://docs.gl/gl4/glCopyTexImage1D       
    GLF_(glCopyTexImage1D,                              /**/ void(APIENTRY*)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border))
    /// https://docs.gl/gl4/glCopyTexImage2D       
    GLF_(glCopyTexImage2D,                              /**/ void(APIENTRY*)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border))
    /// https://docs.gl/gl4/glCopyTexSubImage1D    
    GLF_(glCopyTexSubImage1D,                           /**/ void(APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width))
    GLF_(glCopyTextureSubImage1D,                       /**/ void(APIENTRY*)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width))
    /// https://docs.gl/gl4/glCopyTexSubImage2D    
    GLF_(glCopyTexSubImage2D,                           /**/ void(APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height))
    GLF_(glCopyTextureSubImage2D,                       /**/ void(APIENTRY*)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height))
    /// https://docs.gl/gl4/glCopyTexSubImage3D    
    GLF_(glCopyTexSubImage3D,                           /**/ void(APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height))
    GLF_(glCopyTextureSubImage3D,                       /**/ void(APIENTRY*)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height))
    /// https://docs.gl/gl4/glCreateTextures       
    GLF_(glCreateTextures,                              /**/ void(APIENTRY*)(GLenum target, GLsizei n, GLuint* textures))
    /// https://docs.gl/gl4/glDeleteTextures       
    GLD_(glDeleteTextures,                              /**/ void(APIENTRY*)(GLsizei n, const GLuint* textures))
    /// https://docs.gl/gl4/glGenTextures          
    GLF_(glGenTextures,                                 /**/ void(APIENTRY*)(GLsizei n, GLuint* textures))
    /// https://docs.gl/gl4/glGetCompressedTexImage
    GLF_(glGetCompressedTexImage,                       /**/ void(APIENTRY*)(GLenum target, GLint level, GLvoid* pixels))
    GLF_(glGetnCompressedTexImage,                      /**/ void(APIENTRY*)(GLenum target, GLint level, GLsizei bufSize, void* pixels))
    GLF_(glGetCompressedTextureImage,                   /**/ void(APIENTRY*)(GLuint texture, GLint level, GLsizei bufSize, void* pixels))
    /// https://docs.gl/gl4/glGetCompressedTextureSubImage
    GLF_(glGetCompressedTextureSubImage,                /**/ void(APIENTRY*)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels))
    /// https://docs.gl/gl4/glGetTexImage          
    GLF_(glGetTexImage,                                 /**/ void(APIENTRY*)(GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels))
    GLF_(glGetnTexImage,                                /**/ void(APIENTRY*)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels))
    GLF_(glGetTextureImage,                             /**/ void(APIENTRY*)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels))
    /// https://docs.gl/gl4/glGetTexLevelParameter 
    GLF_(glGetTexLevelParameterfv,                      /**/ void(APIENTRY*)(GLenum target, GLint level, GLenum pname, GLfloat* params))
    GLF_(glGetTexLevelParameteriv,                      /**/ void(APIENTRY*)(GLenum target, GLint level, GLenum pname, GLint* params))
    GLF_(glGetTextureLevelParameterfv,                  /**/ void(APIENTRY*)(GLuint texture, GLint level, GLenum pname, GLfloat* params))
    GLF_(glGetTextureLevelParameteriv,                  /**/ void(APIENTRY*)(GLuint texture, GLint level, GLenum pname, GLint* params))
    /// https://docs.gl/gl4/glGetTexParameter      
    GLF_(glGetTexParameterfv,                           /**/ void(APIENTRY*)(GLenum target, GLenum pname, GLfloat* params))
    GLF_(glGetTexParameteriv,                           /**/ void(APIENTRY*)(GLenum target, GLenum pname, GLint* params))
    GLF_(glGetTexParameterIiv,                          /**/ void(APIENTRY*)(GLenum target, GLenum pname, GLint* params))
    GLF_(glGetTexParameterIuiv,                         /**/ void(APIENTRY*)(GLenum target, GLenum pname, GLuint* params))
    GLF_(glGetTextureParameterfv,                       /**/ void(APIENTRY*)(GLuint texture, GLenum pname, GLfloat* params))
    GLF_(glGetTextureParameteriv,                       /**/ void(APIENTRY*)(GLuint texture, GLenum pname, GLint* params))
    GLF_(glGetTextureParameterIiv,                      /**/ void(APIENTRY*)(GLuint texture, GLenum pname, GLint* params))
    GLF_(glGetTextureParameterIuiv,                     /**/ void(APIENTRY*)(GLuint texture, GLenum pname, GLuint* params))
    /// https://docs.gl/gl4/glGetTextureSubImage   
    GLF_(glGetTextureSubImage,                          /**/ void(APIENTRY*)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels))
    /// https://docs.gl/gl4/glInvalidateTexImage   
    GLF_(glInvalidateTexImage,                          /**/ void(APIENTRY*)(GLuint texture, GLint level))
    /// https://docs.gl/gl4/glInvalidateTexSubImage
    GLF_(glInvalidateTexSubImage,                       /**/ void(APIENTRY*)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth))
    /// https://docs.gl/gl4/glIsTexture            
    GLF_(glIsTexture,                                   /**/ GLboolean(APIENTRY*)(GLuint texture))
    /// https://docs.gl/gl4/glTexBuffer            
    GLF_(glTexBuffer,                                   /**/ void(APIENTRY*)(GLenum target, GLenum internalFormat, GLuint buffer))
    GLF_(glTextureBuffer,                               /**/ void(APIENTRY*)(GLuint texture, GLenum internalformat, GLuint buffer))
    /// https://docs.gl/gl4/glTexBufferRange       
    GLF_(glTexBufferRange,                              /**/ void(APIENTRY*)(GLenum target, GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizeiptr size))
    GLF_(glTextureBufferRange,                          /**/ void(APIENTRY*)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizei size))
    /// https://docs.gl/gl4/glTexImage1D           
    GLF_(glTexImage1D,                                  /**/ void(APIENTRY*)(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid* data))
    /// https://docs.gl/gl4/glTexImage2D           
    GLF_(glTexImage2D,                                  /**/ void(APIENTRY*)(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* data))
    /// https://docs.gl/gl4/glTexImage2DMultisample
    GLF_(glTexImage2DMultisample,                       /**/ void(APIENTRY*)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations))
    /// https://docs.gl/gl4/glTexImage3D           
    GLF_(glTexImage3D,                                  /**/ void(APIENTRY*)(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* data))
    /// https://docs.gl/gl4/glTexImage3DMultisample
    GLF_(glTexImage3DMultisample,                       /**/ void(APIENTRY*)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations))
    /// https://docs.gl/gl4/glTexParameter         
    GLF_(glTexParameterf,                               /**/ void(APIENTRY*)(GLenum target, GLenum pname, GLfloat param))
    GLF_(glTexParameteri,                               /**/ void(APIENTRY*)(GLenum target, GLenum pname, GLint param))
    GLF_(glTextureParameterf,                           /**/ void(APIENTRY*)(GLuint texture, GLenum pname, GLfloat param))
    GLF_(glTextureParameteri,                           /**/ void(APIENTRY*)(GLuint texture, GLenum pname, GLint param))
    GLF_(glTexParameterfv,                              /**/ void(APIENTRY*)(GLenum target, GLenum pname, const GLfloat* params))
    GLF_(glTexParameteriv,                              /**/ void(APIENTRY*)(GLenum target, GLenum pname, const GLint* params))
    GLF_(glTexParameterIiv,                             /**/ void(APIENTRY*)(GLenum target, GLenum pname, const GLint* params))
    GLF_(glTexParameterIuiv,                            /**/ void(APIENTRY*)(GLenum target, GLenum pname, const GLuint* params))
    GLF_(glTextureParameterfv,                          /**/ void(APIENTRY*)(GLuint texture, GLenum pname, const GLfloat* paramtexture))
    GLF_(glTextureParameteriv,                          /**/ void(APIENTRY*)(GLuint texture, GLenum pname, const GLint* param))
    GLF_(glTextureParameterIiv,                         /**/ void(APIENTRY*)(GLuint texture, GLenum pname, const GLint* params))
    GLF_(glTextureParameterIuiv,                        /**/ void(APIENTRY*)(GLuint texture, GLenum pname, const GLuint* params))
    /// https://docs.gl/gl4/glTexStorage1D         
    GLF_(glTexStorage1D,                                /**/ void(APIENTRY*)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width))
    GLF_(glTextureStorage1D,                            /**/ void(APIENTRY*)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width))
    /// https://docs.gl/gl4/glTexStorage2D         
    GLF_(glTexStorage2D,                                /**/ void(APIENTRY*)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height))
    GLF_(glTextureStorage2D,                            /**/ void(APIENTRY*)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height))
    /// https://docs.gl/gl4/glTexStorage2DMultisample
    GLF_(glTexStorage2DMultisample,                     /**/ void(APIENTRY*)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations))
    GLF_(glTextureStorage2DMultisample,                 /**/ void(APIENTRY*)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations))
    /// https://docs.gl/gl4/glTexStorage3D         
    GLF_(glTexStorage3D,                                /**/ void(APIENTRY*)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth))
    GLF_(glTextureStorage3D,                            /**/ void(APIENTRY*)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth))
    /// https://docs.gl/gl4/glTexStorage3DMultisample
    GLF_(glTexStorage3DMultisample,                     /**/ void(APIENTRY*)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations))
    GLF_(glTextureStorage3DMultisample,                 /**/ void(APIENTRY*)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations))
    /// https://docs.gl/gl4/glTexSubImage1D        
    GLF_(glTexSubImage1D,                               /**/ void(APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid* pixels))
    GLF_(glTextureSubImage1D,                           /**/ void(APIENTRY*)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels))
    /// https://docs.gl/gl4/glTexSubImage2D        
    GLF_(glTexSubImage2D,                               /**/ void(APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels))
    GLF_(glTextureSubImage2D,                           /**/ void(APIENTRY*)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels))
    /// https://docs.gl/gl4/glTexSubImage3D        
    GLF_(glTexSubImage3D,                               /**/ void(APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels))
    GLF_(glTextureSubImage3D,                           /**/ void(APIENTRY*)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels))
    /// https://docs.gl/gl4/glTextureView          
    GLF_(glTextureView,                                 /**/ void(APIENTRY*)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers))








    /// Rendering                                  


    /// https://docs.gl/gl4/glClear                
    GLD_(glClear,                                       /**/ void(APIENTRY*)(GLbitfield mask))
    /// https://docs.gl/gl4/glClearBuffer          
    GLF_(glClearBufferiv,                               /**/ void(APIENTRY*)(GLenum buffer, GLint drawbuffer, const GLint* value))
    GLF_(glClearBufferuiv,                              /**/ void(APIENTRY*)(GLenum buffer, GLint drawbuffer, const GLuint* value))
    GLF_(glClearBufferfv,                               /**/ void(APIENTRY*)(GLenum buffer, GLint drawbuffer, const GLfloat* value))
    GLF_(glClearBufferfi,                               /**/ void(APIENTRY*)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil))
    GLF_(glClearNamedFramebufferiv,                     /**/ void(APIENTRY*)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value))
    GLF_(glClearNamedFramebufferuiv,                    /**/ void(APIENTRY*)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value))
    GLF_(glClearNamedFramebufferfv,                     /**/ void(APIENTRY*)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value))
    GLF_(glClearNamedFramebufferfi,                     /**/ void(APIENTRY*)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat depth, GLint stencil))
    /// https://docs.gl/gl4/glClearColor           
    GLD_(glClearColor,                                  /**/ void(APIENTRY*)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha))
    /// https://docs.gl/gl4/glClearDepth           
    GLF_(glClearDepth,                                  /**/ void(APIENTRY*)(GLdouble depth))
    GLF_(glClearDepthf,                                 /**/ void(APIENTRY*)(GLfloat depth))
    /// https://docs.gl/gl4/glClearStencil         
    GLF_(glClearStencil,                                /**/ void(APIENTRY*)(GLint s))
    /// https://docs.gl/gl4/glDrawBuffer           
    GLF_(glDrawBuffer,                                  /**/ void(APIENTRY*)(GLenum buf))
    GLF_(glNamedFramebufferDrawBuffer,                  /**/ void(APIENTRY*)(GLuint framebuffer, GLenum buf))
    /// https://docs.gl/gl4/glFinish               
    GLF_(glFinish,                                      /**/ void(APIENTRY*)(void))
    /// https://docs.gl/gl4/glFlush                
    GLF_(glFlush,                                       /**/ void(APIENTRY*)(void))
    /// https://docs.gl/gl4/glReadBuffer           
    GLF_(glReadBuffer,                                  /**/ void(APIENTRY*)(GLenum mode))
    GLF_(glNamedFramebufferReadBuffer,                  /**/ void(APIENTRY*)(GLuint framebuffer, GLenum mode))
    /// https://docs.gl/gl4/glReadPixels           
    GLF_(glReadPixels,                                  /**/ void(APIENTRY*)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* data))
    GLF_(glReadnPixels,                                 /**/ void(APIENTRY*)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data))








    /// FrameBuffers                               


    /// https://docs.gl/gl4/glBindFramebuffer      
    GLF_(glBindFramebuffer,                             /**/ void(APIENTRY*)(GLenum target, GLuint framebuffer))
    /// https://docs.gl/gl4/glBindRenderbuffer     
    GLF_(glBindRenderbuffer,                            /**/ void(APIENTRY*)(GLenum target, GLuint renderbuffer))
    /// https://docs.gl/gl4/glBlitFramebuffer      
    GLF_(glBlitFramebuffer,                             /**/ void(APIENTRY*)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter))
    GLF_(glBlitNamedFramebuffer,                        /**/ void(APIENTRY*)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter))
    /// https://docs.gl/gl4/glCheckFramebufferStatus
    GLF_(glCheckFramebufferStatus,                      /**/ GLenum(APIENTRY*)(GLenum target))
    GLF_(glCheckNamedFramebufferStatus,                 /**/ GLenum(APIENTRY*)(GLuint framebuffer, GLenum target))
    /// https://docs.gl/gl4/glCreateFramebuffers   
    GLF_(glCreateFramebuffers,                          /**/ void(APIENTRY*)(GLsizei n, GLuint* ids))
    /// https://docs.gl/gl4/glCreateRenderbuffers  
    GLF_(glCreateRenderbuffers,                         /**/ void(APIENTRY*)(GLsizei n, GLuint* renderbuffers))
    /// https://docs.gl/gl4/glDeleteFramebuffers   
    GLF_(glDeleteFramebuffers,                          /**/ void(APIENTRY*)(GLsizei n, GLuint* framebuffers))
    /// https://docs.gl/gl4/glDeleteRenderbuffers  
    GLF_(glDeleteRenderbuffers,                         /**/ void(APIENTRY*)(GLsizei n, GLuint* renderbuffers))
    /// https://docs.gl/gl4/glDrawBuffers          
    GLF_(glDrawBuffers,                                 /**/ void(APIENTRY*)(GLsizei n, const GLenum* bufs))
    GLF_(glNamedFramebufferDrawBuffers,                 /**/ void(APIENTRY*)(GLuint framebuffer, GLsizei n, const GLenum* bufs))
    /// https://docs.gl/gl4/glFramebufferParameteri
    GLF_(glFramebufferParameteri,                       /**/ void(APIENTRY*)(GLenum target, GLenum pname, GLint param))
    GLF_(glNamedFramebufferParameteri,                  /**/ void(APIENTRY*)(GLuint framebuffer, GLenum pname, GLint param))
    /// https://docs.gl/gl4/glFramebufferRenderbuffer
    GLF_(glFramebufferRenderbuffer,                     /**/ void(APIENTRY*)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer))
    GLF_(glNamedFramebufferRenderbuffer,                /**/ void(APIENTRY*)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer))
    /// https://docs.gl/gl4/glFramebufferTexture   
    GLF_(glFramebufferTexture,                          /**/ void(APIENTRY*)(GLenum target, GLenum attachment, GLuint texture, GLint level))
    GLF_(glFramebufferTexture1D,                        /**/ void(APIENTRY*)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level))
    GLF_(glFramebufferTexture2D,                        /**/ void(APIENTRY*)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level))
    GLF_(glFramebufferTexture3D,                        /**/ void(APIENTRY*)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint layer))
    GLF_(glNamedFramebufferTexture,                     /**/ void(APIENTRY*)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level))
    /// https://docs.gl/gl4/glFramebufferTextureLayer
    GLF_(glFramebufferTextureLayer,                     /**/ void(APIENTRY*)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer))
    GLF_(glNamedFramebufferTextureLayer,                /**/ void(APIENTRY*)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer))
    /// https://docs.gl/gl4/glGenFramebuffers      
    GLF_(glGenFramebuffers,                             /**/ void(APIENTRY*)(GLsizei n, GLuint* ids))
    /// https://docs.gl/gl4/glGenRenderbuffers     
    GLF_(glGenRenderbuffers,                            /**/ void(APIENTRY*)(GLsizei n, GLuint* renderbuffers))
    /// https://docs.gl/gl4/glGenerateMipmap       
    GLF_(glGenerateMipmap,                              /**/ void(APIENTRY*)(GLenum target))
    GLF_(glGenerateTextureMipmap,                       /**/ void(APIENTRY*)(GLuint texture))
    /// https://docs.gl/gl4/glGetFramebufferAttachmentParameter
    GLF_(glGetFramebufferAttachmentParameteriv,         /**/ void(APIENTRY*)(GLenum target, GLenum attachment, GLenum pname, GLint* params))
    GLF_(glGetNamedFramebufferAttachmentParameteriv,    /**/ void(APIENTRY*)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params))
    /// https://docs.gl/gl4/glGetFramebufferParameter
    GLF_(glGetFramebufferParameteriv,                   /**/ void(APIENTRY*)(GLenum target, GLenum pname, GLint* params))
    GLF_(glGetNamedFramebufferParameteriv,              /**/ void(APIENTRY*)(GLuint framebuffer, GLenum pname, GLint* param))
    /// https://docs.gl/gl4/glGetRenderbufferParameter
    GLF_(glGetRenderbufferParameteriv,                  /**/ void(APIENTRY*)(GLenum target, GLenum pname, GLint* params))
    GLF_(glGetNamedRenderbufferParameteriv,             /**/ void(APIENTRY*)(GLuint renderbuffer, GLenum pname, GLint* params))
    /// https://docs.gl/gl4/glInvalidateFramebuffer
    GLF_(glInvalidateFramebuffer,                       /**/ void(APIENTRY*)(GLenum target, GLsizei numAttachments, const GLenum* attachments))
    GLF_(glInvalidateNamedFramebufferData,              /**/ void(APIENTRY*)(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments))
    /// https://docs.gl/gl4/glInvalidateSubFramebuffer
    GLF_(glInvalidateSubFramebuffer,                    /**/ void(APIENTRY*)(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLint width, GLint height))
    GLF_(glInvalidateNamedFramebufferSubData,           /**/ void(APIENTRY*)(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height))
    /// https://docs.gl/gl4/glIsFramebuffer        
    GLF_(glIsFramebuffer,                               /**/ GLboolean(APIENTRY*)(GLuint framebuffer))
    /// https://docs.gl/gl4/glIsRenderbuffer       
    GLF_(glIsRenderbuffer,                              /**/ GLboolean(APIENTRY*)(GLuint renderbuffer))
    /// https://docs.gl/gl4/glRenderbufferStorage  
    GLF_(glRenderbufferStorage,                         /**/ void(APIENTRY*)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height))
    GLF_(glNamedRenderbufferStorage,                    /**/ void(APIENTRY*)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height))
    /// https://docs.gl/gl4/glRenderbufferStorageMultisample
    GLF_(glRenderbufferStorageMultisample,              /**/ void(APIENTRY*)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height))
    GLF_(glNamedRenderbufferStorageMultisample,         /**/ void(APIENTRY*)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height))
    /// https://docs.gl/gl4/glSampleMaski          
    GLF_(glSampleMaski,                                 /**/ void(APIENTRY*)(GLuint maskNumber, GLbitfield mask))








    /// Shaders                                    


    /// https://docs.gl/gl4/glAttachShader         
    GLF_(glAttachShader,                                /**/ void(APIENTRY*)(GLuint program, GLuint shader))
    /// https://docs.gl/gl4/glBindAttribLocation   
    GLF_(glBindAttribLocation,                          /**/ void(APIENTRY*)(GLuint program, GLuint index, const GLchar* name))
    /// https://docs.gl/gl4/glBindFragDataLocation 
    GLF_(glBindFragDataLocation,                        /**/ void(APIENTRY*)(GLuint program, GLuint colorNumber, const char* name))
    /// https://docs.gl/gl4/glBindFragDataLocationIndexed
    GLF_(glBindFragDataLocationIndexed,                 /**/ void(APIENTRY*)(GLuint program, GLuint colorNumber, GLuint index, const char* name))
    /// https://docs.gl/gl4/glCompileShader        
    GLF_(glCompileShader,                               /**/ void(APIENTRY*)(GLuint shader))
    /// https://docs.gl/gl4/glCreateProgram        
    GLF_(glCreateProgram,                               /**/ GLuint(APIENTRY*)(void))
    /// https://docs.gl/gl4/glCreateShader         
    GLF_(glCreateShader,                                /**/ GLuint(APIENTRY*)(GLenum shaderType))
    /// https://docs.gl/gl4/glCreateShaderProgram  
    GLF_(glCreateShaderProgramv,                        /**/ GLuint(APIENTRY*)(GLenum type, GLsizei count, const char** strings))
    /// https://docs.gl/gl4/glDeleteProgram        
    GLF_(glDeleteProgram,                               /**/ void(APIENTRY*)(GLuint program))
    /// https://docs.gl/gl4/glDeleteShader         
    GLF_(glDeleteShader,                                /**/ void(APIENTRY*)(GLuint shader))
    /// https://docs.gl/gl4/glDetachShader         
    GLF_(glDetachShader,                                /**/ void(APIENTRY*)(GLuint program, GLuint shader))
    /// https://docs.gl/gl4/glGetActiveAtomicCounterBufferiv
    GLF_(glGetActiveAtomicCounterBufferiv,              /**/ void(APIENTRY*)(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params))
    /// https://docs.gl/gl4/glGetActiveAttrib      
    GLF_(glGetActiveAttrib,                             /**/ void(APIENTRY*)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name))
    /// https://docs.gl/gl4/glGetActiveSubroutineName
    GLF_(glGetActiveSubroutineName,                     /**/ void(APIENTRY*)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name))
    /// https://docs.gl/gl4/glGetActiveSubroutineUniform
    GLF_(glGetActiveSubroutineUniformiv,                /**/ void(APIENTRY*)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values))
    /// https://docs.gl/gl4/glGetActiveSubroutineUniformName
    GLF_(glGetActiveSubroutineUniformName,              /**/ void(APIENTRY*)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name))
    /// https://docs.gl/gl4/glGetActiveUniform     
    GLF_(glGetActiveUniform,                            /**/ void(APIENTRY*)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name))
    /// https://docs.gl/gl4/glGetActiveUniformBlock
    GLF_(glGetActiveUniformBlockiv,                     /**/ void(APIENTRY*)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params))
    /// https://docs.gl/gl4/glGetActiveUniformBlockName
    GLF_(glGetActiveUniformBlockName,                   /**/ void(APIENTRY*)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName))
    /// https://docs.gl/gl4/glGetActiveUniformName 
    GLF_(glGetActiveUniformName,                        /**/ void(APIENTRY*)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName))
    /// https://docs.gl/gl4/glGetActiveUniformsiv  
    GLF_(glGetActiveUniformsiv,                         /**/ void(APIENTRY*)(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params))
    /// https://docs.gl/gl4/glGetAttachedShaders   
    GLF_(glGetAttachedShaders,                          /**/ void(APIENTRY*)(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders))
    /// https://docs.gl/gl4/glGetAttribLocation    
    GLF_(glGetAttribLocation,                           /**/ GLint(APIENTRY*)(GLuint program, const GLchar* name))
    /// https://docs.gl/gl4/glGetFragDataIndex     
    GLF_(glGetFragDataIndex,                            /**/ GLint(APIENTRY*)(GLuint program, const char* name))
    /// https://docs.gl/gl4/glGetFragDataLocation  
    GLF_(glGetFragDataLocation,                         /**/ GLint(APIENTRY*)(GLuint program, const char* name))
    /// https://docs.gl/gl4/glGetProgram           
    GLF_(glGetProgramiv,                                /**/ void(APIENTRY*)(GLuint program, GLenum pname, GLint* params))
    /// https://docs.gl/gl4/glGetProgramBinary     
    GLF_(glGetProgramBinary,                            /**/ void(APIENTRY*)(GLuint program, GLsizei bufsize, GLsizei* length, GLenum* binaryFormat, void* binary))
    /// https://docs.gl/gl4/glGetProgramInfoLog    
    GLF_(glGetProgramInfoLog,                           /**/ void(APIENTRY*)(GLuint program, GLsizei maxLength, GLsizei* length, GLchar* infoLog))
    /// https://docs.gl/gl4/glGetProgramResource   
    GLF_(glGetProgramResourceiv,                        /**/ void(APIENTRY*)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei bufSize, GLsizei* length, GLint* params))
    /// https://docs.gl/gl4/glGetProgramResourceIndex
    GLF_(glGetProgramResourceIndex,                     /**/ GLuint(APIENTRY*)(GLuint program, GLenum programInterface, const char* name))
    /// https://docs.gl/gl4/glGetProgramResourceLocation
    GLF_(glGetProgramResourceLocation,                  /**/ GLint(APIENTRY*)(GLuint program, GLenum programInterface, const char* name))
    /// https://docs.gl/gl4/glGetProgramResourceLocationIndex
    GLF_(glGetProgramResourceLocationIndex,             /**/ GLint(APIENTRY*)(GLuint program, GLenum programInterface, const char* name))
    /// https://docs.gl/gl4/glGetProgramResourceName
    GLF_(glGetProgramResourceName,                      /**/ void(APIENTRY*)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, char* name))
    /// https://docs.gl/gl4/glGetProgramStage      
    GLF_(glGetProgramStageiv,                           /**/ void(APIENTRY*)(GLuint program, GLenum shadertype, GLenum pname, GLint* values))
    /// https://docs.gl/gl4/glGetShader            
    GLF_(glGetShaderiv,                                 /**/ void(APIENTRY*)(GLuint shader, GLenum pname, GLint* params))
    /// https://docs.gl/gl4/glGetShaderInfoLog     
    GLF_(glGetShaderInfoLog,                            /**/ void(APIENTRY*)(GLuint shader, GLsizei maxLength, GLsizei* length, GLchar* infoLog))
    /// https://docs.gl/gl4/glGetShaderPrecisionFormat
    GLF_(glGetShaderPrecisionFormat,                    /**/ void(APIENTRY*)(GLenum shaderType, GLenum precisionType, GLint* range, GLint* precision))
    /// https://docs.gl/gl4/glGetShaderSource      
    GLF_(glGetShaderSource,                             /**/ void(APIENTRY*)(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source))
    /// https://docs.gl/gl4/glGetSubroutineIndex   
    GLF_(glGetSubroutineIndex,                          /**/ GLuint(APIENTRY*)(GLuint program, GLenum shadertype, const GLchar* name))
    /// https://docs.gl/gl4/glGetSubroutineUniformLocation
    GLF_(glGetSubroutineUniformLocation,                /**/ GLint(APIENTRY*)(GLuint program, GLenum shadertype, const GLchar* name))
    /// https://docs.gl/gl4/glGetUniform           
    GLF_(glGetUniformfv,                                /**/ void(APIENTRY*)(GLuint program, GLint location, GLfloat* params))
    GLF_(glGetUniformiv,                                /**/ void(APIENTRY*)(GLuint program, GLint location, GLint* params))
    GLF_(glGetUniformuiv,                               /**/ void(APIENTRY*)(GLuint program, GLint location, GLuint* params))
    GLF_(glGetUniformdv,                                /**/ void(APIENTRY*)(GLuint program, GLint location, GLdouble* params))
    GLF_(glGetnUniformfv,                               /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei bufSize, GLfloat* params))
    GLF_(glGetnUniformiv,                               /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei bufSize, GLint* params))
    GLF_(glGetnUniformuiv,                              /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei bufSize, GLuint* params))
    GLF_(glGetnUniformdv,                               /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei bufSize, GLdouble* params))
    /// https://docs.gl/gl4/glGetUniformBlockIndex 
    GLF_(glGetUniformBlockIndex,                        /**/ GLuint(APIENTRY*)(GLuint program, const GLchar* uniformBlockName))
    /// https://docs.gl/gl4/glGetUniformIndices    
    GLF_(glGetUniformIndices,                           /**/ void(APIENTRY*)(GLuint program, GLsizei uniformCount, const GLchar** uniformNames, GLuint* uniformIndices))
    /// https://docs.gl/gl4/glGetUniformLocation   
    GLF_(glGetUniformLocation,                          /**/ GLint(APIENTRY*)(GLuint program, const GLchar* name))
    /// https://docs.gl/gl4/glGetUniformSubroutine 
    GLF_(glGetUniformSubroutineuiv,                     /**/ void(APIENTRY*)(GLenum shadertype, GLint location, GLuint* values))
    /// https://docs.gl/gl4/glIsProgram            
    GLF_(glIsProgram,                                   /**/ GLboolean(APIENTRY*)(GLuint program))
    /// https://docs.gl/gl4/glIsShader             
    GLF_(glIsShader,                                    /**/ GLboolean(APIENTRY*)(GLuint shader))
    /// https://docs.gl/gl4/glLinkProgram          
    GLF_(glLinkProgram,                                 /**/ void(APIENTRY*)(GLuint program))
    /// https://docs.gl/gl4/glMinSampleShading     
    GLF_(glMinSampleShading,                            /**/ void(APIENTRY*)(GLfloat value))
    /// https://docs.gl/gl4/glProgramBinary        
    GLF_(glProgramBinary,                               /**/ void(APIENTRY*)(GLuint program, GLenum binaryFormat, const void* binary, GLsizei length))
    /// https://docs.gl/gl4/glProgramParameter     
    GLF_(glProgramParameteri,                           /**/ void(APIENTRY*)(GLuint program, GLenum pname, GLint value))
    /// https://docs.gl/gl4/glProgramUniform       
    GLF_(glProgramUniform1f,                            /**/ void(APIENTRY*)(GLuint program, GLint location, GLfloat v0))
    GLF_(glProgramUniform2f,                            /**/ void(APIENTRY*)(GLuint program, GLint location, GLfloat v0, GLfloat v1))
    GLF_(glProgramUniform3f,                            /**/ void(APIENTRY*)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2))
    GLF_(glProgramUniform4f,                            /**/ void(APIENTRY*)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3))
    GLF_(glProgramUniform1i,                            /**/ void(APIENTRY*)(GLuint program, GLint location, GLint v0))
    GLF_(glProgramUniform2i,                            /**/ void(APIENTRY*)(GLuint program, GLint location, GLint v0, GLint v1))
    GLF_(glProgramUniform3i,                            /**/ void(APIENTRY*)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2))
    GLF_(glProgramUniform4i,                            /**/ void(APIENTRY*)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3))
    GLF_(glProgramUniform1ui,                           /**/ void(APIENTRY*)(GLuint program, GLint location, GLuint v0))
    GLF_(glProgramUniform2ui,                           /**/ void(APIENTRY*)(GLuint program, GLint location, GLuint v0, GLuint v1))
    GLF_(glProgramUniform3ui,                           /**/ void(APIENTRY*)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2))
    GLF_(glProgramUniform4ui,                           /**/ void(APIENTRY*)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3))
    GLF_(glProgramUniform1fv,                           /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, const GLfloat* value))
    GLF_(glProgramUniform2fv,                           /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, const GLfloat* value))
    GLF_(glProgramUniform3fv,                           /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, const GLfloat* value))
    GLF_(glProgramUniform4fv,                           /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, const GLfloat* value))
    GLF_(glProgramUniform1iv,                           /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, const GLint* value))
    GLF_(glProgramUniform2iv,                           /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, const GLint* value))
    GLF_(glProgramUniform3iv,                           /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, const GLint* value))
    GLF_(glProgramUniform4iv,                           /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, const GLint* value))
    GLF_(glProgramUniform1uiv,                          /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, const GLuint* value))
    GLF_(glProgramUniform2uiv,                          /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, const GLuint* value))
    GLF_(glProgramUniform3uiv,                          /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, const GLuint* value))
    GLF_(glProgramUniform4uiv,                          /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, const GLuint* value))
    GLF_(glProgramUniformMatrix2fv,                     /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    GLF_(glProgramUniformMatrix3fv,                     /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    GLF_(glProgramUniformMatrix4fv,                     /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    GLF_(glProgramUniformMatrix2x3fv,                   /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    GLF_(glProgramUniformMatrix3x2fv,                   /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    GLF_(glProgramUniformMatrix2x4fv,                   /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    GLF_(glProgramUniformMatrix4x2fv,                   /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    GLF_(glProgramUniformMatrix3x4fv,                   /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    GLF_(glProgramUniformMatrix4x3fv,                   /**/ void(APIENTRY*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    /// https://docs.gl/gl4/glReleaseShaderCompiler
    GLF_(glReleaseShaderCompiler,                       /**/ void(APIENTRY*)(void))
    /// https://docs.gl/gl4/glShaderBinary         
    GLF_(glShaderBinary,                                /**/ void(APIENTRY*)(GLsizei count, const GLuint* shaders, GLenum binaryFormat, const void* binary, GLsizei length))
    /// https://docs.gl/gl4/glShaderSource         
    GLF_(glShaderSource,                                /**/ void(APIENTRY*)(GLuint shader, GLsizei count, const GLchar** string, const GLint* length))
    /// https://docs.gl/gl4/glShaderStorageBlockBinding
    GLF_(glShaderStorageBlockBinding,                   /**/ void(APIENTRY*)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding))
    /// https://docs.gl/gl4/glUniform              
    GLF_(glUniform1f,                                   /**/ void(APIENTRY*)(GLint location, GLfloat v0))
    GLF_(glUniform2f,                                   /**/ void(APIENTRY*)(GLint location, GLfloat v0, GLfloat v1))
    GLF_(glUniform3f,                                   /**/ void(APIENTRY*)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2))
    GLF_(glUniform4f,                                   /**/ void(APIENTRY*)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3))
    GLF_(glUniform1i,                                   /**/ void(APIENTRY*)(GLint location, GLint v0))
    GLF_(glUniform2i,                                   /**/ void(APIENTRY*)(GLint location, GLint v0, GLint v1))
    GLF_(glUniform3i,                                   /**/ void(APIENTRY*)(GLint location, GLint v0, GLint v1, GLint v2))
    GLF_(glUniform4i,                                   /**/ void(APIENTRY*)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3))
    GLF_(glUniform1ui,                                  /**/ void(APIENTRY*)(GLint location, GLuint v0))
    GLF_(glUniform2ui,                                  /**/ void(APIENTRY*)(GLint location, GLuint v0, GLuint v1))
    GLF_(glUniform3ui,                                  /**/ void(APIENTRY*)(GLint location, GLuint v0, GLuint v1, GLuint v2))
    GLF_(glUniform4ui,                                  /**/ void(APIENTRY*)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3))
    GLF_(glUniform1fv,                                  /**/ void(APIENTRY*)(GLint location, GLsizei count, const GLfloat* value))
    GLF_(glUniform2fv,                                  /**/ void(APIENTRY*)(GLint location, GLsizei count, const GLfloat* value))
    GLF_(glUniform3fv,                                  /**/ void(APIENTRY*)(GLint location, GLsizei count, const GLfloat* value))
    GLF_(glUniform4fv,                                  /**/ void(APIENTRY*)(GLint location, GLsizei count, const GLfloat* value))
    GLF_(glUniform1iv,                                  /**/ void(APIENTRY*)(GLint location, GLsizei count, const GLint* value))
    GLF_(glUniform2iv,                                  /**/ void(APIENTRY*)(GLint location, GLsizei count, const GLint* value))
    GLF_(glUniform3iv,                                  /**/ void(APIENTRY*)(GLint location, GLsizei count, const GLint* value))
    GLF_(glUniform4iv,                                  /**/ void(APIENTRY*)(GLint location, GLsizei count, const GLint* value))
    GLF_(glUniform1uiv,                                 /**/ void(APIENTRY*)(GLint location, GLsizei count, const GLuint* value))
    GLF_(glUniform2uiv,                                 /**/ void(APIENTRY*)(GLint location, GLsizei count, const GLuint* value))
    GLF_(glUniform3uiv,                                 /**/ void(APIENTRY*)(GLint location, GLsizei count, const GLuint* value))
    GLF_(glUniform4uiv,                                 /**/ void(APIENTRY*)(GLint location, GLsizei count, const GLuint* value))
    GLF_(glUniformMatrix2fv,                            /**/ void(APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    GLF_(glUniformMatrix3fv,                            /**/ void(APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    GLF_(glUniformMatrix4fv,                            /**/ void(APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    GLF_(glUniformMatrix2x3fv,                          /**/ void(APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    GLF_(glUniformMatrix3x2fv,                          /**/ void(APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    GLF_(glUniformMatrix2x4fv,                          /**/ void(APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    GLF_(glUniformMatrix4x2fv,                          /**/ void(APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    GLF_(glUniformMatrix3x4fv,                          /**/ void(APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    GLF_(glUniformMatrix4x3fv,                          /**/ void(APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value))
    /// https://docs.gl/gl4/glUniformBlockBinding  
    GLF_(glUniformBlockBinding,                         /**/ void(APIENTRY*)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding))
    /// https://docs.gl/gl4/glUniformSubroutines   
    GLF_(glUniformSubroutinesuiv,                       /**/ void(APIENTRY*)(GLenum shadertype, GLsizei count, const GLuint* indices))
    /// https://docs.gl/gl4/glUseProgram           
    GLF_(glUseProgram,                                  /**/ void(APIENTRY*)(GLuint program))
    /// https://docs.gl/gl4/glUseProgramStages     
    GLF_(glUseProgramStages,                            /**/ void(APIENTRY*)(GLuint pipeline, GLbitfield stages, GLuint program))
    /// https://docs.gl/gl4/glValidateProgram      
    GLF_(glValidateProgram,                             /**/ void(APIENTRY*)(GLuint program))








    /// BufferObjects                              


    /// https://docs.gl/gl4/glBindBuffer           
    GLF_(glBindBuffer,                                  /**/ void(APIENTRY*)(GLenum target, GLuint buffer))
    /// https://docs.gl/gl4/glBindBufferBase       
    GLF_(glBindBufferBase,                              /**/ void(APIENTRY*)(GLenum target, GLuint index, GLuint buffer))
    /// https://docs.gl/gl4/glBindBufferRange      
    GLF_(glBindBufferRange,                             /**/ void(APIENTRY*)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size))
    /// https://docs.gl/gl4/glBindBuffersBase      
    GLF_(glBindBuffersBase,                             /**/ void(APIENTRY*)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers))
    /// https://docs.gl/gl4/glBindBuffersRange     
    GLF_(glBindBuffersRange,                            /**/ void(APIENTRY*)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLintptr* sizes))
    /// https://docs.gl/gl4/glBindVertexBuffer     
    GLF_(glBindVertexBuffer,                            /**/ void(APIENTRY*)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLintptr stride))
    GLF_(glVertexArrayVertexBuffer,                     /**/ void(APIENTRY*)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride))
    /// https://docs.gl/gl4/glBindVertexBuffers    
    GLF_(glBindVertexBuffers,                           /**/ void(APIENTRY*)(GLuint first, GLsizei count, const GLuint* buffers, const GLuintptr* offsets, const GLsizei* strides))
    GLF_(glVertexArrayVertexBuffers,                    /**/ void(APIENTRY*)(GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides))
    /// https://docs.gl/gl4/glBufferData           
    GLF_(glBufferData,                                  /**/ void(APIENTRY*)(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage))
    GLF_(glNamedBufferData,                             /**/ void(APIENTRY*)(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage))
    /// https://docs.gl/gl4/glBufferStorage        
    GLF_(glBufferStorage,                               /**/ void(APIENTRY*)(GLenum target, GLsizeiptr size, const GLvoid* data, GLbitfield flags))
    GLF_(glNamedBufferStorage,                          /**/ void(APIENTRY*)(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags))
    /// https://docs.gl/gl4/glBufferSubData        
    GLF_(glBufferSubData,                               /**/ void(APIENTRY*)(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data))
    GLF_(glNamedBufferSubData,                          /**/ void(APIENTRY*)(GLuint buffer, GLintptr offset, GLsizei size, const void* data))
    /// https://docs.gl/gl4/glClearBufferData      
    GLF_(glClearBufferData,                             /**/ void(APIENTRY*)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data))
    GLF_(glClearNamedBufferData,                        /**/ void(APIENTRY*)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data))
    /// https://docs.gl/gl4/glClearBufferSubData   
    GLF_(glClearBufferSubData,                          /**/ void(APIENTRY*)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data))
    GLF_(glClearNamedBufferSubData,                     /**/ void(APIENTRY*)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizei size, GLenum format, GLenum type, const void* data))
    /// https://docs.gl/gl4/glCopyBufferSubData    
    GLF_(glCopyBufferSubData,                           /**/ void(APIENTRY*)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size))
    GLF_(glCopyNamedBufferSubData,                      /**/ void(APIENTRY*)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizei size))
    /// https://docs.gl/gl4/glCreateBuffers        
    GLF_(glCreateBuffers,                               /**/ void(APIENTRY*)(GLsizei n, GLuint* buffers))
    /// https://docs.gl/gl4/glCreateVertexArrays   
    GLF_(glCreateVertexArrays,                          /**/ void(APIENTRY*)(GLsizei n, GLuint* arrays))
    /// https://docs.gl/gl4/glDeleteBuffers        
    GLF_(glDeleteBuffers,                               /**/ void(APIENTRY*)(GLsizei n, const GLuint* buffers))
    /// https://docs.gl/gl4/glDisableVertexAttribArray

    /// https://docs.gl/gl4/glDrawArrays           
    GLD_(glDrawArrays,                                  /**/ void(APIENTRY*)(GLenum mode, GLint first, GLsizei count))
    /// https://docs.gl/gl4/glDrawArraysIndirect   
    GLF_(glDrawArraysIndirect,                          /**/ void(APIENTRY*)(GLenum mode, const void* indirect))
    /// https://docs.gl/gl4/glDrawArraysInstanced  
    GLF_(glDrawArraysInstanced,                         /**/ void(APIENTRY*)(GLenum mode, GLint first, GLsizei count, GLsizei primcount))
    /// https://docs.gl/gl4/glDrawArraysInstancedBaseInstance
    GLF_(glDrawArraysInstancedBaseInstance,             /**/ void(APIENTRY*)(GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLuint baseinstance))
    /// https://docs.gl/gl4/glDrawElements         
    GLF_(glDrawElements,                                /**/ void(APIENTRY*)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices))
    /// https://docs.gl/gl4/glDrawElementsBaseVertex
    GLF_(glDrawElementsBaseVertex,                      /**/ void(APIENTRY*)(GLenum mode, GLsizei count, GLenum type, GLvoid* indices, GLint basevertex))
    /// https://docs.gl/gl4/glDrawElementsIndirect 
    GLF_(glDrawElementsIndirect,                        /**/ void(APIENTRY*)(GLenum mode, GLenum type, const void* indirect))
    /// https://docs.gl/gl4/glDrawElementsInstanced
    GLF_(glDrawElementsInstanced,                       /**/ void(APIENTRY*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount))
    /// https://docs.gl/gl4/glDrawElementsInstancedBaseInstance
    GLF_(glDrawElementsInstancedBaseInstance,           /**/ void(APIENTRY*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount, GLuint baseinstance))
    /// https://docs.gl/gl4/glDrawElementsInstancedBaseVertex
    GLF_(glDrawElementsInstancedBaseVertex,             /**/ void(APIENTRY*)(GLenum mode, GLsizei count, GLenum type, GLvoid* indices, GLsizei primcount, GLint basevertex))
    /// https://docs.gl/gl4/glDrawElementsInstancedBaseVertexBaseInstance
    GLF_(glDrawElementsInstancedBaseVertexBaseInstance, /**/ void(APIENTRY*)(GLenum mode, GLsizei count, GLenum type, GLvoid* indices, GLsizei primcount, GLint basevertex, GLuint baseinstance))
    /// https://docs.gl/gl4/glDrawRangeElements    
    GLF_(glDrawRangeElements,                           /**/ void(APIENTRY*)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices))
    /// https://docs.gl/gl4/glDrawRangeElementsBaseVertex
    GLF_(glDrawRangeElementsBaseVertex,                 /**/ void(APIENTRY*)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid* indices, GLint basevertex))
    /// https://docs.gl/gl4/glEnableVertexAttribArray
    GLF_(glEnableVertexAttribArray,                     /**/ void(APIENTRY*)(GLuint index))
    GLF_(glDisableVertexAttribArray,                    /**/ void(APIENTRY*)(GLuint index))
    GLF_(glEnableVertexArrayAttrib,                     /**/ void(APIENTRY*)(GLuint vaobj, GLuint index))
    GLF_(glDisableVertexArrayAttrib,                    /**/ void(APIENTRY*)(GLuint vaobj, GLuint index))
    /// https://docs.gl/gl4/glFlushMappedBufferRange
    GLF_(glFlushMappedBufferRange,                      /**/ void(APIENTRY*)(GLenum target, GLintptr offset, GLsizeiptr length))
    GLF_(glFlushMappedNamedBufferRange,                 /**/ void(APIENTRY*)(GLuint buffer, GLintptr offset, GLsizei length))
    /// https://docs.gl/gl4/glGenBuffers           
    GLF_(glGenBuffers,                                  /**/ void(APIENTRY*)(GLsizei n, GLuint* buffers))
    /// https://docs.gl/gl4/glGetBufferParameter   
    GLF_(glGetBufferParameteriv,                        /**/ void(APIENTRY*)(GLenum target, GLenum value, GLint* data))
    GLF_(glGetBufferParameteri64v,                      /**/ void(APIENTRY*)(GLenum target, GLenum value, GLint64* data))
    GLF_(glGetNamedBufferParameteriv,                   /**/ void(APIENTRY*)(GLuint buffer, GLenum pname, GLint* params))
    GLF_(glGetNamedBufferParameteri64v,                 /**/ void(APIENTRY*)(GLuint buffer, GLenum pname, GLint64* params))
    /// https://docs.gl/gl4/glGetBufferParameteriv 

    /// https://docs.gl/gl4/glGetBufferPointerv    
    GLF_(glGetBufferPointerv,                           /**/ void(APIENTRY*)(GLenum target, GLenum pname, GLvoid** params))
    GLF_(glGetNamedBufferPointerv,                      /**/ void(APIENTRY*)(GLuint buffer, GLenum pname, void** params))
    /// https://docs.gl/gl4/glGetBufferSubData     
    GLF_(glGetBufferSubData,                            /**/ void(APIENTRY*)(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid* data))
    GLF_(glGetNamedBufferSubData,                       /**/ void(APIENTRY*)(GLuint buffer, GLintptr offset, GLsizei size, void* data))
    /// https://docs.gl/gl4/glGetVertexArrayIndexed
    GLF_(glGetVertexArrayIndexed64iv,                   /**/ void(APIENTRY*)(GLuint vaobj, GLuint index, GLenum pname, GLint64* param))
    GLF_(glGetVertexArrayIndexediv,                     /**/ void(APIENTRY*)(GLuint vaobj, GLuint index, GLenum pname, GLint* param))
    /// https://docs.gl/gl4/glGetVertexArrayiv     
    GLF_(glGetVertexArrayiv,                            /**/ void(APIENTRY*)(GLuint vaobj, GLenum pname, GLint* param))
    /// https://docs.gl/gl4/glGetVertexAttrib      
    GLF_(glGetVertexAttribdv,                           /**/ void(APIENTRY*)(GLuint index, GLenum pname, GLdouble* params))
    GLF_(glGetVertexAttribfv,                           /**/ void(APIENTRY*)(GLuint index, GLenum pname, GLfloat* params))
    GLF_(glGetVertexAttribiv,                           /**/ void(APIENTRY*)(GLuint index, GLenum pname, GLint* params))
    GLF_(glGetVertexAttribIiv,                          /**/ void(APIENTRY*)(GLuint index, GLenum pname, GLint* params))
    GLF_(glGetVertexAttribIuiv,                         /**/ void(APIENTRY*)(GLuint index, GLenum pname, GLuint* params))
    GLF_(glGetVertexAttribLdv,                          /**/ void(APIENTRY*)(GLuint index, GLenum pname, GLdouble* params))
    /// https://docs.gl/gl4/glGetVertexAttribPointerv
    GLF_(glGetVertexAttribPointerv,                     /**/ void(APIENTRY*)(GLuint index, GLenum pname, GLvoid** pointer))
    /// https://docs.gl/gl4/glInvalidateBufferData 
    GLF_(glInvalidateBufferData,                        /**/ void(APIENTRY*)(GLuint buffer))
    /// https://docs.gl/gl4/glInvalidateBufferSubData
    GLF_(glInvalidateBufferSubData,                     /**/ void(APIENTRY*)(GLuint buffer, GLintptr offset, GLsizeiptr length))
    /// https://docs.gl/gl4/glIsBuffer             
    GLF_(glIsBuffer,                                    /**/ GLboolean(APIENTRY*)(GLuint buffer))
    /// https://docs.gl/gl4/glMapBuffer            
    GLF_(glMapBuffer,                                   /**/ void*(*)(GLenum target, GLenum access))
    GLF_(glMapNamedBuffer,                              /**/ void*(*)(GLuint buffer, GLenum access))
    /// https://docs.gl/gl4/glMapBufferRange       
    GLF_(glMapBufferRange,                             /**/ void*(*)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access))
    GLF_(glMapNamedBufferRange,                        /**/ void*(*)(GLuint buffer, GLintptr offset, GLsizei length, GLbitfield access))
    /// https://docs.gl/gl4/glMultiDrawArrays      
    GLF_(glMultiDrawArrays,                             /**/ void(APIENTRY*)(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount))
    /// https://docs.gl/gl4/glMultiDrawArraysIndirect
    GLF_(glMultiDrawArraysIndirect,                     /**/ void(APIENTRY*)(GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride))
    /// https://docs.gl/gl4/glMultiDrawElements    
    GLF_(glMultiDrawElements,                           /**/ void(APIENTRY*)(GLenum mode, const GLsizei* count, GLenum type, const GLvoid* const* indices, GLsizei drawcount))
    /// https://docs.gl/gl4/glMultiDrawElementsBaseVertex
    GLF_(glMultiDrawElementsBaseVertex,                 /**/ void(APIENTRY*)(GLenum mode, const GLsizei* count, GLenum type, const GLvoid* const* indices, GLsizei drawcount, const GLint* basevertex))
    /// https://docs.gl/gl4/glMultiDrawElementsIndirect
    GLF_(glMultiDrawElementsIndirect,                   /**/ void(APIENTRY*)(GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride))
    /// https://docs.gl/gl4/glPatchParameter       
    GLF_(glPatchParameteri,                             /**/ void(APIENTRY*)(GLenum pname, GLint value))
    GLF_(glPatchParameterfv,                            /**/ void(APIENTRY*)(GLenum pname, const GLfloat* values))
    /// https://docs.gl/gl4/glPrimitiveRestartIndex
    GLF_(glPrimitiveRestartIndex,                       /**/ void(APIENTRY*)(GLuint index))
    /// https://docs.gl/gl4/glProvokingVertex      
    GLF_(glProvokingVertex,                             /**/ void(APIENTRY*)(GLenum provokeMode))
    /// https://docs.gl/gl4/glUnmapBuffer          
    GLF_(glUnmapBuffer,                                 /**/ GLboolean(APIENTRY*)(GLenum target))
    GLF_(glUnmapNamedBuffer,                            /**/ GLboolean(APIENTRY*)(GLuint buffer))
    /// https://docs.gl/gl4/glVertexArrayElementBuffer
    GLF_(glVertexArrayElementBuffer,                    /**/ void(APIENTRY*)(GLuint vaobj, GLuint buffer))
    /// https://docs.gl/gl4/glVertexAttrib         
    GLF_(glVertexAttrib1f,                              /**/ void(APIENTRY*)(GLuint index, GLfloat v0))
    GLF_(glVertexAttrib1s,                              /**/ void(APIENTRY*)(GLuint index, GLshort v0))
    GLF_(glVertexAttrib1d,                              /**/ void(APIENTRY*)(GLuint index, GLdouble v0))
    GLF_(glVertexAttribI1i,                             /**/ void(APIENTRY*)(GLuint index, GLint v0))
    GLF_(glVertexAttribI1ui,                            /**/ void(APIENTRY*)(GLuint index, GLuint v0))
    GLF_(glVertexAttrib2f,                              /**/ void(APIENTRY*)(GLuint index, GLfloat v0, GLfloat v1))
    GLF_(glVertexAttrib2s,                              /**/ void(APIENTRY*)(GLuint index, GLshort v0, GLshort v1))
    GLF_(glVertexAttrib2d,                              /**/ void(APIENTRY*)(GLuint index, GLdouble v0, GLdouble v1))
    GLF_(glVertexAttribI2i,                             /**/ void(APIENTRY*)(GLuint index, GLint v0, GLint v1))
    GLF_(glVertexAttribI2ui,                            /**/ void(APIENTRY*)(GLuint index, GLuint v0, GLuint v1))
    GLF_(glVertexAttrib3f,                              /**/ void(APIENTRY*)(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2))
    GLF_(glVertexAttrib3s,                              /**/ void(APIENTRY*)(GLuint index, GLshort v0, GLshort v1, GLshort v2))
    GLF_(glVertexAttrib3d,                              /**/ void(APIENTRY*)(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2))
    GLF_(glVertexAttribI3i,                             /**/ void(APIENTRY*)(GLuint index, GLint v0, GLint v1, GLint v2))
    GLF_(glVertexAttribI3ui,                            /**/ void(APIENTRY*)(GLuint index, GLuint v0, GLuint v1, GLuint v2))
    GLF_(glVertexAttrib4f,                              /**/ void(APIENTRY*)(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3))
    GLF_(glVertexAttrib4s,                              /**/ void(APIENTRY*)(GLuint index, GLshort v0, GLshort v1, GLshort v2, GLshort v3))
    GLF_(glVertexAttrib4d,                              /**/ void(APIENTRY*)(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3))
    GLF_(glVertexAttrib4Nub,                            /**/ void(APIENTRY*)(GLuint index, GLubyte v0, GLubyte v1, GLubyte v2, GLubyte v3))
    GLF_(glVertexAttribI4i,                             /**/ void(APIENTRY*)(GLuint index, GLint v0, GLint v1, GLint v2, GLint v3))
    GLF_(glVertexAttribI4ui,                            /**/ void(APIENTRY*)(GLuint index, GLuint v0, GLuint v1, GLuint v2, GLuint v3))
    GLF_(glVertexAttribL1d,                             /**/ void(APIENTRY*)(GLuint index, GLdouble v0))
    GLF_(glVertexAttribL2d,                             /**/ void(APIENTRY*)(GLuint index, GLdouble v0, GLdouble v1))
    GLF_(glVertexAttribL3d,                             /**/ void(APIENTRY*)(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2))
    GLF_(glVertexAttribL4d,                             /**/ void(APIENTRY*)(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3))
    GLF_(glVertexAttrib1fv,                             /**/ void(APIENTRY*)(GLuint index, const GLfloat* v))
    GLF_(glVertexAttrib1sv,                             /**/ void(APIENTRY*)(GLuint index, const GLshort* v))
    GLF_(glVertexAttrib1dv,                             /**/ void(APIENTRY*)(GLuint index, const GLdouble* v))
    GLF_(glVertexAttribI1iv,                            /**/ void(APIENTRY*)(GLuint index, const GLint* v))
    GLF_(glVertexAttribI1uiv,                           /**/ void(APIENTRY*)(GLuint index, const GLuint* v))
    GLF_(glVertexAttrib2fv,                             /**/ void(APIENTRY*)(GLuint index, const GLfloat* v))
    GLF_(glVertexAttrib2sv,                             /**/ void(APIENTRY*)(GLuint index, const GLshort* v))
    GLF_(glVertexAttrib2dv,                             /**/ void(APIENTRY*)(GLuint index, const GLdouble* v))
    GLF_(glVertexAttribI2iv,                            /**/ void(APIENTRY*)(GLuint index, const GLint* v))
    GLF_(glVertexAttribI2uiv,                           /**/ void(APIENTRY*)(GLuint index, const GLuint* v))
    GLF_(glVertexAttrib3fv,                             /**/ void(APIENTRY*)(GLuint index, const GLfloat* v))
    GLF_(glVertexAttrib3sv,                             /**/ void(APIENTRY*)(GLuint index, const GLshort* v))
    GLF_(glVertexAttrib3dv,                             /**/ void(APIENTRY*)(GLuint index, const GLdouble* v))
    GLF_(glVertexAttribI3iv,                            /**/ void(APIENTRY*)(GLuint index, const GLint* v))
    GLF_(glVertexAttribI3uiv,                           /**/ void(APIENTRY*)(GLuint index, const GLuint* v))
    GLF_(glVertexAttrib4fv,                             /**/ void(APIENTRY*)(GLuint index, const GLfloat* v))
    GLF_(glVertexAttrib4sv,                             /**/ void(APIENTRY*)(GLuint index, const GLshort* v))
    GLF_(glVertexAttrib4dv,                             /**/ void(APIENTRY*)(GLuint index, const GLdouble* v))
    GLF_(glVertexAttrib4iv,                             /**/ void(APIENTRY*)(GLuint index, const GLint* v))
    GLF_(glVertexAttrib4bv,                             /**/ void(APIENTRY*)(GLuint index, const GLbyte* v))
    GLF_(glVertexAttrib4ubv,                            /**/ void(APIENTRY*)(GLuint index, const GLubyte* v))
    GLF_(glVertexAttrib4usv,                            /**/ void(APIENTRY*)(GLuint index, const GLushort* v))
    GLF_(glVertexAttrib4uiv,                            /**/ void(APIENTRY*)(GLuint index, const GLuint* v))
    GLF_(glVertexAttrib4Nbv,                            /**/ void(APIENTRY*)(GLuint index, const GLbyte* v))
    GLF_(glVertexAttrib4Nsv,                            /**/ void(APIENTRY*)(GLuint index, const GLshort* v))
    GLF_(glVertexAttrib4Niv,                            /**/ void(APIENTRY*)(GLuint index, const GLint* v))
    GLF_(glVertexAttrib4Nubv,                           /**/ void(APIENTRY*)(GLuint index, const GLubyte* v))
    GLF_(glVertexAttrib4Nusv,                           /**/ void(APIENTRY*)(GLuint index, const GLushort* v))
    GLF_(glVertexAttrib4Nuiv,                           /**/ void(APIENTRY*)(GLuint index, const GLuint* v))
    GLF_(glVertexAttribI4bv,                            /**/ void(APIENTRY*)(GLuint index, const GLbyte* v))
    GLF_(glVertexAttribI4ubv,                           /**/ void(APIENTRY*)(GLuint index, const GLubyte* v))
    GLF_(glVertexAttribI4sv,                            /**/ void(APIENTRY*)(GLuint index, const GLshort* v))
    GLF_(glVertexAttribI4usv,                           /**/ void(APIENTRY*)(GLuint index, const GLushort* v))
    GLF_(glVertexAttribI4iv,                            /**/ void(APIENTRY*)(GLuint index, const GLint* v))
    GLF_(glVertexAttribI4uiv,                           /**/ void(APIENTRY*)(GLuint index, const GLuint* v))
    GLF_(glVertexAttribL1dv,                            /**/ void(APIENTRY*)(GLuint index, const GLdouble* v))
    GLF_(glVertexAttribL2dv,                            /**/ void(APIENTRY*)(GLuint index, const GLdouble* v))
    GLF_(glVertexAttribL3dv,                            /**/ void(APIENTRY*)(GLuint index, const GLdouble* v))
    GLF_(glVertexAttribL4dv,                            /**/ void(APIENTRY*)(GLuint index, const GLdouble* v))
    GLF_(glVertexAttribP1ui,                            /**/ void(APIENTRY*)(GLuint index, GLenum type, GLboolean normalized, GLuint value))
    GLF_(glVertexAttribP2ui,                            /**/ void(APIENTRY*)(GLuint index, GLenum type, GLboolean normalized, GLuint value))
    GLF_(glVertexAttribP3ui,                            /**/ void(APIENTRY*)(GLuint index, GLenum type, GLboolean normalized, GLuint value))
    GLF_(glVertexAttribP4ui,                            /**/ void(APIENTRY*)(GLuint index, GLenum type, GLboolean normalized, GLuint value))
    /// https://docs.gl/gl4/glVertexAttribBinding  
    GLF_(glVertexAttribBinding,                         /**/ void(APIENTRY*)(GLuint attribindex, GLuint bindingindex))
    GLF_(glVertexArrayAttribBinding,                    /**/ void(APIENTRY*)(GLuint vaobj, GLuint attribindex, GLuint bindingindex))
    /// https://docs.gl/gl4/glVertexAttribDivisor  
    GLF_(glVertexAttribDivisor,                         /**/ void(APIENTRY*)(GLuint index, GLuint divisor))
    /// https://docs.gl/gl4/glVertexAttribFormat   
    GLF_(glVertexAttribFormat,                          /**/ void(APIENTRY*)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset))
    GLF_(glVertexAttribIFormat,                         /**/ void(APIENTRY*)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset))
    GLF_(glVertexAttribLFormat,                         /**/ void(APIENTRY*)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset))
    GLF_(glVertexArrayAttribFormat,                     /**/ void(APIENTRY*)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset))
    GLF_(glVertexArrayAttribIFormat,                    /**/ void(APIENTRY*)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset))
    GLF_(glVertexArrayAttribLFormat,                    /**/ void(APIENTRY*)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset))
    /// https://docs.gl/gl4/glVertexAttribPointer  
    GLF_(glVertexAttribPointer,                         /**/ void(APIENTRY*)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer))
    GLF_(glVertexAttribIPointer,                        /**/ void(APIENTRY*)(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer))
    GLF_(glVertexAttribLPointer,                        /**/ void(APIENTRY*)(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer))
    /// https://docs.gl/gl4/glVertexBindingDivisor 
    GLF_(glVertexBindingDivisor,                        /**/ void(APIENTRY*)(GLuint bindingindex, GLuint divisor))
    GLF_(glVertexArrayBindingDivisor,                   /**/ void(APIENTRY*)(GLuint vaobj, GLuint bindingindex, GLuint divisor))








    /// StateManagement                            


    /// https://docs.gl/gl4/glBlendColor           
    GLF_(glBlendColor,                                  /**/ void(APIENTRY*)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha))
    /// https://docs.gl/gl4/glBlendEquation        
    GLF_(glBlendEquation,                               /**/ void(APIENTRY*)(GLenum mode))
    GLF_(glBlendEquationi,                              /**/ void(APIENTRY*)(GLuint buf, GLenum mode))
    /// https://docs.gl/gl4/glBlendEquationSeparate
    GLF_(glBlendEquationSeparate,                       /**/ void(APIENTRY*)(GLenum modeRGB, GLenum modeAlpha))
    GLF_(glBlendEquationSeparatei,                      /**/ void(APIENTRY*)(GLuint buf, GLenum modeRGB, GLenum modeAlpha))
    /// https://docs.gl/gl4/glBlendFunc            
    GLF_(glBlendFunc,                                   /**/ void(APIENTRY*)(GLenum sfactor, GLenum dfactor))
    GLF_(glBlendFunci,                                  /**/ void(APIENTRY*)(GLuint buf, GLenum sfactor, GLenum dfactor))
    /// https://docs.gl/gl4/glBlendFuncSeparate    
    GLF_(glBlendFuncSeparate,                           /**/ void(APIENTRY*)(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha))
    GLF_(glBlendFuncSeparatei,                          /**/ void(APIENTRY*)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha))
    /// https://docs.gl/gl4/glClampColor           
    GLF_(glClampColor,                                  /**/ void(APIENTRY*)(GLenum target, GLenum clamp))
    /// https://docs.gl/gl4/glClipControl          
    GLF_(glClipControl,                                 /**/ void(APIENTRY*)(GLenum origin, GLenum depth))
    /// https://docs.gl/gl4/glColorMask            
    GLF_(glColorMask,                                   /**/ void(APIENTRY*)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha))
    GLF_(glColorMaski,                                  /**/ void(APIENTRY*)(GLuint buf, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha))
    /// https://docs.gl/gl4/glCullFace             
    GLF_(glCullFace,                                    /**/ void(APIENTRY*)(GLenum mode))
    /// https://docs.gl/gl4/glDepthFunc            
    GLF_(glDepthFunc,                                   /**/ void(APIENTRY*)(GLenum func))
    /// https://docs.gl/gl4/glDepthMask            
    GLF_(glDepthMask,                                   /**/ void(APIENTRY*)(GLboolean flag))
    /// https://docs.gl/gl4/glDepthRange           
    GLF_(glDepthRange,                                  /**/ void(APIENTRY*)(GLdouble nearVal, GLdouble farVal))
    GLF_(glDepthRangef,                                 /**/ void(APIENTRY*)(GLfloat nearVal, GLfloat farVal))
    /// https://docs.gl/gl4/glDepthRangeArray      
    GLF_(glDepthRangeArrayv,                            /**/ void(APIENTRY*)(GLuint first, GLsizei count, const GLdouble* v))
    /// https://docs.gl/gl4/glDepthRangeIndexed    
    GLF_(glDepthRangeIndexed,                           /**/ void(APIENTRY*)(GLuint index, GLdouble nearVal, GLdouble farVal))
    /// https://docs.gl/gl4/glDisable              

    /// https://docs.gl/gl4/glEnable               
    GLD_(glEnable,                                      /**/ void(APIENTRY*)(GLenum cap))
    GLD_(glDisable,                                     /**/ void(APIENTRY*)(GLenum cap))
    GLF_(glEnablei,                                     /**/ void(APIENTRY*)(GLenum cap, GLuint index))
    GLF_(glDisablei,                                    /**/ void(APIENTRY*)(GLenum cap, GLuint index))
    /// https://docs.gl/gl4/glFrontFace            
    GLF_(glFrontFace,                                   /**/ void(APIENTRY*)(GLenum mode))
    /// https://docs.gl/gl4/glGet                  
    GLF_(glGetBooleanv,                                 /**/ void(APIENTRY*)(GLenum pname, GLboolean* data))
    GLF_(glGetDoublev,                                  /**/ void(APIENTRY*)(GLenum pname, GLdouble* data))
    GLF_(glGetFloatv,                                   /**/ void(APIENTRY*)(GLenum pname, GLfloat* data))
    GLF_(glGetIntegerv,                                 /**/ void(APIENTRY*)(GLenum pname, GLint* data))
    GLF_(glGetInteger64v,                               /**/ void(APIENTRY*)(GLenum pname, GLint64* data))
    GLF_(glGetBooleani_v,                               /**/ void(APIENTRY*)(GLenum target, GLuint index, GLboolean* data))
    GLF_(glGetIntegeri_v,                               /**/ void(APIENTRY*)(GLenum target, GLuint index, GLint* data))
    GLF_(glGetFloati_v,                                 /**/ void(APIENTRY*)(GLenum target, GLuint index, GLfloat* data))
    GLF_(glGetDoublei_v,                                /**/ void(APIENTRY*)(GLenum target, GLuint index, GLdouble* data))
    GLF_(glGetInteger64i_v,                             /**/ void(APIENTRY*)(GLenum target, GLuint index, GLint64* data))
    /// https://docs.gl/gl4/glGetError             
    GLF_(glGetError,                                    /**/ GLenum(APIENTRY*)(void))
    /// https://docs.gl/gl4/glHint                 
    GLF_(glHint,                                        /**/ void(APIENTRY*)(GLenum target, GLenum mode))
    /// https://docs.gl/gl4/glIsEnabled            
    GLF_(glIsEnabled,                                   /**/ GLboolean(APIENTRY*)(GLenum cap))
    GLF_(glIsEnabledi,                                  /**/ GLboolean(APIENTRY*)(GLenum cap, GLuint index))
    /// https://docs.gl/gl4/glLineWidth            
    GLF_(glLineWidth,                                   /**/ void(APIENTRY*)(GLfloat width))
    /// https://docs.gl/gl4/glLogicOp              
    GLF_(glLogicOp,                                     /**/ void(APIENTRY*)(GLenum opcode))
    /// https://docs.gl/gl4/glPixelStore           
    GLF_(glPixelStoref,                                 /**/ void(APIENTRY*)(GLenum pname, GLfloat param))
    GLF_(glPixelStorei,                                 /**/ void(APIENTRY*)(GLenum pname, GLint param))
    /// https://docs.gl/gl4/glPointParameter       
    GLF_(glPointParameterf,                             /**/ void(APIENTRY*)(GLenum pname, GLfloat param))
    GLF_(glPointParameteri,                             /**/ void(APIENTRY*)(GLenum pname, GLint param))
    GLF_(glPointParameterfv,                            /**/ void(APIENTRY*)(GLenum pname, const GLfloat* params))
    GLF_(glPointParameteriv,                            /**/ void(APIENTRY*)(GLenum pname, const GLint* params))
    /// https://docs.gl/gl4/glPointSize            
    GLF_(glPointSize,                                   /**/ void(APIENTRY*)(GLfloat size))
    /// https://docs.gl/gl4/glPolygonMode          
    GLF_(glPolygonMode,                                 /**/ void(APIENTRY*)(GLenum face, GLenum mode))
    /// https://docs.gl/gl4/glPolygonOffset        
    GLF_(glPolygonOffset,                               /**/ void(APIENTRY*)(GLfloat factor, GLfloat units))
    /// https://docs.gl/gl4/glSampleCoverage       
    GLF_(glSampleCoverage,                              /**/ void(APIENTRY*)(GLfloat value, GLboolean invert))
    /// https://docs.gl/gl4/glScissor              
    GLF_(glScissor,                                     /**/ void(APIENTRY*)(GLint x, GLint y, GLsizei width, GLsizei height))
    /// https://docs.gl/gl4/glScissorArray         
    GLF_(glScissorArrayv,                               /**/ void(APIENTRY*)(GLuint first, GLsizei count, const GLint* v))
    /// https://docs.gl/gl4/glScissorIndexed       
    GLF_(glScissorIndexed,                              /**/ void(APIENTRY*)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height))
    GLF_(glScissorIndexedv,                             /**/ void(APIENTRY*)(GLuint index, const GLint* v))
    /// https://docs.gl/gl4/glStencilFunc          
    GLF_(glStencilFunc,                                 /**/ void(APIENTRY*)(GLenum func, GLint ref, GLuint mask))
    /// https://docs.gl/gl4/glStencilFuncSeparate  
    GLF_(glStencilFuncSeparate,                         /**/ void(APIENTRY*)(GLenum face, GLenum func, GLint ref, GLuint mask))
    /// https://docs.gl/gl4/glStencilMask          
    GLF_(glStencilMask,                                 /**/ void(APIENTRY*)(GLuint mask))
    /// https://docs.gl/gl4/glStencilMaskSeparate  
    GLF_(glStencilMaskSeparate,                         /**/ void(APIENTRY*)(GLenum face, GLuint mask))
    /// https://docs.gl/gl4/glStencilOp            
    GLF_(glStencilOp,                                   /**/ void(APIENTRY*)(GLenum sfail, GLenum dpfail, GLenum dppass))
    /// https://docs.gl/gl4/glStencilOpSeparate    
    GLF_(glStencilOpSeparate,                           /**/ void(APIENTRY*)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass))
    /// https://docs.gl/gl4/glViewport             
    GLD_(glViewport,                                    /**/ void(APIENTRY*)(GLint x, GLint y, GLsizei width, GLsizei height))
    /// https://docs.gl/gl4/glViewportArray        
    GLF_(glViewportArrayv,                              /**/ void(APIENTRY*)(GLuint first, GLsizei count, const GLfloat* v))
    /// https://docs.gl/gl4/glViewportIndexed      
    GLF_(glViewportIndexedf,                            /**/ void(APIENTRY*)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h))
    GLF_(glViewportIndexedfv,                           /**/ void(APIENTRY*)(GLuint index, const GLfloat* v))








    /// TransformFeedback                          


    /// https://docs.gl/gl4/glBeginTransformFeedback
    GLF_(glBeginTransformFeedback,                      /**/ void(APIENTRY*)(GLenum primitiveMode))
    GLF_(glEndTransformFeedback,                        /**/ void(APIENTRY*)(void))
    /// https://docs.gl/gl4/glBindTransformFeedback
    GLF_(glBindTransformFeedback,                       /**/ void(APIENTRY*)(GLenum target, GLuint id))
    /// https://docs.gl/gl4/glCreateTransformFeedbacks
    GLF_(glCreateTransformFeedbacks,                    /**/ void(APIENTRY*)(GLsizei n, GLuint* ids))
    /// https://docs.gl/gl4/glDeleteTransformFeedbacks
    GLF_(glDeleteTransformFeedbacks,                    /**/ void(APIENTRY*)(GLsizei n, const GLuint* ids))
    /// https://docs.gl/gl4/glDrawTransformFeedback
    GLF_(glDrawTransformFeedback,                       /**/ void(APIENTRY*)(GLenum mode, GLuint id))
    /// https://docs.gl/gl4/glDrawTransformFeedbackInstanced
    GLF_(glDrawTransformFeedbackInstanced,              /**/ void(APIENTRY*)(GLenum mode, GLuint id, GLsizei primcount))
    /// https://docs.gl/gl4/glDrawTransformFeedbackStream
    GLF_(glDrawTransformFeedbackStream,                 /**/ void(APIENTRY*)(GLenum mode, GLuint id, GLuint stream))
    /// https://docs.gl/gl4/glDrawTransformFeedbackStreamInstanced
    GLF_(glDrawTransformFeedbackStreamInstanced,        /**/ void(APIENTRY*)(GLenum mode, GLuint id, GLuint stream, GLsizei primcount))
    /// https://docs.gl/gl4/glEndTransformFeedback 

    /// https://docs.gl/gl4/glGenTransformFeedbacks
    GLF_(glGenTransformFeedbacks,                       /**/ void(APIENTRY*)(GLsizei n, GLuint* ids))
    /// https://docs.gl/gl4/glGetTransformFeedback 
    GLF_(glGetTransformFeedbackiv,                      /**/ void(APIENTRY*)(GLuint xfb, GLenum pname, GLint* param))
    GLF_(glGetTransformFeedbacki_v,                     /**/ void(APIENTRY*)(GLuint xfb, GLenum pname, GLuint index, GLint* param))
    GLF_(glGetTransformFeedbacki64_v,                   /**/ void(APIENTRY*)(GLuint xfb, GLenum pname, GLuint index, GLint64* param))
    /// https://docs.gl/gl4/glGetTransformFeedbackVarying
    GLF_(glGetTransformFeedbackVarying,                 /**/ void(APIENTRY*)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, char* name))
    /// https://docs.gl/gl4/glIsTransformFeedback  
    GLF_(glIsTransformFeedback,                         /**/ GLboolean(APIENTRY*)(GLuint id))
    /// https://docs.gl/gl4/glPauseTransformFeedback
    GLF_(glPauseTransformFeedback,                      /**/ void(APIENTRY*)(void))
    /// https://docs.gl/gl4/glResumeTransformFeedback
    GLF_(glResumeTransformFeedback,                     /**/ void(APIENTRY*)(void))
    /// https://docs.gl/gl4/glTransformFeedbackBufferBase
    GLF_(glTransformFeedbackBufferBase,                 /**/ void(APIENTRY*)(GLuint xfb, GLuint index, GLuint buffer))
    /// https://docs.gl/gl4/glTransformFeedbackBufferRange
    GLF_(glTransformFeedbackBufferRange,                /**/ void(APIENTRY*)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizei size))
    /// https://docs.gl/gl4/glTransformFeedbackVaryings
    GLF_(glTransformFeedbackVaryings,                   /**/ void(APIENTRY*)(GLuint program, GLsizei count, const char** varyings, GLenum bufferMode))








    /// Utility                                    


    /// https://docs.gl/gl4/glDispatchCompute      
    GLF_(glDispatchCompute,                             /**/ void(APIENTRY*)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z))
    /// https://docs.gl/gl4/glDispatchComputeIndirect
    GLF_(glDispatchComputeIndirect,                     /**/ void(APIENTRY*)(GLintptr indirect))
    /// https://docs.gl/gl4/glGetGraphicsResetStatus
    GLF_(glGetGraphicsResetStatus,                      /**/ GLenum(APIENTRY*)(void))
    /// https://docs.gl/gl4/glGetInternalformat    
    GLF_(glGetInternalformativ,                         /**/ void(APIENTRY*)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint* params))
    GLF_(glGetInternalformati64v,                       /**/ void(APIENTRY*)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64* params))
    /// https://docs.gl/gl4/glGetMultisample       
    GLF_(glGetMultisamplefv,                            /**/ void(APIENTRY*)(GLenum pname, GLuint index, GLfloat* val))
    /// https://docs.gl/gl4/glGetString            
    GLF_(glGetString,                                   /**/ GLubyte const*(*)(GLenum name))
    GLF_(glGetStringi,                                  /**/ GLubyte const*(*)(GLenum name, GLuint index))
    /// https://docs.gl/gl4/glMemoryBarrier        
    GLF_(glMemoryBarrier,                               /**/ void(APIENTRY*)(GLbitfield barriers))
    GLF_(glMemoryBarrierByRegion,                       /**/ void(APIENTRY*)(GLbitfield barriers))








    /// Queries                                    


    /// https://docs.gl/gl4/glBeginConditionalRender
    GLF_(glBeginConditionalRender,                      /**/ void(APIENTRY*)(GLuint id, GLenum mode))
    GLF_(glEndConditionalRender,                        /**/ void(APIENTRY*)(void))
    /// https://docs.gl/gl4/glBeginQuery           
    GLF_(glBeginQuery,                                  /**/ void(APIENTRY*)(GLenum target, GLuint id))
    GLF_(glEndQuery,                                    /**/ void(APIENTRY*)(GLenum target))
    /// https://docs.gl/gl4/glBeginQueryIndexed    
    GLF_(glBeginQueryIndexed,                           /**/ void(APIENTRY*)(GLenum target, GLuint index, GLuint id))
    GLF_(glEndQueryIndexed,                             /**/ void(APIENTRY*)(GLenum target, GLuint index))
    /// https://docs.gl/gl4/glCreateQueries        
    GLF_(glCreateQueries,                               /**/ void(APIENTRY*)(GLenum target, GLsizei n, GLuint* ids))
    /// https://docs.gl/gl4/glDeleteQueries        
    GLF_(glDeleteQueries,                               /**/ void(APIENTRY*)(GLsizei n, const GLuint* ids))
    /// https://docs.gl/gl4/glEndConditionalRender 

    /// https://docs.gl/gl4/glEndQuery             

    /// https://docs.gl/gl4/glEndQueryIndexed      

    /// https://docs.gl/gl4/glGenQueries           
    GLF_(glGenQueries,                                  /**/ void(APIENTRY*)(GLsizei n, GLuint* ids))
    /// https://docs.gl/gl4/glGetQueryIndexed      
    GLF_(glGetQueryIndexediv,                           /**/ void(APIENTRY*)(GLenum target, GLuint index, GLenum pname, GLint* params))
    /// https://docs.gl/gl4/glGetQueryObject       
    GLF_(glGetQueryObjectiv,                            /**/ void(APIENTRY*)(GLuint id, GLenum pname, GLint* params))
    GLF_(glGetQueryObjectuiv,                           /**/ void(APIENTRY*)(GLuint id, GLenum pname, GLuint* params))
    GLF_(glGetQueryObjecti64v,                          /**/ void(APIENTRY*)(GLuint id, GLenum pname, GLint64* params))
    GLF_(glGetQueryObjectui64v,                         /**/ void(APIENTRY*)(GLuint id, GLenum pname, GLuint64* params))
    /// https://docs.gl/gl4/glGetQueryiv           
    GLF_(glGetQueryiv,                                  /**/ void(APIENTRY*)(GLenum target, GLenum pname, GLint* params))
    /// https://docs.gl/gl4/glIsQuery              
    GLF_(glIsQuery,                                     /**/ GLboolean(APIENTRY*)(GLuint id))
    /// https://docs.gl/gl4/glQueryCounter         
    GLF_(glQueryCounter,                                /**/ void(APIENTRY*)(GLuint id, GLenum target))








    /// Syncing                                    


    /// https://docs.gl/gl4/glClientWaitSync       
    GLF_(glClientWaitSync,                              /**/ GLenum(APIENTRY*)(GLsync sync, GLbitfield flags, GLuint64 timeout))
    /// https://docs.gl/gl4/glDeleteSync           
    GLF_(glDeleteSync,                                  /**/ void(APIENTRY*)(GLsync sync))
    /// https://docs.gl/gl4/glFenceSync            
    GLF_(glFenceSync,                                   /**/ GLsync(APIENTRY*)(GLenum condition, GLbitfield flags))
    /// https://docs.gl/gl4/glGetSync              
    GLF_(glGetSynciv,                                   /**/ void(APIENTRY*)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values))
    /// https://docs.gl/gl4/glIsSync               
    GLF_(glIsSync,                                      /**/ GLboolean(APIENTRY*)(GLsync sync))
    /// https://docs.gl/gl4/glTextureBarrier       
    GLF_(glTextureBarrier,                              /**/ void(APIENTRY*)(void))
    /// https://docs.gl/gl4/glWaitSync             
    GLF_(glWaitSync,                                    /**/ void(APIENTRY*)(GLsync sync, GLbitfield flags, GLuint64 timeout))








    /// Vertex Array Objects

    /// https://docs.gl/gl4/glBindVertexArray
    GLF_(glBindVertexArray,                             /**/ void (APIENTRY*)(GLuint array))
    /// https://docs.gl/gl4/glDeleteVertexArrays
    GLF_(glDeleteVertexArrays,                          /**/ void (APIENTRY*)(GLsizei n, GLuint const* arrays))
    /// https://docs.gl/gl4/glGenVertexArrays
    GLF_(glGenVertexArrays,                             /**/ void (APIENTRY*)(GLsizei n, GLuint* arrays))
    /// https://docs.gl/gl4/glBindVertexArray
    GLF_(glIsVertexArray,                               /**/ GLboolean(APIENTRY*)(GLuint array))







    /// Samplers                                   


    /// https://docs.gl/gl4/glBindSampler          
    GLF_(glBindSampler,                                 /**/ void(APIENTRY*)(GLuint unit, GLuint sampler))
    /// https://docs.gl/gl4/glBindSamplers         
    GLF_(glBindSamplers,                                /**/ void(APIENTRY*)(GLuint first, GLsizei count, const GLuint* samplers))
    /// https://docs.gl/gl4/glCreateSamplers       
    GLF_(glCreateSamplers,                              /**/ void(APIENTRY*)(GLsizei n, GLuint* samplers))
    /// https://docs.gl/gl4/glDeleteSamplers       
    GLF_(glDeleteSamplers,                              /**/ void(APIENTRY*)(GLsizei n, const GLuint* samplers))
    /// https://docs.gl/gl4/glGenSamplers          
    GLF_(glGenSamplers,                                 /**/ void(APIENTRY*)(GLsizei n, GLuint* samplers))
    /// https://docs.gl/gl4/glGetSamplerParameter  
    GLF_(glGetSamplerParameterfv,                       /**/ void(APIENTRY*)(GLuint sampler, GLenum pname, GLfloat* params))
    GLF_(glGetSamplerParameteriv,                       /**/ void(APIENTRY*)(GLuint sampler, GLenum pname, GLint* params))
    GLF_(glGetSamplerParameterIiv,                      /**/ void(APIENTRY*)(GLuint sampler, GLenum pname, GLint* params))
    GLF_(glGetSamplerParameterIuiv,                     /**/ void(APIENTRY*)(GLuint sampler, GLenum pname, GLuint* params))
    /// https://docs.gl/gl4/glIsSampler            
    GLF_(glIsSampler,                                   /**/ GLboolean(APIENTRY*)(GLuint id))
    /// https://docs.gl/gl4/glSamplerParameter     
    GLF_(glSamplerParameterf,                           /**/ void(APIENTRY*)(GLuint sampler, GLenum pname, GLfloat param))
    GLF_(glSamplerParameteri,                           /**/ void(APIENTRY*)(GLuint sampler, GLenum pname, GLint param))
    GLF_(glSamplerParameterfv,                          /**/ void(APIENTRY*)(GLuint sampler, GLenum pname, const GLfloat* params))
    GLF_(glSamplerParameteriv,                          /**/ void(APIENTRY*)(GLuint sampler, GLenum pname, const GLint* params))
    GLF_(glSamplerParameterIiv,                         /**/ void(APIENTRY*)(GLuint sampler, GLenum pname, const GLint* params))
    GLF_(glSamplerParameterIuiv,                        /**/ void(APIENTRY*)(GLuint sampler, GLenum pname, const GLuint* params))








    /// ProgramPipelines                           


    /// https://docs.gl/gl4/glActiveShaderProgram  
    GLF_(glActiveShaderProgram,                         /**/ void(APIENTRY*)(GLuint pipeline, GLuint program))
    /// https://docs.gl/gl4/glBindProgramPipeline  
    GLF_(glBindProgramPipeline,                         /**/ void(APIENTRY*)(GLuint pipeline))
    /// https://docs.gl/gl4/glCreateProgramPipelines
    GLF_(glCreateProgramPipelines,                      /**/ void(APIENTRY*)(GLsizei n, GLuint* pipelines))
    /// https://docs.gl/gl4/glDeleteProgramPipelines
    GLF_(glDeleteProgramPipelines,                      /**/ void(APIENTRY*)(GLsizei n, const GLuint* pipelines))
    /// https://docs.gl/gl4/glGenProgramPipelines  
    GLF_(glGenProgramPipelines,                         /**/ void(APIENTRY*)(GLsizei n, GLuint* pipelines))
    /// https://docs.gl/gl4/glGetProgramPipeline   
    GLF_(glGetProgramPipelineiv,                        /**/ void(APIENTRY*)(GLuint pipeline, GLenum pname, GLint* params))
    /// https://docs.gl/gl4/glGetProgramPipelineInfoLog
    GLF_(glGetProgramPipelineInfoLog,                   /**/ void(APIENTRY*)(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog))
    /// https://docs.gl/gl4/glIsProgramPipeline    
    GLF_(glIsProgramPipeline,                           /**/ GLboolean(APIENTRY*)(GLuint pipeline))
    /// https://docs.gl/gl4/glValidateProgramPipeline
    GLF_(glValidateProgramPipeline,                     /**/ void(APIENTRY*)(GLuint pipeline))








    /// Debug                                      


    /// https://docs.gl/gl4/glDebugMessageCallback 
    GLF_(glDebugMessageCallback,                        /**/ void(APIENTRY*)(DEBUGPROC callback, void* userParam))
    /// https://docs.gl/gl4/glDebugMessageControl  
    GLF_(glDebugMessageControl,                         /**/ void(APIENTRY*)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled))
    /// https://docs.gl/gl4/glDebugMessageInsert   
    GLF_(glDebugMessageInsert,                          /**/ void(APIENTRY*)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* message))
    /// https://docs.gl/gl4/glGetDebugMessageLog   
    GLF_(glGetDebugMessageLog,                          /**/ GLuint(APIENTRY*)(GLuint count, GLsizei bufSize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog))
    /// https://docs.gl/gl4/glGetObjectLabel       
    GLF_(glGetObjectLabel,                              /**/ void(APIENTRY*)(GLenum identifier, GLuint name, GLsizei bifSize, GLsizei* length, char* label))
    /// https://docs.gl/gl4/glGetObjectPtrLabel    
    GLF_(glGetObjectPtrLabel,                           /**/ void(APIENTRY*)(void* ptr, GLsizei bifSize, GLsizei* length, char* label))
    /// https://docs.gl/gl4/glGetPointerv          
    GLF_(glGetPointerv,                                 /**/ void(APIENTRY*)(GLenum pname, GLvoid** params))
    /// https://docs.gl/gl4/glGetProgramInterface  
    GLF_(glGetProgramInterfaceiv,                       /**/ void(APIENTRY*)(GLuint program, GLenum programInterface, GLenum pname, GLint* params))
    /// https://docs.gl/gl4/glObjectLabel          
    GLF_(glObjectLabel,                                 /**/ void(APIENTRY*)(GLenum identifier, GLuint name, GLsizei length, const char* label))
    /// https://docs.gl/gl4/glObjectPtrLabel       
    GLF_(glObjectPtrLabel,                              /**/ void(APIENTRY*)(void* ptr, GLsizei length, const char* label))
    /// https://docs.gl/gl4/glPopDebugGroup        
    GLF_(glPopDebugGroup,                               /**/ void(APIENTRY*)(void))
    /// https://docs.gl/gl4/glPushDebugGroup       
    GLF_(glPushDebugGroup,                              /**/ void(APIENTRY*)(GLenum source, GLuint id, GLsizei length, const char* message))

}






















#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS                              0x92D9
#define GL_ACTIVE_ATTRIBUTES                                          0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH                                0x8B8A
#define GL_ACTIVE_PROGRAM                                             0x8259
#define GL_ACTIVE_RESOURCES                                           0x92F5
#define GL_ACTIVE_SUBROUTINES                                         0x8DE5
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH                               0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORMS                                 0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS                        0x8E47
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH                       0x8E49
#define GL_ACTIVE_TEXTURE                                             0x84E0
#define GL_ACTIVE_UNIFORMS                                            0x8B86
#define GL_ACTIVE_UNIFORM_BLOCKS                                      0x8A36
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH                       0x8A35
#define GL_ACTIVE_UNIFORM_MAX_LENGTH                                  0x8B87
#define GL_ACTIVE_VARIABLES                                           0x9305
#define GL_ALIASED_LINE_WIDTH_RANGE                                   0x846E
#define GL_ALL_BARRIER_BITS                                           0xFFFFFFFF
#define GL_ALL_SHADER_BITS                                            0xFFFFFFFF
#define GL_ALPHA                                                      0x1906
#define GL_ALREADY_SIGNALED                                           0x911A
#define GL_ALWAYS                                                     0x0207
#define GL_AND                                                        0x1501
#define GL_AND_INVERTED                                               0x1504
#define GL_AND_REVERSE                                                0x1502
#define GL_ANY_SAMPLES_PASSED                                         0x8C2F
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE                            0x8D6A
#define GL_ARRAY_BUFFER                                               0x8892
#define GL_ARRAY_BUFFER_BINDING                                       0x8894
#define GL_ARRAY_SIZE                                                 0x92FB
#define GL_ARRAY_STRIDE                                               0x92FE
#define GL_ATOMIC_COUNTER_BARRIER_BIT                                 0x00001000
#define GL_ATOMIC_COUNTER_BUFFER                                      0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS               0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES        0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_BINDING                              0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE                            0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_INDEX                                0x9301
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER         0x90ED
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER        0x92CB
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER        0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER    0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER          0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_SIZE                                 0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_START                                0x92C2
#define GL_ATTACHED_SHADERS                                           0x8B85
#define GL_AUTO_GENERATE_MIPMAP                                       0x8295
#define GL_BACK                                                       0x0405
#define GL_BACK_LEFT                                                  0x0402
#define GL_BACK_RIGHT                                                 0x0403
#define GL_BGR                                                        0x80E0
#define GL_BGRA                                                       0x80E1
#define GL_BGRA_INTEGER                                               0x8D9B
#define GL_BGR_INTEGER                                                0x8D9A
#define GL_BLEND                                                      0x0BE2
#define GL_BLEND_COLOR                                                0x8005
#define GL_BLEND_DST                                                  0x0BE0
#define GL_BLEND_DST_ALPHA                                            0x80CA
#define GL_BLEND_DST_RGB                                              0x80C8
#define GL_BLEND_EQUATION                                             0x8009
#define GL_BLEND_EQUATION_ALPHA                                       0x883D
#define GL_BLEND_EQUATION_RGB                                         0x8009
#define GL_BLEND_SRC                                                  0x0BE1
#define GL_BLEND_SRC_ALPHA                                            0x80CB
#define GL_BLEND_SRC_RGB                                              0x80C9
#define GL_BLOCK_INDEX                                                0x92FD
#define GL_BLUE                                                       0x1905
#define GL_BLUE_INTEGER                                               0x8D96
#define GL_BOOL                                                       0x8B56
#define GL_BOOL_VEC2                                                  0x8B57
#define GL_BOOL_VEC3                                                  0x8B58
#define GL_BOOL_VEC4                                                  0x8B59
#define GL_BUFFER                                                     0x82E0
#define GL_BUFFER_ACCESS                                              0x88BB
#define GL_BUFFER_ACCESS_FLAGS                                        0x911F
#define GL_BUFFER_BINDING                                             0x9302
#define GL_BUFFER_DATA_SIZE                                           0x9303
#define GL_BUFFER_IMMUTABLE_STORAGE                                   0x821F
#define GL_BUFFER_MAPPED                                              0x88BC
#define GL_BUFFER_MAP_LENGTH                                          0x9120
#define GL_BUFFER_MAP_OFFSET                                          0x9121
#define GL_BUFFER_MAP_POINTER                                         0x88BD
#define GL_BUFFER_SIZE                                                0x8764
#define GL_BUFFER_STORAGE_FLAGS                                       0x8220
#define GL_BUFFER_UPDATE_BARRIER_BIT                                  0x00000200
#define GL_BUFFER_USAGE                                               0x8765
#define GL_BUFFER_VARIABLE                                            0x92E5
#define GL_BYTE                                                       0x1400
#define GL_CAVEAT_SUPPORT                                             0x82B8
#define GL_CCW                                                        0x0901
#define GL_CLAMP_READ_COLOR                                           0x891C
#define GL_CLAMP_TO_BORDER                                            0x812D
#define GL_CLAMP_TO_EDGE                                              0x812F
#define GL_CLEAR                                                      0x1500
#define GL_CLEAR_BUFFER                                               0x82B4
#define GL_CLEAR_TEXTURE                                              0x9365
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT                           0x00004000
#define GL_CLIENT_STORAGE_BIT                                         0x0200
#define GL_CLIPPING_INPUT_PRIMITIVES                                  0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES                                 0x82F7
#define GL_CLIP_DEPTH_MODE                                            0x935D
#define GL_CLIP_DISTANCE0                                             0x3000
#define GL_CLIP_DISTANCE1                                             0x3001
#define GL_CLIP_DISTANCE2                                             0x3002
#define GL_CLIP_DISTANCE3                                             0x3003
#define GL_CLIP_DISTANCE4                                             0x3004
#define GL_CLIP_DISTANCE5                                             0x3005
#define GL_CLIP_DISTANCE6                                             0x3006
#define GL_CLIP_DISTANCE7                                             0x3007
#define GL_CLIP_ORIGIN                                                0x935C
#define GL_COLOR                                                      0x1800
#define GL_COLOR_ATTACHMENT0                                          0x8CE0
#define GL_COLOR_ATTACHMENT1                                          0x8CE1
#define GL_COLOR_ATTACHMENT10                                         0x8CEA
#define GL_COLOR_ATTACHMENT11                                         0x8CEB
#define GL_COLOR_ATTACHMENT12                                         0x8CEC
#define GL_COLOR_ATTACHMENT13                                         0x8CED
#define GL_COLOR_ATTACHMENT14                                         0x8CEE
#define GL_COLOR_ATTACHMENT15                                         0x8CEF
#define GL_COLOR_ATTACHMENT16                                         0x8CF0
#define GL_COLOR_ATTACHMENT17                                         0x8CF1
#define GL_COLOR_ATTACHMENT18                                         0x8CF2
#define GL_COLOR_ATTACHMENT19                                         0x8CF3
#define GL_COLOR_ATTACHMENT2                                          0x8CE2
#define GL_COLOR_ATTACHMENT20                                         0x8CF4
#define GL_COLOR_ATTACHMENT21                                         0x8CF5
#define GL_COLOR_ATTACHMENT22                                         0x8CF6
#define GL_COLOR_ATTACHMENT23                                         0x8CF7
#define GL_COLOR_ATTACHMENT24                                         0x8CF8
#define GL_COLOR_ATTACHMENT25                                         0x8CF9
#define GL_COLOR_ATTACHMENT26                                         0x8CFA
#define GL_COLOR_ATTACHMENT27                                         0x8CFB
#define GL_COLOR_ATTACHMENT28                                         0x8CFC
#define GL_COLOR_ATTACHMENT29                                         0x8CFD
#define GL_COLOR_ATTACHMENT3                                          0x8CE3
#define GL_COLOR_ATTACHMENT30                                         0x8CFE
#define GL_COLOR_ATTACHMENT31                                         0x8CFF
#define GL_COLOR_ATTACHMENT4                                          0x8CE4
#define GL_COLOR_ATTACHMENT5                                          0x8CE5
#define GL_COLOR_ATTACHMENT6                                          0x8CE6
#define GL_COLOR_ATTACHMENT7                                          0x8CE7
#define GL_COLOR_ATTACHMENT8                                          0x8CE8
#define GL_COLOR_ATTACHMENT9                                          0x8CE9
#define GL_COLOR_BUFFER_BIT                                           0x00004000
#define GL_COLOR_CLEAR_VALUE                                          0x0C22
#define GL_COLOR_COMPONENTS                                           0x8283
#define GL_COLOR_ENCODING                                             0x8296
#define GL_COLOR_LOGIC_OP                                             0x0BF2
#define GL_COLOR_RENDERABLE                                           0x8286
#define GL_COLOR_WRITEMASK                                            0x0C23
#define GL_COMMAND_BARRIER_BIT                                        0x00000040
#define GL_COMPARE_REF_TO_TEXTURE                                     0x884E
#define GL_COMPATIBLE_SUBROUTINES                                     0x8E4B
#define GL_COMPILE_STATUS                                             0x8B81
#define GL_COMPRESSED_R11_EAC                                         0x9270
#define GL_COMPRESSED_RED                                             0x8225
#define GL_COMPRESSED_RED_RGTC1                                       0x8DBB
#define GL_COMPRESSED_RG                                              0x8226
#define GL_COMPRESSED_RG11_EAC                                        0x9272
#define GL_COMPRESSED_RGB                                             0x84ED
#define GL_COMPRESSED_RGB8_ETC2                                       0x9274
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2                   0x9276
#define GL_COMPRESSED_RGBA                                            0x84EE
#define GL_COMPRESSED_RGBA8_ETC2_EAC                                  0x9278
#define GL_COMPRESSED_RGBA_BPTC_UNORM                                 0x8E8C
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT                           0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT                         0x8E8F
#define GL_COMPRESSED_RG_RGTC2                                        0x8DBD
#define GL_COMPRESSED_SIGNED_R11_EAC                                  0x9271
#define GL_COMPRESSED_SIGNED_RED_RGTC1                                0x8DBC
#define GL_COMPRESSED_SIGNED_RG11_EAC                                 0x9273
#define GL_COMPRESSED_SIGNED_RG_RGTC2                                 0x8DBE
#define GL_COMPRESSED_SRGB                                            0x8C48
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC                           0x9279
#define GL_COMPRESSED_SRGB8_ETC2                                      0x9275
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2                  0x9277
#define GL_COMPRESSED_SRGB_ALPHA                                      0x8C49
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM                           0x8E8D
#define GL_COMPRESSED_TEXTURE_FORMATS                                 0x86A3
#define GL_COMPUTE_SHADER                                             0x91B9
#define GL_COMPUTE_SHADER_BIT                                         0x00000020
#define GL_COMPUTE_SHADER_INVOCATIONS                                 0x82F5
#define GL_COMPUTE_SUBROUTINE                                         0x92ED
#define GL_COMPUTE_SUBROUTINE_UNIFORM                                 0x92F3
#define GL_COMPUTE_TEXTURE                                            0x82A0
#define GL_COMPUTE_WORK_GROUP_SIZE                                    0x8267
#define GL_CONDITION_SATISFIED                                        0x911C
#define GL_CONSTANT_ALPHA                                             0x8003
#define GL_CONSTANT_COLOR                                             0x8001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT                          0x00000002
#define GL_CONTEXT_CORE_PROFILE_BIT                                   0x00000001
#define GL_CONTEXT_FLAGS                                              0x821E
#define GL_CONTEXT_FLAG_DEBUG_BIT                                     0x00000002
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT                        0x00000001
#define GL_CONTEXT_FLAG_NO_ERROR_BIT                                  0x00000008
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT                             0x00000004
#define GL_CONTEXT_LOST                                               0x0507
#define GL_CONTEXT_PROFILE_MASK                                       0x9126
#define GL_CONTEXT_RELEASE_BEHAVIOR                                   0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH                             0x82FC
#define GL_COPY                                                       0x1503
#define GL_COPY_INVERTED                                              0x150C
#define GL_COPY_READ_BUFFER                                           0x8F36
#define GL_COPY_READ_BUFFER_BINDING                                   0x8F36
#define GL_COPY_WRITE_BUFFER                                          0x8F37
#define GL_COPY_WRITE_BUFFER_BINDING                                  0x8F37
#define GL_CULL_FACE                                                  0x0B44
#define GL_CULL_FACE_MODE                                             0x0B45
#define GL_CURRENT_PROGRAM                                            0x8B8D
#define GL_CURRENT_QUERY                                              0x8865
#define GL_CURRENT_VERTEX_ATTRIB                                      0x8626
#define GL_CW                                                         0x0900
#define GL_DEBUG_CALLBACK_FUNCTION                                    0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM                                  0x8245
#define GL_DEBUG_GROUP_STACK_DEPTH                                    0x826D
#define GL_DEBUG_LOGGED_MESSAGES                                      0x9145
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH                           0x8243
#define GL_DEBUG_OUTPUT                                               0x92E0
#define GL_DEBUG_OUTPUT_SYNCHRONOUS                                   0x8242
#define GL_DEBUG_SEVERITY_HIGH                                        0x9146
#define GL_DEBUG_SEVERITY_LOW                                         0x9148
#define GL_DEBUG_SEVERITY_MEDIUM                                      0x9147
#define GL_DEBUG_SEVERITY_NOTIFICATION                                0x826B
#define GL_DEBUG_SOURCE_API                                           0x8246
#define GL_DEBUG_SOURCE_APPLICATION                                   0x824A
#define GL_DEBUG_SOURCE_OTHER                                         0x824B
#define GL_DEBUG_SOURCE_SHADER_COMPILER                               0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY                                   0x8249
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM                                 0x8247
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR                             0x824D
#define GL_DEBUG_TYPE_ERROR                                           0x824C
#define GL_DEBUG_TYPE_MARKER                                          0x8268
#define GL_DEBUG_TYPE_OTHER                                           0x8251
#define GL_DEBUG_TYPE_PERFORMANCE                                     0x8250
#define GL_DEBUG_TYPE_POP_GROUP                                       0x826A
#define GL_DEBUG_TYPE_PORTABILITY                                     0x824F
#define GL_DEBUG_TYPE_PUSH_GROUP                                      0x8269
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR                              0x824E
#define GL_DECR                                                       0x1E03
#define GL_DECR_WRAP                                                  0x8508
#define GL_DELETE_STATUS                                              0x8B80
#define GL_DEPTH                                                      0x1801
#define GL_DEPTH24_STENCIL8                                           0x88F0
#define GL_DEPTH32F_STENCIL8                                          0x8CAD
#define GL_DEPTH_ATTACHMENT                                           0x8D00
#define GL_DEPTH_BUFFER_BIT                                           0x00000100
#define GL_DEPTH_CLAMP                                                0x864F
#define GL_DEPTH_CLEAR_VALUE                                          0x0B73
#define GL_DEPTH_COMPONENT16                                          0x81A5
#define GL_DEPTH_COMPONENT24                                          0x81A6
#define GL_DEPTH_COMPONENT32                                          0x81A7
#define GL_DEPTH_COMPONENT32F                                         0x8CAC
#define GL_DEPTH_COMPONENTS                                           0x8284
#define GL_DEPTH_FUNC                                                 0x0B74
#define GL_DEPTH_RANGE                                                0x0B70
#define GL_DEPTH_RENDERABLE                                           0x8287
#define GL_DEPTH_STENCIL                                              0x84F9
#define GL_DEPTH_STENCIL_ATTACHMENT                                   0x821A
#define GL_DEPTH_STENCIL_TEXTURE_MODE                                 0x90EA
#define GL_DEPTH_TEST                                                 0x0B71
#define GL_DEPTH_WRITEMASK                                            0x0B72
#define GL_DISPATCH_INDIRECT_BUFFER                                   0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING                           0x90EF
#define GL_DITHER                                                     0x0BD0
#define GL_DONT_CARE                                                  0x1100
#define GL_DOUBLE                                                     0x140A
#define GL_DOUBLEBUFFER                                               0x0C32
#define GL_DOUBLE_MAT2                                                0x8F46
#define GL_DOUBLE_MAT2x3                                              0x8F49
#define GL_DOUBLE_MAT2x4                                              0x8F4A
#define GL_DOUBLE_MAT3                                                0x8F47
#define GL_DOUBLE_MAT3x2                                              0x8F4B
#define GL_DOUBLE_MAT3x4                                              0x8F4C
#define GL_DOUBLE_MAT4                                                0x8F48
#define GL_DOUBLE_MAT4x2                                              0x8F4D
#define GL_DOUBLE_MAT4x3                                              0x8F4E
#define GL_DOUBLE_VEC2                                                0x8FFC
#define GL_DOUBLE_VEC3                                                0x8FFD
#define GL_DOUBLE_VEC4                                                0x8FFE
#define GL_DRAW_BUFFER                                                0x0C01
#define GL_DRAW_BUFFER0                                               0x8825
#define GL_DRAW_BUFFER1                                               0x8826
#define GL_DRAW_BUFFER10                                              0x882F
#define GL_DRAW_BUFFER11                                              0x8830
#define GL_DRAW_BUFFER12                                              0x8831
#define GL_DRAW_BUFFER13                                              0x8832
#define GL_DRAW_BUFFER14                                              0x8833
#define GL_DRAW_BUFFER15                                              0x8834
#define GL_DRAW_BUFFER2                                               0x8827
#define GL_DRAW_BUFFER3                                               0x8828
#define GL_DRAW_BUFFER4                                               0x8829
#define GL_DRAW_BUFFER5                                               0x882A
#define GL_DRAW_BUFFER6                                               0x882B
#define GL_DRAW_BUFFER7                                               0x882C
#define GL_DRAW_BUFFER8                                               0x882D
#define GL_DRAW_BUFFER9                                               0x882E
#define GL_DRAW_FRAMEBUFFER                                           0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING                                   0x8CA6
#define GL_DRAW_INDIRECT_BUFFER                                       0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING                               0x8F43
#define GL_DST_ALPHA                                                  0x0304
#define GL_DST_COLOR                                                  0x0306
#define GL_DYNAMIC_COPY                                               0x88EA
#define GL_DYNAMIC_DRAW                                               0x88E8
#define GL_DYNAMIC_READ                                               0x88E9
#define GL_DYNAMIC_STORAGE_BIT                                        0x0100
#define GL_ELEMENT_ARRAY_BARRIER_BIT                                  0x00000002
#define GL_ELEMENT_ARRAY_BUFFER                                       0x8893
#define GL_ELEMENT_ARRAY_BUFFER_BINDING                               0x8895
#define GL_EQUAL                                                      0x0202
#define GL_EQUIV                                                      0x1509
#define GL_EXTENSIONS                                                 0x1F03
#define GL_FALSE                                                      0
#define GL_FASTEST                                                    0x1101
#define GL_FILL                                                       0x1B02
#define GL_FILTER                                                     0x829A
#define GL_FIRST_VERTEX_CONVENTION                                    0x8E4D
#define GL_FIXED                                                      0x140C
#define GL_FIXED_ONLY                                                 0x891D
#define GL_FLOAT                                                      0x1406
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV                             0x8DAD
#define GL_FLOAT_MAT2                                                 0x8B5A
#define GL_FLOAT_MAT2x3                                               0x8B65
#define GL_FLOAT_MAT2x4                                               0x8B66
#define GL_FLOAT_MAT3                                                 0x8B5B
#define GL_FLOAT_MAT3x2                                               0x8B67
#define GL_FLOAT_MAT3x4                                               0x8B68
#define GL_FLOAT_MAT4                                                 0x8B5C
#define GL_FLOAT_MAT4x2                                               0x8B69
#define GL_FLOAT_MAT4x3                                               0x8B6A
#define GL_FLOAT_VEC2                                                 0x8B50
#define GL_FLOAT_VEC3                                                 0x8B51
#define GL_FLOAT_VEC4                                                 0x8B52
#define GL_FRACTIONAL_EVEN                                            0x8E7C
#define GL_FRACTIONAL_ODD                                             0x8E7B
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS                         0x8E5D
#define GL_FRAGMENT_SHADER                                            0x8B30
#define GL_FRAGMENT_SHADER_BIT                                        0x00000002
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT                            0x8B8B
#define GL_FRAGMENT_SHADER_INVOCATIONS                                0x82F4
#define GL_FRAGMENT_SUBROUTINE                                        0x92EC
#define GL_FRAGMENT_SUBROUTINE_UNIFORM                                0x92F2
#define GL_FRAGMENT_TEXTURE                                           0x829F
#define GL_FRAMEBUFFER                                                0x8D40
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE                          0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE                           0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING                      0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE                      0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE                          0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE                          0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED                             0x8DA7
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME                         0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE                         0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE                            0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE                        0x8217
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE               0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER                       0x8CD4
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL                       0x8CD2
#define GL_FRAMEBUFFER_BARRIER_BIT                                    0x00000400
#define GL_FRAMEBUFFER_BINDING                                        0x8CA6
#define GL_FRAMEBUFFER_BLEND                                          0x828B
#define GL_FRAMEBUFFER_COMPLETE                                       0x8CD5
#define GL_FRAMEBUFFER_DEFAULT                                        0x8218
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS                 0x9314
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT                                 0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS                                 0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES                                0x9313
#define GL_FRAMEBUFFER_DEFAULT_WIDTH                                  0x9310
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT                          0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER                         0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS                       0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT                  0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE                         0x8D56
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER                         0x8CDC
#define GL_FRAMEBUFFER_RENDERABLE                                     0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED                             0x828A
#define GL_FRAMEBUFFER_SRGB                                           0x8DB9
#define GL_FRAMEBUFFER_UNDEFINED                                      0x8219
#define GL_FRAMEBUFFER_UNSUPPORTED                                    0x8CDD
#define GL_FRONT                                                      0x0404
#define GL_FRONT_AND_BACK                                             0x0408
#define GL_FRONT_FACE                                                 0x0B46
#define GL_FRONT_LEFT                                                 0x0400
#define GL_FRONT_RIGHT                                                0x0401
#define GL_FULL_SUPPORT                                               0x82B7
#define GL_FUNC_ADD                                                   0x8006
#define GL_FUNC_REVERSE_SUBTRACT                                      0x800B
#define GL_FUNC_SUBTRACT                                              0x800A
#define GL_GEOMETRY_INPUT_TYPE                                        0x8917
#define GL_GEOMETRY_OUTPUT_TYPE                                       0x8918
#define GL_GEOMETRY_SHADER                                            0x8DD9
#define GL_GEOMETRY_SHADER_BIT                                        0x00000004
#define GL_GEOMETRY_SHADER_INVOCATIONS                                0x887F
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED                         0x82F3
#define GL_GEOMETRY_SUBROUTINE                                        0x92EB
#define GL_GEOMETRY_SUBROUTINE_UNIFORM                                0x92F1
#define GL_GEOMETRY_TEXTURE                                           0x829E
#define GL_GEOMETRY_VERTICES_OUT                                      0x8916
#define GL_GEQUAL                                                     0x0206
#define GL_GET_TEXTURE_IMAGE_FORMAT                                   0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE                                     0x8292
#define GL_GREATER                                                    0x0204
#define GL_GREEN                                                      0x1904
#define GL_GREEN_INTEGER                                              0x8D95
#define GL_GUILTY_CONTEXT_RESET                                       0x8253
#define GL_HALF_FLOAT                                                 0x140B
#define GL_HIGH_FLOAT                                                 0x8DF2
#define GL_HIGH_INT                                                   0x8DF5
#define GL_IMAGE_1D                                                   0x904C
#define GL_IMAGE_1D_ARRAY                                             0x9052
#define GL_IMAGE_2D                                                   0x904D
#define GL_IMAGE_2D_ARRAY                                             0x9053
#define GL_IMAGE_2D_MULTISAMPLE                                       0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY                                 0x9056
#define GL_IMAGE_2D_RECT                                              0x904F
#define GL_IMAGE_3D                                                   0x904E
#define GL_IMAGE_BINDING_ACCESS                                       0x8F3E
#define GL_IMAGE_BINDING_FORMAT                                       0x906E
#define GL_IMAGE_BINDING_LAYER                                        0x8F3D
#define GL_IMAGE_BINDING_LAYERED                                      0x8F3C
#define GL_IMAGE_BINDING_LEVEL                                        0x8F3B
#define GL_IMAGE_BINDING_NAME                                         0x8F3A
#define GL_IMAGE_BUFFER                                               0x9051
#define GL_IMAGE_CLASS_10_10_10_2                                     0x82C3
#define GL_IMAGE_CLASS_11_11_10                                       0x82C2
#define GL_IMAGE_CLASS_1_X_16                                         0x82BE
#define GL_IMAGE_CLASS_1_X_32                                         0x82BB
#define GL_IMAGE_CLASS_1_X_8                                          0x82C1
#define GL_IMAGE_CLASS_2_X_16                                         0x82BD
#define GL_IMAGE_CLASS_2_X_32                                         0x82BA
#define GL_IMAGE_CLASS_2_X_8                                          0x82C0
#define GL_IMAGE_CLASS_4_X_16                                         0x82BC
#define GL_IMAGE_CLASS_4_X_32                                         0x82B9
#define GL_IMAGE_CLASS_4_X_8                                          0x82BF
#define GL_IMAGE_COMPATIBILITY_CLASS                                  0x82A8
#define GL_IMAGE_CUBE                                                 0x9050
#define GL_IMAGE_CUBE_MAP_ARRAY                                       0x9054
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS                        0x90C9
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE                         0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE                            0x90C7
#define GL_IMAGE_PIXEL_FORMAT                                         0x82A9
#define GL_IMAGE_PIXEL_TYPE                                           0x82AA
#define GL_IMAGE_TEXEL_SIZE                                           0x82A7
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT                           0x8B9B
#define GL_IMPLEMENTATION_COLOR_READ_TYPE                             0x8B9A
#define GL_INCR                                                       0x1E02
#define GL_INCR_WRAP                                                  0x8507
#define GL_INFO_LOG_LENGTH                                            0x8B84
#define GL_INNOCENT_CONTEXT_RESET                                     0x8254
#define GL_INT                                                        0x1404
#define GL_INTERLEAVED_ATTRIBS                                        0x8C8C
#define GL_INTERNALFORMAT_ALPHA_SIZE                                  0x8274
#define GL_INTERNALFORMAT_ALPHA_TYPE                                  0x827B
#define GL_INTERNALFORMAT_BLUE_SIZE                                   0x8273
#define GL_INTERNALFORMAT_BLUE_TYPE                                   0x827A
#define GL_INTERNALFORMAT_DEPTH_SIZE                                  0x8275
#define GL_INTERNALFORMAT_DEPTH_TYPE                                  0x827C
#define GL_INTERNALFORMAT_GREEN_SIZE                                  0x8272
#define GL_INTERNALFORMAT_GREEN_TYPE                                  0x8279
#define GL_INTERNALFORMAT_PREFERRED                                   0x8270
#define GL_INTERNALFORMAT_RED_SIZE                                    0x8271
#define GL_INTERNALFORMAT_RED_TYPE                                    0x8278
#define GL_INTERNALFORMAT_SHARED_SIZE                                 0x8277
#define GL_INTERNALFORMAT_STENCIL_SIZE                                0x8276
#define GL_INTERNALFORMAT_STENCIL_TYPE                                0x827D
#define GL_INTERNALFORMAT_SUPPORTED                                   0x826F
#define GL_INT_2_10_10_10_REV                                         0x8D9F
#define GL_INT_IMAGE_1D                                               0x9057
#define GL_INT_IMAGE_1D_ARRAY                                         0x905D
#define GL_INT_IMAGE_2D                                               0x9058
#define GL_INT_IMAGE_2D_ARRAY                                         0x905E
#define GL_INT_IMAGE_2D_MULTISAMPLE                                   0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY                             0x9061
#define GL_INT_IMAGE_2D_RECT                                          0x905A
#define GL_INT_IMAGE_3D                                               0x9059
#define GL_INT_IMAGE_BUFFER                                           0x905C
#define GL_INT_IMAGE_CUBE                                             0x905B
#define GL_INT_IMAGE_CUBE_MAP_ARRAY                                   0x905F
#define GL_INT_SAMPLER_1D                                             0x8DC9
#define GL_INT_SAMPLER_1D_ARRAY                                       0x8DCE
#define GL_INT_SAMPLER_2D                                             0x8DCA
#define GL_INT_SAMPLER_2D_ARRAY                                       0x8DCF
#define GL_INT_SAMPLER_2D_MULTISAMPLE                                 0x9109
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY                           0x910C
#define GL_INT_SAMPLER_2D_RECT                                        0x8DCD
#define GL_INT_SAMPLER_3D                                             0x8DCB
#define GL_INT_SAMPLER_BUFFER                                         0x8DD0
#define GL_INT_SAMPLER_CUBE                                           0x8DCC
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY                                 0x900E
#define GL_INT_VEC2                                                   0x8B53
#define GL_INT_VEC3                                                   0x8B54
#define GL_INT_VEC4                                                   0x8B55
#define GL_INVALID_ENUM                                               0x0500
#define GL_INVALID_FRAMEBUFFER_OPERATION                              0x0506
#define GL_INVALID_INDEX                                              0xFFFFFFFF
#define GL_INVALID_OPERATION                                          0x0502
#define GL_INVALID_VALUE                                              0x0501
#define GL_INVERT                                                     0x150A
#define GL_ISOLINES                                                   0x8E7A
#define GL_IS_PER_PATCH                                               0x92E7
#define GL_IS_ROW_MAJOR                                               0x9300
#define GL_KEEP                                                       0x1E00
#define GL_LAST_VERTEX_CONVENTION                                     0x8E4E
#define GL_LAYER_PROVOKING_VERTEX                                     0x825E
#define GL_LEFT                                                       0x0406
#define GL_LEQUAL                                                     0x0203
#define GL_LESS                                                       0x0201
#define GL_LINE                                                       0x1B01
#define GL_LINEAR                                                     0x2601
#define GL_LINEAR_MIPMAP_LINEAR                                       0x2703
#define GL_LINEAR_MIPMAP_NEAREST                                      0x2701
#define GL_LINES                                                      0x0001
#define GL_LINES_ADJACENCY                                            0x000A
#define GL_LINE_LOOP                                                  0x0002
#define GL_LINE_SMOOTH                                                0x0B20
#define GL_LINE_SMOOTH_HINT                                           0x0C52
#define GL_LINE_STRIP                                                 0x0003
#define GL_LINE_STRIP_ADJACENCY                                       0x000B
#define GL_LINE_WIDTH                                                 0x0B21
#define GL_LINE_WIDTH_GRANULARITY                                     0x0B23
#define GL_LINE_WIDTH_RANGE                                           0x0B22
#define GL_LINK_STATUS                                                0x8B82
#define GL_LOCATION                                                   0x930E
#define GL_LOCATION_COMPONENT                                         0x934A
#define GL_LOCATION_INDEX                                             0x930F
#define GL_LOGIC_OP_MODE                                              0x0BF0
#define GL_LOSE_CONTEXT_ON_RESET                                      0x8252
#define GL_LOWER_LEFT                                                 0x8CA1
#define GL_LOW_FLOAT                                                  0x8DF0
#define GL_LOW_INT                                                    0x8DF3
#define GL_MAJOR_VERSION                                              0x821B
#define GL_MANUAL_GENERATE_MIPMAP                                     0x8294
#define GL_MAP_COHERENT_BIT                                           0x0080
#define GL_MAP_FLUSH_EXPLICIT_BIT                                     0x0010
#define GL_MAP_INVALIDATE_BUFFER_BIT                                  0x0008
#define GL_MAP_INVALIDATE_RANGE_BIT                                   0x0004
#define GL_MAP_PERSISTENT_BIT                                         0x0040
#define GL_MAP_READ_BIT                                               0x0001
#define GL_MAP_UNSYNCHRONIZED_BIT                                     0x0020
#define GL_MAP_WRITE_BIT                                              0x0002
#define GL_MATRIX_STRIDE                                              0x92FF
#define GL_MAX                                                        0x8008
#define GL_MAX_3D_TEXTURE_SIZE                                        0x8073
#define GL_MAX_ARRAY_TEXTURE_LAYERS                                   0x88FF
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS                         0x92DC
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE                             0x92D8
#define GL_MAX_CLIP_DISTANCES                                         0x0D32
#define GL_MAX_COLOR_ATTACHMENTS                                      0x8CDF
#define GL_MAX_COLOR_TEXTURE_SAMPLES                                  0x910E
#define GL_MAX_COMBINED_ATOMIC_COUNTERS                               0x92D7
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS                        0x92D1
#define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES                       0x82FA
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS                    0x8266
#define GL_MAX_COMBINED_DIMENSIONS                                    0x8282
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS                   0x8A33
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS                   0x8A32
#define GL_MAX_COMBINED_IMAGE_UNIFORMS                                0x90CF
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS              0x8F39
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES                       0x8F39
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS                         0x90DC
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS               0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS            0x8E1F
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS                           0x8B4D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS                                0x8A2E
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS                     0x8A31
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS                                0x8265
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS                         0x8264
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS                                 0x91BD
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS                          0x90DB
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE                             0x8262
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS                            0x91BC
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS                                 0x91BB
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS                             0x8263
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT                               0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS                         0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE                                0x91BF
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE                                  0x851C
#define GL_MAX_CULL_DISTANCES                                         0x82F9
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH                                0x826C
#define GL_MAX_DEBUG_LOGGED_MESSAGES                                  0x9144
#define GL_MAX_DEBUG_MESSAGE_LENGTH                                   0x9143
#define GL_MAX_DEPTH                                                  0x8280
#define GL_MAX_DEPTH_TEXTURE_SAMPLES                                  0x910F
#define GL_MAX_DRAW_BUFFERS                                           0x8824
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS                               0x88FC
#define GL_MAX_ELEMENTS_INDICES                                       0x80E9
#define GL_MAX_ELEMENTS_VERTICES                                      0x80E8
#define GL_MAX_ELEMENT_INDEX                                          0x8D6B
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS                               0x92D6
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS                        0x92D0
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS                                0x90CE
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS                              0x9125
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET                          0x8E5C
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS                         0x90DA
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS                                0x8A2D
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS                            0x8B49
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS                               0x8DFD
#define GL_MAX_FRAMEBUFFER_HEIGHT                                     0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS                                     0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES                                    0x9318
#define GL_MAX_FRAMEBUFFER_WIDTH                                      0x9315
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS                               0x92D5
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS                        0x92CF
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS                                0x90CD
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS                              0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS                             0x9124
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES                               0x8DE0
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS                            0x8E5A
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS                         0x90D7
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS                           0x8C29
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS                       0x8DE1
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS                                0x8A2C
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS                            0x8DDF
#define GL_MAX_HEIGHT                                                 0x827F
#define GL_MAX_IMAGE_SAMPLES                                          0x906D
#define GL_MAX_IMAGE_UNITS                                            0x8F38
#define GL_MAX_INTEGER_SAMPLES                                        0x9110
#define GL_MAX_LABEL_LENGTH                                           0x82E8
#define GL_MAX_LAYERS                                                 0x8281
#define GL_MAX_NAME_LENGTH                                            0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES                                   0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES                             0x92F8
#define GL_MAX_PATCH_VERTICES                                         0x8E7D
#define GL_MAX_PROGRAM_TEXEL_OFFSET                                   0x8905
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET                          0x8E5F
#define GL_MAX_RECTANGLE_TEXTURE_SIZE                                 0x84F8
#define GL_MAX_RENDERBUFFER_SIZE                                      0x84E8
#define GL_MAX_SAMPLES                                                0x8D57
#define GL_MAX_SAMPLE_MASK_WORDS                                      0x8E59
#define GL_MAX_SERVER_WAIT_TIMEOUT                                    0x9111
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE                              0x90DE
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS                         0x90DD
#define GL_MAX_SUBROUTINES                                            0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS                           0x8DE8
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS                           0x92D3
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS                    0x92CD
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS                            0x90CB
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS                          0x886C
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS                         0x8E83
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS                     0x90D8
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS                       0x8E81
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS                   0x8E85
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS                            0x8E89
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS                        0x8E7F
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS                        0x92D4
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS                 0x92CE
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS                         0x90CC
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS                       0x886D
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS                      0x8E86
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS                  0x90D9
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS                    0x8E82
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS                         0x8E8A
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS                     0x8E80
#define GL_MAX_TESS_GEN_LEVEL                                         0x8E7E
#define GL_MAX_TESS_PATCH_COMPONENTS                                  0x8E84
#define GL_MAX_TEXTURE_BUFFER_SIZE                                    0x8C2B
#define GL_MAX_TEXTURE_IMAGE_UNITS                                    0x8872
#define GL_MAX_TEXTURE_LOD_BIAS                                       0x84FD
#define GL_MAX_TEXTURE_MAX_ANISOTROPY                                 0x84FF
#define GL_MAX_TEXTURE_SIZE                                           0x0D33
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS                             0x8E70
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS              0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS                    0x8C8B
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS                 0x8C80
#define GL_MAX_UNIFORM_BLOCK_SIZE                                     0x8A30
#define GL_MAX_UNIFORM_BUFFER_BINDINGS                                0x8A2F
#define GL_MAX_UNIFORM_LOCATIONS                                      0x826E
#define GL_MAX_VARYING_COMPONENTS                                     0x8B4B
#define GL_MAX_VARYING_FLOATS                                         0x8B4B
#define GL_MAX_VARYING_VECTORS                                        0x8DFC
#define GL_MAX_VERTEX_ATOMIC_COUNTERS                                 0x92D2
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS                          0x92CC
#define GL_MAX_VERTEX_ATTRIBS                                         0x8869
#define GL_MAX_VERTEX_ATTRIB_BINDINGS                                 0x82DA
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET                          0x82D9
#define GL_MAX_VERTEX_ATTRIB_STRIDE                                   0x82E5
#define GL_MAX_VERTEX_IMAGE_UNIFORMS                                  0x90CA
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS                               0x9122
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS                           0x90D6
#define GL_MAX_VERTEX_STREAMS                                         0x8E71
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS                             0x8B4C
#define GL_MAX_VERTEX_UNIFORM_BLOCKS                                  0x8A2B
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS                              0x8B4A
#define GL_MAX_VERTEX_UNIFORM_VECTORS                                 0x8DFB
#define GL_MAX_VIEWPORTS                                              0x825B
#define GL_MAX_VIEWPORT_DIMS                                          0x0D3A
#define GL_MAX_WIDTH                                                  0x827E
#define GL_MEDIUM_FLOAT                                               0x8DF1
#define GL_MEDIUM_INT                                                 0x8DF4
#define GL_MIN                                                        0x8007
#define GL_MINOR_VERSION                                              0x821C
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET                          0x8E5B
#define GL_MIN_MAP_BUFFER_ALIGNMENT                                   0x90BC
#define GL_MIN_PROGRAM_TEXEL_OFFSET                                   0x8904
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET                          0x8E5E
#define GL_MIN_SAMPLE_SHADING_VALUE                                   0x8C37
#define GL_MIPMAP                                                     0x8293
#define GL_MIRRORED_REPEAT                                            0x8370
#define GL_MIRROR_CLAMP_TO_EDGE                                       0x8743
#define GL_MULTISAMPLE                                                0x809D
#define GL_NAME_LENGTH                                                0x92F9
#define GL_NAND                                                       0x150E
#define GL_NEAREST                                                    0x2600
#define GL_NEAREST_MIPMAP_LINEAR                                      0x2702
#define GL_NEAREST_MIPMAP_NEAREST                                     0x2700
#define GL_NEGATIVE_ONE_TO_ONE                                        0x935E
#define GL_NEVER                                                      0x0200
#define GL_NICEST                                                     0x1102
#define GL_NONE                                                       0
#define GL_NOOP                                                       0x1505
#define GL_NOR                                                        0x1508
#define GL_NOTEQUAL                                                   0x0205
#define GL_NO_ERROR                                                   0
#define GL_NO_RESET_NOTIFICATION                                      0x8261
#define GL_NUM_ACTIVE_VARIABLES                                       0x9304
#define GL_NUM_COMPATIBLE_SUBROUTINES                                 0x8E4A
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS                             0x86A2
#define GL_NUM_EXTENSIONS                                             0x821D
#define GL_NUM_PROGRAM_BINARY_FORMATS                                 0x87FE
#define GL_NUM_SAMPLE_COUNTS                                          0x9380
#define GL_NUM_SHADER_BINARY_FORMATS                                  0x8DF9
#define GL_NUM_SHADING_LANGUAGE_VERSIONS                              0x82E9
#define GL_NUM_SPIR_V_EXTENSIONS                                      0x9554
#define GL_OBJECT_TYPE                                                0x9112
#define GL_OFFSET                                                     0x92FC
#define GL_ONE                                                        1
#define GL_ONE_MINUS_CONSTANT_ALPHA                                   0x8004
#define GL_ONE_MINUS_CONSTANT_COLOR                                   0x8002
#define GL_ONE_MINUS_DST_ALPHA                                        0x0305
#define GL_ONE_MINUS_DST_COLOR                                        0x0307
#define GL_ONE_MINUS_SRC1_ALPHA                                       0x88FB
#define GL_ONE_MINUS_SRC1_COLOR                                       0x88FA
#define GL_ONE_MINUS_SRC_ALPHA                                        0x0303
#define GL_ONE_MINUS_SRC_COLOR                                        0x0301
#define GL_OR                                                         0x1507
#define GL_OR_INVERTED                                                0x150D
#define GL_OR_REVERSE                                                 0x150B
#define GL_OUT_OF_MEMORY                                              0x0505
#define GL_PACK_ALIGNMENT                                             0x0D05
#define GL_PACK_COMPRESSED_BLOCK_DEPTH                                0x912D
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT                               0x912C
#define GL_PACK_COMPRESSED_BLOCK_SIZE                                 0x912E
#define GL_PACK_COMPRESSED_BLOCK_WIDTH                                0x912B
#define GL_PACK_IMAGE_HEIGHT                                          0x806C
#define GL_PACK_LSB_FIRST                                             0x0D01
#define GL_PACK_ROW_LENGTH                                            0x0D02
#define GL_PACK_SKIP_IMAGES                                           0x806B
#define GL_PACK_SKIP_PIXELS                                           0x0D04
#define GL_PACK_SKIP_ROWS                                             0x0D03
#define GL_PACK_SWAP_BYTES                                            0x0D00
#define GL_PARAMETER_BUFFER                                           0x80EE
#define GL_PARAMETER_BUFFER_BINDING                                   0x80EF
#define GL_PATCHES                                                    0x000E
#define GL_PATCH_DEFAULT_INNER_LEVEL                                  0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL                                  0x8E74
#define GL_PATCH_VERTICES                                             0x8E72
#define GL_PIXEL_BUFFER_BARRIER_BIT                                   0x00000080
#define GL_PIXEL_PACK_BUFFER                                          0x88EB
#define GL_PIXEL_PACK_BUFFER_BINDING                                  0x88ED
#define GL_PIXEL_UNPACK_BUFFER                                        0x88EC
#define GL_PIXEL_UNPACK_BUFFER_BINDING                                0x88EF
#define GL_POINT                                                      0x1B00
#define GL_POINTS                                                     0x0000
#define GL_POINT_FADE_THRESHOLD_SIZE                                  0x8128
#define GL_POINT_SIZE                                                 0x0B11
#define GL_POINT_SIZE_GRANULARITY                                     0x0B13
#define GL_POINT_SIZE_RANGE                                           0x0B12
#define GL_POINT_SPRITE_COORD_ORIGIN                                  0x8CA0
#define GL_POLYGON_MODE                                               0x0B40
#define GL_POLYGON_OFFSET_CLAMP                                       0x8E1B
#define GL_POLYGON_OFFSET_FACTOR                                      0x8038
#define GL_POLYGON_OFFSET_FILL                                        0x8037
#define GL_POLYGON_OFFSET_LINE                                        0x2A02
#define GL_POLYGON_OFFSET_POINT                                       0x2A01
#define GL_POLYGON_OFFSET_UNITS                                       0x2A00
#define GL_POLYGON_SMOOTH                                             0x0B41
#define GL_POLYGON_SMOOTH_HINT                                        0x0C53
#define GL_PRIMITIVES_GENERATED                                       0x8C87
#define GL_PRIMITIVES_SUBMITTED                                       0x82EF
#define GL_PRIMITIVE_RESTART                                          0x8F9D
#define GL_PRIMITIVE_RESTART_FIXED_INDEX                              0x8D69
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED                    0x8221
#define GL_PRIMITIVE_RESTART_INDEX                                    0x8F9E
#define GL_PROGRAM                                                    0x82E2
#define GL_PROGRAM_BINARY_FORMATS                                     0x87FF
#define GL_PROGRAM_BINARY_LENGTH                                      0x8741
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT                            0x8257
#define GL_PROGRAM_INPUT                                              0x92E3
#define GL_PROGRAM_OUTPUT                                             0x92E4
#define GL_PROGRAM_PIPELINE                                           0x82E4
#define GL_PROGRAM_PIPELINE_BINDING                                   0x825A
#define GL_PROGRAM_POINT_SIZE                                         0x8642
#define GL_PROGRAM_SEPARABLE                                          0x8258
#define GL_PROVOKING_VERTEX                                           0x8E4F
#define GL_PROXY_TEXTURE_1D                                           0x8063
#define GL_PROXY_TEXTURE_1D_ARRAY                                     0x8C19
#define GL_PROXY_TEXTURE_2D                                           0x8064
#define GL_PROXY_TEXTURE_2D_ARRAY                                     0x8C1B
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE                               0x9101
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY                         0x9103
#define GL_PROXY_TEXTURE_3D                                           0x8070
#define GL_PROXY_TEXTURE_CUBE_MAP                                     0x851B
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY                               0x900B
#define GL_PROXY_TEXTURE_RECTANGLE                                    0x84F7
#define GL_QUADS                                                      0x0007
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION                   0x8E4C
#define GL_QUERY                                                      0x82E3
#define GL_QUERY_BUFFER                                               0x9192
#define GL_QUERY_BUFFER_BARRIER_BIT                                   0x00008000
#define GL_QUERY_BUFFER_BINDING                                       0x9193
#define GL_QUERY_BY_REGION_NO_WAIT                                    0x8E16
#define GL_QUERY_BY_REGION_NO_WAIT_INVERTED                           0x8E1A
#define GL_QUERY_BY_REGION_WAIT                                       0x8E15
#define GL_QUERY_BY_REGION_WAIT_INVERTED                              0x8E19
#define GL_QUERY_COUNTER_BITS                                         0x8864
#define GL_QUERY_NO_WAIT                                              0x8E14
#define GL_QUERY_NO_WAIT_INVERTED                                     0x8E18
#define GL_QUERY_RESULT                                               0x8866
#define GL_QUERY_RESULT_AVAILABLE                                     0x8867
#define GL_QUERY_RESULT_NO_WAIT                                       0x9194
#define GL_QUERY_TARGET                                               0x82EA
#define GL_QUERY_WAIT                                                 0x8E13
#define GL_QUERY_WAIT_INVERTED                                        0x8E17
#define GL_R11F_G11F_B10F                                             0x8C3A
#define GL_R16                                                        0x822A
#define GL_R16F                                                       0x822D
#define GL_R16I                                                       0x8233
#define GL_R16UI                                                      0x8234
#define GL_R16_SNORM                                                  0x8F98
#define GL_R32F                                                       0x822E
#define GL_R32I                                                       0x8235
#define GL_R32UI                                                      0x8236
#define GL_R3_G3_B2                                                   0x2A10
#define GL_R8                                                         0x8229
#define GL_R8I                                                        0x8231
#define GL_R8UI                                                       0x8232
#define GL_R8_SNORM                                                   0x8F94
#define GL_RASTERIZER_DISCARD                                         0x8C89
#define GL_READ_BUFFER                                                0x0C02
#define GL_READ_FRAMEBUFFER                                           0x8CA8
#define GL_READ_FRAMEBUFFER_BINDING                                   0x8CAA
#define GL_READ_ONLY                                                  0x88B8
#define GL_READ_PIXELS                                                0x828C
#define GL_READ_PIXELS_FORMAT                                         0x828D
#define GL_READ_PIXELS_TYPE                                           0x828E
#define GL_READ_WRITE                                                 0x88BA
#define GL_RED                                                        0x1903
#define GL_RED_INTEGER                                                0x8D94
#define GL_REFERENCED_BY_COMPUTE_SHADER                               0x930B
#define GL_REFERENCED_BY_FRAGMENT_SHADER                              0x930A
#define GL_REFERENCED_BY_GEOMETRY_SHADER                              0x9309
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER                          0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER                       0x9308
#define GL_REFERENCED_BY_VERTEX_SHADER                                0x9306
#define GL_RENDERBUFFER                                               0x8D41
#define GL_RENDERBUFFER_ALPHA_SIZE                                    0x8D53
#define GL_RENDERBUFFER_BINDING                                       0x8CA7
#define GL_RENDERBUFFER_BLUE_SIZE                                     0x8D52
#define GL_RENDERBUFFER_DEPTH_SIZE                                    0x8D54
#define GL_RENDERBUFFER_GREEN_SIZE                                    0x8D51
#define GL_RENDERBUFFER_HEIGHT                                        0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT                               0x8D44
#define GL_RENDERBUFFER_RED_SIZE                                      0x8D50
#define GL_RENDERBUFFER_SAMPLES                                       0x8CAB
#define GL_RENDERBUFFER_STENCIL_SIZE                                  0x8D55
#define GL_RENDERBUFFER_WIDTH                                         0x8D42
#define GL_RENDERER                                                   0x1F01
#define GL_REPEAT                                                     0x2901
#define GL_REPLACE                                                    0x1E01
#define GL_RESET_NOTIFICATION_STRATEGY                                0x8256
#define GL_RG                                                         0x8227
#define GL_RG16                                                       0x822C
#define GL_RG16F                                                      0x822F
#define GL_RG16I                                                      0x8239
#define GL_RG16UI                                                     0x823A
#define GL_RG16_SNORM                                                 0x8F99
#define GL_RG32F                                                      0x8230
#define GL_RG32I                                                      0x823B
#define GL_RG32UI                                                     0x823C
#define GL_RG8                                                        0x822B
#define GL_RG8I                                                       0x8237
#define GL_RG8UI                                                      0x8238
#define GL_RG8_SNORM                                                  0x8F95
#define GL_RGB                                                        0x1907
#define GL_RGB10                                                      0x8052
#define GL_RGB10_A2                                                   0x8059
#define GL_RGB10_A2UI                                                 0x906F
#define GL_RGB12                                                      0x8053
#define GL_RGB16                                                      0x8054
#define GL_RGB16F                                                     0x881B
#define GL_RGB16I                                                     0x8D89
#define GL_RGB16UI                                                    0x8D77
#define GL_RGB16_SNORM                                                0x8F9A
#define GL_RGB32F                                                     0x8815
#define GL_RGB32I                                                     0x8D83
#define GL_RGB32UI                                                    0x8D71
#define GL_RGB4                                                       0x804F
#define GL_RGB5                                                       0x8050
#define GL_RGB565                                                     0x8D62
#define GL_RGB5_A1                                                    0x8057
#define GL_RGB8                                                       0x8051
#define GL_RGB8I                                                      0x8D8F
#define GL_RGB8UI                                                     0x8D7D
#define GL_RGB8_SNORM                                                 0x8F96
#define GL_RGB9_E5                                                    0x8C3D
#define GL_RGBA                                                       0x1908
#define GL_RGBA12                                                     0x805A
#define GL_RGBA16                                                     0x805B
#define GL_RGBA16F                                                    0x881A
#define GL_RGBA16I                                                    0x8D88
#define GL_RGBA16UI                                                   0x8D76
#define GL_RGBA16_SNORM                                               0x8F9B
#define GL_RGBA2                                                      0x8055
#define GL_RGBA32F                                                    0x8814
#define GL_RGBA32I                                                    0x8D82
#define GL_RGBA32UI                                                   0x8D70
#define GL_RGBA4                                                      0x8056
#define GL_RGBA8                                                      0x8058
#define GL_RGBA8I                                                     0x8D8E
#define GL_RGBA8UI                                                    0x8D7C
#define GL_RGBA8_SNORM                                                0x8F97
#define GL_RGBA_INTEGER                                               0x8D99
#define GL_RGB_INTEGER                                                0x8D98
#define GL_RG_INTEGER                                                 0x8228
#define GL_RIGHT                                                      0x0407
#define GL_SAMPLER                                                    0x82E6
#define GL_SAMPLER_1D                                                 0x8B5D
#define GL_SAMPLER_1D_ARRAY                                           0x8DC0
#define GL_SAMPLER_1D_ARRAY_SHADOW                                    0x8DC3
#define GL_SAMPLER_1D_SHADOW                                          0x8B61
#define GL_SAMPLER_2D                                                 0x8B5E
#define GL_SAMPLER_2D_ARRAY                                           0x8DC1
#define GL_SAMPLER_2D_ARRAY_SHADOW                                    0x8DC4
#define GL_SAMPLER_2D_MULTISAMPLE                                     0x9108
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY                               0x910B
#define GL_SAMPLER_2D_RECT                                            0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW                                     0x8B64
#define GL_SAMPLER_2D_SHADOW                                          0x8B62
#define GL_SAMPLER_3D                                                 0x8B5F
#define GL_SAMPLER_BINDING                                            0x8919
#define GL_SAMPLER_BUFFER                                             0x8DC2
#define GL_SAMPLER_CUBE                                               0x8B60
#define GL_SAMPLER_CUBE_MAP_ARRAY                                     0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW                              0x900D
#define GL_SAMPLER_CUBE_SHADOW                                        0x8DC5
#define GL_SAMPLES                                                    0x80A9
#define GL_SAMPLES_PASSED                                             0x8914
#define GL_SAMPLE_ALPHA_TO_COVERAGE                                   0x809E
#define GL_SAMPLE_ALPHA_TO_ONE                                        0x809F
#define GL_SAMPLE_BUFFERS                                             0x80A8
#define GL_SAMPLE_COVERAGE                                            0x80A0
#define GL_SAMPLE_COVERAGE_INVERT                                     0x80AB
#define GL_SAMPLE_COVERAGE_VALUE                                      0x80AA
#define GL_SAMPLE_MASK                                                0x8E51
#define GL_SAMPLE_MASK_VALUE                                          0x8E52
#define GL_SAMPLE_POSITION                                            0x8E50
#define GL_SAMPLE_SHADING                                             0x8C36
#define GL_SCISSOR_BOX                                                0x0C10
#define GL_SCISSOR_TEST                                               0x0C11
#define GL_SEPARATE_ATTRIBS                                           0x8C8D
#define GL_SET                                                        0x150F
#define GL_SHADER                                                     0x82E1
#define GL_SHADER_BINARY_FORMATS                                      0x8DF8
#define GL_SHADER_BINARY_FORMAT_SPIR_V                                0x9551
#define GL_SHADER_COMPILER                                            0x8DFA
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT                            0x00000020
#define GL_SHADER_IMAGE_ATOMIC                                        0x82A6
#define GL_SHADER_IMAGE_LOAD                                          0x82A4
#define GL_SHADER_IMAGE_STORE                                         0x82A5
#define GL_SHADER_SOURCE_LENGTH                                       0x8B88
#define GL_SHADER_STORAGE_BARRIER_BIT                                 0x00002000
#define GL_SHADER_STORAGE_BLOCK                                       0x92E6
#define GL_SHADER_STORAGE_BUFFER                                      0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING                              0x90D3
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT                     0x90DF
#define GL_SHADER_STORAGE_BUFFER_SIZE                                 0x90D5
#define GL_SHADER_STORAGE_BUFFER_START                                0x90D4
#define GL_SHADER_TYPE                                                0x8B4F
#define GL_SHADING_LANGUAGE_VERSION                                   0x8B8C
#define GL_SHORT                                                      0x1402
#define GL_SIGNALED                                                   0x9119
#define GL_SIGNED_NORMALIZED                                          0x8F9C
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST                        0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE                       0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST                      0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE                     0x82AF
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY                              0x0B23
#define GL_SMOOTH_LINE_WIDTH_RANGE                                    0x0B22
#define GL_SMOOTH_POINT_SIZE_GRANULARITY                              0x0B13
#define GL_SMOOTH_POINT_SIZE_RANGE                                    0x0B12
#define GL_SPIR_V_BINARY                                              0x9552
#define GL_SPIR_V_EXTENSIONS                                          0x9553
#define GL_SRC1_ALPHA                                                 0x8589
#define GL_SRC1_COLOR                                                 0x88F9
#define GL_SRC_ALPHA                                                  0x0302
#define GL_SRC_ALPHA_SATURATE                                         0x0308
#define GL_SRC_COLOR                                                  0x0300
#define GL_SRGB                                                       0x8C40
#define GL_SRGB8                                                      0x8C41
#define GL_SRGB8_ALPHA8                                               0x8C43
#define GL_SRGB_ALPHA                                                 0x8C42
#define GL_SRGB_READ                                                  0x8297
#define GL_SRGB_WRITE                                                 0x8298
#define GL_STACK_OVERFLOW                                             0x0503
#define GL_STACK_UNDERFLOW                                            0x0504
#define GL_STATIC_COPY                                                0x88E6
#define GL_STATIC_DRAW                                                0x88E4
#define GL_STATIC_READ                                                0x88E5
#define GL_STENCIL                                                    0x1802
#define GL_STENCIL_ATTACHMENT                                         0x8D20
#define GL_STENCIL_BACK_FAIL                                          0x8801
#define GL_STENCIL_BACK_FUNC                                          0x8800
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL                               0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS                               0x8803
#define GL_STENCIL_BACK_REF                                           0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK                                    0x8CA4
#define GL_STENCIL_BACK_WRITEMASK                                     0x8CA5
#define GL_STENCIL_BUFFER_BIT                                         0x00000400
#define GL_STENCIL_CLEAR_VALUE                                        0x0B91
#define GL_STENCIL_COMPONENTS                                         0x8285
#define GL_STENCIL_FAIL                                               0x0B94
#define GL_STENCIL_FUNC                                               0x0B92
#define GL_STENCIL_INDEX                                              0x1901
#define GL_STENCIL_INDEX1                                             0x8D46
#define GL_STENCIL_INDEX16                                            0x8D49
#define GL_STENCIL_INDEX4                                             0x8D47
#define GL_STENCIL_INDEX8                                             0x8D48
#define GL_STENCIL_PASS_DEPTH_FAIL                                    0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS                                    0x0B96
#define GL_STENCIL_REF                                                0x0B97
#define GL_STENCIL_RENDERABLE                                         0x8288
#define GL_STENCIL_TEST                                               0x0B90
#define GL_STENCIL_VALUE_MASK                                         0x0B93
#define GL_STENCIL_WRITEMASK                                          0x0B98
#define GL_STEREO                                                     0x0C33
#define GL_STREAM_COPY                                                0x88E2
#define GL_STREAM_DRAW                                                0x88E0
#define GL_STREAM_READ                                                0x88E1
#define GL_SUBPIXEL_BITS                                              0x0D50
#define GL_SYNC_CONDITION                                             0x9113
#define GL_SYNC_FENCE                                                 0x9116
#define GL_SYNC_FLAGS                                                 0x9115
#define GL_SYNC_FLUSH_COMMANDS_BIT                                    0x00000001
#define GL_SYNC_GPU_COMMANDS_COMPLETE                                 0x9117
#define GL_SYNC_STATUS                                                0x9114
#define GL_TESS_CONTROL_OUTPUT_VERTICES                               0x8E75
#define GL_TESS_CONTROL_SHADER                                        0x8E88
#define GL_TESS_CONTROL_SHADER_BIT                                    0x00000008
#define GL_TESS_CONTROL_SHADER_PATCHES                                0x82F1
#define GL_TESS_CONTROL_SUBROUTINE                                    0x92E9
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM                            0x92EF
#define GL_TESS_CONTROL_TEXTURE                                       0x829C
#define GL_TESS_EVALUATION_SHADER                                     0x8E87
#define GL_TESS_EVALUATION_SHADER_BIT                                 0x00000010
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS                         0x82F2
#define GL_TESS_EVALUATION_SUBROUTINE                                 0x92EA
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM                         0x92F0
#define GL_TESS_EVALUATION_TEXTURE                                    0x829D
#define GL_TESS_GEN_MODE                                              0x8E76
#define GL_TESS_GEN_POINT_MODE                                        0x8E79
#define GL_TESS_GEN_SPACING                                           0x8E77
#define GL_TESS_GEN_VERTEX_ORDER                                      0x8E78
#define GL_TEXTURE                                                    0x1702
#define GL_TEXTURE0                                                   0x84C0
#define GL_TEXTURE1                                                   0x84C1
#define GL_TEXTURE10                                                  0x84CA
#define GL_TEXTURE11                                                  0x84CB
#define GL_TEXTURE12                                                  0x84CC
#define GL_TEXTURE13                                                  0x84CD
#define GL_TEXTURE14                                                  0x84CE
#define GL_TEXTURE15                                                  0x84CF
#define GL_TEXTURE16                                                  0x84D0
#define GL_TEXTURE17                                                  0x84D1
#define GL_TEXTURE18                                                  0x84D2
#define GL_TEXTURE19                                                  0x84D3
#define GL_TEXTURE2                                                   0x84C2
#define GL_TEXTURE20                                                  0x84D4
#define GL_TEXTURE21                                                  0x84D5
#define GL_TEXTURE22                                                  0x84D6
#define GL_TEXTURE23                                                  0x84D7
#define GL_TEXTURE24                                                  0x84D8
#define GL_TEXTURE25                                                  0x84D9
#define GL_TEXTURE26                                                  0x84DA
#define GL_TEXTURE27                                                  0x84DB
#define GL_TEXTURE28                                                  0x84DC
#define GL_TEXTURE29                                                  0x84DD
#define GL_TEXTURE3                                                   0x84C3
#define GL_TEXTURE30                                                  0x84DE
#define GL_TEXTURE31                                                  0x84DF
#define GL_TEXTURE4                                                   0x84C4
#define GL_TEXTURE5                                                   0x84C5
#define GL_TEXTURE6                                                   0x84C6
#define GL_TEXTURE7                                                   0x84C7
#define GL_TEXTURE8                                                   0x84C8
#define GL_TEXTURE9                                                   0x84C9
#define GL_TEXTURE_1D                                                 0x0DE0
#define GL_TEXTURE_1D_ARRAY                                           0x8C18
#define GL_TEXTURE_2D                                                 0x0DE1
#define GL_TEXTURE_2D_ARRAY                                           0x8C1A
#define GL_TEXTURE_2D_MULTISAMPLE                                     0x9100
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY                               0x9102
#define GL_TEXTURE_3D                                                 0x806F
#define GL_TEXTURE_ALPHA_SIZE                                         0x805F
#define GL_TEXTURE_ALPHA_TYPE                                         0x8C13
#define GL_TEXTURE_BASE_LEVEL                                         0x813C
#define GL_TEXTURE_BINDING_1D                                         0x8068
#define GL_TEXTURE_BINDING_1D_ARRAY                                   0x8C1C
#define GL_TEXTURE_BINDING_2D                                         0x8069
#define GL_TEXTURE_BINDING_2D_ARRAY                                   0x8C1D
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE                             0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY                       0x9105
#define GL_TEXTURE_BINDING_3D                                         0x806A
#define GL_TEXTURE_BINDING_BUFFER                                     0x8C2C
#define GL_TEXTURE_BINDING_CUBE_MAP                                   0x8514
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY                             0x900A
#define GL_TEXTURE_BINDING_RECTANGLE                                  0x84F6
#define GL_TEXTURE_BLUE_SIZE                                          0x805E
#define GL_TEXTURE_BLUE_TYPE                                          0x8C12
#define GL_TEXTURE_BORDER_COLOR                                       0x1004
#define GL_TEXTURE_BUFFER                                             0x8C2A
#define GL_TEXTURE_BUFFER_BINDING                                     0x8C2A
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING                          0x8C2D
#define GL_TEXTURE_BUFFER_OFFSET                                      0x919D
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT                            0x919F
#define GL_TEXTURE_BUFFER_SIZE                                        0x919E
#define GL_TEXTURE_COMPARE_FUNC                                       0x884D
#define GL_TEXTURE_COMPARE_MODE                                       0x884C
#define GL_TEXTURE_COMPRESSED                                         0x86A1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT                            0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE                              0x82B3
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH                             0x82B1
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE                              0x86A0
#define GL_TEXTURE_COMPRESSION_HINT                                   0x84EF
#define GL_TEXTURE_CUBE_MAP                                           0x8513
#define GL_TEXTURE_CUBE_MAP_ARRAY                                     0x9009
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X                                0x8516
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y                                0x8518
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z                                0x851A
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X                                0x8515
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y                                0x8517
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z                                0x8519
#define GL_TEXTURE_CUBE_MAP_SEAMLESS                                  0x884F
#define GL_TEXTURE_DEPTH                                              0x8071
#define GL_TEXTURE_DEPTH_SIZE                                         0x884A
#define GL_TEXTURE_DEPTH_TYPE                                         0x8C16
#define GL_TEXTURE_FETCH_BARRIER_BIT                                  0x00000008
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS                             0x9107
#define GL_TEXTURE_GATHER                                             0x82A2
#define GL_TEXTURE_GATHER_SHADOW                                      0x82A3
#define GL_TEXTURE_GREEN_SIZE                                         0x805D
#define GL_TEXTURE_GREEN_TYPE                                         0x8C11
#define GL_TEXTURE_HEIGHT                                             0x1001
#define GL_TEXTURE_IMAGE_FORMAT                                       0x828F
#define GL_TEXTURE_IMAGE_TYPE                                         0x8290
#define GL_TEXTURE_IMMUTABLE_FORMAT                                   0x912F
#define GL_TEXTURE_IMMUTABLE_LEVELS                                   0x82DF
#define GL_TEXTURE_INTERNAL_FORMAT                                    0x1003
#define GL_TEXTURE_LOD_BIAS                                           0x8501
#define GL_TEXTURE_MAG_FILTER                                         0x2800
#define GL_TEXTURE_MAX_ANISOTROPY                                     0x84FE
#define GL_TEXTURE_MAX_LEVEL                                          0x813D
#define GL_TEXTURE_MAX_LOD                                            0x813B
#define GL_TEXTURE_MIN_FILTER                                         0x2801
#define GL_TEXTURE_MIN_LOD                                            0x813A
#define GL_TEXTURE_RECTANGLE                                          0x84F5
#define GL_TEXTURE_RED_SIZE                                           0x805C
#define GL_TEXTURE_RED_TYPE                                           0x8C10
#define GL_TEXTURE_SAMPLES                                            0x9106
#define GL_TEXTURE_SHADOW                                             0x82A1
#define GL_TEXTURE_SHARED_SIZE                                        0x8C3F
#define GL_TEXTURE_STENCIL_SIZE                                       0x88F1
#define GL_TEXTURE_SWIZZLE_A                                          0x8E45
#define GL_TEXTURE_SWIZZLE_B                                          0x8E44
#define GL_TEXTURE_SWIZZLE_G                                          0x8E43
#define GL_TEXTURE_SWIZZLE_R                                          0x8E42
#define GL_TEXTURE_SWIZZLE_RGBA                                       0x8E46
#define GL_TEXTURE_TARGET                                             0x1006
#define GL_TEXTURE_UPDATE_BARRIER_BIT                                 0x00000100
#define GL_TEXTURE_VIEW                                               0x82B5
#define GL_TEXTURE_VIEW_MIN_LAYER                                     0x82DD
#define GL_TEXTURE_VIEW_MIN_LEVEL                                     0x82DB
#define GL_TEXTURE_VIEW_NUM_LAYERS                                    0x82DE
#define GL_TEXTURE_VIEW_NUM_LEVELS                                    0x82DC
#define GL_TEXTURE_WIDTH                                              0x1000
#define GL_TEXTURE_WRAP_R                                             0x8072
#define GL_TEXTURE_WRAP_S                                             0x2802
#define GL_TEXTURE_WRAP_T                                             0x2803
#define GL_TIMEOUT_EXPIRED                                            0x911B
#define GL_TIMEOUT_IGNORED                                            0xFFFFFFFFFFFFFFFF
#define GL_TIMESTAMP                                                  0x8E28
#define GL_TIME_ELAPSED                                               0x88BF
#define GL_TOP_LEVEL_ARRAY_SIZE                                       0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE                                     0x930D
#define GL_TRANSFORM_FEEDBACK                                         0x8E22
#define GL_TRANSFORM_FEEDBACK_ACTIVE                                  0x8E24
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT                             0x00000800
#define GL_TRANSFORM_FEEDBACK_BINDING                                 0x8E25
#define GL_TRANSFORM_FEEDBACK_BUFFER                                  0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE                           0x8E24
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING                          0x8C8F
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX                            0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE                             0x8C7F
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED                           0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE                             0x8C85
#define GL_TRANSFORM_FEEDBACK_BUFFER_START                            0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE                           0x934C
#define GL_TRANSFORM_FEEDBACK_OVERFLOW                                0x82EC
#define GL_TRANSFORM_FEEDBACK_PAUSED                                  0x8E23
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN                      0x8C88
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW                         0x82ED
#define GL_TRANSFORM_FEEDBACK_VARYING                                 0x92F4
#define GL_TRANSFORM_FEEDBACK_VARYINGS                                0x8C83
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH                      0x8C76
#define GL_TRIANGLES                                                  0x0004
#define GL_TRIANGLES_ADJACENCY                                        0x000C
#define GL_TRIANGLE_FAN                                               0x0006
#define GL_TRIANGLE_STRIP                                             0x0005
#define GL_TRIANGLE_STRIP_ADJACENCY                                   0x000D
#define GL_TRUE                                                       1
#define GL_TYPE                                                       0x92FA
#define GL_UNDEFINED_VERTEX                                           0x8260
#define GL_UNIFORM                                                    0x92E1
#define GL_UNIFORM_ARRAY_STRIDE                                       0x8A3C
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX                        0x92DA
#define GL_UNIFORM_BARRIER_BIT                                        0x00000004
#define GL_UNIFORM_BLOCK                                              0x92E2
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS                              0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES                       0x8A43
#define GL_UNIFORM_BLOCK_BINDING                                      0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE                                    0x8A40
#define GL_UNIFORM_BLOCK_INDEX                                        0x8A3A
#define GL_UNIFORM_BLOCK_NAME_LENGTH                                  0x8A41
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER                 0x90EC
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER                0x8A46
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER                0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER            0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER         0x84F1
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER                  0x8A44
#define GL_UNIFORM_BUFFER                                             0x8A11
#define GL_UNIFORM_BUFFER_BINDING                                     0x8A28
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT                            0x8A34
#define GL_UNIFORM_BUFFER_SIZE                                        0x8A2A
#define GL_UNIFORM_BUFFER_START                                       0x8A29
#define GL_UNIFORM_IS_ROW_MAJOR                                       0x8A3E
#define GL_UNIFORM_MATRIX_STRIDE                                      0x8A3D
#define GL_UNIFORM_NAME_LENGTH                                        0x8A39
#define GL_UNIFORM_OFFSET                                             0x8A3B
#define GL_UNIFORM_SIZE                                               0x8A38
#define GL_UNIFORM_TYPE                                               0x8A37
#define GL_UNKNOWN_CONTEXT_RESET                                      0x8255
#define GL_UNPACK_ALIGNMENT                                           0x0CF5
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH                              0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT                             0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE                               0x912A
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH                              0x9127
#define GL_UNPACK_IMAGE_HEIGHT                                        0x806E
#define GL_UNPACK_LSB_FIRST                                           0x0CF1
#define GL_UNPACK_ROW_LENGTH                                          0x0CF2
#define GL_UNPACK_SKIP_IMAGES                                         0x806D
#define GL_UNPACK_SKIP_PIXELS                                         0x0CF4
#define GL_UNPACK_SKIP_ROWS                                           0x0CF3
#define GL_UNPACK_SWAP_BYTES                                          0x0CF0
#define GL_UNSIGNALED                                                 0x9118
#define GL_UNSIGNED_BYTE                                              0x1401
#define GL_UNSIGNED_BYTE_2_3_3_REV                                    0x8362
#define GL_UNSIGNED_BYTE_3_3_2                                        0x8032
#define GL_UNSIGNED_INT                                               0x1405
#define GL_UNSIGNED_INT_10F_11F_11F_REV                               0x8C3B
#define GL_UNSIGNED_INT_10_10_10_2                                    0x8036
#define GL_UNSIGNED_INT_24_8                                          0x84FA
#define GL_UNSIGNED_INT_2_10_10_10_REV                                0x8368
#define GL_UNSIGNED_INT_5_9_9_9_REV                                   0x8C3E
#define GL_UNSIGNED_INT_8_8_8_8                                       0x8035
#define GL_UNSIGNED_INT_8_8_8_8_REV                                   0x8367
#define GL_UNSIGNED_INT_ATOMIC_COUNTER                                0x92DB
#define GL_UNSIGNED_INT_IMAGE_1D                                      0x9062
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY                                0x9068
#define GL_UNSIGNED_INT_IMAGE_2D                                      0x9063
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY                                0x9069
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE                          0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY                    0x906C
#define GL_UNSIGNED_INT_IMAGE_2D_RECT                                 0x9065
#define GL_UNSIGNED_INT_IMAGE_3D                                      0x9064
#define GL_UNSIGNED_INT_IMAGE_BUFFER                                  0x9067
#define GL_UNSIGNED_INT_IMAGE_CUBE                                    0x9066
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY                          0x906A
#define GL_UNSIGNED_INT_SAMPLER_1D                                    0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY                              0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D                                    0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY                              0x8DD7
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE                        0x910A
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY                  0x910D
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT                               0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_3D                                    0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_BUFFER                                0x8DD8
#define GL_UNSIGNED_INT_SAMPLER_CUBE                                  0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY                        0x900F
#define GL_UNSIGNED_INT_VEC2                                          0x8DC6
#define GL_UNSIGNED_INT_VEC3                                          0x8DC7
#define GL_UNSIGNED_INT_VEC4                                          0x8DC8
#define GL_UNSIGNED_NORMALIZED                                        0x8C17
#define GL_UNSIGNED_SHORT                                             0x1403
#define GL_UNSIGNED_SHORT_1_5_5_5_REV                                 0x8366
#define GL_UNSIGNED_SHORT_4_4_4_4                                     0x8033
#define GL_UNSIGNED_SHORT_4_4_4_4_REV                                 0x8365
#define GL_UNSIGNED_SHORT_5_5_5_1                                     0x8034
#define GL_UNSIGNED_SHORT_5_6_5                                       0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV                                   0x8364
#define GL_UPPER_LEFT                                                 0x8CA2
#define GL_VALIDATE_STATUS                                            0x8B83
#define GL_VENDOR                                                     0x1F00
#define GL_VERSION                                                    0x1F02
#define GL_VERTEX_ARRAY                                               0x8074
#define GL_VERTEX_ARRAY_BINDING                                       0x85B5
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT                            0x00000001
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING                         0x889F
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR                                0x88FE
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED                                0x8622
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER                                0x88FD
#define GL_VERTEX_ATTRIB_ARRAY_LONG                                   0x874E
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED                             0x886A
#define GL_VERTEX_ATTRIB_ARRAY_POINTER                                0x8645
#define GL_VERTEX_ATTRIB_ARRAY_SIZE                                   0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE                                 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE                                   0x8625
#define GL_VERTEX_ATTRIB_BINDING                                      0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET                              0x82D5
#define GL_VERTEX_BINDING_BUFFER                                      0x8F4F
#define GL_VERTEX_BINDING_DIVISOR                                     0x82D6
#define GL_VERTEX_BINDING_OFFSET                                      0x82D7
#define GL_VERTEX_BINDING_STRIDE                                      0x82D8
#define GL_VERTEX_PROGRAM_POINT_SIZE                                  0x8642
#define GL_VERTEX_SHADER                                              0x8B31
#define GL_VERTEX_SHADER_BIT                                          0x00000001
#define GL_VERTEX_SHADER_INVOCATIONS                                  0x82F0
#define GL_VERTEX_SUBROUTINE                                          0x92E8
#define GL_VERTEX_SUBROUTINE_UNIFORM                                  0x92EE
#define GL_VERTEX_TEXTURE                                             0x829B
#define GL_VERTICES_SUBMITTED                                         0x82EE
#define GL_VIEWPORT                                                   0x0BA2
#define GL_VIEWPORT_BOUNDS_RANGE                                      0x825D
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX                            0x825F
#define GL_VIEWPORT_SUBPIXEL_BITS                                     0x825C
#define GL_VIEW_CLASS_128_BITS                                        0x82C4
#define GL_VIEW_CLASS_16_BITS                                         0x82CA
#define GL_VIEW_CLASS_24_BITS                                         0x82C9
#define GL_VIEW_CLASS_32_BITS                                         0x82C8
#define GL_VIEW_CLASS_48_BITS                                         0x82C7
#define GL_VIEW_CLASS_64_BITS                                         0x82C6
#define GL_VIEW_CLASS_8_BITS                                          0x82CB
#define GL_VIEW_CLASS_96_BITS                                         0x82C5
#define GL_VIEW_CLASS_BPTC_FLOAT                                      0x82D3
#define GL_VIEW_CLASS_BPTC_UNORM                                      0x82D2
#define GL_VIEW_CLASS_RGTC1_RED                                       0x82D0
#define GL_VIEW_CLASS_RGTC2_RG                                        0x82D1
#define GL_VIEW_CLASS_S3TC_DXT1_RGB                                   0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA                                  0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA                                  0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA                                  0x82CF
#define GL_VIEW_COMPATIBILITY_CLASS                                   0x82B6
#define GL_WAIT_FAILED                                                0x911D
#define GL_WRITE_ONLY                                                 0x88B9
#define GL_XOR                                                        0x1506
#define GL_ZERO                                                       0
#define GL_ZERO_TO_ONE                                                0x935F
#define GL_VERSION_1_0                                                1
#define GL_VERSION_1_1                                                1
#define GL_VERSION_1_2                                                1
#define GL_VERSION_1_3                                                1
#define GL_VERSION_1_4                                                1
#define GL_VERSION_1_5                                                1
#define GL_VERSION_2_0                                                1
#define GL_VERSION_2_1                                                1
#define GL_VERSION_3_0                                                1
#define GL_VERSION_3_1                                                1
#define GL_VERSION_3_2                                                1
#define GL_VERSION_3_3                                                1
#define GL_VERSION_4_0                                                1
#define GL_VERSION_4_1                                                1
#define GL_VERSION_4_2                                                1
#define GL_VERSION_4_3                                                1
#define GL_VERSION_4_4                                                1
#define GL_VERSION_4_5                                                1
#define GL_VERSION_4_6                                                1






#include <memory>
#define GLRAII_LAMBDA(func) decltype([](gl::GLuint id){ func(id); })
#define GLRAII_SINGLE(func) decltype([](gl::GLuint id){ func(1, &id); })
namespace gl::raii {

    struct glid;

    template <class Del>
    using glid_deleter = decltype([](glid* p) { Del{}(reinterpret_cast<gl::GLuint>(p)); });

    template <class Del>
    struct unqiue_glid : std::unique_ptr<glid, glid_deleter<Del>> {
        constexpr unqiue_glid() noexcept = default;
        constexpr unqiue_glid(unqiue_glid<Del>&&) noexcept = default;
        constexpr unqiue_glid(unqiue_glid<Del> const&) noexcept = delete;
        constexpr unqiue_glid& operator=(unqiue_glid<Del>&&) noexcept = default;
        constexpr unqiue_glid& operator=(unqiue_glid<Del> const&) noexcept = delete;

        constexpr unqiue_glid(gl::GLuint id) noexcept : std::unique_ptr<glid, glid_deleter<Del>>(reinterpret_cast<glid*>(id)) {}

        constexpr auto id() const noexcept -> gl::GLuint { return reinterpret_cast<gl::GLuint>(this->get()); }
        constexpr operator gl::GLuint() const& noexcept { return id(); }
        constexpr operator gl::GLuint() const&& noexcept = delete;
        constexpr operator gl::GLuint() & noexcept { return id(); }
        constexpr operator gl::GLuint() && noexcept = delete;
    };

    /* 
    * Calls `constructor(args..., 1, &id)`
    * @returns Value from the out parameter placed into &id
    */
    template<class...Args>
    auto make1from(auto&& constructor, Args...args) -> gl::GLuint {
        gl::GLuint id{};
        constructor(args..., 1, &id);
        return id;
    }

    using buffer      /**/ = unqiue_glid<GLRAII_SINGLE(gl::glDeleteBuffers)>;
    using vertexarray /**/ = unqiue_glid<GLRAII_SINGLE(gl::glDeleteVertexArrays)>;
    using framebuffer /**/ = unqiue_glid<GLRAII_SINGLE(gl::glDeleteFramebuffers)>;
    using texture     /**/ = unqiue_glid<GLRAII_SINGLE(gl::glDeleteTextures)>;
    using program     /**/ = unqiue_glid<GLRAII_LAMBDA(gl::glDeleteProgram)>;
    using shader      /**/ = unqiue_glid<GLRAII_LAMBDA(gl::glDeleteShader)>;
}

#endif // !GL_H
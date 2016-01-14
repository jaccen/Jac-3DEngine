#ifndef _VISUAL_ENGINEHEADER_H
#define _VISUAL_ENGINEHEADER_H
#ifdef WIN32
#include <Windows.h>
#define sleep(t) Sleep((t)*1000)
#else
#include <unistd.h>
#endif



//#define USE_OPENGL 1
#ifdef EGLS_MAC
#include "GL/gl.h"
#include "GL/glext.h"
typedef int GLfixed;
typedef int GLsizeiptr;
#define GL_ETC1_RGB8_OES                                        0x8D64
#define glBindFramebufferOES         glBindFramebuffer
#define GL_FRAMEBUFFER_OES           GL_FRAMEBUFFER
#define GL_FIXED                      GL_INT
#define GL_SRC0_RGB                   GL_SOURCE0_RGB
#define GL_SRC1_RGB                   GL_SOURCE1_RGB
#define GL_SRC2_RGB                   GL_SOURCE2_RGB
#define GL_SRC0_ALPHA                 GL_SOURCE0_ALPHA
#define GL_SRC1_ALPHA                 GL_SOURCE1_ALPHA
#define GL_SRC2_ALPHA                 GL_SOURCE2_ALPHA
#define GL_ARRAY_BUFFER                   0x8892
#define GL_STREAM_DRAW                    0x88E0
#define GL_STATIC_DRAW                    0x88E4
#define GL_DYNAMIC_DRAW                   0x88E8
#define F2F(x) ((GLfloat)(((GLint)(x))/65536.f))

extern void glMultMatrixx(const GLfixed *m);
extern void glTranslatex(GLfixed x, GLfixed y, GLfixed z);
extern void glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
extern void glScalex(GLfixed x, GLfixed y, GLfixed z);
extern void glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
extern void glOrthox(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar);
extern void glFrustumx(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar);
extern void glFogx(GLenum pname, GLfixed param);
#elif __IPHONE_NA
#ifdef __IPHONE_NA_ES2
#include <OpenGLES/ES2/gl.h>
#elif __IPHONE_NA_ES3
#include <OpenGLES/ES3/gl.h>
#else
#include <OpenGLES/ES1/gl.h>
#endif
#define F2F(x) ((GLfloat)(((GLint)(x))/65536.f))
#elif   USE_OPENGL
#define GL_GLEXT_PROTOTYPES
#define GLEW_STATIC
#include <GL/glew.h>
//typedef long GLsizeiptr;
#define GL_ETC1_RGB8_OES                                        0x8D64
#define glBindFramebufferOES         glBindFramebuffer
#define GL_FRAMEBUFFER_OES           GL_FRAMEBUFFER
#define GL_SRC0_RGB                   GL_SOURCE0_RGB
#define GL_SRC1_RGB                   GL_SOURCE1_RGB
#define GL_SRC2_RGB                   GL_SOURCE2_RGB
#define GL_SRC0_ALPHA                 GL_SOURCE0_ALPHA
#define GL_SRC1_ALPHA                 GL_SOURCE1_ALPHA
#define GL_SRC2_ALPHA                 GL_SOURCE2_ALPHA
#define GL_ARRAY_BUFFER                   0x8892
#define GL_STREAM_DRAW                    0x88E0
#define GL_STATIC_DRAW                    0x88E4
#define GL_DYNAMIC_DRAW                   0x88E8

#else
#include <GLES2/gl2.h>
//#include <GLES3/gl3.h>

//UseEGL
//#include <EGL/egl.h>
//#include <EGL/eglext.h>
//#include <GLES2/gl2ext.h>
#ifndef  GL_ETC1_RGB8_OES
#define GL_ETC1_RGB8_OES                                        0x8D64
#endif
#define F2F(x) ((GLfloat)(((GLint)(x))/65536.f))
#endif


#endif
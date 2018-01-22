/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2013-2016 Chukong Technologies Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __PLATFORM_CCGL_H__
#define __PLATFORM_CCGL_H__
/// @cond DO_NOT_SHOW

#include "platform/CCPlatformConfig.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC

#import <OpenGL/gl.h>
#import <OpenGL/glext.h>

//cjh #define CC_GL_DEPTH24_STENCIL8      -1
//
//
//#define glDeleteVertexArrays            glDeleteVertexArraysAPPLE
//#define glGenVertexArrays               glGenVertexArraysAPPLE
//#define glBindVertexArray               glBindVertexArrayAPPLE
//#define glClearDepthf                   glClearDepth
//#define glDepthRangef                   glDepthRange
//#define glReleaseShaderCompiler(xxx)

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>

#define glClearDepth                glClearDepthf
#define glDepthRange                glDepthRangef
//#define glDeleteVertexArrays        glDeleteVertexArraysOES
//#define glGenVertexArrays           glGenVertexArraysOES
//#define glBindVertexArray           glBindVertexArrayOES
//#define glMapBuffer                 glMapBufferOES
//#define glUnmapBuffer               glUnmapBufferOES
//
//#define GL_DEPTH24_STENCIL8         GL_DEPTH24_STENCIL8_OES
//#define GL_DEPTH_STENCIL            GL_DEPTH_STENCIL_OES
//#define GL_WRITE_ONLY               GL_WRITE_ONLY_OES

#define GL_MAX_TEXTURE_UNITS    GL_MAX_TEXTURE_IMAGE_UNITS
#define GL_MAX_SAMPLES_APPLE    GL_MAX_SAMPLES

#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID


#define glClearDepth                glClearDepthf
#define glDeleteVertexArrays        glDeleteVertexArraysOES
#define glGenVertexArrays           glGenVertexArraysOES
#define glBindVertexArray           glBindVertexArrayOES
#define glMapBuffer                 glMapBufferOES
#define glUnmapBuffer               glUnmapBufferOES
#define glTexImage3D                glTexImage3DOES
#define glCompressedTexImage3D        glCompressedTexImage3DOES
#define glCompressedTexSubImage3D    glCompressedTexSubImage3DOES
#define glTexSubImage3D             glTexSubImage3DOES
#define glDepthRange                glDepthRangef
#define glSubImage3D                glSubImage3DOES

#define GL_DEPTH24_STENCIL8         GL_DEPTH24_STENCIL8_OES
#define GL_WRITE_ONLY               GL_WRITE_ONLY_OES

#define GL_MAX_TEXTURE_UNITS        GL_MAX_TEXTURE_IMAGE_UNITS

// GL_GLEXT_PROTOTYPES isn't defined in glplatform.h on android ndk r7
// we manually define it here
#include <GLES2/gl2platform.h>
#ifndef GL_GLEXT_PROTOTYPES
#define GL_GLEXT_PROTOTYPES 1
#endif

// normal process
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
// gl2.h doesn't define GLchar on Android
typedef char GLchar;
// android defines GL_BGRA_EXT but not GL_BRGA
#ifndef GL_BGRA
#define GL_BGRA  0x80E1
#endif

//declare here while define in EGLView_android.cpp
extern PFNGLGENVERTEXARRAYSOESPROC glGenVertexArraysOESEXT;
extern PFNGLBINDVERTEXARRAYOESPROC glBindVertexArrayOESEXT;
extern PFNGLDELETEVERTEXARRAYSOESPROC glDeleteVertexArraysOESEXT;

#define glGenVertexArraysOES glGenVertexArraysOESEXT
#define glBindVertexArrayOES glBindVertexArrayOESEXT
#define glDeleteVertexArraysOES glDeleteVertexArraysOESEXT

#elif CC_TARGET_PLATFORM == CC_PLATFORM_WIN32

#elif CC_TARGET_PLATFORM == CC_PLATFORM_WINRT

#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX

#endif

/// @endcond
#endif /* __PLATFORM_CCPLATFORMDEFINE_H__*/


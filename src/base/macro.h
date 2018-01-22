/****************************************************************************
 Copyright (c) 2018 Chukong Technologies
 
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

#pragma once

#include "config.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <android/log.h>
#endif

#define NS_CC_BASE_BEGIN                     namespace cocos2d { namespace base {
#define NS_CC_BASE_END                       }}
#define USING_NS_CC_BASE                     using namespace cocos2d::base

#define NS_CC_CC_BEGIN                      namespace cocos2d { namespace gfx {
#define NS_CC_CC_END                        }}
#define USING_NS_CC_GFX                      using namespace cocos2d::gfx

#define NS_CC_RENDERER_BEGIN                 namespace cocos2d { namespace renderer {
#define NS_CC_RENDERER_END                   }}
#define USING_NS_CC_RENDERER                 using namespace cocos2d::renderer

#ifndef CC_SAFE_DELETE
#define CC_SAFE_DELETE(p)           do { delete (p); (p) = nullptr; } while(0)
#endif

#ifndef CC_SAFE_DELETE_ARRAY
#define CC_SAFE_DELETE_ARRAY(p)     do { if(p) { delete[] (p); (p) = nullptr; } } while(0)
#endif

#ifndef CC_SAFE_FREE
#define CC_SAFE_FREE(p)             do { if(p) { free(p); (p) = nullptr; } } while(0)
#endif

#ifndef CC_SAFE_RELEASE
#define CC_SAFE_RELEASE(p)          do { if(p) { (p)->release(); } } while(0)
#endif

#ifndef CC_SAFE_RELEASE_NULL
#define CC_SAFE_RELEASE_NULL(p)     do { if(p) { (p)->release(); (p) = nullptr; } } while(0)
#endif

#ifndef CC_SAFE_RETAIN
#define CC_SAFE_RETAIN(p)           do { if(p) { (p)->retain(); } } while(0)
#endif

#ifndef CC_BREAK_IF
#define CC_BREAK_IF(cond)           if(cond) break
#endif

#ifndef CC_DISALLOW_COPY_ASSIGN_AND_MOVE
    #define CC_DISALLOW_COPY_ASSIGN_AND_MOVE(type) \
        type(const type&) = delete; \
        type& operator =(const type&) = delete; \
        type(type &&) = delete; \
        type& operator =(const type &&) = delete;
#endif // CC_DISALLOW_COPY_ASSIGN_AND_MOVE


#define CC_LOG_TAG "cocos2d"
#define CC_QUOTEME_(x) #x
#define CC_QUOTEME(x) CC_QUOTEME_(x)

#if defined(COCOS2D_DEBUG) && COCOS2D_DEBUG > 0
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define CCLOGV(fmt, ...) __android_log_print(ANDROID_LOG_VERBOSE, CC_LOG_TAG, " (" CC_QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__)
#else
#define CCLOGV(fmt, ...) printf("V/" CC_LOG_TAG " (" CC_QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__)
#endif // (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#else
#define CCLOGV(fmt, ...) do {} while(false)
#endif // defined(COCOS2D_DEBUG) && COCOS2D_DEBUG > 0

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define CCLOGD(fmt, ...) __android_log_print(ANDROID_LOG_DEBUG, CC_LOG_TAG, " (" CC_QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__)
#define CCLOGI(fmt, ...) __android_log_print(ANDROID_LOG_INFO, CC_LOG_TAG, " (" CC_QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__)
#define CCLOGW(fmt, ...) __android_log_print(ANDROID_LOG_WARN, CC_LOG_TAG, " (" CC_QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__)
#define CCLOGE(fmt, ...) __android_log_print(ANDROID_LOG_ERROR, CC_LOG_TAG, " (" CC_QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__)
#else
#define CCLOGD(fmt, ...) printf("D/" CC_LOG_TAG " (" CC_QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__)
#define CCLOGI(fmt, ...) printf("I/" CC_LOG_TAG " (" CC_QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__)
#define CCLOGW(fmt, ...) printf("W/" CC_LOG_TAG " (" CC_QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__)
#define CCLOGE(fmt, ...) printf("E/" CC_LOG_TAG " (" CC_QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__)
#endif // (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#define CC_DEFINE_CREATE_METHOD_0(clsName, initMethod) \
static clsName* create() \
{ \
    clsName* ret = new (std::nothrow) clsName(); \
    if (ret && ret->initMethod()) \
    { \
        ret->autorelease(); \
        return ret; \
    } \
    delete ret; \
    return nullptr; \
}

#define CC_DEFINE_CREATE_METHOD_1(clsName, initMethod, arg0Type) \
static clsName* create(arg0Type arg0) \
{ \
    clsName* ret = new (std::nothrow) clsName(); \
    if (ret && ret->initMethod(arg0)) \
    { \
        ret->autorelease(); \
        return ret; \
    } \
    delete ret; \
    return nullptr; \
}

#define CC_DEFINE_CREATE_METHOD_2(clsName, initMethod, arg0Type, arg1Type) \
static clsName* create(arg0Type arg0, arg1Type arg1) \
{ \
    clsName* ret = new (std::nothrow) clsName(); \
    if (ret && ret->initMethod(arg0, arg1)) \
    { \
        ret->autorelease(); \
        return ret; \
    } \
    delete ret; \
    return nullptr; \
}

#define CC_DEFINE_CREATE_METHOD_3(clsName, initMethod, arg0Type, arg1Type, arg2Type) \
static clsName* create(arg0Type arg0, arg1Type arg1, arg2Type arg2) \
{ \
    clsName* ret = new (std::nothrow) clsName(); \
    if (ret && ret->initMethod(arg0, arg1, arg2)) \
    { \
        ret->autorelease(); \
        return ret; \
    } \
    delete ret; \
    return nullptr; \
}

#define CC_DEFINE_CREATE_METHOD_4(clsName, initMethod, arg0Type, arg1Type, arg2Type, arg3Type) \
static clsName* create(arg0Type arg0, arg1Type arg1, arg2Type arg2, arg3Type arg3) \
{ \
    clsName* ret = new (std::nothrow) clsName(); \
    if (ret && ret->initMethod(arg0, arg1, arg2, arg3)) \
    { \
        ret->autorelease(); \
        return ret; \
    } \
    delete ret; \
    return nullptr; \
}

#define CC_DEFINE_CREATE_METHOD_5(clsName, initMethod, arg0Type, arg1Type, arg2Type, arg3Type, arg4Type) \
static clsName* create(arg0Type arg0, arg1Type arg1, arg2Type arg2, arg3Type arg3, arg4Type arg4) \
{ \
    clsName* ret = new (std::nothrow) clsName(); \
    if (ret && ret->initMethod(arg0, arg1, arg2, arg3, arg4)) \
    { \
        ret->autorelease(); \
        return ret; \
    } \
    delete ret; \
    return nullptr; \
}

#define CC_DEFINE_CREATE_METHOD_6(clsName, initMethod, arg0Type, arg1Type, arg2Type, arg3Type, arg4Type, arg5Type) \
static clsName* create(arg0Type arg0, arg1Type arg1, arg2Type arg2, arg3Type arg3, arg4Type arg4, arg5Type arg5) \
{ \
    clsName* ret = new (std::nothrow) clsName(); \
    if (ret && ret->initMethod(arg0, arg1, arg2, arg3, arg4, arg5)) \
    { \
        ret->autorelease(); \
        return ret; \
    } \
    delete ret; \
    return nullptr; \
}

// enum class to GLENUM
#define CC_ENUM_CLASS_TO_GLENUM(value)  static_cast<GLenum>(value)

#define _CC_GL_CHECK(_call) \
    do { \
        _call; \
        GLenum gl_err = glGetError(); \
        if (0 != gl_err) \
            CCLOGE(#_call "; GL error 0x%x: %s", gl_err, glEnumName(gl_err)); \
    } while(false)


#if COCOS2D_DEBUG > 0
#   define CC_GL_CHECK(_call)   _CC_GL_CHECK(_call)
#else
#   define CC_GL_CHECK(_call)   _call
#endif // BCC_CONFIG_DEBUG



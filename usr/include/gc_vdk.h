/****************************************************************************
*
*    Copyright (c) 2005 - 2012 by Vivante Corp.  All rights reserved.
*
*    The material in this file is confidential and contains trade secrets
*    of Vivante Corporation. This is proprietary information owned by
*    Vivante Corporation. No part of this work may be disclosed,
*    reproduced, copied, transmitted, or used in any way for any purpose,
*    without the express written permission of Vivante Corporation.
*
*****************************************************************************/




#ifndef __gc_vdk_h_
#define __gc_vdk_h_


/* Include VDK types. */
#include "gc_vdk_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
** Define VDKAPI and VDKLANG macros. *******************************************
**
** VDKAPI   Import or export function scope.
** VDKLANG  Language defintion of function.
*/
#ifdef _WIN32
#ifdef __VDK_EXPORT
#       define VDKAPI __declspec(dllexport)
#   else
#       define VDKAPI __declspec(dllimport)
#   endif
#   define VDKLANG __cdecl
#else
#   define VDKAPI
#   define VDKLANG
#endif

/*******************************************************************************
** Initialization. *************************************************************
*/

VDKAPI vdkPrivate VDKLANG
vdkInitialize(
    void
    );

VDKAPI void VDKLANG
vdkExit(
    vdkPrivate Private
    );

/*******************************************************************************
** Display. ********************************************************************
*/

VDKAPI vdkDisplay VDKLANG
vdkGetDisplayByIndex(
    vdkPrivate Private,
    gctINT DisplayIndex
    );

VDKAPI vdkDisplay VDKLANG
vdkGetDisplay(
    vdkPrivate Private
    );

VDKAPI int VDKLANG
vdkGetDisplayInfo(
    vdkDisplay Display,
    int * Width,
    int * Height,
    unsigned long * Physical,
    int * Stride,
    int * BitsPerPixel
    );

typedef halDISPLAY_INFO vdkDISPLAY_INFO;

VDKAPI int VDKLANG
vdkGetDisplayInfoEx(
    vdkDisplay Display,
    unsigned int DisplayInfoSize,
    vdkDISPLAY_INFO * DisplayInfo
    );

VDKAPI int VDKLANG
vdkGetDisplayVirtual(
    vdkDisplay Display,
    int * Width,
    int * Height
    );

VDKAPI int VDKLANG
vdkGetDisplayBackbuffer(
    vdkDisplay Display,
    unsigned int * Offset,
    int * X,
    int * Y
    );

VDKAPI int VDKLANG
vdkSetDisplayVirtual(
    vdkDisplay Display,
    unsigned int Offset,
    int X,
    int Y
    );

VDKAPI void VDKLANG
vdkDestroyDisplay(
    vdkDisplay Display
    );

/*******************************************************************************
** Windows. ********************************************************************
*/

VDKAPI vdkWindow VDKLANG
vdkCreateWindow(
    vdkDisplay Display,
    int X,
    int Y,
    int Width,
    int Height
    );

VDKAPI int VDKLANG
vdkGetWindowInfo(
    vdkWindow Window,
    int * X,
    int * Y,
    int * Width,
    int * Height,
    int * BitsPerPixel,
    unsigned int * Offset
    );

VDKAPI void VDKLANG
vdkDestroyWindow(
    vdkWindow Window
    );

VDKAPI void VDKLANG
vdkSetWindowTitle(
    vdkWindow Window,
    const char * Title
    );

VDKAPI int VDKLANG
vdkShowWindow(
    vdkWindow Window
    );

VDKAPI int VDKLANG
vdkHideWindow(
    vdkWindow Window
    );

VDKAPI int VDKLANG
vdkDrawImage(
    vdkWindow Window,
    int Left,
    int Top,
    int Right,
    int Bottom,
    int Width,
    int Height,
    int BitsPerPixel,
    void * Bits
    );

VDKAPI int VDKLANG
vdkGetImage(
    vdkWindow Window,
    int Left,
    int Top,
    int Right,
    int Bottom,
    int * BitsPerPixel,
    void ** Bits
    );

VDKAPI void VDKLANG
vdkCapturePointer(
    vdkWindow Window
    );

/*******************************************************************************
** Pixmaps. ********************************************************************
*/

VDKAPI vdkPixmap VDKLANG
vdkCreatePixmap(
    vdkDisplay Display,
    int Width,
    int Height,
    int BitsPerPixel
    );

VDKAPI int VDKLANG
vdkGetPixmapInfo(
    vdkPixmap Pixmap,
    int * Width,
    int * Height,
    int * BitsPerPixel,
    int * Stride,
    void ** Bits
    );

VDKAPI int VDKLANG
vdkDrawPixmap(
    vdkPixmap Pixmap,
    int Left,
    int Top,
    int Right,
    int Bottom,
    int Width,
    int Height,
    int BitsPerPixel,
    void * Bits
    );

VDKAPI void VDKLANG
vdkDestroyPixmap(
    vdkPixmap Pixmap
    );

/*******************************************************************************
** ClientBuffers. **************************************************************
*/

VDKAPI vdkClientBuffer VDKLANG
vdkCreateClientBuffer(
    int Width,
    int Height,
    int Format,
    int Type
    );

VDKAPI int VDKLANG
vdkGetClientBufferInfo(
    vdkClientBuffer ClientBuffer,
    int * Width,
    int * Height,
    int * Stride,
    void ** Bits
    );

VDKAPI int VDKLANG
vdkDestroyClientBuffer(
    vdkClientBuffer ClientBuffer
    );

/*******************************************************************************
** Events. *********************************************************************
*/

VDKAPI int VDKLANG
vdkGetEvent(
    vdkWindow Window,
    vdkEvent * Event
    );

/*******************************************************************************
** Time. ***********************************************************************
*/

VDKAPI unsigned int VDKLANG
vdkGetTicks(
    void
    );

/*******************************************************************************
** EGL support. ****************************************************************
*/

/* EGL prototypes. */
typedef EGLDisplay (EGLAPIENTRY * EGL_GET_DISPLAY)(
    EGLNativeDisplayType display_id
    );

typedef EGLBoolean (EGLAPIENTRY * EGL_INITIALIZE)(
    EGLDisplay dpy,
    EGLint *major,
    EGLint *minor
    );

typedef EGLBoolean (EGLAPIENTRY * EGL_TERMINATE)(
    EGLDisplay dpy
    );

typedef EGLBoolean (EGLAPIENTRY * EGL_RELEASE_THREAD)(
    void
    );

typedef EGLBoolean (EGLAPIENTRY * EGL_CHOOSE_CONFIG)(
    EGLDisplay dpy,
    const EGLint *attrib_list,
    EGLConfig *configs,
    EGLint config_size,
    EGLint *num_config
    );

typedef EGLSurface (EGLAPIENTRY * EGL_CREATE_WINDOW_SURFACE)(
    EGLDisplay dpy,
    EGLConfig config,
    EGLNativeWindowType win,
    const EGLint *attrib_list
    );

typedef EGLBoolean (EGLAPIENTRY * EGL_DESTROY_SURFACE)(
    EGLDisplay dpy,
    EGLSurface surface
    );

typedef EGLContext (EGLAPIENTRY * EGL_CREATE_CONTEXT)(
    EGLDisplay dpy,
    EGLConfig config,
    EGLContext share_context,
    const EGLint *attrib_list
    );

typedef EGLBoolean (EGLAPIENTRY * EGL_DESTROY_CONTEXT)(
    EGLDisplay dpy,
    EGLContext ctx
    );

typedef EGLBoolean (EGLAPIENTRY * EGL_MAKE_CURRENT)(
    EGLDisplay dpy,
    EGLSurface draw,
    EGLSurface read,
    EGLContext ctx
    );

typedef EGLBoolean (EGLAPIENTRY * EGL_SWAP_BUFFERS)(
    EGLDisplay dpy,
    EGLSurface surface
    );

typedef void (* EGL_PROC)(void);

typedef EGL_PROC (EGLAPIENTRY * EGL_GET_PROC_ADDRESS)(
    const char *procname
    );

typedef EGLBoolean (EGLAPIENTRY * EGL_BIND_API)(
    EGLenum api
    );

/* VDK_EGL structure defining the stuff required for EGL support. */
typedef struct _vdkEGL
{
    /* Pointer to VDK private data. */
    vdkPrivate                  vdk;

    /* Pointer to vdkDisplay structure. */
    vdkDisplay                  display;

    /* Pointer to vdkWindow structure. */
    vdkWindow                   window;

    /* EGL version. */
    EGLint                      eglMajor;
    EGLint                      eglMinor;

    /* EGL pointers. */
    EGLDisplay                  eglDisplay;
    EGLConfig                   eglConfig;
    EGLSurface                  eglSurface;
    EGLContext                  eglContext;

    /* EGL function pointers. */
    EGL_GET_DISPLAY             eglGetDisplay;
    EGL_INITIALIZE              eglInitialize;
    EGL_TERMINATE               eglTerminate;
    EGL_RELEASE_THREAD          eglReleaseThread;
    EGL_CHOOSE_CONFIG           eglChooseConfig;
    EGL_CREATE_WINDOW_SURFACE   eglCreateWindowSurface;
    EGL_DESTROY_SURFACE         eglDestroySurface;
    EGL_CREATE_CONTEXT          eglCreateContext;
    EGL_DESTROY_CONTEXT         eglDestroyContext;
    EGL_MAKE_CURRENT            eglMakeCurrent;
    EGL_SWAP_BUFFERS            eglSwapBuffers;
    EGL_GET_PROC_ADDRESS        eglGetProcAddress;
    EGL_BIND_API                eglBindAPI;
}
vdkEGL;

typedef void (EGLAPIENTRY * EGL_ADDRESS)(
    void);

EGL_ADDRESS
vdkGetAddress(
    vdkPrivate Private,
    const char * Function
    );

#define VDK_CONFIG_RGB565_D16       ((const EGLint *) 1)
#define VDK_CONFIG_RGB565_D24       ((const EGLint *) 3)
#define VDK_CONFIG_RGB888_D16       ((const EGLint *) 5)
#define VDK_CONFIG_RGB888_D24       ((const EGLint *) 7)
#define VDK_CONFIG_RGB565_D16_AA    ((const EGLint *) 9)
#define VDK_CONFIG_RGB565_D24_AA    ((const EGLint *) 11)
#define VDK_CONFIG_RGB888_D16_AA    ((const EGLint *) 13)
#define VDK_CONFIG_RGB888_D24_AA    ((const EGLint *) 15)
#define VDK_CONFIG_RGB565           ((const EGLint *) 17)
#define VDK_CONFIG_RGB888           ((const EGLint *) 19)
#define VDK_CONFIG_RGB565_AA        ((const EGLint *) 21)
#define VDK_CONFIG_RGB888_AA        ((const EGLint *) 23)

/* OpenVG Configurations. */
#define VDK_CONFIG_RGB565_VG        ((const EGLint *) 500)
#define VDK_CONFIG_RGB888_VG        ((const EGLint *) 501)

#define VDK_CONTEXT_ES11            ((const EGLint *) 0)
#define VDK_CONTEXT_ES20            ((const EGLint *) 2)

VDKAPI int VDKLANG
vdkSetupEGL(
    int X,
    int Y,
    int Width,
    int Height,
    const EGLint * ConfigurationAttributes,
    const EGLint * SurfaceAttributes,
    const EGLint * ContextAttributes,
    vdkEGL * Egl
    );

VDKAPI int VDKLANG
vdkSwapEGL(
    vdkEGL * Egl
    );

VDKAPI void VDKLANG
vdkFinishEGL(
    vdkEGL * Egl
    );

/*******************************************************************************
** GL Textures. ****************************************************************
*/

typedef enum _vdkTextureType
{
    VDK_TGA,
    VDK_PNG,
    VDK_PKM,
}
vdkTextureType;

typedef enum _vdkTextureFace
{
    VDK_2D,
    VDK_POSITIVE_X,
    VDK_NEGATIVE_X,
    VDK_POSITIVE_Y,
    VDK_NEGATIVE_Y,
    VDK_POSITIVE_Z,
    VDK_NEGATIVE_Z,
}
vdkTextureFace;

VDKAPI unsigned int VDKLANG
vdkLoadTexture(
    vdkEGL * Egl,
    const char * FileName,
    vdkTextureType Type,
    vdkTextureFace Face
    );

/*******************************************************************************
** GL Shaders. *****************************************************************
*/

VDKAPI unsigned int VDKLANG
vdkMakeProgram(
    vdkEGL * Egl,
    const char * VertexShader,
    const char * FragmentShader,
    char ** Log
    );

VDKAPI int VDKLANG
vdkDeleteProgram(
    vdkEGL * Egl,
    unsigned int Program
    );

#ifdef __cplusplus
}
#endif

#endif /* __gc_vdk_h_ */

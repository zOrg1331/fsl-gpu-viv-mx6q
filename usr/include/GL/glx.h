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


/*
 * The contents of this file are subject to the GLX Public License Version 1.0
 * (the "License"). You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at Silicon Graphics, Inc.,
 * attn: Legal Services, 2011 N. Shoreline Blvd., Mountain View, CA 94043
 * or at http://www.sgi.com/software/opensource/glx/license.html.
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis. ALL WARRANTIES ARE DISCLAIMED, INCLUDING, WITHOUT LIMITATION, ANY
 * IMPLIED WARRANTIES OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
 * PURPOSE OR OF NON- INFRINGEMENT. See the License for the specific
 * language governing rights and limitations under the License.
 */

#ifndef __gc_glx_h__
#define __gc_glx_h__

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <GL/gl.h>
#include <GL/glxtokens.h>

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
** GLX resources.
*/

/* Drawables (rendering surfaces). */
typedef XID GLXDrawable;	/* Any of the defined drawable types. */
typedef XID GLXWindow;      /* On screen surface. */
typedef XID GLXPixmap;		/* Off screen surface. */
typedef XID GLXPbuffer;		/* Off screen surface. */

/* Specific drawable configuration for its creation. */
typedef XID GLXFBConfigID;


/*******************************************************************************
** GLXContext is a pointer to opaque data.
*/

typedef struct __GLXcontextRec * GLXContext;


/*******************************************************************************
** GLXFBConfig is a pointer to opaque data.
*/

typedef struct __GLXFBConfigRec * GLXFBConfig;


/*******************************************************************************
** GLX 1.0 and later.
*/

extern XVisualInfo *
glXChooseVisual(
	Display * Dpy,
	int ScreenNumber,
	int * AttributeList
	);

extern GLXContext
glXCreateContext(
	Display * Dpy,
	XVisualInfo *vis,
	GLXContext shareList,
	Bool direct
	);

extern void
glXDestroyContext(
	Display * Dpy,
	GLXContext ctx
	);

extern Bool glXMakeCurrent(
	Display * Dpy,
	GLXDrawable drawable,
	GLXContext ctx
	);

extern void glXCopyContext(
	Display * Dpy,
	GLXContext src,
	GLXContext dst,
	unsigned long mask
	);

extern void
glXSwapBuffers(
	Display * Dpy,
	GLXDrawable drawable
	);

extern GLXPixmap
glXCreateGLXPixmap(
	Display * Dpy,
	XVisualInfo *visual,
	Pixmap pixmap
	);

extern void
glXDestroyGLXPixmap(
	Display * Dpy,
	GLXPixmap pixmap
	);

extern Bool
glXQueryExtension(
	Display * Dpy,
	int *errorb,
	int *event
	);

extern Bool
glXQueryVersion(
	Display * Dpy,
	int *maj,
	int *min
	);

extern Bool
glXIsDirect(
	Display * Dpy,
	GLXContext ctx
	);

extern int
glXGetConfig(
	Display * Dpy,
	XVisualInfo *visual,
	int attrib,
	int *value
	);

extern GLXContext
glXGetCurrentContext(
	void
	);

extern GLXDrawable
glXGetCurrentDrawable(
	void
	);

extern void
glXWaitGL(
	void
	);

extern void
glXWaitX(
	void
	);

extern void
glXUseXFont(
	Font font,
	int first,
	int count,
	int list
	);


/*******************************************************************************
** GLX 1.1 and later.
*/

#if defined(GLX_VERSION_1_1)

extern const char *
glXQueryExtensionsString(
	Display * Dpy,
	int ScreenNumber
	);

extern const char *
glXQueryServerString(
	Display * Dpy,
	int ScreenNumber,
	int name
	);

extern const char *
glXGetClientString(
	Display * Dpy,
	int name
	);

#endif	/* GLX_VERSION_1_1 */


/*******************************************************************************
** GLX 1.2 and later.
*/

#if defined(GLX_VERSION_1_2)

extern Display *
glXGetCurrentDisplay(
	void
	);

#endif	/* GLX_VERSION_1_2 */

/* GLX 1.3 and later. */
#if defined(GLX_VERSION_1_3)

typedef Display * (* PFNGLXGETCURRENTDISPLAYPROC) (
	void
	);

#endif	/* GLX_VERSION_1_3 */


/*******************************************************************************
** GLX 1.3 and later.
*/

#if defined(GLX_VERSION_1_3)

extern GLXFBConfig *
glXChooseFBConfig(
	Display * Dpy,
	int ScreenNumber,
	const int * AttributeList,
	int *nitems
	);

typedef GLXFBConfig * (* PFNGLXCHOOSEFBCONFIGPROC) (
	Display * Dpy,
	int ScreenNumber,
	const int * AttributeList,
	int *nelements
	);

/*-------------------------*/

extern int
glXGetFBConfigAttrib(
	Display * Dpy,
	GLXFBConfig config,
	int attribute,
	int *value
	);

typedef int (* PFNGLXGETFBCONFIGATTRIBPROC) (
	Display * Dpy,
	GLXFBConfig config,
	int attribute,
	int *value
	);

/*-------------------------*/

extern GLXFBConfig *
glXGetFBConfigs(
	Display * Dpy,
	int ScreenNumber,
	int *nelements
	);

typedef GLXFBConfig * (* PFNGLXGETFBCONFIGSPROC) (
	Display * Dpy,
	int ScreenNumber,
	int *nelements
	);

/*-------------------------*/

extern XVisualInfo *
glXGetVisualFromFBConfig(
	Display * Dpy,
	GLXFBConfig config
	);

typedef XVisualInfo * (* PFNGLXGETVISUALFROMFBCONFIGPROC) (
	Display * Dpy,
	GLXFBConfig config
	);

/*-------------------------*/

extern GLXWindow
glXCreateWindow(
	Display * Dpy,
	GLXFBConfig config,
	Window win,
	const int * AttributeList
	);

typedef GLXWindow (* PFNGLXCREATEWINDOWPROC) (
	Display * Dpy,
	GLXFBConfig config,
	Window win,
	const int * AttributeList
	);

/*-------------------------*/

extern void
glXDestroyWindow(
	Display * Dpy,
	GLXWindow window
	);

typedef void (* PFNGLXDESTROYWINDOWPROC) (
	Display * Dpy,
	GLXWindow win
	);

/*-------------------------*/

extern GLXPixmap
glXCreatePixmap(
	Display * Dpy,
	GLXFBConfig config,
	Pixmap pixmap,
	const int * AttributeList
	);

typedef GLXPixmap (* PFNGLXCREATEPIXMAPPROC) (
	Display * Dpy,
	GLXFBConfig config,
	Pixmap pixmap,
	const int * AttributeList
	);

/*-------------------------*/

extern void
glXDestroyPixmap(
	Display * Dpy,
	GLXPixmap pixmap
	);

typedef void (* PFNGLXDESTROYPIXMAPPROC) (
	Display * Dpy,
	GLXPixmap pixmap
	);

/*-------------------------*/

extern GLXPbuffer
glXCreatePbuffer(
	Display * Dpy,
	GLXFBConfig config,
	const int * AttributeList
	);

typedef GLXPbuffer (* PFNGLXCREATEPBUFFERPROC) (
	Display * Dpy,
	GLXFBConfig config,
	const int * AttributeList
	);

/*-------------------------*/

extern void
glXDestroyPbuffer(
	Display * Dpy,
	GLXPbuffer pbuf
	);
typedef void (* PFNGLXDESTROYPBUFFERPROC) (
	Display * Dpy,
	GLXPbuffer pbuf
	);

/*-------------------------*/

extern void
glXQueryDrawable(
	Display * Dpy,
	GLXDrawable draw,
	int attribute,
	unsigned int *value
	);

typedef void (* PFNGLXQUERYDRAWABLEPROC) (
	Display * Dpy,
	GLXDrawable draw,
	int attribute,
	unsigned int *value
	);

/*-------------------------*/

extern GLXContext
glXCreateNewContext(
	Display * Dpy,
	GLXFBConfig config,
	int renderType,
	GLXContext shareList,
	Bool direct
	);

typedef GLXContext (* PFNGLXCREATENEWCONTEXTPROC) (
	Display * Dpy,
	GLXFBConfig config,
	int render_type,
	GLXContext share_list,
	Bool direct
	);

/*-------------------------*/

extern Bool
glXMakeContextCurrent(
	Display * Dpy,
	GLXDrawable draw,
	GLXDrawable read,
	GLXContext ctx
	);

typedef Bool (* PFNGLXMAKECONTEXTCURRENTPROC) (
	Display * Dpy,
	GLXDrawable draw,
	GLXDrawable read,
	GLXContext ctx
	);

/*-------------------------*/

extern GLXDrawable
glXGetCurrentReadDrawable(
	void
	);

typedef GLXDrawable (* PFNGLXGETCURRENTREADDRAWABLEPROC) (
	void
	);

/*-------------------------*/

extern int
glXQueryContext(
	Display * Dpy,
	GLXContext ctx,
	int attribute,
	int *value
	);

typedef int (* PFNGLXQUERYCONTEXTPROC) (
	Display * Dpy,
	GLXContext ctx,
	int attribute,
	int *value
	);

/*-------------------------*/

extern void
glXSelectEvent(
	Display * Dpy,
	GLXDrawable drawable,
	unsigned long mask
	);

typedef void (* PFNGLXSELECTEVENTPROC) (
	Display * Dpy,
	GLXDrawable draw,
	unsigned long event_mask
	);

/*-------------------------*/

extern void
glXGetSelectedEvent(
	Display * Dpy,
	GLXDrawable drawable,
	unsigned long *mask
	);

typedef void (* PFNGLXGETSELECTEDEVENTPROC) (
	Display * Dpy,
	GLXDrawable draw,
	unsigned long *event_mask
	);

#endif	/* GLX_VERSION_1_3 */


/*******************************************************************************
** GLX 1.4 and later.
*/

#if defined(GLX_VERSION_1_4)

extern void *
glXGetProcAddress(
	const GLubyte *procname
	);

typedef __GLXextFuncPtr (* PFNGLXGETPROCADDRESSPROC) (
	const GLubyte *procName
	);

#endif	/* GLX_VERSION_1_4 */


#ifdef __cplusplus
}
#endif

#endif	/* !__gc_glx_h__ */

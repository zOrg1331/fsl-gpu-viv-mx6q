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


#ifndef __eglrename_h_
#define __eglrename_h_

#if defined(_EGL_APPENDIX)

#define _EGL_RENAME_2(api, appendix)	api ## appendix
#define _EGL_RENAME_1(api, appendix)	_EGL_RENAME_2(api, appendix)
#define gcmEGL(api)						_EGL_RENAME_1(api, _EGL_APPENDIX)

#define eglBindAPI						gcmEGL(eglBindAPI)
#define eglBindTexImage					gcmEGL(eglBindTexImage)
#define eglChooseConfig					gcmEGL(eglChooseConfig)
#define eglClientWaitSyncKHR			gcmEGL(eglClientWaitSyncKHR)
#define eglCopyBuffers					gcmEGL(eglCopyBuffers)
#define eglCreateContext				gcmEGL(eglCreateContext)
#define eglCreateImageKHR				gcmEGL(eglCreateImageKHR)
#define eglCreatePbufferFromClientBuffer \
			gcmEGL(eglCreatePbufferFromClientBuffer)
#define eglCreatePbufferSurface			gcmEGL(eglCreatePbufferSurface)
#define eglCreatePixmapSurface			gcmEGL(eglCreatePixmapSurface)
#define eglCreateSyncKHR				gcmEGL(eglCreateSyncKHR)
#define eglCreateWindowSurface			gcmEGL(eglCreateWindowSurface)
#define eglDestroyContext				gcmEGL(eglDestroyContext)
#define eglDestroyImageKHR				gcmEGL(eglDestroyImageKHR)
#define eglDestroyImageKHR				gcmEGL(eglDestroyImageKHR)
#define eglDestroySurface				gcmEGL(eglDestroySurface)
#define eglDestroySyncKHR				gcmEGL(eglDestroySyncKHR)
#define eglGetConfigAttrib				gcmEGL(eglGetConfigAttrib)
#define eglGetConfigs					gcmEGL(eglGetConfigs)
#define eglGetCurrentContext			gcmEGL(eglGetCurrentContext)
#define eglGetCurrentDisplay			gcmEGL(eglGetCurrentDisplay)
#define eglGetCurrentSurface			gcmEGL(eglGetCurrentSurface)
#define eglGetDisplay					gcmEGL(eglGetDisplay)
#define eglGetError						gcmEGL(eglGetError)
#define eglGetProcAddress				gcmEGL(eglGetProcAddress)
#define eglGetSyncAttribKHR				gcmEGL(eglGetSyncAttribKHR)
#define eglInitialize					gcmEGL(eglInitialize)
#define eglLockSurfaceKHR				gcmEGL(eglLockSurfaceKHR)
#define eglMakeCurrent					gcmEGL(eglMakeCurrent)
#define eglQueryAPI						gcmEGL(eglQueryAPI)
#define eglQueryContext					gcmEGL(eglQueryContext)
#define eglQueryString					gcmEGL(eglQueryString)
#define eglQuerySurface					gcmEGL(eglQuerySurface)
#define eglReleaseTexImage				gcmEGL(eglReleaseTexImage)
#define eglReleaseThread				gcmEGL(eglReleaseThread)
#define eglSetSwapRectangleANDROID		gcmEGL(eglSetSwapRectangleANDROID)
#define eglSignalSyncKHR				gcmEGL(eglSignalSyncKHR)
#define eglSurfaceAttrib				gcmEGL(eglSurfaceAttrib)
#define eglSwapBuffers					gcmEGL(eglSwapBuffers)
#define eglSwapBuffersRegionEXT         gcmEGL(eglSwapBuffersRegionEXT)
#define eglSwapInterval					gcmEGL(eglSwapInterval)
#define eglSwapRectangleANDROID			gcmEGL(eglSwapRectangleANDROID)
#define eglTerminate					gcmEGL(eglTerminate)
#define eglUnlockSurfaceKHR				gcmEGL(eglUnlockSurfaceKHR)
#define eglWaitClient					gcmEGL(eglWaitClient)
#define eglWaitGL						gcmEGL(eglWaitGL)
#define eglWaitNative					gcmEGL(eglWaitNative)

#endif /* _EGL_APPENDIX */
#endif /* __eglrename_h_ */

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
 * Vivante specific definitions and declarations for all API library.
 */
#ifndef __khrvivante_h_

#include "gc_hal.h"

/* EGL image type enum. */
typedef enum _khrIMAGE_TYPE
{
	KHR_IMAGE_TEXTURE_2D			= 1,
	KHR_IMAGE_TEXTURE_CUBE,
	KHR_IMAGE_TEXTURE_3D,
	KHR_IMAGE_RENDER_BUFFER,
	KHR_IMAGE_VG_IMAGE,
	KHR_IMAGE_PIXMAP,
	KHR_IMAGE_ANDROID_NATIVE_BUFFER,
	KHR_IMAGE_WAYLAND_BUFFER,
} khrIMAGE_TYPE;

#define KHR_EGL_IMAGE_MAGIC_NUM		gcmCC('I','M','A','G')

/* EGL Image */
typedef struct _khrEGL_IMAGE
{
	gctUINT						magic;
	khrIMAGE_TYPE				type;
	gcoSURF						surface;
	gcoSURF						srcSurface;

	union
	{
		struct _khrEGL_IMAGE_TEXTURE
		{
			gctUINT				width;
			gctUINT				height;

			/* Format defined in GLES. */
			gctUINT				format;

			gctINT				level;
			gctINT				face;
			gctINT				depth;

			/* Address offset in surface, for cubemap. */
			gctUINT32			offset;

			gctINT				texture;
			gctPOINTER			object;
		} texture;

		struct _khrEGL_IMAGE_PIXMAP
		{
			gctUINT				width;
			gctUINT				height;
			gceSURF_FORMAT		format;
			gctINT				stride;

			gctPOINTER			address;
#ifdef EGL_API_XXX
			gctINT				seqNo;
#endif
		} pixmap;

		struct _khrEGL_IMAGE_VGIMAGE
		{
            gcoSURF             texSurface;

			gctUINT				width;
			gctUINT				height;
			gctUINT				offset_x;
			gctUINT				offset_y;

			gctUINT				format;
			gctUINT				allowedQuality;
            gctBOOL             dirty;
            gctBOOL             *dirtyPtr;
            gctINT32            rootWidth;
            gctINT32            rootHeight;
            gctINT32            rootOffsetX;
            gctINT32            rootOffsetY;
		} vgimage;

#if defined(ANDROID)
        struct _khrEGL_IMAGE_ANDROID
        {
            gctPOINTER          native;
            gctUINT             nativeFormat;
            /* In Android, used to carry info about compositor client. */
            gctPOINTER                  privHandle;
        } androidNativeBuffer;
#endif
	} u;
}
khrEGL_IMAGE;

typedef khrEGL_IMAGE * khrEGL_IMAGE_PTR;

#define __khrvivante_h_
#endif

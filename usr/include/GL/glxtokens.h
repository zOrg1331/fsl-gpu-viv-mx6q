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

#ifndef __gc_glx_tokens_h__
#define __gc_glx_tokens_h__

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
** Supported GLX versions.
*/

#define GLX_VERSION_1_1                 1
#define GLX_VERSION_1_2                 1

/*
#define GLX_VERSION_1_3                 1
#define GLX_VERSION_1_4                 1
*/

/*******************************************************************************
** Error return values from glXGetConfig.
** Success is indicated by a value of 0.
*/

#define GLX_BAD_SCREEN                  1       /* Screen # is bad. */
#define GLX_BAD_ATTRIBUTE               2       /* Attribute to get is bad. */
#define GLX_NO_EXTENSION                3       /* No glx extension on server. */
#define GLX_BAD_VISUAL                  4       /* Visual # not known by GLX. */
#define GLX_BAD_CONTEXT                 5
#define GLX_BAD_VALUE                   6
#define GLX_BAD_ENUM                    7


/*******************************************************************************
** Names for attributes to glXGetConfig.
**/

#define GLX_USE_GL                      1       /* Support GLX rendering. */
#define GLX_BUFFER_SIZE                 2       /* Depth of the color buffer. */
#define GLX_LEVEL                       3       /* Level in plane stacking. */
#define GLX_RGBA                        4       /* True if RGBA mode. */
#define GLX_DOUBLEBUFFER                5       /* Double buffering supported. */
#define GLX_STEREO                      6       /* Stereo buffering supported. */
#define GLX_AUX_BUFFERS                 7       /* Number of aux buffers. */
#define GLX_RED_SIZE                    8       /* Number of red component bits. */
#define GLX_GREEN_SIZE                  9       /* Number of green component bits. */
#define GLX_BLUE_SIZE                   10      /* Number of blue component bits. */
#define GLX_ALPHA_SIZE                  11      /* Number of alpha component bits. */
#define GLX_DEPTH_SIZE                  12      /* Number of depth bits. */
#define GLX_STENCIL_SIZE                13      /* Number of stencil bits. */
#define GLX_ACCUM_RED_SIZE              14      /* Number of red accum bits. */
#define GLX_ACCUM_GREEN_SIZE            15      /* Number of green accum bits. */
#define GLX_ACCUM_BLUE_SIZE             16      /* Number of blue accum bits. */
#define GLX_ACCUM_ALPHA_SIZE            17      /* Number of alpha accum bits. */

#define GLX_SAMPLE_BUFFERS_ARB          100000  /* Number of multisample buffers. */
#define GLX_SAMPLES_ARB                 100001  /* Number of multisample samples. */


/*******************************************************************************
** Names for attributes to glXGetClientString.
** GLX 1.1 and later.
*/

#if defined(GLX_VERSION_1_1)
#define GLX_VENDOR                      1
#define GLX_VERSION                     2
#define GLX_EXTENSIONS                  3
#endif


/*******************************************************************************
** FBConfig-specific attributes.
** GLX 1.3 and later.
*/

#if defined(GLX_VERSION_1_3)
#define GLX_CONFIG_CAVEAT               0x20    /* Like visual_info VISUAL_CAVEAT. */
#define GLX_X_VISUAL_TYPE               0x22
#define GLX_TRANSPARENT_TYPE            0x23
#define GLX_TRANSPARENT_INDEX_VALUE     0x24
#define GLX_TRANSPARENT_RED_VALUE       0x25
#define GLX_TRANSPARENT_GREEN_VALUE     0x26
#define GLX_TRANSPARENT_BLUE_VALUE      0x27
#define GLX_TRANSPARENT_ALPHA_VALUE     0x28
#define GLX_DRAWABLE_TYPE               0x8010
#define GLX_RENDER_TYPE                 0x8011
#define GLX_X_RENDERABLE                0x8012
#define GLX_FBCONFIG_ID                 0x8013
#define GLX_MAX_PBUFFER_WIDTH           0x8016
#define GLX_MAX_PBUFFER_HEIGHT          0x8017
#define GLX_MAX_PBUFFER_PIXELS          0x8018
#define GLX_VISUAL_ID                   0x800B
#endif


/*******************************************************************************
** Generic "don't care" value for glX ChooseFBConfig
** attributes (except GLX_LEVEL).
** GLX 1.3 and later.
*/

#if defined(GLX_VERSION_1_3)
#define GLX_DONT_CARE                   0xFFFFFFFF
#endif


/*******************************************************************************
** GLX_RENDER_TYPE bits.
** GLX 1.3 and later.
*/

#if defined(GLX_VERSION_1_3)
#define GLX_RGBA_BIT                    0x00000001
#define GLX_COLOR_INDEX_BIT             0x00000002
#endif


/*******************************************************************************
** GLX_DRAWABLE_TYPE bits.
** GLX 1.3 and later.
*/

#if defined(GLX_VERSION_1_3)
#define GLX_WINDOW_BIT                  0x00000001
#define GLX_PIXMAP_BIT                  0x00000002
#define GLX_PBUFFER_BIT                 0x00000004
#endif


/*******************************************************************************
** GLX_CONFIG_CAVEAT attribute values.
** GLX 1.3 and later.
*/

#if defined(GLX_VERSION_1_3)
#define GLX_NONE                        0x8000
#define GLX_SLOW_CONFIG                 0x8001
#define GLX_NON_CONFORMANT_CONFIG       0x800D
#endif


/*******************************************************************************
** GLX_X_VISUAL_TYPE attribute values.
** GLX 1.3 and later.
*/

#if defined(GLX_VERSION_1_3)
#define GLX_TRUE_COLOR                  0x8002
#define GLX_DIRECT_COLOR                0x8003
#define GLX_PSEUDO_COLOR                0x8004
#define GLX_STATIC_COLOR                0x8005
#define GLX_GRAY_SCALE                  0x8006
#define GLX_STATIC_GRAY                 0x8007
#endif


/*******************************************************************************
** GLX_TRANSPARENT_TYPE attribute values.
** GLX 1.3 and later.
*/

#if defined(GLX_VERSION_1_3)
/* #define GLX_NONE                        0x8000 */
#define GLX_TRANSPARENT_RGB             0x8008
#define GLX_TRANSPARENT_INDEX           0x8009
#endif


/*******************************************************************************
** glXCreateGLXPbuffer attributes.
** GLX 1.3 and later.
*/

#if defined(GLX_VERSION_1_3)
#define GLX_PRESERVED_CONTENTS          0x801B
#define GLX_LARGEST_PBUFFER             0x801C
#define GLX_PBUFFER_HEIGHT              0x8040  /* New for GLX 1.3 */
#define GLX_PBUFFER_WIDTH               0x8041  /* New for GLX 1.3 */
#endif


/*******************************************************************************
** glXQueryGLXPBuffer attributes.
** GLX 1.3 and later.
*/

#if defined(GLX_VERSION_1_3)
#define GLX_WIDTH                       0x801D
#define GLX_HEIGHT                      0x801E
#define GLX_EVENT_MASK                  0x801F
#endif


/*******************************************************************************
** glXCreateNewContext render_type attribute values.
** GLX 1.3 and later.
*/

#if defined(GLX_VERSION_1_3)
#define GLX_RGBA_TYPE                   0x8014
#define GLX_COLOR_INDEX_TYPE            0x8015
#endif


/*******************************************************************************
** glXQueryContext attributes.
** GLX 1.3 and later.
*/

#if defined(GLX_VERSION_1_3)
#define GLX_SCREEN                      0x800C
#endif


/*******************************************************************************
** glXSelectEvent event mask bits.
** GLX 1.3 and later.
*/

#if defined(GLX_VERSION_1_3)
#define GLX_PBUFFER_CLOBBER_MASK        0x08000000
#endif


/*******************************************************************************
** GLXPbufferClobberEvent event_type values.
** GLX 1.3 and later.
*/

#if defined(GLX_VERSION_1_3)
#define GLX_DAMAGED                     0x8020
#define GLX_SAVED                       0x8021
#endif


/*******************************************************************************
** GLXPbufferClobberEvent draw_type values.
** GLX 1.3 and later.
*/

#if defined(GLX_VERSION_1_3)
#define GLX_WINDOW                      0x8022
#define GLX_PBUFFER                     0x8023
#endif


/*******************************************************************************
** GLXPbufferClobberEvent buffer_mask bits.
** GLX 1.3 and later.
*/

#if defined(GLX_VERSION_1_3)
#define GLX_FRONT_LEFT_BUFFER_BIT       0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT      0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT        0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT       0x00000008
#define GLX_AUX_BUFFERS_BIT             0x00000010
#define GLX_DEPTH_BUFFER_BIT            0x00000020
#define GLX_STENCIL_BUFFER_BIT          0x00000040
#define GLX_ACCUM_BUFFER_BIT            0x00000080
#endif


/*******************************************************************************
** Names for attributes to glXGetConfig.
** GLX 1.4 and later.
*/

#if defined(GLX_VERSION_1_4)
#define GLX_SAMPLE_BUFFERS              0x186A0 /* Number of multisample buffers. */
#define GLX_SAMPLES                     0x186A1 /* Number of multisample samples. */
#endif


#ifdef __cplusplus
}
#endif

#endif	/* !__gc_glx_tokens_h__ */

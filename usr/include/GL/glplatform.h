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


#ifndef __glplatform_h_
#define __glplatform_h_

/* $Id: glplatform.h,v 1.1 2010/05/19 00:29:40 ashlychkov Exp $ */

#ifdef __cplusplus
extern "C" {
#endif

/*
** License Applicability. Except to the extent portions of this file are
** made subject to an alternative license as permitted in the SGI Free
** Software License B, Version 1.0 (the "License"), the contents of this
** file are subject only to the provisions of the License. You may not use
** this file except in compliance with the License. You may obtain a copy
** of the License at Silicon Graphics, Inc., attn: Legal Services, 1600
** Amphitheatre Parkway, Mountain View, CA 94043-1351, or at:
**
** http://oss.sgi.com/projects/FreeB
**
** Note that, as provided in the License, the Software is distributed on an
** "AS IS" basis, with ALL EXPRESS AND IMPLIED WARRANTIES AND CONDITIONS
** DISCLAIMED, INCLUDING, WITHOUT LIMITATION, ANY IMPLIED WARRANTIES AND
** CONDITIONS OF MERCHANTABILITY, SATISFACTORY QUALITY, FITNESS FOR A
** PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
**
** Original Code. The Original Code is: OpenGL Sample Implementation,
** Version 1.2.1, released January 26, 2000, developed by Silicon Graphics,
** Inc. The Original Code is Copyright (c) 1991-2000 Silicon Graphics, Inc.
** Copyright in any portions created by third parties is as indicated
** elsewhere herein. All Rights Reserved.
**
** Additional Notice Provisions: The application programming interfaces
** established by SGI in conjunction with the Original Code are The
** OpenGL(R) Graphics System: A Specification (Version 1.2.1), released
** April 1, 1999; The OpenGL(R) Graphics System Utility Library (Version
** 1.3), released November 4, 1998; and OpenGL(R) Graphics with the X
** Window System(R) (Version 1.3), released October 19, 1998. This software
** was created using the OpenGL(R) version 1.2.1 Sample Implementation
** published by SGI, but has not been independently verified as being
** compliant with the OpenGL(R) version 1.2.1 Specification.
*/

/*-------------------------------------------------------------------------
 * Definition of GL_APICALL and GL_APIENTRY
 *-----------------------------------------------------------------------*/

#if defined(_WIN32) || defined(__VC32__)
#ifndef GL_APICALL
#if defined (_DLL_EXPORTS)
#			define GL_APICALL __declspec(dllexport)
#		else
#			define GL_APICALL __declspec(dllimport)
#		endif
#	endif
#elif defined (__ARMCC_VERSION)                      /* ADS */
#   define GL_APICALL
#elif defined (__SYMBIAN32__) && defined (__GCC32__) /* Symbian GCC */
#   define GL_APICALL __declspec(dllexport)
#elif defined (__GNUC__)                             /* GCC dependencies (kludge) */
#   define GL_APICALL
#endif

#if !defined (GL_APICALL)
#   error Unsupported platform!
#endif

#define GL_APIENTRY

#ifndef GLAPI
#	define GLAPI GL_APICALL
#	define __DEFINED_GLAPI
#endif

#ifdef __cplusplus
}
#endif

#endif /* __gl2platform_h_ */

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




#ifndef __gc_vdk_types_h_
#define __gc_vdk_types_h_

#ifdef _WIN32
#pragma warning(disable:4127)	/* Conditional expression is constant. */
#pragma warning(disable:4100)	/* Unreferenced formal parameter. */
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <EGL/egl.h>
#include "gc_hal_eglplatform.h"

/*******************************************************************************
** vdkPrivate. *****************************************************************
*/

typedef struct _vdkPrivate *	vdkPrivate;

/*******************************************************************************
** Display. ********************************************************************
*/
typedef EGLNativeDisplayType	vdkDisplay;

/*******************************************************************************
** Window. *********************************************************************
*/
typedef EGLNativeWindowType		vdkWindow;


/*******************************************************************************
** Pixmap. *********************************************************************
*/
typedef EGLNativePixmapType		vdkPixmap;


/*******************************************************************************
** ClientBuffer. ***************************************************************
*/
typedef void *					vdkClientBuffer;


/*******************************************************************************
** Events. *********************************************************************
*/

#define VDK_KEYBOARD        HAL_KEYBOARD
#define VDK_POINTER         HAL_POINTER
#define VDK_BUTTON          HAL_BUTTON
#define VDK_CLOSE           HAL_CLOSE
#define VDK_WINDOW_UPDATE   HAL_WINDOW_UPDATE

#define VDK_UNKNOWN         HAL_UNKNOWN
#define VDK_BACKSPACE       HAL_BACKSPACE
#define VDK_TAB             HAL_TAB
#define VDK_ENTER           HAL_ENTER
#define VDK_ESCAPE          HAL_ESCAPE
#define VDK_SPACE           HAL_SPACE
#define VDK_SINGLEQUOTE     HAL_SINGLEQUOTE
#define VDK_PAD_ASTERISK    HAL_PAD_ASTERISK
#define VDK_COMMA           HAL_COMMA
#define VDK_HYPHEN          HAL_HYPHEN
#define VDK_PERIOD          HAL_PERIOD
#define VDK_SLASH           HAL_SLASH
#define VDK_0               HAL_0
#define VDK_1               HAL_1
#define VDK_2               HAL_2
#define VDK_3               HAL_3
#define VDK_4               HAL_4
#define VDK_5               HAL_5
#define VDK_6               HAL_6
#define VDK_7               HAL_7
#define VDK_8               HAL_8
#define VDK_9               HAL_9
#define VDK_SEMICOLON       HAL_SEMICOLON
#define VDK_EQUAL           HAL_EQUAL
#define VDK_A               HAL_A
#define VDK_B               HAL_B
#define VDK_C               HAL_C
#define VDK_D               HAL_D
#define VDK_E               HAL_E
#define VDK_F               HAL_F
#define VDK_G               HAL_G
#define VDK_H               HAL_H
#define VDK_I               HAL_I
#define VDK_J               HAL_J
#define VDK_K               HAL_K
#define VDK_L               HAL_L
#define VDK_M               HAL_M
#define VDK_N               HAL_N
#define VDK_O               HAL_O
#define VDK_P               HAL_P
#define VDK_Q               HAL_Q
#define VDK_R               HAL_R
#define VDK_S               HAL_S
#define VDK_T               HAL_T
#define VDK_U               HAL_U
#define VDK_V               HAL_V
#define VDK_W               HAL_W
#define VDK_X               HAL_X
#define VDK_Y               HAL_Y
#define VDK_Z               HAL_Z
#define VDK_LBRACKET        HAL_LBRACKET
#define VDK_BACKSLASH       HAL_BACKSLASH
#define VDK_RBRACKET        HAL_RBRACKET
#define VDK_BACKQUOTE       HAL_BACKQUOTE
#define VDK_F1              HAL_F1
#define VDK_F2              HAL_F2
#define VDK_F3              HAL_F3
#define VDK_F4              HAL_F4
#define VDK_F5              HAL_F5
#define VDK_F6              HAL_F6
#define VDK_F7              HAL_F7
#define VDK_F8              HAL_F8
#define VDK_F9              HAL_F9
#define VDK_F10             HAL_F10
#define VDK_F11             HAL_F11
#define VDK_F12             HAL_F12
#define VDK_LCTRL           HAL_LCTRL
#define VDK_RCTRL           HAL_RCTRL
#define VDK_LSHIFT          HAL_LSHIFT
#define VDK_RSHIFT          HAL_RSHIFT
#define VDK_LALT            HAL_LALT
#define VDK_RALT            HAL_RALT
#define VDK_CAPSLOCK        HAL_CAPSLOCK
#define VDK_NUMLOCK         HAL_NUMLOCK
#define VDK_SCROLLLOCK      HAL_SCROLLLOCK
#define VDK_PAD_0           HAL_PAD_0
#define VDK_PAD_1           HAL_PAD_1
#define VDK_PAD_2           HAL_PAD_2
#define VDK_PAD_3           HAL_PAD_3
#define VDK_PAD_4           HAL_PAD_4
#define VDK_PAD_5           HAL_PAD_5
#define VDK_PAD_6           HAL_PAD_6
#define VDK_PAD_7           HAL_PAD_7
#define VDK_PAD_8           HAL_PAD_8
#define VDK_PAD_9           HAL_PAD_9
#define VDK_PAD_HYPHEN      HAL_PAD_HYPHEN
#define VDK_PAD_PLUS        HAL_PAD_PLUS
#define VDK_PAD_SLASH       HAL_PAD_SLASH
#define VDK_PAD_PERIOD      HAL_PAD_PERIOD
#define VDK_PAD_ENTER       HAL_PAD_ENTER
#define VDK_SYSRQ           HAL_SYSRQ
#define VDK_PRNTSCRN        HAL_PRNTSCRN
#define VDK_BREAK           HAL_BREAK
#define VDK_UP              HAL_UP
#define VDK_LEFT            HAL_LEFT
#define VDK_RIGHT           HAL_RIGHT
#define VDK_DOWN            HAL_DOWN
#define VDK_HOME            HAL_HOME
#define VDK_END             HAL_END
#define VDK_PGUP            HAL_PGUP
#define VDK_PGDN            HAL_PGDN
#define VDK_INSERT          HAL_INSERT
#define VDK_DELETE          HAL_DELETE
#define VDK_LWINDOW         HAL_LWINDOW
#define VDK_RWINDOW         HAL_RWINDOW
#define VDK_MENU            HAL_MENU
#define VDK_POWER           HAL_POWER
#define VDK_SLEEP           HAL_SLEEP
#define VDK_WAKE            HAL_WAKE

typedef halEvent vdkEvent;

#ifdef __cplusplus
}
#endif

#endif /* __gc_vdk_types_h_ */

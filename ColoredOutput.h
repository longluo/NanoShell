/*
** 	ColoredOutput.h: 
**		Macros definitions for colored output in BASH or Serial.
**  Created by long.luo <uniqueluolong@gmail.com>
**
** addtogroup NanoShell
** @{
*/

#ifndef __COLORED_OUTPUT_H__
#define __COLORED_OUTPUT_H__

#include "NanoShell_Config.h"


#if defined _BASH_

// Normal colors
#define BLACK(x)  "\e[0;30m" x "\e[0m"   // Black
#define RED(x)    "\e[0;31m" x "\e[0m"   // Red
#define GREEN(x)  "\e[0;32m" x "\e[0m"   // Green
#define YELLOW(x) "\e[0;33m" x "\e[0m"   // Yellow
#define BLUE(x)   "\e[0;34m" x "\e[0m"   // Blue
#define PURPLE(x) "\e[0;35m" x "\e[0m"   // Purple
#define CYAN(x)   "\e[0;36m" x "\e[0m"   // Cyan
#define WHITE(x)  "\e[0;37m" x "\e[0m"   // White

// Bold colors
#define BOLD_BLACK(x)  "\e[1;30m" x "\e[0m"   // Black
#define BOLD_RED(x)    "\e[1;31m" x "\e[0m"   // Red
#define BOLD_GREEN(x)  "\e[1;32m" x "\e[0m"   // Green
#define BOLD_YELLOW(x) "\e[1;33m" x "\e[0m"   // Yellow
#define BOLD_BLUE(x)   "\e[1;34m" x "\e[0m"   // Blue
#define BOLD_PURPLE(x) "\e[1;35m" x "\e[0m"   // Purple
#define BOLD_CYAN(x)   "\e[1;36m" x "\e[0m"   // Cyan
#define BOLD_WHITE(x)  "\e[1;37m" x "\e[0m"   // White

// Underlined colors
#define UNDER_BLACK(x)  "\e[4;30m" x "\e[0m"   // Black
#define UNDER_RED(x)    "\e[4;31m" x "\e[0m"   // Red
#define UNDER_GREEN(x)  "\e[4;32m" x "\e[0m"   // Green
#define UNDER_YELLOW(x) "\e[4;33m" x "\e[0m"   // Yellow
#define UNDER_BLUE(x)   "\e[4;34m" x "\e[0m"   // Blue
#define UNDER_PURPLE(x) "\e[4;35m" x "\e[0m"   // Purple
#define UNDER_CYAN(x)   "\e[4;36m" x "\e[0m"   // Cyan
#define UNDER_WHITE(x)  "\e[4;37m" x "\e[0m"   // White

// Backround color
#define BKG_BLACK(x)  "\e[40m" x "\e[0m"   // Black
#define BKG_RED(x)    "\e[41m" x "\e[0m"   // Red
#define BKG_GREEN(x)  "\e[42m" x "\e[0m"   // Green
#define BKG_YELLOW(x) "\e[43m" x "\e[0m"   // Yellow
#define BKG_BLUE(x)   "\e[44m" x "\e[0m"   // Blue
#define BKG_PURPLE(x) "\e[45m" x "\e[0m"   // Purple
#define BKG_CYAN(x)   "\e[46m" x "\e[0m"   // Cyan
#define BKG_WHITE(x)  "\e[47m" x "\e[0m"   // White

#elif defined _SERIAL_

// Normal colors
#define BLACK(x)  "\033[0;30m" x "\033[0m"   // Black
#define RED(x)    "\033[0;31m" x "\033[0m"   // Red
#define GREEN(x)  "\033[0;32m" x "\033[0m"   // Green
#define YELLOW(x) "\033[0;33m" x "\033[0m"   // Yellow
#define BLUE(x)   "\033[0;34m" x "\033[0m"   // Blue
#define PURPLE(x) "\033[0;35m" x "\033[0m"   // Purple
#define CYAN(x)   "\033[0;36m" x "\033[0m"   // Cyan
#define WHITE(x)  "\033[0;37m" x "\033[0m"   // White

// Bold colors
#define BOLD_BLACK(x)  "\033[1;30m" x "\033[0m"   // Black
#define BOLD_RED(x)    "\033[1;31m" x "\033[0m"   // Red
#define BOLD_GREEN(x)  "\033[1;32m" x "\033[0m"   // Green
#define BOLD_YELLOW(x) "\033[1;33m" x "\033[0m"   // Yellow
#define BOLD_BLUE(x)   "\033[1;34m" x "\033[0m"   // Blue
#define BOLD_PURPLE(x) "\033[1;35m" x "\033[0m"   // Purple
#define BOLD_CYAN(x)   "\033[1;36m" x "\033[0m"   // Cyan
#define BOLD_WHITE(x)  "\033[1;37m" x "\033[0m"   // White

// Underlined colors
#define UNDER_BLACK(x)  "\033[4;30m" x "\033[0m"   // Black
#define UNDER_RED(x)    "\033[4;31m" x "\033[0m"   // Red
#define UNDER_GREEN(x)  "\033[4;32m" x "\033[0m"   // Green
#define UNDER_YELLOW(x) "\033[4;33m" x "\033[0m"   // Yellow
#define UNDER_BLUE(x)   "\033[4;34m" x "\033[0m"   // Blue
#define UNDER_PURPLE(x) "\033[4;35m" x "\033[0m"   // Purple
#define UNDER_CYAN(x)   "\033[4;36m" x "\033[0m"   // Cyan
#define UNDER_WHITE(x)  "\033[4;37m" x "\033[0m"   // White

// Backround color
#define BKG_BLACK(x)  "\033[40m" x "\033[0m"   // Black
#define BKG_RED(x)    "\033[41m" x "\033[0m"   // Red
#define BKG_GREEN(x)  "\033[42m" x "\033[0m"   // Green
#define BKG_YELLOW(x) "\033[43m" x "\033[0m"   // Yellow
#define BKG_BLUE(x)   "\033[44m" x "\033[0m"   // Blue
#define BKG_PURPLE(x) "\033[45m" x "\033[0m"   // Purple
#define BKG_CYAN(x)   "\033[46m" x "\033[0m"   // Cyan
#define BKG_WHITE(x)  "\033[47m" x "\033[0m"   // White

#endif /*_SERIAL_*/

#endif/*__COLORED_OUTPUT_H__*/

/*
** Close the group.
** @}
*/


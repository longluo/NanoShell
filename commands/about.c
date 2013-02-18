/*
** 	about.c: 
**		
**  Created by long.luo <uniqueluolong@gmail.com>
**
** addtogroup NanoShell
** @{
*/

#include "about.h"
#include "../ColoredOutput.h"

extern int (* ns_printf)(const char *format, ...);
extern void (* ns_gets)(char *str, unsigned int size);

int about(void) 
{
	ns_printf("\n" BOLD_YELLOW("NanoShell") " - A Nano Shell program.\n"
			"Written in C by " BOLD_GREEN("long.luo") " <"
			BOLD_YELLOW("uniqueluolong@gmail.com") ">\n\n");

	return 0;
}

/*
** Close the group.
** @}
*/
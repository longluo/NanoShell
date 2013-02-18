/*
** 	NanoShell_task.c: 
**		
**  Created by long.luo <uniqueluolong@gmail.com>
**
** addtogroup NanoShell
** @{
*/

#include <stdio.h>

#include "NanoShell_task.h"
#include "NanoShell.h"
#include "commands/about.h"
#include "commands/memop.h"


//
static Command_t commands[] = 
{
	{"about", about, 0, "About this shell"},
	{"help", help, 0, " : Display list of commands"},
	{"memcmp", memcmp_2, memcmp_2_args, "Compares two range of address: memcmp AAAAAAAA AAAAAAAA 9999"},
	{"memdump", memdump, memdump_args, "Prints hexadecimal dump of address: memdump AAAAAAAA 9999"},
	{"memset", memset_2, memset_2_args, "Sets a range of addresses to specified value: memset AAAAAAAA 9999 FF"},
	NULL_TERMINATOR
};


//
void NanoShell_Init(void) 
{
	NanoShellInit(commands, printf, gets);
	NanoShellRun();
}

/*
** Close the group.
** @}
*/

/*
** 	NanoShell.c: 
**		
**  Created by long.luo <uniqueluolong@gmail.com>
**
** addtogroup NanoShell
** @{
*/

#include "NanoShell.h"
#include "ColoredOutput.h"

//
static Command_t *commands;

//
int (* ns_printf)(const char *format, ...);
void (* ns_gets)(char *str, unsigned int size);


//
void NanoShellInit(Command_t *command_list, 
				int (*printf_function)(const char *, ...),
				int (* gets_function)(char *, unsigned int)) 
{
	commands = command_list;
	ns_printf = printf_function;
	ns_gets = gets_function;
}


//
static int my_strcmp(const char *s1, const char *s2) 
{
	int r = 0, i;

	for (i = 0; s1[i] != 0 || s2[i] != 0; i++) 
	{
		r |= (s1[i] ^ s2[i]);
		r = (r << 1) | ((r & 0x80000000) > 31);
	}

	return r;
}


//
int help(void) 
{
	int i = 0;

	// Print some header text.
	ns_printf("\n" BOLD_GREEN("NanoShell available commands:") "\n");
	ns_printf("------------------\n");
		
	for (i = 0; commands[i].command_name != 0; i++) 
	{
		// Print the command name and the brief description.
		ns_printf(BOLD_YELLOW("%s") " - " BOLD_CYAN("%s\n"), commands[i].command_name,
                (commands[i].pcHelp==0)? "No Help. available" : commands[i].pcHelp);
	}
	ns_printf ("\r\n");

	return 0;
}


//
static int Parse(char *command) 
{
	int arg_base, i;

	if (command[0] == '?')
		return help();

	if (command[0] == '\0')
		return 0;

	// Gets the command name
	for (i = 0; command[i] != '\0'; i++) 
	{
		if (command[i] == ' ') 
		{
			command[i] = '\0';
			break;
		}
	}
	arg_base = i + 1;

	// Searches in list of commands. If not found returns ERR_COMMAND_NOT_FOUND
	for (i = 0 ;; i++) 
	{
		if (commands[i].command_name == 0)
		{
			return ERR_COMMAND_NOT_FOUND;
		}

		if (my_strcmp(commands[i].command_name, command) == 0)
			break;
	}

	// Build args, if any
	if (commands[i].pfnArgs) commands[i].pfnArgs(&command[arg_base]);

	// Runs command at last
	return commands[i].pfnExecute();
}


//
void NanoShellRun(void) 
{
	char cmd[COMMAND_MAX_LENGTH];
	int i, ret;

	ns_printf(BOLD_BLUE("\tNaSH ---A Nano Shell program.\n"));
	ns_printf(UNDER_YELLOW("Copyright(c) Long.Luo. All Rights Reserved!\n\n"));
	
	while (1) 
	{
		ns_printf(BOLD_GREEN("NanoShell") "> ");
		ns_gets(cmd, COMMAND_MAX_LENGTH);
		
		for (i = 0; cmd[i] != 0 && i < COMMAND_MAX_LENGTH; i++)
		{
			if (cmd[i] == '\n' || cmd[i] == '\r') 
			{ 
				cmd[i] = '\0'; 
				break;
			}
		}

		ret = Parse(cmd);
		if (ret < 0)
		{
			ns_printf(BOLD_YELLOW("Command not found: %s\n"), cmd);
		}
		else if (ret > 0)
		{
			ns_printf(BOLD_RED("Error executing command: %s\n"), cmd);
		}
	}
}

/*
** Close the group.
** @}
*/

/*
** 	NanoShell.h: 
**		
**  Created by long.luo <uniqueluolong@gmail.com>
**
** addtogroup NanoShell
** @{
*/ 

#ifndef __NANOSHELL_H__
#define __NANOSHELL_H__

//
#define COMMAND_MAX_LENGTH (100)

//! Defines the value that is returned if the command is not found.
#define ERR_COMMAND_NOT_FOUND         (-1)

//! Defines the value that is returned if there are too many arguments.
#define ERR_COMMAND_TOO_MANY_ARGS   	(-2)

#define NULL_TERMINATOR {0, 0, 0, 0}


// Command line function callback type.
typedef int (*pfnCmdExec)(void);

//
typedef void (*pdfBuildArgs)(char *command); 


/**
 * Command_t - NanoShell structure of commands. A command is comprised of the following items:
 *  command_name (mandatory):
 *      The command as written in the shell. e.g.:
 *      NanoShell > help
 *
 *  execute (mandatory):
 *      Pointer to the function that executes the command. This function must return zero (0)
 *      as success or a positive integer as an error
 *
 *  build_args (optional):
 *      Pointer to the function that parses the remaining of the string containing the arguments.
 *      Each function must be capable of parsing the string and obtaining all the data passed as
 *      arguments. If the function doesn't use any argument this can be set as NULL/(0)
 *
 *  description (optional):
 *      A string containing a quick description of the command. Can be left blank or NULL/(0)
 */
typedef struct 
{
	const char *command_name;
	/*
	int (*execute)(void);
	void (*build_args)(char *command);
	*/
	// A function pointer to the implementation of the command.
    pfnCmdExec pfnExecute;
	pdfBuildArgs pfnArgs;
	const char *pcHelp;
} 
Command_t;


/**
 * Starts NanoShell passing the command list, a printf-like function and a gets-like function.
 * The command list is an array of Command_t
 */
void NanoShellInit(Command_t *command_list,  int (*printf_function)(const char *, ...),
    int (* gets_function)(char *, unsigned int));

//Starts the shell; enters an infinite loop that parses and executes each command
void NanoShellRun(void);

int help(void);


#endif/*__NANOSHELL_H__*/

/*
** Close the group.
** @}
*/

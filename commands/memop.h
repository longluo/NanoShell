/*
** 	memop.h: 
**		
**  Created by long.luo <uniqueluolong@gmail.com>
**
** addtogroup NanoShell
** @{
*/

#ifndef __MEMOP_H__
#define __MEMOP_H__

/* Memory compare command: compares [amount] bytes from [address1] to [address2] and see it they match
 *
 * memcmp [address1] [address2] [amount] */
int memcmp_2(void);
void memcmp_2_args(char *command);

/* Memory dump command: dumps the hexadecimal representation of [address] until offset [amount]
 *
 * memdump [address] [amount] */
int memdump(void);
void memdump_args(char *command);

/* Memory set: sets a range of [amount] bytes from [address] to [value]
 *
 * memset [address] [amount] [value] */
int memset_2(void);
void memset_2_args(char *command);

/* External declaration of printf */
extern int (* ns_printf)(const char *format, ...);

#endif/*__MEMOP_H__*/

/*
** Close the group.
** @}
*/

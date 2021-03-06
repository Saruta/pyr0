/*
 * File: console.h
 * Author: Fabien Siron <fabien.siron@epita.fr>
 *
 * Description: stuff about console and early console
 */

#ifndef _CONSOLE_H_
# define _CONSOLE_H_

# include <kernel/types.h>

/* early stuff */
void early_console_init (void);
int early_kdebug (const char *s, size_t length);

/* vga con_init */

void console_init(void);
void console_putchar(char n);
size_t console_write(const char *buf, size_t len);

#endif /*!_CONSOLE_H_*/

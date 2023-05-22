#ifndef FT_PRINTF
# define FT_PRINTF

# include "ft_libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int ft_printf(const char *format, ...);

// Linked list management

/*
int	ft_addchar(t_list **s_clst, const char *format);
int	ft_addstring(t_list s_clst, va_list params, const char *format);
int	ft_addhex(t_list s_clst, va_list params, const char *format);
int	ft_addhexupper(t_list s_clst, va_list params, const char *format);
int	ft_addint(t_list s_clst, va_list params, const char *format);
int	ft_addnum(t_list s_clst, va_list params, const char *format);
int	ft_addunsint(t_list s_clst, va_list params, const char *format);
*/

// Aux functions
void	ft_del(void *cont);

#endif

/* 
printf() & Variable Args
------------------------

MAN SUMMARY && KEY CONCEPTS
###########################

printf() is part of the <stdio.h> library.
Its functions print the given 'format' to:
a. stdoutpu
b. file
c. string

Prototype:
##########

{
	int	*ft_printf(const char *format, ...);
}

ATTENTION! 
Those '...' are not an indication that more things will come here
It is the explicit declaration of a variable argument.

Behaviour:
##########

In the case of printf() it writes 'fotmat' = {char *format} in the stdoutput interpolating the refered vars delimited by the char '%' for its corresponding values. You've already use it so you know what it means!

Format string
-------------
It has zero or more directives (%_ where _ is a the conversion specifier).

The 'format' string controls how the 'subsequent_arguments' = {...} are processed to latter be displayed in the stdoutput.
(YES! Those are the '...' in the agrs of the prototype of the function.)

Subsequent arguments
--------------------
The 'subsequent_arguments' are implemented using variable number of arguments provided by the <stdarg.h> library. 
[Ctrl] + [Click] to learn more >>
https://man7.org/linux/man-pages/man3/stdarg.3.html

	KEY CONCEPTS:
	a. include the <sdtarg.h> lib

	b. prototype/declare the functions as:
		{
			int function(int potatoes, ...)
		}

	c. declare the variable of type 'va_list' where you will receive the '...':
		{
			va_list my_variable_args;
		}

	d. initialize the variable 'my_variable_args':
		{
			va_start(my_variable_args, potatoes);
		}
		
		YES! It swittches its order.
		
		You can't receive '...' without at least one previous arg.
		The '...' must be the last arg you get.
				
	e. acces the variable arguments:
		{
			int value = va_arg(my_variable_args, int);
		}

		This action access the memory where the memory of the first variable argument, cast it in the specified type and retruns its value. Also, moves the pointer of the variable arguments to the next position.

	EUREKA! The variable args can be understood as a linked list of void pointers. So you have to specify the type to access its values properly. If you don't understand linked lists yet, go through the LIBFT bonus section.

	But...! How to know what is the type of each argument? This is the function of the previous arguments. The type of the arguments is not hardcoded in your program. It is know during execution time. So thake that into account.
:w
	In the case of 'printf()' the 'format' string has that information for you. So you have to read the format string in order to know how to read the variable arguments that the user of the function is providing.

	f. Use the value of your argument. Sorte it, pass it to another function... U2Y!

	g. Close the variable argument.
	{
		va_end(my_variable_args);
	}

SUMMARY OF VARIABLE ARGS IMPLEMENTATION
#######################################

1. { #include <stdarg.h> }
2. { int function(int potatoes, ...); }
3. { va_list my_variable_args; }
4. { va_start(my_variable_args); }
5. { int value = va_arg(my_variable_arg, type); }
6. { va_end(my_variable_args); }
<<<<<<< HEAD

=======
*/

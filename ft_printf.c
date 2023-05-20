#include "ft_printf.h"
#include "ft_libft/libft.h"

// c s p d i(0, 0b, 0x) u x X %

// todas las funciones reciben el puntero en el char previo al que deben procesar
	// addchar() adds a char to clst
	// addint() takes char as param, d for int and i to check format
	// addstring() adds string
	// addhex() adds lowercase hex
	// addhexupper() adds uppercase hex
	// addunsint() adds uninsgend int

static int	ft_process(const char format, va_list params, t_list *clst)
{
	int control;

	control = 1;
	while (control && *format)
	{
		if (*format != '%')
			control = ft_addchar(clst, format);
		else if (*format == '%' && *(format + 1) == '%')
			control = ft_addchar(clst, ++format);
			/*
		else if (*format == '%' && *(format + 1) == 'c')
			control = ft_addcharva(clst, params, ++format);
		else if (*format == '%' && *(format + 1) == 's')
			control = ft_addstring(clst, params, ++format);
		else if (*format == '%' && *(format + 1) == 'p')
			control = ft_addhex(clst, params, ++format);
		else if (*format == '%' && *(format + 1) == 'd')
			control = ft_addint(clst, params, ++format);
		else if (*format == '%' && *(format + 1) == 'i')
			control = ft_addnum(clst, params, ++format);
		else if (*format == '%' && *(format + 1) == 'u')
			control = ft_addunsint(clst, params, ++format);
		else if (*format == '%' && *(format + 1) == 'x')
			control = ft_addhex(clst, params, ++format);
		else if (*format == '%' && *(format + 1) == 'X')
			control = ft_addhexupper(clst, params, ++format);*/
		format++;
	}
	return (control);
}

int	ft_printf(const char format, ...)
{
	va_list	params; // params
	t_list	*clst; // head of the linked list of chars
	int		control;
	int		printed; // count of the chars printed

	va_start(params);
	clst = NULL;
	control = ft_process(format, params, clst);
	va_end(params);
	if (control > 0)
		printed = ft_lstprint(clst);
	ft_lstclear(clst, ft_del);
	clst = NULL;
	return (printed);
}

int	main(void)
{
	ft_printf("Hola Mundo!");
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:38:52 by apchelni          #+#    #+#             */
/*   Updated: 2024/10/03 18:38:55 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_fspec(const char **input, va_list args, int length)
{
	(*input)++;
	if (**input == '%')
		length = handle_char('%');
	else if (**input == '\0')
		return (-1);
	else if (**input == 'c')
		length = handle_char((char)va_arg(args, int));
	else if (**input == 's')
		length = handle_str(va_arg(args, char *));
	else if (**input == 'd' || **input == 'i')
		length = handle_dec(va_arg(args, int));
	else if (**input == 'u')
		length = handle_un(va_arg(args, unsigned int));
	else if (**input == 'x' || **input == 'X')
		length = handle_hex(va_arg(args, size_t), **input);
	else if (**input == 'p')
		length = handle_p(va_arg(args, void *));
	else
	{
		length = handle_char('%');
		length += handle_char(**input);
	}
	return (length);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		length;
	int		spec_res;

	va_start(args, input);
	length = 0;
	if (!input)
		return (-1);
	while (*input)
	{
		if (*input == '%')
		{
			spec_res = check_fspec(&input, args, length);
			if (spec_res == -1)
				return (-1);
			else
				length += spec_res;
		}
		else
			length += handle_char(*input);
		input++;
	}
	va_end (args);
	return (length);
}

#include "ft_printf.h"
#include <limits.h>

int main(void)
{
    char c = 'A';
    char *s = "Hello, ft_printf!";
    void *p = s;
    int d = -12345;
    int i = 67890;
    unsigned int u = 4294967295U; // UINT_MAX
    int hex = 48879; // 0xBEEF

    ft_printf("%%c: %c\n", c);
    ft_printf("%%s: %s\n", s);
    ft_printf("%%p: %p\n", p);
    ft_printf("%%d: %d\n", d);
    ft_printf("%%i: %i\n", i);
    ft_printf("%%u: %u\n", u);
    ft_printf("%%x: %x\n", hex);
    ft_printf("%%X: %X\n", hex);
    ft_printf("%%%%: %%\n");

    return 0;
}

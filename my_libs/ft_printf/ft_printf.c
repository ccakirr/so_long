/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:48:00 by ccakir            #+#    #+#             */
/*   Updated: 2025/06/25 17:48:00 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbru_fd(unsigned int n, int fd)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += ft_putnbru_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
	count++;
	return (count);
}

int	putptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		count += ft_putstr_fd("(nil)", 1);
	else
	{
		count += ft_putstr_fd("0x", 1);
		count += lower_hexa_printer(ptr);
	}
	return (count);
}

static int	is_format(char contype)
{
	if (contype == 'c' || contype == 's' || contype == 'p' || contype == 'd'
		|| contype == 'i' || contype == 'u' || contype == 'x' || contype == 'X')
		return (1);
	return (0);
}

static int	formatter(char type, va_list args)
{
	if (!is_format(type))
		return (0);
	if (type == 'c')
		return (ft_putchar_fd((char)va_arg(args, int), 1));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (type == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (type == 'u')
		return (ft_putnbru_fd(va_arg(args, unsigned int), 1));
	else if (type == '%')
		return (ft_putchar_fd('%', 1));
	else if (type == 'x')
		return (lower_hexa_printer(va_arg(args, unsigned int)));
	else if (type == 'X')
		return (higher_hexa_printer(va_arg(args, unsigned int)));
	else if (type == 'p')
		return (putptr((unsigned long long)va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		size;

	i = 0;
	size = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && is_format(format[i + 1]))
		{
			size += formatter(format[i + 1], args);
			i += 2;
		}
		else
		{
			if (format[i] == '%')
				i++;
			ft_putchar_fd(format[i], 1);
			i++;
			size++;
		}
	}
	va_end(args);
	return (size);
}

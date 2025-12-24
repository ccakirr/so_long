/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:28:08 by ccakir            #+#    #+#             */
/*   Updated: 2025/06/25 17:28:08 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_putstr_fd(char *str, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putchar_fd(unsigned char c, int fd);
int		ft_printf(const char *format, ...);
int		lower_hexa_printer(unsigned long long n);
int		higher_hexa_printer(unsigned long long n);
#endif

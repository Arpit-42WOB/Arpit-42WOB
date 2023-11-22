/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:08:40 by amehrotr          #+#    #+#             */
/*   Updated: 2023/06/06 18:55:46 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdlib.h>
# include<stdarg.h>
# include<unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(int c);
int	ft_puthexa_low(unsigned int num);
int	ft_puthexa_up(unsigned int num);
int	ft_putnbr(int num);
int	ft_putptr(unsigned long num);
int	ft_putstr(char *s);
int	ft_putunbr(unsigned int num);

#endif
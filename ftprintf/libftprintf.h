/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:21:29 by rabril-h          #+#    #+#             */
/*   Updated: 2022/02/11 23:10:43 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *s, ...);
int		ft_putchar_cnt(const char s);
int		ft_putstr_cnt(const char *s);
int		ft_putptr_cnt(unsigned long int n);
int		ft_putnbr_cnt(int n);
int		ft_putunbr_cnt(unsigned int n, int l);
int		ft_puthnbr_cnt(unsigned int n, char c);

#endif

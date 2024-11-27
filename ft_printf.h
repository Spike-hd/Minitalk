/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hduflos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:55:28 by hduflos           #+#    #+#             */
/*   Updated: 2024/11/16 14:50:22 by hduflos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	print_char(int c);
int	print_string(char *str);
int	print_hexa(int n, char c);
int	void_to_hexa(void *p);
int	print_nbr(int n);
int	print_unbr(unsigned int n);

#endif

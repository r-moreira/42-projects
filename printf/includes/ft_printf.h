/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:09:19 by romoreir          #+#    #+#             */
/*   Updated: 2020/09/20 14:09:19 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>
#include <wchar.h>

# define IS_FLAG(c)		(((c) == '0' || (c) == '-') ? true : false)
# define IS_CONV(c)		(((c) == 'c' || (c) == 's' || (c) == 'p' ||\
						(c) == 'd' || (c) == 'i' || (c) == 'u' ||\
						(c) == 'x' || (c) == 'X' || (c) == '%') ? true : false)
# define IS_STAR(c)		(((c) == '*') ? true : false)
# define IS_PREC(c)		(((c) == '.') ? true: false)
# define IS_OPTN(c)		((IS_FLAG(c) || IS_STAR(c) ||\
						IS_PREC (c)) ? true : false)
# define PAD_LEFT(len)	tools.opts.width > (len) && !tools.flags.minus
# define PAD_RIGTH(len)	tools.opts.width > (len) && tools.flags.minus
# define ZERO_FLAG		tools.flags.zero && tools.opts.precision == -1 &&\
						!tools.flags.minus
# define IS_STR_CONV(c)	(((c) == 'c' || (c) == 's') ? true: false)
# define IS_NBR_CONV(c)	(((c) == 'd' || (c) == 'i' || (c) == 'u' ||\
						(c) == 'x' || (c) == 'X' || (c) == 'p') ? true: false)
# define DECIMAL		10
# define LOWER_HEXA		97
# define UPPER_HEXA		65
# define ABS(n) 		((n < 0) ? -(n) : (n))

typedef struct	s_flags
{
	bool		zero;
	bool		minus;
}				t_flags;

typedef	struct	s_options
{
	ssize_t		width;
	ssize_t		precision;
}				t_options;

typedef	struct	s_conversion
{
	t_flags		flags;
	t_options	opts;
	ssize_t		count;
	char		conv;
	int			sign;
}				t_conversion;

typedef	int	(*t_functs)(va_list *, t_conversion);

typedef	struct	s_ptr_functs
{
	t_functs	functs[10];
	char		conversions[10];
}				t_ptr_functs;

typedef union	u_arg_types
{
	char				_char;
	int					_int;
	unsigned int		_uint;
	long unsigned int	_luint;
	char				*_char_ptr;
	void				*_void_ptr;
}				t_arg_types;

int				ft_set_ptr_functs(t_ptr_functs **ptr);
void			ft_set_parse_tools(t_conversion *tools);
int 			ft_is_input_valid(const char *str);
void			ft_define_flags(const char **str, t_conversion *tools);
void			ft_define_width(const char **str, va_list *args,
t_conversion *tools);
void			ft_define_precision(const char **str, va_list *args,
t_conversion *tools);
void			ft_print_width(t_conversion tools, int len);
void			ft_print_precision(t_conversion tools, int len);
int				ft_get_output_len(char *arg_str, t_conversion tools);
char 			*ft_nbr_to_str(int base, t_arg_types arg, t_conversion tools);
int				ft_ptr_funct_character(va_list *args, t_conversion tools);
int				ft_ptr_funct_string(va_list *args, t_conversion tools);
int				ft_ptr_funct_pointer(va_list *args, t_conversion tools);
int				ft_ptr_funct_integer(va_list *args, t_conversion tools);
int				ft_ptr_funct_hexadecimal(va_list *args, t_conversion tools);
int				ft_ptr_funct_percent(va_list *args, t_conversion tools);
#endif

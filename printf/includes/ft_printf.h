/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:09:19 by romoreir          #+#    #+#             */
/*   Updated: 2020/10/22 01:22:14 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# define DECIMAL		10
# define LOWER_HEXA		97
# define UPPER_HEXA		65

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
	char				u_char;
	int					u_int;
	unsigned int		u_uint;
	long unsigned int	u_luint;
	char				*u_char_ptr;
	void				*u_void_ptr;
}				t_arg_types;

typedef enum	e_conversion_params
{
	E_FALSE,
	E_DIGIT,
	E_STAR,
	E_PREC,
	E_FLAG,
	E_CONV
}				t_conversion_params;

int				ft_set_ptr_functs(t_ptr_functs **ptr);
void			ft_set_parse_tools(t_conversion *tools);
int				ft_is_input_valid(const char *str);
int				ft_is_option(char c);
int				ft_is_conversion(char c);
void			ft_define_flags(const char **str, t_conversion *tools);
void			ft_define_width(const char **str, va_list *args,
t_conversion *tools);
void			ft_define_precision(const char **str, va_list *args,
t_conversion *tools);
void			ft_print_width(t_conversion tools, int len);
void			ft_print_precision(t_conversion tools, int len);
char			*ft_nbr_to_str(int base, t_arg_types arg, t_conversion *tools);
int				ft_ptr_funct_character(va_list *args, t_conversion tools);
int				ft_ptr_funct_string(va_list *args, t_conversion tools);
int				ft_ptr_funct_pointer(va_list *args, t_conversion tools);
int				ft_ptr_funct_integer(va_list *args, t_conversion tools);
int				ft_ptr_funct_hexadecimal(va_list *args, t_conversion tools);
int				ft_ptr_funct_percent(va_list *args, t_conversion tools);
#endif

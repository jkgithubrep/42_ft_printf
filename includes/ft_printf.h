/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:18:38 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/06 10:00:14 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/types.h>

/*
** Typedefs
*/
typedef char				t_char;
typedef	short				t_short;
typedef int					t_int;
typedef long int			t_lint;
typedef long long			t_llint;
typedef	unsigned char		t_uchar;
typedef unsigned short		t_ushort;
typedef unsigned int		t_uint;
typedef unsigned long		t_ulint;
typedef unsigned long long	t_ullint;
typedef float				t_float;
typedef double				t_double;
typedef long double			t_ldouble;

/*
** Union to store the different int types
*/
typedef union				u_ints{
	t_char					s_char;
	t_short					s_short;
	t_int					s_int;
	t_lint					s_lint;
	t_llint					s_llint;
	ssize_t					s_size_t;
	intmax_t				s_intmax;
	t_uchar					u_char;
	t_ushort				u_short;
	t_uint					u_int;
	t_ulint					u_lint;
	t_ullint				u_llint;
	size_t					u_size_t;
	uintmax_t				u_intmax;
}							t_ints;

/*
** Union to store the different double types
*/
typedef union				u_dbls{
	t_float					fl;
	t_double				dbl;
	t_ldouble				ldbl;
}							t_dbls;

# define EXIT_FAIL          -1
# define BUF_SIZE			4096

/*
** Length modifiers j and z not handled
*/

# define TYPES             "dDiuUoOxXfeEgGaAcsp"
# define SIGNED_TYPES      "di"
# define FLAGS             "-+ 0#"
# define LEN_MODIFS        "hlLjz"
# define NUM_TYPES         "douxXi"
# define TYPE_PREFIX       "xX"

/*
** DOLLAR and ASTERISK unused.
*/

# define DOLLAR            '$'
# define ASTERISK          '*'
# define DOT               '.'
# define PERCENT           '%'

# define MINUS             '-'
# define PLUS              '+'
# define SPACE             ' '
# define HASH              '#'
# define ZERO              '0'

# define DEC_BASE          "0123456789"
# define OCT_BASE          "01234567"
# define L_HEX_BASE        "0123456789abcdef"
# define U_HEX_BASE        "0123456789ABCDEF"

# define PREF_OCT          "0"
# define PREF_L_HEX        "0x"
# define PREF_U_HEX        "0X"

typedef enum				e_sign_type{
	UNSIGNED = 0x0,
	SIGNED = 0x1,
}							t_sign_type;

enum						e_flags{
	FL_MINUS = 0x1,
	FL_PLUS = 0x2,
	FL_SPACE = 0x4,
	FL_HASH = 0x8,
	FL_ZERO = 0x10,
	FL_PREC = 0x20,
	FL_WIDTH = 0x40,
	FL_NULL = 0x80,
	FL_POINT = 0x100,
	FL_ERR = 0x200,
};

typedef enum				e_len_modifs{
	LEN_MOD_HH,
	LEN_MOD_H,
	LEN_MOD_L,
	LEN_MOD_LL,
	LEN_MOD_CAP_L,
	LEN_MOD_J,
	LEN_MOD_Z,
	LEN_MOD_NA
}							t_len_modifs;

typedef struct				s_format{
	char					type_char;
	int						is_neg;
	int						prec;
	int						width;
	t_uint					flags;
	t_len_modifs			len_mod;
	t_sign_type				is_signed;
}							t_format;

typedef struct				s_worker{
	char					*final_str;
	char					buf[BUF_SIZE];
	int						count;
	int						i;
}							t_worker;

typedef struct				s_result{
	char					*str;
	int						count;
}							t_result;

typedef struct				s_buf{
	char					buf[BUF_SIZE];
	int						i;
}							t_buf;

int							ft_printf(const char *fmt, ...);
int							ft_dprintf(int d, const char *fmt, ...);
int							ft_asprintf(char **str, const char *fmt, ...);
int							ft_vdprintf(int d, const char *fmt, va_list args);
int							ft_vasprintf(char **str, const char *fmt,
																va_list args);

#endif

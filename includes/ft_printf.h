/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:18:38 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/25 19:54:05 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>

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
	t_uchar					u_char;
	t_ushort				u_short;
	t_uint					u_int;
	t_ulint					u_lint;
	t_ullint				u_llint;
}							t_ints;

/*
** Union to store the different double types
*/
typedef union				u_dbls{
	t_float					fl;
	t_double				dbl;
	t_ldouble				ldbl;
}							t_dbls;

# define BUF_SIZE			4096

# define TYPES             "dcsouxXfeEgGaApi%"
# define SIGNED_TYPES      "di"
# define FLAGS             "-+ 0#"
# define LEN_MODIFS        "hlLjz"
# define NUM_TYPES         "douxXi"
# define TYPE_PREFIX       "oxX"

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

typedef enum		e_sign_type{
	UNSIGNED = 0x0,
	SIGNED = 0x1,
}					t_sign_type;

enum				e_flags{
	FL_MINUS = 0x1,
	FL_PLUS = 0x2,
	FL_SPACE = 0x4,
	FL_HASH = 0x8,
	FL_ZERO = 0x10,
	FL_PREC = 0x20,
	FL_WIDTH = 0x40,
	FL_NULL = 0x80,
	FL_ERR = 0x100,
};

typedef enum		e_len_modifs{
	LEN_MOD_HH,
	LEN_MOD_H,
	LEN_MOD_L,
	LEN_MOD_LL,
	LEN_MOD_CAP_L,
	LEN_MOD_J,
	LEN_MOD_Z,
	LEN_MOD_NA
}					t_len_modifs;

typedef struct		s_format{
	int				width;
	int				prec;
	t_uint			flags;
	t_len_modifs	len_mod;
	char 			type_char;
	t_sign_type     is_signed;
	int				is_neg;
}					t_format;

typedef struct		s_result{
	char			*str;
	int				count;
}					t_result;

int					ft_printf(const char *fmt, ...);
int					ft_dprintf(int d, const char *fmt, ...);
int					ft_asprintf(char **str, const char *fmt, ...);
int					ft_vdprintf(int d, const char *fmt, va_list args);
int					ft_vasprintf(char **str, const char *fmt, va_list args);

/*
** INTEGER CONVERSION:
** minus ('-'): Left-justify the result in the field.
** plus ('+'):  For signed %d and %i conversions, print a plus sign if the value
**              is positive.
** space (' '): For signed %d and %i conversions, if the result does not start
**              with a plus or minus sign, prefix it with a space instead.
**              Flag ignored if '+' flag also supplied.
** hash ('#'):  For the '%o' conversion, forces the leading digit to be '0'
**              as if by increasing the precision.
**              For '%x' or '%X', prefixes a leading '0x' or '0X' to the
**              result.
**              Does not do anything for '%d', '%i' or '%u'.
** zero ('0'):  Pad the field with zeros instead of spaces.
**              The zeros are placed after any indication of sign or base.
**              Flag ignored if '-' flag also specified, or if a precision
**              is specified.
*/

/*
** List of the conversion specifiers expected to end a conversion specification:
**  - d, i: int converted to signed decimal notation;
**  - o, u, x, X: unsigned int converted to octal (o), unsigned decimal (u),
**    or unsigned hexadecimal (x, X);
**  - e, E: double argument rounded and converted in the style [-]d.ddde+/-dd
**          (exponential notation);
**  - f: double argument rounded and converted in the style [-]ddd.ddd
**       (fixed-point) notation;
**  - g, G: double argument converted in the style of f or e (or E for G conver-
**          sions);
**  - a, A: double argument converted to hexadecimal notation in the style
**          [-]0xh.hhhp+/-dd (0X for A conversions);
**  - c: int argument converted to an unsigned char;
**  - s: const char * argument (string) is printed;
**  - p: void * pointer argument printed in hexadecimal;
**  - %: a '%' is written, no argument is converted.
*/

#endif

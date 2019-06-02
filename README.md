# Ft_printf
The __*ft_printf*__ project at [42](https://www.42.fr/) consists in coding your own version of the libc function *printf*, which is used to perform formatted output based on a format string that specifies how to format the values of the remaining arguments.

![Printf example](https://upload.wikimedia.org/wikipedia/commons/2/2c/Printf.svg) 
*Wikimedia.org*

## Mandatory part
Your *ft_printf* function should:
- handle the `%c`, `%s` and `%p` conversion types;
- handle the `%d`, `%i`, `%u`, `%o`, `%x`, `%X` conversion types with the modifiers `hh`, `h`, `l`, `ll`;
- handle the `%f` conversion type with the modifiers `l` and `L`;
- handle `%%`;
- handle the following flags: `#`, `0`, `-`, `+` and `space`;
- handle the field *width* as well as the *precision*.

## Bonus part

As part as the bonus part of the project, my *ft_printf* function includes the following:
- conversion types `%D`, `%U`, `%O`;
- modifiers `j` (*intmax_t*), and `z` (*size_t*);
- conversion types `%e`, `%E`, `%g` and `%G`, with the modifiers `l` and `L`;
- `*` wildcard;
- custom conversion type `%b` to print a number in binary notation;
- custom modifier to modify the typography of the output with the following format: `ft_printf("this is a {color} colored text {reset}."` The text portion between `{color}` and `{reset}` will be printed with the appropriate color. Also works with background colors and some typographic styles like *bold* and *underline*.

As part of this project, I followed the global code structure of the original printf function. Thus, I coded two other functions:
- `ft_dprintf` which allows to print on a specific file descriptor;
- `ft_asprintf` which allows to store the output in a string. 

## Key learnings

- **Variadic functions** and the use of `va_list`;
- **Floating-point arithmetic**, **IEEE 754** (single precision, double precision, extended precision);
- Display of floating point numbers (from LDBL_MIN to LDBL_MAX) based on the *Dragon4* algorithm;
- Creation of a bigint function library to work with large integers quantities including the following operations: *addition, substraction, multiplication, comparison, shift left, power of 10.*

## References

- Printing floating-point numbers by *Ryan Juckett*: http://www.ryanjuckett.com/programming/printing-floating-point-numbers/
- IEEE Standard for floating-point numbers by *V Rajaraman*: https://www.ias.ac.in/article/fulltext/reso/021/01/0011-0030
- GNU libc manual: https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html#Formatted-Output

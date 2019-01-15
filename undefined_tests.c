/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undefined_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:10:24 by jkettani          #+#    #+#             */
/*   Updated: 2019/01/10 12:11:47 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	print_h2("=> Invalid format:");
	test_int("[UNDEFINED] Int greater than 127 with length modifier h -- 298 = 42 + 256", "%hc", "298", 298);
	test_int("[UNDEFINED] Int greater than 127 with length modifier z -- 298 = 42 + 256", "%hc", "298", 298);
	test_int("[UNDEFINED] Int greater than 127 with length modifier L -- 298 = 42 + 256", "%hc", "298", 298);
	test_int("[UNDEFINED] Int greater than 127 with length modifier ll -- 298 = 42 + 256", "%llc", "298", 298);
	test_int("[UNDEFINED] Small letter ASCII char 'a' with length modifier hh", "%hhc", "'a'", 'a');
	test_int("[UNDEFINED] Small letter ASCII char 'a' with length modifier h", "%hc", "'a'", 'a');
	test_int("[UNDEFINED] Small letter ASCII char 'a' with length modifier L", "%hc", "'a'", 'a');
	test_int("[UNDEFINED] Small letter ASCII char 'a' with precision", "%+.2c", "'a'", 'a');
	test_int("[UNDEFINED] Small letter ASCII char 'a' with + sign", "%+c", "'a'", 'a');
	test_int("[UNDEFINED] Small letter ASCII char 'a' with # sign", "%#c", "'a'", 'a');
	test_int("[INVALID] Small letter ASCII char 'a' with left blank spaces and spaces between number and type", "%10   c", "'a'", 'a');
	test_int("[UNDEFINED] Small letter ASCII char 'a' with left blank spaces and spaces between \% and number", "%    10c", "'a'", 'a');
	test_int("[INVALID] Small letter ASCII char 'a' with left blank spaces and spaces before and after number", "%    10     c", "'a'", 'a');
	test_int("[UNDEFINED] Small letter ASCII char 'a' with left zeros", "%010c", "'a'", 'a');
	test_int("[INVALID] Small letter ASCII char 'a' with left zeros and space before and after", "%   0   10   c", "'a'", 'a');
	test_int("[UNDEFINED] Small letter ASCII char 'a' with left zeros -- multiple zeros in argument", "%00010c", "'a'", 'a');
	test_int("[UNDEFINED] Small letter ASCII char 'a' with left zeros -- multiple zeros in argument and + sign after zeros", "%000+10c", "'a'", 'a');
	test_int("[UNDEFINED] Small letter ASCII char 'a' with left zeros -- multiple zeros in argument and + sign before zeros", "%+00010c", "'a'", 'a');
	test_int("[UNDEFINED] Small letter ASCII char 'a' with left zeros -- multiple zeros in argument and + sign between zeros", "%0+0010c", "'a'", 'a');
	test_int("[UNDEFINED] Small letter ASCII char 'a' with right zeroes spaces -- minus sign before zero", "%-010c", "'a'", 'a');
	test_int("[UNDEFINED] Small letter ASCII char 'a' with right zeroes spaces -- minus sign after zero", "%0-10c", "'a'", 'a');
	test_int("[UNDEFINED] Small letter ASCII char 'a' with right zeroes spaces -- multiple zeros after - sign", "%-00010c", "'a'", 'a');
	test_int("[UNDEFINED] Small letter ASCII char 'a' with right zeroes spaces -- minus sign between zeros", "%00-010c", "'a'", 'a');


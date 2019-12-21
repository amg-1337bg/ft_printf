/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:34:10 by bamghoug          #+#    #+#             */
/*   Updated: 2019/12/20 17:59:47 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int			g_empty_char;
int			g_length;
void		check_arg(char **arg, int *neg_or_not, int zero);
void		check_prec_arg(char **param, int *neg_or_not, int *index_of);
void		check_arg_p(char *arg, int *star_val, int *neg_or_not);
int			check_precision(const char *s, int *i);
void		hm_ze_sp(int min, int max, int zero, int neg_or_not);
void		minimal_width_pos(char *arg, int i, int zero, int neg_or_not);
void		minimal_width_neg(char *arg, int i, int zero, int neg_or_not);
void		min_width(const char *s, va_list arg, int *i, int index_of);
void		ignor_mi_sp(const char *s, int *i, int *star_neg);
int			get_flag_value(const char *s, int *i, va_list arg, int *zero);
char		*which_con(char c, va_list arg, int *index_of);
void		change_glob_int(char c, char *param, int *j, int i_o_a);
char		*con_s(void *arg);
char		*con_d_i(void *arg);
char		*con_c(void *arg);
char		*con_p(void *arg);
char		*which_con(char c, va_list arg, int *index_of);
char		*con_u(void *arg);
char		*con_x_upper(void *arg);
char		*con_x(void *arg);
char		*ft_charjoin_r(char *s1, char c);
char		*ft_charjoin_l(char c, char *s1);
char		*detect_perc(const char *s, int i);
void		ignor_mi_sp(const char *s, int *i, int *star_neg);
int			get_flag_value(const char *s, int *i, va_list arg, int *zero);
void		fill_print(char **param, int neg_or_not);
int			get_flag_value_p(const char *s, int *i, va_list arg);
char		*greater_op(char *param, int j, int *index_of, int neg_or_not);
char		*lower_op(char *param, int j, int *index_of, int neg_or_not);
char		space_zer(char *arg, int star_val, int zero, int j);
char		*min_wid_prec_op(int length, int star_val, char zero_or_space);
void		min_precision(const char *s, va_list arg, int *i, int index_of);
char		*min_prec(const char *s, va_list arg, int *i, int *index_of);
void		modify_res(char **res, char *arg, int neg_or_not,
		int arg_neg_or_not);
char		*prec_min(char *arg, int star_val, int zero, int j);
void		flag_founded(const char *s, va_list arg, int *i);
void		conv_occur(const char *s, va_list arg, int *i);
void		modify_res(char **res, char *arg, int neg_or_not,
		int arg_neg_or_not);
int			ft_atoi(const char *str);
char		*ft_inverse(char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
char		*ft_itoa_u(unsigned int n);
void		*ft_memcpy(void *dst, const	void *src, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_printf(const char *s, ...);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_itoa(int n);
void		ft_putchar_fd(const char *c, int fd, int len);
void		print_empty_char(int neg_or_not);
void		check_ar(char **arg, int zero, int j, int *arg_neg_or_not);
void		looking_for_conv(const char *s, va_list ap);
#endif

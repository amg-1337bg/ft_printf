/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:59:45 by bamghoug          #+#    #+#             */
/*   Updated: 2019/11/21 10:59:53 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *con_s(void *arg)
{
    char *res;

    if (arg != NULL)
        res = (char *)arg;
    else
        res = "(null)";
    return (res);
}
char    *con_d_i(void *arg)
{
    char *res;
    int i;

    i = (int)arg;
    res = ft_itoa(i);
    return (res);
}
char    *con_c(void *arg)
{
    char *res;
    char c;

    res = malloc (2 * sizeof(char));
    c = (int)arg;
    res[0] = c;
    res [1] = '\0';
    return(res);
}

char    *ft_charjoin_r(char *s1, char c)
{
    char *res;
    size_t i;

    i = ft_strlen(s1);
    if ((res = (char *)malloc(i + 2)) == NULL)
        return (NULL);
    i = 0;
    while(s1[i] != '\0')
    {
        res[i] = s1[i];
        i++;
    }
    res[i] = c;
    res[++i] = '\0';
    return (res);
}

char    *ft_charjoin_l(char c, char *s1)
{
    char *res;
    int i;
    int j;

    i = ft_strlen(s1);
    j = i + 1;
    if ((res = (char *)malloc(i + 2)) == NULL)
        return (NULL);
    while(i >= 0)
    {
        res[j] = s1[i];
        i--;
        j--;
    }
    res[j] = c;
    return (res);
}

char    *con_p(void *arg)
{
    char *res;
    unsigned long dec;
    int j;
    int i;
    char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    i = 0;
    res = ft_strdup("");
    dec = (unsigned long)arg;
    if (dec == 0)
        res = "0";
    while (dec > 0)
    {
        j = dec % 16;
        dec = dec / 16;
        res = ft_charjoin_r(res, arr[j]);
    }
    res = ft_strjoin(res, "x0");
    res = ft_inverse(res);
    return (res);
}

char    *con_u(void *arg)
{
    char *res;
    unsigned int i;

    i = (unsigned int)arg;
    res = ft_itoa_u(i);
    return (res);
}

char    *con_X(void *arg)
{
    char *res;
    char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    unsigned long i;
    int j;

    i = (unsigned long)arg;
    if (i == 0)
        return (ft_strdup("0"));
    res = ft_strdup("");
    while (i > 0)
    {
        j = i % 16;
        i = i / 16;
        res = ft_charjoin_r(res, arr[j]);
    }
    res = ft_inverse(res);
    return (res);
}
char    *con_x(void *arg)
{
    char *res;
    char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned long i;
    int j;

    i = (unsigned long)arg;
    if (i == 0)
        return (ft_strdup("0"));
    res = ft_strdup("");
    while (i > 0)
    {
        j = i % 16;
        i = i / 16;
        res = ft_charjoin_r(res, arr[j]);
    }
    res = ft_inverse(res);
    return (res);
}
char    *which_con(char c, va_list arg, int *index_of)
{
    char *res;

    res = ft_strdup("");
    if (c == 's')
        res = con_s(va_arg(arg, void*));
    else if (c == 'd' || c == 'i')
    {
        *index_of = 1;
        res = con_d_i(va_arg(arg, void*));
    }
    else if (c == 'c')
		res = con_c(va_arg(arg, void*));
	else if (c == 'p')
		res = con_p(va_arg(arg, void*));
	else if (c == 'u')
		res = con_u(va_arg(arg, void*));
	else if (c == 'x')
		res = con_x(va_arg(arg, void*));
	else if (c == 'X')
		res = con_X(va_arg(arg, void*));
    return (res);
}

char *detect_perc(const char *s, int i)
{
    char *res;
    int index;
    int j;

    index = i;
    j = 0;
    while (s[i] != '%' && s[i] != '\0')
        i++;
    res = (char *)malloc(i + 1);
    while (s[index] != '%' && s[index] != '\0')
    {
        res[j] = s[index];
        j++;
        index++; 
    }
    res[j] = '\0';
    return(res);
}

char    *minimal_width_pos(char *arg, int i, int zero, int neg_or_not)
{
    char *spaces;
    char *res;
    int index;
    int j;
    char space_or_zero;

    res = ft_strdup("");
    j = ft_strlen(arg);
    space_or_zero = ' ';
    index = 0;
    if (j > i)
    {
        if (neg_or_not == 1)
            arg = ft_strjoin("-", arg);
        return (arg);
    }
    spaces = (char*)malloc(((i - j) + 1) * sizeof(char));
    if (zero == 1)
        space_or_zero = '0';
    if (neg_or_not == 1)
        i--;
    while(j < i)
    {
        spaces[index] = space_or_zero;
        index++;
        j++;
    }
    spaces[index] = '\0';
    res = ft_strjoin(spaces, arg);
    free (spaces);
    if (neg_or_not == 1)
        res = ft_strjoin("-", res);
    return (res);
}

char    *minimal_width_neg(char *arg, int i, int zero, int neg_or_not)
{
    char *spaces;
    char *res;
    int index;
    int j;
    char space_or_zero;

    res = ft_strdup("");
    j = ft_strlen(arg);
    space_or_zero = ' ';
    index = 0;
    i = i * -1;
    if (j > i)
    {
        if (neg_or_not == 1)
            arg = ft_strjoin("-", arg);
        return (arg);
    }
    spaces = (char*)malloc(((i - j) + 1) * sizeof(char));
    if (zero == 1)
        space_or_zero = '0';
    if (neg_or_not == 1)
        i--;
    while(j < i)
    {
        spaces[index] = space_or_zero;
        index++;
        j++;
    }
    spaces[index] = '\0';
    res = ft_strjoin(arg, spaces);
    free (spaces);
    if (neg_or_not == 1)
        res = ft_strjoin("-", res);
    return (res);
}

char    *min_width(const char *s,char *print, va_list arg, int *i)
{
    int j;
    int zero;
    int neg_or_not;
    int i_o_a;
    char *param;

    zero = 0;
    neg_or_not = 0;
    i_o_a = *i;
    while (ft_isalpha(s[i_o_a]) == 0)
        i_o_a++;
    if ((j = ft_atoi(&s[*i])) != 0 || s[*i] == 0 || s[*i] == '-' || s[*i] == '*' || s[*i] == ' ')
    {
        if (s[*i] == '*')
            j = va_arg(arg, int);
        if (s[*i] == '0')
            zero = 1;
        param = which_con(s[i_o_a], arg, &i_o_a);
        if (param[0] == '-')
        {
            neg_or_not = 1;
            param = ft_substr(param, 1, ft_strlen(param));
        }
        if (j > 0)
            print = ft_strjoin(print, minimal_width_pos(param, j, zero, neg_or_not));
        else if (j < 0)
            print = ft_strjoin(print, minimal_width_neg(param, j, zero, neg_or_not));
        else
            print = ft_strjoin(print, param);
    }
    return (print);
}

/*char    *precision(const char *s, char *print, char *arg, int *i, int *last, int index_of)
{
    char *res;
    size_t j;
    size_t length;
    int index;

    j = ft_atoi(&s[*i + 1]);
    index = 0;
    print = ft_strjoin(print, detect_perc(s, *last));
    length = ft_strlen(arg);
    if (j > length)
    {
        if (index_of == 0)
            print = ft_strjoin(print, arg);
        if (index_of == 1)
        {
            res = malloc((j - length + 1) * sizeof(char));
            while (length < j)
            {
                res[index] = '0';
                index++;
                length++;
            }
            res[index] = '\0';
            arg = ft_strjoin(res, arg);
            free (res);
            print = ft_strjoin(print, arg);
        }
    }
    else if (j <= length)
    {
        if (index_of == 0)
        {
            res = ft_substr(arg, 0, j);
            print = ft_strjoin(print, res);
        }
        if (index_of == 1)
            print = ft_strjoin(print, arg);
    }
    return (print);
}
*/
char    *min_prec(const char *s, va_list arg, int *i, int index_of)
{
    char *res;
    char *param;
    int j;
    int atoi_prec;
    int length;
    int neg_or_not;
    int i_o_a;

    res = ft_strdup("");
    neg_or_not = 0;
    j = 0;
    i_o_a = *i;
    while (ft_isalpha(s[i_o_a]) == 0 && s[i_o_a] != '\0')
        i_o_a++;
    atoi_prec = *i + 1;
    if (ft_atoi(&s[atoi_prec]) != 0 || s[atoi_prec] == '0' || s[atoi_prec] == '*')
    {
        if (s[atoi_prec] == '*')
            j = va_arg(arg, int);
        else
            j = ft_atoi(&s[atoi_prec]);
    }
    param = which_con(s[i_o_a], arg, &index_of);
    if (param[0] == '-')
    {
        neg_or_not = 1;
        param = ft_substr(param, 1, ft_strlen(param));
    }
    length = ft_strlen(param);
    if (j >= length)
    {
        if (index_of == 1)
        {
            while ((j - length) > 0)
            {
                param = ft_charjoin_l('0', param);
                length++;
            }
        }
        res = ft_strjoin(res, param);
        if (neg_or_not == 1)
            res = ft_charjoin_l('-', res);
    }
    else if (j < length && ft_memcmp(param, "0", length) != 0)
    {
        if (index_of == 1 || j < 0)
            res = param;
        else
            res = ft_substr(param, 0, j);
        if (neg_or_not == 1)
            res = ft_charjoin_l('-', res);
    }
    return (res);
}

char    *prec_min(char *arg, int star_val)
{
    int j;
    char *res;
    int length;
    int index;
    int neg_or_not;

    index = 0;
    neg_or_not = 0;
    res = ft_strdup("");
    length = ft_strlen(arg);
    j = star_val;
    if (j < 0)
    {
        neg_or_not = 1;
        j *= -1;
    }
    if (j <= length)
        return (arg);
    else if (j > length)
    {
        if (((res = (char*)malloc((j - length + 1) * sizeof(char))) == NULL))
            return (res);
        while (length < j)
        {
            res[index] = ' ';
            index++;
            length++;
        }
        res[index] = '\0';
        if (neg_or_not == 0)
            res = ft_strjoin(res, arg);
        else
            res = ft_strjoin(arg, res);
        
    }
    return (res);
}

/*char    *min_precision_operation(const char *s, va_list arg, int *i, int j, int index_of)
{
    char *res;

    if (j == *i)
        res = min_prec(s, arg, &j, index_of);
    else
    {
        res = min_prec(s, arg, &j, index_of);
        res = prec_min(s, res, i);
    }
    return (res);
}*/

char    *min_precision(const char *s, char *print, va_list arg, int *i, int index_of)
{
    int j;
    int star_val;
    char *con_ret;

    if (s[*i] == '*')
        star_val = va_arg(arg, int);
    else if (ft_atoi(&s[*i]) != 0 || s[*i] == '0')
        star_val = ft_atoi(&s[*i]);
    j = *i;
    while (s[j] != '.' && s[j] != '\0')
        j++;
    if (j == *i)
        con_ret = min_prec(s, arg, &j, index_of);
    else
    {
        con_ret = min_prec(s, arg, &j, index_of);
        con_ret = prec_min(con_ret, star_val);
    }
    //con_ret = min_precision_operation(s, arg, i, j, index_of);
    print = ft_strjoin(print, con_ret);
    return (print);
}

int     check_precision(const char *s, int *i)
{
    int j;

    j = *i;
    while (ft_isalpha(s[j]) == 0 && s[j] != '\0')
    {
        if (s[j] == '.')
            return (1);
        j++;   
    }
    return (0);
}

char    *flag_founded(const char *s, char *print, va_list arg, int *i)
{
    int j;
    //char *param;
    int index_of;
    //int star_val;

    (*i)++;
    j = *i;
    index_of = 0;
    while (ft_isalpha(s[j]) == 0)
        j++;
    //param = which_con(s[j], arg, &index_of);
    if (check_precision(s, i) == 1)
        print = min_precision(s, print, arg, i, index_of);
    else if (ft_atoi(&s[*i]) != 0 || s[*i] == 0 || s[*i] == '-' || s[*i] == '*' || s[*i] == ' ')
        print = min_width(s, print, arg, i);
    //else if (s[*i] == '.')
    //   print = precision(s, print, param, i, last, index_of);
    *i = j + 1;
    return (print);
}

char    *conv_occur(const char *s, char *print, va_list arg, int *i)
{
    static int last;
    int index_of;

    index_of = 0;
    print = ft_strjoin(print, detect_perc(s, last));
    if (ft_isalpha(s[*i + 1]) == 1 || s[*i + 1] == '%')
    {
        if (s[*i + 1] == '%')
            print = ft_charjoin_r(print, '%');
        print = ft_strjoin(print, which_con(s[*i + 1], arg, &index_of));
        last = *i + 2;
        *i = *i + 2;
    }
    else
    {
        print = flag_founded(s, print, arg, i);
        last = *i;
    }
    return(print);
}

char    *fake_perc(const char *s, char *print, int *i)
{
    void *fake;
    char *sp;

    fake = NULL;
    sp = conv_occur(s, print, fake, i);
    return (sp);
}

int ft_printf(const char *s, ...)
{
    va_list ap;
    va_start (ap, s);
    int i;
    int last;
    char *print;

    i = 0;
    last = 0;
    print = ft_strdup("");
    while (s[i] != '\0')
    {
        if (s[i] == '%')
        {
            if (s[i + 1] == '%')
                print = fake_perc(s, print, &i);
            else
                print = conv_occur(s, print ,ap, &i);
            last = i;
        }
        else
            i++;
    }
    print = ft_strjoin(print, ft_substr(s, last,i));
    i = ft_strlen(print);
    ft_putstr_fd(print, 1);
    free (print);
    return(i);
}

int main()
{
    //char *s = NULL;
    char *e = " i'm fine thanks";
    ft_printf("hello% s thanks to you\n", e);
    printf("hello% s thanks to you", e);
    return (0);
}
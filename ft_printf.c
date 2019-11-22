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

#include <stdarg.h>
#include "libft.h"
#include <stdio.h>
char    *con_s(void *arg)
{
    char *res;

    res = (char *)arg;
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

    c = (char)arg;
    res = &c;
    return(res);
}

char    *ft_charjoin(char *s1, char c)
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
    while (dec > 0)
    {
        j = dec % 16;
        dec = dec / 16;
        res = ft_charjoin(res, arr[j]);
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
    res = ft_itoa(i);
    return (res);
}

char    *con_X(void *arg)
{
    char *res;
    char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int i;
    int j;

    i = (int)arg;
    res = ft_strdup("");
    while (i > 0)
    {
        j = i % 16;
        i = i / 16;
        res = ft_charjoin(res, arr[j]);
    }
    res = ft_inverse(res);
    return (res);
}
char    *con_x(void *arg)
{
    char *res;
    char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    int i;
    int j;

    i = (int)arg;
    res = ft_strdup("");
    while (i > 0)
    {
        j = i % 16;
        i = i / 16;
        res = ft_charjoin(res, arr[j]);
    }
    res = ft_inverse(res);
    return (res);
}
char    *which_con(char c, void *arg)
{
    char *res;
    char per = '%';

    res = ft_strdup("");
    if (c == 's')
        res = con_s(arg);
    else if (c == 'd' || c == 'i')
        res = con_d_i(arg);
    else if (c == 'c')
		res = con_c(arg);
	else if (c == 'p')
		res = con_p(arg);
	else if (c == 'u')
		res = con_u(arg);
	else if (c == 'x')
		res = con_x(arg);
	else if (c == 'X')
		res = con_X(arg);
    /*else if (c == '%')
        res = &per;*/
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
/*char    *flag_found(const char *, char *print, void *arg, int i)
{

}*/
char    *conv_occur(const char *s, char *print, void *arg, int i)
{
    static int last;

    if (ft_isalpha(s[i + 1]) == 1 || s[i + 1] == '%')
    {
        if (s[i + 1] == '%')
            print = ft_strjoin(print, ft_substr(s, last, (i + 1)));
        else
            print = ft_strjoin(print, detect_perc(s, last));
        print = ft_strjoin(print, which_con(s[i + 1], arg));
        last = i + 2;
    }
    else
    {

    }
    return(print);
}

char    *fake_perc(const char *s, char *print, int i)
{
    void *fake;
    char *sp;

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
                print = fake_perc(s, print, i);
            else
                print = conv_occur(s, print ,va_arg(ap, void*), i);
            i += 2;
            last = i;
        }
        else
            i++;
    }
    print = ft_strjoin(print, ft_substr(s, last,i));
    ft_putstr_fd(print, 1);
    free (print);
    return(0);
}
int main()
{
    char *s = "how are you";
    char *e = " i'm fine thanks";
    //ft_printf("how friends %%%s hello %s\n", s, e);
    printf("how friends %%%s hello %s", s, e);
    return (0);
}
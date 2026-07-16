/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:31:43 by lpedroso          #+#    #+#             */
/*   Updated: 2026/07/16 15:13:40 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int ft_is_delimiter(char argv)
{
    return( argv == ' ' || argv == '\t');
}
int main (int argc, char **argv)
{
    int i = 0;
    int j;

    if(argc != 2)
        return (write(1, "\n", 1), 0);

    while (argv[1][i])
        i++;
    if (i == 0)
        return (write(1, "\n", 1), 0);
    j = i;
    i--;
    while ( (ft_is_delimiter(argv[1][i]) == 1 ) && i >= 0)
        i--;
    while ( (ft_is_delimiter(argv[1][i]) == 0 ) && i >= 0)
        i--;
    i++;
    while ( (ft_is_delimiter(argv[1][i]) == 0 ) && i < j)
    {
        write(1,&argv[1][i], 1);
        i++;
    }
    return (write(1, "\n", 1), 0);
}

/*
int main_pointer(int argc, char **argv)
{
    char *s;

    if (argc != 2)
        return (write(1, "\n", 1), 0);

    s = argv[1];

    while (*s)                 // move to end of string
        s++;

    s--;                       // last real char

    while (s >= argv[1] && ft_is_delim(*s))
        s--;                   // skip trailing delimiters

    while (s >= argv[1] && !ft_is_delim(*s))
        s--;                   // skip last word backwards

    s++;                       // now at start of last word

    while (*s && !ft_is_delim(*s))
        write(1, s++, 1);      // print last word

    return (write(1, "\n", 1), 0);
}
*/
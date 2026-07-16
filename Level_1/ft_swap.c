/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:35:58 by lpedroso          #+#    #+#             */
/*   Updated: 2026/07/15 16:44:10 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

#include <stdio.h>

int main(void)
{
    int *ptr_a;
    int *ptr_b;
    int a = 0;
    int b = 1;

    ptr_a = &a;
    ptr_b = &b;

    printf("antes a:%d b:%d\n", a, b);
    ft_swap(ptr_a, ptr_b);
    printf("depois a:%d b:%d\n", a, b);

    return 0;
    
}
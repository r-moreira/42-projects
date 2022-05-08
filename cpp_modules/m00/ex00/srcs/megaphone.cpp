/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:24:04 by romoreir          #+#    #+#             */
/*   Updated: 2022/05/08 19:24:04 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	ft_strlen(const char *s)
{
    int	i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int	ft_toupper(int c)
{
    if (c >= 97 && c <= 122)
        c -= 32;
    return (c);
}

void megaphone(int argc, char *argv[])
{
    int	i;
    int j;
    int	len;

    i = 0;
    while (++i < argc)
    {
        j = -1;
        len = ft_strlen(argv[i]);
        while (++j < len)
            std::cout << (char)ft_toupper(argv[i][j]);
        std::cout << " ";
    }
    std::cout << std::endl;
}

int main (int argc, char *argv[])
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
        megaphone(argc, argv);
    return 0;
}

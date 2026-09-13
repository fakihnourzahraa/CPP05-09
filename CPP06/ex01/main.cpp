/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 13:03:17 by nour              #+#    #+#             */
/*   Updated: 2026/09/13 13:04:09 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "Serializer.hpp"
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout <<"INVALID"<<std::endl;
        return 0;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
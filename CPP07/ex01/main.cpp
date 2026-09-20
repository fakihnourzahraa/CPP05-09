/* ************************************************************************** */
/*	                                                                         */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 14:11:08 by nour              #+#    #+#             */
/*   Updated: 2026/09/20 17:48:20 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "iter.hpp"

void addition(std::string &a)
{
    a = "hi";
}
template <typename T> void printValue(T val) {
    std::cout << val << std::endl;
}

int main(void)
{
	std::string a[] = {"Hiii", "uhm", "UHHH"};
	::iter(a, 2, addition);
	for (int i = 0 ;i < 3; i++)
	{
		std::cout << a[i] <<std::endl;
	}
	std::cout << std::endl;
	::iter(a, 3, printValue<const std::string&>);
	std::cout << std::endl;
	::iter(a, 3, printValue< std::string&>);
	return 0;
}
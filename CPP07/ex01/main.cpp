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

void alterstr(std::string &a)
{
    a = "hi";
}
template <typename T> void printValue(T val) {
    std::cout << val << std::endl;
}
void addition(int &a)
{
    a = a + 1;
}

int main(void)
{
	std::string a[] = {"test", "test", "test"};
	::iter(a, 2, alterstr);
	::iter(a, 3, printValue<const std::string&>);

	int b[] = {1,2,3};
	::iter(b, 3, addition);
	::iter(b, 3, printValue<const int&>);

	const std::string ca[] = {"const", "stays", "same"};
	::iter(ca, 3, printValue<const std::string&>);
	// ::iter(ca, 3, alterstr);

	const int cb[] = {10, 20, 30};
	::iter(cb, 3, printValue<const int&>);
	// ::iter(cb, 3, addition);

	return 0;
}
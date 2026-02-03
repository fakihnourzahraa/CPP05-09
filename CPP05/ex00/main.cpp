/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:47:46 by nfakih            #+#    #+#             */
/*   Updated: 2026/02/03 15:30:02 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main()
{
    try
	{
		Bureaucrat obj("A", 151);
        obj.incrementBureau();
		std::cout << obj << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
    try
	{
		Bureaucrat obj("B", 150);
        obj.decrementBureau();
		std::cout << obj << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    try
	{
		Bureaucrat obj("C", 140);
		std::cout << "Before: " << obj << std::endl;
        obj.incrementBureau();
		std::cout << "After: " << obj << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    return (0);
}

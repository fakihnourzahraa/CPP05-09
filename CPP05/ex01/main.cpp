/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:47:46 by nfakih            #+#    #+#             */
/*   Updated: 2026/01/30 17:01:09 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int main()
{
    try
    {
        Form form1("Tax Form", 50, 25);
        std::cout << form1 << std::endl;
        
        Form form2("Permission Slip", 100, 75);
        std::cout << form2 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Form invalidForm1("Bad Form", 0, 50);
        std::cout << invalidForm1 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Form invalidForm2("Bad Form", 50, 151);
        std::cout << invalidForm2 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        Bureaucrat bob("Bob", 45);
        Form form("Contract", 50, 25);
        
        std::cout << bob << std::endl;
        std::cout << form << std::endl;
        
        bob.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        Bureaucrat intern("Intern", 100);
        Form importantForm("Top Secret Document", 25, 10);
        
        std::cout << intern << std::endl;
        std::cout << importantForm << std::endl;
        
        intern.signForm(importantForm);
        std::cout << importantForm << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
	try
    {
        Form petition("Petition", 75, 50);
        Bureaucrat alice("Alice", 50);
        Bureaucrat charlie("Charlie", 80);
        
        std::cout << petition << std::endl;
        
        alice.signForm(petition);
        std::cout << petition << std::endl;

        charlie.signForm(petition);
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
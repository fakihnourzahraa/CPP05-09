/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:47:46 by nfakih            #+#    #+#             */
/*   Updated: 2026/01/19 14:53:24 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test 1: Creating valid forms ===" << std::endl;
    try
    {
        Form form1("Tax Form", 50, 25);
        std::cout << form1 << std::endl;
        
        Form form2("Permission Slip", 100, 75);
        std::cout << form2 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 2: Creating forms with invalid grades ===" << std::endl;
    try
    {
        Form invalidForm1("Bad Form", 0, 50);
        std::cout << invalidForm1 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Form invalidForm2("Bad Form", 50, 151);
        std::cout << invalidForm2 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 3: Bureaucrat signing forms (successful) ===" << std::endl;
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

    std::cout << "=== Test 4: Bureaucrat trying to sign form (grade too low) ===" << std::endl;
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

    std::cout << "=== Test 5: Multiple bureaucrats signing the same form ===" << std::endl;
    try
    {
        Form petition("Petition", 75, 50);
        Bureaucrat alice("Alice", 50);
        Bureaucrat charlie("Charlie", 80);
        
        std::cout << petition << std::endl;
        
        alice.signForm(petition);
        std::cout << petition << std::endl;
        
        // Try to sign already signed form
        charlie.signForm(petition);
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 6: Bureaucrat with exact required grade ===" << std::endl;
    try
    {
        Bureaucrat exactGrade("ExactGrade", 50);
        Form form("Application", 50, 25);
        
        std::cout << exactGrade << std::endl;
        std::cout << form << std::endl;
        
        exactGrade.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 7: Bureaucrat with grade just too low ===" << std::endl;
    try
    {
        Bureaucrat almostThere("AlmostThere", 51);
        Form strictForm("Strict Form", 50, 25);
        
        std::cout << almostThere << std::endl;
        std::cout << strictForm << std::endl;
        
        almostThere.signForm(strictForm);
        std::cout << strictForm << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 8: High-level bureaucrat signing form ===" << std::endl;
    try
    {
        Bureaucrat ceo("CEO", 1);
        Form anyForm("Any Form", 150, 150);
        
        std::cout << ceo << std::endl;
        std::cout << anyForm << std::endl;
        
        ceo.signForm(anyForm);
        std::cout << anyForm << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
	

    return 0;
}
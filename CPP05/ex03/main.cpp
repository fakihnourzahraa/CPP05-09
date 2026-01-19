/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:47:46 by nfakih            #+#    #+#             */
/*   Updated: 2026/01/19 23:34:52 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));

    std::cout << "\n========== Test 1: Intern creates ShrubberyCreationForm ==========\n" << std::endl;
    {
        Intern someRandomIntern;
        AForm* form = NULL;
        
        try
        {
            form = someRandomIntern.makeForm("ShrubberyCreationForm", "home");
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        if (form)
        {
            Bureaucrat bob("Bob", 137);
            std::cout << *form << std::endl;
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }
    }

    std::cout << "\n========== Test 2: Intern creates RobotomyRequestForm ==========\n" << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf = NULL;
        
        try
        {
            rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        if (rrf)
        {
            Bureaucrat charlie("Charlie", 40);
            std::cout << *rrf << std::endl;
            charlie.signForm(*rrf);
            charlie.executeForm(*rrf);
            charlie.executeForm(*rrf);
            charlie.executeForm(*rrf);
            delete rrf;
        }
    }

    std::cout << "\n========== Test 3: Intern creates PresidentialPardonForm ==========\n" << std::endl;
    {
        Intern someRandomIntern;
        AForm* ppf = NULL;
        
        try
        {
            ppf = someRandomIntern.makeForm("PresidentialPardonForm", "Arthur Dent");
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        if (ppf)
        {
            Bureaucrat president("President", 1);
            std::cout << *ppf << std::endl;
            president.signForm(*ppf);
            president.executeForm(*ppf);
            delete ppf;
        }
    }

    std::cout << "\n========== Test 4: Intern tries to create non-existent form ==========\n" << std::endl;
    {
        Intern someRandomIntern;
        AForm* form = NULL;
        
        try
        {
            form = someRandomIntern.makeForm("CoffeeMakingForm", "office");
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        if (form)
            delete form;
    }

    std::cout << "\n========== Test 5: Intern creates multiple forms ==========\n" << std::endl;
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        AForm* forms[3] = {NULL, NULL, NULL};
        
        try
        {
            forms[0] = intern.makeForm("ShrubberyCreationForm", "garden");
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        try
        {
            forms[1] = intern.makeForm("RobotomyRequestForm", "Marvin");
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        try
        {
            forms[2] = intern.makeForm("PresidentialPardonForm", "Zaphod");
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        std::cout << "\n--- Processing all forms ---" << std::endl;
        for (int i = 0; i < 3; i++)
        {
            if (forms[i])
            {
                std::cout << "\nForm " << i + 1 << ":" << std::endl;
                std::cout << *forms[i] << std::endl;
                boss.signForm(*forms[i]);
                boss.executeForm(*forms[i]);
            }
        }
        
        std::cout << "\n--- Cleaning up forms ---" << std::endl;
        for (int i = 0; i < 3; i++)
        {
            if (forms[i])
                delete forms[i];
        }
    }

    std::cout << "\n========== Test 6: Case sensitivity test ==========\n" << std::endl;
    {
        Intern intern;
        AForm* form = NULL;
        
        std::cout << "Trying with lowercase:" << std::endl;
        try
        {
            form = intern.makeForm("robotomyrequestform", "test");
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        if (form)
            delete form;
        
        form = NULL;
        std::cout << "\nTrying with correct case:" << std::endl;
        try
        {
            form = intern.makeForm("RobotomyRequestForm", "test");
            if (form)
            {
                std::cout << "Form created successfully!" << std::endl;
            }
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        if (form)
            delete form;
    }

    std::cout << "\n========== Test 7: Typo in form name ==========\n" << std::endl;
    {
        Intern intern;
        AForm* form = NULL;
        
        try
        {
            form = intern.makeForm("ShruberyCreationForm", "test");  // Typo
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        if (form)
            delete form;
    }

    std::cout << "\n========== Test 8: Full workflow with intern ==========\n" << std::endl;
    {
        Intern intern;
        Bureaucrat lowLevel("LowLevel", 150);
        Bureaucrat midLevel("MidLevel", 50);
        Bureaucrat highLevel("HighLevel", 1);
        AForm* form = NULL;
        
        try
        {
            form = intern.makeForm("PresidentialPardonForm", "Criminal");
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        if (form)
        {
            std::cout << "\n" << *form << std::endl;
            
            std::cout << "\nLow level bureaucrat tries:" << std::endl;
            lowLevel.signForm(*form);
            
            std::cout << "\nMid level bureaucrat tries:" << std::endl;
            midLevel.signForm(*form);
            
            std::cout << "\nHigh level bureaucrat tries:" << std::endl;
            highLevel.signForm(*form);
            
            std::cout << "\nMid level tries to execute:" << std::endl;
            midLevel.executeForm(*form);
            
            std::cout << "\nHigh level executes:" << std::endl;
            highLevel.executeForm(*form);
            
            delete form;
        }
    }

    std::cout << "\n========== Test 9: The subject's example ==========\n" << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf = NULL;
        
        try
        {
            rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        if (rrf)
        {
            Bureaucrat executor("Executor", 1);
            executor.signForm(*rrf);
            executor.executeForm(*rrf);
            delete rrf;
        }
    }

    std::cout << "\n========== End of tests ==========\n" << std::endl;

    return 0;
}
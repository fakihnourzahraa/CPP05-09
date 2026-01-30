/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:47:46 by nfakih            #+#    #+#             */
/*   Updated: 2026/01/30 18:29:01 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"


int main()
{

    std::cout << "\nIntern creates ShrubberyCreationForm\n" << std::endl;
    {
        Intern someRandomIntern;
        AForm* form = NULL;
        
        try
        {
            form = someRandomIntern.makeForm("ShrubberyCreationForm", "home");
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
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

    std::cout << "\nIntern creates RobotomyRequestForm\n" << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf = NULL;
        
        try
        {
            rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
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

    std::cout << "\nIntern creates PresidentialPardonForm\n" << std::endl;
    {
        Intern someRandomIntern;
        AForm* ppf = NULL;
        
        try
        {
            ppf = someRandomIntern.makeForm("PresidentialPardonForm", "Arthur Dent");
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
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

    std::cout << "\nIntern tries to create non-existent form\n" << std::endl;
    {
        Intern someRandomIntern;
        AForm* form = NULL;
        
        try
        {
            form = someRandomIntern.makeForm("CoffeeMakingForm", "office");
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        
        if (form)
            delete form;
    }

    std::cout << "\nThe subject's example\n" << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf = NULL;
        
        try
        {
            rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        
        if (rrf)
        {
            Bureaucrat executor("Executor", 1);
            executor.signForm(*rrf);
            executor.executeForm(*rrf);
            delete rrf;
        }
    }

	return (0);
}
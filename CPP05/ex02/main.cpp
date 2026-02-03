/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:47:46 by nfakih            #+#    #+#             */
/*   Updated: 2026/02/03 16:01:39 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "\nShrubberyCreationForm\n" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 137);
        ShrubberyCreationForm shrubForm("home");
        
        std::cout << alice << std::endl;
        std::cout << shrubForm << std::endl;

        alice.signForm(shrubForm);
        std::cout << shrubForm << std::endl;

        alice.executeForm(shrubForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;
    try
    {
        Bureaucrat bob("Bob", 145);
        ShrubberyCreationForm shrubForm("garden");
        
        std::cout << bob << std::endl;
        std::cout << shrubForm << std::endl;
        
        bob.signForm(shrubForm);

        bob.executeForm(shrubForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;
    try
    {
        Bureaucrat ceo("CEO", 1);
        ShrubberyCreationForm shrubForm("office");
        
        std::cout << ceo << std::endl;
        std::cout << shrubForm << std::endl;
        
        ceo.executeForm(shrubForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;
    std::cout << "\nRobotomyRequestForm \n" << std::endl;
    try
    {
        Bureaucrat charlie("Charlie", 40);
        RobotomyRequestForm robotForm("Bender");
        
        std::cout << charlie << std::endl;
        std::cout << robotForm << std::endl;
        
        charlie.signForm(robotForm);
        charlie.executeForm(robotForm);
        
        std::cout << "\nTrying robotomy multiple times:" << std::endl;
        charlie.executeForm(robotForm);
        charlie.executeForm(robotForm);
        charlie.executeForm(robotForm);
        charlie.executeForm(robotForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;
    try
    {
        Bureaucrat intern("Intern", 72);
        RobotomyRequestForm robotForm("Target");
        
        std::cout << intern << std::endl;
        std::cout << robotForm << std::endl;

        intern.signForm(robotForm);
        
        intern.executeForm(robotForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;
    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardonForm("Arthur Dent");
        
        std::cout << president << std::endl;
        std::cout << pardonForm << std::endl;

        president.signForm(pardonForm);
        president.executeForm(pardonForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;
    try
    {
        Bureaucrat manager("Manager", 30);
        PresidentialPardonForm pardonForm("Ford Prefect");
        
        std::cout << manager << std::endl;
        std::cout << pardonForm << std::endl;

        manager.signForm(pardonForm);

        manager.executeForm(pardonForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;
    try
    {
        Bureaucrat signer("Signer", 5);
        Bureaucrat executor("Executor", 10);
        PresidentialPardonForm pardonForm("Zaphod Beeblebrox");
        
        std::cout << signer << std::endl;
        std::cout << executor << std::endl;
        std::cout << pardonForm << std::endl;
        
        signer.signForm(pardonForm);
        
        executor.executeForm(pardonForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;
    try
    {
        Bureaucrat b1("B1", 145);
        Bureaucrat b2("B2", 137);
        ShrubberyCreationForm form("edge");
        
        b1.signForm(form);
        b2.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;
    return 0;
}
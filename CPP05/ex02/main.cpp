/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:47:46 by nfakih            #+#    #+#             */
/*   Updated: 2026/01/19 16:11:48 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Seed random number generator for RobotomyRequestForm
    srand(time(NULL));

    std::cout << "\n========== Test 1: ShrubberyCreationForm ==========\n" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 137);
        ShrubberyCreationForm shrubForm("home");
        
        std::cout << alice << std::endl;
        std::cout << shrubForm << std::endl;
        
        // Sign the form
        alice.signForm(shrubForm);
        std::cout << shrubForm << std::endl;
        
        // Execute the form
        alice.executeForm(shrubForm);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== Test 2: ShrubberyCreationForm - Grade too low to execute ==========\n" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 145);
        ShrubberyCreationForm shrubForm("garden");
        
        std::cout << bob << std::endl;
        std::cout << shrubForm << std::endl;
        
        // Sign the form (Bob can sign: grade 145, required 145)
        bob.signForm(shrubForm);
        
        // Try to execute (Bob cannot execute: grade 145, required 137)
        bob.executeForm(shrubForm);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== Test 3: ShrubberyCreationForm - Not signed ==========\n" << std::endl;
    try
    {
        Bureaucrat ceo("CEO", 1);
        ShrubberyCreationForm shrubForm("office");
        
        std::cout << ceo << std::endl;
        std::cout << shrubForm << std::endl;
        
        // Try to execute without signing
        ceo.executeForm(shrubForm);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== Test 4: RobotomyRequestForm ==========\n" << std::endl;
    try
    {
        Bureaucrat charlie("Charlie", 40);
        RobotomyRequestForm robotForm("Bender");
        
        std::cout << charlie << std::endl;
        std::cout << robotForm << std::endl;
        
        // Sign and execute
        charlie.signForm(robotForm);
        charlie.executeForm(robotForm);
        
        // Try multiple times to see 50% success rate
        std::cout << "\nTrying robotomy multiple times:" << std::endl;
        charlie.executeForm(robotForm);
        charlie.executeForm(robotForm);
        charlie.executeForm(robotForm);
        charlie.executeForm(robotForm);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== Test 5: RobotomyRequestForm - Grade too low ==========\n" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 72);
        RobotomyRequestForm robotForm("Target");
        
        std::cout << intern << std::endl;
        std::cout << robotForm << std::endl;
        
        // Sign (can sign: grade 72, required 72)
        intern.signForm(robotForm);
        
        // Try to execute (cannot execute: grade 72, required 45)
        intern.executeForm(robotForm);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== Test 6: PresidentialPardonForm ==========\n" << std::endl;
    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardonForm("Arthur Dent");
        
        std::cout << president << std::endl;
        std::cout << pardonForm << std::endl;
        
        // Sign and execute
        president.signForm(pardonForm);
        president.executeForm(pardonForm);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== Test 7: PresidentialPardonForm - Grade too low to sign ==========\n" << std::endl;
    try
    {
        Bureaucrat manager("Manager", 30);
        PresidentialPardonForm pardonForm("Ford Prefect");
        
        std::cout << manager << std::endl;
        std::cout << pardonForm << std::endl;
        
        // Try to sign (cannot: grade 30, required 25)
        manager.signForm(pardonForm);
        
        // Won't reach here
        manager.executeForm(pardonForm);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== Test 8: PresidentialPardonForm - Grade too low to execute ==========\n" << std::endl;
    try
    {
        Bureaucrat signer("Signer", 5);
        Bureaucrat executor("Executor", 10);
        PresidentialPardonForm pardonForm("Zaphod Beeblebrox");
        
        std::cout << signer << std::endl;
        std::cout << executor << std::endl;
        std::cout << pardonForm << std::endl;
        
        // Sign with high-grade bureaucrat
        signer.signForm(pardonForm);
        
        // Try to execute with lower-grade bureaucrat (cannot: grade 10, required 5)
        executor.executeForm(pardonForm);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== Test 9: All three forms with one bureaucrat ==========\n" << std::endl;
    try
    {
        Bureaucrat superBureaucrat("SuperBureaucrat", 1);
        
        ShrubberyCreationForm shrub("park");
        RobotomyRequestForm robot("Marvin");
        PresidentialPardonForm pardon("Trillian");
        
        std::cout << superBureaucrat << std::endl;
        
        // Sign all forms
        std::cout << "\n--- Signing all forms ---" << std::endl;
        superBureaucrat.signForm(shrub);
        superBureaucrat.signForm(robot);
        superBureaucrat.signForm(pardon);
        
        // Execute all forms
        std::cout << "\n--- Executing all forms ---" << std::endl;
        superBureaucrat.executeForm(shrub);
        superBureaucrat.executeForm(robot);
        superBureaucrat.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== Test 10: Edge cases - Exact grade requirements ==========\n" << std::endl;
    try
    {
        // ShrubberyCreationForm: sign 145, exec 137
        Bureaucrat b1("B1", 145);
        Bureaucrat b2("B2", 137);
        ShrubberyCreationForm form("edge");
        
        b1.signForm(form);      // Should work (exact grade)
        b2.executeForm(form);   // Should work (exact grade)
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== End of tests ==========\n" << std::endl;

    return 0;
}
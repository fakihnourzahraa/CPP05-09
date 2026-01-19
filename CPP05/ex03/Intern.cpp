/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:08:12 by nour              #+#    #+#             */
/*   Updated: 2026/01/19 16:31:29 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << " Intern destructor called" << std::endl;
}

const char* Intern::FormNonExistentException::what() const throw()
{
    return "Intern::FormNonExistentException";
}

Intern::Intern(const Intern &other)
{
    (void) other;
    std::cout << "Intern copy constructor is called" <<std::endl;
}

Intern  &Intern::operator=(const Intern &other)
{
    std::cout << "Intern copy assignement constructor is called" << std::endl;
    if (this == &other)
    {
        return *this;
    }
    return (*this);
}
AForm *Intern::makeForm(std::string first, std::string second)
{
    if (first == "ShrubberyCreationForm")
        return new ShrubberyCreationForm(second);
    else if (first == "PresidentialPardonForm")
        return new PresidentialPardonForm(second);
    else if (first == "RobotomyRequestForm")
        return new RobotomyRequestForm(second);
    else
        throw FormNonExistentException();
}

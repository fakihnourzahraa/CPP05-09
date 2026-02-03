/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:08:12 by nour              #+#    #+#             */
/*   Updated: 2026/02/03 16:20:27 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
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
	std::string levels[] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm"};
	int c;
	c = -1;
	for (int i = 0; i < 3; i++)
	{
		if (levels[i] == first)
			c = i;
	}
	switch (c)
	{
		case 0:
			return new ShrubberyCreationForm(second);
		case 1:
			return new PresidentialPardonForm(second);
		case 2:
			return new RobotomyRequestForm(second);
		default:
			throw FormNonExistentException();
	}
}

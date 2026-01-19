/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:44:07 by nour              #+#    #+#             */
/*   Updated: 2026/01/19 16:13:53 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << this->getName() << " PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string t) : AForm("PresidentialPardonForm", 25, 5)
{
    this->target = t;
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    this->target = other.target;
    std::cout << "PresidentialPardonForm copy constructor is called" <<std::endl;
}

PresidentialPardonForm  &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "PresidentialPardonForm copy assignement constructor is called" << std::endl;
    if (this == &other)
    {
        return *this;
    }
    AForm::operator=(other);
    this->target = other.target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (this->getSigned() == false)
        throw NotSignedException();
    if (executor.getGrade() > this->getEx())
        throw AForm::GradeTooLowException();

    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
const char* PresidentialPardonForm::NotSignedException::what() const throw()
{
    return "PresidentialPardonForm::NotSignedException";
}
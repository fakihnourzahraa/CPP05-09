/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:44:07 by nour              #+#    #+#             */
/*   Updated: 2026/01/19 16:10:37 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << this->getName() << " RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string t) : AForm("RobotomyRequestForm", 72, 45)
{
    this->target = t;
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    this->target = other.target;
    std::cout << "RobotomyRequestForm copy constructor is called" <<std::endl;
}

RobotomyRequestForm  &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm copy assignement constructor is called" << std::endl;
    if (this == &other)
    {
        return *this;
    }
    AForm::operator=(other);
    this->target = other.target;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (this->getSigned() == false)
        throw NotSignedException();
    if (executor.getGrade() > this->getEx())
        throw AForm::GradeTooLowException();

    srand(time(NULL));
    if (rand() % 2 == 0)
    {
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed on " << this->target << "!" << std::endl;
    }
}
const char* RobotomyRequestForm::NotSignedException::what() const throw()
{
    return "RobotomyRequestForm::NotSignedExcpetion";
}
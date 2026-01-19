/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:47:28 by nour              #+#    #+#             */
/*   Updated: 2026/01/19 16:10:18 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), sign_grade(75), ex_grade(75)
{
    this->is_signed = false;
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << name << "AForm destructor called" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() 
{
    return "AForm::GradeTooHighException";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm::GradeTooLowException";
}

AForm::AForm(std::string n, int sign, int ex) : name(n), sign_grade(sign), ex_grade(ex)
{
    if (sign > 150 || ex > 150)
        throw GradeTooLowException();
    if (sign < 1 || ex < 1)
        throw GradeTooHighException();
    this->is_signed = false;
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : name(other.name), sign_grade(other.sign_grade), ex_grade(other.ex_grade)
{
    this->is_signed = other.is_signed;
    std::cout << "AForm copy constructor is called" <<std::endl;
}

AForm  &AForm::operator=(const AForm &other)
{
    std::cout << "AForm copy assignement constructor is called" << std::endl;
    if (this == &other)
    {
        return *this;
    }
    return (*this);
}

std::string const AForm::getName() const
{
    return (this->name);
}
int AForm::getEx() const
{
    return (this->ex_grade);
}

int AForm::getSign() const
{
    return (this->sign_grade);
}

bool AForm::getSigned() const
{
    return (this->is_signed);
}

std::ostream    &operator<<(std::ostream &out, const AForm &AForm)
{
    out << AForm.getName() << ", AForm signed?  " << AForm.getSigned() << ", AForm to sign " << AForm.getSign() << ", AForm to execute " << AForm.getEx() << std::endl;
    return (out);
}

int    AForm::beSigned(Bureaucrat *b)
{
    if (b->getGrade() <= this->sign_grade)
    {
        this->is_signed = true;
        return (1);
    }
    else
        throw GradeTooLowException();
    return (0);
}
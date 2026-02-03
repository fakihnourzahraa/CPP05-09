/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:47:28 by nour              #+#    #+#             */
/*   Updated: 2026/02/03 15:49:31 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"
# include "Bureaucrat.hpp"

Form::Form() : name("Default"), sign_grade(75), ex_grade(75)
{
    this->is_signed = false;
	std::cout << "Default Form constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << name << " form destructor called" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw() 
{
    return "Form::GradeTooHighException";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form::GradeTooLowException";
}

Form::Form(std::string n, int sign, int ex) : name(n), sign_grade(sign), ex_grade(ex)
{
    if (sign > 150 || ex > 150)
        throw GradeTooLowException();
    if (sign < 1 || ex < 1)
        throw GradeTooHighException();
    this->is_signed = false;
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &other) : name(other.name), sign_grade(other.sign_grade), ex_grade(other.ex_grade)
{
    this->is_signed = other.is_signed;
    std::cout << "Form copy constructor is called" <<std::endl;
}

Form  &Form::operator=(const Form &other)
{
    std::cout << "Form copy assignement constructor is called" << std::endl;
    if (this == &other)
    {
        return *this;
    }
	this->is_signed = other.is_signed;
    return (*this);
}

std::string const Form::getName() const
{
    return (this->name);
}
int Form::getEx() const
{
    return (this->ex_grade);
}

int Form::getSign() const
{
    return (this->sign_grade);
}

bool Form::getSigned() const
{
    return (this->is_signed);
}

std::ostream    &operator<<(std::ostream &out, const Form &Form)
{
	std::string h = "false";
	
	if (Form.getSigned())
		h = "true";
    out << Form.getName() << ", Form signed?  " << h << ", Form to sign " << Form.getSign() << ", Form to execute " << Form.getEx() << std::endl;
    return (out);
}

int    Form::beSigned(Bureaucrat *b)
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
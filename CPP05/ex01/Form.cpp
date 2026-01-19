/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:47:28 by nour              #+#    #+#             */
/*   Updated: 2026/01/14 12:13:02 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"


Form::Form() : name("Default"), to_sign(75), to_ex(75)
{
    this->sign = false;
	std::cout << "Default Form constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << name << "Form destructor called" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw() 
{
    return "Form::GradeTooHighException";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form::GradeTooLowException";
}

Form::Form(std::string n, int sign, int ex) : name(n), to_sign(sign), to_ex(ex)
{
    if (sign > 150 || ex > 150)
        throw GradeTooLowException();
    if (sign < 1 || ex < 1)
        throw GradeTooHighException();
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &other) : name(other.name), to_sign(other.to_sign), to_ex(other.to_ex)
{
    std::cout << "Form copy constructor is called" <<std::endl;
}

Form  &Form::operator=(const Form &other)
{
    std::cout << "Form copy assignement constructor is called" << std::endl;
    if (this == &other)
    {
        return *this;
    }
    return (*this);
}

std::string const Form::getName() const
{
    return (this->name);
}
const int Form::getEx() const
{
    return (this->to_ex);
}

const int Form::getSign() const
{
    return (this->to_sign);
}

bool Form::getSigned() const
{
    return (this->to_sign);
}

std::ostream    &operator<<(std::ostream &out, const Form &Form)
{
    out << Form.getName() << ", Form signed?  " << Form.getSigned() << ", Form to sign " << Form.getSign() << " , Form to execute" << Form.getEx() << std::endl;
    return (out);
}

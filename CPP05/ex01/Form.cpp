/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:47:28 by nour              #+#    #+#             */
/*   Updated: 2026/01/13 21:50:00 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form() : name("Default")
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

Form::Form(std::string n, int g) : name(n)
{
        if (g > 150)
            throw GradeTooLowException();
        if (g < 1)
            throw GradeTooHighException();
        
        std::cout << "Form constructor called" << std::endl;

}

Form::Form(const Form &other) : name(other.name)
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
    this->grade = other.grade;
    return (*this);
}

std::string const Form::getName() const
{
    return (this->name);
}
int Form::getGrade() const
{
    return (this->grade);
}

std::ostream    &operator<<(std::ostream &out, const Form &Form)
{
    out << Form.getName() << ", Form grade  " << Form.getGrade() << std::endl;
    return (out);
}
void	Form::incrementBureau()
{
    if (this->grade > 1)
        this->grade = this->grade - 1;
    else
        std::cout << "Grade too high" << std::endl;
}
void	Form::decrementBureau()
{
    if (this->grade < 150)
        this->grade = this->grade + 1;
    else
        std::cout << "Grade too low" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:08:12 by nour              #+#    #+#             */
/*   Updated: 2026/02/03 16:02:47 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default")
{
    this->grade = 75;
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << name << " Bureaucrat destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Bureaucrat::GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat::GradeTooLowException";
}

Bureaucrat::Bureaucrat(std::string n, int g) : name(n)
{
        if (g > 150)
            throw GradeTooLowException();
        if (g < 1)
            throw GradeTooHighException();
        this->grade = g;
        std::cout << "Bureaucrat constructor called" << std::endl;

}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
    std::cout << "Bureaucrat copy constructor is called" <<std::endl;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat copy assignement constructor is called" << std::endl;
    if (this == &other)
    {
        return *this;
    }
    this->grade = other.grade;
    return (*this);
}

std::string const Bureaucrat::getName() const
{
    return (this->name);
}
int Bureaucrat::getGrade() const
{
    return (this->grade);
}

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return (out);
}
void	Bureaucrat::incrementBureau()
{
    if (this->grade > 1)
        this->grade = this->grade - 1;
    else
        throw GradeTooHighException();
}
void	Bureaucrat::decrementBureau()
{
    if (this->grade < 150)
        this->grade = this->grade + 1;
	else
		throw GradeTooLowException();
}
void    Bureaucrat::signForm(AForm &f)
{
    try
    {
        f.beSigned(this);
        std:: cout << this->name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << this->name << " couldn't sign " << f.getName() << e.what() << std::endl;
    }
}
void	Bureaucrat::executeForm(AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl; 
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn't execute " << form.getName() << " " << e.what() << std::endl;
	}
	
}
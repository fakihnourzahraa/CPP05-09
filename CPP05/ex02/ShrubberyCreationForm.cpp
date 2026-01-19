/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:05:59 by nour              #+#    #+#             */
/*   Updated: 2026/01/19 16:01:59 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"
   
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = "default_target";
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << this->getName() << " shrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = t;
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    this->target = other.target;
    std::cout << "ShrubberyCreationForm copy constructor is called" <<std::endl;
}

ShrubberyCreationForm  &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "ShrubberyCreationForm copy assignement constructor is called" << std::endl;
    if (this == &other)
    {
        return *this;
    }
    AForm::operator=(other);
    this->target = other.target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (this->getSigned() == false)
        throw NotSignedException();
    if (executor.getGrade() > this->getEx())
        throw AForm::GradeTooLowException();
    
    std::string filename = this->target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open())
    {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }

    file << "                                                         ." << std::endl;
    file << "                                              .         ;  " << std::endl;
    file << "                 .              .              ;%     ;;" << std::endl;
    file << "                   ,           ,                :;%  %;" << std::endl;
    file << "                    :         ;                   :;%;'     .," << std::endl;
    file << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
    file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
    file << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
    file << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    file << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    file << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
    file << "                      `@%:.  :;%.         ;@@%;'" << std::endl;
    file << "                        `@%.  `;@%.      ;@@%;" << std::endl;
    file << "                          `@%%. `@%%    ;@@%;" << std::endl;
    file << "                            ;@%. :@%%  %@@%;" << std::endl;
    file << "                              %@bd%%%bd%%:;" << std::endl;
    file << "                                #@%%%%%:;;" << std::endl;
    file << "                                %@@%%%::;" << std::endl;
    file << "                                %@@@@%(o);  . '" << std::endl;
    file << "                                %@@@o%;:(.,'  " << std::endl;
    file << "                            `.. %@@@o%::;   " << std::endl;
    file << "                               `)@@@o%::;   " << std::endl;
    file << "                                %@@(o)::;    " << std::endl;
    file << "                               .%@@@@%::;    " << std::endl;
    file << "                               ;%@@@@%::;.   " << std::endl;
    file << "                              ;%@@@@%%:;;;." << std::endl;
    file << "                          ...;%@@@@@%%:;;;;,.." << std::endl;

    file.close();
}
const char* ShrubberyCreationForm::NotSignedException::what() const throw()
{
    return "ShrubberyCreationForm::NotSignedExcpetion";
}
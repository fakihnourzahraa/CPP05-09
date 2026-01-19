/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:28:04 by nour              #+#    #+#             */
/*   Updated: 2026/01/19 16:29:10 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "iostream"
# include "fstream"
# include "iomanip"
# include "cstdlib"
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
    public:
	Intern();
	virtual ~Intern();
	Intern &operator=(const Intern &other);
	Intern(const Intern &other);
	AForm *makeForm(std::string first, std::string second);

	class FormNonExistentException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};


#endif
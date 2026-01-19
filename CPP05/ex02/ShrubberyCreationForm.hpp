/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:28:04 by nour              #+#    #+#             */
/*   Updated: 2026/01/19 16:01:39 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "iostream"
# include "fstream"
# include "iomanip"
# include "cstdlib"
# include "AForm.hpp"
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
	std::string target;
	
    public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	void execute(Bureaucrat const &executor) const;
	class NotSignedException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

#endif
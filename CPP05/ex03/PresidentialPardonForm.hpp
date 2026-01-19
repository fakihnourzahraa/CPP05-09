/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:28:04 by nour              #+#    #+#             */
/*   Updated: 2026/01/19 16:00:42 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "iostream"
# include "fstream"
# include "iomanip"
# include "cstdlib"
# include "cstdlib"
# include "ctime"
# include "AForm.hpp"
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
	std::string target;
	
    public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	void execute(Bureaucrat const &executor) const;
	class NotSignedException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

#endif
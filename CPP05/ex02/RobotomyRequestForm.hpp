/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:28:04 by nour              #+#    #+#             */
/*   Updated: 2026/01/19 16:01:32 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "iostream"
# include "fstream"
# include "iomanip"
# include "cstdlib"
# include "cstdlib"
# include "ctime"
# include "AForm.hpp"
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
	std::string target;
	
    public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	void execute(Bureaucrat const &executor) const;
	class NotSignedException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

#endif
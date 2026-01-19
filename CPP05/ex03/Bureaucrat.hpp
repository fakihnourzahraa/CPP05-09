/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:28:04 by nour              #+#    #+#             */
/*   Updated: 2026/01/19 16:04:12 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "iostream"
# include "fstream"
# include "iomanip"
# include "cstdlib"
# include "AForm.hpp"

class Bureaucrat
{
    private:
    std::string const	name;
	int					grade;

    public:
	Bureaucrat();
	virtual ~Bureaucrat();
	Bureaucrat(std::string n, int g);
	Bureaucrat &operator=(const Bureaucrat &other);
	Bureaucrat(const Bureaucrat &other);
	void	signForm(AForm &form);

	std::string const getName() const;
	int getGrade() const;
	void	incrementBureau();
	void	decrementBureau();
	void	executeForm(AForm &from) const;
	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
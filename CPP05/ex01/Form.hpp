/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:28:04 by nour              #+#    #+#             */
/*   Updated: 2026/01/19 14:47:59 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "iostream"
# include "fstream"
# include "iomanip"
# include "cstdlib"

class Bureaucrat;

class Form
{
    private:
    std::string const	name;
	bool				is_signed;
	const int			sign_grade;
	const int			ex_grade;

    public:
	Form();
	~Form();
	Form(std::string n, int sign, int ex);
	Form &operator=(const Form &other);
	Form(const Form &other);

	std::string const getName() const;
	bool		getSigned() const;
	int getSign() const;
	int	getEx() const;

	int		beSigned(Bureaucrat *b);
	
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

std::ostream    &operator<<(std::ostream &out, const Form &Form);

#endif
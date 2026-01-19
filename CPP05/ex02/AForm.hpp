/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:28:04 by nour              #+#    #+#             */
/*   Updated: 2026/01/19 16:05:52 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "iostream"
# include "fstream"
# include "iomanip"
# include "cstdlib"

class Bureaucrat;

class AForm
{
    private:
    std::string const	name;
	bool				is_signed;
	const int			sign_grade;
	const int			ex_grade;

    public:
	AForm();
	virtual ~AForm();
	AForm(std::string n, int sign, int ex);
	AForm &operator=(const AForm &other);
	AForm(const AForm &other);

	std::string const getName() const;
	bool		getSigned() const;
	int getSign() const;
	int	getEx() const;

	int		beSigned(Bureaucrat *b);
	virtual void execute(Bureaucrat const &executor) const = 0;
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

std::ostream    &operator<<(std::ostream &out, const AForm &AForm);

#endif
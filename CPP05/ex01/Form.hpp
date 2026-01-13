/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:28:04 by nour              #+#    #+#             */
/*   Updated: 2026/01/13 21:49:02 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "iostream"
# include "fstream"
# include "iomanip"
# include "cstdlib"

class Form
{
    private:
    std::string const	name;
	bool				sign;
	const int			to_sign;
	const int			to_ex;

    public:
	Form();
	~Form();
	Form(std::string n, int g);
	Form &operator=(const Form &other);
	Form(const Form &other);

	std::string const getName() const;
	bool		getSign() const;
	const int	to_sign() const;
	const int	to_ex() const;

	
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
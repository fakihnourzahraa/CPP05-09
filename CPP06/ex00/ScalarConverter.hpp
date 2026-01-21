/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:28:04 by nour              #+#    #+#             */
/*   Updated: 2026/01/19 16:05:52 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "iostream"
# include "fstream"
# include "iomanip"
# include "cstdlib"
#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cerrno>
#include <iomanip>
class ScalarConverter
{
    public:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &other);
	ScalarConverter(const ScalarConverter &other);
	static bool isChar(const std::string& literal);
    static void isInt(const std::string& literal);
    static void isFloat(const std::string& literal);
    static void isDouble(const std::string& literal);
    
    static void convertFromChar(const std::string& literal);
    static void convertFromInt(const std::string& literal);
    static void convertFromFloat(const std::string& literal);
    static void convertFromDouble(const std::string& literal);
    static void convertPseudoLiteral(const std::string& literal);

	static void convert(const std::string &a);
};

#endif
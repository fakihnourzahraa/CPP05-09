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
struct conv
{
    std::string literal = "";
    bool error = false;
    char c = '\0';
    int i = 0;
    float f = 0;
    double d = 0;
    std::string s = "";
};
class ScalarConverter
{
    private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &other);
	ScalarConverter(const ScalarConverter &other);
    static bool  ScalarConverter::isChar(conv a);
    static void isInt(conv a);
    static void isFloat(conv a);
    static void isDouble(conv a);
    static conv lToStruct(const std::string& literal);
    static void convertFromChar(conv a);
    static void convertFromInt(conv a);
    static void convertFromFloat(conv a);
    static void convertFromDouble(conv a);
    static void convertPseudoLiteral(conv a);

    public:
	static void convert(const std::string &a);
};

#endif
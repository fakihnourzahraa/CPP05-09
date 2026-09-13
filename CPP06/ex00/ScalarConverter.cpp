/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:47:28 by nour              #+#    #+#             */
/*   Updated: 2026/09/13 12:57:05 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
{
	std::cout << "Default ScalarConverter constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}


ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
    std::cout << "ScalarConverter copy constructor is called" <<std::endl;
}

ScalarConverter  &ScalarConverter::operator=(const ScalarConverter &other)
{
    std::cout << "ScalarConverter copy assignement constructor is called" << std::endl;
    if (this == &other)
    {
        return *this;
    }
    return (*this);
}

void  ScalarConverter::isChar(conv a)
{
    if (a.literal[1] >= 32 && a.literal[1] <= 126)
    {
        char c = a.literal[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
    }
    else
    {
        std::cout << "invalid usage"<< std::endl;
    }
}

void ScalarConverter::isInt(conv a)
{

    int i = 0;
    if (a.literal[0] == '+' || a.literal[0] == '-')
        i++;
    if (i == 1 && !isdigit(a.literal[1]))
    {
        std::cout << "Invalid Usage" << std::endl;
        return ;
    }    
    for (int j = i; j < static_cast<int>(a.literal.length()); j++)
    {
        if (!isdigit(a.literal[j]))
        {
            std::cout << "Invalid Usage" << std::endl;
            return ;
        }
    }
    convertFromInt(a);
}

void ScalarConverter::isFloat(conv a)
{

    if (a.literal[a.literal.length() - 1] != 'f')
    {
        isDouble(a);
        return ;
    }
    bool ans = true;
    std::string rawNum = a.literal.substr(0, a.literal.length() - 1);
    int i = 0;
    int dot = 0;
    
    if (a.literal[0] == '+' || a.literal[0] == '-')
        i++;
    if (i == 1 && !isdigit(a.literal[1]))
    {
        std::cout << "Invalid Usage" << std::endl;
        return ;
    }
    
    for (int j = i; j < static_cast<float>(rawNum.length()); j++)
    {
        if (rawNum[j] == '.')
        {
            if (dot)
                dot++;
        }
        else if (!isdigit(rawNum[j]))
            ans = false;
    }
    if (ans == true && (dot == 1 || dot == 0))
        convertFromFloat(a);
    else
        std::cout << "Invalid Usage" << std::endl;
}

void ScalarConverter::isDouble(conv a)
{

    bool ans = true;
    
    int i = 0;
    int dot = 0;
    if (a.literal.find('.') == static_cast<long unsigned int>(-1))
    {
        isInt(a);
        return ;
    }
    if (a.literal[0] == '+' || a.literal[0] == '-')
        i++;
    if (i == 1 && !isdigit(a.literal[1]))
    {
        std::cout << "Invalid Usage" << std::endl;
        return ;
    }

    for (int j = i; j < static_cast<float>(a.literal.length()); j++)
    {
        if (a.literal[j] == '.')
        {
            if (dot)
                dot++;
        }
        else if (!isdigit(a.literal[j]))
            ans = false;
    }
    if (ans == true && dot <= 1)
        convertFromDouble(a);
    else
        std::cout << "Invalid Usage" << std::endl;
}

void ScalarConverter::convertFromInt(conv a)
{
    errno = 0;
    char* end;
    long value = strtol(a.literal.c_str(), &end, 10);
    
    if (errno == ERANGE || value > INT_MAX || value < INT_MIN)
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    
    int intValue = static_cast<int>(value);
    
    if (intValue < 0 || intValue > 127 || intValue < 32 || intValue == 127)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
    
    std::cout << "int: " << intValue << std::endl;
    
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(intValue) << "f" << std::endl;
    
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(intValue) << std::endl;
}

void ScalarConverter::convertFromFloat(conv a)
{

    std::string withoutF = a.literal.substr(0, a.literal.length() - 1);
    float val = static_cast<float>(atof(withoutF.c_str()));

    if (val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (val < 32 || val == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
    
    if (val > INT_MAX || val < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << val << "f" << std::endl;
    
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
}

void ScalarConverter::convertFromDouble(conv a)
{
    double val = atof(a.literal.c_str());
    
    if (val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (val < 32 || val == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
    
    if (val > INT_MAX || val < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
    
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
    
    std::cout << "double: " << std::fixed << std::setprecision(1) << val << std::endl;
}

void ScalarConverter::convertPseudoLiteral(conv a)
{ 

    if (a.literal == "nanf" || a.literal == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (a.literal == "+inff" || a.literal == "+inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (a.literal == "-inff" || a.literal == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}
conv ScalarConverter::lToStruct(const std::string& literal)
{

    int length = literal.length();
    conv a;
    a.literal = literal;
    if (length == 3 && literal[0] == '\'' && literal[2] == '\'')
        isChar(a);
    else if (literal == "nan" || literal == "nanf" ||literal == "+inf" || literal == "+inff" ||
        literal == "-inf" || literal == "-inff")
            convertPseudoLiteral(a);
    else if ((literal[0] >= '0' && literal[0] <= '9') || (literal[0] == '-' || literal[0] == '+'))
        isFloat(a);
    else
    {
        std::cout << "Invalid Input" <<std::endl;
        a.error = true;     
    }
    return a;
}
void ScalarConverter::convert(const std::string& literal)
{
    if (literal.empty())
    {
        std::cout << "Invalid Input" <<std::endl;
        // std::cout << "Char: impossible" << std::endl;
        // std::cout << "Int: impossible" << std::endl;
        // std::cout << "Float: impossible" << std::endl;
        // std::cout << "Double: impossible" << std::endl;
        return ;
    }
    conv data = lToStruct(literal);
}
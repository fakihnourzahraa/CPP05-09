/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:47:28 by nour              #+#    #+#             */
/*   Updated: 2026/01/20 18:32:39 by nour             ###   ########.fr       */
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

bool  ScalarConverter::isChar(const std::string& literal)
{
    bool ans = true;
    if (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff")
            convertPseudoLiteral(literal);
    else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        convertFromChar(literal);
    else
    {
        ans = false;
        std::cout << "Char Impossible" << std::endl;
    }
    return (ans);
}
//need to fix this


void ScalarConverter::isInt(const std::string& literal)
{
    bool ans = true;

    int i = 0;
    if (literal[0] == '+' || literal[0] == '-')
        i++;
    if (i == 1 && !isdigit(literal[1]))
    {
        std::cout << "Int: impossible" << std::endl;
        return ;
    }    
    for (int j = i; j < literal.length(); j++)
    {
        if (!isdigit(literal[j]))
        {
            std::cout << "Int: impossible" << std::endl;
            return ;
        }
    }
        convertFromInt(literal);
}


void ScalarConverter::isFloat(const std::string& literal)
{
    bool ans = true;
    if (literal.empty() || literal[literal.length() - 1] != 'f')
    {
        std::cout << "Float: impossible" << std::endl;
        return ;
    }
    
    std::string rawNum = literal.substr(0, literal.length() - 1);
    int i = 0;
    int dot = 0;
    
    if (i == 1 && !isdigit(literal[1]))
    {
        std::cout << "Float: impossible" << std::endl;
        return ;
    }
    
    for (int j = i; i < rawNum.length(); j++)
    {
        if (rawNum[i] == '.')
        {
            if (dot)
                dot++;
        }
        else if (!isdigit(rawNum[i]))
            ans = false;
    }
    if (ans == true && dot <= 1)
        convertFromFloat(literal);
    else
        std::cout << "Float: impossible" << std::endl;
}

void ScalarConverter::isDouble(const std::string& literal)
{
    bool ans = true;
    
    int i = 0;
    bool dot = false;
    
    if (literal[0] == '+' || literal[0] == '-')
        i++;
    
    if (i == 1 && !isdigit(literal[1]))
    {
        std::cout << "Double: impossible" << std::endl;
        return ;
    }
    
    for (int j = i; i < literal.length(); j++)
    {
        if (literal[i] == '.')
        {
            if (dot)
                dot++;
        }
        else if (!isdigit(literal[i]))
            ans = false;
    }
    if (ans == true && dot <= 1)
        convertFromFloat(literal);
    else
        std::cout << "Double: impossible" << std::endl;
}

void ScalarConverter::convertFromChar(const std::string& literal)
{
    char c = literal[1];
    
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertFromInt(const std::string& literal)
{
    errno = 0;
    char* end;
    long value = strtol(literal.c_str(), &end, 10);
    
    if (errno == ERANGE || value > INT_MAX || value < INT_MIN)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    
    int intValue = static_cast<int>(value);
    
    // Convert to char
    if (intValue < 0 || intValue > 127)
        std::cout << "char: impossible" << std::endl;
    else if (intValue < 32 || intValue == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
    
    std::cout << "int: " << intValue << std::endl;
    
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(intValue) << "f" << std::endl;
    
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(intValue) << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string& literal)
{
    std::string withoutF = literal.substr(0, literal.length() - 1);
    float floatValue = static_cast<float>(atof(withoutF.c_str()));
    
    // Convert to char
    if (std::isnan(floatValue) || std::isinf(floatValue) || floatValue < 0 || floatValue > 127)
        std::cout << "char: impossible" << std::endl;
    else if (floatValue < 32 || floatValue == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(floatValue) << "'" << std::endl;
    
    // Convert to int
    if (std::isnan(floatValue) || std::isinf(floatValue) || floatValue > INT_MAX || floatValue < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
    
    // Convert to float
    std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
    
    // Convert to double
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(floatValue) << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string& literal)
{
    double doubleValue = atof(literal.c_str());
    
    // Convert to char
    if (std::isnan(doubleValue) || std::isinf(doubleValue) || doubleValue < 0 || doubleValue > 127)
        std::cout << "char: impossible" << std::endl;
    else if (doubleValue < 32 || doubleValue == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(doubleValue) << "'" << std::endl;
    
    // Convert to int
    if (std::isnan(doubleValue) || std::isinf(doubleValue) || doubleValue > INT_MAX || doubleValue < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
    
    // Convert to float
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(doubleValue) << "f" << std::endl;
    
    // Convert to double
    std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
}

void ScalarConverter::convertPseudoLiteral(const std::string& literal)
{
    
    if (literal == "nanf" || literal == "nan")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "+inff" || literal == "+inf")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "-inff" || literal == "-inf")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal)
{
    if (literal.empty())
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: impossible" << std::endl;
        std::cout << "Double: impossible" << std::endl;
        return ;
    }
    if (isChar(literal))
    {
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: impossible" << std::endl;
        std::cout << "Double: impossible" << std::endl;
        return ;
    }
    isInt(literal);
    isFloat(literal);
    isDouble(literal);
}
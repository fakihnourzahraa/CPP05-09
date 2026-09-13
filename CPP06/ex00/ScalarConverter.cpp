/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:47:28 by nour              #+#    #+#             */
/*   Updated: 2026/09/13 11:30:52 by nour             ###   ########.fr       */
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

bool  ScalarConverter::isChar(conv a)
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
    bool ans = true;

    int i = 0;
    if (a.literal[0] == '+' || a.literal[0] == '-')
        i++;
    if (i == 1 && !isdigit(a.literal[1]))
    {
        std::cout << "Invalid Usage" << std::endl;
        return ;
    }    
    for (int j = i; j < a.literal.length(); j++)
    {
        if (!isdigit(a.literal[j]))
        {
            std::cout << "Invalid Usage" << std::endl;
            return ;
        }
    }
}

void ScalarConverter::isFloat(conv a)
{
    bool ans = true;
    if (a.literal[a.literal.length() - 1] != 'f')
    {
        isDouble(a);
        return ;
    }
    std::string rawNum = a.literal.substr(0, a.literal.length() - 1);
    int i = 0;
    int dot = 0;
    
    if (i == 1 && !isdigit(a.literal[1]))
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
        convertFromFloat(a);
    else
        std::cout << "Float: impossible" << std::endl;
}

void ScalarConverter::isDouble(conv a)
{
    bool ans = true;
    
    int i = 0;
    bool dot = false;
    if (!a.literal.find('.'))
    {
        isInt(a);
        return ;
    }
    if (a.literal[0] == '+' || a.literal[0] == '-')
        i++;
    
    if (i == 1 && !isdigit(a.literal[1]))
    {
        std::cout << "Double: impossible" << std::endl;
        return ;
    }
    
    for (int j = i; i < a.literal.length(); j++)
    {
        if (a.literal[i] == '.')
        {
            if (dot)
                dot++;
        }
        else if (!isdigit(a.literal[i]))
            ans = false;
    }
    if (ans == true && dot <= 1)
        convertFromFloat(a);
    else
        std::cout << "Double: impossible" << std::endl;
    isInt(a);
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

void ScalarConverter::convertFromDouble(conv a)
{
    double doubleValue = atof(a.literal.c_str());
    
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
    int length = size(literal);
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
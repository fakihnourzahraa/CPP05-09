/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:47:28 by nour              #+#    #+#             */
/*   Updated: 2026/09/14 18:08:14 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

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

void  ScalarConverter::isChar(const std::string& literal)
{
    if (literal[1] >= 32 && literal[1] <= 126)
    {
        char c = literal[1];
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

void ScalarConverter::isInt(const std::string& literal)
{

    int i = 0;
    if (literal[0] == '+' || literal[0] == '-')
        i++;
    if (i == 1 && !isdigit(literal[1]))
    {
        std::cout << "Invalid Usage" << std::endl;
        return ;
    }    
    for (int j = i; j < static_cast<int>(literal.length()); j++)
    {
        if (!isdigit(literal[j]))
        {
            std::cout << "Invalid Usage" << std::endl;
            return ;
        }
    }
    convertFromInt(literal);
}

void ScalarConverter::isFloat(const std::string& literal)
{
    if (literal[literal.length() - 1] != 'f')
    {
        isDouble(literal);
        return ;
    }
    bool ans = true;
    std::string rawNum = literal.substr(0, literal.length() - 1);
    int i = 0;
    int dot = 0;
    
    if (literal[0] == '+' || literal[0] == '-')
        i++;
    if (i == 1 && !isdigit(literal[1]))
    {
        std::cout << "Invalid Usage" << std::endl;
        return ;
    }
    
    for (int j = i; j < static_cast<float>(rawNum.length()); j++)
    {
        if (rawNum[j] == '.')
        {
                dot++;
        }
        else if (!isdigit(rawNum[j]))
            ans = false;
    }
    if (ans == true && (dot == 1 || dot == 0))
        convertFromFloat(literal);
    else
        std::cout << "Invalid Usage" << std::endl;
}

void ScalarConverter::isDouble(const std::string& literal)
{
    bool ans = true;
    
    int i = 0;
    int dot = 0;
    if (literal.find('.') == static_cast<long unsigned int>(-1))
    {
		errno = 0;
		char* end;
		long value = strtod(literal.c_str(), &end);
	
		if (! (errno == ERANGE || value > INT_MAX || value < INT_MIN)){
			isInt(literal);
			return ;
		}//just making sure its within the int limits before handing it off to int bc it has no .
	}
	
    if (literal[0] == '+' || literal[0] == '-')
        i++;
    if (i == 1 && !isdigit(literal[1]))
    {
        std::cout << "Invalid Usage" << std::endl;
        return ;
    }

    for (int j = i; j < static_cast<float>(literal.length()); j++)
    {
        if (literal[j] == '.')
        {
            if (literal[j+1] && (literal[j+1] >= '0' && literal[j+1]<= '9'))
                dot++;
            else
            {
                std::cout <<"Invalid Usage"<<std::endl;
                return ;
            }
        }
        else if (!isdigit(literal[j]))
            ans = false;
    }
    if (ans == true && dot <= 1)
        convertFromDouble(literal);
    else
        std::cout << "Invalid Usage" << std::endl;
}

void ScalarConverter::convertFromInt(const std::string& literal)
{
    errno = 0;
    char* end;
    long value = strtol(literal.c_str(), &end, 10);
    
    int intValue = static_cast<int>(value);
    
    if (intValue < 0 || intValue > 127 || intValue < 32 || intValue == 127)
        std::cout << "char: impossible" << std::endl;
    else
    {    std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;}
    
		std::cout << "int: " << intValue << std::endl;
    
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(intValue) << "f" << std::endl;
    
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(intValue) << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string& literal)
{

    std::string withoutF = literal.substr(0, literal.length() - 1);
    float val = static_cast<float>(atof(withoutF.c_str()));

    if (val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (val < 32 || val == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
    
    if (val > 2147483647.0f || val < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << val << "f" << std::endl;
    
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string& literal)
{
	errno = 0;
	char* end;
	double val = strtod(literal.c_str(), &end);

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
    if (val > FLT_MAX || val < -FLT_MAX)
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
    // CHECK ME flt decimal ./ScalarConverter 340282122.1 
    std::cout << "double: " << std::fixed << std::setprecision(1) << val << std::endl;
}

void ScalarConverter::convertPseudoLiteral(const std::string& literal)
{ 

    if (literal == "nanf" || literal == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "+inff" || literal == "+inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "-inff" || literal == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::lToStruct(const std::string& literal)
{
    int length = literal.length();

    if (length == 3 && literal[0] == '\'' && literal[2] == '\'')
        isChar(literal);
    else if (literal == "nan" || literal == "nanf" ||literal == "+inf" || literal == "+inff" ||
        literal == "-inf" || literal == "-inff")
            convertPseudoLiteral(literal);
    else if ((literal[0] >= '0' && literal[0] <= '9') || (literal[0] == '-' || literal[0] == '+'))
        isFloat(literal);
    else
        std::cout << "Invalid Input" <<std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    if (literal.empty())
    {
        std::cout << "Invalid Input" <<std::endl;
        return ;
    }
    lToStruct(literal);
}
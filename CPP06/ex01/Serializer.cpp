/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:47:28 by nour              #+#    #+#             */
/*   Updated: 2026/09/13 14:41:07 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

Serializer::Serializer() 
{
	std::cout << "Default Serializer constructor called" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;
}


Serializer::Serializer(const Serializer &other)
{
    (void)other;
    std::cout << "Serializer copy constructor is called" <<std::endl;
}

Serializer  &Serializer::operator=(const Serializer &other)
{
    std::cout << "Serializer copy assignement constructor is called" << std::endl;
    if (this == &other)
    {
        return *this;
    }
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
   return reinterpret_cast<uintptr_t>(ptr);   
}
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
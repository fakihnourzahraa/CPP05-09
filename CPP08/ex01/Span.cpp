/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:17:57 by nfakih            #+#    #+#             */
/*   Updated: 2026/10/10 12:53:06 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

template <typename T>
Span<T>::Span()
{
    this->N = 0;
	std::cout << "Default Span constructor called" << std::endl;
}

template <typename T>
Span<T>::~Span()
{
	std::cout << N << " Span destructor called" << std::endl;
}

template <typename T>
Span<T>::Span(unsigned int N)
{
    this->N = N;
    std::cout << "Span constructor called" << std::endl;

}

template <typename T>
const char* Span<T>::SpanIsFull::what() const throw() 
{
    return "Span::SpanIsFullException";
}

template <typename T>
const char* Span<T>::SpanIsEmpty::what() const throw()
{
    return "Span::SpanIsEmptyException";
}

template <typename T>
Span<T>::Span(const Span &other) : N(other.N)
{
    std::cout << "Span copy constructor is called" <<std::endl;
}

template <typename T>
Span<T>  &Span<T>::operator=(const Span<T> &other)
{
    std::cout << "Span copy assignement constructor is called" << std::endl;
    if (this == &other)
    {
        return *this;
    }
    this->N = other.N;
    return (*this);
}

template <typename T>
unsigned int Span<T>::getN() 
{
    return (this->N);
}
template <typename T>
void Span<T>::addNumber(int num)
{
	
}

template <typename T>
int Span<T>::shortestSpan()
{
	for (int i = cont.begin(); i < cont.end(); i++)
	{
		
	}

}

template <typename T>
int Span<T>::longestSpan()
{

}

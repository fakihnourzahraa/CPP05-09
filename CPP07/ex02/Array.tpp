/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 15:31:55 by nour              #+#    #+#             */
/*   Updated: 2026/09/20 11:02:09 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"
        
template <typename T> Array<T>::Array() {
    this->arr = NULL;
    this->len = 0;
    std::cout << "Default Array constructor called" << std::endl;
}

template <typename T> Array<T>::Array(unsigned int n) {
    this->len = n;
   this->arr = new T[n]();
    std::cout << "Default Array constructor called" << std::endl;
} 
template <typename T> Array<T>::~Array() {
    std::cout << "Array destructor called" << std::endl;
    delete[] this->arr;
}

template <typename T> Array<T>::Array(const Array &other)
{
    std::cout << "Array copy constructor is called" <<std::endl;
    this->arr = new T[other.len];
    this->len = other.len;
    for (int i = 0; i < len; i++)
    {
        this->arr[i] = other.arr[i];
    }
}

template <typename T> Array<T> &Array<T>::operator=(const Array &other)
{
    std::cout << "Array copy assignement constructor is called" << std::endl;
    if (this == &other)
    {
        return *this;
    }
    delete[] this->arr;
    this->arr = new T[other.len];
    this->len = other.len;
    for (int i = 0; i < len; i++)
    {
        this->arr[i] = other.arr[i];
    }
    return (*this);
}

template <typename T> T &Array<T>::operator[](int i)
{
    if (i < 0 || i >= static_cast<int>(this->len))
        throw OutOfBoundsException();
    return this->arr[i];
}

template <typename T> const T &Array<T>::operator[](int i) const
{
    if (i < 0 || i >= static_cast<int>(this->len))
        throw OutOfBoundsException();
    return this->arr[i];
}

template <typename T> int Array<T>::size(void) const
{
    return (this->len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 15:31:55 by nour              #+#    #+#             */
/*   Updated: 2026/09/19 16:11:35 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"
        
template <typename T> Array<T>::Array() {
    this->dt = T;
    this->arr = new T();
    this->len = 0;
    std::cout << "Default Array constructor called" << std::endl;
}

template <typename T> Array<T>::Array(unsigned int n) {
    this->dt = T;
    this->len = n;
    this->arr = new T(n);
    std::cout << "Default Array constructor called" << std::endl;
} 
template <typename T> Array<T>::~Array() {
    std::cout << "Array destructor called" << std::endl;
}

template <typename T> Array<T>::Array(const Array &other)
{
    std::cout << "Array copy constructor is called" <<std::endl;
    this->arr = other.arr;
    this->dt = other.dt;
    this->len = other.len;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &other)
{
    std::cout << "Array copy assignement constructor is called" << std::endl;
    if (this == &other)
    {
        return *this;
    }
    return (*this);
}

template <typename T> T Array<T>::operator[](int)
{
    if (i >= 0 || i >)
        T a = arr[i];
    else
        throw OutOfBoundsException;
}
template <typename T> int Array<T>::size(void)
{
    return (sizeof(arr)/ sizeof(arr[0]));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 13:03:11 by nour              #+#    #+#             */
/*   Updated: 2026/09/19 16:10:11 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP 
# define ARRAY_HPP
# include <string>

template <typename T>
class Array{
    private:
        T dt;
        int len;
        T *arr[];
    
    public:
        Array();
        Array(unsigned int n);
        ~Array();
        Array &operator=(const Array &other);
        T operator[](int);
        Array(const Array &other); 
        int size();
        
    class OutOfBoundsException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Error: Index is out of bounds!";
            }
        };

};

#endif
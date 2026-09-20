/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 13:03:11 by nour              #+#    #+#             */
/*   Updated: 2026/09/20 10:47:47 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP 
# define ARRAY_HPP
# include <string>
# include <ctime>
# include <cstdlib>

template <typename T>
class Array{
    private:
        T *arr;
        int len;
    
    public:
        Array();
        Array(unsigned int n);
        ~Array();
        Array &operator=(const Array &other);
        T &operator[](int);
        const T &operator[](int) const;
        Array(const Array &other); 
        int size() const;
        
    class OutOfBoundsException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Error: Index is out of bounds!";
            }
        };

};

#endif
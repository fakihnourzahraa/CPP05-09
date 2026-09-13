/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 13:03:11 by nour              #+#    #+#             */
/*   Updated: 2026/09/13 13:04:42 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "iostream"
# include "fstream"
# include "iomanip"
# include "cstdlib"
# include <cstdint>
# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <cmath>
# include <cerrno>
# include <iomanip>

class Serializer
{
    private:
	Serializer();
	~Serializer();
	Serializer &operator=(const Serializer &other);
	Serializer(const Serializer &other);

    public:
	uintptr_t serialize(Data* ptr);
    Data* deserialize(uintptr_t raw);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 13:03:11 by nour              #+#    #+#             */
/*   Updated: 2026/09/19 14:08:45 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <string>

template <typename T> T max(T &x, T &y)
{
    if (x > y)
        return x;
    return y;
} 
template <typename T> T min(T &x, T &y)
{
    if (x > y)
        return y;
    return x;
} 
template <typename T> void swap(T &x, T &y)
{
    T z = x;
    x = y;
    y = z;
} 
#endif
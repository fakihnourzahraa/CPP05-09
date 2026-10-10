/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 13:03:11 by nour              #+#    #+#             */
/*   Updated: 2026/10/10 12:45:12 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <string>
# include <iostream>
# include <cstdlib>
# include <ctime>
# include "easyfind.hpp"
# include "vector"
# include "list"
# include "deque"
# include "stack"
# include "queue"

template <typename T>
class Span
{
    private:
	unsigned int N;
	template <typename T> cont;

    public:
	Span();
	~Span();
	Span(unsigned int N);
	Span &operator=(const Span &other);
	Span(const Span &other);

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();	
	unsigned int getN();
	
	class SpanIsFull : public std::exception
	{
		public:
		const char *what() const throw();
	};
	class SpanIsEmpty : public std::exception
	{
		public:
		const char *what() const throw();
	};
	template <typename T> int easyCopy(T arr[], int x, int y)
	{
		for (unsigned long j = 0; (j < arr.size() && j < y); j++)
		{
			addNumber(arr[j]);
		}
	} 
};

#endif
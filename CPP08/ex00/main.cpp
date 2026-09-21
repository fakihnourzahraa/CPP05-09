/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 14:11:08 by nour              #+#    #+#             */
/*   Updated: 2026/09/21 17:10:18 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "easyfind.hpp"
# include "vector"
# include "list"
# include "deque"
# include "stack"
# include "queue"

int main(void)
{

    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
	std::cout<<::easyfind(vec, 10)<<std::endl;
	
	std::list<float> list1;
	list1.push_back(1.5f);
	list1.push_front(0.5f);
	std::cout<<::easyfind(vec, 2)<<std::endl;
	
	std::stack<int> stack1;
	stack1.push(5);
	stack1.push(10);
	std::cout<<::easyfind(vec, 10)<<std::endl;
	
	std::priority_queue<int> pq1;
	pq1.push(30);
	pq1.push(10);
	pq1.push(50); 
	std::cout<<::easyfind(vec, 10)<<std::endl;
    return 0;
}
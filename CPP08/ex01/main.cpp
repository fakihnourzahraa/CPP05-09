/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 14:11:08 by nour              #+#    #+#             */
/*   Updated: 2026/10/10 13:44:39 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "Span.hpp"
# include "vector"
# include "list"
# include "deque"
# include "stack"
# include "queue"


int main()
{
    std::cout << "--- 1. Testing Constructors ---" << std::endl;
    Span<int> sp(5);
    std::cout << "Span size N is: " << sp.getN() << std::endl;

    std::cout << "\n--- 2. Testing addNumber ---" << std::endl;
    try 
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Successfully added 5 numbers!" << std::endl;
        
        // This 6th add should trigger your exception
        std::cout << "Attempting to add a 6th number..." << std::endl;
        sp.addNumber(42); 
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- 3. Testing Copy Constructor & Assignment ---" << std::endl;
    Span<int> spCopy(sp);
    std::cout << "Copied Span size N is: " << spCopy.getN() << std::endl;

    Span<int> spAssign;
    spAssign = sp;
    std::cout << "Assigned Span size N is: " << spAssign.getN() << std::endl;

    std::cout << "\n--- 4. Destruction Phase ---" << std::endl;
    return 0;
}
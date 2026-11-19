/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 15:31:55 by nour              #+#    #+#             */
/*   Updated: 2026/11/19 13:50:18 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "Array.hpp"
# include "Array.tpp"

template <typename T>
void printArray(const Array<T> &arr)
{
    std::cout << "[ ";
    for (unsigned int i = 0; i < static_cast<unsigned int>(arr.size()); i++)
        std::cout << arr[i] << " ";
    std::cout << "] size: " << arr.size() << std::endl;
}

int main(void)
{
    std::cout << "--- empty array ---" << std::endl;
    Array<int> empty;
    printArray(empty);
    try
    {
        empty[0] = 1;
    }
    catch (const std::exception &e)
    {
        std::cerr << "empty[0]: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- int array (default-initialized, then filled) ---" << std::endl;
    Array<int> nums(5);
    printArray(nums);
    for (unsigned int i = 0; i < 5; i++)
        nums[i] = i * 10;
    printArray(nums);

    Array<int> copy(nums);
    copy[0] = 999;
    std::cout << "original: ";
    printArray(nums);
    std::cout << "copy:     ";
    printArray(copy);

   
    Array<int> assigned(2);
    assigned = nums;
    nums[4] = -1;
    std::cout << "original: ";
    printArray(nums);
    std::cout << "assigned: ";
    printArray(assigned);

    Array<std::string> words(3);
    words[0] = "hello";
    words[1] = "from";
    words[2] = "Array";
    printArray(words);

    const Array<std::string> constWords(words);
    std::cout << "constWords[0]: " << constWords[0] << std::endl;
    std::cout << "constWords.size(): " << constWords.size() << std::endl;
    // constWords[0] = "nope"; 
    std::cout << std::endl << "--- out of bounds ---" << std::endl;
    try
    {
        nums[5] = 42;
    }
    catch (const std::exception &e)
    {
        std::cerr << "nums[5]: " << e.what() << std::endl;
    }
    try
    {
        std::cout << constWords[-1] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "constWords[-1]: " << e.what() << std::endl;
    }

    return 0;
}
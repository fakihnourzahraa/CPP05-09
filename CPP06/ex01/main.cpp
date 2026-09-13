/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 13:03:17 by nour              #+#    #+#             */
/*   Updated: 2026/09/13 15:11:45 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "Serializer.hpp"

int main(void)
{
    Data pre;
    pre.id = 42;
    pre.label = "hi";
    pre.val = 5;

    Data *prePtr = &pre;

    uintptr_t raw = Serializer::serialize(prePtr);
    std::cout << "Serialized: " << raw << std::endl;

    Data *post = Serializer::deserialize(raw);
    std::cout << "Deserialized: " << post << std::endl;

    std::cout << "id=" << post->id << " label=" << post->label<< " value=" << post->val << std::endl;

    return 0;
}
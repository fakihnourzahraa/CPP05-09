/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 13:03:17 by nour              #+#    #+#             */
/*   Updated: 2026/09/13 16:16:39 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base *generate(void)
{
    srand(time(0));
    int num = (rand() % 3) + 1;
    if (num == 1)
        A *a();
    
}

int main(void)
{

    uintptr_t raw = Serializer::serialize(prePtr);
    std::cout << "Serialized: " << raw << std::endl;

    Data *post = Serializer::deserialize(raw);
    std::cout << "Deserialized: " << post << std::endl;

    std::cout << "id=" << post->id << " label=" << post->label<< " value=" << post->val << std::endl;

    return 0;
}
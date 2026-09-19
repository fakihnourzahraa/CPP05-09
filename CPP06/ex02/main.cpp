/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 13:03:17 by nour              #+#    #+#             */
/*   Updated: 2026/09/19 12:02:43 by nfakih           ###   ########.fr       */
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

	int num =0;
     num = (rand() % 3) + 1;
    if (num == 1)
	{
		std::cout <<"A generated"<<std::endl;
		Base *a = new A();
		return a;
	}
	else if (num == 2)
	{
		std::cout <<"B generated"<<std::endl;
		Base *a = new B();
		return a;
	}		
		std::cout <<"C generated"<<std::endl;
		Base *a = new C();
		return a;
}
void identify(Base *p)
{
	Base *a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout <<"Pointer is A"<<std::endl;
		return ;
	}
	Base *b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout <<"Pointer is B"<<std::endl;
		return ;
	}
	Base *c = dynamic_cast<C*>(p);
	if (c)
	{
		std::cout <<"Pointer is C"<<std::endl;
		return ;
	}
}

void identify(Base &p)
{
	try 
	{
		Base &a = dynamic_cast<A&>(p);
		std::cout << "Pointer is A"<<std::endl;
		(void) a;
		return;
	}
	catch (const std::exception& e)
	{	
	}

	
	try 
	{
		Base &a = dynamic_cast<B&>(p);
			std::cout << "Pointer is B"<<std::endl;
		(void) a;
		return;
	}
	catch (const std::exception& e)
	{	
	}

	
	try 
	{
		Base &a = dynamic_cast<C&>(p);
		std::cout << "Pointer is C"<<std::endl;
		(void) a;
		return ;
	}
	catch (const std::exception& e)
	{	
	}

}

int main(void)
{
	    srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		Base *a = generate();
		identify(a);
		identify(*a);
		delete a;
		a = NULL;
	}

    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 13:03:17 by nour              #+#    #+#             */
/*   Updated: 2026/09/13 17:52:59 by nfakih           ###   ########.fr       */
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
	bool r = false;
	try 
	{
		Base *a = dynamic_cast<A*>(&p);
		(void) a;
	}
	catch (const std::exception& e)
	{	
		r = true;
	}
	if (r == false)
	{
		std::cout << "Pointer is A";
		return ;
	}
	
	try 
	{
		Base *a = dynamic_cast<B*>(&p);
		(void) a;
	}
	catch (const std::exception& e)
	{	
		r = true;
	}
	if (r == false)
	{
		std::cout << "Pointer is B";
		return ;
	}
	
	try 
	{
		Base *a = dynamic_cast<C*>(&p);
		(void) a;
	}
	catch (const std::exception& e)
	{	
		r = true;
	}
	if (r == false)
	{
		std::cout << "Pointer is C";
		return ;
	}
}

int main(void)
{
	Base *a = generate();
	identify(a);
	identify(&*a);

    return 0;
}
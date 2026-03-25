/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:24 by asmati            #+#    #+#             */
/*   Updated: 2026/03/25 16:28:46 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Creation of Animals === " << std::endl << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* c = new WrongCat();
	std::cout << std::endl << "=== Animals sounds ===" << std::endl << std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();
		//Wrong fonction test !
	
	std::cout << std::endl << "=== Wrong Animals sounds ===" << std::endl << std::endl;
	wrong->makeSound(); 
	c->makeSound() ;
	
	std::cout << std::endl << "=== Delete ===" << std::endl << std::endl; 
	delete j;
	delete i;
	delete meta;
	delete c;
	delete wrong;

	std::cout << std::endl << "=== End? ===" << std::endl ; 
	return 0;
}
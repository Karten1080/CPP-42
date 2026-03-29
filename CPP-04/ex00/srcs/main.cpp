/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:24 by asmati            #+#    #+#             */
/*   Updated: 2026/03/28 20:30:33 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main()
{
    std::cout << "--- Creation ---" << std::endl;
    const Animal* Good_Animal = new Animal();
    const Animal* Good_Dog = new Dog();
    const Animal* Good_Cat = new Cat();
    const WrongAnimal* Wrong_Animal = new WrongAnimal();
    const WrongAnimal* Wrong_Cat = new WrongCat();
    std::cout << std::endl << "--- Make Sound ---" << std::endl << std::endl;
    Good_Animal->getType();
    Good_Animal->makeSound(); 
    Good_Dog->getType();
    Good_Dog->makeSound();
    Good_Cat->getType();
    Good_Cat->makeSound();
    std::cout << std::endl << "--- Make Wrong Sound ---" << std::endl << std::endl;
    Wrong_Animal->getType();
    Wrong_Animal->makeSound();
    Wrong_Cat->getType();
    Wrong_Cat->makeSound();
    std::cout << std::endl << "--- Destruction ---" << std::endl << std::endl;
    delete Good_Animal;
    delete Good_Dog;
    delete Good_Cat;
    delete Wrong_Animal;
    delete Wrong_Cat;
    std::cout << std::endl << "--- End? ---" << std::endl;
    return 0;
}
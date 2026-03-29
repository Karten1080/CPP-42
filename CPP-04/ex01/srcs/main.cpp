/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:24 by asmati            #+#    #+#             */
/*   Updated: 2026/03/29 14:23:41 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "--- Creation ---" << std::endl;
    int Animals = 10;
    const Animal* Zoo[Animals];
    
    for(int i = 0; i < Animals;i++)
    {
        if(i < (Animals / 2))
            Zoo[i] = new Dog();
        else
            Zoo[i] = new Cat();
    }
    std::cout << std::endl << "--- Animal Sound ---" << std::endl << std::endl;
    for(int i = 0; i < Animals;i++)
        Zoo[i]->makeSound();
    std::cout << std::endl << "--- Destruction de l'array" << std::endl << std::endl;
    for(int i = 0; i < Animals;i++)
        delete Zoo[i];    
    std::cout << std::endl <<"--- Test Deep Copy ---" << std::endl; 
    Dog original;
    original.getBrain()->
    return 0;
}
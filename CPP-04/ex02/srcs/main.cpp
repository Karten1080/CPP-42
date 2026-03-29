/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:24 by asmati            #+#    #+#             */
/*   Updated: 2026/03/29 23:09:11 by asmati           ###   ########.fr       */
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
     Animal* Zoo[Animals];
    
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
    original.getBrain()->setIdea(0,"I'm original");
    Dog copy(original);
    copy.getBrain()->setIdea(0,"I'm copy");
    
    std::cout << std::endl << "Original idée 0 : " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copie idée 0    : " << copy.getBrain()->getIdea(0) << std::endl;

    if (original.getBrain()->getIdea(0) != copy.getBrain()->getIdea(0))
        std::cout << "✅ SUCCÈS : Les cerveaux sont distincts !" << std::endl;
    else
        std::cout << "❌ ÉCHEC : C'est une Shallow Copy (cerveau partagé) !" << std::endl;

    std::cout << "\n--- TEST DEEP COPY (AFFECTATION) ---" << std::endl;
    Cat cat1;
    Cat cat2;
    cat1.getBrain()->setIdea(0, "Manger du thon");
    
    cat2 = cat1;
    // cat2.getBrain()->setIdea(0, "Dormir sur le clavier");

    std::cout << "Cat1 idée 0 : " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 idée 0 : " << cat2.getBrain()->getIdea(0) << std::endl;

    
    return 0;
}
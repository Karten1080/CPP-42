/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:46:16 by asmati            #+#    #+#             */
/*   Updated: 2026/03/28 15:42:31 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongWrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongWrongAnimal makes a sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    std::cout << type << ": ";
    return type;
}



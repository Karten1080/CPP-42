/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:46:16 by asmati            #+#    #+#             */
/*   Updated: 2026/03/28 21:22:44 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Animal makes a sound" << std::endl;
}

std::string Animal::getType()  const{
    std::cout << type << ": ";
    return type;
}

Animal &Animal::operator=(const Animal &src)
{
    if(this != &src)
    {
        this->type = src.type;
    }
    return *this;
}
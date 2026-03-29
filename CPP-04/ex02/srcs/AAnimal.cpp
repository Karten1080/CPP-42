/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:46:16 by asmati            #+#    #+#             */
/*   Updated: 2026/03/29 17:03:22 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called" << std::endl;
}

void AAnimal::makeSound() const {
    std::cout << "AAnimal makes a sound" << std::endl;
}

std::string AAnimal::getType()  const{
    std::cout << type << ": ";
    return type;
}

AAnimal::AAnimal(const AAnimal &src)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    this->type = src.type;       
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
    if(this != &src)
        this->type = src.type;
    return *this;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:24 by asmati            #+#    #+#             */
/*   Updated: 2026/03/25 15:07:19 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog"; 
    std::cout << "Dog: constructor called" << std::endl;
}

Dog::~Dog(){
	this->type = "Dog";
	std::cout << "Dog: Destructor called" << std::endl;
};

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}


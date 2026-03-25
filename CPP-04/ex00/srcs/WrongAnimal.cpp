
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:24 by asmati            #+#    #+#             */
/*   Updated: 2026/03/25 13:41:58 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal: Constructor called" << std::endl;
};

WrongAnimal::~WrongAnimal(){
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal: Destructor called" << std::endl;
};

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal make sound" << std::endl;
}

std::string WrongAnimal::getType() const{
	return(this->type);
}
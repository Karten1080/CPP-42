
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

#include "Animal.hpp"

Animal::Animal(){
	this->type = "Animal";
	std::cout << "Animal: Constructor called" << std::endl;
};

Animal::~Animal(){
	this->type = "Animal";
	std::cout << "Animal: Destructor called" << std::endl;
};

void Animal::makeSound() const {
    std::cout << "Animal make sound" << std::endl;
}

std::string Animal::getType() const{
	return(this->type);
}
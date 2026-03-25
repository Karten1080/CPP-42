/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:24 by asmati            #+#    #+#             */
/*   Updated: 2026/03/25 14:43:53 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat() : Animal(){
	this->type = "Cat";
	std::cout << "Cat: Constructor called" << std::endl;
};

Cat::~Cat(){
	this->type = "Cat";
	std::cout << "Cat: Destructor called" << std::endl;
};

void Cat::makeSound() const {
    std::cout << "Miaou! Miaou!" << std::endl;
}
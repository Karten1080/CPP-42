/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:24 by asmati            #+#    #+#             */
/*   Updated: 2026/03/25 16:24:03 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal(){
	this->type = "WrongCat";
	std::cout << "WrongCat: Constructor called" << std::endl;
};

WrongCat::~WrongCat(){
	this->type = "WrongCat";
	std::cout << "WrongCat: Destructor called" << std::endl;
};

void WrongCat::makeSound() const {
    std::cout << "WrongCat: Miaou! Miaou!" << std::endl;
}
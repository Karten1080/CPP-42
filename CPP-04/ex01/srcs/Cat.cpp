/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:46:16 by asmati            #+#    #+#             */
/*   Updated: 2026/03/28 21:27:19 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

Cat::Cat() :  Animal() {
    this->type = "Cat";
    this->_brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->_brain = new Brain(*src._brain);
}

Cat &Cat::operator=(const Cat &src)
{
    if(this != &src){
        delete this->_brain;
        Animal::operator=(src);
        this->_brain = new Brain(*src._brain);        
    }
    return *this;
}


Brain* Cat::getBrain(void) const 
{
    return (this->_brain);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:46:16 by asmati            #+#    #+#             */
/*   Updated: 2026/03/29 16:57:10 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

Dog::Dog() :  Animal(){
    std::cout << "Dog constructor called" << std::endl;
    this->_brain = new Brain();
    this->type = "Dog";
}

Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof !" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = new Brain(*src._brain);
}

Dog &Dog::operator=(const Dog &src)
{
    if(this != &src)
    {
        delete _brain;
        Animal::operator=(src);
        this->_brain = new Brain(*src._brain);        
    }
    return (*this);    
}

Brain* Dog::getBrain(void) const 
{
    return (this->_brain);
}
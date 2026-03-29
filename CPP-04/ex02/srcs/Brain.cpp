/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:46:16 by asmati            #+#    #+#             */
/*   Updated: 2026/03/28 16:26:08 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
};

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
};

Brain::Brain(const Brain &src)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for(int i = 0;i < 100; i++)
    {
        this->ideas[i] = src.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &src)
{
    std::cout << "Brain copy assignment called" << std::endl;
    if(this != &src)
    {
        for(int i = 0;i < 100; i++)
        {
            this->ideas[i] = src.ideas[i];
        }
    }
    return *this;
}

void Brain::setIdea(int index, std::string idea)
{
    if(index >= 0 && index <= 100)
        this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    return (this->ideas[index]);
}
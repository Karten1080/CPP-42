/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:24 by asmati            #+#    #+#             */
/*   Updated: 2026/03/16 15:31:36 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : 	_value(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};


Fixed::Fixed(const int n)
{
	std::cout << "Int Constructor Called" << std::endl;
	this->_value =  (n << _bits);
}

Fixed::Fixed(const float n)
{
	std::cout << "Float Constructor Called" << std::endl;
	this->_value = roundf(n * (1 << _bits));
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _bits));
}	

int Fixed::toInt(void) const
{
	return (this->_value >> _bits);
}

std::ostream & operator<<(std::ostream & os, Fixed const & fixed)
{
	return (os << fixed.toFloat());
}
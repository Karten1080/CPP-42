/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:24 by asmati            #+#    #+#             */
/*   Updated: 2026/03/17 15:14:18 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : 	_value(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

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

Fixed Fixed::operator*(Fixed const & rhs) const{
	Fixed res;
	long long tmp =((long long)this->_value * rhs.getRawBits() >> _bits);
	if(Overflow(tmp))
		return (std::cerr << "Error: Fixed multiplication overflow" << std::endl,Fixed(0));
	res.setRawBits((int)tmp);
	return (res);
}

Fixed Fixed::operator/(Fixed const & rhs) const{
	Fixed res;
	if(rhs.getRawBits() == 0)
		return (std::cerr << "Error: Division by zero" << std::endl,Fixed(0));
	long long tmp = (((long long)this->_value << _bits) / rhs.getRawBits());	
	if(Overflow(tmp))
		return (std::cerr << "Error: Fixed division overflow" << std::endl,Fixed(0));
	res.setRawBits(tmp);
	return (res);
}

Fixed Fixed::operator+(Fixed const & rhs) const {
	long long tmp = ((long long)this->_value + rhs.getRawBits());
	if(Overflow(tmp))
		return (std::cerr << "Error: Fixed addition overflow" << std::endl, Fixed(0));
	Fixed res;
	res.setRawBits((int)tmp);
	return (res);
}

Fixed & Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if(this != &src)
		this->_value = src.getRawBits();
	return *this;
}

Fixed & min(Fixed & a, Fixed & b)
{
	return (a < b ? a : b);
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b)
{
	return (a < b ? a : b);
}

Fixed & max(Fixed & a, Fixed & b)
{
	return (a > b ? a : b);	
}

const Fixed & Fixed::max(const Fixed & a, const Fixed & b)
{
	return (a > b ? a : b);	
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

int Fixed::toInt(void) const
{
	return (this->_value >> _bits);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _bits));
}	


bool Fixed::operator==(const Fixed & rhs) const
{	
	return(this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed & rhs) const
{
		return(this->getRawBits() <= rhs.getRawBits());

}

bool Fixed::operator>=(const Fixed & rhs) const
{
		return(this->getRawBits() >= rhs.getRawBits());	
}

bool Fixed::operator<(const Fixed & rhs) const
{
		return(this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>(const Fixed & rhs) const
{
		return(this->getRawBits() > rhs.getRawBits());		
}

bool Fixed::operator!=(const Fixed & rhs) const
{
			return(this->getRawBits() != rhs.getRawBits());
}

Fixed & Fixed::operator++(void)
{
	this->_value++;
	return *this;
}
Fixed & Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed copy(*this);
	_value++;
	return (copy);	
}

Fixed Fixed::operator--(int)
{
	Fixed copy(*this);
	_value--;
	return (copy);	
}


bool	Fixed::Overflow(long long n) const
{
    return (n > 2147483647 || n < -2147483648);
}

std::ostream & operator<<(std::ostream & os, Fixed const & fixed)
{
	return (os << fixed.toFloat());
}
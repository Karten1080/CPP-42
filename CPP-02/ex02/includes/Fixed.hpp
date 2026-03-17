/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:18 by asmati            #+#    #+#             */
/*   Updated: 2026/03/17 13:44:28 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
#include <cmath>

class Fixed {
private:
	int					_value;
	static const int 	_bits = 8;


public:
	Fixed();
	~Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &src);            
	
	Fixed &operator=(const Fixed &src);
	Fixed operator+(Fixed const & rhs) const;	
	Fixed operator*(Fixed const & rhs) const;
	Fixed operator/(Fixed const & rhs) const;

	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	bool operator==(Fixed const & rhs) const;
	bool operator<(Fixed const & rhs) const;
	bool operator<=(Fixed const & rhs) const;
	bool operator>=(Fixed const & rhs) const;
	bool operator>(Fixed const & rhs) const;
	bool operator!=(Fixed const & rhs) const;
	bool Overflow(long long n) const;

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream & operator<<(std::ostream & os, Fixed const & fixed);

#endif
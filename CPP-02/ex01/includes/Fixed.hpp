/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:18 by asmati            #+#    #+#             */
/*   Updated: 2026/03/14 15:15:01 by asmati           ###   ########.fr       */
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
	Fixed(const Fixed &src);            // Constructeur de recopie
	Fixed &operator=(const Fixed &src); // Opérateur d'affectation
	Fixed(const int n);
	int toInt( void ) const;
	Fixed(const float n);
	float toFloat( void ) const;
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );

};

#endif
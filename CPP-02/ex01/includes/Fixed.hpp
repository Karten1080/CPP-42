/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:18 by asmati            #+#    #+#             */
/*   Updated: 2026/03/16 14:56:28 by asmati           ###   ########.fr       */
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
	
	float toFloat( void ) const;
	int toInt( void ) const;

};

std::ostream & operator<<(std::ostream & os, Fixed const & fixed);

#endif
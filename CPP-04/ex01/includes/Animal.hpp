/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:18 by asmati            #+#    #+#             */
/*   Updated: 2026/03/21 22:14:05 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
#include "Brain.hpp"


class Animal {
protected:
		std::string type;
public:
	
	Animal();
    virtual ~Animal();
	Animal &operator=(const Animal &src);
	virtual void makeSound() const;
	virtual std::string getType() const;
};

#endif
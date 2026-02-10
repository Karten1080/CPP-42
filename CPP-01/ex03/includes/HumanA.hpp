/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:57:25 by asmati            #+#    #+#             */
/*   Updated: 2026/02/03 13:33:12 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class HumanA {
private:

	std::string _Name;
	Weapon& _Weapon;

public:
	HumanA(const std::string& Name,Weapon& Weapon);
	~HumanA();

	void attack();
};

#endif
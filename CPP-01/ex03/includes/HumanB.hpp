/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:57:25 by asmati            #+#    #+#             */
/*   Updated: 2026/02/03 13:58:05 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class HumanB {
private:

	std::string _Name;
	Weapon* _Weapon;

public:
	HumanB(const std::string& Name);
	~HumanB();

	void attack();
	void setWeapon(Weapon& weapon);  // Pour assigner une arme plus tard

};

#endif
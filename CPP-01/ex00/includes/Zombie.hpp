/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:58:59 by asmati            #+#    #+#             */
/*   Updated: 2026/02/02 17:14:00 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {

private:
	std::string _Name;
	
public:

	Zombie(std::string);
	~Zombie();
	
	void announce(void);


};


Zombie* newZombie( std::string name );	
void  randomChump(std::string name);



#endif
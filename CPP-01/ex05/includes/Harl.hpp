/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:11:05 by asmati            #+#    #+#             */
/*   Updated: 2026/02/18 10:45:01 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



# ifndef HARL_HPP
# define HARL_HPP
#include <iostream>


class Harl{
	private :
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public :
		Harl();
		~Harl();
		void complain( std::string level );
		void (Harl::*fonctions[4])();

};

#endif
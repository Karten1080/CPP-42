/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:11:05 by asmati            #+#    #+#             */
/*   Updated: 2026/02/12 12:37:02 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


class Harl{
	private :
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public :
		void complain( std::string level );
		

};
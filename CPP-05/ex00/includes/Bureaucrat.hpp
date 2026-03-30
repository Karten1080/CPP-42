/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:43:49 by asmati            #+#    #+#             */
/*   Updated: 2026/03/30 21:48:33 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>

class Bureaucrat 
{
private:
    const std::string   _name;
    int                 _grade;
public:
    
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat &operator=(const Bureaucrat &src);
    ~Bureaucrat();
    
    class GradeTooHighException : public std::exception{
    public:
        virtual const char* what() const throw(){return "The grade is to high (grade > 1)!";}
    };
    class GradeTooLowException : public std::exception{
        public:
            virtual const char* what() const throw(){return "The grade is to low (grade < 150)!";}
    };
    
    std::string     getName() const;
    int             getGrade() const;
    void            incrementGrade();
    void            decrementGrade();


};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
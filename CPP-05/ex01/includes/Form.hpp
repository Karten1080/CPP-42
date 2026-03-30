/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:43:49 by asmati            #+#    #+#             */
/*   Updated: 2026/03/30 22:15:19 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Form_HPP
# define Form_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string   _name;
    bool                _signed;
    const int           _grade_sign;
    const int           _grade_execute;
    
public:
    
    Form();
    Form(std::string name,int grade_sign,int grade_execute);
    Form(const Form &src);
    Form &operator=(const Form &src);
    ~Form();
    
    class GradeTooHighException : public std::exception{
    public:
        virtual const char* what() const throw(){return "The grade is to high (grade > 1)!";}
    };
    class GradeTooLowException : public std::exception{
        public:
            virtual const char* what() const throw(){return "The grade is to low (grade < 150)!";}
    };
    

    
    std::string     getName() const;
  
   
    void            beSigned(const Bureaucrat & b);
    int             getGrade_Sign() const;
    int             getGrade_execute() const;
    bool            getIsSigned() const;
  

};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif
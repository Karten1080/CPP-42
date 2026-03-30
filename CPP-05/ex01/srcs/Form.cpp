/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:43:53 by asmati            #+#    #+#             */
/*   Updated: 2026/03/30 18:28:45 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false),_grade_sign(150),_grade_execute(150){};

Form::Form(std::string name,int grade_sign,int grade_execute) : _name(name), _signed(false), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
    if(_grade_sign < 1 || _grade_execute < 1)
        throw Form::GradeTooHighException();
    else if(_grade_execute > 150 || _grade_sign > 150)
        throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form &src)
{
    if(this != &src)
        this->_signed = src._signed;
    return *this;    
}

Form::~Form(){};

std::string Form::getName() const
{
    return this->_name;
}

int Form::getGrade_Sign() const
{
    return this->_grade_sign;
}

int Form::getGrade_execute() const
{
    return this->_grade_execute;
}

bool    Form::getIsSigned() const
{
    return (this->_signed);
}

void Form::beSigned(const Bureaucrat & b)
{
    if(b.getGrade() <= this->_grade_sign)
        this->_signed = true;
    else
        throw Form::GradeTooLowException();
}


std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
    o << "Form: " << rhs.getName()
      << " | signed: " << (rhs.getIsSigned() ? "Yes" : "NO")
      << " | Grade to sign: " << rhs.getGrade_Sign()
      << " | Grade to execute: " << rhs.getGrade_execute();
    return o;
}

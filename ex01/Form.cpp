/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:27:28 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/10 02:44:38 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// getter / setter

const std::string Form::getName( void ) const {
	return _name;
}

int Form::getSign( void ) const {
	return _sign;
}

int Form::getExec( void ) const {
	return _exec;
}

bool	Form::getStatus( void )
{
	return _status;
}

void	Form::beSigned(Bureaucrat* param)
{
	(void)param;
}

// Orthodox Canonical Form

Form::Form( const std::string name, int sign, int exec ) : 
	_name(name), _sign(sign), _exec(exec) {

	if (_sign < 1)
		throw GradeTooHighException(name, _sign);
	else if (_sign > 150)
		throw GradeTooLowException(name, _sign);
	if (_exec < 1)
		throw GradeTooHighException(name, _exec);
	else if (_exec > 150)
		throw GradeTooLowException(name, _exec);
}

Form::~Form ( void ) {}

// Exception handler

Form::GradeTooHighException::GradeTooHighException(const std::string& name, int grade) :
	_name(name), _grade(grade) {}

Form::GradeTooHighException::~GradeTooHighException( void ) throw() {}

const char* Form::GradeTooHighException::what() const throw()
{
	return this->_name.c_str();
}

int Form::GradeTooHighException::grade() const {
	return _grade;
}

Form::GradeTooLowException::GradeTooLowException(const std::string& name, int grade) :
	_name(name), _grade(grade) {}

Form::GradeTooLowException::~GradeTooLowException( void ) throw() {}

const char* Form::GradeTooLowException::what() const throw()
{
	return this->_name.c_str();
}

int Form::GradeTooLowException::grade() const {
	return _grade;
}

std::ostream& operator<<( std::ostream& os, const Form& rhs )
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getName() << ".";
	return os;
}

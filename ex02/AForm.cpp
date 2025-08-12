/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:11:20 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/12 14:12:30 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
	if (_status)
	{
		std::cout 
			<< C_R
			<< param->getName()
			<< " couldn't sign ["
			<< getName()
			<< "] because "
			<< "already signed in."
			<< C_CLR << std::endl;
		return;
	}
	std::cout 
		<< C_G
		<< param->getName()
		<< " signed ["
		<< getName()
		<< "]"
		<< C_CLR << std::endl;
	_status = !_status;
}

// Orthodox Canonical Form

Form::Form( const std::string name, int sign, int exec ) : 
	_name(name), _sign(sign), _exec(exec) {
	if (_sign < MAX_GRADE)
		throw GradeTooHighException(name, _sign, _exec);
	else if (_sign > MIN_GRADE)
		throw GradeTooLowException(name, _sign, _exec);
	if (_exec < MAX_GRADE)
		throw GradeTooHighException(name, _sign, _exec);
	else if (_exec > MIN_GRADE)
		throw GradeTooLowException(name, _sign, _exec);
	_status = false;
	Log::a(F, L, C_B, "[" + _name + "] constructed.");
}

Form::~Form ( void ) {
	Log::a(F, L, C_R, "[" + _name + "] destructed.");
}

// Exception handler

Form::GradeTooHighException::GradeTooHighException(const std::string& name, int sign, int exec) :
	_name(name), _sign(sign), _exec(exec) {}

Form::GradeTooHighException::~GradeTooHighException( void ) throw() {}

const char* Form::GradeTooHighException::what() const throw()
{
	return this->_name.c_str();
}

int Form::GradeTooHighException::sign() const {
	return _sign;
}

int Form::GradeTooHighException::exec() const {
	return _exec;
}

Form::GradeTooLowException::GradeTooLowException(const std::string& name, int sign, int exec) :
	_name(name), _sign(sign), _exec(exec) {}

Form::GradeTooLowException::~GradeTooLowException( void ) throw() {}

const char* Form::GradeTooLowException::what() const throw()
{
	return this->_name.c_str();
}

int Form::GradeTooLowException::sign() const {
	return _sign;
}

int Form::GradeTooLowException::exec() const {
	return _exec;
}

std::ostream& operator<<( std::ostream& os, const Form& rhs )
{
	os << "Form name [" << rhs.getName() << "]"
		<< " sign level [" << rhs.getSign() << "]"
		<< " exec level [" << rhs.getExec() << "]";
	return os;
}

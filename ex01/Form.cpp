/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:27:28 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/12 18:14:26 by tiizuka          ###   ########.fr       */
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

Form::Form( const std::string name) :
	_name(name),
	_sign(DEFAULT_SIGN_GRADE),
	_exec(DEFAULT_EXEC_GRADE) {

		if (_sign < MAX_GRADE)
		throw GradeTooHighException("[" + name + "]" + " sign grade " + Log::itoa(_sign));
	else if (_sign > MIN_GRADE)
		throw GradeTooLowException("[" + name + "]" + " sign grade " + Log::itoa(_sign));
	if (_exec < MAX_GRADE)
		throw GradeTooHighException("[" + name + "]" + " exec grade " + Log::itoa(_exec));
	else if (_exec > MIN_GRADE)
		throw GradeTooLowException("[" + name + "]" + " exec grade " + Log::itoa(_exec));
	_status = false;
	Log::a(F, L, C_B, "[" + _name + "] constructed.");
}

Form::~Form ( void ) {
	Log::a(F, L, C_R, "[" + _name + "] destructed.");
}

// Exception handler

Form::GradeTooHighException::GradeTooHighException(const std::string& name) : _name(name) {
	std::cout << _name << std::endl;
}

Form::GradeTooHighException::~GradeTooHighException( void ) throw() {}

const char* Form::GradeTooHighException::what() const throw()
{
	std::cout << _name << std::endl;
	return _name.c_str();
}

Form::GradeTooLowException::GradeTooLowException(const std::string& name) : _name(name) {}

Form::GradeTooLowException::~GradeTooLowException( void ) throw() {}

const char* Form::GradeTooLowException::what() const throw()
{
	return this->_name.c_str();
}

std::ostream& operator<<( std::ostream& os, const Form& rhs )
{
	os
		<< "Form name [" << rhs.getName() << "]"
		<< " status [" << (rhs.getExec() ? "sign in" : "sign out") << "]"
		<< " sign [" << rhs.getSign() << "]"
		<< " exec [" << rhs.getExec() << "]";
	return os;
}

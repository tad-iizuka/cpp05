/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:11:20 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/12 21:05:59 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// getter / setter

const std::string AForm::getName( void ) const {
	return _name;
}

int AForm::getSign( void ) const {
	return _sign;
}

int AForm::getExec( void ) const {
	return _exec;
}

bool	AForm::getStatus( void )
{
	return _status;
}

void	AForm::beSigned(Bureaucrat* param)
{
	if (_status)
	{
		Log::a(F, L, C_R, param->getName(), "couldn't sign", getName(), "because of already signed in.");
		return;
	}
	if (_sign < param->getGrade())
		throw GradeTooHighException(
			"[" + param->getName() + "]" + " sign grade " + Log::itoa(param->getGrade()));
	else if (_exec > param->getGrade())
		throw GradeTooHighException(
			"[" + param->getName() + "]" + " exec grade " + Log::itoa(param->getGrade()));
	Log::a(F, L, C_G, param->getName(), "signed", getName());
	_status = !_status;
}

// Orthodox Canonical Form

AForm::AForm( const std::string name) :
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

AForm::~AForm ( void ) {
	Log::a(F, L, C_R, "[" + _name + "] destructed.");
}

// Exception handler

AForm::GradeTooHighException::GradeTooHighException(const std::string& name) : _name(name) {}

AForm::GradeTooHighException::~GradeTooHighException( void ) throw() {}

const char* AForm::GradeTooHighException::what() const throw()
{
	return _name.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& name) : _name(name) {}

AForm::GradeTooLowException::~GradeTooLowException( void ) throw() {}

const char* AForm::GradeTooLowException::what() const throw()
{
	return this->_name.c_str();
}

std::ostream& operator<<( std::ostream& os, const AForm& rhs )
{
	os
		<< __FILE__ << ":"
		<< __LINE__ << " "
		<< "Form [" << rhs.getName() << "]"
		<< " status [" << (rhs.getExec() ? "sign in" : "sign out") << "]"
		<< " sign [" << rhs.getSign() << "]"
		<< " exec [" << rhs.getExec() << "]";
	return os;
}

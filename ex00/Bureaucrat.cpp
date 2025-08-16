/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:27:46 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/16 14:57:40 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// getter / setter

const std::string Bureaucrat::getName( void ) const {
	return _name;
}

int Bureaucrat::getGrade( void ) const {
	return _grade;
}

void Bureaucrat::setGrade( int grade ) {
	_grade = grade;
}

void	Bureaucrat::incGrade( void ) {
	if (_grade - 1 < MAX_GRADE)
		throw GradeTooHighException(_name, _grade - 1);
	else
		_grade--;
}

void	Bureaucrat::decGrade( void ) {
	if (_grade + 1 > MIN_GRADE)
		throw GradeTooLowException(_name, _grade + 1);
	else
		_grade++;
}

// Orthodox Canonical Form

Bureaucrat::Bureaucrat( void ) : _name("none"), _grade(0) {
	throw GradeTooLowException(_name, _grade);
}

Bureaucrat::Bureaucrat( const std::string& name, int grade ) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException(name, grade);
	else if (grade > 150)
		throw GradeTooLowException(Log::m(static_cast::string(file), std::string& line, std::string& color,
			std::string& s1, std::string& s2);
	_grade = grade;
	Log::a(F, L, C_B, "[" + _name + "] constructed.");
}

Bureaucrat::~Bureaucrat ( void ) {
	Log::a(F, L, C_R, "[" + _name + "] destructed.");
}

// Exception handler

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& error) :
	_error(error) {}

Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return this->_error.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& error) :
	_error(error) {}

Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw() {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return this->_error.c_str();
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& rhs )
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return os;
}

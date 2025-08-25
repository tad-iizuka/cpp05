/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:27:46 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/25 18:02:46 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
		throw GradeTooHighException(Log::m(F, L, C_R,
				_name, Log::itoa(_grade - 1)));
	else
		_grade--;
}

void	Bureaucrat::decGrade( void ) {
	if (_grade + 1 > MIN_GRADE)
		throw GradeTooLowException(Log::m(F, L, C_R,
				_name, Log::itoa(_grade + 1)));
	else
		_grade++;
}

void	Bureaucrat::signForm(Form& form)
{
	form.beSigned(*this);
}

// Orthodox Canonical Form

Bureaucrat::Bureaucrat( const std::string& name, int grade ) : _name(name) {
	if (grade < MAX_GRADE)
		throw GradeTooHighException(Log::m(F, L, C_R,
				_name, Log::itoa(grade)));
	else if (grade > MIN_GRADE)
		throw GradeTooLowException(Log::m(F, L, C_R,
				_name, Log::itoa(grade)));
	_grade = grade;
	Log::a(F, L, C_B, "[" + _name + "] constructed.");
}

Bureaucrat::~Bureaucrat ( void ) {
	Log::a(F, L, C_B, "[" + _name + "] destructed.");
}

// Exception handler

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& error) :
	_error(error) {}

Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return _error.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& error) :
	_error(error) {}

Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw() {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return _error.c_str();
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& rhs )
{
	os << C_G << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << C_CLR;
	return os;
}

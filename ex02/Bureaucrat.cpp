/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:27:46 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/14 04:50:37 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

void	Bureaucrat::signForm( void )
{
	AForm *f = new AForm("NewForm");
	f->beSigned(*this);
	delete f;
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	form.execute(*this);
	Log::a(F, L, C_B, "[executeForm]");
}

// Orthodox Canonical Form

Bureaucrat::Bureaucrat( void ) : _name("none"), _grade(0) {
	throw GradeTooLowException(_name, _grade);
}

Bureaucrat::Bureaucrat( const std::string& name, int grade ) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException(name, grade);
	else if (grade > 150)
		throw GradeTooLowException(name, grade);
	_grade = grade;
	Log::a(F, L, C_B, "[" + _name + "] constructed.");
}

Bureaucrat::~Bureaucrat ( void ) {
	Log::a(F, L, C_R, "[" + _name + "] destructed.");
}

// Exception handler

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& name, int grade) :
	_name(name), _grade(grade) {}

Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return this->_name.c_str();
}

int Bureaucrat::GradeTooHighException::grade() const {
	return _grade;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& name, int grade) :
	_name(name), _grade(grade) {}

Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw() {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return this->_name.c_str();
}

int Bureaucrat::GradeTooLowException::grade() const {
	return _grade;
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& rhs )
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return os;
}

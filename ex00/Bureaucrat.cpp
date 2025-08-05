/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:27:46 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/05 22:35:23 by tiizuka          ###   ########.fr       */
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
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decGrade( void ) {
	if (_grade + 1 > 1)
		throw GradeTooHighException();
	else
		_grade--;
}

// Orthodox Canonical Form

Bureaucrat::Bureaucrat( const std::string& name, int grade ) :
	_name(name), _grade(grade) {

	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat ( void ) {}

// Exception handler

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade is Low";
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& rhs )
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return os;
}

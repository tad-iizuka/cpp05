/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:27:46 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/02 03:36:24 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const std::string Bureaucrat::getName( void ) const {
	return _name;
}

unsigned int Bureaucrat::getGrade( void ) const {
	return _grade;
}

void Bureaucrat::setGrade( unsigned int grade ) {
	_grade = grade;
}

Bureaucrat::Bureaucrat( void ) : _name("none"), _grade(1) {}

Bureaucrat::Bureaucrat( std::string name, unsigned int grade ) :
	_name(name), _grade(grade) {}

Bureaucrat::Bureaucrat( const Bureaucrat& src) :
	_name(src._name), _grade(src._grade) {}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& rhs ) {
	if (this != &rhs)
	{
	}
	return *this;
}

Bureaucrat::~Bureaucrat ( void ) {}

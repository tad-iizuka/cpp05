/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:27:28 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/09 12:45:49 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Orthodox Canonical Form

Form::Form( const std::string& name, int grade ) : _name(name), _grade(grade) {

	if (_grade < 1)
		throw GradeTooHighException(name, grade);
	else if (_grade > 150)
		throw GradeTooLowException(name, grade);
}

Form::~Form ( void ) {}

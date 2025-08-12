/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:32:00 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/13 07:24:46 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

void	ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	(void)executor;
	Log::a(F, L, C_G, "[execute]");
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target) :
	AForm(target), _sign(DEFAULT_SIGN_GRADE), _exec(DEFAULT_EXEC_GRADE)  {

	if (_sign < MAX_GRADE)
		throw GradeTooHighException("[" + target + "]" + " sign grade " + Log::itoa(_sign));
	else if (_sign > MIN_GRADE)
		throw GradeTooLowException("[" + target + "]" + " sign grade " + Log::itoa(_sign));
	if (_exec < MAX_GRADE)
		throw GradeTooHighException("[" + target + "]" + " exec grade " + Log::itoa(_exec));
	else if (_exec > MIN_GRADE)
		throw GradeTooLowException("[" + target + "]" + " exec grade " + Log::itoa(_exec));
	_status = false;
	Log::a(F, L, C_B, "[" + _name + "] constructed.");
}

ShrubberyCreationForm::~ShrubberyCreationForm ( void ) {
	Log::a(F, L, C_R, "[" + _name + "] destructed.");
}

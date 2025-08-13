/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:30:53 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/14 06:10:41 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

void	RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	(void)executor;
	Log::a(F, L, C_Y, "drilling noises: brrrrrr...");
	usleep(500000);
	Log::a(F, L, C_Y, "drilling noises: vrrrrrr...");
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0) {
		Log::a(F, L, C_Y, _name, "has been robotomized successed.");
	} else {
		Log::a(F, L, C_Y, _name, "has been robotomized failed.");
	}
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target) :
	AForm(target, DEFAULT_SIGN_GRADE, DEFAULT_EXEC_GRADE) {

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

RobotomyRequestForm::~RobotomyRequestForm ( void ) {
	Log::a(F, L, C_R, "[" + _name + "] destructed.");
}

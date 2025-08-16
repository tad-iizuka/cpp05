/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:30:53 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/17 03:16:04 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	Log::a(F, L, C_Y, "drilling noises: brrrrrr...");
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0) {
		Log::a(F, L, C_Y, _target, "has been robotomized successed.");
	} else {
		Log::a(F, L, C_Y, _target, "has been robotomized failed.");
	}
	Log::a(F, L, C_G, executor.getName(), "executed", _target);
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target) :
	AForm("RobotomyRequestForm", DEFAULT_SIGN_GRADE, DEFAULT_EXEC_GRADE), _target(target) {
	Log::a(F, L, C_B, "[" + _name + "] constructed.");
}

RobotomyRequestForm::~RobotomyRequestForm ( void ) {
	Log::a(F, L, C_B, "[" + _name + "] destructed.");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:30:06 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/16 20:55:51 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	Log::a(F, L, C_Y, _target, "has been pardoned by Zaphod Beeblebrox.");
	Log::a(F, L, C_G, executor.getName(), "executed", _target);
}

PresidentialPardonForm::PresidentialPardonForm( const std::string target) :
	AForm("PresidentialPardonForm", DEFAULT_SIGN_GRADE, DEFAULT_EXEC_GRADE), _target(target) {
	Log::a(F, L, C_B, "[" + _name + "] constructed.");
}

PresidentialPardonForm::~PresidentialPardonForm ( void ) {
	Log::a(F, L, C_B, "[" + _name + "] destructed.");
}

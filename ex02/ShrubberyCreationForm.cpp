/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:32:00 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/25 17:46:32 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::string name = _target + "_shrubbery";
	std::ofstream ofs(name.c_str());
	if (!ofs.is_open()) {
		std::cerr << "Error: couldn't open a " << name.c_str() << std::endl;
		return;
	}
	ofs << "  A  " << std::endl;
	ofs << " AAA " << std::endl;
	ofs << "AAAAA" << std::endl;
	ofs << "  |  " << std::endl;
	ofs.close();
	Log::a(F, L, C_Y, ("[" + _target + "_shrubbery]"), "has been created.");
	Log::a(F, L, C_G, executor.getName(), "executed", _target);
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target) :
	AForm("ShrubberyCreationForm", DEFAULT_SIGN_GRADE, DEFAULT_EXEC_GRADE), _target(target) {
	Log::a(F, L, C_B, "[" + _name + "] constructed.");
}

ShrubberyCreationForm::~ShrubberyCreationForm ( void ) {
	Log::a(F, L, C_B, "[" + _name + "] destructed.");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:47:09 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/15 02:29:01 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <cstring>

class AForm;

class Intern
{
	struct Forms
	{
		const char*	name;
		AForm*			(*f)(const std::string&);
	};

	public:

		AForm*	makeForm(const std::string& form, const std::string& target);

		Intern( void );
		~Intern ( void );
		
	private:

		Intern( const Intern& src); 						// can't use
		Intern& operator=( const Intern& rhs );	// can't use	

};

#endif

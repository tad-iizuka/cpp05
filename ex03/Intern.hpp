/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:47:09 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/14 21:13:57 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern
{
	struct forms
	{
		const char*	name;
		AForm*			(AForm::*f)(const std::string&);
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

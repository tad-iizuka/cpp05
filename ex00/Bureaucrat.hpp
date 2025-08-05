/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:25:23 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/05 22:33:37 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Log.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
{
	public:

		const std::string getName( void ) const;
		int								getGrade( void ) const;
		void 							setGrade( int grade );
		void							incGrade( void );
		void							decGrade( void );

		Bureaucrat( void ) {};											 			// empty definition
		Bureaucrat( const std::string& name, int grade );
		~Bureaucrat ( void );

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:

		const std::string _name;
		int 							_grade;

		Bureaucrat( const Bureaucrat& src); 						// can't use
		Bureaucrat& operator=( const Bureaucrat& rhs );	// can't use
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& rhs );

#endif

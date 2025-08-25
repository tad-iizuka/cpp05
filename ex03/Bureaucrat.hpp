/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:25:23 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/25 17:11:50 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Log.hpp"

class AForm;

class Bureaucrat
{
	public:

		const std::string getName( void ) const;
		int								getGrade( void ) const;
		void 							setGrade( int grade );
		void							incGrade( void );
		void							decGrade( void );
		void							signForm(AForm& form);
		void							executeForm(const AForm& form) const;

		Bureaucrat( const std::string& name, int grade );
		~Bureaucrat ( void );

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(const std::string& error);
				virtual ~GradeTooHighException ( void ) throw();
				virtual const char* what() const throw();
			private:
				std::string _error;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(const std::string& error);
				virtual ~GradeTooLowException ( void ) throw();
				virtual const char* what() const throw();
			private:
				std::string _error;
		};

	private:

		const std::string _name;
		int 							_grade;

		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;

		Bureaucrat( void );															// can't use
		Bureaucrat( const Bureaucrat& src); 						// can't use
		Bureaucrat& operator=( const Bureaucrat& rhs );	// can't use
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& rhs );

#endif

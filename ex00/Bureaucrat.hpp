/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:25:23 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/02 03:36:30 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Log.hpp"

class Bureaucrat
{
	public:

		const std::string getName( void ) const;
		unsigned int getGrade( void ) const;
		void setGrade( unsigned int grade );

		Bureaucrat( void );
		Bureaucrat( std::string name, unsigned int grade );
		Bureaucrat( const Bureaucrat& src) ;
		Bureaucrat& operator=( const Bureaucrat& rhs );
		~Bureaucrat ( void );

		class GradeTooHighException : public std::exception
		{
			public:

				// GradeTooHighException(const std::string& name, unsigned int grade) :
				// 	_name(name), _grade(grade)
				virtual const char* what() const throw();
			// 	{
			// 		return (_name + ", bureaucrat grade" + Log::itoa(_grade)).c_str();
			// 	}
			// private:

			// 	const std::string _name;
			// 	unsigned int _grade;

		};

		class GradeTooLowException : public std::exception
		{
			public:

				// GradeTooLowException(const std::string& name, unsigned int grade) :
				// 	_name(name), _grade(grade) {}
				virtual const char* what() const throw();
			// 	{
			// 		return (_name + ", bureaucrat grade" + Log::itoa(_grade)).c_str();
			// 	}
			// private:

			// 	const std::string _name;
			// 	unsigned int _grade;

		};

	private:

		const std::string _name;
		unsigned int 			_grade;
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& rhs );

#endif

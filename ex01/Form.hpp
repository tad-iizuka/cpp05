/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:26:56 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/17 13:06:23 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Form
{

	public:

		const std::string getName( void ) const;
		bool							getStatus( void ) const;
		int								getSign( void ) const;
		int								getExec( void ) const;
		void							beSigned(const Bureaucrat& param);

		Form( const std::string name, int sign, int exec );
		~Form ( void );

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

		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;
		static const int DEFAULT_SIGN_GRADE = 1;
		static const int DEFAULT_EXEC_GRADE = 1;

		Form( void );
		Form( const Form& src); 						// can't use
		Form& operator=( const Form& rhs );	// can't use

		const std::string _name;
		bool							_status;
		const int 				_sign;
		const int					_exec;

};

std::ostream& operator<<( std::ostream& os, const Form& rhs );

#endif

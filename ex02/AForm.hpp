/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:11:26 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/16 20:40:16 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class AForm
{

	public:

		const std::string getName( void ) const;
		bool							getStatus( void );
		int								getSign( void ) const;
		int								getExec( void ) const;
		void							beSigned(const Bureaucrat& executor);
		virtual void			execute(const Bureaucrat& executor) const = 0;

		AForm( const std::string name, int sign, int exec );
		virtual ~AForm ( void );

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
		
	protected:

		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;
		static const int DEFAULT_SIGN_GRADE = 1;
		static const int DEFAULT_EXEC_GRADE = 1;

		AForm( void );
		AForm( const AForm& src); 						// can't use
		AForm& operator=( const AForm& rhs );	// can't use

		const std::string _name;
		bool							_status;
		const int 				_sign;
		const int					_exec;

};

std::ostream& operator<<( std::ostream& os, const AForm& rhs );

#endif

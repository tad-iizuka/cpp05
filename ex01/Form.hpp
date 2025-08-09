/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:26:56 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/09 13:23:46 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{

	public:

		const std::string getName( void ) const;
		bool							getSigned( void );
		int								getGradeForSign( void );
		int								getGradeForExecute( void );
		void							beSigned(Bureaucrat& param);
	
		Form( const std::string& name, const int grade );
		~Form ( void );

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(const std::string& name, int grade);
				~GradeTooHighException ( void ) throw();
				virtual const char* what() const throw();
				virtual int					grade( void ) const;
			private:
				std::string _name;
				int					_grade;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(const std::string& name, int grade);
				~GradeTooLowException ( void ) throw();
				virtual const char* what() const throw();
				virtual int					grade( void ) const;
			private:
				std::string _name;
				int					_grade;
		};
		
	private:

		Form( void );
		const std::string _name;
		bool							_signed;
		const int 				_grade;

};

std::ostream& operator<<( std::ostream& os, const Form& rhs );

#endif

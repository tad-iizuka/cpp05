/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:07:13 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/20 20:33:09 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdio>

// Font color
#define C_CLR "\033[0m"
#define C_R "\033[31m"	// Red
#define C_G "\033[32m"	// Green
#define C_B "\033[34m"	// Blue
#define C_Y "\033[33m"	// Yellow
#define C_M "\033[35m"	// Magenta
#define C_W "\033[37m"	// White
#define C_BL "\033[30m"	// Black
#define C_CY "\033[36m"	// Cyan

// Background color
#define CB_R "\033[41m"	// Red
#define CB_G "\033[42m"	// Green
#define CB_B "\033[44m"	// Blue
#define CB_Y "\033[43m"	// Yellow
#define CB_M "\033[45m"	// Magenta
#define CB_W "\033[47m"	// White
#define CB_BL "\033[40m"	// Black
#define CB_CY "\033[46m"	// Cyan

// Font style
#define S_BOLD "\033[1m"	// Bold
#define S_ULINE "\033[4m"	// Underline

#define F __FILE__
#define L __LINE__

class Log
{
	public:

		static std::string itoa(int num);
		static std::string ptoa(void* ptr);	
		static void	a(const char* file, int line, const char* color, std::string s1,
			std::string s2, std::string s3, std::string s4, std::string s5);	
		static void	a(const char* file, int line, const char* color, std::string s1,
			std::string s2, std::string s3, std::string s4);
		static void	a(const char* file, int line, const char* color, std::string s1,
			std::string s2, std::string s3);
		static void	a(const char* file, int line, const char* color, std::string s1,
			std::string s2);
		static void	a(const char* file, int line, const char* color, std::string s1);
		static std::string	m(const char* file, int line, const char* color,
			std::string s1, std::string s2, std::string s3, std::string s4);
		static std::string	m(const char* file, int line, const char* color,
			std::string s1, std::string s2, std::string s3);
		static std::string	m(const char* file, int line, const char* color,
			std::string s1, std::string s2);
		static std::string	m(const char* file, int line, const char* color,
			std::string s1);
};

#endif

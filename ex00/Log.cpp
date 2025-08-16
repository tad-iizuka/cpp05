/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:07:13 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/16 17:26:09 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Log.hpp"

void	Log::a(const char *file, int line, const char *color, std::string s1,
	std::string s2, std::string s3, std::string s4, std::string s5) {
	std::cout
		<< file << ":"
		<< line << " "
		<< color
		<< s1 << " "
		<< s2 << " "
		<< s3 << " "
		<< s4 << " "
		<< s5
		<< C_CLR << std::endl;
}

void	Log::a(const char *file, int line, const char *color, std::string s1,
	std::string s2, std::string s3, std::string s4) {
	std::cout
		<< file << ":"
		<< line << " "
		<< color
		<< s1 << " "
		<< s2 << " "
		<< s3 << " "
		<< s4
		<< C_CLR << std::endl;
}

void	Log::a(const char *file, int line, const char *color, std::string s1,
	std::string s2, std::string s3) {
	std::cout
		<< file << ":"
		<< line << " "
		<< color
		<< s1 << " "
		<< s2 << " "
		<< s3
		<< C_CLR << std::endl;
}

void	Log::a(const char *file, int line, const char *color, std::string s1,
	std::string s2) {
	std::cout
		<< file << ":"
		<< line << " "
		<< color
		<< s1 << " "
		<< s2
		<< C_CLR << std::endl;
}

void	Log::a(const char *file, int line, const char *color, std::string s1) {
	std::cout
		<< file << ":"
		<< line << " "
		<< color
		<< s1
		<< C_CLR << std::endl;
}

std::string Log::itoa(int num)
{
	std::stringstream ss;
	ss << num;
	return ss.str();
}

std::string Log::ptoa(void* ptr) {
    char buf[32];
    sprintf(buf, "0x%lx", (unsigned long)ptr);
    return std::string(buf);
}

std::string Log::m(const char *file, std::string line, std::string color,
	std::string s1, std::string s2, std::string s3, std::string s4)
{
	std::string str;
	str = static_cast<std::string>(file) + ":" + line + " " + color;
	str += "Exception#";
	str += " [" + s1 + "]";
	str += " [" + s2 + "]";
	str += " [" + s3 + "]";
	str += " [" + s4 + "]";
	str += C_CLR;
	str += "\n";
	return str;
}

std::string Log::m(const char *file, std::string line, std::string color,
	std::string s1, std::string s2, std::string s3)
{
	std::string str;
	str = static_cast<std::string>(file) + ":" + line + " " + color;
	str += "Exception";
	str += " [" + s1 + "]";
	str += " [" + s2 + "]";
	str += " [" + s3 + "]";
	str += C_CLR;
	str += "\n";
	return str;
}

std::string Log::m(const char *file, std::string line, std::string color,
	std::string s1, std::string s2)
{
	std::string str;
	str = static_cast<std::string>(file) + ":" + line + " " + color;
	str += "Exception#";
	str += " [" + s1 + "]";
	str += " [" + s2 + "]";
	str += C_CLR;
	str += "\n";
	return str;
}

std::string Log::m(const char *file, std::string line, std::string color,
	std::string s1)
{
	std::string str;
	str = static_cast<std::string>(file) + ":" + line + " " + color;
	str += "Exceptiona#";
	str += " [" + s1 + "]";
	str += C_CLR;
	str += "\n";
	return str;
}


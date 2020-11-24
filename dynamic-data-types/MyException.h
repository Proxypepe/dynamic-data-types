#pragma once
#include <exception>

class MyException : public std::exception
{
public:
	const char* out_of_range() const throw()
	{
		return "Out of range";
	}

};
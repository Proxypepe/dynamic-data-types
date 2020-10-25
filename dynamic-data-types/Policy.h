#pragma once

#include <iostream>
#include <string>
//
class Policy
{
private:
	int number;																	 
	std::string company;												
	std::string surname;												

public:
	Policy();																	
	Policy(int number, std::string company, std::string surname);

	void initByInput();															
	void init(int number, std::string company, std::string surname);		
	void printFullData();													
	void setNumber(int number);											
	void setCompany(std::string company);									
	void setSurname(std::string surname);										

	int getNumber();														
	std::string getCompany();												
	std::string getSurname();												

	friend std::ostream& operator<<(std::ostream& out, const Policy& arg);

};
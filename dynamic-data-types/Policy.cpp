#include "Policy.h"

Policy::Policy()
{
	number = 0;
	company = "";
	surname = "";
}

Policy::Policy(int number, std::string company, std::string surname)
{
	this->number = number;
	this->company = company;
	this->surname = surname;
}


void Policy::initByInput()
{
	std::cout << "Enter number: ";
	std::cin >> number;
	std::cout << "Enter company: ";
	std::cin >> company;
	std::cout << "Enter surname: ";
	std::cin >> surname;
}

void Policy::init(int number, std::string company, std::string surname)
{
	std::cout << "U entered number: " << number << "\n";
	this->number = number;
	std::cout << "U entered company: " << company << "\n";
	this->company = company;
	std::cout << "U entered surname: " << surname << "\n";
	this->surname = surname;
}
void Policy::printFullData()
{
	std::cout << "number: " << number << "\n";
	std::cout << "company: " << company << "\n";
	std::cout << "surnmae: " << surname << "\n";
}

void Policy::setNumber(int number)
{
	this->number = number;
}

void Policy::setCompany(std::string company)
{
	this->company = company;
}

void Policy::setSurname(std::string surname)
{
	this->surname = surname;
}

int Policy::getNumber()
{
	return this->number;
}

std::string Policy::getCompany()
{
	return this->company;
}

std::string Policy::getSurname()
{
	return this->surname;
}



std::ostream& operator<<(std::ostream& out, const Policy& arg)
{
	out << "number = " << arg.number << "\n" << "company = " << arg.company << "\n" << "surname = " << arg.surname << "\n";
	return out;
}

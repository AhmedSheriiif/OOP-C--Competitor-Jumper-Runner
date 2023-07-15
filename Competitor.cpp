#include "Competitor.h"
#include <typeinfo>
#include <stdexcept>

Competitor::Competitor(std::string name, int startNr)
{
	this->name = name;
	this->startNr = startNr;

}

Competitor::~Competitor()
{
}

int Competitor::getStartNr() const
{

	return startNr;

}

bool Competitor::operator<(const Competitor& other) const
{
	if (typeid(*this) != typeid(other))
	{
		throw std::runtime_error("Different subtyp of objects");
	}

	return resultToCompare() < other.resultToCompare();

}

bool Competitor::operator>(const Competitor& other) const
{
	if (typeid(*this) != typeid(other))
	{
		throw std::runtime_error("Different subtyp of objects");
	}

	return resultToCompare() > other.resultToCompare();

}

std::string Competitor::toStringCommon() const
{
	/*
	return a string containing name and start number. A competitor with the name James Smith and the start number 123
	the string is
	"Name: James Smith
	 Start number: 123"
	*/
	std::string out = "Name: " + name + "\n";
	out += "Start number: " + std::to_string(startNr);

	return out;
}
#include "Runner.h"

Runner::Runner(std::string name, int startNr) : Competitor(name, startNr)
{
	this->raceTime = 0.0;

}

Runner& Runner::operator=(const Runner& other)
{

	// ...
	Competitor::operator=(other);
	this->raceTime = other.raceTime;
	return *this;
}

double Runner::getRaceTime() const
{
	return raceTime;
}

std::string Runner::toString() const
{
	/*
	 return a string containing name, startnumber and also race time if it has been registered
	 For a runner with the name Allan Red and the start number 111 before race time has been registered
	 "Name: Allan Red
	 Start number: 111"
	 and after the race time 12.35 has been registered
	 "Name: Allan Red
	 Start number: 111
	 Race time: 12.35"
	 It is required to use toStringCommon()
	*/

	std::string out = toStringCommon();
	if (raceTime > 0)
		out += "\nRace time: " + std::to_string(raceTime);

	return out;
}

void Runner::addResult(double raceTime)
{
	this->raceTime = raceTime;
}

Runner* Runner::clone()
{
	// allocate memory on the heap for an identical copy of the object
	// ...
	return new Runner(*this);
}

double Runner::resultToCompare() const
{
	return getRaceTime();
}
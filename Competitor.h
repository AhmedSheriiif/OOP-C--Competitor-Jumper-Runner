#ifndef COMPETITOR_H
#define COMPETITOR_H
#include<string>

class Competitor
{
private:
	std::string name;
	int startNr;
protected:
	std::string toStringCommon() const;
	virtual double resultToCompare() const = 0;
public:
	Competitor(std::string name = "", int startNr = -1);
	Competitor(const Competitor& other) = default;
	Competitor& operator=(const Competitor& other) = default;
	virtual~Competitor();

	int getStartNr() const;

	virtual void addResult(double result) = 0;
	virtual std::string toString() const = 0;
	virtual Competitor* clone() = 0;

	bool operator<(const Competitor& other) const;
	bool operator>(const Competitor& other) const;

};
#endif

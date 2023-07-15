#ifndef JUMPER_H
#define JUMPER_H
#include"Competitor.h"
class Jumper :public Competitor
{
private:
	int totalNrOfJumps;
	int madeJumps;
	double *jumpResult;
protected:
	virtual double resultToCompare() const override;
public:
	Jumper(std::string name, int startNr, int totalNrOfJumps);
	Jumper(const Jumper& other);
	Jumper& operator=(const Jumper& other);
	~Jumper();

	double bestJumpResult()const;

	virtual std::string toString() const override;
	virtual void addResult(double jumpLength) override;
	virtual Jumper* clone() override;

	double* getJumpResult() const; // for testing only
};
#endif
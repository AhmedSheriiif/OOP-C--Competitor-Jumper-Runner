#ifndef RUNNER_H
#define RUNNER_H
#include"Competitor.h"
class Runner :public Competitor
{
private:
	double raceTime;
protected:
	virtual double resultToCompare() const override;
public:
	Runner(std::string name, int startNr);
	Runner(const Runner& other) = default;
	Runner& operator=(const Runner& other);
	~Runner() = default;

	double getRaceTime()const;

	virtual std::string toString() const override;
	virtual void addResult(double raceTime) override;
	virtual Runner* clone() override;
};
#endif
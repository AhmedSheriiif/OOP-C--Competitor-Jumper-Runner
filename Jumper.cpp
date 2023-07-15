#include "Jumper.h"


Jumper::Jumper(std::string name, int startNr, int totalNrOfJumps) : Competitor(name, startNr)
{
    this->totalNrOfJumps = totalNrOfJumps;
    this->madeJumps = 0;

    jumpResult = new double[totalNrOfJumps];
    for (int i = 0; i < totalNrOfJumps; i++)
    {
        jumpResult[i] = 0.0;
    }

}

Jumper::Jumper(const Jumper& other) : Competitor(other)
{
    totalNrOfJumps = other.totalNrOfJumps;
    madeJumps = other.madeJumps;
    jumpResult = new double[totalNrOfJumps];
    for (int i = 0; i < totalNrOfJumps; i++)
    {
        jumpResult[i] = other.jumpResult[i];
    }


}


Jumper& Jumper::operator=(const Jumper& other)
{
    Competitor::operator=(other);
    totalNrOfJumps = other.totalNrOfJumps;
    madeJumps = other.madeJumps;
    delete[] jumpResult;
    jumpResult = new double[totalNrOfJumps];
    for (int i = 0; i < totalNrOfJumps; i++)
    {
        jumpResult[i] = other.jumpResult[i];
    }

    return *this;
}

Jumper::~Jumper()
{
    delete[] jumpResult;
}

double Jumper::bestJumpResult() const
{
    double bestJump = jumpResult[0];
    for (int i = 1; i < madeJumps; i++)
    {
        if (jumpResult[i] > bestJump)
            bestJump = jumpResult[i];
    }
    return bestJump;
}

std::string Jumper::toString() const
{
    /*
     returns a string containing name, startnumber and if jump results has been registerd also these results
     For a jumper with the name Berry Brown and the start number 333 before results has been registerd
     "Name: Berry Brown
     Start number: 333"
     and after the jump results 5.34 and 6.21 has been registered
     "Name: Berry Brown
     Start number: 333
     Jump 1: 5.34
     Jump 2: 6.21"
     It is required to use toStringCommon()
    */
    std::string out = toStringCommon();
    for (int i = 0; i < madeJumps; i++)
    {
        std::string jump_out = "\nJump " + std::to_string(i + 1) + ": " + std::to_string(jumpResult[i]);
        out += jump_out;
    }

    return out;
}

void Jumper::addResult(double jumpLength)
{
    if (madeJumps < totalNrOfJumps)
    {
        jumpResult[madeJumps] = jumpLength;
        madeJumps++;
    }
}

Jumper* Jumper::clone()
{
    return new Jumper(*this);
}

double Jumper::resultToCompare() const
{
    return bestJumpResult();
}

double* Jumper::getJumpResult() const
{
    return jumpResult;
}


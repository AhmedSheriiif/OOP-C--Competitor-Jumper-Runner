#include "CompetitorHandler.h"

CompetitorHandler::CompetitorHandler()
{
}

CompetitorHandler::~CompetitorHandler()
{
    for (Competitor*& comp : competitorsVect)
    {
        delete comp;
    }

}

CompetitorHandler::CompetitorHandler(const CompetitorHandler& other)
{
    for (Competitor* comp : other.competitorsVect)
    {
        competitorsVect.push_back(comp->clone());
    }

}

CompetitorHandler& CompetitorHandler::operator=(const CompetitorHandler& other)
{
    if (this != &other)
    {

        for (Competitor* comp : competitorsVect)
        {
            delete comp;
        }
        competitorsVect.clear();

        for (Competitor* comp : other.competitorsVect)
        {
            competitorsVect.push_back(comp->clone());
        }
    }
    return *this;
}

void CompetitorHandler::addCompetitor(Competitor* comp)
{
    competitorsVect.push_back(comp);

}

bool CompetitorHandler::registerResult(int startNr, double result)
{
    for (Competitor*& comp : competitorsVect)
    {
        if (comp->getStartNr() == startNr)
        {
            comp->addResult(result);
            return true;
        }
    }
    return false;
}

bool CompetitorHandler::removeCompetitor(int startNr)
{
    for (std::vector<Competitor*>::iterator it = competitorsVect.begin(); it != competitorsVect.end(); ++it) {
        if ((*it)->getStartNr() == startNr) {
            delete* it;
            competitorsVect.erase(it);
            return true;
        }
    }

    return false;
}

Competitor* CompetitorHandler::competitor(int startNr)
{
    for (Competitor*& comp : competitorsVect)
    {
        if (comp->getStartNr() == startNr) {
            return comp;
        }
    }
    return nullptr;
}

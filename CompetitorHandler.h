#ifndef COMPETITORHANDLER_H
#define COMPETITORHANDLER_H
#include"Competitor.h"
#include <vector>
#include<string>

enum WINNER_BASED_ON { MIN_RESULT = 0, MAX_RESULT = 1 };

class CompetitorHandler
{
private:
    std::vector<Competitor*> competitorsVect;
public:
    CompetitorHandler();
    ~CompetitorHandler();
    CompetitorHandler(const CompetitorHandler& other);
    CompetitorHandler& operator=(const CompetitorHandler& other);

    void addCompetitor(Competitor* comp);
    bool registerResult(int startNr, double result);
    bool removeCompetitor(int startNr);

    Competitor* competitor(int startNr); // used for testing

    template<typename T> void competitorsAsStrings(std::vector<std::string>& compVect)const;
    template <typename T> int getNrOf() const;
    template <typename T> std::string  getWinnerAsString(WINNER_BASED_ON based_on);
};




template<typename T>
inline void CompetitorHandler::competitorsAsStrings(std::vector<std::string>& compVect) const
{
    // fills parameter compVect with the result of toString() for all objects of type T
    compVect.clear();
    for (Competitor* comp : competitorsVect)
    {
        T* t = dynamic_cast<T*>(comp);
        if (t != nullptr)
        {
            compVect.push_back(comp->toString());
        }
    }
}


template<typename T>
inline int CompetitorHandler::getNrOf() const
{
    // calculates and returns the number of object of type T
    // ...
    int counter = 0;
    for (Competitor* comp : competitorsVect)
    {
        if (dynamic_cast<T*>(comp) != nullptr)
            counter++;
    }
    return counter;
}

template<typename T>
inline std::string CompetitorHandler::getWinnerAsString(WINNER_BASED_ON based_on) {
    T* winner = nullptr;
    for (Competitor* comp : competitorsVect) {
        T* t = dynamic_cast<T*>(comp);
        if (t != nullptr && (winner == nullptr || (based_on == MIN_RESULT && *t < *winner) ||
            (based_on == MAX_RESULT && *t > *winner))) {
            winner = t;
        }
    }
    if (winner != nullptr)
        return winner->toString();
    else
        return "";
}


#endif
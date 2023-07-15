#include "CompetitorHandler.h"
#include "Runner.h"
#include "Jumper.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    CompetitorHandler ch;

    ch.addCompetitor(new Runner("R1", 101));
    ch.addCompetitor(new Jumper("J1", 201, 3));
    ch.addCompetitor(new Jumper("J2", 202, 3));
    ch.addCompetitor(new Runner("R2", 102));
    ch.addCompetitor(new Jumper("J3", 203, 3));
    ch.addCompetitor(new Runner("R3", 103));
    ch.addCompetitor(new Runner("R4", 104));


    std::vector<std::string> jumpers;
    std::vector<std::string> runners;
    std::vector<std::string> competitors;

    ch.competitorsAsStrings<Competitor>(competitors);
    for (auto str : competitors)
    {
        std::cout << str << std::endl;
    }

    std::cout << std::endl << std::endl;
    competitors.clear();

    ch.competitorsAsStrings<Jumper>(jumpers);
    for (auto str : jumpers)
        std::cout << str << std::endl;
    jumpers.clear();

    std::cout << std::endl << std::endl;
    ch.competitorsAsStrings<Runner>(runners);
    for (auto str : runners)
        std::cout << str << std::endl;
    runners.clear();

    ch.registerResult(101, 67.8);
    ch.registerResult(102, 57.8);
    ch.registerResult(103, 77.1);
    ch.registerResult(104, 62.3);

    std::string winner = ch.getWinnerAsString<Runner>(WINNER_BASED_ON::MIN_RESULT);
    std::cout << "Winner is " << winner << std::endl;

    if (!ch.removeCompetitor(103))
        std::cout << "Competitor 103 was not removed??" << std::endl;

    // ... and so on

    std::cout << std::endl << std::endl;

    return 0;
}

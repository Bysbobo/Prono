#ifndef TEAMSTATISTICS_H
#define TEAMSTATISTICS_H

#include "team.h"

/**
 * @brief The TeamStatistics class implements the statistics of a team in a league.
 */
class TeamStatistics
{
public:
    TeamStatistics(const Team& team);

private:
    /**
     * @brief aTeam : The team which caracteristics should be determined.
     */
    const Team aTeam;

};

#endif // TEAMSTATISTICS_H

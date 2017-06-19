#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QDebug>

#include "league.h"

bool League::isTeamAvailable(const QString &teamName) const
{
    const int size = aTeams.size();
    for (int i = 0; i < size; ++i)
        if (aTeams.at(i).getFullName() == teamName || aTeams.at(i).getShortName() == teamName)
            return true;
    return false;
}

bool League::retrieveTeamsFromFile(const QString &fileName)
{
    // Read and stock all clubs
    QFile teamFlow(fileName);
    if (!teamFlow.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Cannot open file " << fileName;
        return false;
    }

    QTextStream in(&teamFlow);

    // Retrieve teams information
    while (!in.atEnd()) {
        const QString line = in.readLine();
        if (line != QString(""))
        {
            const QStringList infos = line.split(QString(" "));
            aTeams.push_back(Team(infos.at(0), infos.at(1)));
        }
    }

    return true;
}

bool League::retrieveMatchsFromFile(unsigned int untilThisJourney)
{
    Q_UNUSED(untilThisJourney);
    // Read and stock all matches
    /*QString firstTeam, secondTeam;
    unsigned int firstScore, secondScore;
    QFile matchFlow(MATCHS);
    if (!matchFlow.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Cannot open file " << MATCHS;
        return false;
    }

    QTextStream in(&matchFlow);

    unsigned int journeyNumberTreated = 0, test = 1;
    untilThisJourney = ((untilThisJourney < 10) ? 10 : untilThisJourney);
    QString line;
    while (getline(matchFlow, line, '\n') && ++journeyNumberTreated <= untilThisJourney)
    {
        istringstream iss(line);
        string aString;
        int count(-1);
        while (getline(iss, aString, '/'))
        {
            count++;
            if (count == 0 || count == 1)
                continue;

            switch (count % 4)
            {
                case 2:
                {
                    firstTeam   =  aString;
                    cout << "N." << test++ << " - " << firstTeam << " ";
                    break;
                }
                case 3:
                {
                    firstScore  = atol(aString.c_str());
                    cout << firstScore << " - ";
                    break;
                }
                case 0:
                {
                    secondScore = atol(aString.c_str());
                    cout << secondScore << " ";
                    break;
                }
                case 1:
                {
                    secondTeam  =  aString;
                    cout << secondTeam << endl;
                    // For each line, have to save collected datas
                    vector<Team>::iterator itVect = _vectorOfTeams.begin();
                    for (; itVect != _vectorOfTeams.end(); ++itVect)
                    {
                        if (itVect->getShortName() == firstTeam)
                        {
                            if (firstScore == secondScore) itVect->addPointsForRanking(1);
                            if (firstScore >  secondScore) itVect->addPointsForRanking(3);
                            itVect->updateGoals(firstScore, secondScore);
                            itVect->updateMatchCounter();
                        }
                        if (itVect->getShortName() == secondTeam)
                        {
                            if (secondScore == firstScore) itVect->addPointsForRanking(1);
                            if (secondScore >  firstScore) itVect->addPointsForRanking(3);
                            itVect->updateGoals(secondScore, firstScore);
                            itVect->updateMatchCounter();
                        }
                    }
                    _vectorOfMatchs.push_back(Match(stringToTeam(firstTeam), stringToTeam(secondTeam), firstScore, secondScore));
                }
            }
        }
    }

    sort(_vectorOfTeams.begin(), _vectorOfTeams.end());
    reverse(_vectorOfTeams.begin(), _vectorOfTeams.end());

    updateRanking();

    matchFlow.close();*/

    return true;
}

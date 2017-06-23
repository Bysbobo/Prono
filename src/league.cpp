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

int League::getTeamIndex(const QString& teamName) const
{
    const int size = aTeams.size();
    for (int i = 0; i < size; ++i)
        if (aTeams.at(i).getFullName() == teamName || aTeams.at(i).getShortName() == teamName)
            return i;
    return -1;
}

bool League::retrieveTeamsFromFile(const QString &fileName)
{
    // Open file
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

bool League::retrieveMatchsFromFile(const QString& fileName)
{
    // Open file
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Cannot open file " << fileName;
        return false;
    }

    QTextStream in(&file);

    // Retrieve teams information
    uint8_t i=0;
    uint8_t day;
    while (!in.atEnd()) {
        const QString line = in.readLine();

        if (line != QString(""))
        {
            if (i % 2 == 0) // Retrieve the day of the matches
            {
                const QStringList infos = line.split(QString(" "));
                day = infos.at(1).toInt();
            } else { // Retrieve the matches of the day
                const QStringList matches = line.split(QString(";"));
                const int nbMatches = matches.size();
                for (int j = 0; j < nbMatches; ++j)
                {
                    // Create the match
                    const QStringList infos = matches.at(j).split(QString(" "));
                    const Match m(QString("2016-2017"), day, infos.at(0), infos.at(3), infos.at(1).toInt(), infos.at(2).toInt());

                    // Add the match to the match list of the league
                    aMatches.push_back(m);

                    // Add the match to the teams involved in it
                    aTeams[getTeamIndex(infos.at(0))].addMatch(m);
                    aTeams[getTeamIndex(infos.at(3))].addMatch(m);
                }
            }
            ++i;
        }
    }

    return true;
}

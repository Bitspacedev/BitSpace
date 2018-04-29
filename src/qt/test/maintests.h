#ifndef MAINTESTS_H
#define MAINTESTS_H


#include <QTest>
#include <QObject>

#include "../../wallet.h"
#include "../../main.h"

class MainTests : public QObject
{
    Q_OBJECT

private slots:
    void testGetProofOfWorkReward();
    void testGetProofOfStakeReward();
};

#endif // MAINTESTS_H

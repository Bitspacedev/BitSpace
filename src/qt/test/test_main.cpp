#include <QTest>
#include <QObject>

#include "maintests.h"

// This is all you need to run all the tests
int main(int argc, char *argv[])
{
    bool fInvalid = false;

    MainTests test1;
    if (QTest::qExec(&test1) != 0)
        fInvalid = true;

    return fInvalid;
}

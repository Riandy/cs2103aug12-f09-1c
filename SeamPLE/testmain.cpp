#include "UnitTest.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    int retval(0);

    retval += QTest::qExec(&UnitTest(), argc, argv);
    // Add more test like above here

    return (retval ? 1 : 0);
}

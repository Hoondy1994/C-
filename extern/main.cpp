#include <QCoreApplication>
#include <iostream>

#include "testB.h"
#include "testA.h"

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    main1();
    cout<<"hello world"<<endl;

    return a.exec();
}

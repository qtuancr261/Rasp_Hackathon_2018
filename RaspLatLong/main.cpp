#include <QCoreApplication>
#include "hackathoncommunityapi.h"
#include <cstdlib>
#include <itead.h>
#include "uartportapi.h"
#define STATUS_LED1 GPIO10
using std::cin;
using std::cout;
using std::endl;
void setup(void)
{
    printf("setup begin\n");
    pinMode(STATUS_LED1, OUTPUT);
}
void loop(void)
{
    digitalWrite(STATUS_LED1,HIGH);
    delay(1000);
    digitalWrite(STATUS_LED1,LOW);
    delay(1000);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    HackathonCommunityAPI CommunityAPI{QString("hackathon.documents.asia")};
    UARTPortAPI uartPort{};
    QObject::connect(&uartPort, SIGNAL(locationChanged(int)), &CommunityAPI, SLOT(updateByLocation(int)));
    /*QStringList listLocation;
    listLocation.append("10.8076523|106.6624106");
    listLocation.append("10.8477678|106.7721297");
    listLocation.append("10.801043|106.658754");
    listLocation.append("10.803047|106.708597");
    listLocation.append("10.792292|106.704957");
    listLocation.append("10.8076261|106.6634687");
    for (QString location: listLocation)
        CommunityAPI.updateLatLongRasp(location);*/
    //cout << "Press any key to exit " << endl;
    return a.exec();
}

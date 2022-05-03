#include "widget.h"
#include <QApplication>
#include <QResource>
#include "config.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QResource::registerResource(GAME_MEDIA);


    Widget w;
    w.show();
    return a.exec();
}

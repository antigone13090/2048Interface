#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <game2048.h>
#include <time.h>
#include <QtQml>
#include <initiator.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);  // instance the class QApplication in app
    Game2048 exec;  // instance the class Game2048 in exec

    srand(time(NULL));
    Initiator initiator;  // instance the class Initiator
    initiator.init(exec.grid,exec.score,exec.max);  // call the method init of the class Inititor

    QQmlApplicationEngine engine;  // instance the class QApplicationEngine in engine
    engine.rootContext()->setContextProperty("grid",(&exec));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}

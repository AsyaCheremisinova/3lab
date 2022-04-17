#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <starlist.h>
#include <QQmlContext>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    StarList viewModel;

    QQmlApplicationEngine engine;

    QQmlContext *context = engine.rootContext();
    context->setContextObject(&viewModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

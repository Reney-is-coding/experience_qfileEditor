#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


#include "../include/textModel.h"

int main ( int argc, char** argv )
{
    QGuiApplication app ( argc, argv );

    QQmlApplicationEngine engine;

    TextModel *textmodel = new TextModel();


    engine.rootContext()->setContextProperty("textModel", textmodel);
    engine.load ( QUrl ( QStringLiteral ( "qrc:/qml/main.qml" ) ) );
    return app.exec();
}

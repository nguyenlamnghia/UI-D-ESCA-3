#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQuickView view;
    view.engine()->addImportPath("qrc:/UI/imports");
//    view.setSource(QUrl("qrc:/UI/content/Screen01.ui.qml"));
    view.setSource(QUrl("qrc:/UI/content/Adjustment_screen.qml"));
    if (!view.errors().isEmpty())
        return -1;
    view.show();

    return app.exec();
}

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "trafficlightbutton.h"
#include "trafficwalk.h"
#include "walksign.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    auto root_context = engine.rootContext();

    qmlRegisterUncreatableType<TrafficWalk>("TrafficWalkModule",1,0,"TrafficWalk","do not instantiate");
    qmlRegisterUncreatableType<WalkSign>("WalkSignModule",1,0,"WalkSign","do not instantiate");
    qmlRegisterUncreatableType<TrafficLightButton>("TrafficLightButton",1,0,"TrafficButton","do not instantiate");

    TrafficLightButton trafficLightButton;
    root_context->setContextProperty("trafficLightButton", &trafficLightButton);

    WalkSign walkSign;
    root_context->setContextProperty("walkSign", &walkSign);

    TrafficWalk trafficWalk(&walkSign, &trafficLightButton);
    root_context->setContextProperty("trafficWalk", &trafficWalk);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}

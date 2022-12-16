#include <QtTest>
#include "../objects/objects.h"

// add necessary includes here

class test_lb : public QObject
{
    Q_OBJECT

public:
    test_lb();
    ~test_lb();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
};

test_lb::test_lb()
{

}

test_lb::~test_lb()
{

}

void test_lb::test_case1()
{
    Sedan sedan;
    QVERIFY(!sedan.drive(100));
    QCOMPARE(sedan.getFuelLevel(), 0);
    sedan.refuel();
    QCOMPARE(sedan.getFuelLevel(), 50000);
    QVERIFY(sedan.drive(100));
    QCOMPARE(sedan.getMilage(), 100);
    QCOMPARE(sedan.getFuelLevel(), 43000);
    QVERIFY(sedan.drive(500));
    QCOMPARE(sedan.getMilage(), 600);
    QCOMPARE(sedan.getFuelLevel(),8000);
    sedan.refuel();
    QCOMPARE(sedan.getFuelLevel(),50000);
    QVERIFY(!sedan.drive(1000));
    QCOMPARE(sedan.getMilage(), 600);
    QCOMPARE(sedan.getFuelLevel(), 50000);
}
void test_lb::test_case2(){
    Bicycle bicycle;
    QVERIFY(bicycle.drive(0));
    QCOMPARE(bicycle.getMilageBicycle(), 0);
    QVERIFY(bicycle.drive(50));
    QCOMPARE(bicycle.getMilageBicycle(), 50);
    QVERIFY(bicycle.drive(1000));
    QCOMPARE(bicycle.getMilageBicycle(), 1050);
    QVERIFY(bicycle.drive(10000));
    QCOMPARE(bicycle.getMilageBicycle(), 11050);
}
void test_lb::test_case3(){
    Route route;
    RoutePoint routepoint;
    Suv suv;
    QVERIFY(!route.run(&suv));
    routepoint.xKm = 0;
    routepoint.yKm = 0;
    routepoint.name = "point_1";
    route.addPoint(routepoint);
    QVERIFY(!route.run(&suv));
    routepoint.xKm = 3;
    routepoint.yKm = 4;
    routepoint.name = "point_2";
    route.addPoint(routepoint);
    QVERIFY(route.run(&suv));
    routepoint.xKm = 100;
    routepoint.yKm = 100;
    routepoint.name = "point_3";
    route.addPoint(routepoint);
     QCOMPARE(suv.getFuelLevel(), 79300);
    QVERIFY(route.run(&suv));
    QCOMPARE(route.getTravel(), 136);
    QCOMPARE(suv.getMilage(), 146);
    QCOMPARE(suv.getFuelLevel(), 59560);
}

QTEST_APPLESS_MAIN(test_lb)

#include "tst_test_lb.moc"

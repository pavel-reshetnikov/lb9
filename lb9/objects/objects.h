#ifndef OBJECTS_H
#define OBJECTS_H
#include <iostream>
#include <clocale>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
using namespace std;

class Objects
{
public:
    Objects();
};
class IVehicle
{
public:
    virtual bool drive(int kilometers)=0;
    virtual void refuel()=0;
    virtual void printStatus()=0;

};
class AbstractCar : public IVehicle
{
public:
    int tank;
    int fuelrate;
    int fuel;
    int mileage;
    bool drive(int kilometres);
    void refuel();
    void printStatus();
    double getFuelLevel();
    double getMilage();
};
class Sedan : public AbstractCar{public: Sedan();};
class Bus : public AbstractCar{public: Bus();};
class Suv : public AbstractCar { public: Suv();};

class Bicycle : public IVehicle
{
    int mileage;
public:
    Bicycle();
    bool drive(int kilometres);
    void refuel();
    void printStatus();
    float getMilageBicycle();
};
struct RoutePoint
{
    int xKm = 0;
    int yKm = 0;
    string name;
};

class Route
{

public:
    int travel;
    vector<RoutePoint> vpoint;
    void addPoint(const RoutePoint& point);
    bool run(IVehicle* vehicle);
    int getTravel();
};

#endif // OBJECTS_H

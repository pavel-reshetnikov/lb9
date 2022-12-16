#include "objects.h"

Objects::Objects()
{
}
bool AbstractCar::drive(int kilometres)
{

    if (fuel >= fuelrate * kilometres) {
        fuel = fuel - fuelrate * kilometres;
        cout << "Passed " << kilometres << " km" << endl;
        mileage += kilometres;
        return true;
    }
    else {
        cout << "Dont have fuel " << endl;
        return false;
    }

};
void AbstractCar::refuel()
{
    fuel = tank; cout << "You refueled " << endl;
};
void AbstractCar::printStatus()
{
    cout << "Fuel: " << fuel / 1000 << "/" << tank / 1000 << " ";
    cout << "Mileage: " << mileage << " km" << endl;
};
Sedan::Sedan()
{
    tank = 50000;
    fuelrate = 70;
    fuel = 0;
    mileage = 0;
}
Bus::Bus()
{
    tank = 100000;
    fuelrate = 190;
    fuel = 0;
    mileage = 0;
}
Suv::Suv()
{
    tank = 80000;
    fuelrate = 140;
    fuel = 0;
    mileage = 0;
}
Bicycle::Bicycle(){ mileage = 0;}
bool Bicycle::drive(int kilometres)
{
    cout << "Passed " << kilometres << " km" << endl;
    mileage += kilometres;
    return true;
};
void Bicycle::refuel() { cout << "The bike can't be refueled" << endl; };

    void Bicycle::printStatus()
    {
        cout << "Mileage: " << mileage << "km" << endl;
    };

    void Route::addPoint(const RoutePoint& point)
    {
        vpoint.push_back(point);

    };
    bool Route::run(IVehicle* vehicle)
    {
        travel = 0;
        if (vpoint.size() < 2)
        {
            cout << "Add more than 1 waypoint"<< endl;
            return false;
        }
        else
        {

            for (int i = 1; i < vpoint.size(); i++)
            {
                travel = sqrt(pow(vpoint[i].xKm - vpoint[i - 1].xKm, 2) + pow(vpoint[i].yKm - vpoint[i - 1].yKm, 2));
                if (vehicle->drive(travel) == true)
                {
                    cout << "You have passed from the point '" << vpoint[i - 1].name << "' to the point '" << vpoint[i].name << "' " << endl;
                }
                else
                {
                    vehicle->refuel();
                    --i;
                }
            }
        }
        return true;
    };
    double AbstractCar::getFuelLevel(){return this->fuel;};
    double AbstractCar::getMilage(){return this->mileage;};
    float Bicycle::getMilageBicycle(){return this->mileage;};
    int Route::getTravel(){return this->travel;};

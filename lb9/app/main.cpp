#include <iostream>
#include "../objects/objects.h"
using namespace std;

int main(int argc, char* argv[])
    {
        setlocale(LC_CTYPE, "rus");
        Route route;
        RoutePoint routepoint;
        string xstr, ystr, namestr;
       // int xx = 0, yy = 0;
        ifstream fin;
        cout << endl << endl;
        if (argc >= 2)
        {
            fin.open(argv[1]);
            if (fin.is_open())
            {
                cout << "-----File open-----" << endl;


                while (!fin.eof())
                {
                    fin >> xstr;
                    fin >> ystr;
                    fin >> routepoint.name;
                    routepoint.xKm = stoi(xstr);
                    routepoint.yKm = stoi(ystr);
                    route.addPoint(routepoint);
                    cout << xstr << " " << ystr << " " << routepoint.name << endl;
                }
            }
            else
            {
                cout << "-----File not open-----" << endl;
            }

        }
        else
        {
            cout << "-----Parameters < 2-----" << endl;
        }
        IVehicle* vehicles[4] = { new Sedan, new Suv, new Bus, new Bicycle }; // Создаем объекты классов для моделирования
        for (int i = 0; i < 4; ++i)
        {
            route.run(vehicles[i]);
            cout << "------------" << endl << endl;
        }
        return 0;
    };

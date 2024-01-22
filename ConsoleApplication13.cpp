
#include <iostream>
#include <vector>
using namespace std;
struct Driver
{
    string name, car,password;
    int ID;
};
struct Passenger
{
    string Name;
    int ID;
    string password;
};
struct Request
{
    Passenger passanger;
    Driver driver;
    string routeStart, routeEnd;
};
int main()
{
    setlocale(LC_ALL, "Russian");
    bool memberStatus = 0;//0 - водитель, 1 - пассажир
    int programStatus = 0;
    vector<Request> Req;
    vector<Driver> Drivers;
    vector<Passenger> Passengers;
    int currentRoute = 0,drivercounter=0,passcounter=0;
    int statusInt;
    while (programStatus == 0)
    {
        cout << "Выберите действие:" << endl << "1.Добавить водителя" << endl << "2.Добавить пассажира" << endl<<"3.Выйти"<<endl;
         cin >> statusInt;
         if (statusInt == 3)
         {
             programStatus = 1;
        }
        if (statusInt == 1)
        {
            Driver insertingDriver;
            cout << "Введите имя водителя:";
            cin >> insertingDriver.name;
            cout << endl << "Введите машину водителя:";
            cin >> insertingDriver.car;
            cout << endl << "Введите пароль водителя:";
            cin >> insertingDriver.password;
            insertingDriver.ID = drivercounter;
            drivercounter++;
            Drivers.push_back(insertingDriver);
        }
        else if (statusInt == 2)
        {
            Passenger insertingPass;
            cout << endl << "Введите имя пассажира:";
            cin >> insertingPass.Name;
            cout << endl << "Введите пароль пассажира:";
            cin >> insertingPass.password;
            insertingPass.ID = passcounter;
            Passengers.push_back(insertingPass);
            passcounter++;
        }
       
    }
    while (programStatus != 0)
    {
        string password;
        int currentID,login;
        bool passwordIsTrue = 0;
        cout << "Вы пассажир или водитель? 1 - Пассажир, 0 - Водитель";
        cin >> memberStatus;
        if (memberStatus == 1)//пассажир
        {
            cout << "Введите логин"<<endl;
            cin >> login;
            for (int i = 0; i < Passengers.size(); i++)
            {
                if (login == Passengers[i].ID)
                {
                    currentID = i;
                }
            }
            cout << "Введите пароль" << endl;
            while (passwordIsTrue == 0)
            {
                cin >> password;
                if (Passengers[currentID].password == password)
                {
                    passwordIsTrue = 1;
                }
                else
                {
                    cout << "Пароль неверный."<<endl;
                }
            }
            bool tripYesNo = 0; // 0 - нет 1 - да
            cout << "Желаете создать поездку? 0 - Нет, 1 - Да";
            cin >> tripYesNo;
            if (tripYesNo == 1)
            {
                Request reqq;
                cout << "Введите начальную и конечную точки: ";// на данном этапе нужно вводить всё правильно
                cin >> reqq.routeStart >> reqq.routeEnd;
                reqq.passanger = Passengers[currentID];
                Req.push_back(reqq);
            }
        }
        if (memberStatus == 0)//водитель
        {
            cout << "Введите логин" << endl;
            cin >> login;
            for (int i = 0; i < Drivers.size(); i++)
            {
                if (login == Drivers[i].ID)
                {
                    currentID = i;
                }
            }
            cout << "Введите пароль" << endl;
            while (passwordIsTrue == 0)
            {
                cin >> password;
                if (Drivers[currentID].password == password)
                {
                    passwordIsTrue = 1;
                }
                else
                {
                    cout << "Пароль неверный." << endl;
                }
            }
            cout << "Доступные поездки:";
            for (int i = 0; i < Req.size(); i++)
            {
                cout << i << "." << Req[i].routeStart << "-" << Req[i].routeEnd <<" "<<Req[i].passanger.Name<<endl;
            }
            int routeSelector;
            cout << "Выбор поездки: ";
            cin >> routeSelector;
            Req[routeSelector].driver = Drivers[currentID];
        }
        cout << "Желаете выйти из программы?";
        cin >> programStatus;
        
    }
    for (int i = 0; i < Req.size(); i++) {
        cout<<Req[i].passanger.Name<<" "<<Req[i].driver.name<<" "  << Req[i].routeStart << "-" << Req[i].routeEnd;
    }
}


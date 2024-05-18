#include <iostream>
using namespace std;

__interface IProduction {
    virtual void Release() = 0;
};

class Car : public IProduction {
public:
    virtual void Release() override {
        cout << "New passenger car\n";
    }
};

class Truck : public IProduction {
public:
    virtual void Release() override {
        cout << "New truck\n";
    }
};

__interface IWorkShop {
    virtual IProduction* Create() = 0;
};

class CarWorkShop : public IWorkShop {
public:
    virtual IProduction* Create() override {
        return new Car();
    }
};

class TruckWorkShop : public IWorkShop {
public:
    virtual IProduction* Create() override {
        return new Truck();
    }
};

int main() {
    IWorkShop* creator = new CarWorkShop;
    IProduction* car = creator->Create();
    creator = new TruckWorkShop();
    IProduction* truck = creator->Create();
    car->Release();
    truck->Release();
}
#include <iostream>
#include <string>

using namespace std;

class Transport {
protected:
    string typeName;
    double dailyCost;

public:
    Transport(const string& name, double cost) : typeName(name), dailyCost(cost) {}
    virtual double fetchRentalCost() const = 0;
    virtual void showInfo() const = 0;
    virtual ~Transport() {}
};

class Sedan : public Transport {
public:
    Sedan(const string& name, double cost) : Transport(name, cost) {}

    double fetchRentalCost() const override {
        return dailyCost;
    }

    void showInfo() const override {
        cout << "Sedan Name: " << typeName << " | Cost per Day: $" << dailyCost << endl;
    }
};

class Motorbike : public Transport {
public:
    Motorbike(const string& name, double cost) : Transport(name, cost) {}

    double fetchRentalCost() const override {
        return dailyCost;
    }

    void showInfo() const override {
        cout << "Motorbike Name: " << typeName << " | Cost per Day: $" << dailyCost << endl;
    }
};

int main() {
    Transport* sedan = new Sedan("Honda Accord", 55.0);
    Transport* bike = new Motorbike("KTM Duke", 22.5);

    sedan->showInfo();
    bike->showInfo();

    delete sedan;
    delete bike;

    return 0;
}

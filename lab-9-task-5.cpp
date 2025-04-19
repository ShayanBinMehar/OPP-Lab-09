#include <iostream>
using namespace std;

class Exercise {
public:
    virtual double getCalories() const = 0;
    virtual ~Exercise() {}
};

class Jogging : public Exercise {
private:
    double kilometers;
    double durationMins;

public:
    Jogging(double km, double mins) : kilometers(km), durationMins(mins) {}

    double getCalories() const override {
        return kilometers * 6 * (durationMins / 60.0);
    }
};

class Biking : public Exercise {
private:
    double averageVelocity;
    double durationHrs;

public:
    Biking(double velocity, double hours) : averageVelocity(velocity), durationHrs(hours) {}

    double getCalories() const override {
        return averageVelocity * durationHrs * 3;
    }
};

int main() {
    Jogging jogSession(5.0, 30.0);
    Biking bikeSession(20.0, 1.0);

    cout << "Jogging burned: " << jogSession.getCalories() << " kcal\n";
    cout << "Biking burned: " << bikeSession.getCalories() << " kcal\n";

    return 0;
}

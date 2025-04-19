#include <iostream>
#include <string>

using namespace std;

class Device {
public:
    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual string statusReport() = 0;
    virtual ~Device() {}
};

class LEDLight : public Device {
private:
    bool powerState;
    int level;

public:
    LEDLight() : powerState(false), level(0) {}

    void activate() override {
        powerState = true;
        level = 100;
    }

    void deactivate() override {
        level = 0;
        powerState = false;
    }

    string statusReport() override {
        return powerState 
            ? "LEDLight active with intensity: " + to_string(level) 
            : "LEDLight is inactive";
    }
};

// Modified Thermostat
class ClimateController : public Device {
private:
    bool powerState;
    double temp;

public:
    ClimateController() : powerState(false), temp(20.0) {}

    void activate() override {
        powerState = true;
    }

    void deactivate() override {
        powerState = false;
    }

    string statusReport() override {
        return powerState 
            ? "ClimateController running at " + to_string(temp) + "°C"
            : "ClimateController is off";
    }
};

// Main logic
int main() {
    LEDLight lamp;
    ClimateController climate;

    Device* smartDevices[2] = { &lamp, &climate };

    for (auto device : smartDevices) {
        device->activate();
        cout << device->statusReport() << endl;
    }

    for (auto device : smartDevices) {
        device->deactivate();
        cout << device->statusReport() << endl;
    }

    return 0;
}

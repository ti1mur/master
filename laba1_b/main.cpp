#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class Car {
private:
    const std::string model;
public:
    
    Car(const std::string& mod) : model(mod) {}
    virtual ~Car() {std::cout << "Car model: " << model << std::endl;}
};

class Mercedes : public Car {
public:
    Mercedes(std::string mod) :Car::Car(mod) {}
    virtual ~Mercedes () {std::cout << "Brand: Mercedes, ";}
};

class BMW : public Car {
public:
    BMW(std::string mod) :Car::Car(mod) {}
    virtual ~BMW() { std::cout << "Brand: BMW, "; }
};

int main() {
    std::vector<Car*> cars;
    std::ifstream file("cars.txt");
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::string brand, model;
            brand = line.substr(0, line.find(" "));
            model = line.substr(line.find(" ") + 1);
            if (brand == "Mercedes") {
                cars.push_back(new Mercedes(model));
            }
            else if (brand == "BMW") {
                cars.push_back(new BMW(model));
            }
        }
        file.close();
    }
    else {
        std::cout << "Unable to open file" << std::endl;
        return 0;
    }

    for (int i = 0; i < cars.size(); i++) { delete cars[i]; }

    return 0;
}
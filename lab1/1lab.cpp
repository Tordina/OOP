#include "Derivative.hpp"


Derivative::Derivative(double x, double step) : _x(x), _step(step) {
    std::cout << "Constructor (base)\n";
}


Derivative::~Derivative() {
    std::cout << "Destructor (base)\n";
}


double Derivative::function(double y) {
    return pow(y, 3);
}


double Derivative::value() const {
    return _derivative;
}


Left::Left(double x, double step) : Derivative(x, step) {
    std::cout << "Constructor (left)\n";
}


Left::~Left() {
    std::cout << "Destructor (left)\n";
}


void Left::calc() {
    _derivative = (function(_x) - function(_x - _step)) / _step;
}


Right::Right(double x, double step) : Derivative(x, step) {
    std::cout << "Constructor (right)\n";
}


Right::~Right() {
    std::cout << "Destructor (right)\n";
}


void Right::calc() {
    _derivative = (function(_x + _step) - function(_x)) / _step;
}


Center::Center(double x, double step) : Derivative(x, step) {
    std::cout << "Constructor (center)\n";
}


Center::~Center() {
    std::cout << "Destructor (center)\n";
}


void Center::calc() {
    _derivative = (function(_x + _step) - function(_x - _step)) / (2 * _step);
}


void main() {

    std::vector<Derivative*> derivatives;

    derivatives.push_back(new Left(3, 0.1));
    derivatives.push_back(new Right(3, 0.1));
    derivatives.push_back(new Center(3, 0.1));

    for (const auto& derivative : derivatives) {
        derivative->calc();
        std::cout << derivative->value() << std::endl;
    }

    for (auto& derivative : derivatives)
        delete derivative;
    derivatives.clear();
}


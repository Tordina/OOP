#include <iostream>
#include <functional>
#include <memory>
#include <utility>
class Derivative {
private:
public:
    double _x, step;
    std::function<double(double)> funkc;
    Derivative (double x, double s, std::function<double(double)> f) {
        _x = x;  step = s; funkc = std::move(f);//move-превращает во временный объект(предотвращает копирование объектов)
    };
    //создаём вертуальную функцию 
    virtual double DerivativeDiff() {
        return 0;
    };
};

class DerivativeLeft : public Derivative {
public:
    DerivativeLeft(double x, double step, std::function<double(double)> f) : Derivative(x, step, f) {};
    //переопределяем функцию 
    double DerivativeDiff() override {
        return ((funkc(_x + step) - funkc(_x)) / step);//по формуле
    };
};

class DerivativeRight : public Derivative {
public:
    DerivativeRight(double x, double s, std::function<double(double)> f) : Derivative(x, s, f) {};

    double DerivativeDiff() override {
        return (funkc(_x) - funkc(_x + step)) / step;//по формуле
    };
};

class DerivativeCentral : public Derivative {
public:
    DerivativeCentral(double x, double s, std::function<double(double)> f) : Derivative(x, s, f) {}; 
    double DerivativeDiff() override {
        return (funkc(_x + step) - funkc(_x - step)) / (2 * step);//по формуле
    };
};
int main() {

    std::function<double(double)>f = [](double x) {
        return x * x * x;
    };
    double x = 3;
    double s = 0.1;
    // make_unique -создаёт указатель на объект с параметрами конструктора и объект будет удален при выходе)
    std::unique_ptr<Derivative> DerivativeL = std::make_unique<DerivativeLeft>(DerivativeLeft(x, s, f)); 
    std::unique_ptr<Derivative> DerivativeR= std::make_unique<DerivativeRight>(DerivativeRight(x, s, f));
    std::unique_ptr<Derivative> DerivativeC= std::make_unique<DerivativeCentral>(DerivativeCentral(x,s, f));

    std::cout << "DerivativeLeft = " << DerivativeL->DerivativeDiff() << std::endl;
    std::cout << "DerivativeRight = " << DerivativeR->DerivativeDiff() << std::endl;
    std::cout << "DerivativeCentral = " << DerivativeC->DerivativeDiff() << std::endl;
    return 0;
}
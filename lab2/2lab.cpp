#include <iostream>
#include <string>
using namespace std;


class Ratio {
public:

    Ratio() {
        numer = 0;
        denom = 0;
        whole = 0;
    }


    Ratio(int n, int d) {
        numer = n;
        denom = d;
        whole = 0;
    }

    int getNumer() const {
        return numer;
    }

    int getDenom() const {
        return denom;
    }

    void set(int n, int d) {
        numer = n;
        denom = d;
    }

    void print() {
        if (whole != 0)
            cout << whole << "+";

        cout << numer << "/" << denom << endl;
    }


    bool read() {

        string str;
        getline(cin, str);
        if (str.find('/') == -1) {
            cout << "Введите правильно дробь" << endl;
            return 0;
        }
        int sep = str.find('/');
        int a, b;
        try {
            a = stoi(str.substr(0, sep));
            b = stoi(str.substr(sep + 1));
        }
        catch (exception& err) {
            cout << "Числитель и знаменатель должны состоять из цифр " << endl;
            return 0;
        }
        if (b == 0) {
            cout << "Делить на ноль нельзя " << endl;
            return 0;
        }
        this->set(a, b);
        return 1;
    }

    void reduction() {
        int gcd_value = gcd(numer, denom);
        numer /= gcd_value;
        denom /= gcd_value;
    }
        float toDecimal() {
        cout << "Перевод в десятичную дробь ";

        float tmp = float(numer) / float(denom);

        return tmp;
    }

  
    Ratio wholePart() {
        cout << "Выделение целой части ";

        Ratio tmp;

        if (abs(numer) < abs(denom)) {
            tmp = *this;
        }
        else {

            tmp.whole = numer / denom;

            tmp.numer = numer - denom * tmp.whole;

            tmp.denom = denom;
        }

        return tmp;
    }

    void operator=(const Ratio& r) {
        numer = r.getNumer();
        denom = r.getDenom();
    }

    Ratio operator+(const Ratio& r) {
        Ratio tmp;

        tmp.numer = numer * r.getDenom() + denom * r.getNumer();
        tmp.denom = denom * r.getDenom();

        tmp.reduction();

        return tmp;
    }

    Ratio add(const Ratio& r) {
        cout << "x + y = ";

        Ratio tmp = *this + r;

        return tmp;
    }

    Ratio operator-(const Ratio& r) {
        Ratio tmp;

        tmp.numer = numer * r.getDenom() - denom * r.getNumer();
        tmp.denom = denom * r.getDenom();

        tmp.reduction();

        return tmp;
    }

    Ratio subtract(const Ratio& r) {
        cout << "x - y = ";

        Ratio tmp = *this - r;

        return tmp;
    }
    Ratio operator*(const Ratio& r) {
        Ratio tmp; 
        tmp.numer = numer * r.getNumer(); 
        tmp.denom = denom * r.getDenom(); 
        tmp.reduction(); 
        return tmp; 
    }

    Ratio multiply(const Ratio& r) {
 
        cout << "x * y = "; 
        Ratio tmp = *this * r;
        return tmp;
    }

    Ratio operator/(const Ratio& r) {
        Ratio tmp; 
        tmp.numer = numer * r.getDenom(); 
        tmp.denom = denom * r.getNumer();
        if (r.getNumer() == 0) { 
            cout << "Делить на ноль нельзя :(" << endl;
            return *this; 
        }
        tmp.reduction(); 
        return tmp; 
    }

    Ratio divide(const Ratio& r) {
        cout << "x / y = "; 
        Ratio tmp = *this / r; 
        return tmp;
    }

private:
    int whole; 
    int numer;
    int denom; 
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b); 
    }
};

int main() {
    try {
        setlocale(LC_ALL, "Russian");
        Ratio x, y; 
        bool x_flag = 0, y_flag = 0; 
        cout << "Вводите дроби в формате а/б" << endl; 
        while (!x_flag) { 
            cout << "Введите первую дробь: ";
            x_flag = x.read();
        }
        while (!y_flag) { 
            cout << "Введите вторую дробь: "; 
            y_flag = y.read(); 
        }
        cout << endl; 
        Ratio z = x.add(y); 
        z.print(); 
        z.wholePart().print();
        cout << z.toDecimal() << endl; 
        x.subtract(y).print();
        x.multiply(y).print(); 
        x.divide(y).print();
    }
    catch (exception& e) { 
        cout << "Произошло исключение: " << e.what();
    }
}
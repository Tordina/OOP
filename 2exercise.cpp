
#include <iostream> 
#include <string> // библиотека для работы со строками

using namespace std; 

// Определение класса Fraction (дробь)
class Fraction
{
public:
    // Конструктор по умолчанию
    Fraction() {
        numer = 0; 
        denom = 0; 
        whole = 0; 
    }

    // Конструктор с параметрами 
    Fraction(int n, int d) {
        numer = n; 
        denom = d; 
        whole = 0; 
    }

    
    int getNumer() const { return numer; } 
    int getDenom() const { return denom; } 

    
    void set(int n, int d) {
        numer = n; 
        denom = d; 
    }

    // вывод дроби в консоль
    void print() {
        if (whole != 0) 
            cout << whole << "+"; 
        cout << numer << '/' << denom << endl; 
    }

    // ввод дроби с консоли
    void read() {
        string str; // строка для хранения введенных данных
        getline(cin, str); // считываем строку с консоли
        int sep = str.find('/'); // находим позицию разделителя '/'
        this->set(stoi(str.substr(0, sep)), stoi(str.substr(sep + 1))); // устанавливаем значения числителя и знаменателя из строки
    }

    //сокращения дроби
    void simplify() {
        for (int i = 1; i <= min(abs(numer), abs(denom)); ++i) { 
            if (numer % i == 0 && denom % i == 0) { 
                numer /= i; 
                denom /= i; 
            }
        }
    }

    // перевод дроби в десятичную форму
    float toDecimal() {
        cout << "перевод в десятичную дробь" << endl;
        float tmp = float(numer) / float(denom);
        return tmp; 
    }

    //выделения целой части дроби
    Fraction wholePart() {
        cout << "выделение целой части" << endl;
        Fraction tmp; 
        if (numer < denom) 
            tmp = *this;
        else {
            tmp.whole = numer / denom; 
            tmp.numer = numer - denom * tmp.whole; 
            tmp.denom = denom;
        }
        return tmp; 
    }

    //  оператора присваивания
    void operator=(const Fraction& r) {
        numer = r.getNumer(); 
        denom = r.getDenom(); 
    }

    //  оператора сложения
    Fraction operator+(const Fraction& r) {
        Fraction tmp; 
        tmp.numer = numer * r.getDenom() + denom * r.getNumer(); 
        tmp.denom = denom * r.getDenom();
        tmp.simplify();
        return tmp; 
    }

    //сложения дробей
    Fraction add(const Fraction& r) {
        cout << "сложение" << endl;
        Fraction tmp = *this + r; 
        return tmp; 
    }

    // оператора вычитания
    Fraction operator-(const Fraction& r) {

      
        Fraction tmp; 
        tmp.numer = numer * r.getDenom() - denom * r.getNumer(); 
        tmp.denom = denom * r.getDenom();
        tmp.simplify(); 
        return tmp; 
    }

    //вычитания дробей
    Fraction subtract(const Fraction& r) {
        cout << "вычитание" << endl;
        Fraction tmp = *this - r; 
        return tmp;
    }

    // оператора умножения
    Fraction operator*(const Fraction& r) {
        Fraction tmp;
        tmp.numer = numer * r.getNumer();
        tmp.denom = denom * r.getDenom(); 
        tmp.simplify(); 
        return tmp; 
    }

    // умножения дробей
    Fraction multiply(const Fraction& r) {
        cout << "умножение" << endl;
        Fraction tmp = *this * r; 
        return tmp; 
    }

    // оператора деления
    Fraction operator/(const Fraction& r) {
        Fraction tmp; 
        tmp.numer = numer * r.getDenom(); 
        tmp.denom = denom * r.getNumer(); 
        tmp.simplify(); 
        return tmp; 
    }

    // деления дробей
    Fraction divide(const Fraction& r) {
        cout << "деление" << endl;
        Fraction tmp = *this / r; 
        return tmp;
    }

private:
    int whole; 
    int numer; 
    int denom;
};

int main()
{
    setlocale(LC_ALL, "Russian"); 
    Fraction x, y; 
    cout << "Введите первую дробь: ";
    x.read();
    cout << "Введите вторую дробь: ";
    y.read(); 
    cout << endl;
    Fraction z = x.add(y); 
    z.print(); 
    z.wholePart().print(); 
    cout << z.toDecimal() << endl;; 
    x.subtract(y).print(); 
    x.multiply(y).print(); 
    x.divide(y).print(); 
    return 0;
}
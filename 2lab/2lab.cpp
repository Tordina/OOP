#include <iostream>
#include <string>

class Ratio
{
private:
	int _numer;
	int _denom;
public:
	Ratio(int numer, int denom) : _numer(numer), _denom(denom)
	{
		std::cout << "constructor\n";
	}

	Ratio() = default;
	Ratio(const Ratio& ratio) = default;
	~Ratio() = default;

	Ratio(const std::string& ratio)
	{
		RatioToInt(ratio);
	}

	int getNumer() const { return _numer; }
	int getDumer() const { return _denom; }

	//сокращение дроби
	void reduction()
	{
		int gcd_value = gcd(_numer, _denom);
		_numer /= gcd_value;
		_denom /= gcd_value;
	}

	//обратная дробь
	void reverse()
	{
		std::swap(_numer, _denom);
	}

	//получение десятичного представления
	double decimal()
	{
		double x = _numer * 1.0 / _denom;
		return x;
	}

	friend std::istream& operator>>(std::istream& in, Ratio& ratio);
	friend std::ostream& operator<<(std::ostream& out, const Ratio& ratio);

	Ratio& operator=(const Ratio& ratio) = default;

	Ratio operator+(const Ratio& ratio)
	{
		Ratio tmp = *this;
		tmp._numer = _numer * ratio._denom + _denom * ratio._numer;
		tmp._denom = _denom * ratio._denom;
		tmp.reduction();
		return tmp;
	}

	Ratio operator-(const Ratio& ratio)
	{
		Ratio tmp = *this;
		tmp._numer = _numer * ratio._denom - _denom * ratio._numer;
		tmp._denom = _denom * ratio._denom;
		tmp.reduction();
		return tmp;
	}

	Ratio operator/(const Ratio& ratio)
	{
		Ratio tmp = *this;
		tmp._numer = _numer * ratio._denom;
		tmp._denom = _denom * ratio._numer;
		tmp.reduction();
		return tmp;
	}

	Ratio operator*(const Ratio& ratio)
	{
		Ratio tmp = *this;
		tmp._numer = _numer * ratio._numer;
		tmp._denom = _denom * ratio._denom;
		tmp.reduction();
		return tmp;
	}



	//перевод строки в дроби
	void RatioToInt(const std::string& value) 
	{
		int pos = value.find('/');
		std::string numerStr = value.substr(0, pos);
		std::string dumerStr = value.substr(pos + 1, value.length() - pos);

		_numer = std::stoi(numerStr);
		_denom = std::stoi(dumerStr);
	}

	//НОД
	int gcd(int a, int b)
	{
		if (b == 0) return a;
		return gcd(b, a % b);
	}
};

std::istream& operator>>(std::istream& in, Ratio& ratio)
{
	std::string value;
	in >> value;
	ratio.RatioToInt(value);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Ratio& ratio)
{
	out << ratio._numer << "/" << ratio._denom;
	return out;
}

void commandList()
{
	std::cout << "press 0 to exit\n";
	std::cout << "press 1 to sum\n";
	std::cout << "press 2 to substract\n";
	std::cout << "press 3 to multiply\n";
	std::cout << "press 4 to divide\n";
	std::cout << "press 5 to find a reverse ratio\n";
	std::cout << "press 6 to find a decimal ratio\n";
	std::cout << "press 7 to see command list\n";
}

int main()
{
	Ratio r1;
	Ratio r2;

	int command = 1;

	std::cout << "Enter 2 simple ratio separated by space" << std::endl;
	std::cin >> r1 >> r2;
	commandList();


	while (command != 0)
	{
		std::cout << "Command: ";
		std::cin >> command;

		switch (command)
		{
		case 1: std::cout << r1 + r2 << std::endl;
			break;

		case 2: std::cout << r1 - r2 << std::endl;
			break;

		case 3: std::cout << r1 * r2 << std::endl;
			break;

		case 4: std::cout << r1 / r2 << std::endl;
			break;

		case 5:
			r1.reverse();
			r2.reverse();
			std::cout << r1 << " " << r2 << std::endl;
			break;

		case 6:
			std::cout << r1.decimal() << " " << r2.decimal() << std::endl;
			break;

		case 7:
			commandList();
			break;

		default:
			std::cout << " " << std::endl;
			break;
		}
	};

	return 0;
}

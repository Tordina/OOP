#pragma once


#include <iostream>
#include <cmath>
#include <vector>
class Derivative {
public:
	Derivative(double x, double step);
	virtual ~Derivative();
	double function(double y);
	virtual void calc() = 0;
	double value() const; 

protected:
	double _derivative; 
	double _x; 
	double _step; 
};

class Left : public Derivative {
public:
	Left(double x, double step); 
	~Left(); 
	void calc() override; 
};

class Right : public Derivative {
public:
	Right(double x, double step); 
	~Right(); 
	void calc() override; 
};

class Center : public Derivative {
public:
	Center(double x, double step);
	~Center(); 
	void calc() override; 
};
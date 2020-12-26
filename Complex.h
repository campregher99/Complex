#ifndef COMPLEX_H
#define COMPLEX_H
#include <math.h>
#define MORE long
#include "Double.h"
class Complex
{
	//variabili
private:
	Double real {0};
	Double imaginary {0};

	//funzioni
public:
	//costruttori
	explicit Complex() {Double::setMultiplier(10000);};
	Complex(double _real, double _imaginary)
	{
	    Double::setMultiplier(10000);
	    real = _real;
	    imaginary = _imaginary;
    };

	//setter e getter
	void setCartesian(double _real, double _imaginary);
	void setPolar(double _module, double _phase);
	double getReal(void) const;
	double getImaginary(void) const;
	double getModule(void) const;
	double getPhase(void) const;

	//overload assegnamento
	template <typename T> Complex operator=(T _number);
	Complex operator=(const Complex& _complex);

	//overload operazioni aritmetiche
	template <typename T> Complex operator+(T _number) const;
	Complex operator+(const Complex& _complex) const;
	template <typename T> Complex operator-(T _number) const;
	Complex operator-(const Complex& _complex) const;
	template <typename T> Complex operator*(T _number) const;
	Complex operator*(const Complex& _complex) const;
	template <typename T> Complex operator/(T _number) const;
	Complex operator/(const Complex& _complex) const;

	template <typename T> Complex operator+=(T _number);
	Complex operator+=(const Complex& _complex);
	template <typename T> Complex operator-=(T _number);
	Complex operator-=(const Complex& _complex);
	template <typename T> Complex operator*=(T _number);
	Complex operator*=(const Complex& _complex);
	template <typename T> Complex operator/=(T _number);
	Complex operator/=(const Complex& _complex);

	template <typename T> bool operator==(T _number) const;
	bool operator==(const Complex& _complex) const;
	template <typename T> bool operator!=(T _number) const;
	bool operator!=(const Complex& _complex) const;
	template <typename T> bool operator<(T _number) const;
	bool operator<(const Complex& _complex) const;
	template <typename T> bool operator>(T _number) const;
	bool operator>(const Complex& _complex) const;
	template <typename T> bool operator<=(T _number) const;
	bool operator<=(const Complex& _complex) const;
	template <typename T> bool operator>=(T _number) const;
	bool operator>=(const Complex& _complex) const;



private:
	double module(void) const;
	double phase(void) const;
	bool toCartesian(double _module, double _phase);


};

template <typename T> Complex Complex::operator=(T _number)
{
	real=(double)_number;
	return *this;
}

template <typename T> Complex Complex::operator+(T _number) const
{
	Complex sum {real+_number,imaginary};
	return sum;
}

template <typename T> Complex Complex::operator-(T _number) const
{
	Complex sub {real-_number,imaginary};
	return sub;
}

template <typename T> Complex Complex::operator*(T _number) const
{
	Complex mul {module()*_number*cos(phase()),module()*_number*sin(phase())};
	return mul;
}

template <typename T> Complex Complex::operator/(T _number) const
{
	Complex div {module()/_number*cos((double)imaginary),module()/_number*sin((double)imaginary)};
	return div;
}

template <typename T> Complex Complex::operator+=(T _number)
{
	real+=_number;
	return *this;
}

template <typename T> Complex Complex::operator-=(T _number)
{
	real-=_number;
	return *this;
}

template <typename T> Complex Complex::operator*=(T _number)
{
	*this=*this*_number;
	return *this;
}

template <typename T> Complex Complex::operator/=(T _number)
{
	*this=*this/_number;
	return *this;
}

template <typename T> bool Complex::operator==(T _number) const
{
	if (real==_number&&imaginary!=0)
		return true;
	return false;
}

template <typename T> bool Complex::operator!=(T _number) const
{
	if(!(*this==_number))
		return true;
	return false;
}

template <typename T> bool Complex::operator<(T _number) const
{
	if(module()<_number)
		return true;
	return false;
}

template <typename T> bool Complex::operator>(T _number) const
{
	if(!(*this<_number))
		return true;
	return false;
}

template <typename T> bool Complex::operator<=(T _number) const
{
	if(*this<_number||*this==_number)
		return true;
	return false;
}

template <typename T> bool Complex::operator>=(T _number) const
{
	if(*this>_number||*this==_number)
		return true;
	return false;
}

template <typename T> Complex operator+(T _number, const Complex& _complex)
{
	Complex sum {_complex.getReal()+_number,_complex.getImaginary()};
	return sum;
}

template <typename T> Complex operator-(T _number, const Complex& _complex)
{
	Complex sub {_number-_complex.getReal(),-_complex.getImaginary()};
	return sub;
}

template <typename T> Complex operator*(T _number, const Complex& _complex)
{
	Complex mul {_complex.getModule()*cos(_complex.getPhase())*_number,_complex.getModule()*sin(_complex.getPhase())*_number};
	return mul;
}

template <typename T> Complex operator/(T _number, const Complex& _complex)
{
	Complex div {_number/_complex.getModule()*cos(-_complex.getPhase()),_number/_complex.getModule()*sin(-_complex.getPhase())};
	return div;
}
#endif

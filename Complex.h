#ifndef COMPLEX_H
#define COMPLEX_H
#include <math.h>

class Complex
{
	//variabili
private:
	double real = 0;
	double imaginary = 0;

	//funzioni
public:
	//costruttori
	explicit Complex() {};
	Complex(double _real, double _imaginary): real {_real}, imaginary{_imaginary} {};

	//setter e getter
	void setCartesian(double _real, double _imaginary);
	void setPolar(double _module, double _phase);
	double getReal(void) const;
	double getImaginary(void) const;
	double getModule(void) const;
	double getPhase(void) const;

	//overload assegnamento
	template <typename T> Complex operator=(T _number)
	{
		real=(double)_number;
		return *this;
	};
	Complex operator=(const Complex& _complex);

	//overload operazioni aritmetiche
	template <typename T> Complex operator+(T _number) const
	{
		Complex sum {real+_number,imaginary};
		return sum;
	};
	Complex operator+(const Complex& _complex) const;
	template <typename T> Complex operator-(T _number) const
	{
		Complex sub {real-_number,imaginary};
		return sub;
	};
	Complex operator-(const Complex& _complex) const;
	template <typename T> Complex operator*(T _number) const
	{
	    double _real=module()*_number*cos(phase()),_imaginary=module()*_number*sin(phase());
		Complex mul {_real,_imaginary};
		return mul;
	};
	Complex operator*(const Complex& _complex) const;
	template <typename T> Complex operator/(T _number) const
	{
		Complex div {module()/_number*cos(imaginary),module()/_number*sin(imaginary)};
		return div;
	};
	Complex operator/(const Complex& _complex) const;

	template <typename T> Complex operator+=(T _number)
	{
		real+=_number;
		return *this;
	};
	Complex operator+=(const Complex& _complex);
	template <typename T> Complex operator-=(T _number)
	{
		real-=_number;
		return *this;
	};
	Complex operator-=(const Complex& _complex);
	template <typename T> Complex operator*=(T _number)
	{
		*this=*this*_number;
		return *this;
	};
	Complex operator*=(const Complex& _complex);
	template <typename T> Complex operator/=(T _number)
	{
		*this=*this/_number;
		return *this;
	};
	Complex operator/=(const Complex& _complex);

	template <typename T> bool operator==(T _number) const
	{
		if (real==_number&&imaginary!=0)
		{
			return true;
		}
		return false;
	};
	bool operator==(const Complex& _complex) const;
	template <typename T> bool operator!=(T _number) const
	{
		if(!(*this==_number))
		{
			return true;
		}
		return false;
	};
	bool operator!=(const Complex& _complex) const;
	template <typename T> bool operator<(T _number) const
	{
		if(module()<_number)
		{
			return true;
		}
		return false;
	};
	bool operator<(const Complex& _complex) const;
	template <typename T> bool operator>(T _number) const
	{
		if(!(*this<_number))
		{
			return true;
		}
		return false;
	};
	bool operator>(const Complex& _complex) const;
	template <typename T> bool operator<=(T _number) const
	{
		if(*this<_number||*this==_number)
		{
			return true;
		}
		return false;
	};
	bool operator<=(const Complex& _complex) const;
	template <typename T> bool operator>=(T _number) const
	{
		if(*this>_number||*this==_number)
		{
			return true;
		}
		return false;
	};
	bool operator>=(const Complex& _complex) const;



private:
	double module(void) const;
	double phase(void) const;
	bool toCartesian(double _module, double _phase);


};

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
	return di;
}
#endif

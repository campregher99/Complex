#include "Complex.h"

void Complex::setCartesian(double _real, double _imaginary)
{
	real = _real;
	imaginary = _imaginary;
}

void Complex::setPolar(double _module, double _phase)
{
	real=_module*cos(_phase);
	imaginary=_module*sin(_phase);
}

double Complex::getReal(void) const
{
	return real.getValue();
}

double Complex::getImaginary(void) const
{
	return imaginary.getValue();
}

double Complex::getModule(void) const
{
	return module();
}

double Complex::getPhase(void) const
{
	return phase();
}

Complex Complex::operator=(const Complex& _complex)
{
	if(this != &_complex)
	{
		real=_complex.getReal();
		imaginary=_complex.getImaginary();
	}
	return *this;
}

Complex Complex::operator+(const Complex& _complex) const
{
	Complex sum {real+_complex.getReal(),imaginary+_complex.getImaginary()};
	return sum;
}

Complex Complex::operator-(const Complex& _complex) const
{
	Complex sub {real-_complex.getReal(),imaginary-_complex.getImaginary()};
	return sub;
}

Complex Complex::operator*(const Complex& _complex) const
{
	Complex mul{module()*_complex.getModule()*cos(phase()+_complex.getPhase()),module()*_complex.getModule()*sin(phase()+_complex.getPhase())};
		return mul;
}

Complex Complex::operator/(const Complex& _complex) const
{
	Complex div {module()/_complex.getModule()*cos(phase()-_complex.getPhase()),module()/_complex.getModule()*sin(phase()-_complex.getPhase())};
	return div;
}


Complex Complex::operator+=(const Complex& _complex)
{
	*this=*this+_complex;
	return *this;
}

Complex Complex::operator-=(const Complex& _complex)
{
	*this=*this-_complex;
	return *this;
}

Complex Complex::operator*=(const Complex& _complex)
{
	*this=*this*_complex;
	return *this;
}

Complex Complex::operator/=(const Complex& _complex)
{
	*this=*this/_complex;
	return *this;
}


bool Complex::operator==(const Complex& _complex) const
{
	if(real==_complex.getReal()&&imaginary==_complex.getImaginary())
	{
		return true;
	}
	return false;
}

bool Complex::operator!=(const Complex& _complex) const
{
	if(!(*this==_complex))
		{
			return true;
		}
		return false;
}

bool Complex::operator<(const Complex& _complex) const
{
	if(module()<_complex.getModule())
		{
			return true;
		}
		return false;
}

bool Complex::operator>(const Complex& _complex) const
{
	if(!(*this<_complex))
		{
			return true;
		}
		return false;
}

bool Complex::operator<=(const Complex& _complex) const
{
	if(*this<_complex||*this==_complex)
		{
			return true;
		}
		return false;
}

bool Complex::operator>=(const Complex& _complex) const
{
	if(*this>_complex||*this==_complex)
		{
			return true;
		}
		return false;
}

double Complex::module(void) const
{
	return sqrt((real*real+imaginary*imaginary).getValue());
}

double Complex::phase(void) const
{
	return atan2(imaginary.getValue(),real.getValue());
}

bool Complex::toCartesian(double _module, double _phase)
{
	real=_module*cos(_phase);
	imaginary=_module*sin(_phase);
	return true;
}

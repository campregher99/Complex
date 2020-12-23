#include "Double.h"



double Double::getValue() const
{
	if(lastMultiplier!=getMultiplier())
		return value/(double)lastMultiplier;
	return value/(double)getMultiplier();
}

int Double::getRowValue() const
{
	if(lastMultiplier!=getMultiplier())
	{
		int newValue=value*adjustValue();
		return newValue;
	}
	return value;
}

Double Double::operator+(const Double& _double) const
{
	Double* newDouble= new Double {};
	newDouble->setRowValue(getRowValue()+_double.getRowValue());
	return *newDouble;
}

Double Double::operator-(const Double& _double) const
{
	Double* newDouble= new Double {};
	newDouble->setRowValue(getRowValue()-_double.getRowValue());
	return *newDouble;
}

Double Double::operator*(const Double& _double) const
{
	Double* newDouble= new Double {};
	newDouble->setRowValue(getRowValue()*_double.getValue());
	return *newDouble;
}

Double Double::operator/(const Double& _double) const
{
	Double* newDouble = new Double {};
	newDouble->setRowValue(getRowValue()/(double)_double.getRowValue()*getMultiplier());
	return *newDouble;
}

Double Double::operator=(const Double& _double)
{
	if(getMultiplier()!=lastMultiplier)
		adjustValue();
	value=_double.getRowValue();
	return *this;
}

Double Double::operator+=(const Double& _double)
{
	*this=*this+_double;
	return *this;
}

Double Double::operator-=(const Double& _double)
{
	*this=*this-_double;
	return *this;
}

Double Double::operator*=(const Double& _double)
{
	*this=*this*_double;
	return *this;
}

Double Double::operator/=(const Double& _double)
{
	*this = *this / _double;
	return *this;
}

bool Double::operator==(const Double& _double) const
{
	if(getRowValue()==_double.getRowValue())
		return true;
	return false;
}

bool Double::operator!=(const Double& _double) const
{
	if(!(*this==_double))
		return true;
	return false;
}

bool Double::operator<(const Double& _double) const
{
	if(getRowValue()<_double.getRowValue())
		return true;
	return false;
}

bool Double::operator>(const Double& _double) const
{
	if(getRowValue()>_double.getRowValue())
		return true;
	return false;
}

bool Double::operator<=(const Double& _double) const
{
	if(*this==_double||*this<_double)
		return true;
	return false;
}

bool Double::operator>=(const Double& _double) const
{
	if(*this==_double||*this>_double)
		return true;
	return false;
}

double Double::adjustValue() const
{
	return (double)getMultiplier()/lastMultiplier;
}

void Double::adjustValue()
{
	value*=(double)getMultiplier()/lastMultiplier;
	lastMultiplier = getMultiplier();
}

void Double::setRowValue(int _number)
{
	value = _number; 
}
#ifndef DOUBLE_H
#define DOUBLE_H
#ifndef MORE
#define MORE
#endif
class Double
{
private:
	MORE int value=0;
	static inline int multiplier=100;
	int lastMultiplier=multiplier;

public:
	Double()=default;
	template <typename T> Double(T _number) : value {_number*multiplier} {};
	static bool setMultiplier(int _multiplier)
	{
	if(_multiplier<10)
		return false;
	multiplier=_multiplier;
	return true;
    };
	~Double()=default;

	double getValue() const;
	int getRowValue() const;
	template <typename T> bool setValue(const T& _number);

	template <typename T> double operator+(const T& _number) const;
	Double operator+(const Double& _double) const;
	template <typename T> double operator-(const T& _number) const;
	Double operator-(const Double& _double) const;
	template <typename T> double operator*(const T& _number) const;
	Double operator*(const Double& _double) const;
	template <typename T> double operator/(const T& _number) const;
	Double operator/(const Double& _double) const;

	template <typename T> Double operator=(const T& _number);
	Double operator=(const Double& _double);
	template <typename T> Double operator+=(const T& _number);
	Double operator+=(const Double& _double);
	template <typename T> Double operator-=(const T& _number);
	Double operator-=(const Double& _double);
	template <typename T> Double operator*=(const T& _number);
	Double operator*=(const Double& _double);
	template <typename T> Double operator/=(const T& _number);
	Double operator/=(const Double& _double);

	template <typename T> bool operator==(const T& _number) const;
	bool operator==(const Double& _double) const;
	template <typename T> bool operator!=(const T& _number) const;
	bool operator!=(const Double& _double) const;
	template <typename T> bool operator<(const T& _number) const;
	bool operator<(const Double& _double) const;
	template <typename T> bool operator>(const T& _number) const;
	bool operator>(const Double& _double) const;
	template <typename T> bool operator<=(const T& _number) const;
	bool operator<=(const Double& _double) const;
	template <typename T> bool operator>=(const T& _number) const;
	bool operator>=(const Double& _double) const;


protected:
	static int getMultiplier()
	{
	return multiplier;
    };
	double adjustValue() const;
	void adjustValue();
	void setRowValue(int _number);
};

template <typename T> bool Double::setValue(const T& _number)
{
	if(lastMultiplier!=getMultiplier())
		adjustValue();
	value=_number*multiplier;
	return true;
}

template <typename T> double Double::operator+(const T& _number) const
{
	return getValue()+_number;
}

template <typename T> double Double::operator-(const T& _number) const
{
	return getValue()-_number;
}

template <typename T> double Double::operator*(const T& _number) const
{
	return getValue()*_number;
}

template <typename T> double Double::operator/(const T& _number) const
{
	return getValue()/_number;
}

template <typename T> Double Double::operator=(const T& _number)
{
	if(lastMultiplier!=multiplier)
		adjustValue();
	value=_number*multiplier;
	return *this;
}

template <typename T> Double Double::operator+=(const T& _number)
{
	*this=*this+_number;
	return *this;
}

template <typename T> Double Double::operator-=(const T& _number)
{
	*this=*this-_number;
	return *this;
}

template <typename T> Double Double::operator*=(const T& _number)
{
	*this=*this*_number;
	return *this;
}

template <typename T> Double Double::operator/=(const T& _number)
{
	*this=*this/_number;
	return *this;
}

template <typename T> bool Double::operator==(const T& _number) const
{
	if(getValue()==_number)
		return true;
	return false;
}

template <typename T> bool Double::operator!=(const T& _number) const
{
	if(!(*this==_number))
		return true;
	return false;
}

template <typename T> bool Double::operator<(const T& _number) const
{
	if(getValue()<_number)
		return true;
	return false;
}

template <typename T> bool Double::operator>(const T& _number) const
{
	if(!(*this<_number))
		return true;
	return false;
}

template <typename T> bool Double::operator<=(const T& _number) const
{
	if(*this<_number||*this==_number)
		return true;
	return false;
}

template <typename T> bool Double::operator>=(const T& _number) const
{
	if(*this>_number||*this==_number)
		return true;
	return false;
}

template <typename T> T operator+(const T& _number, const Double& _double)
{
	return _number+_double.getValue();
}

template <typename T> T operator-(const T& _number, const Double& _double)
{
	return _number-_double.getValue();
}

template <typename T> T operator*(const T& _number, const Double& _double)
{
	return _number*_double.getValue();
}

template <typename T> T operator/(const T& _number, const Double& _double)
{
	return _number/_double.getValue();
}
#endif

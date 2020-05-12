#include "../Vector2.h"

template<class T>
Vector2Template<T>::Vector2Template()
{
	x = 0;
	y = 0;
}

template<class T>
Vector2Template<T>::Vector2Template(T x, T y)
{
	this->x = x;
	this->y = y;
}

template<class T>
Vector2Template<T>::~Vector2Template()
{
}

// ‘ã“ü‰‰ŽZŽq
template<class T>
Vector2Template<T>& Vector2Template<T>::operator=(const Vector2Template<T>& vec)
{
	x = vec.x;
	y = vec.y;

	return *this;
}

// “YŽš‰‰ŽZŽq
template<class T>
int Vector2Template<T>::operator [](int i)
{
	if (i == 0)
	{
		return x;
	}
	else if (i == 1)
	{
		return y;
	}
	else
	{
		return x;
	}
}

// ”äŠr‰‰ŽZŽq
template<class T>
bool Vector2Template<T>::operator==(const Vector2Template& vec)const
{
	return ((x == vec.x) && (y == vec.y));
}

template<class T>
bool Vector2Template<T>::operator!=(const Vector2Template& vec)const
{
	return !((x == vec.x) && (y == vec.y));
}

template<class T>
bool Vector2Template<T>::operator> (const Vector2Template& vec)const
{
	return ((x > vec.x) && (y > vec.y));
}

template<class T>
bool Vector2Template<T>::operator>=(const Vector2Template& vec)const
{
	return ((x >= vec.x) && (y >= vec.y));
}

template<class T>
bool Vector2Template<T>::operator< (const Vector2Template& vec)const
{
	return ((x < vec.x) && (y < vec.y));
}

template<class T>
bool Vector2Template<T>::operator<=(const Vector2Template& vec)const
{
	return ((x <= vec.x) && (y <= vec.y));
}


// ’P€‰‰ŽZŽq
template<class T>
Vector2Template<T>& Vector2Template<T>::operator+=(const Vector2Template& vec)
{
	x += vec.x;
	y += vec.y;

	return *this;
}

template<class T>
Vector2Template<T>& Vector2Template<T>::operator-=(const Vector2Template& vec)
{
	x -= vec.x;
	y -= vec.y;

	return *this;
}

template<class T>
Vector2Template<T>& Vector2Template<T>::operator*=(T v)
{
	x *= v;
	y *= v;

	return *this;
}

template<class T>
Vector2Template<T>& Vector2Template<T>::operator/=(T v)
{
	x /= v;
	y /= v;

	return *this;
}

template<class T>
Vector2Template<T> Vector2Template<T>::operator+(void)const
{
	return *this;
}

template<class T>
Vector2Template<T> Vector2Template<T>::operator-(void)const
{
	return Vector2Template<T>(-this->x,-this->y);
}



// Vector2 + int
template<class T>
Vector2Template<T> operator + (const Vector2Template<T>& u,T v)
{
	Vector2Template<T> vec;
	vec.x = u.x + v;
	vec.y = u.y + v;
	return vec;
}

// Vector2 - int
template<class T>
Vector2Template<T> operator - (const Vector2Template<T>& u,T v)
{
	Vector2Template<T> vec;
	vec.x = u.x - v;
	vec.y = u.y - v;
	return vec;
}

// Vector2 * int
template<class T>
Vector2Template<T> operator * (const Vector2Template<T>& u,T v)
{
	Vector2Template<T> vec;
	vec.x = u.x * v;
	vec.y = u.y * v;
	return vec;
}

// Vector2 / int
template<class T>
Vector2Template<T> operator / (const Vector2Template<T>& u,T v)
{
	Vector2Template<T> vec;
	vec.x = u.x / v;
	vec.y = u.y / v;
	return vec;
}

// Vector2 % int
template<class T>
Vector2Template<T> operator % (const Vector2Template<T>& u,T v)
{
	Vector2Template<T> vec;
	vec.x = u.x % v;
	vec.y = u.y % v;
	return vec;
}

// int * Vector2
template<class T>
Vector2Template<T> operator * (T u,const Vector2Template<T>& v)
{
	Vector2Template<T> vec;
	vec.x = u * v.x;
	vec.y = u * v.y;
	return vec;
}

// Vector2 + Vector2
template<class T>
Vector2Template<T> operator + (const Vector2Template<T>& u, const Vector2Template<T>& v)
{
	Vector2Template<T> vec;
	vec.x = u.x + v.x;
	vec.y = u.y + v.y;
	return vec;
}
// Vector2 - Vector2
template<class T>
Vector2Template<T> operator - (const Vector2Template<T>& u, const Vector2Template<T>& v)
{
	Vector2Template<T> vec;
	vec.x = u.x - v.x;
	vec.y = u.y - v.y;
	return vec;
}
// Vector2 * Vector2
template<class T>
Vector2Template<T> operator * (const Vector2Template<T>& u, const Vector2Template<T>& v)
{
	Vector2Template<T> vec;
	vec.x = u.x * v.x;
	vec.y = u.y * v.y;
	return vec;
}
// Vector2 / Vector2
template<class T>
Vector2Template<T> operator / (const Vector2Template<T>& u, const Vector2Template<T>& v)
{
	Vector2Template<T> vec;
	vec.x = u.x / v.x;
	vec.y = u.y / v.y;
	return vec;
}
// Vector2 % Vector2
template<class T>
Vector2Template<T> operator % (const Vector2Template<T>& u, const Vector2Template<T>& v)
{
	Vector2Template<T> vec;
	vec.x = u.x % v.x;
	vec.y = u.y % v.y;
	return vec;
}

template<class T>
Vector2Template<T> abs(const Vector2Template<T>& u)
{
	Vector2Template<T> tmp = u;
	if (tmp.x < 0)
	{
		tmp.x*= -1;
	}
	if (tmp.y < 0)
	{
		tmp.y *= -1;
	}
	
	return tmp;
}
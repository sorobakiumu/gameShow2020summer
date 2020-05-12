#pragma once
#include <cmath>

template<class T>class Vector2Template
{
public:
	Vector2Template();
	Vector2Template(T x,T y);
	~Vector2Template();
	T x;
	T y;

	// ‘ã“ü‰‰ŽZŽq
	Vector2Template& operator = (const Vector2Template& vec);
	// “YŽš‰‰ŽZŽq
	int operator [] (int i);

	// ”äŠr‰‰ŽZŽq
	bool operator == (const Vector2Template& vec)const;
	bool operator != (const Vector2Template& vec)const;
	bool operator >  (const Vector2Template& vec)const;
	bool operator >= (const Vector2Template& vec)const;
	bool operator <  (const Vector2Template& vec)const;
	bool operator <= (const Vector2Template& vec)const;
	// ’P€‰‰ŽZŽq
	Vector2Template& operator += (const Vector2Template& vec);
	Vector2Template& operator -= (const Vector2Template& vec);
	Vector2Template& operator *= (T v);
	Vector2Template& operator /= (T v);
	Vector2Template operator + (void) const;
	Vector2Template operator - (void) const;
};

// ƒxƒNƒgƒ‹‚Ì‰‰ŽZ

// Vector2 + int
template<class T>
Vector2Template<T> operator + (const Vector2Template<T>& u,T v);
// Vector2 - int
template<class T>
Vector2Template<T> operator - (const Vector2Template<T>& u,T v);
// Vector2 * int
template<class T>
Vector2Template<T> operator * (const Vector2Template<T>& u,T v);
// Vector2 /int
template<class T>
Vector2Template<T> operator / (const Vector2Template<T>& u, T v);
// vector2 % int
template<class T>
Vector2Template<T> operator % (const Vector2Template<T>& u, T v);

// int * Vector2
template<class T>
Vector2Template<T> operator * (T v,const Vector2Template<T>& u);

// Vector2 + Vector2
template<class T>
Vector2Template<T> operator + (const Vector2Template<T>& u, const Vector2Template<T>& v);
// Vector2 - Vector2
template<class T>
Vector2Template<T> operator - (const Vector2Template<T>& u, const Vector2Template<T>& v);
// Vector2 * Vector2
template<class T>
Vector2Template<T> operator * (const Vector2Template<T>& u, const Vector2Template<T>& v);
// Vector2 / Vector2
template<class T>
Vector2Template<T> operator / (const Vector2Template<T>& u, const Vector2Template<T>& v);
// Vector2 % Vector2
template<class T>
Vector2Template<T> operator % (const Vector2Template<T>& u, const Vector2Template<T>& v);

template<class T>
Vector2Template<T> abs(const Vector2Template<T>& u);


using Vec2Int = Vector2Template<int>;
using Vec2double = Vector2Template<double>;
using Vec2float = Vector2Template<float>;

#include "Details/Vector2.h"
#pragma once
#include<cmath>
#include <assert.h>
#include <DxLib.h>

template<typename T>
struct Vector2D
{
	T x;
	T y;
	Vector2D(T inx, T iny) :x(inx), y(iny) {}
	Vector2D() :x(0), y(0) {}
	Vector2D operator+(const Vector2D& rval) const{
		return Vector2D(x + rval.x, y + rval.y);
	}
	Vector2D operator-(const Vector2D& rval) const{
		return Vector2D(x - rval.x, y - rval.y);
	}

	void operator+=(const Vector2D& v) {
		x += v.x;
		y += v.y;
	}
	void operator-=(const Vector2D& v) {
		x -= v.x;
		y -= v.y;
	}
	Vector2D operator/ (const float& v) const{
		return Vector2D(x / v, y / v);
	}
	float Magnitude() const{
		return hypot(x, y);
	}
	//二乗を返す
	float SQMagnitude()const {
		return hypot(x,y)* hypot(x, y);
	}
	Vector2D Nomerize() const{
		float mag = Magnitude();
		return{ x / mag,y / mag };
	}
	Vector2D Nomerized() const {
		float mag = Magnitude();
		return{ x / mag,y / mag };
	}
	bool operator==(const Vector2D& v)
	{
		assert(!(isnan(v.x) || isnan(v.y)));
		return ((v.x == x) && (v.y == y));
	}
	bool operator!=(const Vector2D& v)
	{
		assert(!(isnan(v.x) || isnan(v.y)));
		return ((v.x != x) || (v.y != y));
	}
	float Dot(const Vector2D& v)
	{
		return v.x * x + v.y * y;
	}
	float Clas(const Vector2D& v)
	{
		return v.x * x - v.y * y;
	}
	Vector2D operator* (const float& v) const {
		return Vector2D(x * v, y* v);
	}
	bool IsNILL()const;
	static const Vector2D<float> NIL;
};

using Vector2 =Vector2D<int>;
using Vector2f = Vector2D<float>;
using Vec2Float = Vector2f;
using Position2 = Vector2D<int>;
using Position2f = Vector2D<float>;

// 線分
struct Segment
{
	Position2f start;//起点 
	Vector2f vec;//起点からもう１端点までのベクトル 
	Segment() {}
	Segment(const Position2f& s, const Position2f& v) :start(s), vec(v) {}
	Segment(float x, float y, float vx, float vy) :start(x, y), vec(vx, vy) {}
	static const Segment NIL;
	bool IsNILL();
	Position2f End();
};


struct Size
{
	int w, h;
};

// 矩形
struct Rect
{
	Position2f pos;
	Size size;

};

// 円形
struct Circle {
	Vector2f center;//中心
	float radius;//半径
	Circle() :center{ 0,0 }, radius(0){};
	Circle(const Position2f p, float r) :center{ p }, radius(r){};
	void AddRad(float);
	void SetRad(float);
	void SetCenter(Vec2Float);
	Vec2Float GetCenter();
	void Draw();
	void ShaderDraw(int,int);
};

// 行列(3*3)
struct Matrix {
	float m[3][3] = {};

};

///カプセル構造体
struct Capsule
{
	Position2f start;//起点
	Vector2f vec;//起点からもう１端点までのベクトル
	float radius;//カプセルの厚み
};

template <typename T>
T Clamp(T value, T minval = 0, T maxval = 1)
{
	return (std::min)((std::max)(value, minval), maxval);
}

template <typename T>
float Dot(Vector2D<T>& num, Vector2D<T>& num2)
{
	return num.x * num2.x + num.y * num2.y;
}

template <typename T>
float Cross(Vector2D<T> num, Vector2D<T> num2)
{
	return num.x * num2.y - num.y * num2.x;
}
float GetAngleTwoVector(Vec2Float&, Vec2Float&);

// 単位行列を返す
Matrix IdentityMat();

///平行移動行列を返す 
template <typename T>
Matrix TranslateMat(Vector2D<T>);

///回転行列を返す
Matrix RotateMat(float);

///２つの行列の乗算を返す 
Matrix MultipleMat(const Matrix& lmat, const Matrix& rmat);

///ベクトルに対して行列乗算を適用し、結果のベクトルを返す 
template <typename T>
Vector2D<T> MultipleVec(const Matrix, const Vector2D<T>);

Matrix operator*(const Matrix, const Matrix);
template <typename T>
Vector2D<T> operator*(const Matrix& mat, const Vector2D<T>& vec);

template <typename T>
Vector2D<T> RotaVec(const Vector2D<T>, const Vector2D<T>, float);

template<typename T>
inline bool Vector2D<T>::IsNILL() const
{
	return isnan(x) || isnan(y);
}


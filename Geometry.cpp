#include "Geometry.h"
#include <DxLib.h>
#include <vector>

const Vector2D<float> Vector2D<float>::NIL(NAN, NAN);
const Segment Segment::NIL(Vector2f::NIL, Vector2f::NIL);

namespace DxLib
{
	const VECTOR V2V(const Vector2f& vec)
	{
		return VGet(vec.x, vec.y, 0);
	}
}

bool Segment::IsNILL()
{
	return isnan(vec.x) || isnan(vec.y);
}
Position2f Segment::End()
{
	return start + vec;
}


void Circle::AddRad(float rad)
{
	radius += rad;
}

void Circle::SetRad(float rad)
{
	radius = rad;
}

void Circle::SetCenter(Vec2Float pos)
{
	center = pos;
}

Vec2Float Circle::GetCenter()
{
	return center;
}

void Circle::Draw()
{
	DrawCircle(center.x,center.y,radius,0xffffff,false);
}

void Circle::ShaderDraw(int pixel,int image)
{
	std::vector<VERTEX2DSHADER> vertex;
	vertex.resize(2*361);
	for (auto& v:vertex)
	{
		v.dif.a = 0xff;
		v.dif.r = v.dif.g = 0xa0;
		v.dif.b = 0xff;
		v.u = 0.0f;
		v.v = 0.0f;
		v.rhw = 5.0f;
	}
	auto tmpV = Vector2f(0,-radius);
	for (int i = 0; i < 361; i++)
	{
		vertex[i * 2].pos = V2V(center);
		vertex[i * 2].u = vertex[i * 2].pos.x / 800;
		vertex[i * 2].v = vertex[i * 2 ].pos.y / 600;
		vertex[i * 2 + 1].pos = V2V(center + tmpV);
		vertex[i * 2 + 1].u = vertex[i * 2 + 1].pos.x / 800;
		vertex[i * 2 + 1].v = vertex[i * 2 + 1].pos.y / 600;
		tmpV = RotateMat(DX_PI_F/180.0) * tmpV;
	}

	DxLib::SetUsePixelShader(pixel);
	DxLib::SetUseTextureToShader(0, image);
	DrawPrimitive2DToShader(vertex.data(),vertex.size(), DX_PRIMTYPE_TRIANGLESTRIP);
}


Matrix IdentityMat()
{
	Matrix mat;
	mat.m[0][0] = 1;
	mat.m[1][1] = 1;
	mat.m[2][2] = 1;
	return mat;
}

Matrix RotateMat(float ang)
{
	Matrix mat;
	mat.m[0][0] = cos(ang);
	mat.m[0][1] = -sin(ang);
	mat.m[1][0] = sin(ang);
	mat.m[1][1] = cos(ang);
	mat.m[2][2] = 1;
	return mat;
}

template <typename T>
Matrix TranslateMat(Vector2D<T> vec)
{
	Matrix mat;
	mat.m[0][0] = 1;
	mat.m[0][2] = vec.x;
	mat.m[1][1] = 1;
	mat.m[1][2] = vec.y;
	mat.m[2][2] = 1;
	return mat;
}

template<typename T>
Vector2D<T> MultipleVec(const Matrix mat, const Vector2D<T> vec)
{
	return Vector2D<T>(vec.x * mat.m[0][0] + vec.y * mat.m[0][1] + 1 * mat.m[0][2],
		vec.x * mat.m[1][0] + vec.y * mat.m[1][1] + 1 * mat.m[1][2]);
}

Matrix MultipleMat(const Matrix& lmat, const Matrix& rmat)
{
	Matrix ret = {};

	for (int k = 0; k <= 2; ++k) {
		for (int j = 0; j <= 2; ++j) {
			for (int i = 0; i <= 2; ++i) {
				ret.m[k][j] += lmat.m[k][i] * rmat.m[i][j];
			}
		}
	}

	return ret;

}

Matrix operator*(const Matrix lmat, const Matrix rmat)
{
	return MultipleMat(lmat, rmat);
}

template<typename T>
Vector2D<T> operator*(const Matrix& mat, const Vector2D<T>& vec)
{
	return MultipleVec(mat, vec);
}

template<typename T>
Vector2D<T> RotaVec(const Vector2D<T> vec, const Vector2D<T> center, float ang)
{
	Matrix mat = MultipleMat(TranslateMat(Vec2Float(center.x, center.y)),
		MultipleMat(RotateMat(ang),
			TranslateMat(Vec2Float(-center.x, -center.y))));

	return MultipleVec(mat, vec);
}

Fan::Fan() :Center(0, 0), Vec1(0, 0), Vec2(0, 0), Radius(0), Angle(0)
{
}

Fan::Fan(Position2f center, Vec2Float v1, Vec2Float v2):Center(center),Vec1(v1),Vec2(v2)
{
	Radius = Vec1.Magnitude();
	Angle = 0;
}

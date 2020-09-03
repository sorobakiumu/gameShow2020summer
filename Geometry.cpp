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


void Circle::Draw()
{
	DrawCircle(center.x,center.y,radius,0xffffff,false);
}

void Circle::ShaderDraw(int pixel,int image)
{
	std::vector<VERTEX2DSHADER> vertex;
	vertex.resize(2*360);
	for (auto& v:vertex)
	{
		v.dif.a = 0xff;
		v.dif.r = v.dif.g = 0xa0;
		v.dif.b = 0xff;
		v.u = 0.0f;
		v.v = 0.0f;
		v.rhw = 5.0f;
	}
	for (int i = 0; i < 360; i++)
	{
		vertex[i * 2].pos = V2V(center);
		vertex[i * 2].u = vertex[i * 2].pos.x / 800;
		vertex[i * 2].v = vertex[i * 2 ].pos.y / 600;
		vertex[i * 2 + 1].pos = V2V({ center.x + cos((float)i/180*DX_PI_F)*radius,center.y + sin((float)i / 180 * DX_PI_F)*radius });
		vertex[i * 2 + 1].u = vertex[i * 2 + 1].pos.x / 800;
		vertex[i * 2 + 1].v = vertex[i * 2 + 1].pos.y / 600;
	}

	DxLib::SetUsePixelShader(pixel);
	DxLib::SetUseTextureToShader(0, image);
	DrawPrimitive2DToShader(vertex.data(),vertex.size(), DX_PRIMTYPE_TRIANGLELIST);
}

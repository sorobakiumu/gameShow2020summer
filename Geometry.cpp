#include "Geometry.h"
const Vector2D<float> Vector2D<float>::NIL(NAN, NAN);
const Segment Segment::NIL(Vector2f::NIL, Vector2f::NIL);

bool Segment::IsNILL()
{
	return isnan(vec.x) || isnan(vec.y);
}
Position2f Segment::End()
{
	return start + vec;
}
#include "./vector2.h"

t_vector2 get_vector_from_floats(float x, float y)
{
	t_vector2 vector;
	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vector2 sum_vector2(t_vector2 a, t_vector2 b)
{
	t_vector2 result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}
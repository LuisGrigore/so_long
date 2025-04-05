#ifndef VECTOR2_H
# define VECTOR2_H

typedef struct s_vector2
{
	float	x;
	float	y;
}	t_vector2;

t_vector2 get_vector_from_floats(float x, float y);
t_vector2 sum_vector2(t_vector2 a, t_vector2 b);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:23:24 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/06 17:23:32 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

typedef struct s_vector2
{
	float	x;
	float	y;
}	t_vector2;

t_vector2	get_vector_from_floats(float x, float y);
t_vector2	sum_vector2(t_vector2 a, t_vector2 b);

#endif
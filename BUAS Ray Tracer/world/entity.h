#pragma once
#include "../math/mathlibrary.h"

namespace brt
{
	class entity
	{
	public:
		entity();
		explicit entity(const vec3 &pos);
		virtual ~entity();

		virtual void update(float) {}

		const mat4 get_transformation_matrix() const
		{
			mat4 result = mat4::identity();
			result *= mat4::scale(scale);
			result *= mat4::rotateX(rotation.m_X) * mat4::rotateY(rotation.m_Y) * mat4::rotateZ(rotation.m_Z);
			result *= mat4::translate(position);
			return result;

			//return mat4::identity() * mat4::rotateX(rotation.m_X) * mat4::rotateY(rotation.m_Y) * mat4::rotateZ(rotation.m_Z) * mat4::translate(position);
		}

	public:
		vec3 position;
		vec3 rotation; // TODO: quaternions?
		vec3 scale;
	};
}
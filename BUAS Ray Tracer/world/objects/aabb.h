#pragma once
#include "sceneobject.h"

namespace brt
{
	class aabb : public sceneobject
	{
	public:
		aabb(const vec3& pos, std::shared_ptr<material> mat);
		virtual ~aabb();

		virtual vec3 get_normal_at(const vec3& point) const override;

		virtual bool has_intersection(const vec3& origin, const vec3& dir, intersection& info) override;

	protected:
		virtual vec3 get_bound(int b) const
		{
			//return m_localbounds[b] + position;
			return m_localbounds[b] + get_transformation_matrix().position();
		}

	protected:
		vec3 m_localbounds[2];
	};
}
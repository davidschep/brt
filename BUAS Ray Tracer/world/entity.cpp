#include "entity.h"

namespace brt
{
	entity::entity()
	{
		position = vec3();
		rotation = vec3();
		scale = vec3(1.f, 1.f, 1.f);
	}

	entity::entity(const vec3 &pos)
	{
		position = pos;
		rotation = vec3();
		scale = vec3(1.f, 1.f, 1.f);
	}

	entity::~entity()
	{
	}
}
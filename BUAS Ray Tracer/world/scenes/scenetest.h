#pragma once
#include "scene.h"

namespace brt
{
	class scenetest : public scene
	{
	public:
		scenetest(raytracer* application);
		virtual ~scenetest();

		virtual void update(float deltat) override;

	private:
		void build_scene();

	private:
	};
}
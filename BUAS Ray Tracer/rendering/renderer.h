#pragma once
#include <memory>

class vec3;

namespace sf
{
	class RenderWindow;
	class Color;
	class Image;
}

namespace brt
{
	struct ray;
	class scene;
	class raytracer;
	class sceneobject;
	class light;
	struct color;
	
	class renderer
	{
	public:
		explicit renderer(raytracer* app);
		~renderer();

		void update(float deltat);

		sf::RenderWindow* get_window() const { return m_window; }
		void set_resolution(unsigned int width, unsigned int height);

		void window_clear() const;
		void window_display() const;

	private:
		ray calculate_point_sample_ray(int x, int y) const;

		const color calculate_point_sample(ray& r, int recursivecount) const;

		color calculate_ambient_shading(const sf::Color& colatpoint) const;
		color calculate_lamberts_shading(const sf::Color& colatpoint, const std::shared_ptr<light> l, const vec3& unitsurfacenormal, const vec3& unitlightdir) const;
		color calculate_phong_shading(const sceneobject* obj, const std::shared_ptr<light> l, const vec3& unitsurfacenormal, const vec3& unitlightdir, const float specintensity, const sf::Color& speccol) const;
		color calculate_ideal_reflection(int recursivecount, const ray& r, const vec3& normalat, const vec3& intersecpoint) const;
		color calculate_refraction(int recursivecount, const ray& r, const vec3& normalat, const vec3& intersecpoint, const float refrectiveindex) const;
		float calculate_fresnel(const ray& r, const vec3& normalat, const float refrectiveindex) const;

		bool lies_in_shadow(const vec3& intersecpoint, const sceneobject* obj, const vec3& normalat, const std::shared_ptr<light> l) const;
		vec3 get_light_dir(const std::shared_ptr<light> l, const vec3& intersecpoint) const;

	private:
		raytracer* m_application;

		sf::RenderWindow* m_window;

		sf::Image* m_screenimage;
	};
}
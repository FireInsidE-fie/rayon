#ifndef CAMERA_H
# define CAMERA_H

# include "rtweekend.h"
# include "hittable.h"

class camera
{
public:
	double	aspect_ratio	= 1.0;	// Ratio of image width over height
	int		image_width		= 100;	// Rendered image pixel count in width

	void render(const hittable& world)
	{
		initialize();

		// Output render information in PPM format

		// Output header
		std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

		// Output color information
		for (int j = 0; j < image_height; j++)
		{
			std::clog << "\r[!] - Scanlines remaining: " << (image_height - j) << ' ' << std::flush;
			for (int i = 0; i < image_width; i++)
			{
				auto pixel_center = pixel00_loc + i * pixel_delta_u + j * pixel_delta_v;
				auto ray_direction = pixel_center - center;
				ray r(center, ray_direction);

				color pixel_color = ray_color(r, world);
				write_color(std::cout, pixel_color);
			}
		}

		std::clog << "\r[!] - Done.                    \n";
	}

private:
	int		image_height;	// Rendered image pixel count in height
	point3	center;			// Camera center
	point3	pixel00_loc;	// Location of pixel 0, 0
	vec3	pixel_delta_u;	// Offset to pixel to the right
	vec3	pixel_delta_v;	// Offset to pixel below

	void initialize()
	{
		// Calculate the image height and make sure it is at least 1
		image_height = static_cast<int>(image_width / aspect_ratio);
		image_height = (image_height < 1) ? 1 : image_height;

		center = point3(0, 0, 0);

		// Determine viewport dimensions
		constexpr auto focal_length = 1.0;
		constexpr auto viewport_height = 2.0;
		const auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);

		// Calculate the horizontal and vertical viewport vectors (0, 0 is top left)
		auto viewport_u = vec3(viewport_width, 0, 0);
		auto viewport_v = vec3(0, -viewport_height, 0);

		// Calculate the horizontal and vertical deltas as vectors from pixel to pixel
		pixel_delta_u = viewport_u / image_width;
		pixel_delta_v = viewport_v / image_height;

		// Calculate the location of the 0, 0 pixel
		auto viewport_upper_left =
			center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
		pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
	}

	color ray_color(const ray& r, const hittable& world) const
	{
		hit_record rec;

		if (world.hit(r, interval(0, infinity), rec))
			return 0.5 * (rec.normal + color(1, 1, 1));

		vec3 unit_direction = unit_vector(r.direction());
		auto a = 0.5 * (unit_direction.y() + 1.0);
		return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.88,0.52,0.27);
	}
};

#endif //CAMERA_H

#include "vec3.h"
#include "color.h"

#include <iostream>

int main()
{
	// Image

	const int image_width = 2560;
	const int image_height = 2560;

	// Output render information in PPM format

	// Output header
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	// Output color information
	for (int j = 0; j < image_height; j++)
	{
		std::clog << "\r[!] - Scanlines remaining: " << (image_height - j) << ' ' << std::flush;
		for (int i = 0; i < image_width; i++)
		{
			auto pixel_color = color(double(i) / (image_width - 1), 0, double(j) / (image_height - 1));
			write_color(std::cout, pixel_color);
		}
	}

	std::clog << "\r[!] - Done.                    \n";

	return 0;
}
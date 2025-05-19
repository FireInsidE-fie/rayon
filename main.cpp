#include <iostream>

int main()
{
	// Image

	int image_width = 2560;
	int image_height = 2560;

	// Output render information in PPM format

	// Output header
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	// Output color information
	for (int j = 0; j < image_height; j++)
	{
		std::clog << "\r[!] - Scanlines remaining: " << (image_height - j) << ' ' << std::flush;
		for (int i = 0; i < image_width; i++)
		{
			double r = double(i) / (image_width - 1);
			double g = double(j) / (image_height - 1);
			double b = 0.0;

			int ir = int(255.999 * r);
			int ig = int(255.999 * g);
			int ib = int(255.999 * b);

			std::cout << ir << ' ' << ig << ' ' << ib << '\n';
		}
	}

	std::clog << "\r[!] - Done.                    \n";

	return 0;
}
#ifndef COLOR_H
# define COLOR_H

# include "interval.h"
# include "vec3.h"

// Alias to vec3 to enhance clarity when talking about a RGB color.
using color = vec3;

void write_color(std::ostream& out, const color& pixel_color)
{
	double r = pixel_color.x();
	double g = pixel_color.y();
	double b = pixel_color.z();

	// Expand the 0 to 1 values to 0 to 255 range (one byte)
	static const interval intensity(0.000, 0.999);
	const int rbyte = static_cast<int>(255.999 * intensity.clamp(r));
	const int gbyte = static_cast<int>(255.999 * intensity.clamp(g));
	const int bbyte = static_cast<int>(255.999 * intensity.clamp(b));

	// Write out the pixel's color components in a PPM formatted line
	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif //COLOR_H

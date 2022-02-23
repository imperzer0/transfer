#include <iostream>
#include <cmath>

static constexpr double from = 0.4;
static constexpr double to = 1.0;
static constexpr double gap = 0.1;
static constexpr double dot_count = (to - from) / gap + 1;

double func(double x)
{
	return x + std::sqrt(x) + std::cbrt(x) - 2.5;
}

int main()
{
	double x;
	for (int i = 0; i < dot_count; ++i)
	{
		x = from + i * dot_count;
		std::cout << "(x = " << x << ", y = " << func(x) << ");\n";
	}
}



#include <iostream>
#include <cmath>

static constexpr double from = 0.4;
static constexpr double to = 1.0;
static constexpr double precision = 0.01;

double func(double x)
{
	return x + std::sqrt(x) + std::cbrt(x) - 2.5;
}

int main()
{
	double l = from, r = to, m;
	while (r - l > precision)
	{
		m = (l + r) / 2;
		if (func(m) > 0)
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}
	std::cout << "(x = " << l << ", y = " << func(l) << ");\n";
}


#include <iostream>
#include <cmath>

static constexpr double from = 0.4;
static constexpr double to = 1.0;
static constexpr double precision = 0.01;

double sqr(double x)
{
	return x * x;
}

double func(double x)
{
	return x + std::sqrt(x) + std::cbrt(x) - 2.5;
}

double func1(double x)
{
	return 1 + 1 / (2 * std::sqrt(x)) + 1 / (3 * sqr(std::cbrt(x)));
}

int main()
{
	double pos = from;
	do
	{
		pos -= func(pos) / func1(pos);
	}
	while (std::abs(func(pos)) >= precision);
	std::cout << "(x = " << pos << ", y = " << func(pos) << ");\n";
}


#include <iostream>
#include <fstream>

static constexpr double from = -5;
static constexpr double to = 5;
static constexpr double gap = 0.1;
static constexpr double dot_count = (to - from) / gap + 1;

double func(double x)
{
	return (x < -3 ? 3 : 4);
}

int main()
{
	std::ofstream file("out.txt", std::ios_base::out);
	if (file.is_open())
	{
		double x;
		for (int i = 0; i < dot_count; ++i)
		{
			x = from + i * gap;
			file << "(x = " << x << ", y = " << func(x) << ");\n";
		}
		file.close();
	}
	return 0;
}


#include <iostream>
#include <fstream>

static constexpr double from = -5;
static constexpr double to = 5;
static constexpr double gap = 0.1;
static constexpr double dot_count = (to - from) / gap + 1;

double func(double x)
{
	return (x < -3 ? 3 : 4);
}

int main()
{
	std::ifstream file("out.txt", std::ios_base::in);
	if (file.is_open())
	{
		double x, y, min_el = 10000.0, max_el = -10000.0;
		int min_el_idx = -1, max_el_idx = -1;
		for (int i = 0; i < dot_count; ++i)
		{
			file >> x >> y;
			if (min_el > y)
			{
				min_el = y;
				min_el_idx = i;
			}
			if (max_el < y)
			{
				max_el = y;
				max_el_idx = i;
			}
		}
		std::cout << "minimal: func[" << min_el_idx << "] = " << min_el << ";\n";
		std::cout << "maximal: func[" << max_el_idx << "] = " << max_el << ";\n";
		file.close();
	}
	return 0;
}



#include <iostream>
#include <fstream>

static constexpr double from = -5;
static constexpr double to = 5;
static constexpr double gap = 0.1;
static constexpr size_t dot_count = (to - from) / gap + 1;

double func(double x)
{
	return (x < -3 ? 3 : 4);
}

int main()
{
	std::ifstream file("out.txt", std::ios_base::in);
	if (file.is_open())
	{
		double x, y, array[dot_count];
		for (int i = 0; i < dot_count; ++i)
		{
			file >> x >> y;
			array[i] = y;
		}
		std::sort(array, array + dot_count);
		for (int i = 0; i < dot_count; ++i)
		{
			std::cout << "array[" << i << "] = " << array[i] << ";\n";
		}
		file.close();
	}
	return 0;
}

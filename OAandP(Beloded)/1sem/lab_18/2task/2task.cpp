#include <iostream> 
float metodPrjam(float(*fun) (float), float a, float b, float h);
float integ(float(*) (float), float, float, float);
float f(float);
int main()
{
	float z;
	z = metodPrjam(f, (float)0.0, (float)10.0, (float)0.01);
	std::cout << "Result=" << z;
}

float metodPrjam(float(*fun) (float), float a, float b, float h)
{
	float x, s = 0.0;
	x = a + h;
	while (x <= b)
	{
		s += h * fun(x);
		x = x + h;
	}
	return s / 2;
}

float f(float x)
{
	return (2 * x + 5);
}

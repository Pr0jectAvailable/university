/* ѕример 1 */
//#include <iostream>
//void main()
//{
//	float x = 3, y;
//	y = x * x + sin(x);
//	std::cout << y;
//}

//4 13 вар

//#include <iostream>
//void main()
//{
//	double t, y, a = 1.5, c = 2, d = 0.5e-8; /*с было 9*/
//	t = d * c + a * sqrt(c - 1);
//	y = 0.5 * t / d + exp(a);
//	std::cout << "t=" << t;
//	std::cout << "\ny=" << y;
//}

//5 16 вар
#include <iostream>
void main() {
	double y, w, m = 6, z = 0.05e-5;
	y = cos(5 * m) / pow(sin(0.4 * m), 2);
	w = 4 * z * y - 7 * exp(-2 * y);
	
	std::cout << "y = " << y;
	std::cout << "\nw = " << w;
}

//доп 8 вар
//#include <iostream>
//void main() {
//	double s, t, x = 0.1, j = 12, y = 5e-6;
//	s = 0.4 * x - 1 / j * tan(y);
//	t = s - sin(s);
//	std::cout << "s = " << s;
//	std::cout << "\nt = " << t;
//}

//доп 7 вар
//#include <iostream>
//void main() {
//	double y, w, x = 1.4, m = 6, z = 5e-7;
//	y = sqrt(1 + x) - cos(2 / m);
//	w = 0.6 * z - 2 * exp(-2 * y * m);
//	std::cout << "y = " << y;
//	std::cout << "\nw = " << w;
//}

//доп 15 вар
//#include <iostream>
//void main() {
//	double y, r, a = 1.75, b = 4.5e-4;
//	y = a * exp(-2 * b) - sqrt(1 + a);
//	r = log(1 + 20 * b) / (1 + a);
//	std::cout << "y = " << y;
//	std::cout << "\nr = " << r;
//}
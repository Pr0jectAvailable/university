#ifndef LAB5_h
#define LAB5_h

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif // _WIN32


extern "C" {
	EXPORT int** newMatrix(int size);
	EXPORT void matPrint(int** mat, int size);
	EXPORT int** mutMatrix0(int** mat1, int size1, int** mat2, int size2);
	EXPORT double determinant(int** matrix, int n);
}

#endif
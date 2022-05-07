#include "C:\Users\Mustafa Eissa\Desktop\std_lib_facilities.h"

int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void f(int arr[], int x)
{
	int la[10];
	for (int i = 0; i < 10; i++) {
		la[i] = ga[i];
	}
	for (const auto& a : la)
		cout << a << ' ' << '\n';

	int* p = new int[x];
	for (int i = 0; i < x; ++i) p[i] = arr[i];

	for (int i = 0; i < x; ++i)
		cout << p[i] << '\n';

	delete[] p;
}

int fac(int n)
{
	return n > 1 ? n * fac(n - 1) : 1;
}
int main()
try {
	
	f(ga, 10);

	int aa[10] = {};
	for (int i = 1; i <= 10; i++)
		aa[i] = fac(i);
	
	f(aa, 10);
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception\n";
	return 2;
}
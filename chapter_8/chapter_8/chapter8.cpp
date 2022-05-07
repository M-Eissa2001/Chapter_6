#include "C:\Users\Mustafa Eissa\Desktop\std_lib_facilities.h"
 
/* This function has no effect on the variables.
It just copies the value of the parametersand swaps the copy.
Original values are not affected. It does accept explicit values or variables
*/ 

void swap_v(int a, int b) 
{
	int temp;
	temp = a,
	a = b;
	b = temp;
}

/*
The fnction does recieve references of variables only. 
Constants nor explicit values are not permitted, since the reference of constants cannot be altered, 
and explicit values have no reference. 
*/

void swap_r(int& a, int& b)
{
	int temp;
	temp = a,
		a = b;
	b = temp;
}

/*
This function is not meant to compile. Its arguments are constants. The function body is supposed to be swapping 
the reference of those constants, the thing that is not allowed, nor the values of them.

void swap_cr(const int& a, const int& b)
{
	int temp;
	temp = a,
	a = b;
	b = temp;	
} */

int main()
{
	int x = 7;
	int y = 9;
	swap_r(x, y); 
	swap_v(7, 9);
	const int cx = 7;
	const int cy = 9;
	//swap_cr(cx, cy);
	//swap_cr(7.7, 9.9);
	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx, dy);
	swap_v(7.7, 9.9);
	cout << x << " " << y << " " << cx << " " << cy << " " << dx << " " << dy;
}
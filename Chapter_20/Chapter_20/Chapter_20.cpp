#include "C:\Users\Mustafa Eissa\Desktop\std_lib_facilities.h" 


template <typename T>

void increasea_value(T& temp, int n) 
{
	for (auto& a : temp) 

		a += n;
}

template <typename T>

void print(T& temp)
{
	for (auto& a : temp)
		cout << a << endl;
}

template <typename T1, typename T2>
T2 my_copy(T1 f1, T1 e1, T2 f2) 
{
	for (T1 p = f1; p != e1; p++)
	{
		*f2 = *p;
		f2++;
	}
	return f2;
}


int main()
{
	array <int,10> arr = { 0,1,2,3,4,5,6,7,8,9 }; 
	vector <int> vec = { 0,1,2,3,4,5,6,7,8,9 };
	list <int> lis = { 0,1,2,3,4,5,6,8,7,8,9 };

	array <int, 10> arr_copy = arr;
	vector <int> vec_copy = vec;
	list <int> lis_copy = lis;

	increasea_value(arr_copy, 2);
	increasea_value(vec_copy, 3);
	increasea_value(lis_copy, 5);
	
	cout << "Value of array: " << endl; print(arr_copy);
	cout << "Values of vector: " << endl; print(vec_copy);
	cout << "Values of list: " << endl; print(lis_copy);

	my_copy(arr.begin(), arr.end(), vec_copy.begin());
	my_copy(lis.begin(), lis.end(), arr_copy.begin());

	vector <int> ::iterator vit;
	vit = find(vec.begin(), vec.end(), 3);
	if (vit != vec.end())
		cout << "Found at " << distance(vec.begin(), vit) << endl;
	else
		cout << "Not found..\n";

	list <int> ::iterator lit;
	lit = find(lis.begin(), lis.end(), 27);
	if (lit != lis.end())
		cout << "Found at " << distance(lis.begin(), lit) << endl;
	else
		cout << "Not found..\n";


	return 0;
}
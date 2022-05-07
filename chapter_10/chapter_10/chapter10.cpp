#include "C:\Users\Mustafa Eissa\Desktop\std_lib_facilities.h"

struct point {
	int x;
	int y;

	point() {}
	point(int xx, int yy) {
		x = xx;
		y = yy; 
	}
};

istream& operator >>(istream& is, point& p)
{
	char ch1, ch2, ch3;
	int xx, yy;
	is >> ch1 >> xx >> ch2 >> xx>> ch3;
	if (ch1 != '(' || ch2 != ',')
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}
	if (!is || ch3 != ')') {
		if (is.eof()) return is;
		error("Incorrect point");
	}
	p.x = xx;
	p.y = yy;
	return is;
	
}

ostream& operator<<(ostream& os, point& p)
{
	return os << '(' << p.x << ',' << p.y << ')';
}


void read_from_file(vector<point>& points, string& name)
{
	ifstream ist{ name };
	ist.exceptions(ist.exceptions() | ios_base::badbit);

	if (!ist) error("can't open file ", name);
	for (point p; ist >> p; )
		points.push_back(p);
}


int main()
try {
	cout << "Enter 7 (x,y) pairs\n";
	vector<point> original_points;
	for (int i = 0; i < 7; i++)
	{
		point x;
		cin >> x;
		original_points.push_back(x);


		for (point p : original_points)
			cout << p;
		cout << '\n';


		string fname = "mydata.txt";
		ofstream ost{ fname };
		if (!ost) error("could not open file ", fname);

		for (point p : original_points)
			ost << p;
		ost.close();

		// 5. Read the file back into a vector
		vector<point> processed_points;
		read_from_file(processed_points, fname);

		for (point p : processed_points)
			cout << p;
		cout << '\n';

		if (original_points.size() != processed_points.size())
			cout << "Something's wrong!\n";
	}
}
	catch (exception& e) {
		cerr << "Error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Call for help. Something bad happened!\n";
		return 2;
	}

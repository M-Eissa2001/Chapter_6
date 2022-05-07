#include "C:\Users\Mustafa Eissa\Desktop\std_lib_facilities.h"


template<typename T>
    struct S
{
    private:
    T val;

    public:
    S(T v)
    {
        val = v;
    }
    void set(T v)
    {
        val = v;
    }
    T& get();
    const T& get()const;

    S& operator=(const T&);

};


template<typename T>
    S<T>& S<T>::operator=(const T& strct)
{
    val = strct;
    return this; /* refers to the struct you've made */
}

template<typename T>
    T& S<T>::get()
{
    return val;
}

template<typename T>
void read_val(T& v)
{
    cin >> v;
    val = v;
}

template<typename T>
const T& S<T>::get()const
{
    return val;
}

template<typename T>
    istream& operator>>(istream& is, vector<T>& v)
{
    char ch;
    cin >> ch;
    if (ch != '{') {
        error(" '{' was expected");
        return cin;
    }
    for (T val; cin >> val; ) {
        v.push_back(val);
        cin >> ch;
        if (ch != ',') break;
    }
    return cin;
}
template<typename T>
    ostream& operator<<(ostream& os, vector<T>& v)
{
    os << "{ ";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i] << (i < v.size() - 1 ? ", " : " ");
    }
    os << "}\n";

    return os;
}
int main()
{
    S<int> integar(5);
    S<double> doublenum(1.1);
    S<char> charcter('c');
    S<string> word("WORD");
    S<vector<int>> vec{ vector<int>{0,1,2,3,4,5,6} };

    //cout<< integar.val;
    cout << integar.get() << endl;
    doublenum.set(2.2);
    cout << doublenum.get() << endl;
    doublenum = 3.4;
    cout << doublenum.get() << endl;

    int val;
    read_val(val);
    S<int> Test(val);

    return 0;
}
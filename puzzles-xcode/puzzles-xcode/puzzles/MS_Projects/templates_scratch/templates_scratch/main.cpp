#include <iostream>
using namespace std;

class Cents
{
private: 
		int m_nCents;

public:
		Cents(int nCents):m_nCents(nCents)
		{
				//cout << "Instantiated with " << nCents << " Cents" << endl;
		}
				
		
		friend ostream& operator << (ostream &out, const Cents &cCents)
		{
				out << cCents.m_nCents << " cents";
				return out;
		}

		void operator += (Cents pCents)
		{
				m_nCents += pCents.m_nCents;
		}

		void operator /= (Cents pCents)
		{
				m_nCents /= pCents.m_nCents;
		}

		void operator -= (Cents pCents)
		{
				m_nCents -= pCents.m_nCents;
		}
};

template <typename T>
T maxTemplated(T tX, T tY)
{
		return (tX > tY ? tX : tY);
}

template <typename T>
T avgTemplated(T *tx, int numElements)
{
		T sum = 0;
		for(int i=0; i<numElements; i++)
		{
				sum += tx[i];
		}

		sum /= numElements;
		return sum;
}

int main(void)
{
		Cents c100(100);
		Cents cArray[] = { Cents(50), Cents(20), Cents(30)} ;

		int a=10, b=20;
		int arr[3] = {1,2,3};

		cout << "max of " << a << " " << b << " " << "is " << maxTemplated(a,b) << endl;

		cout << "Avg is: " << avgTemplated(cArray, 3) << endl;

		return 0;
}








#if 0
template <class typeName> void swapargs(typeName &x, typeName &y)
{
	typeName temp;
	temp = x;
	x = y;
	y = temp;
	return;
}

int main()
{
	int x=10, y=20;
	char a='a', b = 'b';
	double d1 = 5.2, d2 = 7.7;

	cout << "Original x, y::" << x << ' ' << y << '\n';
	cout << "Original a, b::" << a << ' ' << b << '\n';
	cout << "Original d1, d2::" << d1 << ' ' << d2 << '\n';

	swapargs(x, y);
	swapargs(a, b);
	swapargs(d1, d2);

	cout << "Swapped x, y::" << x << ' ' << y << '\n';
	cout << "Swapped a, b::" << a << ' ' << b << '\n';
	cout << "Swapped d1, d2::" << d1 << ' ' << d2 << '\n';

	return 0;
}

#endif


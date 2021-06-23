#include<iostream>
using namespace std;

template<typename T>
class vector
{
private:
	int size;
	T *arr;

public:
	vector() {
		cout << "constructor" << endl;
		size = 0;
	 }

	
	int GetSize() {
		return this->size;
	}

	void reserve(int kol) {
		arr = new T[kol];
		this->size += kol;
	}


	void push_back(T element) {

	}

	T &operator[](int const& elem) {
		return *(arr + elem);
	}

	vector& operator=(vector& a) {
		for (int i = 0; i < a.GetSize(); i++) {
			*(this->arr + i) = a[i];
		}
		this->size = a.GetSize();
		return *this;
	}
	
	vector& operator+(vector& a) {
		for (int i = 0; i < a.GetSize(); i++) {
			*(this->arr + this->size + i) = a[i];
		}
		this->size += a.GetSize();
		return *this;
	}




	friend ostream& operator<<(ostream &out,vector& a) {

		for (int i = 0; i < a.GetSize(); i++) {
			out << a[i] << " ";
		}
		return out;
	}

};

int main() {
	vector<int> a;
	a.reserve(5);
	for (int i = 0; i < a.GetSize(); i++) {
		a[i] = i + 1;
	}
	cout <<"a" << a <<"\n";
	vector<int> b;
	b.reserve(9);
	for (int i = 0; i < b.GetSize(); i++) {
		b[i] = i + 10;
	}
	cout << "b" << b << "\n";
	cout << "a+b" << (a+b) << "\n";
	cout << "a=b" << (a=b) << "\n";
	return 0;
}
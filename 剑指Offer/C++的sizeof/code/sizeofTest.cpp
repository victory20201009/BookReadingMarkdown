#include<iostream>

using namespace std;

class Foo {};

class Foo1 {
public:
	Foo1() {};
	~Foo1() {};
};

class Foo2 {
public:
	Foo2() {};
	virtual ~Foo2() {};
};

int main() {
	Foo foo;
	cout << "foo �Ĵ�С��: " << sizeof(foo) << endl;
	Foo1 foo1;
	cout << "���й��캯�����������������ʹ�С��: " << sizeof(foo1) << endl;

	Foo2 foo2;
	cout << "���й��캯�������������������ʹ�С��: " << sizeof(foo2) << endl;
	return 0;
}
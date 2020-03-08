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
	cout << "foo 的大小是: " << sizeof(foo) << endl;
	Foo1 foo1;
	cout << "带有构造函数和析构函数的类型大小是: " << sizeof(foo1) << endl;

	Foo2 foo2;
	cout << "带有构造函数和虚析构函数的类型大小是: " << sizeof(foo2) << endl;
	return 0;
}
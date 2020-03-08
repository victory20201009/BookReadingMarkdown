#include<iostream>
#include<string>

using namespace std;

class CMyString {
public:
	CMyString(char* data = NULL) {
		if (data != NULL) {
			int len = strlen(data)+1;
			buf = new char[len];
			strcpy(buf, data);
		}
	}

	CMyString(const CMyString& str) {
		if (this != &str) {
			char* tmp = buf;
			if (str.buf != NULL) {
				int len = strlen(str.buf) + 1;
				char* newbuf = new char[len];
				strcpy(newbuf, str.buf);
				buf = newbuf;
			}
			else {
				buf = NULL;
			}
			if (tmp != NULL)
				delete[] tmp;
		}	
	}
	
	~CMyString() {
		if (buf != NULL) {
			delete[] buf;
			buf = NULL;
		}
		
	}

	void print() {
		if (buf != NULL)
			cout << buf << endl;
		else cout << "NULL" << endl;
	}
	//声明赋值运算符函数
	CMyString& operator=(const CMyString& str);

private:
	char* buf=NULL;
};

//注意最后才释放原先的内存，不要着急释放原先的内存，否则当new关键字执行失败抛出异常时，就会使得原来的数据被清除，要先保护原先的数据
/*CMyString& CMyString::operator=(const CMyString& str) {

	if (this!=&str) {
		int len = strlen(str.buf) + 1;
		char* newbuf = new char[len];
		strcpy(newbuf, str.buf);
		char* tmp = buf;
		buf = newbuf;
		//最后才释放
		if (tmp != NULL)
			delete[] tmp;
	}
	return *this;
}*/

//另一种思路一致的实现
CMyString& CMyString::operator=(const CMyString& str) {

	if (this != &str) {
		//使用复制构造函数，生成一个临时的对象
		CMyString tmpStr(str);

		//交换临时对象的数据
		char* ptmp = buf;
		buf = tmpStr.buf;
		tmpStr.buf = ptmp;

		//当出了这个大括号(即tmpStr的作用域)，tmpStr就会被回收，也就回收了原来的数据
	}
	return *this;
}

int main() {
	char str[] = "hello,world";
	char str2[] = "I like C++";

	CMyString mystr(str);
	mystr.print();
	CMyString mystr2(str2);
	mystr2.print();

	mystr2 = mystr;
	mystr2.print();
	return 0;
}
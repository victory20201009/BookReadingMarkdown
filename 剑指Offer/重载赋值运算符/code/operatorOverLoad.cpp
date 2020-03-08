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
	//������ֵ���������
	CMyString& operator=(const CMyString& str);

private:
	char* buf=NULL;
};

//ע�������ͷ�ԭ�ȵ��ڴ棬��Ҫ�ż��ͷ�ԭ�ȵ��ڴ棬����new�ؼ���ִ��ʧ���׳��쳣ʱ���ͻ�ʹ��ԭ�������ݱ������Ҫ�ȱ���ԭ�ȵ�����
/*CMyString& CMyString::operator=(const CMyString& str) {

	if (this!=&str) {
		int len = strlen(str.buf) + 1;
		char* newbuf = new char[len];
		strcpy(newbuf, str.buf);
		char* tmp = buf;
		buf = newbuf;
		//�����ͷ�
		if (tmp != NULL)
			delete[] tmp;
	}
	return *this;
}*/

//��һ��˼·һ�µ�ʵ��
CMyString& CMyString::operator=(const CMyString& str) {

	if (this != &str) {
		//ʹ�ø��ƹ��캯��������һ����ʱ�Ķ���
		CMyString tmpStr(str);

		//������ʱ���������
		char* ptmp = buf;
		buf = tmpStr.buf;
		tmpStr.buf = ptmp;

		//���������������(��tmpStr��������)��tmpStr�ͻᱻ���գ�Ҳ�ͻ�����ԭ��������
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
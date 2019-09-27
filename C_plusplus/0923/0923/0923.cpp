#include<iostream>
using namespace std;

#include<string>


//(constructor)
void TestString1()
{
	string s1; //string();
	string s2("hello");//string (const char* s);
	string s3(10, '$');//string (size_t n, char c);
	string s4(s3);//string (const string& str);

	cin >> s1; //istream& operator>> (istream& is, string& str);
	cout << s1 << endl;//ostream& operator<< (ostream& os, const string& str);
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

//Capacity
void TestString2()
{
	string s("hello");
	cout << s.size() << endl;//size_t size����const;
	cout << s.length() << endl;//size_t length() const;
	cout << s.capacity() << endl;//size_t capacity() const;

	if (s.empty())//bool empty() const;
	{
		cout << "NULL String" << endl;
	}
	else
	{
		cout << "Not NULL string" << endl;
	}
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	if (s.empty())
	{
		cout << "NULL String" << endl;
	}
	else
	{
		cout << "Not NULL Stirng" << endl;
	}
}
//resize / reserve
//void resize (size_t n);
//void resize (size_t n, char c);
//		���ܣ���string���е���Ч�ַ��ı䵽n��
//			1�����n����ԭ���ĳ��ȣ������Ĳ���ʹ��c�����
//			2�����nС��ԭ���ĳ��ȣ������Ľ���ɾ��
//		ע�⣺
//			1������ǽ�string���е���ЧԪ����С��ֻ�ı���ЧԪ�صĸ���������ı�ײ�ռ��С
//			2������ǽ�string���е���ЧԪ�����࣬������Ҫ����

void TestString3()
{
	string s("hello");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(10, '!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(20, '8');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(6);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}


int main()
{
	//TestString1();
	//TestString2();
	TestString3();
	return 0;
}
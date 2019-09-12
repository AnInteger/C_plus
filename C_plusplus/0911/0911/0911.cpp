#include<iostream>
using namespace std;

#if 0
//��   �ṹ����c++�б���Ϊ�൫������Ķ��壬ֻ�ǹ��ϳ�Ϊ��
struct Student
{
	//��Ա���� || ��Ϊ
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << ":" << _gender << ":" << _age << endl;
	}

	//��Ա���� || ����
	char _name[20];
	char _gender[3];
	int _age;
};


int main()
{
	Student s;//���ഴ�����󣬱���Ҫ���������
	s.SetStudentInfo("Peter", "��", 29);
	s.PrintStudent();
	//����ʹ��  .  ���������еĺ����ͱ���

	return 0;
}
#endif



#if 0
//���������򣺷�װ   �̳�  ��̬
//��װ����һ��������ڲ�ʵ��ϸ�������������ṩһ�����нӿ��ö���֮����н���

//C++ʵ�ַ�װ����(ͨ���ཫ��������Ժ���Ϊ��װ��һ��)
//				����Ȩ�ޣ�private  protected  public
//				public: ��public���εĳ�Ա������ֱ�������ⱻ����
//				protected/private������ֱ����������з���


//int _age = 10;
//void SetStudentInfo(char* name)
//{}

class Student
{
public:
	//��Ա���� || ��Ϊ
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << ":" << _gender << ":" << _age << endl;
	}

private:
	//��Ա���� || ����
	char _name[20];
	char _gender[3];
	int _age;
};

int g_a = 10;

int main()
{
	Student s;
	s.SetStudentInfo("Peter", "��", 29);
	s.PrintStudent();

	//s._age = 30;//�����޷��������ڵ�˽�г�Ա
	cout << g_a << endl;//������������ȫ�ֱ���
	return 0;
}

#endif

#if 0
// ��C++�����С�ļ����struct��С����ķ�����ȫһ��
class Student
{
public:
	//��Ա���� || ��Ϊ
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << ":" << _gender << ":" << _age << endl;
	}

private:
	//��Ա���� || ����
	char _name[20];
	char _gender[3];
	int _age;
};


int main()
{
	Student s1, s2, s3;
	cout << sizeof(s1) << endl;

	s1.SetStudentInfo("Peter", "��",29);
	s2.SetStudentInfo("����", "Ů", 30);
	s3.SetStudentInfo("summer", "��", 4);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif


#if 0
class A
{
public:
	void TestFun()
	{}
};

//����Ĵ�С�������������п���Ĵ�С��1
class B
{};

int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;

	B b1,b2,b3;
	//������Զ������
	return 0;
}

#endif


#if 0
//��C��������Ҫʵ�����ж��庯���Ĺ�����Ҫ����ṹ��ָ��
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
};

void SetStudentInfo(Student* ps, char* name, char* gender, int age)
{
	strcpy(ps->_name, name);
	strcpy(ps->_gender, gender);
	ps->_age = age;
}


void PrintStudent(Student* ps)
{
	printf("%s %s %s", ps->_name, ps->_gender, ps->_age);
}

#endif



#if 0
class Student
{
public:
	void SetStudentInfo(char* name, char* gender, int age)
	{
		//Student* const  Ϊthisָ�������
		//this=nullptr;  thisָ���޷�����
		cout << this << endl;
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}

	void PrintStudent()
	{
		cout << this->_name << ":" << this->_gender << ":" << this->_age << endl;
	}

	//��������
	void TestFunc(...)
	{
		cout << this << endl;
	}

private:
	// ��Ա���� || ����
	char _name[20];
	char _gender[3];
	int _age;
};
//�����ж���ĺ�����������б�����   ����* const  ���͵�thisָ�룬ָ����ĵ�ַ��
//�ʶ��亯����û�д洢�����У�����ͨ��thisָ��������еĳ�Ա����

#endif



#if 0
//1. ��ʶ������
//2. ʶ�����еĳ�Ա����
//3. ʶ�����еĳ�Ա�������Ҷ����еĳ�Ա�������и�д


class Student
{
public:
	/*void SetStudentInfo(Student* const this, char* name, char* gender, int age)
	{
	strcpy(this->_name, name);
	strcpy(this->_gender, gender);
	this->_age = age;
	}*/

	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	/*
	void PrintStudent(Student* const this)
	{
	cout << this->_name << ":" << this->_age << endl;
	}
	*/

	void PrintStudent()
	{
		cout << _name << ":" << _age << endl;
	}
	//��Ԥ����׶Σ�������������еĺ������и��ģ��Ӷ���ʾ�������б������ص�thisָ��
private:
	//��Ա���� || ����
	char _name[20];
	char _gender[3];
	int _age;
};

int main()
{
	//cout << this << endl;
	//��this��: ֻ���ڷǾ�̬��Ա������Ǿ�̬���ݳ�Ա��ʼֵ�趨����ڲ�����
	Student s1, s2, s3;
	//s1.TestFunc(10);//��������

	cout << &s1 << endl;
	s1.SetStudentInfo("Peter", "��", 29);

	cout << &s2 << endl;
	s2.SetStudentInfo("����", "Ů", 30);

	cout << &s3 << endl;
	s3.SetStudentInfo("summer", "��", 4);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif


#if 0
class A
{
public:
	void PrintA()
	{
		cout << this << endl;
		cout << this->_a << endl;
	}

	void Show()
	{
		cout << this << endl;
		cout << "Show()" << endl;
	}

private:
	int _a;
};

int main()
{
	A* p = NULL;//��A���ָ�����p����ΪNULL
	p->Show();//����ʱ��������A* const thisָ������ŵĵ�ַҲΪ�գ��ʿ��Ե���
	p->PrintA();//����ʱ����Ϊthis��ʱ�Ѿ�Ϊ�գ����޷�����A��Ҳ�޷�����A���еı������ʳ������


	return 0;
}
#endif
#pragma once
#include<unordered_map>'
#include<iostream>
#include<string>
using namespace std;


void TestUnordered_map()
{
	unordered_map<string, string> m;
	m.insert(pair<string, string>("����", "10Ԫ"));
	m.insert(pair<string, string>("����", "15Ԫ"));
	m.insert(pair<string, string>("���", "19Ԫ"));

	m.insert(make_pair("��Ƭ", "20"));

	cout << m.size() << endl;
	cout << m.bucket_count() << endl;
	cout << m.bucket_size(0) << endl;

	cout << m.bucket("����") << endl;//��ȡkey���ڵ�Ͱ��

	m["���"] = "10Ԫ";//���key��������key-val���뵽�����У�����Ĭ��val
	cout << m["���"] << endl;
	cout << m.size() << endl;

	m.erase("���");
	cout << m.size() << endl;

	auto it = m.find("����");
	cout << it->first << "is" << it->second << endl;
}
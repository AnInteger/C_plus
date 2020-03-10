#pragma once
#include "HashBucket.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace MUnorder_Map
{
	template<class K,class V>
	class unordered_map
	{
	public:
		typedef pair<K, V> ValueType;

		struct KOFV
		{
			const K& operator()(const ValueType& data)const
			{
				return data.first;
			}
		};
		typename typedef HashBucket<ValueType, KOFV>::iterator iterator;

	public:
		unordered_map()
			:ht_()
		{}

		iterator begin()
		{
			return ht_.begin();
		}

		iterator end()
		{
			return ht_.end();
		}

		bool empty()const
		{
			return ht_.empty();
		}

		size_t size() const
		{
			return ht_.size();
		}

		pair<iterator, bool> insert(const ValueType& data)
		{
			return ht_.InsertUnique(data);
		}

		size_t erase(const K& key)
		{
			return ht_.EraseUnique(ValueType(key, V()));
		}

		iterator find(const K& key)
		{
			return ht_.Find(ValueType(key, V()));
		}

		void clear()
		{
			ht_.clear();
		}

		void swap(const unordered_map<K, V>& m)
		{
			ht_.swap(m.ht_);
		}

		V& operator[](const K& key)
		{
			return (*(insert(ValueType(key, V())).first)).second;
		}

		size_t bucket_count()const
		{
			return ht_.bucket_count();
		}

		size_t bucket_size(size_t n)const
		{
			return ht_.bucket_size(n);
		}

		
		size_t bucket(const K& key)
		{
			return ht_.bucket(ValueType(key, V()));
		}

	private:
		HashBucket<ValueType, KOFV> ht_;
	};
}


void TestUnordered_map()
{
	MUnorder_Map::unordered_map<string, string> m;
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
	m.clear();
	cout << m.empty() << endl;

	
}
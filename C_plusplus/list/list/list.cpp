#include<iostream>
using namespace std;

namespace bite
{
	//list����ͷ����˫��ѭ������
	template<class T>
	struct ListNode
	{
		ListNode(const T& data = T())
		:_pNext(nullptr)
		, _pPre(nullptr)
		, _data(data)
		{}

		ListNode<T>* _pNext;
		ListNode<T>* _pPre;
		T _data;
	};

	//list�����������ڵ����͵�ָ�����·�װ
	template<class T>
	struct list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T> Self;
	public:
		list_iterator(Node* pCur)
			:_pCur(pCur)
		{}
		//����ָ��ķ�ʽ����Ӧ��
		T& operator*()
		{
			return _pCur->_data;
		}

		T* operator->()
		{
			return &(_pCur->_data);
		}

		//�ƶ�
		Self& operator++()
		{
			_pCur = _pCur->_pNext;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			_pCur = _pCur->_pNext;
			return temp;
		}

		Self& operator--()
		{
			_pCur = _pCur->_pPre;
		}

		Self operator--(int)
		{
			Self temp(*this);
			_pCur = _pCur->_pPre;
			return temp;
		}

		bool operator!=(const Self& s)
		{
			return _pCur == s._pCur;
		}

		bool operator==(const Self& s)
		{
			return _pCur == s._pCur;
		}

		Node* _pCur;
	};
}
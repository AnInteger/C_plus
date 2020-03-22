#pragma once
#if 0
#include <iostream>
#include <algorithm>
using namespace std;
enum Color { RED, BLACK };

template <class T>
struct RBTreeNode
{
	RBTreeNode(const T& val=T(), Color color = RED)
		:pLeft_(nullptr)
		, pRight_(nullptr)
		, pParent_(nullptr)
		,val_(val)
		, color_(color)
	{}

	RBTreeNode* pLeft_;
	RBTreeNode* pRight_;
	RBTreeNode* pParent_;
	T val_;
	Color color_;
};

template <class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		//����ͷ���
		pHead_ = new Node;
		pHead_->pLeft_ = pHead_;
		pHead_->pRight_ = pHead_;
		size_ = 0;
	}

	bool insert(const T& val)
	{
		//���������
		Node*& pRoot = getRoot();
		if (nullptr == pRoot)
		{
			pRoot = new Node(val, BLACK);
			pHead_->pLeft_ = pRoot;
			pHead_->pRight_ = pRoot;
			pRoot->pParent_ = pHead_;
			return true;
		}

		//�ҵ�����λ��
		Node* pCur = pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (val < pCur->val_)
			{
				pCur = pCur->pLeft_;
			}
			else if (val > pCur->val_)
			{
				pCur = pCur->pRight_;
			}
			else
			{
				return false;
			}
		}

		//���н�����
		pCur = new Node(val);

		if (val < pParent->val_)
			pParent->pLeft_ = pCur;
		else
			pParent->pRight_ = pCur;

		pCur->pParent_ = pParent;

		//��֤��������
		while (pParent!=pHead_ && pParent->color_ == RED)
		{
			Node* grandFather = pParent->pParent_;
			if (pParent == grandFather->pLeft_)
			{
				//���һ ˫�׺�����Ϊ��
				Node* uncle = grandFather->pRight_;
				if (uncle&&RED == uncle->color_)
				{
					pParent->color_ = BLACK;
					uncle->color_ = BLACK;
					grandFather->color_ = RED;

					pCur = grandFather;
					pParent = pCur->pParent_;
				}
				else
				{
					//������������
					//�ȴ��������
					if (pCur == pParent->pRight_)
					{
						//����
						RotateLeft(pParent);
						swap(pParent, pCur);
					}
					//�����游��˫�׵���ɫ
					grandFather->color_ = RED;
					pParent->color_ = BLACK;
					RotateRight(grandFather);
				}
			}
			else
			{
				Node* uncle = grandFather->pLeft_;
				if (uncle&&RED == uncle->color_)
				{
					//���һ�����
					pParent->color_ = BLACK;
					uncle->color_ = BLACK;
					grandFather->color_ = RED;

					pCur = grandFather;
					pParent = pCur->pParent_;
				}
				else
				{
					//�������������ķ����
					if (pCur == pParent->pLeft_)
					{
						RotateRight(pParent);
						swap(pCur, pParent);
					}
					pParent->color_ = BLACK;
					grandFather->color_ = RED;
					RotateLeft(grandFather);
				}
			}
		}
		//��֤���ڵ�Ϊ��
		pRoot->color_ = BLACK;

		//������������ֵ
		pHead_->pLeft_ = LeftMost();
		pHead_->pRight_ = RightMost();
		size_++;
		return true;
	}

	bool isvValidRBTree()
	{
		Node* pRoot = getRoot();
		if (nullptr == pRoot)
			return true;

		//���ǿ�
		if (BLACK != pRoot->color_)
		{
			//����2
			cout << "���ڵ�Ϊ�죺����������" << endl;
			return false;
		}

		//����֤����4
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->color_)
				blackCount++;
			pCur = pCur->pLeft_;
		}

		size_t  pathCount = 0;
		
		return _isvValidRBTree(pRoot, pathCount,blackCount);
	}

private:
	//����ֵ
	Node* RightMost()
	{
		Node* pRoot = getRoot();
		if (nullptr == pRoot)
			return pHead_;

		Node* pCur = pRoot;
		while (pCur->pRight_)
		{
			pCur = pCur->pRight_;
		}

		return pCur;
	}

	//����ֵ
	Node* LeftMost()
	{
		Node* pRoot = getRoot();
		if (nullptr == pRoot)
			return pHead_;

		Node* pCur = pRoot;
		while (pCur->pLeft_)
		{
			pCur = pCur->pLeft_;
		}

		return pCur;
	}

	void RotateLeft(Node* pParent)
	{
		Node* pSubR = pParent->pRight_;
		Node* pSubRL = pSubR->pLeft_;

		pParent->pRight_ = pSubRL;
		if (pSubRL)
			pSubRL->pParent_ = pParent;

		pSubR->pLeft_ = pParent;
		Node* pPParent = pParent->pParent_;
		pParent->pParent_ = pSubR;
		pSubR->pParent_ = pPParent;

		if (pPParent == pHead_)
		{
			//pParent�Ǹ��ڵ�
			pHead_->pParent_ = pSubR;
		}
		else
		{
			if (pParent == pPParent->pLeft_)
				pPParent->pLeft_ = pSubR;
			else
				pPParent->pRight_ = pSubR;
		}
	}

	void RotateRight(Node* pParent)
	{
		Node* pSubL = pParent->pLeft_;
		Node* pSubLR = pSubL->pRight_;

		pParent->pLeft_ = pSubLR;
		if (pSubLR)
			pSubLR->pParent_ = pParent;

		pSubL->pRight_ = pParent;
		Node* pPParent = pParent->pParent_;
		pParent->pParent_ = pSubL;
		pSubL->pParent_ = pPParent;

		if (pPParent == pHead_)
		{
			pHead_->pParent_ = pSubL;
		}
		else
		{
			if (pParent == pPParent->pLeft_)
				pPParent->pLeft_ = pSubL;
			else
				pPParent->pRight_ = pSubL;
		}
	}

	bool _isvValidRBTree(Node* pRoot, size_t pathCount, size_t blackCount)
	{
		if (nullptr==pRoot)
			return true;

		if (BLACK == pRoot->color_)
			pathCount++;

		Node* pParent = pRoot->pParent_;
		if (pParent != pHead_ && RED == pParent->color_&&RED == pRoot->color_)
		{
			cout << "���������ĺ�ɫ���" << endl;
			return false;
		}

		if (nullptr == pRoot->pLeft_&&nullptr == pRoot->pRight_)
		{
			if (pathCount != blackCount)
			{
				cout << "ÿ��·���к�ɫ��������һ��" << endl;
				return false;
			}
		}
		return _isvValidRBTree(pRoot->pLeft_, pathCount, blackCount) &&
			       _isvValidRBTree(pRoot->pRight_, pathCount, blackCount);
	}

	//��ȡ���
	Node*& getRoot()
	{
		return	pHead_->pParent_;
	}

private:
	Node* pHead_;
	size_t size_;
};
#endif

#include <iostream>
#include <algorithm>
using namespace std;
enum Color { RED, BLACK };

template <class T>
struct RBTreeNode
{
	RBTreeNode(const T& val = T(), Color color = RED)
		:pLeft_(nullptr)
		, pRight_(nullptr)
		, pParent_(nullptr)
		, val_(val)
		, color_(color)
	{}

	RBTreeNode* pLeft_;
	RBTreeNode* pRight_;
	RBTreeNode* pParent_;
	T val_;
	Color color_;
};

template <class T>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> Self;
	RBTreeIterator(Node* pNode = nullptr)
		:_pNode(pNode)
	{}

	T& operator*()
	{
		return _pNode->val_;
	}

	T* operator->()
	{
		return &_pNode->val_;
	}

	Self& operator++()
	{
		Increasement();
		return *this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		Increasement();
		return temp;
	}

	Self& operator--()
	{
		Decreasement();
		return *this;
	}

	Self operator--(int)
	{
		Self temp(*this);
		Decreasement();
		return temp;
	}

	bool operator==(const Self& s )const
	{
		return _pNode == s._pNode;
	}

	bool operator!=(const Self& s)const
	{
		return _pNode != s._pNode;
	}

	void Increasement()
	{
		if (_pNode->pRight_)
		{
			_pNode = _pNode->pRight_;
			while (_pNode->pLeft_)
			{
				_pNode = _pNode->pLeft_;
			}
		}
		else
		{
			Node* pParent = _pNode->pParent_;
			while(_pNode == pParent->pRight_)
			{
				_pNode = pParent;
				pParent = _pNode->pParent_;
			}
			if(_pNode->pRight_!=pParent)
			_pNode = pParent;
		}
	}

	void Decreasement()
	{
		if (_pNode->pParent_->pParent_ == _pNode&&_pNode->color_==RED)
		{
			_pNode = _pNode->pRight_;
		}
		else if (_pNode->pLeft_)
		{
			_pNode = _pNode->pLeft_;
			while (_pNode->pRight_)
			{
				_pNode = _pNode->pRight_;
			}
		}
		else
		{
			Node*pParent = _pNode->pParent_;
			while (_pNode == pParent->pLeft_)
			{
				_pNode = pParent;
				pParent = _pNode->pParent_;
			}
			_pNode = pParent;
		}
	}

	Node* _pNode;
};

template <class T,class KOFV>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T> Iterator;
public:
	RBTree()
	{
		//����ͷ���
		pHead_ = new Node;
		pHead_->pLeft_ = pHead_;
		pHead_->pRight_ = pHead_;
		size_ = 0;
	}

	Iterator begin()
	{
		return Iterator(pHead_->pLeft_);
	}

	Iterator end()
	{
		return Iterator(pHead_);
	}

	pair<Iterator,bool> insert(const T& val)
	{
		//���������
		Node*& pRoot = getRoot();
		Node* pNewNode = NULL;
		if (nullptr == pRoot)
		{
			pRoot = new Node(val, BLACK);
			pHead_->pLeft_ = pRoot;
			pHead_->pRight_ = pRoot;
			pRoot->pParent_ = pHead_;
			size_++;
			return make_pair(Iterator(pRoot),true);
		}

		//�ҵ�����λ��
		Node* pCur = pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (KOFV()(val) < KOFV()(pCur->val_))
			{
				pCur = pCur->pLeft_;
			}
			else if (KOFV()(val) > KOFV()(pCur->val_))
			{
				pCur = pCur->pRight_;
			}
			else
			{
				return make_pair(Iterator(pCur),false);
			}
		}

		//���н�����
		pNewNode =new Node(val);
		pCur = pNewNode;
		if (KOFV()(val) < KOFV()(pParent->val_))
			pParent->pLeft_ = pCur;
		else
			pParent->pRight_ = pCur;

		pCur->pParent_ = pParent;

		//��֤��������
		while (pParent != pHead_ && pParent->color_ == RED)
		{
			Node* grandFather = pParent->pParent_;
			if (pParent == grandFather->pLeft_)
			{
				//���һ ˫�׺�����Ϊ��
				Node* uncle = grandFather->pRight_;
				if (uncle&&RED == uncle->color_)
				{
					pParent->color_ = BLACK;
					uncle->color_ = BLACK;
					grandFather->color_ = RED;

					pCur = grandFather;
					pParent = pCur->pParent_;
				}
				else
				{
					//������������
					//�ȴ��������
					if (pCur == pParent->pRight_)
					{
						//����
						RotateLeft(pParent);
						swap(pParent, pCur);
					}
					//�����游��˫�׵���ɫ
					grandFather->color_ = RED;
					pParent->color_ = BLACK;
					RotateRight(grandFather);
				}
			}
			else
			{
				Node* uncle = grandFather->pLeft_;
				if (uncle&&RED == uncle->color_)
				{
					//���һ�����
					pParent->color_ = BLACK;
					uncle->color_ = BLACK;
					grandFather->color_ = RED;

					pCur = grandFather;
					pParent = pCur->pParent_;
				}
				else
				{
					//�������������ķ����
					if (pCur == pParent->pLeft_)
					{
						RotateRight(pParent);
						swap(pCur, pParent);
					}
					pParent->color_ = BLACK;
					grandFather->color_ = RED;
					RotateLeft(grandFather);
				}
			}
		}
		//��֤���ڵ�Ϊ��
		pRoot->color_ = BLACK;

		//������������ֵ
		pHead_->pLeft_ = LeftMost();
		pHead_->pRight_ = RightMost();
		size_++;
		return make_pair(Iterator(pNewNode), true);
	}

	bool Empty()const
	{
		return 0 == size_;
	}

	size_t Size()const
	{
		return size_;
	}

	Iterator Find(const T& val)
	{
		Node* pCur = getRoot();
		while (pCur)
		{
			if (KOFV()(pCur->val_) == KOFV()(val))
			{
				return Iterator(pCur);
			}
			else if (KOFV()(pCur->val_) > KOFV()(val))
			{
				pCur = pCur->pLeft_;
			}
			else
			{
				pCur = pCur->pRight_;
			}
		}
		return end();
	}

	bool isvValidRBTree()
	{
		Node* pRoot = getRoot();
		if (nullptr == pRoot)
			return true;

		//���ǿ�
		if (BLACK != pRoot->color_)
		{
			//����2
			cout << "���ڵ�Ϊ�죺����������" << endl;
			return false;
		}

		//����֤����4
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->color_)
				blackCount++;
			pCur = pCur->pLeft_;
		}

		size_t  pathCount = 0;

		return _isvValidRBTree(pRoot, pathCount, blackCount);
	}

private:
	//����ֵ
	Node* RightMost()
	{
		Node* pRoot = getRoot();
		if (nullptr == pRoot)
			return pHead_;

		Node* pCur = pRoot;
		while (pCur->pRight_)
		{
			pCur = pCur->pRight_;
		}

		return pCur;
	}

	//����ֵ
	Node* LeftMost()
	{
		Node* pRoot = getRoot();
		if (nullptr == pRoot)
			return pHead_;

		Node* pCur = pRoot;
		while (pCur->pLeft_)
		{
			pCur = pCur->pLeft_;
		}

		return pCur;
	}

	void RotateLeft(Node* pParent)
	{
		Node* pSubR = pParent->pRight_;
		Node* pSubRL = pSubR->pLeft_;

		pParent->pRight_ = pSubRL;
		if (pSubRL)
			pSubRL->pParent_ = pParent;

		pSubR->pLeft_ = pParent;
		Node* pPParent = pParent->pParent_;
		pParent->pParent_ = pSubR;
		pSubR->pParent_ = pPParent;

		if (pPParent == pHead_)
		{
			//pParent�Ǹ��ڵ�
			pHead_->pParent_ = pSubR;
		}
		else
		{
			if (pParent == pPParent->pLeft_)
				pPParent->pLeft_ = pSubR;
			else
				pPParent->pRight_ = pSubR;
		}
	}

	void RotateRight(Node* pParent)
	{
		Node* pSubL = pParent->pLeft_;
		Node* pSubLR = pSubL->pRight_;

		pParent->pLeft_ = pSubLR;
		if (pSubLR)
			pSubLR->pParent_ = pParent;

		pSubL->pRight_ = pParent;
		Node* pPParent = pParent->pParent_;
		pParent->pParent_ = pSubL;
		pSubL->pParent_ = pPParent;

		if (pPParent == pHead_)
		{
			pHead_->pParent_ = pSubL;
		}
		else
		{
			if (pParent == pPParent->pLeft_)
				pPParent->pLeft_ = pSubL;
			else
				pPParent->pRight_ = pSubL;
		}
	}

	bool _isvValidRBTree(Node* pRoot, size_t pathCount, size_t blackCount)
	{
		if (nullptr == pRoot)
			return true;

		if (BLACK == pRoot->color_)
			pathCount++;

		Node* pParent = pRoot->pParent_;
		if (pParent != pHead_ && RED == pParent->color_&&RED == pRoot->color_)
		{
			cout << "���������ĺ�ɫ���" << endl;
			return false;
		}

		if (nullptr == pRoot->pLeft_&&nullptr == pRoot->pRight_)
		{
			if (pathCount != blackCount)
			{
				cout << "ÿ��·���к�ɫ��������һ��" << endl;
				return false;
			}
		}
		return _isvValidRBTree(pRoot->pLeft_, pathCount, blackCount) &&
			_isvValidRBTree(pRoot->pRight_, pathCount, blackCount);
	}

	//��ȡ���
	Node*& getRoot()
	{
		return	pHead_->pParent_;
	}

private:
	Node* pHead_;
	size_t size_;
};
#include<iostream>
using namespace std;
#include<string.h>
typedef char datatype;
typedef struct Node
{
	datatype elem;
	struct Node *lchild, *rchild;
}BTNode, *BinTree;

BinTree CreateBTree()
{
	BinTree bt = NULL;
	char ch;
	cin >> ch;
	if (ch != '#')
	{
		bt = new BTNode;
		bt->elem = ch;
		bt->lchild = CreateBTree();
		bt->rchild = CreateBTree();
	}
	return bt;
}

void DelTree(BinTree root)
{
	if (root != NULL)
	{
		DelTree(root->lchild);
		DelTree(root->rchild);
	}
	delete(root);
}

void display(BinTree root)
{
	if (root != NULL)
	{
		cout << root->elem;
		if (root->lchild != NULL || root->rchild != NULL)
		{
			cout << '(';
			display(root->lchild);
		}
		if (root->rchild != NULL)
		{
			cout << ',';
			display(root->rchild);
			cout << ')';
		}
	}
}

void preOrder(BinTree root)
{
	if (root != NULL)
	{
		cout << root->elem;
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
}


void inOder(BinTree root)
{
	if (root != NULL)
	{
		inOder(root->lchild);
		cout << root->elem;
		inOder(root->rchild);
	}
}

void postOrder(BinTree root)
{
	if (root != NULL)
	{
		postOrder(root->lchild);
		postOrder(root->rchild);
		cout << root->elem;
	}
}

int maxDepth(BinTree root)
{
	int m = 0, n = 0;
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		m = maxDepth(root->lchild);
		n = maxDepth(root->rchild);
		if (m > n)
		{
			return (m + 1);
		}
		else
		{
			return (n + 1);
		}
	}
}

BinTree Parent(BinTree bt, char NodeName)
{
	if (bt)
	{
		if (bt->elem == NodeName)
		{
			cout << "�ýڵ�Ϊ���ڵ�" << endl;
			return 0;
		}
	}
	if ((bt->lchild->elem == NodeName&&bt->lchild != NULL) || bt->rchild->elem == NodeName&&bt->rchild != NULL)
	{
		return bt;
	}
	else
	{
		BTNode* tempP = NULL;
		if (tempP = Parent(bt->lchild, NodeName))
		{
			return tempP;
		}
		if (tempP = Parent(bt->rchild, NodeName))
		{
			return tempP;
		}
	}
	return NULL;
}

BinTree Search(BinTree bt, char NodeName)
{
	BinTree p;
	if (bt)
	{
		if (bt->elem == NodeName)
		{
			return bt;
		}
		if (bt->lchild)
		{
			p = Search(bt->lchild, NodeName);
			if (p)
			{
				return p;
			}
		}
		if (bt->rchild)
		{
			p = Search(bt->rchild, NodeName);
			if (p)
			{
				return p;
			}
		}
	}
	return NULL;
}

int Nodes(BinTree bt)
{
	if (bt == NULL)
	{
		return 0;
	}
	else
	{
		return Nodes(bt->lchild) + Nodes(bt->rchild) + 1;
	}
}

void DispLeaf(BinTree bt)
{
	if (bt != NULL)
	{
		if (bt->lchild == NULL&&bt->rchild == NULL)
		{
			cout << bt->elem << ',';
		}
		DispLeaf(bt->lchild);
		DispLeaf(bt->rchild);
	}
}

int main()
{
	BinTree root = NULL;
	root = CreateBTree();
	cout << "����˶�������" << endl;
	display(root);
	cout << "\n ��������Ϊ��";
	preOrder(root);
	cout << "\n ��������Ϊ��";
	inOder(root);
	cout << "\n ��������Ϊ��";
	postOrder(root);
	int num = maxDepth(root);
	cout << "\n �ö����������Ϊ��" << num << endl;
	BinTree nn;
	char name;
	cout << "����Ҫ���ҵĽ������" << endl;
	cin >> name;
	nn = Parent(root, name);
	if (nn)
	{
		cout << name << "�ĸ������Ϊ��" << nn->elem << endl;
	}
	nn = Search(root, name);
	if (nn->lchild)
	{
		cout << name << "������Ϊ��" << nn->lchild->elem << endl;
	}
	else
	{
		cout << name << "������." << endl;
	}
	if (nn->rchild)
	{
		cout << name << "���Һ���Ϊ��" << nn->rchild->elem << endl;
	}
	else
	{
		cout << name << "���Һ���." << endl;
	}
	cout << "�˶������Ľ����Ϊ��";
	cout << Nodes(root) << endl;
	cout << "������е�Ҷ�ӽ�㣺\n";
	DispLeaf(root);
	return 0;
}
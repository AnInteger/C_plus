#ifndef _BTREE_H_
#define _BTREE_H_

#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;

#define ENDTAG '#'

typedef struct BinaryTreeNode{
	BTDataType data;
	struct BinaryTreeNode*left;
	struct BinaryTreeNode*right;
}BTNode;

BTNode* BinaryTreeCreate(BTDataType* a);
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
void BinaryTreeLevelOrder(BTNode* root);

#endif /*_BTREE_H_*/
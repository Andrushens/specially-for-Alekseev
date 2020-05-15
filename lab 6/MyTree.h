//---------------------------------------------------------------------------

#ifndef MyTreeH
#include "BinTree.h"
#define MyTreeH
//---------------------------------------------------------------------------
#endif

template<typename T>
class MyTree : public BinTree<T>{
public:
	int GetNumOfLeaves(Node<T>* root);
};

template<typename T>
int MyTree<T>::GetNumOfLeaves(Node<T>* root)
{
	if (root == nullptr) return 0;
	if (root->left == root->right)
		return 1;
	return GetNumOfLeaves(root->left) + GetNumOfLeaves(root->right);
}
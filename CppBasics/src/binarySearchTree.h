#pragma once
#include <initializer_list>

template<typename T>
class binarySearchTree
{

public:
	binarySearchTree() : root{ nullptr } {}
	binarySearchTree(std::initializer_list<T> list) : root{ nullptr }
	{
		for (const T& item : list)
		{
			Insert(item);
		}
	}

	void Insert(const T& item)
	{
		Insert(item, root);
	}

	void Remove(const T& item)
	{
		Remove(item, root);
	}

	bool Contains(const T& item)
	{
		return Contains(item, root);
	}

private:
	struct BinaryNode
	{
		T element;
		BinaryNode* left;
		BinaryNode* right;
		int height;

		BinaryNode(const T& Element, BinaryNode* Left, BinaryNode* Right, int Height = 0)
			: element{ Element }, left{ Left }, right{ Right }, height{ Height } {}

		BinaryNode(T&& Element, BinaryNode* Left, BinaryNode* Right, int Height = 0)
			: element{ Element }, left{ Left }, right{ Right }, height{ Height } {}
	};

	BinaryNode* root;

	//recursive call
	void Insert(const T& item, BinaryNode*& t)
	{
		//check if t is null, for the base case 1.
		if (t == nullptr)
			t = new BinaryNode(item, nullptr, nullptr);


		else if (item < t->element)
		{

			Insert(item, t->left);
		}
		else if (t->element < item)
		{
			Insert(item, t->right);
		}

		BalanceTree(t);

		//check if value is smaller or bigger than t-> element, do the recursive call.
		//insert (item, t-> left) or Inser(item, t->right)
	}

	void Remove(const T& item, BinaryNode*& t)
	{
		//base case value is found item == t-> element
		if (t == nullptr) return;

		if (item == t->element)
		{
			if (t->left != nullptr && t->right != nullptr)
			{
				//two children
				t->element = FindMin(t->right)->element;
				Remove(t->element, t->right);
			}
			else
			{
				//have less than 2 children
				BinaryNode* oldPtr = t;
				t = t->left != nullptr ? t->left : t->right;
				delete oldPtr;
			}
		}
		else if (item < t->element)
		{


			Remove(item, t->left);
		}
		else if (item > t->element)
		{
			Remove(item, t->right);
		}

		BalanceTree(t);

			//two possible cases
			//1 - t has only one child, we just replace t with the child.
			//2 - t has two children pick smallest t->right and assuming t->element = smallest.
			//then remove item from t->right (Remove(item, t->right))

		//if item  < t->element Remove(item, t->left)
		//if item > t->elemnt Remove(item, t->left)
	}

	BinaryNode* FindMin(BinaryNode* t) const
	{
		if (t == nullptr) return nullptr;

		while (t->left != nullptr)
		{
			t = t->left; //because it's a pointer, won't change value
		}
		return t;
	}

	bool Contains(const T& item, BinaryNode* t) const
	{
		if (t == nullptr) return false;
		if (item == t->element) return true;

		if (item < t->element)
		{
			return Contains(item, t->left);
		}
		else
		{
			return Contains(item, t->right);
		}
	}

	void BalanceTree(BinaryNode*& t)
	{

		if (t == nullptr) return;

		if (height(t->left) - height(t->right) > 1)
		{
			if (height(t->left->left) >= height(t->left->right))
			{
				leftSingleRotation(t);
				std::cout << "left single rotation would run" << std::endl;
			}
			else
			{
				leftDoubleRotation(t);
				std::cout << "left double rotation would run" << std::endl;

			}
		}

		else if (height(t->right) - height(t->left) > 1)
		{
			if (height(t->right->right) >= height(t->right->left))
			{
				rightSingleRotation(t);
				std::cout << "right single rotation would run" << std::endl;

			}
			else
			{
				rightDoubleRotation(t);
				std::cout << "right double rotation would run" << std::endl;

			}
		}

		t->height = std::max(height(t->left), height(t->right)) + 1;

	}


	int height(BinaryNode* t) const
	{
		if (t == nullptr) return -1;

		return t->height;
	}

	void leftSingleRotation(BinaryNode*& t)
	{

		BinaryNode* temp = t->left;
		temp->right = t;
		t = temp;
		t->right->right = nullptr;
		t->right->left = nullptr;


		//BinaryNode* temp;
		//temp = t->left;
		//t->left = temp->right;
		//t->right = t;

	}

	void rightSingleRotation(BinaryNode*& t)
	{
		BinaryNode* temp = t->right; 
		temp->left = t;
		t = temp;
		temp->left->left = nullptr;
		temp->left->right = nullptr;

	}
	void leftDoubleRotation(BinaryNode*& t)
	{
		BinaryNode* pv;
		BinaryNode* temp;
		BinaryNode* temp2;
		pv = t;
		temp = pv->right;
		temp2 = pv->right->left;

		pv->right = temp2->left;
		temp->left = temp2->right;
		temp2->left = pv;
		temp2->right = temp;
	}

	void rightDoubleRotation(BinaryNode*& t)
	{
		BinaryNode* pv;
		BinaryNode* temp;
		BinaryNode* temp2;
		pv = t;
		temp = pv->left;
		temp2 = pv->left->right;

		pv->left = temp2->right;
		temp->right = temp2->left;
		temp2->right = pv;
		temp2->left = temp;

	}


};

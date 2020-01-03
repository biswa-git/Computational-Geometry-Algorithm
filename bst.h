#include "essential.h"
template<typename T>
class BST;
template<typename T>
class node
{
	friend class BST<T>;
public:
	node() = delete;
	node(T data) :data(data) {};
private:
	T data;
	node<T>* leftNode = nullptr;
	node<T>* rightNode = nullptr;

};

template<typename T>
class BST
{

public:
	BST();
	~BST();
	void insert(const T&);
private:
	node<T>* head;
};

template<typename T>
BST<T>::BST():head(nullptr)
{
}

template<typename T>
BST<T>::~BST()
{
}

template<typename T>
void BST<T>::insert(const T& data)
{
	if (head == nullptr)
	{
		head = new node<T>(data);
		return;
	}
	node<T>* present{ head };
	while (true)
	{
		if (present == nullptr)
		{ 
			present = new node<T>(data);
			return;
		}
		else
		{
			if (present->data > data)
			{
				present = present->leftNode;
			}
			else if(present->data < data)
			{
				present = present->rightNode;
			}
		}
	}
	
}

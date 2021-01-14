#include <iostream>

int GetMax(int a, int b)
{
	if (a > b) return a;
	else return b;
}

struct Node
{
	int data;
	int height;
	Node* leftChild;
	Node* rightChild;
};

int GetHeight(Node* node)
{
	if (node == nullptr) return 0;
	return node->height;
}

void SetHeight(Node* node)
{
	node->height = GetMax(GetHeight(node->leftChild), GetHeight(node->rightChild)) + 1;
}

int GetDifference(Node* node)
{
	if (node == nullptr) return 0;
	Node* leftChild = node->leftChild;
	Node* rightChild = node->rightChild;
	return GetHeight(leftChild) - GetHeight(rightChild);
}

// LL ȸ��
Node* RotateLL(Node* node)
{
	Node* leftChild = node->leftChild;
	node->leftChild = leftChild->rightChild;
	leftChild->rightChild = node;
	SetHeight(node);
	return leftChild;
}

// RR ȸ��
Node* RotateRR(Node* node)
{
	Node* rightChild = node->rightChild;
	node->rightChild = rightChild->leftChild;
	rightChild->leftChild = node;
	SetHeight(node);
	return rightChild;
}

// LR ȸ��
Node* RotateLR(Node* node)
{
	Node* leftChild = node->leftChild;
	node->leftChild = RotateRR(leftChild);
	SetHeight(node->leftChild);
	return RotateLL(node);
}

// RL ȸ��
Node* RotateRL(Node* node)
{
	Node* rightChild = node->rightChild;
	node->rightChild = RotateLL(rightChild);
	SetHeight(node->rightChild);
	return RotateRR(node);
}

Node* Balance(Node* node)
{
	int difference = GetDifference(node);
	if (difference >= 2)
	{
		if (GetDifference(node->leftChild) >= 1)
		{
			node = RotateLL(node);
		}
		else
		{
			node = RotateLR(node);
		}
	}
	else if (difference <= -2)
	{
		if (GetDifference(node->rightChild) <= -1)
		{
			node = RotateRR(node);
		}
		else
		{
			node = RotateRL(node);
		}
	}
	SetHeight(node);
	return node;
}

Node* InsertNode(Node* node, int data)
{
	if (!node)
	{
		node = new Node();
		node->data = data;
		node->height = 1;
		node->leftChild = node->rightChild = nullptr;
	}
	else if (data < node->data)
	{
		node->leftChild = InsertNode(node->leftChild, data);
		node = Balance(node);
	}
	else if (data > node->data)
	{
		node->rightChild = InsertNode(node->rightChild, data);
		node = Balance(node);
	}
	return node;
}

Node* root = nullptr;

void display(Node* node, int level)
{
	if (node != nullptr)
	{
		display(node->rightChild, level + 1);
		std::cout << "\n";
		if (node == root)
		{
			std::cout << "Root: ";
		}
		for (int i = 0; i < level && node != root; i++)
		{
			std::cout << "     ";
		}
		std::cout << node->data << "(" << GetHeight(node) << ")";
		display(node->leftChild, level + 1);
	}

}

int main()
{
	// AVL Ʈ��
	// ������ ������ ���� Ʈ���� �ǹ���
	// O(logN)�� �ð� ���⵵�� ���� ����

	// ���� �μ�
	// | ���� �ڽ� ���� - ������ �ڽ� ���� |
	// AVL Ʈ���� ��� ��忡 ���� ���� �μ��� -1, 0, 1
	// ���� �μ��� ���� �ʰ� �ȴٸ� 'ȸ��'�� ���� Ʈ�� �籸��

	// ȸ�� (Rotation)
	// LL ȸ��, LR ȸ��, RR ȸ��, RL ȸ��

	// ������ �� ��尡 ���Ե� �� ���� ����
	root = InsertNode(root, 7);
	root = InsertNode(root, 6);
	root = InsertNode(root, 5);
	root = InsertNode(root, 3);
	root = InsertNode(root, 1);
	root = InsertNode(root, 9);
	root = InsertNode(root, 8);
	root = InsertNode(root, 12);
	root = InsertNode(root, 16);
	root = InsertNode(root, 18);
	root = InsertNode(root, 23);
	root = InsertNode(root, 21);
	root = InsertNode(root, 14);
	root = InsertNode(root, 15);
	root = InsertNode(root, 19);
	root = InsertNode(root, 20);
	display(root, 1);
}
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

// LL 회전
Node* RotateLL(Node* node)
{
	Node* leftChild = node->leftChild;
	node->leftChild = leftChild->rightChild;
	leftChild->rightChild = node;
	SetHeight(node);
	return leftChild;
}

// RR 회전
Node* RotateRR(Node* node)
{
	Node* rightChild = node->rightChild;
	node->rightChild = rightChild->leftChild;
	rightChild->leftChild = node;
	SetHeight(node);
	return rightChild;
}

// LR 회전
Node* RotateLR(Node* node)
{
	Node* leftChild = node->leftChild;
	node->leftChild = RotateRR(leftChild);
	SetHeight(node->leftChild);
	return RotateLL(node);
}

// RL 회전
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
	// AVL 트리
	// 균형이 갖춰진 이진 트리를 의미함
	// O(logN)의 시간 복잡도를 유지 가능

	// 균형 인수
	// | 왼쪽 자식 높이 - 오른쪽 자식 높이 |
	// AVL 트리는 모든 노드에 대한 균형 인수가 -1, 0, 1
	// 균형 인수가 맞지 않게 된다면 '회전'을 통해 트리 재구성

	// 회전 (Rotation)
	// LL 회전, LR 회전, RR 회전, RL 회전

	// 균형은 각 노드가 삽입될 때 마다 수행
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
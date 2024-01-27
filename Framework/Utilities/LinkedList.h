#pragma once

/*
//��� struct ���� (data���� nextNode�� ����)
typedef struct Node
{
	int data;
	Node* nextNode;
};

//��ũ�� ����Ʈ Ŭ���� ����
class LinkedList 
{
public:
		//head �� tail�� �����͸� �ʱ�ȭ;
	LinkedList() { 
		head = NULL;
		tail = NULL;
	}
	//ù��°�� node �߰�
	void addFrontNode(int n);
	//�������� node �߰�
	void addNode(int n);
	
	//node ����
	void insertNode(Node* prevNode, int n);
	//node ����
	void deleteNode(Node* prevNode);
	
	//ù��° ��� ��������
	Node* getHead() { return head; }
	//LinkedList ���
	void display(Node* head);
	
private:
	Node* head;
	Node* tail;
};
*/


struct Node {
	class Cards* card;
	struct Node* link; // �� ����ü ��ü�� ����Ű�� �������̹Ƿ� struct���� ����
};

struct HeadNode {
	Node* head; // Node�� ����Ű�� ������, head
};

class LinkedList {

public:
	/*����Ʈ ����, ����� */
	HeadNode* createList()
	{
		HeadNode* H = new HeadNode; // HeadNode�� ����Ű�� ������, H
		H->head = NULL;
		return H;
	}

	/* ����Ʈ�� �������� ��� ����*/
	void addNode(HeadNode* Head, int x);

	/* ����Ʈ�� ������ ��� ����*/
	void deleteNode(HeadNode* Head);

	/* ����Ʈ�� Ư�� ��� ����*/
	void deleteThisNode(HeadNode* Head, int deldata);

	/* ����Ʈ�� Ư�� ��� ����*/
	void addThisNode(HeadNode* Head, int afterthisdata, int adddata);

	/* ����Ʈ�� Ư�� ��� �˻�*/
	void searchNode(HeadNode* Head, int thisdata);

	/* ���Ḯ��Ʈ ���*/
	void printList(HeadNode* L);
};
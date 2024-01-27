#include "Framework.h"
#include "LinkedList.h"

/*
//ù��°�� node �߰�
void LinkedList::addFrontNode(int n) {
	Node* temp = new Node;
	//temp�� �����ʹ� n
	temp->data = n;

	//LinkedList�� ���������
	if (head == NULL) {
		//ù node�� temp
		head = temp;
		//������ node�� temp
		tail = temp;
	}
	//LinkedList�� �����Ͱ� ������
	else {
		//temp�� nextNode�� head
		temp->nextNode = head;
		//head�� temp
		head = temp;
	}
}

//�������� node �߰�
void LinkedList::addNode(int n) {
	Node* temp = new Node;

	//temp�� �����ʹ� n
	temp->data = n;
	//temp�� nextNode = NULL��
	temp->nextNode = NULL;

	//LinkedList�� ���������
	if (head == NULL) {
		//ù node�� temp
		head = temp;
		//������ node�� temp
		tail = temp;
	}
	//LinkedList�� �����Ͱ� ������
	else {
		//���� ������ node�� nextNode�� temp
		tail->nextNode = temp;
		//������ node�� temp
		tail = temp;
	}
}

//node ����
void LinkedList::insertNode(Node* prevNode, int n) {
	Node* temp = new Node;
	//temp�� �����ʹ� n
	temp->data = n;

	//temp�� nextNode ����
	//(���� �� �� node�� nextNode�� temp�� nextNode�� ����)
	temp->nextNode = prevNode->nextNode;

	//temp ����
	//temp���� node�� nextNode�� temp�� ����
	prevNode->nextNode = temp;
}

//node ����
void LinkedList::deleteNode(Node* prevNode) {

	//������ node�� temp�� ����
	//(������ node�� 1�ܰ� �� node�� nextNode) 
	Node* temp = prevNode->nextNode;

	//������ node�� ����
	//(������ node�� nextNode�� 1�ܰ� �� node�� nextNode�� ����)
	prevNode->nextNode = temp->nextNode;

	//temp ����
	delete temp;
}
*/

/* ����Ʈ�� �������� ��� ����*/
void LinkedList::addNode(HeadNode* Head, int x)
{
	Node* NewNode = new Node;  //���� ���� ��� 
	Node* LastNode; //���� �ִ� ����� ������ ���
	NewNode->card = x;
	NewNode->link = NULL;

	if (Head->head == NULL) { // ����Ʈ�� ������� ���
		Head->head = NewNode;
		return;
	}

	LastNode = Head->head;   // ����Ʈ�� ������� ���� ��쿡 ���Ḯ��Ʈ�� ���� ó�� ��尡 LastNode�� ����Ű�� �Ѵ�.
	while (LastNode->link != NULL) LastNode = LastNode->link; // ���Ḯ��Ʈ�� ������ ��带 ã�� ����
	LastNode->link = NewNode; // ������ ��带 ã�� while���� ������ �ڿ� �� ��带 ����Ű�� �Ѵ�.
}

/* ����Ʈ�� ������ ��� ����*/
void LinkedList::deleteNode(HeadNode* Head)
{
	Node* prevNode;  // �����Ǵ� ����� �� ���
	Node* delNode;  // �����Ǵ� ���

	if (Head->head == NULL) return; // ����Ʈ�� �� ���
	if (Head->head->link == NULL) { // �� ���� ��常 ���� ���
		delete Head->head;  // head�� ����Ű�� �޸� ������ �� ������ ��ȯ
		Head->head = NULL;  // ��� ����� link �κ��� head�� null�� ����.
		return;
	}
	else {  // ����Ʈ�� ��� ���� �� �ִ� ���
		prevNode = Head->head; // ��� ��尡 ����Ű�� ��尡 prevNode�� �ǰ� ����
		delNode = Head->head->link; // prevNode ���� ��ġ�� delNode ����
		while (delNode->link != NULL) { //delNode�� ��������尡 �� ������
			prevNode = delNode;       // prevNode�� ��ĭ�� ����
			delNode = prevNode->link; // delNode�� ��ĭ�� ������ ����.
		}
		free(delNode);  // ������ ����� �޸� ������ ��ȯ
		prevNode->link = NULL;
	}
}

/* ����Ʈ�� Ư�� ��� ����*/
void LinkedList::deleteThisNode(HeadNode* Head, int deldata)
{
	Node* delNode;  // �����Ϸ��� ���
	Node* prevNode; // �����Ϸ��� ����� �� ���
	prevNode = Head->head;

	while (prevNode->link->card != deldata) {
		prevNode = prevNode->link;
	}

	delNode = prevNode->link;   // prevNode�� ����Ű�� ��尡 ������ ���
	prevNode->link = delNode->link;  // prevNode�� delNode ���� ��带 ����Ű����
	free(delNode);  // delNode ����

	cout << deldata << " ������ ���� ���� ��尡 �����ƽ��ϴ�." << endl;
	return;
}

/* ����Ʈ�� Ư�� ��� ����*/
void LinkedList::addThisNode(HeadNode* Head, int afterthisdata, int adddata)
{
	// afterthisdata: �� ������ �ڿ� ����
	// adddata: �� �����͸� ����

	Node* prevNode;  //�����Ϸ��� ����� ���� ���
	prevNode = Head->head;

	while (prevNode->card != afterthisdata) {
		prevNode = prevNode->link;
	}

	Node* NewNode = new Node;
	NewNode->card = adddata;
	NewNode->link = prevNode->link;
	prevNode->link = NewNode;
	return;
}

/* ����Ʈ�� Ư�� ��� �˻�*/
void LinkedList::searchNode(HeadNode* Head, int thisdata)
{
	Node* someNode;
	someNode = Head->head;

	while (someNode->card != thisdata) {
		someNode = someNode->link;
	}
	cout << thisdata << " �����͸� �˻��ϴ� �� �����߽��ϴ�." << endl;
}

/* ���Ḯ��Ʈ ���*/
void LinkedList::printList(HeadNode* L)
{
	//��� ������� ����Ʈ ���
	Node* p;
	cout << "���Ḯ��Ʈ ��� = ( ";
	p = L->head;

	while (p != NULL) {
		cout << p->card;
		p = p->link;
		if (p != NULL) cout << " --> ";
	}
	cout << " )" << endl;
}

#include "Framework.h"
#include "LinkedList.h"

/*
//첫번째의 node 추가
void LinkedList::addFrontNode(int n) {
	Node* temp = new Node;
	//temp의 데이터는 n
	temp->data = n;

	//LinkedList가 비어있으면
	if (head == NULL) {
		//첫 node는 temp
		head = temp;
		//마지막 node는 temp
		tail = temp;
	}
	//LinkedList에 데이터가 있으면
	else {
		//temp의 nextNode는 head
		temp->nextNode = head;
		//head는 temp
		head = temp;
	}
}

//마지막의 node 추가
void LinkedList::addNode(int n) {
	Node* temp = new Node;

	//temp의 데이터는 n
	temp->data = n;
	//temp의 nextNode = NULL값
	temp->nextNode = NULL;

	//LinkedList가 비어있으면
	if (head == NULL) {
		//첫 node는 temp
		head = temp;
		//마지막 node는 temp
		tail = temp;
	}
	//LinkedList에 데이터가 있으면
	else {
		//현재 마지막 node의 nextNode는 temp
		tail->nextNode = temp;
		//마지막 node는 temp
		tail = temp;
	}
}

//node 삽입
void LinkedList::insertNode(Node* prevNode, int n) {
	Node* temp = new Node;
	//temp의 데이터는 n
	temp->data = n;

	//temp의 nextNode 저장
	//(삽입 할 앞 node의 nextNode를 temp의 nextNode에 저장)
	temp->nextNode = prevNode->nextNode;

	//temp 삽입
	//temp앞의 node의 nextNode를 temp로 저장
	prevNode->nextNode = temp;
}

//node 삭제
void LinkedList::deleteNode(Node* prevNode) {

	//삭제할 node를 temp에 저장
	//(삭제할 node의 1단계 전 node의 nextNode) 
	Node* temp = prevNode->nextNode;

	//삭제할 node를 제외
	//(삭제할 node의 nextNode를 1단계 전 node의 nextNode에 저장)
	prevNode->nextNode = temp->nextNode;

	//temp 삭제
	delete temp;
}
*/

/* 리스트의 마지막에 노드 삽입*/
void LinkedList::addNode(HeadNode* Head, int x)
{
	Node* NewNode = new Node;  //새로 만들 노드 
	Node* LastNode; //원래 있던 노드의 마지막 노드
	NewNode->card = x;
	NewNode->link = NULL;

	if (Head->head == NULL) { // 리스트가 비어있을 경우
		Head->head = NewNode;
		return;
	}

	LastNode = Head->head;   // 리스트가 비어있지 않은 경우에 연결리스트의 가장 처음 노드가 LastNode를 가리키게 한다.
	while (LastNode->link != NULL) LastNode = LastNode->link; // 연결리스트의 마지막 노드를 찾는 과정
	LastNode->link = NewNode; // 마지막 노드를 찾고 while문을 나오면 뒤에 새 노드를 가리키게 한다.
}

/* 리스트의 마지막 노드 삭제*/
void LinkedList::deleteNode(HeadNode* Head)
{
	Node* prevNode;  // 삭제되는 노드의 앞 노드
	Node* delNode;  // 삭제되는 노드

	if (Head->head == NULL) return; // 리스트가 빈 경우
	if (Head->head->link == NULL) { // 한 개의 노드만 가진 경우
		delete Head->head;  // head가 가리키던 메모리 공간을 힙 영역에 반환
		Head->head = NULL;  // 헤드 노드의 link 부분인 head를 null로 설정.
		return;
	}
	else {  // 리스트에 노드 여러 개 있는 경우
		prevNode = Head->head; // 헤드 노드가 가리키는 노드가 prevNode가 되게 설정
		delNode = Head->head->link; // prevNode 다음 위치로 delNode 설정
		while (delNode->link != NULL) { //delNode가 마지막노드가 될 때까지
			prevNode = delNode;       // prevNode를 한칸씩 가고
			delNode = prevNode->link; // delNode도 한칸씩 끝으로 간다.
		}
		free(delNode);  // 마지막 노드의 메모리 공간을 반환
		prevNode->link = NULL;
	}
}

/* 리스트의 특정 노드 삭제*/
void LinkedList::deleteThisNode(HeadNode* Head, int deldata)
{
	Node* delNode;  // 삭제하려는 노드
	Node* prevNode; // 삭제하려는 노드의 앞 노드
	prevNode = Head->head;

	while (prevNode->link->card != deldata) {
		prevNode = prevNode->link;
	}

	delNode = prevNode->link;   // prevNode가 가리키는 노드가 삭제할 노드
	prevNode->link = delNode->link;  // prevNode가 delNode 다음 노드를 가리키도록
	free(delNode);  // delNode 삭제

	cout << deldata << " 데이터 값을 가진 노드가 삭제됐습니다." << endl;
	return;
}

/* 리스트에 특정 노드 삽입*/
void LinkedList::addThisNode(HeadNode* Head, int afterthisdata, int adddata)
{
	// afterthisdata: 이 데이터 뒤에 삽입
	// adddata: 이 데이터를 삽입

	Node* prevNode;  //삽입하려는 노드의 이전 노드
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

/* 리스트의 특정 노드 검색*/
void LinkedList::searchNode(HeadNode* Head, int thisdata)
{
	Node* someNode;
	someNode = Head->head;

	while (someNode->card != thisdata) {
		someNode = someNode->link;
	}
	cout << thisdata << " 데이터를 검색하는 데 성공했습니다." << endl;
}

/* 연결리스트 출력*/
void LinkedList::printList(HeadNode* L)
{
	//노드 순서대로 리스트 출력
	Node* p;
	cout << "연결리스트 목록 = ( ";
	p = L->head;

	while (p != NULL) {
		cout << p->card;
		p = p->link;
		if (p != NULL) cout << " --> ";
	}
	cout << " )" << endl;
}

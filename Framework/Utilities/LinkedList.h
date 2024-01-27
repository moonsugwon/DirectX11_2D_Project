#pragma once

/*
//노드 struct 구현 (data값과 nextNode가 존재)
typedef struct Node
{
	int data;
	Node* nextNode;
};

//링크드 리스트 클래스 생성
class LinkedList 
{
public:
		//head 와 tail의 포인터를 초기화;
	LinkedList() { 
		head = NULL;
		tail = NULL;
	}
	//첫번째의 node 추가
	void addFrontNode(int n);
	//마지막의 node 추가
	void addNode(int n);
	
	//node 삽입
	void insertNode(Node* prevNode, int n);
	//node 삭제
	void deleteNode(Node* prevNode);
	
	//첫번째 노드 가져오기
	Node* getHead() { return head; }
	//LinkedList 출력
	void display(Node* head);
	
private:
	Node* head;
	Node* tail;
};
*/


struct Node {
	class Cards* card;
	struct Node* link; // 이 구조체 자체를 가리키는 포인터이므로 struct으로 선언
};

struct HeadNode {
	Node* head; // Node를 가리키는 포인터, head
};

class LinkedList {

public:
	/*리스트 생성, 헤드노드 */
	HeadNode* createList()
	{
		HeadNode* H = new HeadNode; // HeadNode를 가리키는 포인터, H
		H->head = NULL;
		return H;
	}

	/* 리스트의 마지막에 노드 삽입*/
	void addNode(HeadNode* Head, int x);

	/* 리스트의 마지막 노드 삭제*/
	void deleteNode(HeadNode* Head);

	/* 리스트의 특정 노드 삭제*/
	void deleteThisNode(HeadNode* Head, int deldata);

	/* 리스트에 특정 노드 삽입*/
	void addThisNode(HeadNode* Head, int afterthisdata, int adddata);

	/* 리스트의 특정 노드 검색*/
	void searchNode(HeadNode* Head, int thisdata);

	/* 연결리스트 출력*/
	void printList(HeadNode* L);
};
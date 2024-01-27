#pragma once

class Hand
{
public:

	Hand();
	~Hand();

	void Update();
	void Render();

	void HandPosition();
	void RodeHand();

	const int GetDamege() { return Damge; }
	const int GetDefence() { return Defence; }
	const int GetType() { return Type; }
	const int GetCost() { return Cost; }
	const int GetState() { return State; }
	const int GetListSize() { return cardList.size(); }
	//const int GetCostnumber() { return Costnumber; }

	class Card* GetdeckList(int index) { return deckList[index]; }
	//class Card* GethandList(int index) 
	//{
	//	if (index < handList.size() - 1)
	//	{
	//		return handList[index]; 
	//	}
	//	return nullptr;
	//}	

	
	void SetCcount(int num);
	void SetState();

private:
	int index = 0;
	int count = 5;
	int Damge = -1;
	int Defence = -1;
	int Cost;
	int Type;
	int State;
	int Costnumber;
	//int Ncount = 0;

	int Ccount = 0;
	bool Cardx = false;

	vector<Vector3> Position;
	//vector<Vector3> pos;
	//vector<Deck> myList;

private:
	class Deck* deck;
	class Card* card;
	vector <class Card*> cardList;
	vector <class Card*> handList;
	vector <class Card*> deckList;
};

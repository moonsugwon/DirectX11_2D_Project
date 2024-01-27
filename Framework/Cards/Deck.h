#pragma once

#include "Card.h"

class Deck
{
public:
	Deck();
	~Deck();

	Card* GetcardList(int index) { return cardList[index]; }

	void detail();

	//void Cardimpact(int index);

private:
	int count = 5;
	Vector3 Position;

private:
	vector<class Card*> cardList;
	//vector<class TextureRect*> impact;
	//vector<class Card&> makeList;

};
#include "Framework.h"
#include "Deck.h"


Deck::Deck()
{
	//cardList
	cardList.push_back(new Card(Card_DESC(), TexturePath + L"card1.png"));
	cardList.push_back(new Card(Card_DESC(), TexturePath + L"card2.png"));
	cardList.push_back(new Card(Card_DESC(), TexturePath + L"card3.png"));
	cardList.push_back(new Card(Card_DESC(), TexturePath + L"card4.png"));
	cardList.push_back(new Card(Card_DESC(), TexturePath + L"card5.png"));
	cardList.push_back(new Card(Card_DESC(), TexturePath + L"card6.png"));
	cardList.push_back(new Card(Card_DESC(), TexturePath + L"card7.png"));
	cardList.push_back(new Card(Card_DESC(), TexturePath + L"card8.png"));
	cardList.push_back(new Card(Card_DESC(), TexturePath + L"card9.png"));
	cardList.push_back(new Card(Card_DESC(), TexturePath + L"card10.png"));
	
	detail();
}

Deck::~Deck()
{
	for (int i = 0; i < cardList.size(); i++)
	{
		SAFE_DELETE(cardList[i]);
	}
}

void Deck::detail()
{
	cardList[0]->SetType(0);
	cardList[0]->SetCost(1);
	cardList[0]->Ability(6, 0);
	
	cardList[1]->SetType(1);
	cardList[1]->SetCost(1);
	cardList[1]->Ability(0, 5);
	
	cardList[2]->SetType(0);
	cardList[2]->SetCost(2);
	cardList[2]->Ability(8, 0);

	cardList[3]->SetType(2);
	cardList[3]->SetCost(0);
	cardList[3]->Ability(2, 0);
	
	cardList[4]->SetType(0);
	cardList[4]->SetCost(2);
	cardList[4]->Ability(14, 0);
	
	cardList[5]->SetType(0);
	cardList[5]->SetCost(1);
	cardList[5]->Ability(0, 5);

	cardList[6]->SetType(2);
	cardList[6]->SetCost(1);
	cardList[6]->Ability(0, 0);
	
	cardList[7]->SetType(0);
	cardList[7]->SetCost(0);	
	cardList[7]->Ability(6, 0);
	
	cardList[8]->SetType(2);	
	cardList[8]->SetCost(1);
	cardList[8]->Ability(0, 10);

	cardList[9]->SetType(0);
	cardList[9]->SetCost(1);
	cardList[9]->Ability(0, 8);
}
#include "Framework.h"
#include "Hand.h"

#include "Deck.h"
#include "Card.h"


Hand::Hand()
{
	//if (Ncount == 0)
	//{
	//	Costnumber = 3;
	//	Ncount++;
	//}
	Costnumber = 3;

	deck = new Deck();
	for (int i = 0; i < 10; i++)
	{
		if (i <= 4)
		{
			card = new Card(deck->GetcardList(0));
			cardList.push_back(card);
		}
		else if (4 < i && i <= 8)
		{
			card = new Card(deck->GetcardList(1));
			cardList.push_back(card);
		}
		else if (i > 8)
		{
			card = new Card(deck->GetcardList(2));
			cardList.push_back(card);
		}
	}

	for (int i = 0; i < cardList.size(); i++)
	{
		cardList[i]->SetState(0);
	}

	for (auto card : cardList)
	{
		Card* temp = new Card(card);
		deckList.push_back(temp);
	}

	//for (int i = 0; i < 5; i++)
	//{
	//	bool skip = false; // 다시 스킵은 false 로 시작
	//	int iValue = intRand(rand); // iValue 는 0~9 까지의 랜덤한 값
	//
	//	//if (cardList[i]->GetState() == CardState::EXCEPT) // 카드 리스트의 위치가 덱이 아니면 실행
	//	//{
	//	//	i--; // 뒤로 돌리고
	//	//	skip = true; // 스킵이 트루가 된다
	//	//}
	//
	//	if (i >= 1 && !skip)
	//	{
	//		for (int n = 0; n < handList.size(); n++) // 핸드리스트 만큼 아래를 실행
	//		{
	//			if (handList[n] == cardList[iValue]) // 핸드리스트 안의 카드가 카드 리스트의 iValue 카드와 같을경우
	//			{
	//				i--; // 뒤로 돌리고
	//				skip = true; // 스킵이 트루가 되며
	//				break; // 위 포문으로 돌아간다
	//			}
	//
	//		}
	//	}
	//
	//	if (!skip) // 스킵이 트루가 되면서 이부분 무시
	//	{
	//		handList.push_back(cardList[iValue]); // 스킵이 false 일 경우 핸드 리스트에 카드 리스트의 iValue 카드 삽입
	//		handList[i]->SetState(1); // 핸드 리스트 카드들의 위치는 핸드로 이동
	//	}
	//}

	RodeHand();
}

Hand::~Hand()
{
	SAFE_DELETE(deck);
	for (int i = 0; i < cardList.size(); i++)
	{
		SAFE_DELETE(card);
	}
	cardList.clear();
	handList.clear();
	deckList.clear();
}

void Hand::Update()
{
	Damge = -1;
	Defence = -1;
	HandPosition();
	for (int i = 0; i < deckList.size(); i++)
	{
		deckList[i]->Update();
	}
	if (Costnumber > 0)
	{
		if (handList.size())
		{
			for (int i = 0; i < count; i++)
			{
				if (handList[i]->Use() == false)
				{
					handList[i]->Update(Position[i]);
				}

				if (handList[i]->Use())
				{
					Cost = handList[i]->GetCost();
					if (Costnumber >= Cost)
					{
						Damge = handList[i]->CardDmg();
						Defence = handList[i]->CardDef();
						Type = handList[i]->GetType();
						State = handList[i]->GetState();
						Costnumber -= Cost;
						handList[i]->SetState(2);
						handList.erase(handList.begin() + i);
						count--;
					}
				}
			}
		}

	}
	else if (Costnumber == 0)
	{
		for (int i = 0; i < count; i++)
		{
			if (handList[i]->Use() == false)
			{
				handList[i]->Update(Position[i]);
			}
		}
		Costnumber--;
	}
	
}

void Hand::Render()
{
	if (deckList.size())
	{
		for (int i = 0; i < deckList.size(); i++)
		{
			deckList[i]->Render();
		}
	}

	if (handList.size())
	{
		for (int i = 0; i < count; i++)
		{
			if (handList[i]->Use() == false)
			{
				handList[i]->Render();
			}
		}
	}
}

void Hand::HandPosition()
{
	if (Position.size() > 6)
	{
		Position.clear();
	}
	if (count == 5)
	{
		for (int i = 0; i < 5; i++)
		{
			Position.push_back(Vector3((WinMaxWidth / 2 - 400) + (200 * i), 100, 0));
		}
	}
	if (count == 4)
	{
		if (Position.size())
		{
			Position.clear();
		}
		for (int i = 0; i < 4; i++)
		{
			Position.push_back(Vector3((WinMaxWidth / 2 - 300) + (200 * i), 100, 0));
		}
	}
	if (count == 3)
	{
		if (Position.size())
		{
			Position.clear();
		}
		for (int i = 0; i < 3; i++)
		{
			Position.push_back(Vector3((WinMaxWidth / 2 - 200) + (200 * i), 100, 0));
		}
	}
	if (count == 2)
	{
		if (Position.size())
		{
			Position.clear();
		}
		for (int i = 0; i < 2; i++)
		{
			Position.push_back(Vector3((WinMaxWidth / 2 - 100) + (200 * i), 100, 0));
		}
	}
	if (count == 1)
	{
		if (Position.size())
		{
			Position.clear();
		}
		Position.push_back(Vector3(WinMaxWidth / 2, 100, 0));
	}
	
}

void Hand::RodeHand() // 덱에서 핸드로 카드를 뽑는다
{
	random_device rand;
	uniform_int_distribution<int> intRand(0, 9);
	
	if (Ccount == 2) // 만약 Ccount 가 2를 넘긴다면
	{
		for (int i = 0; i < cardList.size(); i++) // cardList의 크기만큼 i를 돌리면서
		{
			cardList[i]->SetState(0); // 카드의 위치를 덱으로 넣는다
		}
		Ccount = 0; // Ccount 가 0이 되고
	}
	Ccount++; // RodeHand를 한번 실행할때 마다 Ccount 가 1씩 늘어난다
	
	for (int i = 0; i < 5; i++)
	{
		bool skip = false; // 다시 스킵은 false 로 시작
		int iValue = intRand(rand); // iValue 는 0~9 까지의 랜덤한 값

		if (cardList[iValue]->GetState() == CardState::EXCEPT) // 카드 리스트의 위치가 덱이 아니면 실행
		{
			i--; // 뒤로 돌리고
			skip = true; // 스킵이 트루가 된다
		}
			
		if (i >= 1 && !skip)
		{
			for (int n = 0; n < handList.size(); n++) // 핸드리스트 만큼 아래를 실행
			{
				if (handList[n] == cardList[iValue]) // 핸드리스트 안의 카드가 카드 리스트의 iValue 카드와 같을경우
				{
					i--; // 뒤로 돌리고
					skip = true; // 스킵이 트루가 되며
					break; // 위 포문으로 돌아간다
				}

			}
		}
		
		if (!skip) // 스킵이 트루가 되면서 이부분 무시
		{
			handList.push_back(cardList[iValue]); // 스킵이 false 일 경우 핸드 리스트에 카드 리스트의 iValue 카드 삽입
			handList[i]->SetState(1); // 핸드 리스트 카드들의 위치는 핸드로 이동			
		}
	}
}

void Hand::SetCcount(int num)
{
	Ccount = num;
}

void Hand::SetState()
{
	count = 5;
	Costnumber = 3;
	for (int i = 0; i < handList.size(); i++)
	{
		handList[i]->SetState(2);
		//handList[i]->SetNumber(0);
	}
	handList.clear();
}

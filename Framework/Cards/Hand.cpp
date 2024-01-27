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
	//	bool skip = false; // �ٽ� ��ŵ�� false �� ����
	//	int iValue = intRand(rand); // iValue �� 0~9 ������ ������ ��
	//
	//	//if (cardList[i]->GetState() == CardState::EXCEPT) // ī�� ����Ʈ�� ��ġ�� ���� �ƴϸ� ����
	//	//{
	//	//	i--; // �ڷ� ������
	//	//	skip = true; // ��ŵ�� Ʈ�簡 �ȴ�
	//	//}
	//
	//	if (i >= 1 && !skip)
	//	{
	//		for (int n = 0; n < handList.size(); n++) // �ڵ帮��Ʈ ��ŭ �Ʒ��� ����
	//		{
	//			if (handList[n] == cardList[iValue]) // �ڵ帮��Ʈ ���� ī�尡 ī�� ����Ʈ�� iValue ī��� �������
	//			{
	//				i--; // �ڷ� ������
	//				skip = true; // ��ŵ�� Ʈ�簡 �Ǹ�
	//				break; // �� �������� ���ư���
	//			}
	//
	//		}
	//	}
	//
	//	if (!skip) // ��ŵ�� Ʈ�簡 �Ǹ鼭 �̺κ� ����
	//	{
	//		handList.push_back(cardList[iValue]); // ��ŵ�� false �� ��� �ڵ� ����Ʈ�� ī�� ����Ʈ�� iValue ī�� ����
	//		handList[i]->SetState(1); // �ڵ� ����Ʈ ī����� ��ġ�� �ڵ�� �̵�
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

void Hand::RodeHand() // ������ �ڵ�� ī�带 �̴´�
{
	random_device rand;
	uniform_int_distribution<int> intRand(0, 9);
	
	if (Ccount == 2) // ���� Ccount �� 2�� �ѱ�ٸ�
	{
		for (int i = 0; i < cardList.size(); i++) // cardList�� ũ�⸸ŭ i�� �����鼭
		{
			cardList[i]->SetState(0); // ī���� ��ġ�� ������ �ִ´�
		}
		Ccount = 0; // Ccount �� 0�� �ǰ�
	}
	Ccount++; // RodeHand�� �ѹ� �����Ҷ� ���� Ccount �� 1�� �þ��
	
	for (int i = 0; i < 5; i++)
	{
		bool skip = false; // �ٽ� ��ŵ�� false �� ����
		int iValue = intRand(rand); // iValue �� 0~9 ������ ������ ��

		if (cardList[iValue]->GetState() == CardState::EXCEPT) // ī�� ����Ʈ�� ��ġ�� ���� �ƴϸ� ����
		{
			i--; // �ڷ� ������
			skip = true; // ��ŵ�� Ʈ�簡 �ȴ�
		}
			
		if (i >= 1 && !skip)
		{
			for (int n = 0; n < handList.size(); n++) // �ڵ帮��Ʈ ��ŭ �Ʒ��� ����
			{
				if (handList[n] == cardList[iValue]) // �ڵ帮��Ʈ ���� ī�尡 ī�� ����Ʈ�� iValue ī��� �������
				{
					i--; // �ڷ� ������
					skip = true; // ��ŵ�� Ʈ�簡 �Ǹ�
					break; // �� �������� ���ư���
				}

			}
		}
		
		if (!skip) // ��ŵ�� Ʈ�簡 �Ǹ鼭 �̺κ� ����
		{
			handList.push_back(cardList[iValue]); // ��ŵ�� false �� ��� �ڵ� ����Ʈ�� ī�� ����Ʈ�� iValue ī�� ����
			handList[i]->SetState(1); // �ڵ� ����Ʈ ī����� ��ġ�� �ڵ�� �̵�			
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

#include "Framework.h"
#include "Card.h"

#include "character/Monster.h"
#include "character/Player.h"
//Card::Card(Card_DESC desc, vector <Vector3> Position, wstring ImagePath)
Card::Card(Card_DESC desc, wstring ImagePath)
	: TextureRect(position, Size, 0, ImagePath)
{
	//Costnumber = 3;
	dectector = new MouseDetector(this->GetBox()->GetEdge().LT, this->GetBox()->GetEdge().RB);
}

Card::Card(Card* sample)
	: TextureRect(sample->GetPosition(), sample->GetSize(), 0, sample->GetImagePath())
{
	//Sounds

	dectector = new MouseDetector(this->GetBox()->GetEdge().LT, this->GetBox()->GetEdge().RB);

	this->state = sample->state;
	this->type = sample->type;
	this->cost = sample->cost;
	this->Damge = sample->Damge;
	this->Defence = sample->Defence;
}

Card::~Card()
{
	SAFE_DELETE(dectector);
}

void Card::Update()
{
	dectector->Update(this->GetPosition(), this->GetSize());
	__super::Update();
}

void Card::Update(Vector3 position)
{
	if (state == HAND)
	{
		if (type == ATTACK)
		{
			if (dectector->IsOnMouseCursor())
			{
				this->position = position;
				this->size = Size;
			}
			if (dectector->IsOnMouseCursor() == false)
			{
				this->position = position - Vector3(0, 50, 0);
				this->size = Size - Vector3(50, 50, 0);
			}
			if (dectector->IsMouseDrag())
			{
				this->position = Mouse::Get()->GetPosition();
			}
		}

		else if (type == DEFENCE)
		{
			if (dectector->IsOnMouseCursor())
			{
				this->position = position;
				this->size = Size;
			}
			if (dectector->IsOnMouseCursor() == false)
			{
				this->position = position - Vector3(0, 50, 0);
				this->size = Size - Vector3(50, 50, 0);
			}
			if (dectector->IsMouseDrag())
			{
				this->position = Mouse::Get()->GetPosition();
			}
		}

		else if (type == POWER)
		{
			if (dectector->IsOnMouseCursor())
			{
				this->position = position;
				this->size = Size;
			}
			if (dectector->IsOnMouseCursor() == false)
			{
				this->position = position - Vector3(0, 50, 0);
				this->size = Size - Vector3(50, 50, 0);
			}
			if (dectector->IsMouseDrag())
			{
				this->position = Mouse::Get()->GetPosition();
			}
		}
	}
	Update();
}

void Card::Update(vector<Vector3> Position)
{
	for (int i = 0; i < Position.size(); i++)
	{
		this->position = Position[i];
	}
}

void Card::Update(Vector3 position, Vector3 Size)
{
	this->position = position;
	this->size = Size;
	Update();
}

void Card::Render()
{
	if (state == HAND)
		__super::Render();
}

bool Card::Use()
{
	if (position.y > 300 && dectector->IsMouseDragOff())
	{
		return true;
	}
	return false;
}

void Card::SetCost(int Cost)
{
	this->cost = Cost;
}

void Card::SetState(int number)
{
	if (number == 0)
		this->state = DECK;
	
	if (number == 1)
		this->state = HAND;
	
	if (number == 2)
		this->state = EXCEPT;
}

void Card::SetType(int number)
{

	if (number == 0)
		this->type = ATTACK;

	if (number == 1)
		this->type = DEFENCE;

	if (number == 2)
		this->type = POWER;
}

void Card::Ability(int dmg, int def)
{
	this->Damge = dmg;
	this->Defence = def;
}
#include "Framework.h"
#include "character.h"

#include "Cards/Card.h"
#include "Cards/Deck.h"

character::character(Vector3 Position, Vector3 Size, wstring ImagePath)
	:TextureRect(Position, Size, 0, ImagePath)
{
	deck = new Deck();
}

character::~character()
{
	SAFE_DELETE(deck);
}

void character::Update()
{
	if (Hp > 0)
	{
		__super::Update();
	}
}

void character::Update(Vector3 Position)
{
	this->position = Position;
	Update();
}

void character::Render()
{
	if (Hp > 0)
	{
		__super::Render();

	}
}

void character::SetMaxhp(int Maxhp)
{
	this->Maxhp = Maxhp;
}

void character::SetHp(int Hp)
{
	this->Hp = Hp;
}

void character::SetDamege(int Damege)
{
	this->Damege = Damege;
}

void character::SetDefence(int Defence)
{
	this->Defence = Defence;
}

void character::Setcost(int cost)
{
	this->cost = cost;
}

void character::SetGold(int Gold)
{
	this->Gold = Gold;
}

#include "Framework.h"
#include "Monster.h"

#include "character.h"

Monster::Monster()
{
	monster = new character(Vector3(950, 250, 0), Vector3(200, 200, 0), TexturePath + L"monster1.png");
}

Monster::~Monster()
{
	SAFE_DELETE(monster);
}

void Monster::Update()
{
	monster->Update();
	monster->SetMaxhp(20);
	monster->SetDamege(6);
	monster->SetGold(16);
}

void Monster::Render()
{
	monster->Render();
}


#pragma once

#include "Geomatries/TextureRect.h"

class character : public TextureRect
{
public:
	character(Vector3 Position, Vector3 Size, wstring ImagePath);
	~character();

	void Update(); 
	void Update(Vector3 Position);
	void Render();

	void SetMaxhp(int Maxhp);
	void SetHp(int Hp);
	void SetDamege(int Damege);
	void SetDefence(int Defence);
	void Setcost(int cost);
	void SetGold(int Gold);

	const int GetMaxhp() { return Maxhp; }
	const int GetHp() { return Hp; }
	const int GetDamege() { return Damege; }
	const int GetDefence() { return Defence; }
	const int Getcost() { return cost; }
	const int GetGold() { return Gold; }
private:
	int Maxhp;
	int Hp = Maxhp;
	int Damege;
	int Defence;
	int cost;
	int Gold;
	

private:
	class Deck* deck;
	class Card* card;
};
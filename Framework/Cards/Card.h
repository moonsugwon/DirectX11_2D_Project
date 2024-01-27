#pragma once

#include "Geomatries/TextureRect.h"

enum CardType
{
	ATTACK = 0,
	DEFENCE,
	POWER
};

enum CardState
{
	DECK = 0,
	HAND,
	EXCEPT
};

typedef struct Card_DESC
{
	CardType Type;
	//int Cost;
	CardState State;
	//wstring ImagePath;
};

class Card : public TextureRect
{
public:

	//Card(Card_DESC desc, vector <Vector3> Position, wstring ImagePath);
	//Card(Vector3 position, Vector3 size, wstring ImagePath);
	Card(Card_DESC desc, wstring ImagePath);
	Card(Card* sample);
	~Card();

	void Update();
	void Update(Vector3 position);
	void Update(vector <Vector3> Position);
	void Update(Vector3 position, Vector3 Size);

	void Render();

	bool Use();


	void SetType(int number);
	void SetState(int number);
	void SetCost(int Cost);
	//void SetNumber(int Setnumber);

	void Ability(int dmg, int def);

	const int CardDmg() { return Damge; }
	const int CardDef() { return Defence; }
	const int GetType() { return type; }
	const int GetState() { return state; }
	const int GetCost() { return cost; }
	//const int GetCostnumber() { return Costnumber; }

	//BoundingBox* GetBox() { return box; }

private:
	int cost;
	int Damge;
	int Defence;
	//int Costnumber;
	//int Setnumber;
	
	CardType type;
	CardState state;
	

	Vector3 Size = Vector3(225, 225, 0);
	//vector <Vector3> Position;
private:
	MouseDetector* dectector;
	//BoundingBox* box;
};
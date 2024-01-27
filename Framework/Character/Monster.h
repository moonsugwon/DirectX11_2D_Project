#pragma once

class Monster
{
public:
	Monster();
	~Monster();

	void Update();
	void Render();

	const int GetHp() { return Hp; }

private:
	int Hp;

private:
	class character* monster = nullptr;
};
#pragma once

class Player
{
public:
	Player();
	~Player();

	void Update();
	void Render(); 

private:

private:
	class character* player = nullptr;
};
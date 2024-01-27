#include "Framework.h"
#include "Player.h"

#include "character.h"

Player::Player()
{
	player = new character(Vector3(350, 250, 0), Vector3(200, 200, 0), TexturePath + L"player1.png");
}


Player::~Player()
{
	SAFE_DELETE(player);
}

void Player::Update()
{
	player->Update();
	
}

void Player::Render()
{
	player->Render();
}
#include "stdafx.h"
#include "TestDemo.h"

#include "Geomatries/TextureRect.h"
#include "Cards/Hand.h"
#include "Cards/Card.h"
//#include "Character/Player.h"
//#include "Character/Monster.h"
#include "Character/character.h"
#include "HUD.h"


void TestDemo::Init()
{
	//BackGround
	{
		s1 = new TextureRect(Vector3(650, 200, 0), Vector3(1350, 1020, 0), 0.0f, TexturePath + L"scene1.png");
		s2 = new TextureRect(Vector3(630, 370, 0), Vector3(500, 600, 0), 0.0f, TexturePath + L"Reward.png");
		s3 = new TextureRect(Vector3(680, 370, 0), Vector3(2000, 600, 0), 0.0f, TexturePath + L"MAP1.png");
		s4 = new TextureRect(Vector3(650, 340, 0), Vector3(1300, 650, 0), 0.0f, TexturePath + L"Shop.png");
		s5 = new TextureRect(Vector3(650, 340, 0), Vector3(1300, 700, 0), 0.0f, TexturePath + L"EventPage1.png");

		//campfire
		s6 = new TextureRect(Vector3(630, 350, 0), Vector3(1300, 700, 0), 0.0f, TexturePath + L"CampOn.png");
		s7 = new TextureRect(Vector3(630, 350, 0), Vector3(1300, 700, 0), 0.0f, TexturePath + L"CampOff.png");

	}

	//NPC
	{
		n1 = new TextureRect(Vector3(1100, 350, 0), Vector3(700, 600, 0), 0.0f, TexturePath + L"Whale.png");
		n2 = new TextureRect(Vector3(900, 350, 0), Vector3(250, 300, 0), 0.0f, TexturePath + L"ShopNPC.png");
	}

	// UI
	{
		u1 = new TextureRect(Vector3(700, 680, 0), Vector3(2080, 100, 0), 0.0f, TexturePath + L"bar.png");
		u2 = new TextureRect(Vector3(1150, 700, 0), Vector3(40, 40, 0), -0.1f, TexturePath + L"map.png");
		u3 = new TextureRect(Vector3(400, 700, 0), Vector3(40, 40, 0), 0.0f, TexturePath + L"GoldBag.png");
		u4 = new TextureRect(Vector3(650, 700, 0), Vector3(40, 40, 0), 0.0f, TexturePath + L"floor.png");
		u5 = new TextureRect(Vector3(1200, 700, 0), Vector3(40, 40, 0), 0.0f, TexturePath + L"deck.png");
		u6 = new TextureRect(Vector3(250, 700, 0), Vector3(40, 40, 0), 0.0f, TexturePath + L"Heart.png");
		u7 = new TextureRect(Vector3(1250, 700, 0), Vector3(40, 40, 0), 0.0f, TexturePath + L"settings.png");
		u8 = new TextureRect(Vector3(0, 0, 0), Vector3(40, 40, 0), 0.0f, TexturePath + L"cusor.png");
		u9 = new TextureRect(Vector3(1150, 200, 0), Vector3(150, 150, 0), 0.0f, TexturePath + L"EndButtonOn.png");
		u10 = new TextureRect(Vector3(1150, 200, 0), Vector3(150, 150, 0), 0.0f, TexturePath + L"EndButtonOff.png");
		u11 = new TextureRect(Vector3(50, 50, 0), Vector3(100, 100, 0), 0.0f, TexturePath + L"cardList.png");
		u12 = new TextureRect(Vector3(1200, 50, 0), Vector3(100, 100, 0), 0.0f, TexturePath + L"Except.png");
		u13 = new TextureRect(Vector3(100, 150, 0), Vector3(150, 150, 0), 0.0f, TexturePath + L"cost.png");
		u14 = new TextureRect(Vector3(300, 100, 0), Vector3(500, 35, 0), 0.0f, TexturePath + L"MaxHealthUp.png");
		u15 = new TextureRect(Vector3(300, 100, 0), Vector3(500, 35, 0), 0.0f, TexturePath + L"MaxHealthUpSelect.png");
		u16 = new TextureRect(Vector3(300, 600, 0), Vector3(100, 100, 0), 0.0f, TexturePath + L"sleep.png");

		//Map Icon
		M1 = new TextureRect(Vector3(500, 150, 0), Vector3(100, 100, 0), 0.0f, TexturePath + L"MapMonster.png");
		M2 = new TextureRect(Vector3(650, 600, 0), Vector3(250, 250, 0), 0.0f, TexturePath + L"BossMap.png");
		M3 = new TextureRect(Vector3(550, 450, 0), Vector3(100, 100, 0), 0.0f, TexturePath + L"EventMap.png");
		M4 = new TextureRect(Vector3(650, 350, 0), Vector3(100, 100, 0), 0.0f, TexturePath + L"ShopMap.png");
		M5 = new TextureRect(Vector3(600, 250, 0), Vector3(100, 100, 0), 0.0f, TexturePath + L"BoxMap.png");
		M6 = new TextureRect(Vector3(700, 500, 0), Vector3(100, 100, 0), 0.0f, TexturePath + L"FireMap.png");

		M7 = new TextureRect(Vector3(500, 150, 0), Vector3(150, 150, 0), 0.0f, TexturePath + L"SelectMap.png");
		M8 = new TextureRect(Vector3(500, 150, 0), Vector3(150, 150, 0), 0.0f, TexturePath + L"SelectMap.png");
		M9 = new TextureRect(Vector3(500, 150, 0), Vector3(150, 150, 0), 0.0f, TexturePath + L"SelectMap.png");
		M10 = new TextureRect(Vector3(500, 150, 0), Vector3(150, 150, 0), 0.0f, TexturePath + L"SelectMap.png");
		M11 = new TextureRect(Vector3(500, 150, 0), Vector3(150, 150, 0), 0.0f, TexturePath + L"SelectMap.png");
		M12 = new TextureRect(Vector3(500, 150, 0), Vector3(150, 150, 0), 0.0f, TexturePath + L"SelectMap.png");

		M13 = new TextureRect(Vector3(1150, 200, 0), Vector3(150, 150, 0), 0.0f, TexturePath + L"PassButton.png");
		M14 = new TextureRect(Vector3(950, 300, 0), Vector3(300, 300, 0), 0.0f, TexturePath + L"BoxClose.png");
		M15 = new TextureRect(Vector3(950, 300, 0), Vector3(300, 300, 0), 0.0f, TexturePath + L"BoxOpen.png");
		M16 = new TextureRect(Vector3(300, 200, 0), Vector3(150, 150, 0), 0.0f, TexturePath + L"no.png");
		M17 = new TextureRect(Mouse::Get()->GetPosition(), Vector3(200, 300, 0), 0.0f, TexturePath + L"ShopMouse.png");
	}

	//Relics
	{
		Relic1 = new TextureRect(Vector3(80, 650, 0), Vector3(100, 100, 0), 0.0f, TexturePath + L"Relic1.png");
		Relic2 = new TextureRect(Vector3(150, 650, 0), Vector3(100, 100, 0), 0.0f, TexturePath + L"Relic2.png");
		Relic3 = new TextureRect(Vector3(150, 650, 0), Vector3(100, 100, 0), 0.0f, TexturePath + L"Relic3.png");
	}

	//SelectBox
	{
		sb1 = new TextureRect(Vector3(625, 550, 0), Vector3(400, 250, 0), 0.0f, TexturePath + L"GoldBox.png");
		sb2 = new TextureRect(Vector3(625, 550, 0), Vector3(400, 250, 0), 0.0f, TexturePath + L"GoldBox2.png");
		sb3 = new TextureRect(Vector3(625, 550, 0), Vector3(400, 250, 0), 0.0f, TexturePath + L"RelicBox.png");
		sb4 = new TextureRect(Vector3(625, 550, 0), Vector3(400, 250, 0), 0.0f, TexturePath + L"RelicBox2.png");
	}

	//Event Button
	{
		eb1 = new TextureRect(Vector3(920, 325, 0), Vector3(500, 50, 0), 0.0f, TexturePath + L"EventButton1.png");
		eb2 = new TextureRect(Vector3(920, 325, 0), Vector3(500, 50, 0), 0.0f, TexturePath + L"EventButton2.png");
		eb3 = new TextureRect(Vector3(920, 280, 0), Vector3(500, 50, 0), 0.0f, TexturePath + L"EventButton3.png");
		eb4 = new TextureRect(Vector3(920, 280, 0), Vector3(500, 50, 0), 0.0f, TexturePath + L"EventButton4.png");
		eb5 = new TextureRect(Vector3(920, 235, 0), Vector3(500, 50, 0), 0.0f, TexturePath + L"EventButton5.png");
		eb6 = new TextureRect(Vector3(920, 235, 0), Vector3(500, 50, 0), 0.0f, TexturePath + L"EventButton6.png");
	}

	//number
	{
		num0 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberZero.png");
		num1 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberOne.png");
		num2 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberTwo.png");
		num3 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberThree.png");
		num4 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberFour.png");
		num5 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberFive.png");
		num6 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberSix.png");
		num7 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberSeven.png");
		num8 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberEight.png");
		num9 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberNine.png");
		num10 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberZero.png");
		num11 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberOne.png");
		num12 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberTwo.png");
		num13 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberThree.png");
		num14 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberFour.png");
		num15 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberFive.png");
		num16 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberSix.png");
		num17 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberSeven.png");
		num18 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberEight.png");
		num19 = new TextureRect(Vector3(950, 300, 0), Vector3(35, 35, 0), 0.0f, TexturePath + L"numberNine.png");
	}

	//Player
	{
		//player = new Player();
		player = new character(Vector3(300, 250, 0), Vector3(150, 150, 0), TexturePath + L"player1.png");
	}

	//Monster
	{
		//monster = new Monster();
		monster = new character(Vector3(950, 250, 0), Vector3(150, 150, 0), TexturePath + L"monster1.png");
		Boss = new character(Vector3(950, 350, 0), Vector3(400, 400, 0), TexturePath + L"SlimeKing.png");
		LBoss = new character(Vector3(850, 250, 0), Vector3(200, 200, 0), TexturePath + L"LBoss.png");
		RBoss = new character(Vector3(1050, 250, 0), Vector3(200, 200, 0), TexturePath + L"RBoss.png");

		e5 = new TextureRect(monster->GetPosition() + Vector3(0, 10, 0), Vector3(100, 100, 0), 0.0f, TexturePath + L"Monster_attack.png");
		e6 = new TextureRect(Boss->GetPosition() + Vector3(0, 30, 0), Vector3(100, 100, 0), 0.0f, TexturePath + L"question_mark.png");
		e7 = new TextureRect(Vector3(0, 10, 0), Vector3(100, 100, 0), 0.0f, TexturePath + L"Power_Mark.png");
		e8 = new TextureRect(Vector3(0, 10, 0), Vector3(100, 100, 0), 0.0f, TexturePath + L"Shiled_Mark.png");
		e9 = new TextureRect(Boss->GetPosition() + Vector3(0, 30, 0), Vector3(100, 100, 0), 0.0f, TexturePath + L"Boss_attackDefend.png");
		e10 = new TextureRect(Boss->GetPosition() + Vector3(0, 30, 0), Vector3(100, 100, 0), 0.0f, TexturePath + L"Boss_attack_Mark.png");
		e11 = new TextureRect(Boss->GetPosition() + Vector3(0, 30, 0), Vector3(150, 150, 0), 0.0f, TexturePath + L"Boss_Attack_Effect.png");
		e12 = new TextureRect(Boss->GetPosition() + Vector3(0, 50, 0), Vector3(150, 150, 0), 0.0f, TexturePath + L"Boss_Pattern2.png");
	}

	//Cards
	{
		hand = new Hand();
	}

	//Effect
	{
		e1 = new TextureRect(Vector3(950, 250, 0), Vector3(200, 200, 0), 0.0f, TexturePath + L"effect1.png");
		e2 = new TextureRect(Vector3(300, 250, 0), Vector3(250, 250, 0), 0.0f, TexturePath + L"Shiled.png");
		e3 = new TextureRect(Vector3(300, 250, 0), Vector3(350, 350, 0), 0.0f, TexturePath + L"MonsterAttack.png");
		e4 = new TextureRect(Vector3(370, 250, 0), Vector3(350, 350, 0), 0.0f, TexturePath + L"Cardcut.png");
	}

	mpos = new MouseDetector(u5->GetBox()->GetEdge().LT, u5->GetBox()->GetEdge().RB);
	mpos2 = new MouseDetector(u9->GetBox()->GetEdge().LT, u9->GetBox()->GetEdge().RB);
	mpos3 = new MouseDetector(u11->GetBox()->GetEdge().LT, u11->GetBox()->GetEdge().RB);
	mpos4 = new MouseDetector(u12->GetBox()->GetEdge().LT, u12->GetBox()->GetEdge().RB);
	mpos5 = new MouseDetector(u14->GetBox()->GetEdge().LT, u14->GetBox()->GetEdge().RB);

	//Map Icon
	mpos6 = new MouseDetector(M1->GetBox()->GetEdge().LT, M1->GetBox()->GetEdge().RB);
	mpos7 = new MouseDetector(M2->GetBox()->GetEdge().LT, M2->GetBox()->GetEdge().RB);
	mpos8 = new MouseDetector(M3->GetBox()->GetEdge().LT, M3->GetBox()->GetEdge().RB);
	mpos9 = new MouseDetector(M4->GetBox()->GetEdge().LT, M4->GetBox()->GetEdge().RB);
	mpos10 = new MouseDetector(M5->GetBox()->GetEdge().LT, M5->GetBox()->GetEdge().RB);
	mpos11 = new MouseDetector(M6->GetBox()->GetEdge().LT, M6->GetBox()->GetEdge().RB);
	mpos12 = new MouseDetector(M13->GetBox()->GetEdge().LT, M13->GetBox()->GetEdge().RB);

	mpos13 = new MouseDetector(M14->GetBox()->GetEdge().LT, M14->GetBox()->GetEdge().RB);
	mpos14 = new MouseDetector(sb1->GetBox()->GetEdge().LT, sb1->GetBox()->GetEdge().RB);
	mpos15 = new MouseDetector(sb3->GetBox()->GetEdge().LT, sb3->GetBox()->GetEdge().RB);

	mpos16 = new MouseDetector(n2->GetBox()->GetEdge().LT, n2->GetBox()->GetEdge().RB);
	mpos17 = new MouseDetector(M16->GetBox()->GetEdge().LT, M16->GetBox()->GetEdge().RB);

	mpos18 = new MouseDetector(eb1->GetBox()->GetEdge().LT, eb1->GetBox()->GetEdge().RB);
	mpos19 = new MouseDetector(eb3->GetBox()->GetEdge().LT, eb3->GetBox()->GetEdge().RB);
	mpos20 = new MouseDetector(eb5->GetBox()->GetEdge().LT, eb5->GetBox()->GetEdge().RB);
	mpos21 = new MouseDetector(u16->GetBox()->GetEdge().LT, u16->GetBox()->GetEdge().RB);

	//Timer
	{

	}

	//Hp bar
	{
		hud = new HUD();
	}

	//sounds
	{
		Sounds::Create();
		Sounds::Get()->AddSound("fight",SoundPath + L"Fightbgm.mp3");
		Sounds::Get()->AddSound("CardUse", SoundPath + L"Card_Use.mp3");
		Sounds::Get()->AddSound("TurnEndBtn", SoundPath + L"Turn_End_Btn.mp3");
		Sounds::Get()->AddSound("PlayerTurn", SoundPath + L"Player_Turn.mp3");
		Sounds::Get()->AddSound("EnemyTurn", SoundPath + L"Enemy_Turn.mp3");
		Sounds::Get()->AddSound("MonsterAttackDefence", SoundPath + L"Monster_Attack_Defence.mp3");
		Sounds::Get()->AddSound("BreakDefence", SoundPath + L"Break_Defence.mp3");
		Sounds::Get()->AddSound("EnemyAtk", SoundPath + L"Enemy_Attack.mp3");
		Sounds::Get()->AddSound("PlayerAtk1", SoundPath + L"Player_Attack1.mp3");
		Sounds::Get()->AddSound("PlayerAtk2", SoundPath + L"Player_Attack2.mp3");
		Sounds::Get()->AddSound("DefSet" , SoundPath + L"Defence_Set.mp3");
		Sounds::Get()->AddSound("BackGround", SoundPath + L"BackGround.mp3");
		Sounds::Get()->AddSound("SelectMap", SoundPath + L"SelectMap.mp3");
		Sounds::Get()->AddSound("GetGold", SoundPath + L"GetGold.mp3");
		Sounds::Get()->AddSound("BoxOpen", SoundPath + L"BoxOpen.mp3");
		Sounds::Get()->AddSound("MapOpen", SoundPath + L"MapOpen.mp3");
		Sounds::Get()->AddSound("ShopOpen", SoundPath + L"ShopOpen.mp3");
		Sounds::Get()->AddSound("ShopClose", SoundPath + L"ShopClose.mp3");
		Sounds::Get()->AddSound("ShopBgm", SoundPath + L"ShopBGM.mp3");
		Sounds::Get()->AddSound("CampOn", SoundPath + L"CampOn.mp3");
		Sounds::Get()->AddSound("CampOff", SoundPath + L"CampOff.mp3");
		Sounds::Get()->AddSound("BossBgm", SoundPath + L"BossBgm.mp3");
		Sounds::Get()->AddSound("BossOn", SoundPath + L"BossOn.mp3");
		Sounds::Get()->AddSound("BossAtk", SoundPath + L"Boss_Attack1.mp3");
		Sounds::Get()->AddSound("Boss_Hpdown", SoundPath + L"Boss_Hpdown.mp3");
		Sounds::Get()->AddSound("BossVictory", SoundPath + L"Boss_Victory.mp3");

		Sounds::Get()->Play("BackGround", 0.1f);
	}
}

void TestDemo::Destroy()
{
	SAFE_DELETE(s1);
	SAFE_DELETE(s2);
	SAFE_DELETE(s3);
	SAFE_DELETE(s4);
	SAFE_DELETE(s5);
	SAFE_DELETE(s6);
	SAFE_DELETE(s7);

	SAFE_DELETE(n1);
	SAFE_DELETE(n2);

	SAFE_DELETE(u1);
	SAFE_DELETE(u2);
	SAFE_DELETE(u3);
	SAFE_DELETE(u4);
	SAFE_DELETE(u5);
	SAFE_DELETE(u6);
	SAFE_DELETE(u7);
	SAFE_DELETE(u8);
	SAFE_DELETE(u9);
	SAFE_DELETE(u10);
	SAFE_DELETE(u11);
	SAFE_DELETE(u12);
	SAFE_DELETE(u13);
	SAFE_DELETE(u14);
	SAFE_DELETE(u15);
	SAFE_DELETE(u16);

	SAFE_DELETE(M1);
	SAFE_DELETE(M2);
	SAFE_DELETE(M3);
	SAFE_DELETE(M4);
	SAFE_DELETE(M5);
	SAFE_DELETE(M6);
	SAFE_DELETE(M7);
	SAFE_DELETE(M8);
	SAFE_DELETE(M9);
	SAFE_DELETE(M10);
	SAFE_DELETE(M11);
	SAFE_DELETE(M12);
	SAFE_DELETE(M13);
	SAFE_DELETE(M14);
	SAFE_DELETE(M15);
	SAFE_DELETE(M16);
	SAFE_DELETE(M17);

	SAFE_DELETE(Relic1);
	SAFE_DELETE(Relic2);
	SAFE_DELETE(Relic3);

	SAFE_DELETE(sb1);
	SAFE_DELETE(sb2);
	SAFE_DELETE(sb3);
	SAFE_DELETE(sb4);

	SAFE_DELETE(eb1);
	SAFE_DELETE(eb2);
	SAFE_DELETE(eb3);
	SAFE_DELETE(eb4);
	SAFE_DELETE(eb5);
	SAFE_DELETE(eb6);

	SAFE_DELETE(num0);
	SAFE_DELETE(num1);
	SAFE_DELETE(num2);
	SAFE_DELETE(num3);
	SAFE_DELETE(num4);
	SAFE_DELETE(num5);
	SAFE_DELETE(num6);
	SAFE_DELETE(num7);
	SAFE_DELETE(num8);
	SAFE_DELETE(num9);
	SAFE_DELETE(num10);
	SAFE_DELETE(num11);
	SAFE_DELETE(num12);
	SAFE_DELETE(num13);
	SAFE_DELETE(num14);
	SAFE_DELETE(num15);
	SAFE_DELETE(num16);
	SAFE_DELETE(num17);
	SAFE_DELETE(num18);
	SAFE_DELETE(num19);

	SAFE_DELETE(player);
	SAFE_DELETE(monster);

	SAFE_DELETE(Boss);
	SAFE_DELETE(LBoss);
	SAFE_DELETE(RBoss);

	SAFE_DELETE(e5);
	SAFE_DELETE(e6);
	SAFE_DELETE(e7);
	SAFE_DELETE(e8);
	SAFE_DELETE(e9);
	SAFE_DELETE(e10);
	SAFE_DELETE(e11);
	SAFE_DELETE(e12);

	SAFE_DELETE(hand);

	SAFE_DELETE(e1);
	SAFE_DELETE(e2);
	SAFE_DELETE(e3);
	SAFE_DELETE(e4);

	SAFE_DELETE(mpos);
	SAFE_DELETE(mpos2);
	SAFE_DELETE(mpos3);
	SAFE_DELETE(mpos4);
	SAFE_DELETE(mpos5);

	SAFE_DELETE(mpos6);
	SAFE_DELETE(mpos7);
	SAFE_DELETE(mpos8);
	SAFE_DELETE(mpos9);
	SAFE_DELETE(mpos10);
	SAFE_DELETE(mpos11);
	SAFE_DELETE(mpos12);

	SAFE_DELETE(mpos13);
	SAFE_DELETE(mpos14);
	SAFE_DELETE(mpos15);

	SAFE_DELETE(mpos16);
	SAFE_DELETE(mpos17);

	SAFE_DELETE(mpos18);
	SAFE_DELETE(mpos19);
	SAFE_DELETE(mpos20);
	SAFE_DELETE(mpos21);

	SAFE_DELETE(hud);
}

void TestDemo::Update()
{
	mpos->Update(u5->GetPosition(), u5->GetSize());
	mpos2->Update(u9->GetPosition(), u9->GetSize());
	mpos3->Update(u11->GetPosition(), u11->GetSize());
	mpos4->Update(u12->GetPosition(), u12->GetSize());
	mpos5->Update(u14->GetPosition(), u14->GetSize());

	mpos6->Update(M1->GetPosition(), M1->GetSize());
	mpos7->Update(M2->GetPosition(), M2->GetSize());
	mpos8->Update(M3->GetPosition(), M3->GetSize());
	mpos9->Update(M4->GetPosition(), M4->GetSize());
	mpos10->Update(M5->GetPosition(), M5->GetSize());
	mpos11->Update(M6->GetPosition(), M6->GetSize());

	mpos12->Update(M13->GetPosition(), M13->GetSize());

	mpos13->Update(M14->GetPosition(), M14->GetSize());
	mpos14->Update(sb1->GetPosition(), sb1->GetSize());
	mpos15->Update(sb3->GetPosition(), sb3->GetSize());

	mpos16->Update(n2->GetPosition(), n2->GetSize());
	mpos17->Update(M16->GetPosition(), M16->GetSize());

	mpos18->Update(eb1->GetPosition(), eb1->GetSize());
	mpos19->Update(eb3->GetPosition(), eb3->GetSize());
	mpos20->Update(eb5->GetPosition(), eb5->GetSize());
	mpos21->Update(u16->GetPosition(), u16->GetSize());


	s1->Update();
	s2->Update();
	s3->Update();
	s4->Update();
	s5->Update();
	s6->Update();
	s7->Update();

	num0->Update();
	num1->Update();
	num2->Update();
	num3->Update();
	num4->Update();
	num5->Update();
	num6->Update();
	num7->Update();
	num8->Update();
	num9->Update();
	num10->Update();
	num11->Update();
	num12->Update();
	num13->Update();
	num14->Update();
	num15->Update();
	num16->Update(e5->GetPosition() + Vector3(15, -3, 0), Vector3(10, 10, 0));
	num17->Update();
	num18->Update();
	num19->Update();

	if (Hcount == 0)
	{
		Relic1->Update();
		Relic2->Update();
		Relic3->Update();
		n1->Update();
		u14->Update();
		u15->Update();
	}

	u1->Update();
	u2->Update();
	u3->Update();
	u4->Update();

	{
		if (mpos->IsOnMouseCursor())
		{
			u5->Update(Vector3(1200, 700, 0), Vector3(55, 55, 0));
		}
		else if (mpos->IsOnMouseCursor() == false)
		{
			u5->Update(Vector3(1200, 700, 0), Vector3(40, 40, 0));
		}
	}
	
	u6->Update();
	u7->Update();
	u8->Update(Mouse::Get()->GetPosition() - Vector3(0, 10, 0));
	u9->Update();
	u10->Update();

	if (monster->GetHp() > 0 && PTurn)
	{
		//u11->Update();
		if (mpos3->IsOnMouseCursor())
		{
			u11->Update(Vector3(50, 50, 0), Vector3(110, 110, 0));
		}
		else if (mpos3->IsOnMouseCursor() == false)
		{
			u11->Update(Vector3(50, 50, 0), Vector3(90, 90, 0));
		}
		//u12->Update();
		if (mpos4->IsOnMouseCursor())
		{
			u12->Update(Vector3(1200, 50, 0), Vector3(100, 100, 0));
		}
		else if (mpos4->IsOnMouseCursor() == false)
		{
			u12->Update(Vector3(1200, 50, 0), Vector3(90, 90, 0));
		}
		if (mpos4->IsMouseLClick())
		{
			for (int i = 0; i < hand->GetListSize(); i++)
			{
				hand->GetdeckList(i)->Update();
			}
		}
		u13->Update();
		hand->Update();
	}
	else if (monster->GetHp() <= 0)
	{
		if (mpos12->IsOnMouseCursor())
		{
			M13->Update(Vector3(1150, 200, 0), Vector3(200, 200, 0));
		}
		else if (mpos12->IsOnMouseCursor() == false)
		{
			M13->Update(Vector3(1150, 200, 0), Vector3(150, 150, 0));
		}
	}

	if (Boss->GetHp() > 0)
	{
		if (mpos3->IsOnMouseCursor())
		{
			u11->Update(Vector3(50, 50, 0), Vector3(110, 110, 0));
		}
		else if (mpos3->IsOnMouseCursor() == false)
		{
			u11->Update(Vector3(50, 50, 0), Vector3(90, 90, 0));
		}

		if (mpos4->IsOnMouseCursor())
		{
			u12->Update(Vector3(1200, 50, 0), Vector3(100, 100, 0));
		}
		else if (mpos4->IsOnMouseCursor() == false)
		{
			u12->Update(Vector3(1200, 50, 0), Vector3(90, 90, 0));
		}

		u13->Update();
		hand->Update();
	}

	//player
	{
		if (Hcount == 0)
		{
			player->SetMaxhp(100);
			Hp = player->GetMaxhp();
			player->SetHp(Hp);
			player->SetGold(99);
			player->Setcost(3);
		}
		player->SetDamege(hand->GetDamege());
		if (Rcount == 2)
		{
			player->SetDamege(hand->GetDamege() + 2);
		}
		player->SetDefence(hand->GetDefence());
		if (Rcount == 3)
		{
			player->SetDefence(hand->GetDefence() + 2);
		}
		player->Update();
	}
	//monster
	{
		monster->SetMaxhp(40);
		if (Hcount == 0)
		{
			Hp = monster->GetMaxhp();
			monster->SetHp(Hp);
			monster->SetDamege(6);
			monster->SetGold(16);
			
		}
		if (monster->GetHp() > 0)
		{
			monster->Update();
		}
		if (monster->GetHp() <= 0)
		{
			Sounds::Get()->Pause("fight");
		}
	}

	//Boss
	{
		if (Mapcount == 16)
		{
			Boss->SetMaxhp(120);

			Hp = Boss->GetMaxhp();
			Boss->SetHp(Hp);
			Boss->SetDamege(10);

			Boss->Update();
		}
		//LBoss->SetMaxhp(120);
		//LBoss->SetHp(Hp);
		//
		//RBoss->SetMaxhp(120);
		//RBoss->SetHp(Hp);
		//
		//LBoss->Update();
		//RBoss->Update();
	}
	
	
	M7->Update(M1->GetPosition());
	M8->Update(M2->GetPosition());
	M9->Update(M3->GetPosition());
	M10->Update(M4->GetPosition());
	M11->Update(M5->GetPosition());
	M12->Update(M6->GetPosition());

	if (Mapcount == 1)
	{
		M1->Update();
		M2->Update();
		M3->Update();
		M4->Update();
		M5->Update();
		M6->Update();

		if (mpos6->IsOnMouseCursor())
		{
			M1->Update(Vector3(500, 150, 0), Vector3(150, 150, 0));
		}
		else if (mpos6->IsOnMouseCursor() == false)
		{
			M1->Update(Vector3(500, 150, 0), Vector3(100, 100, 0));
		}
	}

	if (Mapcount == 4)
	{
		if (mpos10->IsOnMouseCursor())
		{
			M5->Update(Vector3(600, 250, 0), Vector3(150, 150, 0));
		}
		else if (mpos10->IsOnMouseCursor() == false)
		{
			M5->Update(Vector3(600, 250, 0), Vector3(100, 100, 0));
		}
	}

	if (Mapcount == 5)
	{
		if (mpos13->IsOnMouseCursor())
		{
			M14->Update(Vector3(950, 300, 0), Vector3(300, 300, 0));
		}
		else if (mpos13->IsOnMouseCursor() == false)
		{
			M14->Update(Vector3(950, 300, 0), Vector3(250, 250, 0));
		}
	}
	M15->Update();
	M16->Update();

	sb1->Update();
	sb2->Update();
	sb3->Update();
	sb4->Update();

	if (Mapcount == 8)
	{
		if (mpos9->IsOnMouseCursor())
		{
			M4->Update(Vector3(650, 350, 0), Vector3(150, 150, 0));
		}
		else if (mpos9->IsOnMouseCursor() == false)
		{
			M4->Update(Vector3(650, 350, 0), Vector3(100, 100, 0));
		}
	}

	if (Mapcount == 9)
	{
		if (mpos16->IsOnMouseCursor())
		{
			n2->Update(Vector3(950, 220, 0), Vector3(350, 350, 0));
		}
		else if (mpos16->IsOnMouseCursor() == false)
		{
			n2->Update(Vector3(950, 220, 0), Vector3(300, 300, 0));
		}
	}

	if (Mapcount == 10)
	{
		M17->Update(Mouse::Get()->GetPosition() - Vector3(0, 140, 0));
	}

	if (Mapcount == 11)
	{
		eb1->Update();
		eb2->Update();
		eb3->Update();
		eb4->Update();
		eb5->Update();
		eb6->Update();
		if (mpos8->IsOnMouseCursor())
		{
			M3->Update(Vector3(550, 450, 0), Vector3(150, 150, 0));
		}
		else if (mpos8->IsOnMouseCursor() == false)
		{
			M3->Update(Vector3(550, 450, 0), Vector3(100, 100, 0));
		}
	}

	if (Mapcount == 13)
	{
		if (mpos11->IsOnMouseCursor())
		{
			M6->Update(Vector3(700, 500, 0), Vector3(150, 150, 0));
		}
		else if (mpos11->IsOnMouseCursor() == false)
		{
			M6->Update(Vector3(700, 500, 0), Vector3(100, 100, 0));
		}
	}

	if (Mapcount == 14)
	{
		if (mpos21->IsOnMouseCursor())
		{
			u16->Update(Vector3(500, 500, 0), Vector3(300, 300, 0));
		}
		else if (mpos21->IsOnMouseCursor() == false)
		{
			u16->Update(Vector3(500, 500, 0), Vector3(250, 250, 0));
		}
	}

	if (Mapcount == 16)
	{
		if (mpos7->IsOnMouseCursor())
		{
			M2->Update(Vector3(650, 600, 0), Vector3(300, 300, 0));
		}
		else if (mpos7->IsOnMouseCursor() == false)
		{
			M2->Update(Vector3(650, 600, 0), Vector3(250, 250, 0));
		}
	}

	e5->Update();
	e6->Update();
	e7->Update(player->GetPosition() + Vector3(50, -80, 0), Vector3(50, 50, 0));
	e8->Update(player->GetPosition() + Vector3(50, -80, 0), Vector3(50, 50, 0));
	e9->Update();
	e10->Update();
	e11->Update();
	e12->Update();

	e1->Update();
	//e1->Update(monster->GetPosition());
	e2->Update();
	e3->Update();
	//e3->Update(player->GetPosition());
	e4->Update();
	//test
	hud->Update();
}

void TestDemo::Render()
{
	s1->Render();

	player->Render();

	if (Hcount == 2 && Mapcount == 2)
	{
		monster->Render();
	}

	if (monster->GetHp() > 0)
	{
		u11->Render();
		u12->Render();
		u13->Render();
		hand->Render();
	}
	
	if (mpos->IsMouseLClick())
	{
		cout << "click" << endl;
		//if (mpos->IsMouseLClick())
		//{
		//	//덱 리스트 출력할 배경 과 카드 출력
		//	for (int i = 0; i < hand->GetListSize(); i++)
		//	{
		//		hand->GetdeckList(i)->Update(Vector3(50 + (50 * i), 500, 0));
		//	}
		//}
	}

	if (mpos4->IsMouseLClick())
	{
		if (hand->GetState() == 0)
		{
			for (int i = 0; i < hand->GetListSize(); i++)
			{
				hand->GetdeckList(i)->Render();
			}
		}
	}

	//BossBattle
	if (Mapcount == 17)
	{
		u11->Render();
		u12->Render();
		u13->Render();
		Boss->Render();
		e6->Render();
		hand->Render();
		//Mapcount++;
	}
	if (Mapcount == 18)
	{
		if (Boss->GetMaxhp() / 2 > Boss->GetHp())
		{
			LBoss->SetMaxhp(Boss->GetHp());
			RBoss->SetMaxhp(Boss->GetHp());
			LBoss->SetHp(Boss->GetHp());
			RBoss->SetHp(Boss->GetHp());

			BossEffectcount = 2;
		}
		u11->Render();
		u12->Render();
		u13->Render();
		Boss->Render();

		if (BossEffectcount == 2)
		{
			e12->Render();
		}
		if (BossEffectcount == 6)
		{
			e6->Render();
			if (Pattern == 2)
			{
				num2->Update();
			}
		}	
		if (BossEffectcount == 10)
		{
			e10->Render();
			num13->Update(e10->GetPosition() + Vector3(15, -3, 0), Vector3(10, 10, 0));
			num13->Render();
			num16->Update(e10->GetPosition() + Vector3(25, -3, 0), Vector3(10, 10, 0));
			num16->Render();
		}
		hand->Render();
	}

	if (Mapcount == 19)
	{
		if (PatternStart == 0)
		{
			random_device rand;
			uniform_int_distribution<int> intRand(0, 2);

			Value = intRand(rand);
			PatternStart++;
		}
	
		RBoss->Render();
		LBoss->Render();
		u11->Render();
		u12->Render();
		u13->Render();

		if (Value == 0)
		{
			e5->Update(Vector3(850, 250, 0) + Vector3(0, 40, 0));
			num6->Update(e5->GetPosition() + Vector3(15, -3, 0), Vector3(10, 10, 0));
			e5->Render();
			num6->Render();

			e5->Update(Vector3(1050, 250, 0) + Vector3(0, 40, 0));
			num16->Update(e5->GetPosition() + Vector3(15, -3, 0), Vector3(10, 10, 0));
			e5->Render();
			num16->Render();
		}
		else if (Value == 1)
		{
			e5->Update(Vector3(850, 250, 0) + Vector3(0, 40, 0));
			num16->Update(e5->GetPosition() + Vector3(15, -3, 0), Vector3(10, 10, 0));
			e5->Render();
			num16->Render();

			e8->Update(Vector3(1050, 250, 0) + Vector3(0, 40, 0));
			num4->Update(e8->GetPosition() + Vector3(15, -3, 0), Vector3(10, 10, 0));
			e8->Render();
			num4->Render();
		}
		else if (Value == 2)
		{
			e9->Update(Vector3(850, 250, 0) + Vector3(0, 40, 0));
			e9->Render();
			
			num3->Update(e9->GetPosition() + Vector3(15, -3, 0), Vector3(10, 10, 0));
			num3->Render();

			e9->Update(Vector3(1050, 250, 0) + Vector3(0, 40, 0));
			e9->Render();
			
			num13->Update(e9->GetPosition() + Vector3(15, -3, 0), Vector3(10, 10, 0));
			num13->Render();
		}
		
		hand->Render();
	}

	if (Mapcount == 20)
	{
		
	}

	if (PTurn)
	{
		Sounds::Get()->Pause("BackGround");
		PFight();
	}

	if (MTurn)
	{
		MFight();
	}

	if (BossBattle)
	{
		BossFight();
	}

	//Map
	//stage 1
	if (Mapcount == 1)
	{
		s3->Render();
		M1->Render();
		M2->Render();
		M3->Render();
		M4->Render();
		M5->Render();
		M6->Render();

		if (mpos6->IsMouseLClick())
		{
			Sounds::Get()->Play("SelectMap", 0.1f);
			Hcount++;
			Mapcount++;
			PTurn = true;
			Sounds::Get()->Play("fight", 0.1f);
			//Sounds::Get()->Play("PlayerTurn", 0.1f);

		}
	}

	if (Mapcount == 16)
	{
		s3->Render();
		M1->Render();
		M2->Render();
		M3->Render();
		M4->Render();
		M5->Render();
		M6->Render();
		M7->Render();
		M11->Render();
		M10->Render();
		M9->Render();
		M12->Render();
		if (mpos7->IsMouseLClick())
		{
			Sounds::Get()->Play("SelectMap", 0.1f);
			Sounds::Get()->Play("BossBgm", 0.1f);
			Mapcount++;
			PTurn = true;
			//Sounds::Get()->Play("PlayerTurn", 0.1f);
		}
	}

	//intro
	if (Hcount == 0)
	{
		n1->Render();
		if (mpos5->IsOnMouseCursor())
		{
			u14->Render();
		}
		else if (mpos5->IsOnMouseCursor() == false)
		{
			u15->Render();
		}
		if (mpos5->IsMouseLClick())
		{
			Sounds::Get()->Play("MapOpen", 0.1f);
			Hp = player->GetMaxhp() + 7;
			player->SetMaxhp(Hp);
			player->SetHp(Hp);
			Mapcount++;
			Hcount++;
			Rcount++;
		}
	}

	//Stage 1.5
	if (monster->GetHp() <= 0 && 2 <= Mapcount < 3)
	{
		if (Mapcount == 2)
		{
			s2->Render();
			M13->Render();
			if (mpos14->IsOnMouseCursor())
			{
				sb2->Render();
			}
			else if (mpos14->IsOnMouseCursor() == false)
			{
				sb1->Render();
			}
			if (mpos14->IsMouseLClick())
			{
				Sounds::Get()->Play("GetGold", 0.1f);
				player->SetGold(player->GetGold() + 13);
				Hp = player->GetGold();
				cout << Hp << endl;
				Mapcount++;
			}
			if (mpos12->IsMouseLClick())
			{
				hand->SetState();
				hand->SetCcount(2);
				hand->RodeHand();
				Sounds::Get()->Play("MapOpen", 0.1f);
				Mapcount += 2;
			}
		}
		if (Mapcount == 3)
		{
			s2->Render();
			M13->Render();
			if (mpos12->IsMouseLClick())
			{
				hand->SetState();
				hand->SetCcount(2);
				hand->RodeHand();
				//hand->Update();
				Sounds::Get()->Play("MapOpen", 0.1f);
				Mapcount++;
			}
		}
	}

	//stage 2
	if (Mapcount == 4)
	{
		M1->Update(Vector3(500, 150, 0), Vector3(100, 100, 0));
		s3->Render();
		M1->Render();
		M2->Render();
		M3->Render();
		M4->Render();
		M5->Render();
		M6->Render();
		M7->Render();

		if (mpos10->IsMouseLClick())
		{
			Sounds::Get()->Play("SelectMap", 0.1f);
			Mapcount++;
			M5->Update(Vector3(600, 250, 0), Vector3(100, 100, 0));
		}
	}

	if (Mapcount == 5)
	{
		M14->Render();
		if (mpos13->IsMouseLClick())
		{
			Sounds::Get()->Play("BoxOpen", 0.1f);
			Mapcount++;
		}
	}

	if (Mapcount == 6)
	{
		M15->Render();
		s2->Render();
		if (mpos15->IsOnMouseCursor())
		{
			sb4->Render();
		}
		else if (mpos15->IsOnMouseCursor() == false)
		{
			sb3->Render();
		}
		if (mpos15->IsMouseLClick())
		{
			Rcount++;
			Mapcount++;
		}
	}

	if (Mapcount == 7)
	{
		s2->Render();
		M15->Render();
		M13->Render();
		if (mpos12->IsMouseLClick())
		{
			Sounds::Get()->Play("MapOpen", 0.1f);
			Mapcount++;
		}
	}

	if (Mapcount == 8)
	{
		s3->Render();
		M1->Render();
		M2->Render();
		M3->Render();
		M4->Render();
		M5->Render();
		M6->Render();
		M7->Render();
		M11->Render();
		if (mpos9->IsMouseLClick())
		{
			Sounds::Get()->Play("SelectMap", 0.1f);
			Mapcount++;
			Sounds::Get()->Pause("BackGround");
			Sounds::Get()->Play("ShopBgm", 0.1f);
			M4->Update(Vector3(650, 350, 0), Vector3(100, 100, 0));
		}
	}

	if (Mapcount == 9)
	{
		n2->Render();
		M13->Render();
		if (mpos16->IsMouseLClick())
		{
			Sounds::Get()->Play("ShopOpen", 0.1f);
			ShopLook = true;
			Mapcount++;
		}
		if (mpos12->IsMouseLClick())
		{
			Sounds::Get()->Play("MapOpen", 0.1f);
			Sounds::Get()->Pause("ShopBgm");
			Sounds::Get()->Play("BackGround", 0.1f);
			Mapcount += 2;
		}
	}

	if (Mapcount == 10)
	{
		s4->Render();
		if (mpos17->IsOnMouseCursor())
		{
			M16->Update(Vector3(170, 200, 0), Vector3(250, 150, 0));
		}
		else if (mpos17->IsOnMouseCursor() == false)
		{
			M16->Update(Vector3(170, 200, 0), Vector3(200, 100, 0));
		}
		M16->Render();

		if (mpos17->IsMouseLClick())
		{
			ShopLook = false;
			Sounds::Get()->Play("ShopClose", 0.1f);
			Mapcount--;
		}
	}

	if (Mapcount == 11)
	{
		s3->Render();
		M1->Render();
		M2->Render();
		M3->Render();
		M4->Render();
		M5->Render();
		M6->Render();
		M7->Render();
		M11->Render();
		M10->Render();
		if (mpos8->IsMouseLClick())
		{
			Sounds::Get()->Play("SelectMap", 0.1f);
			Mapcount++;
			M3->Update(Vector3(550, 450, 0), Vector3(100, 100, 0));
		}
	}

	if (Mapcount == 12)
	{
		s5->Render();
		if (mpos18->IsOnMouseCursor())
		{
			eb2->Render();
		}
		else if (mpos18->IsOnMouseCursor() == false)
		{
			eb1->Render();
		}
		if (mpos18->IsMouseLClick())
		{
			Sounds::Get()->Play("MapOpen", 0.1f);
			player->SetHp(player->GetHp() + 23);
			if (player->GetHp() > player->GetMaxhp())
			{
				player->SetHp(player->GetMaxhp());
			}
			Mapcount++;
		}

		if (mpos19->IsOnMouseCursor())
		{
			eb4->Render();
		}
		else if (mpos19->IsOnMouseCursor() == false)
		{
			eb3->Render();
		}
		if (mpos19->IsMouseLClick())
		{
			Sounds::Get()->Play("MapOpen", 0.1f);
			player->SetMaxhp(player->GetMaxhp() + 5);
			Mapcount++;
		}

		if (mpos20->IsOnMouseCursor())
		{
			eb6->Render();
		}
		else if (mpos20->IsOnMouseCursor() == false)
		{
			eb5->Render();
		}
		if (mpos20->IsMouseLClick())
		{
			Sounds::Get()->Play("MapOpen", 0.1f);
			player->SetMaxhp(player->GetMaxhp() + 5);
			Mapcount++;
			Rcount++;
		}
	}

	if (Mapcount == 13)
	{
		s3->Render();
		M1->Render();
		M2->Render();
		M3->Render();
		M4->Render();
		M5->Render();
		M6->Render();
		M7->Render();
		M11->Render();
		M10->Render();
		M9->Render();
		if (mpos11->IsMouseLClick())
		{
			Sounds::Get()->Play("SelectMap", 0.1f);
			Sounds::Get()->Play("CampOn", 0.1f);
			Mapcount++;
			M6->Update(Vector3(700, 500, 0), Vector3(100, 100, 0));
		}
	}

	if (Mapcount == 14)
	{
		s6->Render();
		u16->Render();
		if (mpos21->IsMouseLClick())
		{
			Sounds::Get()->Pause("CampOn");
			Sounds::Get()->Play("CampOff", 0.1f);
			Mapcount++;
			u16->Update(Vector3(500, 500, 0), Vector3(250, 250, 0));
		}
	}

	if (Mapcount == 15)
	{
		s7->Render();
		u16->Render();
		M13->Render();
		if (mpos12->IsMouseLClick())
		{
			Sounds::Get()->Play("MapOpen", 0.1f);
			Mapcount++;
		}
	}

	if (Rcount > 0)
	{
		Relic1->Render();
		if (Rcount == 2)
		{
			Relic2->Render();
		}
		if (Rcount == 3)
		{
			Relic3->Render();
		}
	}

	u1->Render();
	u2->Render();
	u3->Render();
	u4->Render();
	u5->Render();
	u6->Render();
	u7->Render();
	if (ShopLook)
	{
		M17->Render();
	}
	else
	{
		u8->Render();
	}
	hud->Render();
}


void TestDemo::PostRender()
{
}

void TestDemo::GUI()
{
}

void TestDemo::EffectStart()
{
	if (Estart && monster->GetHp() > 0)
	{
		if (DmgEstart1 && Effectcount <= 0)
		{
			num6->Update(Vector3(950, 250, 0) + Vector3(0, 50 + Ecount, 0));
			num6->Render();
		}
		else if (DmgEstart1 && Effectcount > 0)
		{
			num9->Update(Vector3(950, 250, 0) + Vector3(0, 50 + Ecount, 0));
			num9->Render();
		}

		if (DmgEstart2 && Effectcount > 0)
		{
			if (Debuff == 0)
			{
				num8->Update(Vector3(950, 250, 0) + Vector3(0, 50 + Ecount, 0));
				num8->Render();
			}
			if (Debuff > 0)
			{
				num1->Update(Vector3(950, 250, 0) + Vector3(-20, 50 + Ecount, 0));
				num1->Render();
				num2->Update(Vector3(950, 250, 0) + Vector3(10, 50 + Ecount, 0));
				num2->Render();
			}
		}

		e1->Render();
		if (1 < Ecount && Ecount < 20)
		{
			player->Update(Vector3(350 + (1 * Ecount / 2), 250, 0));
			monster->Update(Vector3(950 + (1 * Ecount / 2), 250, 0));
			e5->Update(monster->GetPosition() + Vector3(0, 10, 0));
			num16->Update(e5->GetPosition() + Vector3(15, -3, 0), Vector3(10, 10, 0));
		}
		else if (Ecount > 20 && Ecount < 40)
		{
			player->Update(Vector3(350 + (1 * Ecount / 2), 250, 0));
			monster->Update(Vector3(950 - (1 * Ecount / 2), 250, 0));
			e5->Update(monster->GetPosition() + Vector3(0, 10, 0));
			num16->Update(e5->GetPosition() + Vector3(15, -3, 0), Vector3(10, 10, 0));

		}
		Ecount++;

		if (Ecount > 40)
		{
			player->Update(Vector3(300, 250, 0));
			monster->Update(Vector3(950, 250, 0));
			e5->Update(monster->GetPosition() + Vector3(0, 10, 0));
			num16->Update(e5->GetPosition() + Vector3(15, -3, 0), Vector3(10, 10, 0));
		}
		if (Ecount > 60)
		{
			Estart = false;
			DmgEstart1 = false;
			DmgEstart2 = false;
			Ecount = 0;
		}
	}

	if (Estart && Boss->GetHp() > 0)
	{
		if (Rcount == 2)
		{
			if (DmgEstart1 && Effectcount <= 0)
			{
				num8->Update(Vector3(950, 350, 0) + Vector3(0, 50 + Ecount, 0));
				num8->Render();
			}
			else if (DmgEstart1 && Effectcount > 0)
			{
				num1->Update(Vector3(950, 350, 0) + Vector3(-20, 50 + Ecount, 0));
				num1->Render();
				num11->Update(Vector3(950, 350, 0) + Vector3(10, 50 + Ecount, 0));
				num11->Render();
			}

			if (DmgEstart2 && Effectcount > 0)
			{
				if (Debuff == 0)
				{
					num1->Update(Vector3(950, 350, 0) + Vector3(-20, 50 + Ecount, 0));
					num1->Render();
					num0->Update(Vector3(950, 350, 0) + Vector3(10, 50 + Ecount, 0));
					num0->Render();
				}
				if (Debuff > 0)
				{
					num1->Update(Vector3(950, 350, 0) + Vector3(-20, 50 + Ecount, 0));
					num1->Render();
					num4->Update(Vector3(950, 350, 0) + Vector3(10, 50 + Ecount, 0));
					num4->Render();
				}
			}
		}
		else if (Rcount != 2)
		{
			if (DmgEstart1 && Effectcount <= 0)
			{
				num6->Update(Vector3(950, 350, 0) + Vector3(0, 50 + Ecount, 0));
				num6->Render();
			}
			else if (DmgEstart1 && Effectcount > 0)
			{
				num9->Update(Vector3(950, 350, 0) + Vector3(0, 50 + Ecount, 0));
				num9->Render();
			}

			if (DmgEstart2 && Effectcount > 0)
			{
				if (Debuff == 0)
				{
					num8->Update(Vector3(950, 350, 0) + Vector3(0, 50 + Ecount, 0));
					num8->Render();
				}
				
				if (Debuff > 0)
				{
					num1->Update(Vector3(950, 350, 0) + Vector3(-20, 50 + Ecount, 0));
					num1->Render();
					num2->Update(Vector3(950, 350, 0) + Vector3(10, 50 + Ecount, 0));
					num2->Render();
				}
			}
		}

		e1->Render();
		if (1 < Ecount && Ecount < 20)
		{
			player->Update(Vector3(350 + (1 * Ecount / 2), 250, 0));
			Boss->Update(Vector3(950 + (1 * Ecount / 2), 350, 0));
			//e5->Update(Boss->GetPosition() + Vector3(0, 10, 0));
		}
		else if (Ecount > 20 && Ecount < 40)
		{
			player->Update(Vector3(350 + (1 * Ecount / 2), 250, 0));
			Boss->Update(Vector3(950 - (1 * Ecount / 2), 350, 0));
			//e5->Update(Boss->GetPosition() + Vector3(0, 10, 0));
		}
		Ecount++;

		if (Ecount > 40)
		{
			player->Update(Vector3(300, 250, 0));
			Boss->Update(Vector3(950, 350, 0));
			//e5->Update(Boss->GetPosition() + Vector3(0, 10, 0));
		}
		if (Ecount > 60)
		{
			Estart = false;
			DmgEstart1 = false;
			DmgEstart2 = false;
			Ecount = 0;
		}
	}
}

void TestDemo::EffectStart2()
{
	if (Estart2 == true)
	{
		e2->Update(player->GetPosition());
		e2->Render();
		Ecount2++;
	}
	if (Ecount2 > 50)
	{
		Estart2 = false;
		Ecount2 = 0;
	}
}

void TestDemo::EffectStart3()
{
	if (Estart3 == true)
	{
		if (Ecount3 < 20)
		{
			player->Update(Vector3(350 + (1 * Ecount3), 250, 0));
			num6->Update(Vector3(350, 250, 0) + Vector3(0, 50 + Ecount3, 0));
			num6->Render();
			e3->Update(player->GetPosition() + Vector3(10, 0, 0));
			e3->Render();
		}
		else if (Ecount3 < 50)
		{
			player->Update(Vector3(350 - (1 * Ecount3 / 2), 250, 0));
			num6->Update(Vector3(350, 250, 0) + Vector3(0, 50 + Ecount3, 0));
			num6->Render();
			e3->Update(player->GetPosition() + Vector3(10, 0, 0));
			e3->Render();
		}
		monster->Update(Vector3(950 - (1 * Ecount3), 250, 0));
		Ecount3++;
	}
	if (Ecount3 >= 50)
	{
		player->Update(Vector3(300, 250, 0));
		monster->Update(Vector3(950, 250, 0));
		Estart3 = false;
		Ecount3 = 0;
		hand->RodeHand();
	}
}

void TestDemo::EffectStart4()
{
	if (DmgEstart3)
	{
		num3->Update(Vector3(350, 250, 0) + Vector3(-20, 50 + Ecount4, 0));
		num3->Render();
		num6->Update(Vector3(350, 250, 0) + Vector3(10, 50 + Ecount4, 0));
		num6->Render();
	}
	if (Estart4)
	{
		if (Ecount4 < 20)
		{
			if (Ecount4 < 10)
			{
				s1->Update(Vector3(650, 200 + (1 * Ecount4 / 2), 0));
			}
			else
			{
				s1->Update(Vector3(650, 200 - (1 * Ecount4 / 2), 0));
			}
			player->Update(Vector3(350 + (1 * Ecount4), 250, 0));
			e11->Update(player->GetPosition() + Vector3(10, 0, 0));
			e11->Render();
		}
		else if (Ecount4 < 50)
		{
			if (Ecount4 < 30)
			{
				s1->Update(Vector3(650 - (1 * Ecount4 / 2), 200, 0));
			}
			else
			{
				s1->Update(Vector3(650 + (1 * Ecount4 / 2), 200, 0));
			}
			player->Update(Vector3(350 - (1 * Ecount4 / 2), 250, 0));
			e11->Update(player->GetPosition() + Vector3(10, 0, 0));
			e11->Render();
		}
		Boss->Update(Vector3(950 - (1 * Ecount4), 350, 0));
		Ecount4++;
	}

	if (Ecount4 >= 50)
	{
		player->Update(Vector3(300, 250, 0));
		Boss->Update(Vector3(950, 350, 0));
		s1->Update(Vector3(650, 200, 0));
	}
	if (Ecount4 > 60)
	{
		PTurn = true;
		//Sounds::Get()->Play("PlayerTurn", 0.1f);
		BossBattle = false;
		Ecount4 = 0;
		Estart4 = false;
		DmgEstart3 = false;
	}

	if (Estart5)
	{
		if (Ecount5 < 20)
		{
			Boss->Update(Vector3(950 + (1 * Ecount5 / 2), 350, 0));
		
			if (Pattern == 1)
			{
				num2->Update(Vector3(950, 350, 0) + Vector3(0, 50 + Ecount5, 0));
				num2->Render();
			}
			else if (Pattern == 0)
			{
				num1->Update(Vector3(950, 350, 0) + Vector3(0, 50 + Ecount5, 0));
				num1->Render();
			}
			
		}
		else if (Ecount5 < 40)
		{
			Boss->Update(Vector3(950 - (1 * Ecount5 / 2), 350, 0));
		
			if (Pattern == 1)
			{
				num2->Update(Vector3(950, 350, 0) + Vector3(0, 50 + Ecount5, 0));
				num2->Render();
			}
			else if (Pattern == 0)
			{
				num1->Update(Vector3(950, 350, 0) + Vector3(0, 50 + Ecount5, 0));
				num1->Render();
			}
		}
		Ecount5++;

		if (Ecount5 > 60)
		{
			Boss->Update(Vector3(950, 350, 0));
			Ecount5 = 0;
			Estart5 = false;
			PTurn = true;
			BossBattle = false;
		}
	}
}

void TestDemo::BossPage2()
{
	if (BossPagestart)
	{
		if (BossPagecount < 10)
		{
			Boss->Update(Vector3(950, 350, 0) - Vector3(5 + BossPagecount, 0, 0));
			LBoss->Update(Vector3(950, 250, 0));
			RBoss->Update(Vector3(950, 250, 0));
		}
		else if(BossPagecount < 20)
		{
			Boss->Update(Vector3(950, 350, 0) + Vector3(5 + BossPagecount, 0, 0));
			LBoss->Update(Vector3(950, 250, 0) - Vector3(2 * BossPagecount, 0, 0));
			RBoss->Update(Vector3(950, 250, 0) + Vector3(2 * BossPagecount, 0, 0));
		}
		else if (BossPagecount < 30)
		{
			Boss->Update(Vector3(950, 350, 0) - Vector3(5 + BossPagecount, 0, 0));
			LBoss->Update(Vector3(950, 250, 0) - Vector3(2 * BossPagecount, 0, 0));
			RBoss->Update(Vector3(950, 250, 0) + Vector3(2 * BossPagecount, 0, 0));
		}
		else if (BossPagecount < 40)
		{
			Boss->Update(Vector3(950, 350, 0) + Vector3(5 + BossPagecount, 0, 0));
			LBoss->Update(Vector3(950, 250, 0) - Vector3(2 * BossPagecount, 0, 0));
			RBoss->Update(Vector3(950, 250, 0) + Vector3(2 * BossPagecount, 0, 0));
		}
		else if (BossPagecount < 50)
		{
			Boss->Update(Vector3(950, 350, 0) - Vector3(5 + BossPagecount, 0, 0));
			LBoss->Update(Vector3(950, 250, 0) - Vector3(2 * BossPagecount, 0, 0));
			RBoss->Update(Vector3(950, 250, 0) + Vector3(2 * BossPagecount, 0, 0));
		}
		BossPagecount++;

		if (BossPagecount == 50)
		{
			LBoss->Update(Vector3(850, 250, 0));
			RBoss->Update(Vector3(1050, 250, 0));
			Boss->Update(Vector3(950, 350, 0));
			BossPagecount = 0;
			BossPagestart = false;
			PTurn = true;
			BossBattle = false;
		}
	}
}

void TestDemo::BossFight2()
{
	if (Estart6)
	{
		if (Ecount6 < 40)
		{
			LBoss->Update(Vector3(850 + 2 * Ecount6, 250, 0));
			RBoss->Update(Vector3(1050, 250, 0));
			if (Ecount6 < 20)
			{
				player->Update(Vector3(350 - 2 * Ecount6, 250, 0));
			}
			else
			{
				player->Update(Vector3(350 + 2 * Ecount6, 250, 0));
			}
		}
		else if (Ecount6 < 80)
		{
			LBoss->Update(Vector3(850, 250, 0));
			RBoss->Update(Vector3(1050 + Ecount6, 250, 0));
			if (Ecount6 < 60)
			{
				player->Update(Vector3(350 - Ecount6, 250, 0));
			}
			else
			{
				player->Update(Vector3(350 + Ecount6, 250, 0));
			}
		}
		Ecount6++;

		if (Ecount6 > 80)
		{
			player->Update(Vector3(350, 250, 0));
			LBoss->Update(Vector3(850, 250, 0));
			RBoss->Update(Vector3(1050, 250, 0));
			Estart6 = false;
			Ecount6 = 0;
			PatternStart = 0;
			PTurn = true;
			BossBattle = false;
		}
	}

	if (Estart7)
	{
		if (Ecount7 < 40)
		{
			LBoss->Update(Vector3(850 + 2 * Ecount7, 250, 0));
			RBoss->Update(Vector3(1050, 250, 0));
			if (Ecount6 < 20)
			{
				player->Update(Vector3(350 - 2 * Ecount7, 250, 0));
			}
			else
			{
				player->Update(Vector3(350 + 2 * Ecount7, 250, 0));
			}
		}
		else if (Ecount7 < 60)
		{
			LBoss->Update(Vector3(850, 250, 0));
			LBoss->Update(Vector3(850, 250, 0));
			e2->Render();
		}
		else if (Ecount7 < 80)
		{
			RBoss->Update(Vector3(1050, 250, 0));
			e2->Update(Vector3(1050, 250, 0));
			e2->Render();
		}
		Ecount7++;

		if (Ecount7 > 80)
		{
			player->Update(Vector3(350, 250, 0));
			LBoss->Update(Vector3(850, 250, 0));
			RBoss->Update(Vector3(1050, 250, 0));
			Estart7 = false;
			Estart7 = 0;
			PatternStart = 0;
			PTurn = true;
			BossBattle = false;
		}
	}

	if (Estart8)
	{
		if (Ecount8 < 40)
		{
			LBoss->Update(Vector3(850 + 2 * Ecount8, 250, 0));
			e2->Update(Vector3(850 + 2 * Ecount8, 250, 0));
			e2->Render();
			RBoss->Update(Vector3(1050, 250, 0));
			if (Ecount8 < 20)
			{
				player->Update(Vector3(350 - 2 * Ecount8, 250, 0));
			}
			else
			{
				player->Update(Vector3(350 + 2 * Ecount8, 250, 0));
			}
		}
		else if (Ecount8 < 80)
		{
			LBoss->Update(Vector3(850, 250, 0));
			RBoss->Update(Vector3(1050 + Ecount8, 250, 0));
			e2->Update(Vector3(1050 * Ecount8, 250, 0));
			e2->Render();
			if (Ecount8 < 60)
			{
				player->Update(Vector3(350 - Ecount8, 250, 0));
			}
			else
			{
				player->Update(Vector3(350 + Ecount8, 250, 0));
			}
		}
		Ecount8++;

		if (Ecount8 > 80)
		{
			player->Update(Vector3(350, 250, 0));
			LBoss->Update(Vector3(850, 250, 0));
			RBoss->Update(Vector3(1050, 250, 0));
			Estart8 = false;
			Estart8 = 0;
			PatternStart = 0;
			PTurn = true;
			BossBattle = false;
		}
	}
}

void TestDemo::PFight()
{
	if (PTurn)
	{
		if (Rcount == 2)
		{
			e7->Render();
			num12->Update(e7->GetPosition() + Vector3(15, -5, 0), Vector3(10, 10, 0));
			num12->Render();
		}
		if (Rcount == 3)
		{
			e8->Render();
			num12->Update(e8->GetPosition() + Vector3(15, -5, 0), Vector3(10, 10, 0));
			num12->Render();
		}

		MTurn = false;
		BossBattle = false;
		u9->Render();
		if (mpos2->IsMouseLClick())
		{
			if (monster->GetHp() > 0)
			{
				Sounds::Get()->Play("TurnEndBtn", 0.1f);
				//Sounds::Get()->Play("EnemyTurn", 0.1f);
				PTurn = false;
				MTurn = true;
				hand->SetState();
				player->Setcost(3);
				if (Effectcount > 0)
				{
					Debuff --;
					Effectcount--;
				}
			}
			if (Boss->GetHp() > 0)
			{
				Sounds::Get()->Play("TurnEndBtn", 0.1f);
				//Sounds::Get()->Play("EnemyTurn", 0.1f);
				PTurn = false;
				BossBattle = true;
				hand->SetState();
				player->Setcost(3);
				if (Effectcount > 0)
				{
					Debuff --;
					Effectcount--;
				}
			}
		}

		if (monster->GetHp() > 0)
		{
			e5->Render();
			num16->Render();
			if (hand->GetCost() <= player->Getcost())
			{
				if (hand->GetDamege() >= 0 && hand->GetDefence() >= 0)
				{
					Sounds::Get()->Play("CardUse", 0.1f);
					Ccount = player->Getcost() - hand->GetCost();
					player->Setcost(Ccount);
					cout << Ccount << endl;

					if (hand->GetType() == 0)
					{
						if (Effectcount <= 0)
						{
							Hp = monster->GetHp() - player->GetDamege();
							monster->SetHp(Hp);
							Hp = monster->GetHp();
							cout << "monster hp : " << Hp << endl;
							Estart = true;
							Hp = player->GetDamege();
							cout << "player dmg : " << Hp << endl;
						}
						else if (Effectcount > 0)
						{
							Hp = monster->GetHp() - (player->GetDamege() + hand->GetDamege() / 2);
							monster->SetHp(Hp);
							Hp = monster->GetHp();
							cout << "monster hp : " << Hp << endl;
							Estart = true;
							Hp = player->GetDamege() + hand->GetDamege() / 2;
							cout << "player dmg : " << Hp << endl;
						}

						if (hand->GetDamege() == 6)
						{
							Sounds::Get()->Play("PlayerAtk2", 0.1f);
							DmgEstart1 = true;
							cout << "Effectcount" << Effectcount << endl;
						}
						else if (hand->GetDamege() == 8)
						{
							Sounds::Get()->Play("PlayerAtk1", 0.1f);
							DmgEstart2 = true;
							if (Effectcount > 0)
							{
								Debuff += 2;
							}
							else if (Effectcount <= 0)
							{
								Debuff = 0;
							}
							Effectcount += 2;
							cout << "Effectcount" << Effectcount << endl;
						}
					}
					else if (hand->GetType() == 1)
					{
						if (Rcount == 3)
						{
							Sounds::Get()->Play("DefSet", 0.1f);
							if (Dcount == 0)
							{
								def = (player->GetDefence() + 2);
								result = def;
								Estart2 = true;
								Dcount++;
							}
							else
							{
								result = def + (player->GetDefence() + 2);
								Estart2 = true;
							}
						}
						if (Rcount != 3)
						{
							Sounds::Get()->Play("DefSet", 0.1f);
							if (Dcount == 0)
							{
								def = player->GetDefence();
								result = def;
								Estart2 = true;
								Dcount++;
							}
							else
							{
								result = def + player->GetDefence();
								Estart2 = true;
							}
						}
					}
				}
			}
		}

		//Boss Battle
		if (Boss->GetHp() > 0)
		{
			if (hand->GetCost() <= player->Getcost())
			{
				if (hand->GetDamege() >= 0 && hand->GetDefence() >= 0)
				{
					Sounds::Get()->Play("CardUse", 0.1f);
					Ccount = player->Getcost() - hand->GetCost();
					player->Setcost(Ccount);
					cout << Ccount << endl;

					if (hand->GetType() == 0)
					{
						if (BossDcount <= 0)
						{
							if (Effectcount <= 0)
							{
								Sounds::Get()->Play("Boss_Hpdown", 0.1f);
								Hp = Boss->GetHp() - player->GetDamege();
								Boss->SetHp(Hp);
								Hp = Boss->GetHp();
								Estart = true;
								cout << "Boss hp : " << Hp << endl;
								Hp = player->GetDamege();
								cout << "player dmg : " << Hp << endl;
							}
							else if (Effectcount > 0)
							{
								Sounds::Get()->Play("Boss_Hpdown", 0.1f);
								Hp = Boss->GetHp() - (player->GetDamege() + hand->GetDamege() / 2);
								Boss->SetHp(Hp);
								Hp = Boss->GetHp();
								Estart = true;
								cout << "Boss hp : " << Hp << endl;
								Hp = player->GetDamege() + hand->GetDamege() / 2;
								cout << "player dmg : " << Hp << endl;
							}

							if (hand->GetDamege() == 6)
							{
								Sounds::Get()->Play("PlayerAtk2", 0.1f);
								DmgEstart1 = true;
								cout << "Effectcount" << Effectcount << endl;
							}
							else if (hand->GetDamege() == 8)
							{
								Sounds::Get()->Play("PlayerAtk1", 0.1f);
								DmgEstart2 = true;
								if (Effectcount > 0)
								{
									Debuff += 2;
								}
								else if (Effectcount <= 0)
								{
									Debuff = 0;
								}
								Effectcount += 2;
								cout << "Effectcount" << Effectcount << endl;
							}
						}
						else if (BossDcount > 0)
						{
							if (Effectcount <= 0)
							{
								Sounds::Get()->Play("Boss_Hpdown", 0.1f);
								Hp = Boss->GetHp() + BossDcount - player->GetDamege();
								Boss->SetHp(Hp);
								Hp = Boss->GetHp();
								Estart = true;
								cout << "Boss hp : " << Hp << endl;
								Hp = player->GetDamege();
								cout << "player dmg : " << Hp << endl;
							}
							else if (Effectcount > 0)
							{
								Sounds::Get()->Play("Boss_Hpdown", 0.1f);
								Hp = Boss->GetHp() + BossDcount - (player->GetDamege() + hand->GetDamege() / 2);
								Boss->SetHp(Hp);
								Hp = Boss->GetHp();
								Estart = true;
								cout << "Boss hp : " << Hp << endl;
								Hp = player->GetDamege() + hand->GetDamege() / 2;
								cout << "player dmg : " << Hp << endl;
							}

							if (hand->GetDamege() == 6)
							{
								Sounds::Get()->Play("PlayerAtk2", 0.1f);
								DmgEstart1 = true;
								cout << "Effectcount" << Effectcount << endl;
							}
							else if (hand->GetDamege() == 8)
							{
								Sounds::Get()->Play("PlayerAtk1", 0.1f);
								DmgEstart2 = true;
								if (Effectcount > 0)
								{
									Debuff += 2;
								}
								else if (Effectcount <= 0)
								{
									Debuff = 0;
								}
								Effectcount += 2;
								cout << "Effectcount" << Effectcount << endl;
							}
						}
					}
					else if (hand->GetType() == 1)
					{
						Sounds::Get()->Play("DefSet", 0.1f);
						if (Dcount == 0)
						{
							def = player->GetDefence();
							result = def;
							Estart2 = true;
							Dcount++;
						}
						else
						{
							result = def + player->GetDefence();
							Estart2 = true;
						}
					}
				}
			}
		}
	
		if (Mapcount < 4)
		{
			if (monster->GetHp() <= 0)
			{
				Sounds::Get()->Resume("BackGround");
				Acount = 0;
				Effectcount = 0;
				Debuff = 0;
				Estart = false;
				player->Setcost(3);
				PTurn = false;
				MTurn = false;
			}
		}
		else
		{
			if (Boss->GetHp() <= 0)
			{
				Sounds::Get()->Play("BossVictory", 0.1f);
				Sounds::Get()->Pause("BossBgm");
				Acount = 0;
				PTurn = false;
				BossBattle = false;
				Mapcount++;
				//MTurn = false;
			}
		}
	}

	EffectStart();
	EffectStart2();
}

void TestDemo::MFight()
{
	EffectStart3();
	if (Rcount == 2)
	{
		e7->Render();
		num12->Update(e7->GetPosition() + Vector3(15, -5, 0), Vector3(10, 10, 0));
		num12->Render();
	}
	if (Rcount == 3)
	{
		e8->Render();
		num12->Update(e8->GetPosition() + Vector3(15, -5, 0), Vector3(10, 10, 0));
		num12->Render();
	}
	if (MTurn)
	{
		u10->Render();
		if (mAttack == 0)
		{
			if (Dcount == 0)
			{
				Sounds::Get()->Play("EnemyAtk", 0.1f);
				Hp = player->GetHp() - monster->GetDamege();
				player->SetHp(Hp);
				Estart3 = true;
			}
			if (Dcount > 0)
			{
				player->SetDefence(result);
				Hp = player->GetDefence() - monster->GetDamege();
				if (Hp >= 0)
				{
					Sounds::Get()->Play("EnemyAtk", 0.1f);
					Sounds::Get()->Play("MonsterAttackDefence", 0.1f);
					player->SetDefence(Hp);
					Estart3 = true;
				}
				else
				{
					Sounds::Get()->Play("EnemyAtk", 0.1f);
					Sounds::Get()->Play("BreakDefence", 0.1f);
					player->SetDefence(0);
					result = player->GetHp() + Hp;
					player->SetHp(result);
					Estart3 = true;
					cout << result << endl;
				}
			}
		}
		mAttack++;
	}
		
	if (Estart3 == false)
	{
		mAttack = 0;
		player->SetDefence(0);
		Dcount = 0;
		PTurn = true;
		//Sounds::Get()->Play("PlayerTurn", 0.1f);
	}
}

void TestDemo::BossFight()
{	
	//start
	if (BossBattle)
	{
		if (Boss->GetMaxhp() / 2 > Boss->GetHp() && Mapcount == 18)
		{
			Value = 3;
		}
		if (Rcount == 2)
		{
			e7->Render();
			num12->Update(e7->GetPosition() + Vector3(15, -5, 0), Vector3(10, 10, 0));
			num12->Render();
		}
		if (Rcount == 3)
		{
			e8->Render();
			num12->Update(e8->GetPosition() + Vector3(15, -5, 0), Vector3(10, 10, 0));
			num12->Render();
		}
		if (mAttack == 0)
		{
			if (Boss->GetMaxhp() / 2 < Boss->GetHp())
			{
				if (Mapcount == 17)
				{
					Mapcount++;
					Value = 0;
				}
				if (Pattern > 0)
				{
					Value = 0;
					if (Pattern == 1)
					{
						Sounds::Get()->Play("BossOn", 0.1f);
					}
				}
				if (Pattern == 0)
				{
					Value = 1;
				}
				cout << "Value : " << Value << endl;
			}
			
			switch (Value)
			{
				case 0:
				{
					if (Boss->GetMaxhp() / 2 < Boss->GetHp())
					{
						hand->RodeHand();
						BossEffectcount = 6;
						Pattern--;
						Estart5 = true;
						if (Pattern == 0)
						{
							Boss->SetDamege(36);
							BossEffectcount = 10;
						}
						if (Pattern < 0)
						{
							Pattern = 1;
						}
						break;
					}
					else if(Boss->GetMaxhp() / 2 > Boss->GetHp())
					{
						Estart6 = true;
						if (Ecount6 == 5)
						{
							if (Dcount == 0)
							{
								Sounds::Get()->Play("BossAtk", 0.1f);
								Hp = player->GetHp() - 6;
								player->SetHp(Hp);
								cout << "player HP :" << Hp << endl;
							}

							if (Dcount > 0)
							{
								player->SetDefence(result);
								Hp = player->GetDefence() - 6;
								if (Hp >= 0)
								{
									Sounds::Get()->Play("BossAtk", 0.1f);
									Sounds::Get()->Play("MonsterAttackDefence", 0.1f);
									player->SetDefence(Hp);
								}
								else
								{
									Sounds::Get()->Play("BossAtk", 0.1f);
									Sounds::Get()->Play("BreakDefence", 0.1f);
									player->SetDefence(0);
									result = player->GetHp() + Hp;
									player->SetHp(result);
									cout << "player HP :" << result << endl;
								}
							}
						}
						else if (Ecount6 == 25)
						{
							if (Dcount == 0)
							{
								Sounds::Get()->Play("BossAtk", 0.1f);
								Hp = player->GetHp() - 6;
								player->SetHp(Hp);
								cout << "player HP :" << Hp << endl;
							}

							if (Dcount > 0)
							{
								player->SetDefence(result);
								Hp = player->GetDefence() - 6;
								if (Hp >= 0)
								{
									Sounds::Get()->Play("BossAtk", 0.1f);
									Sounds::Get()->Play("MonsterAttackDefence", 0.1f);
									player->SetDefence(Hp);
								}
								else
								{
									Sounds::Get()->Play("BossAtk", 0.1f);
									Sounds::Get()->Play("BreakDefence", 0.1f);
									player->SetDefence(0);
									result = player->GetHp() + Hp;
									player->SetHp(result);
									cout << "player HP :" << result << endl;
								}
							}
						}
						hand->RodeHand();
						break;
					}
				}
				case 1:
				{
					if (Boss->GetMaxhp() / 2 < Boss->GetHp())
					{
						Pattern--;
						Estart4 = true;
						DmgEstart3 = true;
						if (BossEffectcount == 10)
						{
							if (Dcount == 0)
							{
								Sounds::Get()->Play("BossAtk", 0.1f);
								Hp = player->GetHp() - Boss->GetDamege();
								player->SetHp(Hp);
								cout << "player HP :" << Hp << endl;
							}

							if (Dcount > 0)
							{
								player->SetDefence(result);
								Hp = player->GetDefence() - Boss->GetDamege();
								if (Hp >= 0)
								{
									Sounds::Get()->Play("BossAtk", 0.1f);
									Sounds::Get()->Play("MonsterAttackDefence", 0.1f);
									player->SetDefence(Hp);
								}
								else
								{
									Sounds::Get()->Play("BossAtk", 0.1f);
									Sounds::Get()->Play("BreakDefence", 0.1f);
									player->SetDefence(0);
									result = player->GetHp() + Hp;
									player->SetHp(result);
									cout << "player HP :" << result << endl;
								}
							}
						}
						BossEffectcount = 6;
						Value = 0;
						hand->RodeHand();
						break;
					}
					else if (Boss->GetMaxhp() / 2 > Boss->GetHp())
					{
						Estart7 = true;
						if (Ecount7 == 5)
						{
							if (Dcount == 0)
							{
								Sounds::Get()->Play("BossAtk", 0.1f);
								Hp = player->GetHp() - 6;
								player->SetHp(Hp);
								cout << "player HP :" << Hp << endl;
							}

							if (Dcount > 0)
							{
								player->SetDefence(result);
								Hp = player->GetDefence() - 6;
								if (Hp >= 0)
								{
									Sounds::Get()->Play("BossAtk", 0.1f);
									Sounds::Get()->Play("MonsterAttackDefence", 0.1f);
									player->SetDefence(Hp);
								}
								else
								{
									Sounds::Get()->Play("BossAtk", 0.1f);
									Sounds::Get()->Play("BreakDefence", 0.1f);
									player->SetDefence(0);
									result = player->GetHp() + Hp;
									player->SetHp(result);
									cout << "player HP :" << result << endl;
								}
							}
						}
						else if (Ecount7 == 25)
						{
							Sounds::Get()->Play("DefSet", 0.1f);
							BossDcount = 4;
						}
						else if (Ecount7 == 35)
						{
							Sounds::Get()->Play("DefSet", 0.1f);
							BossDcount = 4;
						}
						hand->RodeHand();
						break;
					}
				}
				case 2:
				{
					Estart8 = true;
					if (Ecount8 == 5)
					{
						if (Dcount == 0)
						{
							Sounds::Get()->Play("BossAtk", 0.1f);
							Hp = player->GetHp() - 3;
							player->SetHp(Hp);
							cout << "player HP :" << Hp << endl;
						}

						if (Dcount > 0)
						{
							player->SetDefence(result);
							Hp = player->GetDefence() - 3;
							if (Hp >= 0)
							{
								Sounds::Get()->Play("BossAtk", 0.1f);
								Sounds::Get()->Play("MonsterAttackDefence", 0.1f);
								player->SetDefence(Hp);
							}
							else
							{
								Sounds::Get()->Play("BossAtk", 0.1f);
								Sounds::Get()->Play("BreakDefence", 0.1f);
								player->SetDefence(0);
								result = player->GetHp() + Hp;
								player->SetHp(result);
								cout << "player HP :" << result << endl;
							}
						}
						Sounds::Get()->Play("DefSet", 0.1f);
						BossDcount = 3;
					}

					else if (Ecount8 == 25)
					{
						if (Dcount == 0)
						{
							Sounds::Get()->Play("BossAtk", 0.1f);
							Hp = player->GetHp() - 3;
							player->SetHp(Hp);
							cout << "player HP :" << Hp << endl;
						}

						if (Dcount > 0)
						{
							player->SetDefence(result);
							Hp = player->GetDefence() - 3;
							if (Hp >= 0)
							{
								Sounds::Get()->Play("BossAtk", 0.1f);
								Sounds::Get()->Play("MonsterAttackDefence", 0.1f);
								player->SetDefence(Hp);
							}
							else
							{
								Sounds::Get()->Play("BossAtk", 0.1f);
								Sounds::Get()->Play("BreakDefence", 0.1f);
								player->SetDefence(0);
								result = player->GetHp() + Hp;
								player->SetHp(result);
								cout << "player HP :" << result << endl;
							}
						}
						Sounds::Get()->Play("DefSet", 0.1f);
						BossDcount = 3;
					}
					hand->RodeHand();
					break;
				}
				case 3:
				{
					//Value = 2;
					BossPagestart = true;
					//BossEffectcount = 9;
					Mapcount++;
					hand->RodeHand();
					break;
				}
			}
		}
		mAttack++;
	}

	EffectStart4();
	BossPage2();
	BossFight2();
	if (Boss->GetMaxhp() / 2 < Boss->GetHp() && Mapcount == 18)
	{
		if (Estart4 == false && Estart5 == false && BossPagestart == false)
		{
			mAttack = 0;
			player->SetDefence(0);
			Dcount = 0;
			PTurn = true;
		}
	}
	else
	{
		if (Estart6 == false && Estart7 == false && Estart8 == false && BossPagestart == false)
		{
			PatternStart = 0;
			mAttack = 0;
			player->SetDefence(0);
			Dcount = 0;
			PTurn = true;
		}
	}
}

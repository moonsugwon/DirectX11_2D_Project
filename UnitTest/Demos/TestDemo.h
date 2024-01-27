#pragma once

class TestDemo : public IObject
{
public:
	virtual void Init() override;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;
	virtual void GUI() override;

	void EffectStart();
	void EffectStart2();
	void EffectStart3();
	void EffectStart4();

	void BossPage2();

	//void PMove();
	//void MMove();

	void PFight();
	void MFight();
	void BossFight();
	void BossFight2();

private:
	class character* player = nullptr;
	class character* monster = nullptr;
	class character* Boss = nullptr;
	class character* LBoss = nullptr;
	class character* RBoss = nullptr;

	class Hand* hand = nullptr;

	class TextureRect* s1 = nullptr;
	class TextureRect* s2 = nullptr;
	class TextureRect* s3 = nullptr;
	class TextureRect* s4 = nullptr;
	class TextureRect* s5 = nullptr;
	class TextureRect* s6 = nullptr;
	class TextureRect* s7 = nullptr;

	class TextureRect* n1 = nullptr;
	class TextureRect* n2 = nullptr;

	class TextureRect* u1 = nullptr;
	class TextureRect* u2 = nullptr;
	class TextureRect* u3 = nullptr;
	class TextureRect* u4 = nullptr;
	class TextureRect* u5 = nullptr;
	class TextureRect* u6 = nullptr;
	class TextureRect* u7 = nullptr;
	class TextureRect* u8 = nullptr;
	class TextureRect* u9 = nullptr;
	class TextureRect* u10 = nullptr;
	class TextureRect* u11 = nullptr;
	class TextureRect* u12 = nullptr;
	class TextureRect* u13 = nullptr;
	class TextureRect* u14 = nullptr;
	class TextureRect* u15 = nullptr;
	class TextureRect* u16 = nullptr;

	class TextureRect* M1 = nullptr;
	class TextureRect* M2 = nullptr;
	class TextureRect* M3 = nullptr;
	class TextureRect* M4 = nullptr;
	class TextureRect* M5 = nullptr;
	class TextureRect* M6 = nullptr;
					   
	class TextureRect* M7 = nullptr;
	class TextureRect* M8 = nullptr;
	class TextureRect* M9 = nullptr;
	class TextureRect* M10 = nullptr;
	class TextureRect* M11 = nullptr;
	class TextureRect* M12 = nullptr;
					   
	class TextureRect* M13 = nullptr;
	class TextureRect* M14 = nullptr;
	class TextureRect* M15 = nullptr;
	class TextureRect* M16 = nullptr;
	class TextureRect* M17 = nullptr;

	class TextureRect* Relic1 = nullptr;
	class TextureRect* Relic2 = nullptr;
	class TextureRect* Relic3 = nullptr;

	class TextureRect* sb1 = nullptr;
	class TextureRect* sb2 = nullptr;
	class TextureRect* sb3 = nullptr;
	class TextureRect* sb4 = nullptr;

	class TextureRect* eb1 = nullptr;
	class TextureRect* eb2 = nullptr;
	class TextureRect* eb3 = nullptr;
	class TextureRect* eb4 = nullptr;
	class TextureRect* eb5 = nullptr;
	class TextureRect* eb6 = nullptr;

	class TextureRect* num0 = nullptr;
	class TextureRect* num1 = nullptr;
	class TextureRect* num2 = nullptr;
	class TextureRect* num3 = nullptr;
	class TextureRect* num4 = nullptr;
	class TextureRect* num5 = nullptr;
	class TextureRect* num6 = nullptr;
	class TextureRect* num7 = nullptr;
	class TextureRect* num8 = nullptr;
	class TextureRect* num9 = nullptr;
	class TextureRect* num10 = nullptr;
	class TextureRect* num11 = nullptr;
	class TextureRect* num12 = nullptr;
	class TextureRect* num13 = nullptr;
	class TextureRect* num14 = nullptr;
	class TextureRect* num15 = nullptr;
	class TextureRect* num16 = nullptr;
	class TextureRect* num17 = nullptr;
	class TextureRect* num18 = nullptr;
	class TextureRect* num19 = nullptr;


	class TextureRect* e1 = nullptr;
	class TextureRect* e2 = nullptr;
	class TextureRect* e3 = nullptr;
	class TextureRect* e4 = nullptr;
	class TextureRect* e5 = nullptr;
	class TextureRect* e6 = nullptr;
	class TextureRect* e7 = nullptr;
	class TextureRect* e8 = nullptr;
	class TextureRect* e9 = nullptr;
	class TextureRect* e10 = nullptr;
	class TextureRect* e11 = nullptr;
	class TextureRect* e12 = nullptr;

	class MouseDetector* mpos = nullptr;
	class MouseDetector* mpos2 = nullptr;
	class MouseDetector* mpos3 = nullptr;
	class MouseDetector* mpos4 = nullptr;
	class MouseDetector* mpos5 = nullptr;
	
	class MouseDetector* mpos6 = nullptr;
	class MouseDetector* mpos7 = nullptr;
	class MouseDetector* mpos8 = nullptr;
	class MouseDetector* mpos9 = nullptr;
	class MouseDetector* mpos10 = nullptr;
	class MouseDetector* mpos11 = nullptr;
	class MouseDetector* mpos12 = nullptr;
	class MouseDetector* mpos13 = nullptr;

	class MouseDetector* mpos14 = nullptr;
	class MouseDetector* mpos15 = nullptr;

	class MouseDetector* mpos16 = nullptr;
	class MouseDetector* mpos17 = nullptr;

	class MouseDetector* mpos18 = nullptr;
	class MouseDetector* mpos19 = nullptr;
	class MouseDetector* mpos20 = nullptr;
	class MouseDetector* mpos21 = nullptr;

	class Time* StartTime = nullptr;

	class HUD* hud;
private:
	int Acount = 0;
	int Dcount = 0;
	int BossDcount = 0;
	int Hcount = 0;
	
	int Ecount = 0;
	int Ecount2 = 0;
	int Ecount3 = 0;
	int Ecount4 = 0;
	int Ecount5 = 0;
	int Ecount6 = 0;
	int Ecount7 = 0;
	int Ecount8 = 0;
	
	int BossPagecount = 0;
	bool BossPagestart = false;

	int Rcount = 0;

	int Mapcount = 0;

	int PatternStart = 0;
	int mAttack = 0;

	bool PTurn = false;
	bool MTurn = false;
	bool MonsterDead = false;
	bool PlayerDead = false;

	int Effectcount = 0;
	int Debuff = 0;
	int BossEffectcount = 0;

	bool Estart = false;
	bool Estart2 = false;
	bool Estart3 = false;
	bool Estart4 = false;
	bool Estart5 = false;
	bool Estart6 = false;
	bool Estart7 = false;
	bool Estart8 = false;

	bool DmgEstart1 = false;
	bool DmgEstart2 = false;

	int  Pattern = 2;
	int  Value = 0;

	bool DmgEstart3 = false;
	bool DmgEstart4 = false;

	bool ShopLook = false;

	bool BossBattle = false;

	//bool pmove = false;
	//bool mmove = false;

	int Ccount;
	int def;
	int Hp;
	int result;
	
};

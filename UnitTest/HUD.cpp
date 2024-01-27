#include "stdafx.h"
#include "HUD.h"

#include "Utilities/ProgressBar.h"

HUD::HUD()
{
	float width = -WinMaxWidth / 2 + 30;
	float height = WinMaxHeight / 2 - 30;
	HUDBar = new ProgressBar({ 0, 310, 0 }, { WinMaxWidth, 50, 1 }, 0.0f, TexturePath + L"HUD.png", UI::DOWN_TO_UP);
	TimeBar = new ProgressBar({ -10, 315, 0 }, { 225, 44, 1 }, 0.0f, TexturePath + L"hud_guage.png", UI::DOWN_TO_UP);
	SlowBar = new ProgressBar({ -550, 315, 0 }, { 170, 38, 1 }, 0.0f, TexturePath + L"hud_battery.png", UI::DOWN_TO_UP);
	Timer = new ProgressBar({ -85, 345, 0 }, { 180, 32, 1 }, 0.0f, TexturePath + L"Timer.png", UI::LEFT_TO_RIGHT);
}

HUD::~HUD()
{
	SAFE_DELETE(HUDBar);
	SAFE_DELETE(TimeBar);
	SAFE_DELETE(SlowBar);
	SAFE_DELETE(Timer);
}

void HUD::Update()
{
	if (percent >= 1.0f)
		percent = 1.0f;
	if (percent <= 0)
	{
		percent = 0;
		slowcount += 1;
		keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0);
	}
	if (Keyboard::Get()->Press(VK_LSHIFT))
	{
		percent -= 0.005f;
		Timer->UpdateProgressBar(percent);
	}

	percent += 0.002f;
	Timer->UpdateProgressBar(percent);

	HUDBar->Update();
	TimeBar->Update();
	Timer->Update();
	SlowBar->Update();
}

void HUD::Render()
{
	//HUDBar->Render();
	//TimeBar->Render();
	//Timer->Render();
	//SlowBar->Render();
}
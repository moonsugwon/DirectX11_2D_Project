#pragma once

class HUD
{
public:
	HUD();
	~HUD();

	void Update();
	void Render();

private:
	class ProgressBar* HUDBar = nullptr;
	class ProgressBar* SlowBar = nullptr;
	class ProgressBar* TimeBar = nullptr;
	class ProgressBar* Timer = nullptr;

	float percent = 1.0f;
	int slowcount = 0;
};
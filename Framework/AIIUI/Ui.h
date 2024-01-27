#pragma once

class Ui
{
public:
	Ui();
	~Ui();

	void Update();
	void Update(Vector3 Size);
	void Render();

private:

private:
	class TextureRect* u1 = nullptr;
	class TextureRect* u2 = nullptr;
	class TextureRect* u3 = nullptr;
	class TextureRect* u4 = nullptr;
	class TextureRect* u5 = nullptr;
	class TextureRect* u6 = nullptr;
	class TextureRect* u7 = nullptr;
	class TextureRect* u8 = nullptr;
	MouseDetector* MDetector;
};
#include "Framework.h"
#include "Ui.h"

#include "Geomatries/TextureRect.h"

Ui::Ui()
{
	// UI
	{
		u1 = new TextureRect(Vector3(700, 680, 0), Vector3(2080, 100, 0), 0.0f, TexturePath + L"bar.png");
		u2 = new TextureRect(Vector3(1150, 700, 0), Vector3(40, 40, 0), -0.1f, TexturePath + L"map.png");
		u3 = new TextureRect(Vector3(400, 700, 0), Vector3(40, 40, 0), 0.0f, TexturePath + L"GoldBag.png");
		u4 = new TextureRect(Vector3(650, 700, 0), Vector3(40, 40, 0), 0.0f, TexturePath + L"floor.png");
		u5 = new TextureRect(Vector3(1200, 700, 0), Vector3(40, 40, 0), 0.0f, TexturePath + L"deck.png");
		u6 = new TextureRect(Vector3(250, 700, 0), Vector3(40, 40, 0), 0.0f, TexturePath + L"Heart.png");
		u7 = new TextureRect(Vector3(1250, 700, 0), Vector3(40, 40, 0), 0.0f, TexturePath + L"settings.png");
		u8 = new TextureRect(Vector3(1250, 700, 0), Vector3(40, 40, 0), 0.0f, TexturePath + L"cusor.png");
	}
	//MDetector = new MouseDetector(this->GetBox()->GetEdge().LT, this->GetBox()->GetEdge().RB);
}

Ui::~Ui()
{
	SAFE_DELETE(u1);
	SAFE_DELETE(u2);
	SAFE_DELETE(u3);
	SAFE_DELETE(u4);
	SAFE_DELETE(u5);
	SAFE_DELETE(u6);
	SAFE_DELETE(u7);
	SAFE_DELETE(u8);
	SAFE_DELETE(MDetector);

}

void Ui::Update()
{
	
	//MDetector->Update(this->GetPosition(), this->GetSize());
}

void Ui::Update(Vector3 Size)
{
	//if (MDetector->IsOnMouseCursor())
	//{
	//	this->size = Size;
	//}
	//else if (MDetector->IsOnMouseCursor() == false)
	//{
	//	this->size = Size - Vector3(50, 50, 0);
	//}

	Update();
}

void Ui::Render()
{
}

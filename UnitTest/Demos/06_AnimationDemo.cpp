#include "stdafx.h"
#include "06_AnimationDemo.h"

#include "Geomatries/AnimationRect.h"

void AnimationDemo::Init()
{
	p1 = new AnimationRect({ 720, 360, 0 }, { 200, 200, 0 });
}

void AnimationDemo::Destroy()
{
	SAFE_DELETE(p1);
}

void AnimationDemo::Update()
{
	p1->Move();
	p1->Update();
}

void AnimationDemo::Render()
{
	p1->Render();
}

void AnimationDemo::PostRender()
{
}

void AnimationDemo::GUI()
{
}

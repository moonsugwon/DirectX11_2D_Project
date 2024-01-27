#include "Framework.h"
#include "MouseDetector.h"

MouseDetector::MouseDetector(Vector3 LT, Vector3 RB)
    : LT(LT.x, LT.y, 0), RB(RB.x, RB.y, 0)
{
    mouse = Mouse::Get();
}

MouseDetector::~MouseDetector()
{
    mouse->Delete();
}

bool MouseDetector::IsOnMouseCursor()
{
    Vector3 pos;
    Camera::Get()->Unprojection(&pos, mouse->GetPosition(), Values::Identity);

    if (LT.x < pos.x && LT.y > pos.y &&
        RB.x > pos.x && RB.y < pos.y)
        return true;

    return false;
    /*
    if (LT.x < mpos.x && LT.y > mpos.y &&
        RB.x > mpos.x && RB.y < mpos.y &&
        LB.x > mpos.x && LB.y < mpos.y &&
        RT.x < mpos.x && RT.y > mpos.y)
        return true;

    return false;
    */
}


bool MouseDetector::IsMouseLClick()
{
    if (IsOnMouseCursor() && mouse->Down(0))
        return true;

    return false;
}

bool MouseDetector::IsMouseRClick()
{
    if (IsOnMouseCursor() && mouse->Down(1))
        return true;
    return false;
}

bool MouseDetector::IsMouseDrag()
{
    if (IsOnMouseCursor() && mouse->Press(0))
        return true;
    else if (mouse->Up(0))
        return false;

    return false;
}

bool MouseDetector::IsMouseDragOff()
{
    if (IsOnMouseCursor() && mouse->Up(0))
        return true;

    return false;
}

void MouseDetector::Update(Vector3 position, Vector3 size)
{

    LT.x = position.x - (size.x / 2);
    LT.y = position.y + (size.y / 2);

    RB.x = position.x + (size.x / 2);
    RB.y = position.y - (size.y / 2);
    /*
    LT.x = position.x - (size.x / 4);
    LT.y = position.y + (size.y / 4);
    LB.x = position.x + (size.x / 4);
    LB.y = position.y - (size.y / 4);
                                  
                                  
    RB.x = position.x + (size.x / 4);
    RB.y = position.y - (size.y / 4);
    RT.x = position.x - (size.x / 4);
    RT.y = position.y + (size.y / 4);
    */

}

#pragma once

class MouseDetector 
{
public:
    MouseDetector(Vector3 LT, Vector3 RB);
   //MouseDetector(Vector2 LT, Vector2 RB, Vector2 LB, Vector2 RT);
    ~MouseDetector();

    bool IsOnMouseCursor();

    bool IsMouseLClick();
    bool IsMouseRClick();

    bool IsMouseDrag();
    bool IsMouseDragOff();

    void Update(Vector3 position, Vector3 size);

private:
    Vector3 LT, RB = Values::ZeroVec3;
    Mouse* mouse = nullptr;
};
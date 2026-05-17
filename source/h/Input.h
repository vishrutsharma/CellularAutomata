#pragma once
#include <SDL_events.h>
#include "Comp.h"

constexpr float MOUSE_ZOOM_MIN_LEVEL = 0.2f;
constexpr float MOUSE_ZOOM_MAX_LEVEL = 8.0f;

enum MouseButtonType
{
    LEFT_BUTTON,
    RIGHT_BUTTON
};

class Input
{
public:
    void HandleEvent(const SDL_Event&);
    inline const IVec2& GetMousePos(){return m_mousePos;}
    inline const IVec2& GetMousePrevPos() {return m_mousePrevPos;}
    inline float GetMouseWheelZoom() {return m_mouseWheelZoomLevel;}
    inline IVec2 GetMouseDelta() {return m_mouseDelta;}
    bool IsMouseButtonDown(MouseButtonType);

private:
    IVec2 m_mouseDelta;
    IVec2 m_mousePos;
    IVec2 m_mousePrevPos{0,0};
    bool m_isMouseLeftButtonDown = false;
    bool m_isMouseRightButtonDown = false;
    float m_mouseWheelZoomLevel = 0.0f;

};
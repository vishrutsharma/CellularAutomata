#include "Input.h"
#include <iostream>
#include <algorithm>

void Input::HandleEvent(const SDL_Event& event)
{
    switch(event.type)
    {
        case SDL_MOUSEWHEEL:
        {
            if(event.wheel.y > 0)
            {
                m_mouseWheelZoomLevel += 0.1;
            }

            if(event.wheel.y < 0)
            {
                m_mouseWheelZoomLevel -= 0.1;
            }

            m_mouseWheelZoomLevel = std::clamp(m_mouseWheelZoomLevel,MOUSE_ZOOM_MIN_LEVEL,MOUSE_ZOOM_MAX_LEVEL); 
            
        }
        break;

        case SDL_MOUSEMOTION:
        {
            SDL_GetMouseState(&m_mousePos.x,&m_mousePos.y);
            m_mouseDelta = m_mousePos - m_mousePrevPos;
            m_mousePrevPos = m_mousePos;
        }
        break;

        case SDL_MOUSEBUTTONDOWN:
        {
            if (event.button.button == SDL_BUTTON_LEFT)
                m_isMouseLeftButtonDown = true;

            if (event.button.button == SDL_BUTTON_RIGHT)
                m_isMouseRightButtonDown = true;

            SDL_GetMouseState(&m_mousePrevPos.x, &m_mousePrevPos.y);
        }
        break;

        case SDL_MOUSEBUTTONUP:
        {
            if (event.button.button == SDL_BUTTON_LEFT)
                m_isMouseLeftButtonDown = false;

            if (event.button.button == SDL_BUTTON_RIGHT)
                m_isMouseRightButtonDown = false;
        }
        break;
    }
}


    // convert this to bitmask logic
    bool Input::IsMouseButtonDown(MouseButtonType type)
    {
        switch (type)
        {
            case MouseButtonType::LEFT_BUTTON:
                return m_isMouseLeftButtonDown;
                break;

            case MouseButtonType::RIGHT_BUTTON:
                return m_isMouseRightButtonDown;
                break;
        }   
        return false; 
    }
#pragma once
#include <SDL_rect.h>
#include <SDL_render.h>
#include <vector>
#include "Comp.h"

namespace Grid
{   
    struct Node
    {
        SDL_Rect m_rect;
        int m_row;
        int m_col;
        IVec2 m_pos;
        Node(SDL_Rect,int,int,IVec2);
    };

    

    class GridManager
    {
    private:
        int m_nodeDefaultSize;
        int m_zoomLevel;
        SDL_Rect m_viewport;     
        std::vector<std::vector<Node*>> m_nodes; 

    public:
        void Generate(int,SDL_Rect&);
        void Render(SDL_Renderer*);
        void Update();

    };
}
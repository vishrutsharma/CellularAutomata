#pragma once
#include <SDL_rect.h>
#include <SDL_render.h>
#include <vector>
#include "Comp.h"

namespace Grid
{   
    struct Node
    {
        SDL_Rect rect;
        int row;
        int col;
        IVec2 pos;
    };

    class GridManager
    {
    private:
        int m_nodeDefaultSize;
        int m_zoomLevel;
        SDL_Rect m_viewport;     
        std::vector<std::vector<Node*>> m_nodes; 

    public:
        void Generate(int,SDL_Rect);
        void Render(SDL_Renderer&);  

    };
}
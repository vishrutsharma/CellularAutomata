#include "Grid.h"
#include <cmath>
#include <SDL_log.h>

Grid::Node::Node(SDL_Rect rect, int row , int col , IVec2 pos):m_rect(rect),m_row(row),m_col(col),m_pos(pos)
    {
    } 


void Grid::GridManager::Generate(int defaultSize,SDL_Rect& viewPort)
{
    m_nodeDefaultSize = defaultSize;
    m_viewport = viewPort;
    int vprt_width = m_viewport.w;
    int vprt_height = m_viewport.h;
    int vprt_pos_x =  INT_CAST(m_viewport.x + vprt_width/2);
    int vprt_pos_y =  INT_CAST(m_viewport.y + vprt_height/2);

    int padding = 1;
    int nodes_col_count = floor(vprt_width/(defaultSize + padding));
    int nodes_row_count = floor(vprt_height/(defaultSize + padding));

    int start_x = INT_CAST(vprt_pos_x - vprt_width/2);
    int start_y =  INT_CAST(vprt_pos_y - vprt_height/2);

    m_nodes.resize(nodes_row_count);
    for(int r = 0 ;r < nodes_row_count;r++)
    {
        m_nodes[r].resize(nodes_col_count);
    }

    for(int y = 0 ;y < nodes_row_count;y++)
    {
        for(int x = 0 ; x < nodes_col_count; x++)
        {
            int pos_x = start_x + INT_CAST(((defaultSize+padding) * x));   
            int pos_y = start_y + INT_CAST(((defaultSize+padding) * y)) ;  
            IVec2 desiredPos{pos_x,pos_y};  
            SDL_Rect rect = {desiredPos.x,desiredPos.y ,defaultSize,defaultSize};
            m_nodes.at(y).emplace_back(new Node(rect,x,y,desiredPos));
        }
    }
}

void Grid::GridManager::Update()
{

}

void Grid::GridManager::Render(SDL_Renderer* renderer)
{

    if(m_nodes.size() == 0) return;
    SDL_SetRenderDrawColor(renderer,255,142,40,255);
    SDL_RenderDrawRect(renderer, &m_viewport);
    SDL_RenderFillRect(renderer,&m_viewport);

    for(const auto& row : m_nodes)
    {
        for(Node* node : row)
        {
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            SDL_RenderDrawRect(renderer,&node->m_rect);
        }
    }
    
}
                                        


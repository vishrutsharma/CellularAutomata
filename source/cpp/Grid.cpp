#include "Grid.h"
#include <cmath>

void Grid::GridManager::Generate(int defaultSize,SDL_Rect viewPort)
{
    
    m_nodeDefaultSize = defaultSize;
    m_viewport = viewPort;
    int vprt_width = m_viewport.w;
    int vprt_height = m_viewport.h;
    int vprt_pos_x =  INT_CAST(m_viewport.x + vprt_width/2);
    int vprt_pos_y =  INT_CAST(m_viewport.y + vprt_height/2);

    int padding = 0;
    int nodes_x_count = floor(vprt_width/(defaultSize + padding));
    int nodes_y_count = floor(vprt_height/(defaultSize + padding));

    int start_x =  INT_CAST(vprt_pos_x - vprt_width/2);
    int start_y = INT_CAST(vprt_pos_y - vprt_height/2);

    m_nodes.resize(nodes_y_count);
    for(int r = 0 ;r < nodes_y_count;r++)
    {
        m_nodes[r].resize(nodes_x_count);
    }

    for(int y = 0 ;y < nodes_y_count;y++)
    {
        for(int x = 0 ; x < nodes_x_count; x++)
        {
            int pos_x = start_x + ((defaultSize+padding) * x);   
            int pos_y = start_y + ((defaultSize+padding) * y) ;  
            IVec2 desiredPos{pos_x,pos_y};     
        }
    }
}
                                        


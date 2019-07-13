#ifndef Canvas_H
#define Canvas_H

#include <GL/freeglut.h>
#include <vector>

class Canvas
{
    struct character
    {
        float color[ 3 ];
        char theCharacter;
        int x;
        int y;

        bool operator== ( character &c );
    };

    struct rectangle
    {
        float color[ 3 ];
        char key;
        float x1;
        float x2;
        float y1;
        float y2;

        bool operator== ( rectangle &r );
    };
    
    character thisChar;
    rectangle thisRect;
    std::vector<character> characters;
    std::vector<rectangle> rectangles;
        
public:
    Canvas( );
    void clearCanvas( );
    void DrawCharacter( char ch, int x, int y, const float color[ ] );
    void DrawFilledRectangle( float x1, float y1, float x2, float y2,
                              const float color[ ] );
    void redrawWindow( );
};

#endif
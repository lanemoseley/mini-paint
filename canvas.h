#ifndef Canvas_H
#define Canvas_H

#include <GL/freeglut.h>
#include <vector>

class Canvas
{
    struct character
    {
        char theCharacter;
        int x;
        int y;
        float color[ 3 ];

        character( const float Color[], char ch, int X, int Y ) : theCharacter( ch ), x( X ), y( Y )
        {
            for ( int i = 0; i < 3; ++i )
                color[ i ] = Color[ i ];
        }
    };

    struct rectangle
    {
        float x1;
        float x2;
        float y1;
        float y2;
        float color[ 3 ];

        rectangle( const float Color[], float X1, float X2, float Y1, float Y2 ) : x1( X1 ), x2( X2 ), y1( Y1 )
        {
            for ( int i = 0; i < 3; ++i )
                color[ i ] = Color[ i ];
        }
    };
    
    std::vector<character> characters;
    std::vector<rectangle> rectangles;
        
public:
    Canvas( );
    void addCharacter( char ch, int x, int y, const float color[ ] );
    void addRectangle( float x1, float y1, float x2, float y2, const float color[ ] );
    void clearCanvas( );
    void DrawCharacter( char ch, int x, int y, const float color[ ] );
    void DrawFilledRectangle( float x1, float y1, float x2, float y2, const float color[ ] );
    void redrawWindow( );
};

#endif
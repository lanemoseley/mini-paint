#include "canvas.h"

Canvas::Canvas( ) { }

void Canvas::clearCanvas( )
{
    rectangles.clear( );
    characters.clear( );
}

void Canvas::DrawCharacter( char ch, int x, int y, const float color[ ] )
{
    int i, colorArraySize = 3;
    
    glColor3fv( color );
    glRasterPos2i( x, y );
    glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, ch );

    for ( i = 0; i < colorArraySize; ++i )
        thisChar.color[ i ] = color[ i ];

    thisChar.theCharacter = ch;
    thisChar.x = x;
    thisChar.y = y;

    for ( auto x : characters )
    {
        if ( x == thisChar )
            return;
    }
    
    characters.push_back( thisChar );
}

void Canvas::DrawFilledRectangle( float x1, float y1, float x2, float y2,
                                  const float color[ ] )
{
    int i, colorArraySize = 3;
    
    glColor3fv( color );
    glBegin( GL_POLYGON );
    glVertex2f( x1, y1 );
    glVertex2f( x2, y1 );
    glVertex2f( x2, y2 );
    glVertex2f( x1, y2 );
    glEnd( );

    for ( i = 0; i < colorArraySize; ++i )
        thisRect.color[ i ] = color[ i ];
    
    thisRect.x1 = x1;
    thisRect.x2 = x2;
    thisRect.y1 = y1;
    thisRect.y2 = y2;


    /// try moving the rectangle to the top of the stack so that the color gets changed
    for ( auto x : rectangles )
    {
        if ( x == thisRect )
            return;
    }

    rectangles.push_back( thisRect );
}

void Canvas::redrawWindow( )
{
    unsigned int i;
    
    for ( i = 0; i < characters.size( ); ++i )
    {
        DrawCharacter( characters[ i ].theCharacter, characters[ i ].x,
                       characters[ i ].y, characters[ i ].color );
    }

    for ( i = 0; i < rectangles.size( ); ++i )
    {
        DrawFilledRectangle( rectangles[ i ].x1, rectangles[ i ].y1,
                             rectangles[ i ].x2, rectangles[ i ].y2,
                             rectangles[ i ].color );
    }
}

bool Canvas::character::operator== ( character &c )
{
    int i, colorArraySize = 3;

    for ( i = 0; i < colorArraySize; ++i )
    {
        if ( color[ i ] != c.color[ i ] )
            return false;
    }

    if ( x != c.x || y != c.y )
        return false;
    
    return true;
}

bool Canvas::rectangle::operator== ( rectangle &r )
{
    int i, colorArraySize = 3;
    
    for ( i = 0; i < colorArraySize; ++i )
    {
        if( color[ i ] != r.color[ i ] )
            return false;
    }
    
    if( x1 != r.x1 || x2 != r.x2 || y1 != r.y1 || y2 != r.y2 )
        return false;

    return true;    
}
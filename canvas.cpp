#include "canvas.h"

Canvas::Canvas( ) { }

void Canvas::addCharacter( char ch, int x, int y, const float color[ ] )
{ characters.push_back( character( color, ch, x, y ) ); }

void Canvas::addRectangle( float x1, float y1, float x2, float y2,
                                  const float color[ ] )
{ rectangles.push_back( rectangle( color, x1, x2, y1, y2 ) ); }

void Canvas::clearCanvas( )
{
    rectangles.clear( );
    characters.clear( );
}

void Canvas::DrawCharacter( char ch, int x, int y, const float color[ ] )
{
    glColor3fv( color );
    glRasterPos2i( x, y );
    glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, ch );
}

void Canvas::DrawFilledRectangle( float x1, float y1, float x2, float y2,
                                  const float color[ ] )
{
    glColor3fv( color );
    glBegin( GL_POLYGON );
    glVertex2f( x1, y1 );
    glVertex2f( x2, y1 );
    glVertex2f( x2, y2 );
    glVertex2f( x1, y2 );
    glEnd( );
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

// bool Canvas::character::operator== ( character &c )
// {
//     int i, colorArraySize = 3;

//     for ( i = 0; i < colorArraySize; ++i )
//     {
//         if ( color[ i ] != c.color[ i ] )
//             return false;
//     }

//     if ( x != c.x || y != c.y )
//         return false;
    
//     return true;
// }

// bool Canvas::rectangle::operator== ( rectangle &r )
// {
//     int i, colorArraySize = 3;
    
//     for ( i = 0; i < colorArraySize; ++i )
//     {
//         if( color[ i ] != r.color[ i ] )
//             return false;
//     }
    
//     if( x1 != r.x1 || x2 != r.x2 || y1 != r.y1 || y2 != r.y2 )
//         return false;

//     return true;    
// }
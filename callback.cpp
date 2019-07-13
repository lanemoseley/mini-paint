/// Adapted from sample code on class website
#include "callback.h"

void display( )
{
    utilityCentral( new DisplayEvent( ) );
}

void keyboard( unsigned char key, int x, int y )
{
    utilityCentral( new KeyboardEvent( key, x, y ) );
}

void mouseClick( int button, int state, int x, int y )
{
    utilityCentral( new MouseClickEvent( button, state, x, y ) );
}

void mouseMove( int x, int y )
{
    utilityCentral( new MouseMoveEvent( x, y ) );
}

void reshape( const int w, const int h )
{
    glLoadIdentity( );
    gluOrtho2D( 0.0, w, 0.0, h );
    glViewport( 0, 0, w, h );
    utilityCentral( new ReshapeEvent( w, h ) );
}
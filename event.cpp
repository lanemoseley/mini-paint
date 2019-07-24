#include "event.h"

Event::~Event( ) { }

void DisplayEvent::doAction( Canvas &canvas )
{
    canvas.redrawWindow( );
    glutSwapBuffers( );
}

InitEvent::InitEvent( int c, int r ) : columns( c ), rows( r ) { }
void InitEvent::doAction( Canvas &canvas )
{ glClear( GL_COLOR_BUFFER_BIT ); }

KeyboardEvent::KeyboardEvent( unsigned char k, int x, int y ) : key( k ), xLoc( x ), yLoc( y ) { }
void KeyboardEvent::doAction( Canvas &canvas )
{
    // escape closes the program
    if ( key == ESCAPE_KEY )
        glutLeaveMainLoop( );
    
    // backspace clears the canvas
    if ( key == BACKSPACE )
    {
        glClear( GL_COLOR_BUFFER_BIT );
        canvas.clearCanvas( );
        glutSwapBuffers( );
    }
    
    // uppercase letters
    else if ( key > 64 && key < 91 )
    {
        canvas.addCharacter( key, xLoc, glutGet( GLUT_WINDOW_HEIGHT ) - yLoc, Blue );
        canvas.redrawWindow( );
        glutSwapBuffers( );
    }

    // lowercase letters
    else if ( key > 96 && key < 123)
    {
        canvas.addCharacter( key, xLoc, glutGet( GLUT_WINDOW_HEIGHT ) - yLoc, Red );
        canvas.redrawWindow( );
        glutSwapBuffers( );
    }

    // numbers
    else if ( key > 47 && key < 58 )
    {
        canvas.addCharacter( key, xLoc, glutGet( GLUT_WINDOW_HEIGHT ) - yLoc, Green );
        canvas.redrawWindow( );
        glutSwapBuffers( );
    }

    // all other characters
    else
    {
        canvas.addCharacter( key, xLoc, glutGet( GLUT_WINDOW_HEIGHT ) - yLoc, White );
        canvas.redrawWindow( );
        glutSwapBuffers( );
    }
}

MouseClickEvent::MouseClickEvent( int b, int s, int x, int y ) : button( b ), state( s ), xLoc( x ), yLoc( y ) { }
void MouseClickEvent::doAction( Canvas &canvas )
{
    // draws small square on left click
    if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
    {
        canvas.addRectangle( xLoc + 5,
                             glutGet( GLUT_WINDOW_HEIGHT ) - yLoc + 5, xLoc - 5,
                             glutGet( GLUT_WINDOW_HEIGHT ) - yLoc - 5, Yellow );
        canvas.redrawWindow( );
        glutSwapBuffers( );
    }
    
    // draws larger square on right click
    if ( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN )
    {
        canvas.addRectangle( xLoc + 15,
                             glutGet( GLUT_WINDOW_HEIGHT ) - yLoc + 15, xLoc - 15,
                             glutGet( GLUT_WINDOW_HEIGHT ) - yLoc - 15, Orange );
        canvas.redrawWindow( );
        glutSwapBuffers( );
    }
}

MouseMoveEvent::MouseMoveEvent( int x, int y ) : xLoc( x ), yLoc( y ) { }
void MouseMoveEvent::doAction( Canvas &canvas )
{
    std::stringstream ss;
    
    // display mouse coordinates in title bar
    ss << "x = " << xLoc << " :: y = " << yLoc;
    glutSetWindowTitle( ss.str( ).c_str( ) );
}

ReshapeEvent::ReshapeEvent( int w, int h ) : width( w ), height( h ) { }
void ReshapeEvent::doAction( Canvas &canvas )
{
    glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    gluOrtho2D( 0.0, width, 0.0, height );
    glViewport( 0, 0, width, height );
}
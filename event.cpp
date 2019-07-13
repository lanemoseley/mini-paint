/// Adapted from sample code on class website
#include "event.h"

Event::~Event( ) { }

void DisplayEvent::doAction( Canvas &canvas )
{
    canvas.redrawWindow( );
    glutSwapBuffers( );
}

InitEvent::InitEvent( int c, int r ) : columns( c ), rows( r ) { }
void InitEvent::doAction( Canvas &canvas )
{
    glClear( GL_COLOR_BUFFER_BIT );
}

KeyboardEvent::KeyboardEvent( unsigned char k, int x, int y ) : key( k ),
    xLoc( x ), yLoc( y ) { }
void KeyboardEvent::doAction( Canvas &canvas )
{
    if ( key == ESCAPE_KEY )
        glutLeaveMainLoop( );
    
    if ( key == BACKSPACE )
    {
        glClear( GL_COLOR_BUFFER_BIT );
        canvas.clearCanvas( );
        glutSwapBuffers( );
    }
    
    else
    {
        canvas.addCharacter( key, xLoc, glutGet( GLUT_WINDOW_HEIGHT ) - yLoc, White );
        canvas.redrawWindow( );
        glutSwapBuffers( );
    }
}

MouseClickEvent::MouseClickEvent( int b, int s, int x, int y ) :
    button( b ), state( s ), xLoc( x ), yLoc( y ) { }
void MouseClickEvent::doAction( Canvas &canvas )
{
    if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
    {
        canvas.addRectangle( xLoc + 5,
                             glutGet( GLUT_WINDOW_HEIGHT ) - yLoc + 5, xLoc - 5,
                             glutGet( GLUT_WINDOW_HEIGHT ) - yLoc - 5, Red );
        canvas.redrawWindow( );
        glutSwapBuffers( );
    }
    
    if ( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN )
    {
        canvas.addRectangle( xLoc + 5,
                             glutGet( GLUT_WINDOW_HEIGHT ) - yLoc + 5, xLoc - 5,
                             glutGet( GLUT_WINDOW_HEIGHT ) - yLoc - 5, Blue );
        canvas.redrawWindow( );
        glutSwapBuffers( );
    }
    
    if ( button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN )
    {
        canvas.addRectangle( xLoc + 5,
                             glutGet( GLUT_WINDOW_HEIGHT ) - yLoc + 5, xLoc - 5,
                             glutGet( GLUT_WINDOW_HEIGHT ) - yLoc - 5, Green );
        canvas.redrawWindow( );
        glutSwapBuffers( );
    }
}

MouseMoveEvent::MouseMoveEvent( int x, int y ) : xLoc( x ), yLoc( y ) { }
void MouseMoveEvent::doAction( Canvas &canvas )
{
    std::stringstream ss;
    
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
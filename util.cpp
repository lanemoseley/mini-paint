#include "util.h"

void utilityCentral( Event *event )
{
    static Canvas canvas;
    
    event->doAction( canvas );
    delete event;
}

void initOpenGL( int argc, char **argv, const int columns, const int rows )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA );
    glutInitWindowSize( columns, rows );
    glutInitWindowPosition( windowXPos, windowYPos );
    glutCreateWindow( argv[0] );
    glutDisplayFunc( display );
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    glutKeyboardFunc( keyboard );
    glutMouseFunc( mouseClick );
    glutPassiveMotionFunc( mouseMove );
    glutReshapeFunc( reshape );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    utilityCentral( new InitEvent( columns, rows ) );
}
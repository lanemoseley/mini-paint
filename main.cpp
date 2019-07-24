#include "util.h"

// window dimensions
const int COLS = 500;
const int ROWS = 500;

int main( int argc, char *argv[ ] )
{
    initOpenGL( argc, argv, COLS, ROWS );
    glutMainLoop( );
    
    return 0;
}
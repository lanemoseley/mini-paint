#ifndef Callback_H
#define Callback_H

#include "event.h"
#include "util.h"

void display( );
void keyboard( unsigned char key, int x, int y );
void mouseClick( int button, int state, int x, int y );
void mouseMove( int x, int y );
void reshape( const int x, const int y );
void utilityCentral( Event * );

#endif
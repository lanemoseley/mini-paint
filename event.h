#ifndef Event_H
#define Event_H

#include "canvas.h"
#include <GL/freeglut.h>
#include <sstream>

#define ESCAPE_KEY 27
#define BACKSPACE 8

const float Blue[]  = { 0.0, 0.0, 1.0 };
const float Green[] = { 0.0, 1.0, 0.0 };
const float Red[]   = { 1.0, 0.0, 0.0 };
const float White[] = { 1.0, 1.0, 1.0 };

class Event
{
    public:
        virtual void doAction( Canvas & ) = 0;
        virtual ~Event( );
};

class InitEvent : public Event
{
        int columns, rows;
    
    public:
        InitEvent( int, int );
        void doAction( Canvas & );
};

class DisplayEvent : public Event
{
    public:
        void doAction( Canvas & );
};

class KeyboardEvent : public Event
{
        unsigned char key;
        int xLoc;
        int yLoc;
        
    public:
        KeyboardEvent( unsigned char, int, int );
        void doAction( Canvas & );
};

class MouseClickEvent : public Event
{
        int button;
        int state;
        int xLoc;
        int yLoc;
        
    public:
        MouseClickEvent( int, int, int, int );
        void doAction( Canvas & );
};

class MouseMoveEvent : public Event
{
        int xLoc;
        int yLoc;
        
    public:
        MouseMoveEvent( int, int );
        void doAction( Canvas & );
};

class ReshapeEvent : public Event
{
        int width;
        int height;

    public:
        ReshapeEvent( int, int );
        void doAction( Canvas & );
};

#endif
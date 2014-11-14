#pragma once
#include "LocationCoordinate.h"

enum MouseButton{ RIGHT, LEFT, NONE };


struct MouseCoordinates: public LocationCoordinates{
	MouseButton button=NONE;

	MouseCoordinates( int _x, int _y, MouseButton b ) :LocationCoordinates({ _x, _y }){
		button = b;
	}
};


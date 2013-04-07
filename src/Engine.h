/*
 * Engine.h
 *
 *  Created on: Jul 16, 2012
 *      Author: destructo
 */

#ifndef ENGINE_H_
#define ENGINE_H_

#include "Common.h"

#include "graphics/2d/shape/Square.h"
#include "graphics/Screen.h"

#include "input/sdl/SDLKeyBoard.h"
#include "input/glut/Mouse.h"

#include "graphics/Screen.h"
#include "graphics/2d/shape/Point2D.h"
#include "graphics/2d/shape/Square.h"
#include "graphics/2d/sprite/Sprite2D.h"

#include "graphics/3d/shape/Cube.h"



class Engine {
public:
	Engine();
	virtual ~Engine();

	void render();
	void events();
	void logic();
	void quit(int code);


private:

	Screen* screen;
	SDLKeyBoard* keyboard;

	Sprite2D* sprite;

	Point2D* p;
	Square* s;
	Cube* cube;
	Cube* cube2;

	int x;
	int dx;

	int y;
	int dy;

	GLfloat depth;

};


#endif /* ENGINE_H_ */


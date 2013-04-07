/*
 * Engine.cpp
 *
 *  Created on: Jul 16, 2012
 *      Author: destructo
 */

#include "Engine.h"

Engine::Engine() {
	p = new Point2D();
	s = new Square(100);
	cube = new Cube(100);
	//cube2 = new Cube(50);
	/*
	RGB rgb = RGB(0xFF, 00, 00);
	cube->setColor(0, rgb);
	rgb = RGB(0xFF, 00, 00);
	cube->setColor(1, rgb);

	rgb = RGB(00, 0xFF, 00);
	cube->setColor(2, rgb);
	rgb = RGB(00, 0xFF, 00);
	cube->setColor(3, rgb);

	rgb = RGB(00, 00, 0xFF);
	cube->setColor(4, rgb);
	rgb = RGB(00, 00, 0xFF);
	cube->setColor(5, rgb);
*/

	x = 0;
	dx = 6;

	y = 0;
	dy = 6;

	depth = 0;


	screen = new Screen(640, 480, 200, 100, "Game Engine");
	keyboard = new SDLKeyBoard();

	sprite = new Sprite2D("resources/sprites/samus.png", 10, 50);

}

Engine::~Engine() {

}

void Engine::render() {
	//std::cout << "drawing x =" << x << " y = " << y << std::endl;

	screen->clear();


	s->setColor(255, 0, 0);
	s->translate(100, 100, 0);
	s->draw();

	p->setColor(255, 255, 255);
	for(int i = 0; i < 1000; i++) {
		p->translate(i, 50, 0);
		p->draw();
	}

	sprite->translate(x, y, 0);
	sprite->draw();


	screen->startDraw3D();

	// cube->setColor(255, 0, 255);
	cube->rotate(cube->rotX() + 1, cube->rotY() + 1, cube->rotZ() - 1);
	cube->translate(300, 200, depth);
	cube->draw();

	//cube2->rotate(cube2->rotX() - 1, cube2->rotY() - 1, cube2->rotZ() + 1);
	//cube2->translate(300 + x, 200 + y, depth + 500);
	//cube2->draw();


	screen->endDraw3D();

	//s->setColor(255, 255, 0);
	//s->draw(200, 150);

	// cube->setColor(0, 255, 0);

	//cube->translate(400, 280, depth - 100);
	//cube->draw();
	screen->flipBuffers();
}

void Engine::events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                keyboard->keyPressed(event.key.keysym.sym);
                break;
            case SDL_KEYUP:
            	 keyboard->keyReleased(event.key.keysym.sym);
                break;
            case SDL_QUIT:
            	exit(0);
        }
    }
}


void Engine::logic() {


	if (keyboard->isKeyPressed(SDLK_ESCAPE)) {
		quit(0);
	}
	if (keyboard->isKeyPressed(SDLK_LEFT)) {
		x -= 10;
	}
	if (keyboard->isKeyPressed(SDLK_RIGHT)) {
		x += 10;
	}
	if (keyboard->isKeyPressed(SDLK_DOWN)) {
		y += 10;
	}
	if (keyboard->isKeyPressed(SDLK_UP)) {
		y -= 10;
	}

	if(keyboard->isKeyPressed(SDLK_z)) {
		depth--;
		std::cout << "depth: " << depth << std::endl;
	}
	if(keyboard->isKeyPressed(SDLK_x)) {
		depth++;
		std::cout << "depth: " << depth << std::endl;
	}
}


void Engine::quit(int code) {
    SDL_Quit( );

    /* Exit program. */
    exit( code );
}




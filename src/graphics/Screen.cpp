/*
 * Screen.cpp
 *
 *  Created on: Jun 21, 2012
 *      Author: destructo
 */

#include "Screen.h"

Screen::Screen(int width, int height, int windowX, int windowY, std::string windowName) {
	this->width = width;
	this->height = height;
	this->windowX = windowX;
	this->windowY = windowY;
	this->windowName = windowName;
	init();
}

Screen::~Screen() {

}

void Screen::init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return;
	}


	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // *new*
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

	screen = SDL_SetVideoMode(640, 480, 32, SDL_OPENGL); // *changed*

	glClearColor(0, 0, 0, 0);

	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
    glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0, width, height, 0, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glDepthFunc(GL_LESS);    /* pedantic, GL_LESS is the default */
	glClearDepth(1.0);       /* pedantic, 1.0 is the default */


}

void Screen::clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Enable 2D rendering
	//glEnable2D();


}

void Screen::flipBuffers() {
	/*
	 * Swap the buffers. This this tells the driver to
	 * render the next frame from the contents of the
	 * back-buffer, and to set all rendering operations
	 * to occur on what was the front-buffer.
	 *
	 * Double buffering prevents nasty visual tearing
	 * from the application drawing on areas of the
	 * screen that are being updated at the same time.
	 */
	SDL_GL_SwapBuffers();

	// Disable 2D rendering
	//glDisable2D();

	calculateFramerate();
}

void Screen::calculateFramerate() {
	frames++;
	GLint t = SDL_GetTicks();
	if (t - t0 >= 5000) {
		GLfloat seconds = (t - t0) / 1000.0;
		GLfloat fps = frames / seconds;
		printf("%d frames in %g seconds = %g FPS\n", frames, seconds, fps);
		t0 = t;
		frames = 0;
	}
}

void Screen::setBackgroundColor(float r, float g, float b) {
	glClearColor(r, g, b, 0);
}

int Screen::getWidth() {
	return width;
}

int Screen::getHeight() {
	return height;
}

void Screen::startDraw3D() {
	glEnable(GL_CULL_FACE);
}

void Screen::endDraw3D() {
	glDisable(GL_CULL_FACE);
}

void Screen::toggleFullScreen() {
	SDL_WM_ToggleFullScreen(screen);
}


void Screen::glEnable2D() {

	// Save a copy of the projection matrix so that we can restore it
	// when it's time to do 3D rendering again.
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	// Set up the orthographic projection
	glOrtho(0, width, height, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	// Make sure depth testing and lighting are disabled for 2D rendering until
	// we are finished rendering in 2D
	glPushAttrib(GL_DEPTH_BUFFER_BIT | GL_LIGHTING_BIT);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
}

void Screen::glDisable2D() {
	glPopAttrib();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
}


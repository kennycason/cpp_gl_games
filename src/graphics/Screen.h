/*
 * Screen.h
 *
 *  Created on: Jun 21, 2012
 *      Author: destructo
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include "../Common.h"

#define ONE_OVER_FPS (1.0f/60.0f)

class Screen {
public:
	Screen(int width, int height, int windowX, int windowY, std::string windowName);
	virtual ~Screen();
	void clear();
	void flipBuffers();
	void setBackgroundColor(float r, float g, float b);
	int getWidth();
	int getHeight();
	void startDraw3D();
	void endDraw3D();
	void toggleFullScreen();

private:
	void init();
	void calculateFramerate();

	void glEnable2D();
	void glDisable2D();

	SDL_Surface* screen;

	int width;
	int height;

	int windowX;
	int windowY;

	std::string windowName;

	int frames;
	int t0;

};

#endif /* SCREEN_H_ */

/*
 * Sprite2D.h
 *
 *  Created on: Jun 23, 2012
 *      Author: destructo
 */

#ifndef SPRITE2D_H_
#define SPRITE2D_H_

#include "../../../Common.h"

class Sprite2D : public Drawable {
public:
	Sprite2D(std::string fileName, int frames, unsigned int animationSpeed);
	virtual ~Sprite2D();
	virtual void draw();
	void animate();
	void scale(int scale);
	void scale(int scaleX, int scaleY);
	void setTransparency(unsigned int rgb);
	void setAutoAnimate(bool val);
	void setLoopToBegin(bool loop);

private:

	int frames;
	unsigned int animationSpeed;
	int currentFrame;
	unsigned long lastAnimated;
	int frameIterator;
	bool loopToBeginning;
	bool autoAnimate;

	float scaleX;
	float scaleY;

	// represents the width / height of a frame
	int w;
	int h;

	// represents the actual surface's width / height
	int rasterWidth;
	int rasterHeight;

	GLuint texture;
	SDL_Surface* surface;
	GLenum texture_format;
	GLint  nOfColors;

};

#endif /* SPRITE2D_H_ */

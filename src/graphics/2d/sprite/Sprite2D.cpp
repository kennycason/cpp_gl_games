/*
 * Sprite2D.cpp
 *
 *  Created on: Jun 23, 2012
 *      Author: destructo
 *
 *      http://www.lonesock.net/soil.html
 */

#include "Sprite2D.h"

Sprite2D::Sprite2D(std::string fileName, int frames, unsigned int animationSpeed) {
	this->frames = frames;
	this->animationSpeed = animationSpeed;
	texture = 0;
	scaleX = 1.0f;
	scaleY = 1.0f;
	currentFrame = 0;
	frameIterator = 1;
	lastAnimated = SDL_GetTicks();
	autoAnimate = true;

	// load an image file directly as a new OpenGL texture
	texture = SOIL_load_OGL_texture(fileName.c_str(), SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

	// Typical Texture Generation Using Data From The Bitmap
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int miplevel = 0;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_WIDTH,
			&rasterWidth);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_HEIGHT,
			&rasterHeight);
	w = rasterWidth / frames;
	h = rasterHeight;

	//glTexImage2D( GL_TEXTURE_RECTANGLE_NV, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, &texture );
}

Sprite2D::~Sprite2D() {

}

void Sprite2D::draw() {
	glEnable(GL_TEXTURE_2D);
	// Make the sprite 2 times bigger (optional)
	glScalef(scaleX, scaleY, 0.0f);
	// handle angle
	//glMatrixMode(GL_TEXTURE);
	//glLoadIdentity();
	//glTranslatef(w / 2, h / 2, 0.0);
	//glRotatef(1, 0.0, 0.0, 1.0);
	//glTranslatef(- w / 2, - h / 2, 0.0);
	//glMatrixMode(GL_MODELVIEW);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glEnable(GL_BLEND);

	// Set the primitive color to white
	glColor3f(1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, texture);
	// Make the sprite 2 times bigger (optional)

	glBegin(GL_QUADS);

	float startX = 1.0f / frames * currentFrame;

	glTexCoord2f(startX, 0);
	glVertex3f(posX(), posY() + h, 0);

	glTexCoord2f(startX, 1);
	glVertex3f(posX(), posY(), 0);

	glTexCoord2f(startX + 1.0f / frames, 1);
	glVertex3f(posX() + w, posY(), 0);

	glTexCoord2f(startX + 1.0f / frames, 0);
	glVertex3f(posX() + w, posY() + h, 0);

	glEnd();

	if (autoAnimate) {
		animate();
	}
	glDisable(GL_TEXTURE_2D);
}

void Sprite2D::animate() {
	if (frames > 0) {
		if (SDL_GetTicks() - lastAnimated > animationSpeed) {
			lastAnimated = SDL_GetTicks();
			currentFrame += frameIterator;
			if (currentFrame >= frames) {
				if (loopToBeginning) {
					frameIterator = 1;
					currentFrame = 0;
				} else {
					frameIterator = -1;
					currentFrame = frames - 1;
				}
			} else if (currentFrame < 0) {
				frameIterator = 1;
				currentFrame = 0;
			}
		}
	}
}

void Sprite2D::setAutoAnimate(bool val) {
	this->autoAnimate = val;
}

void Sprite2D::setLoopToBegin(bool loop) {
	loopToBeginning = loop;
}

void Sprite2D::scale(int scale) {
	this->scaleX = (float) scale / 100.0;
	this->scaleY = (float) scale / 100.0;
}

void Sprite2D::scale(int scaleX, int scaleY) {
	this->scaleX = (float) scaleX / 100.0;
	this->scaleY = (float) scaleY / 100.0;
}

void Sprite2D::setTransparency(unsigned int rgb) {

}


/*
 * Drawable.h
 *
 *  Created on: Jul 17, 2012
 *      Author: destructo
 */

#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include "../Common.h"

class Drawable {
public:
	Drawable();
	virtual ~Drawable();

	virtual void draw() = 0;

	void translate(GLfloat x, GLfloat y, GLfloat z);
	void translate(GLfloat rot[]);
	GLfloat posX();
	GLfloat posY();
	GLfloat posZ();

	void rotate(GLfloat x, GLfloat y, GLfloat z);
	void rotate(GLfloat rot[]);
	GLfloat rotX();
	GLfloat rotY();
	GLfloat rotZ();

private:
	GLfloat pos[3];
	GLfloat rot[3];
};

#endif /* DRAWABLE_H_ */

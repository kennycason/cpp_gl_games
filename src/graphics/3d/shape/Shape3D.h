/*
 * Shape3D.h
 *
 *  Created on: Jun 26, 2012
 *      Author: destructo
 */

#ifndef SHAPE3D_H_
#define SHAPE3D_H_

#include "../../../Common.h"
#include "../../RGB.h"
#include "../../RGBA.h"

typedef struct Face {
	GLfloat* vertices;
	int dim;
	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat a;
} Face;

class Shape3D : public Drawable {
public:
	Shape3D(int numFaces);
	virtual ~Shape3D();

	Face getFace(int face);
	void setColor(GLfloat r, GLfloat g, GLfloat b);
	void setFaceColor(int face, GLfloat r, GLfloat g, GLfloat b);


protected:

	Face* faces;
	int numFaces;

private:

};



#endif /* SHAPE3D_H_ */

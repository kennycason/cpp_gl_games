/*
 * Square.h
 *
 *  Created on: Jun 21, 2012
 *      Author: destructo
 */

#ifndef SHAPE_2D_H_
#define SHAPE_2D_H_

#include "../../../Common.h"

class Shape2D : public Drawable {
public:
	Shape2D(int vertices, int radius);
	virtual ~Shape2D();

	int getVertices();
	void setColor(GLfloat r, GLfloat g, GLfloat b);
	int getRadius();


protected:
	int radius;

	GLfloat color[3];

private:
	int vertices;

};

#endif /* SHAPE_2D_H_ */

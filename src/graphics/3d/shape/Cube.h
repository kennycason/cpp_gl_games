/*
 * Cube.h
 *
 *  Created on: Jun 26, 2012
 *      Author: destructo
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "Shape3D.h"

class Cube : public Shape3D {
public:
	Cube(int dim);
	Cube(int dim, RGB*& colors);
	virtual ~Cube();
	virtual void draw();
	void setColor(int face, RGB& colors);

private:
	int dim;

	/*
	 * 0 - TOP
	 * 1 - BOTTOM
	 * 2 - FRONT
	 * 3 - BACK
	 * 4 - LEFT
	 * 5 - RIGHT
	 */
	RGB** colors;
};

#endif /* CUBE_H_ */

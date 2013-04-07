/*
 * Square.cpp
 *
 *  Created on: Jun 21, 2012
 *      Author: destructo
 */

#include "Square.h"

Square::Square(int radius) :
		Shape2D(4, radius) {
	this->dim = radius * 2;
}

Square::~Square() {

}

void Square::draw() {
	glTranslatef(posX(), posY(), 0);
	glColor3fv(color);
	glBegin(GL_QUADS);
		glVertex3f(0, 0, 0);
		glVertex3f(dim, 0, 0);
		glVertex3f(dim, dim, 0);
		glVertex3f(0, dim, 0);
	glEnd();
	//glLoadIdentity();
}



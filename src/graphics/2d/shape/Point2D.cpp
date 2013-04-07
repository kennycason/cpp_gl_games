/*
 * Point2D.cpp
 *
 *  Created on: Jul 16, 2012
 *      Author: destructo
 */

#include "Point2D.h"

Point2D::Point2D() :
	Shape2D(0, 0) {

}

Point2D::~Point2D() {
}


void Point2D::draw() {
	glTranslatef(posX(), posY(), posZ());
	glColor3fv(color);
	glBegin(GL_POINTS);
		glVertex2f(0.5f, 0.5f);
	glEnd();
	glLoadIdentity();
}


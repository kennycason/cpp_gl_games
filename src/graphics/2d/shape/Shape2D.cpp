/*
 * Shape2D.cpp
 *
 *  Created on: Jun 21, 2012
 *      Author: destructo
 */

#include "Shape2D.h"

Shape2D::Shape2D(int vertices, int radius) :
	Drawable() {
	this->vertices = vertices;
	this->radius = radius;
}

Shape2D::~Shape2D() {

}

int Shape2D::getVertices() {
	return vertices;
}

void Shape2D::setColor(GLfloat r, GLfloat g, GLfloat b) {
	this->color[0] = r;
	this->color[1] = g;
	this->color[2] = b;
}

int Shape2D::getRadius() {
	return radius;
}

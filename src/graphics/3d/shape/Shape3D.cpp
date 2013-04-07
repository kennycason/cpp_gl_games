/*
 * Shape3D.cpp
 *
 *  Created on: Jun 21, 2012
 *      Author: destructo
 */

#include "Shape3D.h"

Shape3D::Shape3D(int numFaces) :
		Drawable() {
	this->numFaces = numFaces;
	faces = new Face[numFaces];
	for(int i = 0; i < numFaces; i++) {
		faces[i].r = 1.0f;
		faces[i].g = 1.0f;
		faces[i].b = 1.0f;
	}
}

Shape3D::~Shape3D() {

}

Face Shape3D::getFace(int face) {
	return faces[face];
}

void Shape3D::setColor(GLfloat r, GLfloat g, GLfloat b) {
	for(int i = 0; i < numFaces; i++) {
		setFaceColor(i, r, g, b);
	}
}

void Shape3D::setFaceColor(int face, GLfloat r, GLfloat g, GLfloat b) {
	faces[face].r = r;
	faces[face].g = g;
	faces[face].b = b;
}



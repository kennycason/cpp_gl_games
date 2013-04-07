/*
 * Drawable.cpp
 *
 *  Created on: Jul 17, 2012
 *      Author: destructo
 */

#include "Drawable.h"

Drawable::Drawable() {
	rotate(0, 0, 0);
	translate(0, 0, 0);
}

Drawable::~Drawable() {

}

void Drawable::translate(GLfloat x, GLfloat y, GLfloat z) {
	pos[0] = x;
	pos[1] = y;
	pos[2] = z;
}

void Drawable::translate(GLfloat pos[]) {
	this->pos[0] = pos[0];
	this->pos[1] = pos[1];
	this->pos[2] = pos[2];
}

GLfloat Drawable::posX() {
	return pos[0];
}

GLfloat Drawable::posY() {
	return pos[1];
}

GLfloat Drawable::posZ() {
	return pos[2];
}

void Drawable::rotate(GLfloat x, GLfloat y, GLfloat z) {
	rot[0] = x;
	rot[1] = y;
	rot[2] = z;
}

void Drawable::rotate(GLfloat rot[]) {
	this->rot[0] = rot[0];
	this->rot[1] = rot[1];
	this->rot[2] = rot[2];
}

GLfloat Drawable::rotX() {
	return rot[0];
}

GLfloat Drawable::rotY() {
	return rot[1];
}

GLfloat Drawable::rotZ() {
	return rot[2];
}

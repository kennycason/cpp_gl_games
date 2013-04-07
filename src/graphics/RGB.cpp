/*
 * RGB.cpp
 *
 *  Created on: Jul 17, 2012
 *      Author: destructo
 */

#include "RGB.h"

RGB::RGB(GLuint rgb) {
	colors = new GLfloat[3];
	colors[0] = rgb & 0xFF0000;
	colors[1] = rgb & 0x00FF00;
	colors[2] = rgb & 0x0000FF;
}

RGB::RGB(GLfloat r, GLfloat g, GLfloat b) {
	colors = new GLfloat[3];
	colors[0] = r;
	colors[1] = g;
	colors[2] = b;
}

RGB::~RGB() {

}

GLuint RGB::rgb() {
	return  colors[0] * 0xFF0000 +
			colors[1] * 0x00FF00 +
			colors[2] * 0x0000FF;
}

GLfloat RGB::r() {
	return colors[0];
}

GLfloat RGB::g() {
	return colors[1];
}

GLfloat RGB::b() {
	return colors[2];
}

void RGB::rgb(GLuint colors) {
	r(colors & 0xFF0000);
	g(colors & 0x00FF00);
	b(colors & 0x0000FF);
}

void RGB::r(GLfloat r) {
	colors[0] = r;
}

void RGB::g(GLfloat g) {
	colors[1] = g;
}

void RGB::b(GLfloat b) {
	colors[2] = b;
}



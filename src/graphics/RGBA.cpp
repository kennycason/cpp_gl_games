/*
 * RGBA.cpp
 *
 *  Created on: Jul 17, 2012
 *      Author: destructo
 */

#include "RGBA.h"

RGBA::RGBA(GLuint rgba) {
	colors = new GLfloat[4];
	colors[0] = rgba & 0xFF000000;
	colors[1] = rgba & 0x00FF0000;
	colors[2] = rgba & 0x0000FF00;
	colors[3] = rgba & 0x000000FF;
}

RGBA::RGBA(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
	colors = new GLfloat[4];
	colors[0] = a;
	colors[1] = r;
	colors[2] = g;
	colors[3] = b;
}

RGBA::~RGBA() {

}

GLuint RGBA::rgba() {
	return  colors[0] * 0xFF000000 +
			colors[1] * 0x00FF0000 +
			colors[2] * 0x0000FF00 +
			colors[3] * 0x000000FF;
}

GLfloat RGBA::r() {
	return colors[1];
}

GLfloat RGBA::g() {
	return colors[2];
}

GLfloat RGBA::b() {
	return colors[3];
}

GLfloat RGBA::a() {
	return colors[0];
}

void RGBA::rgba(GLuint colors) {
	a(colors & 0xFF000000);
	r(colors & 0x00FF0000);
	g(colors & 0x0000FF00);
	b(colors & 0x000000FF);
}

void RGBA::r(GLfloat r) {
	colors[1] = r;
}

void RGBA::g(GLfloat g) {
	colors[2] = g;
}

void RGBA::b(GLfloat b) {
	colors[3] = b;
}

void RGBA::a(GLfloat a) {
	colors[0] = a;
}

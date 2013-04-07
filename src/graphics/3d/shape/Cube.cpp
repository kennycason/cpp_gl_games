/*
 * Cube.cpp
 *
 *  Created on: Jun 26, 2012
 *      Author: destructo
 */

#include "Cube.h"

Cube::Cube(int dim) :
		Shape3D(6) {
	this->dim = dim;
	this->colors = new RGB*[6];
	this->colors[0] = new RGB(0.0f, 0.0f, 1.0f); // top
	this->colors[1] = new RGB(0.0f, 1.0f, 0.0f); // bottom
	this->colors[2] = new RGB(0.0f, 1.0f, 1.0f); // front
	this->colors[3] = new RGB(1.0f, 0.0f, 0.0f); // back
	this->colors[4] = new RGB(1.0f, 0.0f, 1.0f); // left
	this->colors[5] = new RGB(1.0f, 1.0f, 0.0f); // right
}

Cube::Cube(int dim, RGB*& colors) :
		Shape3D(6) {
	this->dim = dim;
	this->colors = new RGB*[6];

	this->colors[0]->rgb(colors[0].rgb()); // top
	this->colors[1]->rgb(colors[1].rgb()); // bottom
	this->colors[2]->rgb(colors[2].rgb()); // front
	this->colors[3]->rgb(colors[3].rgb()); // back
	this->colors[4]->rgb(colors[4].rgb()); // left
	this->colors[5]->rgb(colors[5].rgb()); // right
}

Cube::~Cube() {
}

void Cube::draw() {
	glPushMatrix();

	glTranslatef(posX(), posY(), posZ());
	/*
	glBegin(GL_QUADS);
		glVertex3f(0, 0, 0);
		glVertex3f(100, 0, 0);
		glVertex3f(100, 100, 0);
		glVertex3f(0, 100, 0);
	glEnd();
*/

	glRotatef(rotX(), 1.0, 0.0, 0.0);
	glRotatef(rotY(), 0.0, 1.0, 0.0);
	glRotatef(rotZ(), 0.0, 0.0, 1.0);

	glBegin(GL_QUADS); // Start Drawing The Cube

	glColor3f(colors[0]->r(), colors[0]->g(), colors[0]->b()); // Set The Color To Green
	glVertex3f( dim, dim,-dim);          // Top Right Of The Quad (Top)
	glVertex3f(-dim, dim,-dim);          // Top Left Of The Quad (Top)
	glVertex3f(-dim, dim, dim);          // Bottom Left Of The Quad (Top)
	glVertex3f( dim, dim, dim);          // Bottom Right Of The Quad (Top)

	glColor3f(colors[1]->r(), colors[1]->g(), colors[1]->b()); // Set The Color To Orange
	glVertex3f( dim,-dim, dim);          // Top Right Of The Quad (Bottom)
	glVertex3f(-dim,-dim, dim);          // Top Left Of The Quad (Bottom)
	glVertex3f(-dim,-dim,-dim);          // Bottom Left Of The Quad (Bottom)
	glVertex3f( dim,-dim,-dim);          // Bottom Right Of The Quad (Bottom)

	glColor3f(colors[2]->r(), colors[2]->g(), colors[2]->b()); // Set The Color To Red
	glVertex3f( dim, dim, dim);          // Top Right Of The Quad (Front)
	glVertex3f(-dim, dim, dim);          // Top Left Of The Quad (Front)
	glVertex3f(-dim,-dim, dim);          // Bottom Left Of The Quad (Front)
	glVertex3f( dim,-dim, dim);          // Bottom Right Of The Quad (Front)

	glColor3f(colors[3]->r(), colors[3]->g(), colors[3]->b()); // Set The Color To Yellow
	glVertex3f( dim,-dim,-dim);          // Bottom Left Of The Quad (Back)
	glVertex3f(-dim,-dim,-dim);          // Bottom Right Of The Quad (Back)
	glVertex3f(-dim, dim,-dim);          // Top Right Of The Quad (Back)
	glVertex3f( dim, dim,-dim);          // Top Left Of The Quad (Back)

	glColor3f(colors[4]->r(), colors[4]->g(), colors[4]->b()); // Set The Color To Blue
	glVertex3f(-dim, dim, dim);          // Top Right Of The Quad (Left)
	glVertex3f(-dim, dim,-dim);          // Top Left Of The Quad (Left)
	glVertex3f(-dim,-dim,-dim);          // Bottom Left Of The Quad (Left)
	glVertex3f(-dim,-dim, dim);          // Bottom Right Of The Quad (Left)

	glColor3f(colors[5]->r(), colors[5]->g(), colors[5]->b()); // Set The Color To Violet
    glVertex3f( dim, dim,-dim);          // Top Right Of The Quad (Right)
    glVertex3f( dim, dim, dim);          // Top Left Of The Quad (Right)
    glVertex3f( dim,-dim, dim);          // Bottom Left Of The Quad (Right)
    glVertex3f( dim,-dim,-dim);          // Bottom Right Of The Quad (Right)

	glEnd(); // Done Drawing The Quad
	glPopMatrix();

}


void Cube::setColor(int face, RGB& colors) {
	this->colors[face]->r(colors.r());
	this->colors[face]->g(colors.g());
	this->colors[face]->b(colors.b());
}

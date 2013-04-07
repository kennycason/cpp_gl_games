/*
 * RGBA.h
 *
 *  Created on: Jul 17, 2012
 *      Author: destructo
 */

#ifndef RGBA_H_
#define RGBA_H_

#include "../Common.h"

class RGBA {
public:
	RGBA(GLuint rgba);
	RGBA(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	virtual ~RGBA();

	GLfloat r();
	GLfloat g();
	GLfloat b();
	GLfloat a();
	GLuint rgba();

	void r(GLfloat r);
	void g(GLfloat g);
	void b(GLfloat b);
	void a(GLfloat a);
	void rgba(GLuint colors);

private:
	GLfloat* colors;

};

#endif /* RGBA_H_ */

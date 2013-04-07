/*
 * RGB.h
 *
 *  Created on: Jul 17, 2012
 *      Author: destructo
 */

#ifndef RGB_H_
#define RGB_H_

#include "../Common.h"

class RGB {
public:
	RGB(GLuint rgb);
	RGB(GLfloat r, GLfloat g, GLfloat b);
	virtual ~RGB();

	GLfloat r();
	GLfloat g();
	GLfloat b();
	GLuint rgb();

	void r(GLfloat r);
	void g(GLfloat g);
	void b(GLfloat b);
	void rgb(GLuint colors);

private:
	GLfloat* colors;

};

#endif /* RGB_H_ */

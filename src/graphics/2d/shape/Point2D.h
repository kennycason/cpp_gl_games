/*
 * Point2D.h
 *
 *  Created on: Jul 16, 2012
 *      Author: destructo
 */

#ifndef POINT2D_H_
#define POINT2D_H_

#include "Shape2D.h"

class Point2D : public Shape2D {
public:
	Point2D();
	virtual ~Point2D();
	virtual void draw();
};

#endif /* POINT2D_H_ */

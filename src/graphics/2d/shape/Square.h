/*
 * Square.h
 *
 *  Created on: Jun 21, 2012
 *      Author: destructo
 */

#ifndef SQUARE_H_
#define SQUARE_H_

#include "Shape2D.h"

class Square : public Shape2D {
public:
	Square(int radius);
	virtual ~Square();

	virtual void draw();

private:
	int dim;

};

#endif /* SQUARE_H_ */

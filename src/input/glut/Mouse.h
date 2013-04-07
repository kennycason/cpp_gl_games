/*
 * Mouse.h
 *
 *  Created on: Jun 22, 2012
 *      Author: destructo
 */

#ifndef MOUSE_H_
#define MOUSE_H_

#include "../../Common.h"

class Mouse : public Observable {
public:
	Mouse();
	virtual ~Mouse();
	bool isLeftClick();
	bool isRightClick();
	bool isMiddleClick();
	bool isScrollUp();
	bool isScrollDown();
	int getX();
	int getY();

	void clickEventHandler(int button, int state, int x, int y);
	void scrollEventHandler(int button, int dir, int x, int y);
private:

	 bool* buttons;
	 int scrollState;

	 int x;
	 int y;
};

#endif /* MOUSE_H_ */

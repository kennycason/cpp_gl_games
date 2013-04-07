/*
 * Mouse.cpp
 *
 *  Created on: Jun 22, 2012
 *      Author: destructo
 */

#include "Mouse.h"

Mouse::Mouse() {
	scrollState = 0;
	buttons = new bool[5];
	for(int i = 0; i < 5; i++) {
		buttons[i] = true;
	}
}

Mouse::~Mouse() {

}

bool Mouse::isLeftClick() {
	return !buttons[GLUT_LEFT_BUTTON];
}

bool Mouse::isRightClick() {
	return !buttons[GLUT_RIGHT_BUTTON];
}

bool Mouse::isMiddleClick() {
	return !buttons[GLUT_MIDDLE_BUTTON];
}

bool Mouse::isScrollUp() {
	bool ret = scrollState > 0;
	if(ret) {
		scrollState = 0;
	}
	return ret;
}

bool Mouse::isScrollDown() {
	bool ret = scrollState < 0;
	if(ret) {
		scrollState = 0;
	}
	return ret;
}

int Mouse::getX() {
	return x;
}

int Mouse::getY() {
	return y;
}

void Mouse::clickEventHandler(int button, int state, int x, int y) {
	this->x = x;
	this->y = y;

	scrollState = 0;
	// std::cout << "scroll button " << button << " state " << state << " x: " << x << " y " << y << std::endl;
	for(int i = 0; i < 3; i++) {
		buttons[i] = true; 	// rest states, else have problem when both mouse keys are pressed at the same time
	}
	buttons[button] = state;

	if(button > 2) {
		scrollEventHandler(button, state, x, y);
	}

}

void Mouse::scrollEventHandler(int button, int state, int x, int y) {
	this->x = x;
	this->y = y;
	// std::cout << "scroll button " << button << " state " << state << " x: " << x << " y " << y << std::endl;

	scrollState = 0;
	if(button == 3 && state == 1) { // up
		// std::cout << "scroll up" << std::endl;
		scrollState = 1;
	} else if(button == 4 && state == 1) { // down
		// std::cout << "scroll down" << std::endl;
		scrollState = -1;
	}
}


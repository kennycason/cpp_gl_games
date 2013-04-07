/*
 * GLUTKeyBoard.cpp
 *
 *  Created on: Jun 22, 2012
 *      Author: destructo
 */

#include "GLUTKeyBoard.h"

GLUTKeyBoard::GLUTKeyBoard() {
	keyStates = new bool[256];
	keySpecialStates = new bool[256];

	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

	for(int i = 0; i < 256; i++) {
		keyStates[i] = false;
		keySpecialStates[i] = false;
	}
}

GLUTKeyBoard::~GLUTKeyBoard() {

}

bool GLUTKeyBoard::isKeyPressed(unsigned char key) {
	// std::cout << key << " checking, key = "  << (int) key << " ? " << keyStates[(int)key] << std::endl;
	return keyStates[key];
}

bool GLUTKeyBoard::isKeyPressed(int key) {
	return keySpecialStates[key];
}

void GLUTKeyBoard::keyUp (unsigned char key, int x, int y) {
	// std::cout << key << " up, key = "  << (int) key << std::endl;
	keyStates[key] = false;
	notifyObservers();
}

void GLUTKeyBoard::keyDown(unsigned char  key, int x, int y) {
	// std::cout << key << " down, key = " << (int) key  << std::endl;
	keyStates[(int) key] = true;
	notifyObservers();
}

void GLUTKeyBoard::keySpecialUp(int key, int x, int y) {
	 // std::cout << key << " up" << std::endl;
	 keySpecialStates[key] = false;
	notifyObservers();
}

void GLUTKeyBoard::keySpecialDown (int key, int x, int y) {
	 // std::cout << key << " down" << std::endl;
	 keySpecialStates[key] = true;
	 notifyObservers();
}


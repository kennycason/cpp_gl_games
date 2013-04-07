/*
 * KeyBoard.h
 *
 *  Created on: Jun 22, 2012
 *      Author: destructo
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "../../Common.h"


class GLUTKeyBoard : public Observable {
public:
	GLUTKeyBoard();
	virtual ~GLUTKeyBoard();
	bool isKeyPressed(unsigned char key);
	bool isKeyPressed(int key);

	void keyDown(unsigned char key, int x, int y);
	void keyUp(unsigned char key, int x, int y);
	void keySpecialDown(int key, int x, int y);
	void keySpecialUp(int key, int x, int y);

private:

	 bool* keyStates;
	 bool* keySpecialStates;

};

#endif /* KEYBOARD_H_ */

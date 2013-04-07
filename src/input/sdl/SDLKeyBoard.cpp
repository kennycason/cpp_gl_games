/*
 * SDLSDLKeyBoard.cpp
 *
 *  Created on: Jun 23, 2012
 *      Author: destructo
 */

#include "SDLKeyBoard.h"


SDLKeyBoard::SDLKeyBoard() {
    clear();
    SDL_EnableKeyRepeat(0,0);
}

SDLKeyBoard::~SDLKeyBoard() {
	delete [] keys;
	delete [] keysPressedTime;
}

bool SDLKeyBoard::isKeyPressed(int key) {
    if(keys[key]) {
        return true;
    }
    return false;
}

void SDLKeyBoard::keyPressed(SDLKey key) {
    keys[key] = true;
    keysPressedTime[key] = SDL_GetTicks();
    notifyObservers();
}

void SDLKeyBoard::keyReleased(SDLKey key) {
    keys[key] = false;
    keysPressedTime[key] = SDL_GetTicks();
    notifyObservers();
}

void SDLKeyBoard::clear() {
    for(int i = 0; i < SDLKeyBoard_MAX_KEYS; i++ ) {
        keys[i] = false;
        keysPressedTime[i]= 0;
    }
}

bool SDLKeyBoard::isCombo(std::vector<int> keys) {
    for(Uint16 i = 0; i < keys.size(); i++) {
        if(!isKeyPressed(keys[i])) {
            return false;
        }
    }
    return true;
}

bool SDLKeyBoard::isSequentialCombo(std::vector<int> keys) {
    Uint32 lastKeyTime = 0;
    for(Uint16 i = 0; i < keys.size(); i++) {
        if(!(isKeyPressed(keys[i]) && keysPressedTime[keys[i]] > lastKeyTime)) {
            return false;
        }
        lastKeyTime = keysPressedTime[keys[i]];
    }
    return true;
}

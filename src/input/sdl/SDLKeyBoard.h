/*
 * SDLSDLKeyBoard.h
 *
 *  Created on: Jun 23, 2012
 *      Author: destructo
 */

#ifndef SDLKeyBoard_H_
#define SDLKeyBoard_H_

#include "../../Common.h"

#define SDLKeyBoard_MAX_KEYS 322

class SDLKeyBoard : public Observable {
public:
    SDLKeyBoard();
    virtual ~SDLKeyBoard();
    void poll();
    bool isKeyPressed(int key);
    void keyPressed(SDLKey key);
    void keyReleased(SDLKey key);
    bool isCombo(std::vector<int> keys);
    bool isSequentialCombo(std::vector<int> keys);
    void clear();

private:
    bool keys[SDLKeyBoard_MAX_KEYS];  // 322 is the number of SDLK_DOWN events, 0 for not pressed, 1 for pressed
    Uint32 keysPressedTime[SDLKeyBoard_MAX_KEYS];  // the time each key was pressed

};

#endif /* SDLKeyBoard_H_ */

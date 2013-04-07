/*
 * Observer.h
 *
 *  Created on: Jun 22, 2012
 *      Author: destructo
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

#include "Observable.h"

class Observable;
class Observer {
    public:
		virtual ~Observer() {};
        virtual void notify(Observable* o) = 0;
};

#endif /* OBSERVER_H_ */

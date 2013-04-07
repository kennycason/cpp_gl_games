/*
 * Observable.h
 *
 *  Created on: Jun 22, 2012
 *      Author: destructo
 */

#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include "../Common.h"


class Observer;
class Observable {
public:
	Observable();
	~Observable();
    void addObserver(Observer& o);
    void removeObserver(Observer& o);
    void notifyObservers();
    void trigger();

private:
    std::set<Observer*> observers;
};

#endif /* OBSERVABLE_H_ */

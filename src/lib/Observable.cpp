/*
 * Observable.cpp
 *
 *  Created on: Jun 22, 2012
 *      Author: destructo
 */

#include "Observable.h"

Observable::Observable() {

}

Observable::~Observable() {
}

void Observable::addObserver(Observer& o) {
    observers.insert(&o);
}

void Observable::removeObserver(Observer& o) {
    observers.erase(&o);
}

void Observable::notifyObservers() {
    std::set<Observer*>::iterator itr;
    for ( itr = observers.begin(); itr != observers.end(); itr++ ) {
    	(*itr)->notify(this);
    }
}

// TEST METHOD TO TRIGGER
// IN THE REAL SCENARIO THIS IS NOT REQUIRED
void Observable::trigger() {
    notifyObservers();
}


#include "Engine.h"

int main(int argc, char** argv) {
	Engine* e = new Engine();
	while(1) {

		e->events();
		e->logic();
		e->render();

	}
	e->quit(0);
	return 0;
}

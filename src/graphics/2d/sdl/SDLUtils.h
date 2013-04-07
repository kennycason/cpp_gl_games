/*
 * SDLUtils.h
 *
 *  Created on: Jun 23, 2012
 *      Author: destructo
 */

#ifndef SDLUTILS_H_
#define SDLUTILS_H_

#include "../../../Common.h"

class SDLUtils {
public:

		/*
		* Return the pixel value at (x, y)
		* NOTE: The surface must be locked before calling this!
		* Taken from SDL documentation.
		*/
		static Uint32 getPixel(SDL_Surface *surface, int x, int y)
		{
			int bpp = surface->format->BytesPerPixel;
			/* Here p is the address to the pixel we want to retrieve */
			Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

			switch(bpp) {
			case 1:
				return *p;

			case 2:
				return *(Uint16 *)p;

			case 3:
				if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
					return p[0] << 16 | p[1] << 8 | p[2];
				else
					return p[0] | p[1] << 8 | p[2] << 16;

			case 4:
				return *(Uint32 *)p;

			default:
				return 0;       /* shouldn't happen, but avoids warnings */
			}
		};

		static int setPixel(SDL_Surface* surface, int x, int y, Uint32 pixel) {
		    if(surface == NULL) {
		         std::cout << "Failed to set pixel, surface not initialized!" << std::endl;
		         return -1;
		     }
		    int bpp = surface->format->BytesPerPixel;
		    /* p is the address to the pixel we want to set */
		    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
		    switch(bpp) {
		        case 1:
		            *p = pixel;
		            break;
		        case 2:
		            *(Uint16 *)p = pixel;
		            break;
		        case 3:
		            if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
		                p[0] = (pixel >> 16) & 0xff;
		                p[1] = (pixel >> 8) & 0xff;
		                p[2] = pixel & 0xff;
		            } else {
		                p[0] = pixel & 0xff;
		                p[1] = (pixel >> 8) & 0xff;
		                p[2] = (pixel >> 16) & 0xff;
		            }
		            break;
		        case 4:
		            *(Uint32 *)p = pixel;
		            break;
		    }
		    return 0;
		};

private:
	SDLUtils() {

	}
	virtual ~SDLUtils() {

	}
};

#endif /* SDLUTILS_H_ */

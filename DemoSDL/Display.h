#ifndef DISPLAY__H_
#define DISPLAY__H_

#include"CommonFunction.h"

SDL_Texture* LoadImageTexture(string path, SDL_Renderer* screen) {
	SDL_Texture* new_texture = NULL;

	SDL_Surface* load_surface = IMG_Load(path.c_str());
	new_texture = SDL_CreateTextureFromSurface(screen, load_surface);
	SDL_FreeSurface(load_surface);

	return new_texture;
}

bool CheckCollision(const SDL_Rect& objectA, const SDL_Rect& objectB)
{
    int leftA = objectA.x;
    int rightA = objectA.x + objectA.w;
    int topA = objectA.y;
    int botA = objectA.y + objectA.h;

    int leftB = objectB.x;
    int rightB = objectB.x + objectB.w;
    int topB = objectB.y;
    int botB = objectB.y + objectB.h;

    if (leftA > leftB && leftA < rightB)
    {
        if (topA > topB && topA < botB)
        {
            return true;
        }
    }

    if (leftA > leftB && leftA < rightB)
    {
        if (botA > topB && botA < botB)
        {
            return true;
        }
    }

    if (rightA > leftB && rightA < rightB)
    {
        if (topA > topB && topA < botB)
        {
            return true;
        }
    }

    if (rightA > leftB && rightA < rightB)
    {
        if (botA > topB && botA < botB)
        {
            return true;
        }
    }

    if (leftB > leftA && leftB < rightA)
    {
        if (topB > topA && topB < botA)
        {
            return true;
        }
    }

    if (leftB > leftA && leftB < rightA)
    {
        if (botB > topA && botB < botA)
        {
            return true;
        }
    }

    if (rightB > leftA && rightB < rightA)
    {
        if (topB > topA && topB < botA)
        {
            return true;
        }
    }

    if (rightB > leftA && rightB < rightA)
    {
        if (botB > topA && botB < botA)
        {
            return true;
        }
    }

    if (topA == topB && rightA == rightB && botA == botB)
    {
        return true;
    }

    return false;
}


#endif // !DISPLAY__H_

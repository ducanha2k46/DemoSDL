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

/*bool CheckCollision(const SDL_Rect bird_check, const SDL_Rect block_check) {
	int bird_top_left_x = bird_check.x;
	int bird_top_left_y = bird_check.y;
	int bird_top_right_x = bird_check.x + bird_check.w;
	int bird_top_right_y = bird_check.y;
	int bird_bottom_left_x = bird_check.x;
	int bird_bottom_left_y = bird_check.y + bird_check.h;
	int bird_bottom_right_x = bird_check.x + bird_check.w;
	int bird_bottom_right_y = bird_check.y + bird_check.h;

	int block_on_top_left_x = block_check.x;
	int block_on_top_left_y = 0;
	//int block_on_top_right_x = block_check.x + block_check.w;
	//int block_on_top_right_y = block_check.y;
	int block_below_bottom_left_x = block_check.x;
	int block_below_bottom_left_y = block_check.y + block_check.h;
	int block_below_bottom_right_x = block_check.x + block_check.w;
	int block_below_bottom_right_y = block_check.y + block_check.h;

	if () {
		return false;
	}
}*/

bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2)
{
    int left_a = object1.x;
    int right_a = object1.x + object1.w;
    int top_a = object1.y;
    int bottom_a = object1.y + object1.h;

    int left_b = object2.x;
    int right_b = object2.x + object2.w;
    int top_b = object2.y;
    int bottom_b = object2.y + object2.h;

    if (left_a > left_b && left_a < right_b)
    {
        if (top_a > top_b && top_a < bottom_b)
        {
            return true;
        }
    }

    if (left_a > left_b && left_a < right_b)
    {
        if (bottom_a > top_b && bottom_a < bottom_b)
        {
            return true;
        }
    }

    if (right_a > left_b && right_a < right_b)
    {
        if (top_a > top_b && top_a < bottom_b)
        {
            return true;
        }
    }

    if (right_a > left_b && right_a < right_b)
    {
        if (bottom_a > top_b && bottom_a < bottom_b)
        {
            return true;
        }
    }

    if (left_b > left_a && left_b < right_a)
    {
        if (top_b > top_a && top_b < bottom_a)
        {
            return true;
        }
    }

    if (left_b > left_a && left_b < right_a)
    {
        if (bottom_b > top_a && bottom_b < bottom_a)
        {
            return true;
        }
    }

    if (right_b > left_a && right_b < right_a)
    {
        if (top_b > top_a && top_b < bottom_a)
        {
            return true;
        }
    }

    if (right_b > left_a && right_b < right_a)
    {
        if (bottom_b > top_a && bottom_b < bottom_a)
        {
            return true;
        }
    }

    if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
    {
        return true;
    }

    return false;
}


#endif // !DISPLAY__H_

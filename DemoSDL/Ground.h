#ifndef GROUND__H_
#define GROUND__H_
#include"CommonFunction.h"
#include"Display.h"

class Ground
{
public:
	SDL_Texture *ground_;
	SDL_Rect ground_rect;
	void Show_ground(SDL_Renderer* des);
	void Set_up_ground(SDL_Renderer* des);
private:

};

void Ground::Set_up_ground(SDL_Renderer* des)
{
	ground_ = LoadImageTexture("Image/Ground.png", des);
	ground_rect = { 0,552,1200,150 };
}

void Ground::Show_ground(SDL_Renderer* des) {
	SDL_RenderCopy(des, ground_, NULL, &ground_rect);
}

#endif // !PLATFORM__H_

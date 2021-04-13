#ifndef PLATFORM__H_
#define PLATFORM__H_
#include"CommonFunction.h"
#include"Display.h"

class Flatform
{
public:
	SDL_Texture *flatform_;
	SDL_Rect flatform_rect;
	void Show_flatform(SDL_Renderer* des);
	void Set_up_flatform(SDL_Renderer* des);
private:

};

void Flatform::Set_up_flatform(SDL_Renderer* des)
{
	flatform_ = LoadImageTexture("Image/Flatform.png", des);
	flatform_rect = { 0,552,1200,150 };
}

void Flatform::Show_flatform(SDL_Renderer* des) {
	SDL_RenderCopy(des, flatform_, NULL, &flatform_rect);
}

#endif // !PLATFORM__H_

#ifndef MAINOBJECT__H_
#define MAINOBJECT__H_

#include"CommonFunction.h"
#include"Display.h"

class Bird	
{
public:
	SDL_Texture* t_up, * t_down;
	int  height_frame_, width_frame_, status_, current_frame_;
	void set_up(SDL_Renderer* des);
	void Show(SDL_Renderer* des, SDL_Rect rect_);
private:
	 
};

void Bird::set_up(SDL_Renderer* des) {
	t_up = LoadImageTexture("Image/Up.png", des);
	t_down = LoadImageTexture("Image/Down.png", des);
	height_frame_ = 77;
	width_frame_ = 77;
	status_ = 1;
	current_frame_ = 0;

}

void Bird::Show(SDL_Renderer* des, SDL_Rect rect_) {
	SDL_Rect show_rect_ = { 0,77 * current_frame_,77,77 };
	if (status_ == 1) SDL_RenderCopy(des, t_up, &show_rect_, &rect_);
	else if (status_ == 0) SDL_RenderCopy(des, t_down, &show_rect_, &rect_);
}


#endif // !MAINOBJECT__H_

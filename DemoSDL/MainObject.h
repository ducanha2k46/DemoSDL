#ifndef MAINOBJECT__H_
#define MAINOBJECT__H_

#include"CommonFunction.h"
#include"Display.h"

class Bird	
{
public:
	SDL_Texture* t_up, * t_down;
	int  height_frame_, width_frame_, status_, current_frame_, bird_width_, bird_height_;
	void set_up(SDL_Renderer* des);
	void Show(SDL_Renderer* des, SDL_Rect rect_);
	void show_dead_(SDL_Renderer* des,SDL_Rect rect_);
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
	SDL_Rect show_rect_ = { 0,0,0,0 };
	if (status_ == 1) {
		if (current_frame_ == 0) show_rect_ = { 0,0,69,49 };
		else if (current_frame_ == 1) show_rect_ = { 0,52,71,53 };
		else if (current_frame_ == 2) show_rect_ = { 0,107,71,53 };
		else if (current_frame_ == 3) show_rect_ = { 0,169,66,55 };
		else if (current_frame_ == 4) show_rect_ = { 0,230,60,61 };
		else if (current_frame_ == 5) show_rect_ = { 0,300,54,67 };


		SDL_RenderCopy(des, t_up, &show_rect_, &rect_);
	}
	if (status_ == 0) {
		if (current_frame_ == 0) show_rect_ = { 0,0,69,49 };
		else if (current_frame_ == 1) show_rect_ = { 0,50,66,54 };
		else if (current_frame_ == 2) show_rect_ = { 0,120,61,60 };
		else if (current_frame_ == 3) show_rect_ = { 0,185,55,67 };
		else if (current_frame_ == 4) show_rect_ = { 0,258,53,71 };
		else if (current_frame_ == 5) show_rect_ = { 0,339,49,69 };


		SDL_RenderCopy(des, t_down, &show_rect_, &rect_);
	}

	bird_height_ = show_rect_.h;
	bird_width_ = show_rect_.w;
}

void Bird::show_dead_(SDL_Renderer* des, SDL_Rect rect_) {
	SDL_Rect show_rect_;
	if (current_frame_ == 0) show_rect_ = { 0,0,60,49 };
	else if (current_frame_ == 1) show_rect_ = { 0,50,66,54 };
	else if (current_frame_ == 2) show_rect_ = { 0,120,61,60 };
	else if (current_frame_ == 3) show_rect_ = { 0,185,55,67 };
	else if (current_frame_ == 4) show_rect_ = { 0,258,53,71 };
	else if (current_frame_ == 5) show_rect_ = { 0,339,49,69 };


	bird_height_ = show_rect_.h;
	bird_width_ = show_rect_.w;
	SDL_RenderCopy(des, t_down, &show_rect_, &rect_);
}

#endif // !MAINOBJECT__H_

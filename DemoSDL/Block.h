#ifndef BLOCK__H_
#define BLOCK__H_
#include"CommonFunction.h"
#include"Display.h"

class Block
{
public:
	SDL_Texture* block_on, * block_below;
	SDL_Rect block_rect, rect_fix;
	void Show_block(SDL_Renderer* des);
	void Set_up_block(SDL_Renderer* des);
private:

};

void Block::Set_up_block(SDL_Renderer* des) {
	block_on = LoadImageTexture("Image/On.png", des);
	block_below = LoadImageTexture("Image/Below.png", des);
	block_rect.w = 86;
	block_rect.h = 400;
	block_rect.y = rand();
	cerr << block_rect.y<<endl;
	block_rect.y = -(block_rect.y % 100) -100;
	block_rect.x = 1286;
}

void Block::Show_block(SDL_Renderer* des) {
	rect_fix = block_rect;
	rect_fix.y = block_rect.y + 555;
	SDL_RenderCopy(des, block_on, NULL, &block_rect);
	SDL_RenderCopy(des, block_below, NULL, &rect_fix);
}




#endif // !BLOCK__H_

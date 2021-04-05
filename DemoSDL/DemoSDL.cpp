#include"CommonFunction.h"
#include"MainObject.h"
#include"Display.h"
#include"Block.h"


SDL_Texture* gBackground;

bool init() {
	bool check = true;
	int ret = SDL_Init(SDL_INIT_VIDEO);	
	if (ret < 0) {
		return false;
	}
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	gWindow = SDL_CreateWindow("Flappy Bird", 
								SDL_WINDOWPOS_UNDEFINED, 
								SDL_WINDOWPOS_UNDEFINED, 
								SCREEN_WIGHT, SCREEN_HIGHT, 
								SDL_WINDOW_SHOWN);

	if (gWindow == NULL) {
		check = false;
	}
	else {
		gScreen = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
		if (gScreen == NULL) {
			check = false;
		}
		else {
			SDL_SetRenderDrawColor(gScreen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) && imgFlags)) {
				check = true;
			}
		}
	}
}
void LoadBackGround() {
	gBackground = LoadImageTexture("Image/BackGround.png", gScreen);
}


void Close() {
	SDL_DestroyRenderer(gScreen);
	gScreen = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* argv[]) {
	if (init() == false) return -1;

	SDL_SetRenderDrawColor(gScreen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
	LoadBackGround();

	Block gBlock[20];
	int add_ = 250;
	for (int i = 0; i < 20; i++) {
		gBlock[i].Set_up_block(gScreen);
		gBlock[i].block_rect.x = gBlock[i].block_rect.x + add_ * i;
	}


	SDL_Rect screen_rect = { 0,0,1200,672 };
	srand(time(NULL));
	
	Bird gBird;
	gBird.set_up(gScreen);
	int y_bird = 200;
	bool quit = false;
	int animation_bird = 0;
	while (!quit) {
		while (SDL_PollEvent(&gEvent) != 0)
		{
			if (gEvent.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		SDL_RenderClear(gScreen);

		SDL_RenderCopy(gScreen, gBackground, NULL, &screen_rect);

		if (gEvent.type == SDL_QUIT) quit = true;

		if (gEvent.type == SDL_KEYDOWN && gEvent.key.keysym.sym == SDLK_ESCAPE) quit = true;

		if (gEvent.type == SDL_KEYDOWN) {
			switch (gEvent.key.keysym.sym) {
			case SDLK_ESCAPE:
				break;
			case SDLK_UP: {
				if (gBird.status_ == 0) {
					gBird.current_frame_ = 0;
					gBird.status_ = 1;
					animation_bird = 0;
					break;
				}

			}
			}
		}

		animation_bird++; 
		if (animation_bird >= 84) gBird.status_ = 0;
		if (gBird.status_ == 1) {
			gBird.current_frame_ = animation_bird / 14;
		}
		else
			if (animation_bird <= 168) {
				gBird.current_frame_ = (animation_bird / 14) - 6;
			}
			else gBird.current_frame_ = 5;

		if (gBird.status_ == 0) y_bird = y_bird + 1;
		else y_bird = y_bird - 1;


		gBird.Show(gScreen, { 200,y_bird,77,77 });

		for (int i = 0; i < 20; i++) {
			if (CheckCollision({ 200,y_bird,77,77 }, gBlock[i].block_rect)) {
				SDL_Delay(5000);
			}
		}



		for (int i = 0; i < 20; i++) {
			gBlock[i].block_rect.x--;
			gBlock[i].Show_block(gScreen);
		}
		SDL_Delay(4);
		SDL_RenderPresent(gScreen);
	}  
	Close();
	return 0;
}
#include"CommonFunction.h"
#include"MainObject.h"
#include"Display.h"
#include"Block.h"
#include"Ground.h"
#include"Music.h"

SDL_Texture* gBackground,* gBackGroundEnd,* gBackGroundBegin,* gBackGroundBeginStart, * gBackGroundBeginQuit, * gScore;
SDL_Texture* gOne,* gTwo,* gThree,* gFour,* gFive,* gSix,* gSeven,* gEight,* gNine,* gZero;

Mix_Music* gMusic = NULL; 
Mix_Chunk* gCollision, * gDie, * gPoint, * gSwooshing, * gWing;

Block gBlock[45];
Ground gGround[20];


bool Check_gBlock = false;
bool Check_gGround = false;
int point = 0;
bool Check_sound = false;



bool init() {
	bool check = true;
	int ret = SDL_INIT_VIDEO;
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
			SDL_SetRenderDrawColor(gScreen, 
				RENDER_DRAW_COLOR, 
				RENDER_DRAW_COLOR, 
				RENDER_DRAW_COLOR, 
				RENDER_DRAW_COLOR);
			int imgFlags = IMG_INIT_PNG;

			if (!(IMG_Init(imgFlags) && imgFlags)) {
				check = false;
			}

			if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1){
			
				check = false;
			}

			if (TTF_Init() == -1) {
				check = false;
			}
			

		}
	}
	return check;
}

void LoadBackGround() {
	//Load Back
	gBackground = LoadImageTexture("Image/BackGround.png", gScreen);
	gBackGroundEnd = LoadImageTexture("Image/BackGround_End.png", gScreen);
	gBackGroundBegin = LoadImageTexture("Image/BackGround_Begin.png", gScreen);
	gBackGroundBeginStart = LoadImageTexture("Image/BackGround_Begin_Start.png", gScreen);
	gBackGroundBeginQuit = LoadImageTexture("Image/BackGround_Begin_Quit.png", gScreen);

	//Load Score
	gScore = LoadImageTexture("Image/Score.png", gScreen);
}

void LoadMixSound() {
	gCollision = LoadMixChunk("Mixer/Collision.wav");
	gDie = LoadMixChunk("Mixer/Die.wav");
	gPoint = LoadMixChunk("Mixer/Point.wav");
	gSwooshing = LoadMixChunk("Mixer/Swooshing.wav");
	gWing = LoadMixChunk("Mixer/Wing.wav");
}

void LoadBlock() {
	int add_ = rand();
	add_ = (add_ % 100) + 250;
	for (int i = 0; i < 45; i++) {
		gBlock[i].Set_up_block(gScreen);
		gBlock[i].block_rect.x = gBlock[i].block_rect.x + add_ * i;
	}

}

void LoadGround() {
	for (int i = 0; i < 20; i++) {
		gGround[i].Set_up_ground(gScreen);
		gGround[i].ground_rect.x = gGround[i].ground_rect.x + 1200 * i;
	}
}

void LoadPoint(){
	gZero = LoadImageTexture("Image/0.png", gScreen);
	gOne = LoadImageTexture("Image/1.png", gScreen);
	gTwo = LoadImageTexture("Image/2.png", gScreen);
	gThree = LoadImageTexture("Image/3.png", gScreen);
	gFour = LoadImageTexture("Image/4.png", gScreen);
	gFive = LoadImageTexture("Image/5.png", gScreen);
	gSix = LoadImageTexture("Image/6.png", gScreen);
	gSeven = LoadImageTexture("Image/7.png", gScreen);
	gEight = LoadImageTexture("Image/8.png", gScreen);
	gNine = LoadImageTexture("Image/9.png", gScreen);
}

void Point(int point,bool check) {
	if (point < 10) {
		if (point == 0) {
			SDL_Rect point_rect = { 1050,600,44,49 };
			if (check == true) point_rect.x += 45;
			SDL_RenderCopy(gScreen, gZero, NULL, &point_rect);
		}

		if (point == 1) {
			SDL_Rect point_rect = { 1050,600,36,48 };
			if (check == true) point_rect.x += 45;
			SDL_RenderCopy(gScreen, gOne, NULL, &point_rect);
		}

		if (point == 2) {
			SDL_Rect point_rect = { 1050,600,42,48 };
			if (check == true) point_rect.x += 45;
			SDL_RenderCopy(gScreen, gTwo, NULL, &point_rect);
		}
		if (point == 3) {
			SDL_Rect point_rect = { 1050,600,42,48 };
			if (check == true) point_rect.x += 45;
			SDL_RenderCopy(gScreen, gThree, NULL, &point_rect);
		}

		if (point == 4) {
			SDL_Rect point_rect = { 1050,600,44,48 };
			if (check == true) point_rect.x += 45;
			SDL_RenderCopy(gScreen, gFour, NULL, &point_rect);
		}

		if (point == 5) {
			SDL_Rect point_rect = { 1050,600,44,48 };
			if (check == true) point_rect.x += 45;
			SDL_RenderCopy(gScreen, gFive, NULL, &point_rect);
		}
		if (point == 6) {
			SDL_Rect point_rect = { 1050,600,44,49 };
			if (check == true) point_rect.x += 45;
			SDL_RenderCopy(gScreen, gSix, NULL, &point_rect);
		}

		if (point == 7) {
			SDL_Rect point_rect = { 1050,600,44,49 };
			if (check == true) point_rect.x += 45;
			SDL_RenderCopy(gScreen, gSeven, NULL, &point_rect);
		}

		if (point == 8) {
			SDL_Rect point_rect = { 1050,600,44,49 };
			if (check == true) point_rect.x += 45;
			SDL_RenderCopy(gScreen, gEight, NULL, &point_rect);
		}

		if (point == 9) {
			SDL_Rect point_rect = { 1050,600,44,49 };
			if (check == true) point_rect.x += 45;
			SDL_RenderCopy(gScreen, gNine, NULL, &point_rect);
		}

	}
	else if (point > 10) {
		int unit = point % 10;
		int dozens = point / 10;
		Point(dozens, false);
		Point(unit, true);
	}
}

void Close() {
	

	//Free Chunk
	Mix_FreeChunk(gCollision);
	Mix_FreeChunk(gDie);
	Mix_FreeChunk(gPoint);
	Mix_FreeChunk(gWing);
	Mix_FreeChunk(gSwooshing);
	gCollision = NULL;
	gDie = NULL;
	gPoint = NULL;
	gSwooshing = NULL;
	gWing = NULL;
	
	//Free Music
	Mix_FreeMusic(gMusic);
	gMusic = NULL;

	//Destroy Windows
	SDL_DestroyRenderer(gScreen);
	gScreen = NULL;
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* argv[]) {

	srand(time(NULL));
	if (init() == false) return -1;

	SDL_SetRenderDrawColor(gScreen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);

	LoadBackGround();
	LoadMixSound();
	LoadBlock();
	LoadGround();
	LoadPoint();


	SDL_Rect screen_rect = { 0,0,1200,672 };
	SDL_Rect score_rect = { 800,600,223,47 };

	Bird gBird;
	gBird.set_up(gScreen);
	int y_bird = 200, x_bird = 200;

	bool quit = false;
	int animation_bird = 0;

	int stop = 0;
	bool begin = false;
	bool again = false;
	while (!quit) {
		while (SDL_PollEvent(&gEvent) != 0)
		{
			if (gEvent.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		if (gEvent.key.keysym.sym == SDLK_ESCAPE) {
			quit = true;

			SDL_RenderClear(gScreen);

			SDL_RenderCopy(gScreen, gBackGroundBeginQuit, NULL, &screen_rect);

			SDL_RenderPresent(gScreen);

			SDL_Delay(300);
		}

		SDL_RenderClear(gScreen);
		if (begin == false) {
			SDL_RenderClear(gScreen);

			SDL_RenderCopy(gScreen, gBackGroundBegin, NULL, &screen_rect);

			SDL_RenderPresent(gScreen);
			if (gEvent.key.keysym.sym == SDLK_SPACE){
				begin = true;

				SDL_RenderClear(gScreen);

				SDL_RenderCopy(gScreen, gBackGroundBeginStart, NULL, &screen_rect);

				SDL_RenderPresent(gScreen);

				SDL_Delay(300);
			}
			else continue;

		}

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
				Mix_PlayChannel(-1, gWing, 0);
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

		if (gBird.status_ == 0) y_bird = y_bird + 2;
		else y_bird = y_bird - 1;

		if (stop == 0) {
			for (int i = 0; i < 45; i++) {
				gBlock[i].block_rect.x--;

				gBlock[i].Show_block(gScreen);

				if ((gBlock[i].block_rect.x <= 200) && (gBlock[i].bPoint == false)) {
					point++;
					gBlock[i].bPoint = true;
					Mix_PlayChannel(-1, gPoint, 0);
					cerr << point << endl;
				}

			}

			for (int i = 0; i < 20; i++) {
				gGround[i].ground_rect.x--;
				gGround[i].Show_ground(gScreen);
			}
		}
		else {
			for (int i = 0; i < 45; i++) {
				gBlock[i].Show_block(gScreen);
			}

			for (int i = 0; i < 20; i++) {
				gGround[i].Show_ground(gScreen);
			}
		}
		SDL_RenderCopy(gScreen, gScore, NULL, &score_rect);
		Point(point, false);
		gBird.Show(gScreen, { x_bird,y_bird,gBird.bird_width_,gBird.bird_height_ });
		if (stop == 0)
			for (int i = 0; i < 45; i++) {
				if (CheckCollision({ x_bird,y_bird,gBird.bird_width_,gBird.bird_height_ }, gBlock[i].block_rect)) {
					stop = 1;

					Mix_PlayChannel(-1, gCollision, 0);
					if (x_bird <= gBlock[i].block_rect.x) {
						x_bird = gBlock[i].block_rect.x;
					}
					break;
				}
				else {
					if (CheckCollision({ x_bird,y_bird,gBird.bird_width_,gBird.bird_height_ }, gBlock[i].rect_fix)) {
						stop = 1;
						Mix_PlayChannel(-1, gCollision, 0);
						if (x_bird <= gBlock[i].block_rect.x) {
							x_bird = gBlock[i].block_rect.x;
						}

						break;
					}
				}
			}

		if (stop == 1) {
			y_bird += 3;
		}

		if ((y_bird + gBird.bird_height_) >= 552 && Check_sound == false) {
			again = false;
			
			Check_sound = true;
			Mix_PlayChannel(-1, gCollision, 0);
			SDL_Delay(300);
			Mix_PlayChannel(-1, gDie, 0);
		}

		SDL_Delay(4);
		SDL_RenderPresent(gScreen);
	}
	Close();
	return 0;
}
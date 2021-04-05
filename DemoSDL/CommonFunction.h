#ifndef COMMONFUNCTION__H_
#define COMMONFUNCTION__H_ 

#include<iostream>
#include<Windows.h>
#include<string>
#include<SDL_image.h>
#include<SDL.h>
#include<time.h>

using namespace std;

static SDL_Window* gWindow = NULL;

static SDL_Renderer* gScreen = NULL;

static SDL_Event gEvent;

//Screen
const int SCREEN_WIGHT = 1200;
const int SCREEN_HIGHT = 672;

const int RENDER_DRAW_COLOR = 255;


#endif // !COMMONFUNCTION__H_
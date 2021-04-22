#ifndef MUSIC__H_
#define MUSIC__H
#include"CommonFunction.h"

Mix_Chunk* LoadMixChunk(string path) {
	Mix_Chunk* new_mix_chunk = Mix_LoadWAV(path.c_str());
	return new_mix_chunk;
}

#endif // !MUSIC__H_

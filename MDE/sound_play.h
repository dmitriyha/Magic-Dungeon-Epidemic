#ifndef SOUND_PLAY_H
#define SOUND_PLAY_H

#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <string>
using namespace std;

class sound_play{
	HWAVEOUT hWaveOut; /* device handle */
	LPSTR block;
	DWORD blockSize;
public:
	sound_play(string path);
	void writeAudioBlock( DWORD size);
	LPSTR loadAudioBlock(const char* filename, DWORD* blockSize);
	void play();
	~sound_play();
};

#endif

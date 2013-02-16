#include "StdAfx.h"
#include "Game.h"

Game::Game(void)
	: _currentRoll(0) {

	memset(_frames, 0, sizeof(int)*21);
}

Game::~Game(void) {
}

int Game::Score(void) {
	int score = 0;
	int frameIndex = 0;
	for (int i=0; i < 10; i++) {
		if (IsStrike(frameIndex)) {
			score += (10 + StrikeBonus(frameIndex));
			frameIndex++;
			continue;
		}

		score += SumOfFrame(frameIndex);
		score += SpareBonus(frameIndex);

		frameIndex += 2;
	}

	return score;
}

void Game::Roll(int pins) {
	if (_currentRoll == 21)
		return;

	_frames[_currentRoll] = pins;
	_currentRoll++;
}

int Game::SumOfFrame(int frameIndex) {
	return _frames[frameIndex] + _frames[frameIndex+1];
}

int Game::SpareBonus(int frameIndex) {
	if (IsSpare(frameIndex))
		return _frames[frameIndex + 2];

	return 0;
}

int Game::StrikeBonus(int frameIndex) {
	if (IsStrike(frameIndex))
		return _frames[frameIndex + 1] + _frames[frameIndex + 2];

	return 0;
}

bool Game::IsSpare(int frameIndex) {
	return (_frames[frameIndex] + _frames[frameIndex+1]) == 10;
}

bool Game::IsStrike(int frameIndex) {
	return _frames[frameIndex] == 10;
}
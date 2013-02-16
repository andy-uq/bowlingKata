#pragma once
class Game
{
public:
	Game(void);
	~Game(void);
	void Roll(int pins);
	int Score(void);

private:
	int _frames[21];
	int _currentRoll;

	int SumOfFrame(int frameIndex);
	bool IsSpare(int frameIndex);
	bool IsStrike(int frameIndex);
	int SpareBonus(int frameIndex);
	int StrikeBonus(int frameIndex);

};


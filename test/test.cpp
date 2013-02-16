// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <gtest/gtest.h>
#include <iostream>

#include <game.h>

int _tmain(int argc, _TCHAR* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	bool quiet = argc != 0 && !wcscmp(argv[0], L"-q");
	if (!quiet) {
		std::cout << "Running in interactive mode" << std::endl;
	}

	int result = RUN_ALL_TESTS();
	if (!quiet && result) {
		getchar();
	}

	return result;
}

void Roll(Game& game, int pins = 0, int times = 20);
void RollSpare(Game& game);
void RollStrike(Game& game);

TEST(Game, CanCreate) {
	Game game;

	ASSERT_EQ(game.Score(), 0);
}

TEST(Game, GutterGame) {
	Game game;
	Roll(game, 0);
	ASSERT_EQ(game.Score(), 0);
}

TEST(Game, AllOnes) {
	Game game;
	Roll(game, 1, 20);
	ASSERT_EQ(20, game.Score());
}


TEST(SimpleTest, ShouldPass) {
	ASSERT_TRUE(true);
}

TEST(SimpleTest, RollOneSpare) {
	Game game;
	RollSpare(game);
	game.Roll(3);
	Roll(game, 0, 17);

	ASSERT_EQ(16, game.Score());
}

TEST(SimpleTest, RollOneStrike) {
	Game game;
	RollStrike(game);
	game.Roll(3);
	game.Roll(4);
	Roll(game, 0, 16);

	ASSERT_EQ(24, game.Score());
}

void RollStrike(Game& game) {
	game.Roll(10);
}

void RollSpare(Game& game) {
	game.Roll(6);
	game.Roll(4);
}

void Roll(Game& game, int pins, int times) {
	for (int i = 0; i < times; i++)
		game.Roll(pins);
}
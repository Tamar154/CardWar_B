#pragma once

#include "player.hpp"
#include "card.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

const int NUM_OF_CARDS = 52;

namespace ariel
{
    class Game
    {
        Player& p1;
        Player& p2;
        int numOfTurns = 0; 
        vector<Card> deck;

    public:
        Game(Player&, Player&);

        void initDeck();
        void shuffleDeck();
        void dealCards();

        void playTurn();
        void printLastTurn();


        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
}
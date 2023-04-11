#pragma once

#include <string>
#include <vector>

#include "card.hpp"

#include <iostream>
using namespace std;

namespace ariel
{
    class Player
    {
        string name;
        vector<Card> deck;
        int stackSize;
        int cardsTaken;
        int numOfWins;

    public:
        Player();
        Player(string);

        int stacksize();
        int cardesTaken();
        string getName();

        void setCardsTaken(int);
        void addCard(Card);
        Card playOpenCard();
        void playClosedCard();
        int getNumOfWins();
        void setNumOfWins(int);
    };
}
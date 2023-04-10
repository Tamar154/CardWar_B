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

    public:
        Player();
        Player(string);

        int stacksize();
        int cardesTaken();
        string getName();

        void setCardsTaken(int);
        void addCard(Card card);
        Card playOpenCard();
        void playClosedCard();
    };
}
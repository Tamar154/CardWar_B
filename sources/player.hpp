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

        // void setCardTaken();
        void addCard(Card card);

        // void printCards()
        // {
        //     cout << "===========PLAYER CARDS========" << endl;
        //     for (Card c : this->deck)
        //     {
        //         cout << c.getRank() << ", " << c.getSuit() << endl;
        //     }
        // }
    };
}
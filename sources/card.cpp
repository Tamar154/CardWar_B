#include "card.hpp"
using namespace ariel;

Card::Card()
{
    this->suit = "";
    this->rank = -1;
}

Card::Card(string suit, int rank)
{
    this->rank = rank;
    this->suit = suit;
}

string Card::getSuit()
{
    return this->suit;
}

int Card::getRank()
{
    return this->rank;
}

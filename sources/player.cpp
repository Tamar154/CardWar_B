#include "player.hpp"

using namespace ariel;
using namespace std;

Player::Player()
{
    this->name = "";
}

Player::Player(string name)
{
    this->name = name;
    this->stackSize = this->deck.size();
    this->cardsTaken = 0;
}

int Player::stacksize()
{
    return this->deck.size();
}

int Player::cardesTaken()
{
    return this->cardsTaken;
}

string Player::getName()
{
    return this->name;
}

void Player::setCardsTaken(int num)
{
    this->cardsTaken = num;
}

void Player::addCard(Card card)
{
    this->deck.push_back(card);
}

Card Player::playOpenCard()
{
    Card c = this->deck.front();
    this->deck.erase(this->deck.begin());
    this->stackSize--;
    return c;
}

void Player::playClosedCard()
{
    this->deck.erase(this->deck.begin());
    this->stackSize--;
}

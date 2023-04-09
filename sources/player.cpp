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
    this->stackSize = 0;
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

// void Player::setCardTaken()
// {
// }

void Player::addCard(Card card)
{
    this->deck.push_back(card);
}

void printCards(){
    
}

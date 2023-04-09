#include "game.hpp"
#include <random>

using namespace std;
using namespace ariel;

Game::Game(Player &player1, Player &player2) : p1(player1), p2(player2)
{
    initDeck();
    shuffleDeck();
    dealCards();
}

void Game::initDeck()
{
    string suits[] = {"clubs", "diamonds", "hearts", "spades"};
    // 1=ace, ... , 11=jack, 12=queen, 13=king
    int ranks[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    for (string suit : suits)
    {
        for (int rank : ranks)
        {
            Card c(suit, rank);
            this->deck.push_back(c);
        }
    }
}

/*
    Thanks to:
    https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
*/
void Game::shuffleDeck()
{
    auto rng = default_random_engine{};
    shuffle(begin(this->deck), end(this->deck), rng);
}

void Game::dealCards()
{
    int i = 0;
    for (Card &c : this->deck)
    {
        if (i % 2 == 0)
            this->p1.addCard(c);
        else
            this->p2.addCard(c);
        i++;
    }
}

void Game::playTurn()
{
    if (this->p1.stacksize() == 0 || this->p2.stacksize() == 0)
    {
        throw string("Game ended");
    }
    if (&p1 == &p2)
    {
        throw("Game cannot be played by one player.");
    }

    Card c1 = this->p1.playOpenCard();
    Card c2 = this->p2.playOpenCard();

    int numOfCardsToTake = 2;
    while (c1.getRank() == c2.getRank())
    {
        this->p1.playClosedCard();
        this->p2.playClosedCard();
        c1 = this->p1.playOpenCard();
        c2 = this->p2.playOpenCard();
        numOfCardsToTake += 4;
    }

    // p1 takes the cards.
    if (c1.getRank() > c2.getRank())
    {
        this->p1.setCardsTaken(p1.cardesTaken() + numOfCardsToTake);
    }
    // p2 takes the cards.
    else
    {
        this->p2.setCardsTaken(p2.cardesTaken() + numOfCardsToTake);
    }
}

void Game::printLastTurn()
{
}

/*
EDGE CASE: there are 2 or 4 cards left, and could be a tie
*/
void Game::playAll()
{
    if (this->p1.stacksize() == 0 || this->p2.stacksize() == 0)
    {
        throw string("Game ended");
    }

    while (this->p1.stacksize() != 0 && this->p2.stacksize() != 0)
    {
        playTurn();
    }
}

void Game::printWiner()
{
}

void Game::printLog()
{
}

void Game::printStats()
{
}

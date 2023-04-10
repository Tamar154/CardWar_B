#include "game.hpp"
#include <random>

using namespace std;
using namespace ariel;

Game::Game(Player &player1, Player &player2) : p1(player1), p2(player2), lastTurn(""), log("")
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
    auto rd = random_device{};
    auto rng = default_random_engine{rd()};
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

    this->lastTurn = "";
    Card c1 = this->p1.playOpenCard();
    Card c2 = this->p2.playOpenCard();

    this->lastTurn += this->p1.getName() + " played " + to_string(c1.getRank()) + " of " + c1.getSuit() + " ";
    this->lastTurn += this->p2.getName() + " played " + to_string(c2.getRank()) + " of " + c2.getSuit() + " ";

    int numOfCardsToTake = 2;
    while (c1.getRank() == c2.getRank())
    {
        if (this->p1.stacksize() >= 2)
        {
            this->p1.playClosedCard();
            this->p2.playClosedCard();
            c1 = this->p1.playOpenCard();
            c2 = this->p2.playOpenCard();
            numOfCardsToTake += 4;
        }
        // Each player takes half of the cards
        else
        {
            this->p1.setCardsTaken(p1.cardesTaken() + (numOfCardsToTake / 2));
            this->p2.setCardsTaken(p2.cardesTaken() + (numOfCardsToTake / 2));
            break;
        }

        this->lastTurn += this->p1.getName() + " played " + to_string(c1.getRank()) + " of " + c1.getSuit() + " ";
        this->lastTurn += this->p2.getName() + " played " + to_string(c2.getRank()) + " of " + c2.getSuit() + " ";
    }

    // p1 takes the cards.
    if (c1.getRank() > c2.getRank())
    {
        this->p1.setCardsTaken(p1.cardesTaken() + numOfCardsToTake);
        this->lastTurn += this->p1.getName() + " wins.";
    }
    // p2 takes the cards.
    else if (c1.getRank() < c2.getRank())
    {
        this->p2.setCardsTaken(p2.cardesTaken() + numOfCardsToTake);
        this->lastTurn += this->p2.getName() + " wins. ";
    }
    else
    {
        this->lastTurn += " draw. ";
    }
}

void Game::printLastTurn()
{
    cout << this->lastTurn << endl;
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

    int count = 1;
    while (this->p1.stacksize() != 0 && this->p2.stacksize() != 0)
    {
        playTurn();

        // cout << "=====> " << count++ << endl;
        // printLastTurn();
        // cout << "p1 stack = " << this->p1.stacksize() << endl;
        // cout << "p1 taken = " << this->p1.cardesTaken() << endl;
        // cout << "p2 stack = " << this->p2.stacksize() << endl;
        // cout << "p2 taken = " << this->p2.cardesTaken() << endl;
    }
}

void Game::printWiner()
{
    if (this->p1.cardesTaken() == this->p2.cardesTaken())
    {
        cout << "The game ended with tie" << endl;
    }
    else if (this->p1.cardesTaken() > this->p2.cardesTaken())
        cout << "The Winner Is: " << this->p1.getName() << endl;
    else
    {
        cout << "The Winner Is: " << this->p2.getName() << endl;
    }
}

void Game::printLog()
{
}

void Game::printStats()
{
}

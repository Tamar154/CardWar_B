#include "sources/game.hpp"

using namespace std;
using namespace ariel;

int main()
{
    // Create two players
    Player p1("player1");
    Player p2("player2");

    // Create a game with player1 and player2
    Game game(p1, p2);

    game.playAll();
    cout << "===== WINNER =====" << endl;
    game.printWiner();
    cout << "===== GAME LOG =====" << endl;
    game.printLog();
    cout << "===== GAME STATS =====" << endl;
    game.printStats();
}
#pragma once

#include <string>
using namespace std;

namespace ariel
{
    class Card
    {
        string suit;
        int rank;
        

    public:
        Card();
        Card(string, int);

        string getSuit();
        int getRank();
        
    };
}
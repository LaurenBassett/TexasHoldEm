/* File: rank.cpp
 * Course: CS216-00x
 * Project: Lab5 (as part of Project 1)
 * Purpose: the implementation of member functions for the Rank class.
 *
 */
#include <iostream>
#include "rank.h"

using namespace std;

// Default constructor.
Rank::Rank()
{
    kind = NoRank;
    point = 0;
}

// Alternate constructor.
// Create a Rank object with specified ranking name and points.
Rank::Rank(hRanks r, rPoints p)
{
    kind = r;
    point = p;
}

// Display a description of the hand-ranking category to standard output.
// The output should look like:
//   FourOfAKind(4)
//   FullHouse(K)
//   Flush(A)
//   ...
void Rank::print()
{
    char suit;
    if (point > 10) {
        if (point == 11) suit = 'J';
        else if (point == 12) suit = 'Q';
        else if (point == 13) suit = 'K';
        else if (point == 14) suit = 'A';
        cout << RANK_NAMES[kind] << "(" << suit << ")" << endl;
        return;
        }
    cout << RANK_NAMES[kind] << "(" << point << ")" << endl;
    return;
}


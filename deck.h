/* File: deck.h
 * Course: CS216-00x
 * Project: Project 1
 * Purpose: the declaration for the Deck class.
 *** DO NOT CHANGE THIS FILE ***
 *
 */
#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

using namespace std;

// Avoid magic numbers
// define constants for a standard 52-card deck: 4 suits * 13 point ranks
const int CARD_START = 2;  // the card value starting at 2
const int SUITS = 4;    // standard 52-card deck includes four suits
const int POINT_RANKS = 13;   // standard 52-card deck includes 13 types of point ranks

class Deck
{
    public:
        // create a standard 52-card deck
        void createDeck();

        // shuffle the cards in 52-card deck
        void shuffleDeck();

        // return a card from the tail of the deck
        Card deal_a_card();

    private:
        vector<Card> deck;
};
#endif  /* DECK_H */

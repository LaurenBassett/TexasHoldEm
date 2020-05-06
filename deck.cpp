/* File: deck.cpp
 * Course: CS216-00x
 * Project: Lab5 (as part of Project 1)
 * Purpose: the implementation of member functions for the Deck class.
 *
 */

#include <cstdlib>
#include <ctime>
#include "deck.h"
#include <vector>
// create a standard 52-card deck
void Deck::createDeck()
{
     for (int s = Card::Spade; s <= SUITS; s++) {
        for(Card::cPoints val = CARD_START; val < POINT_RANKS+CARD_START; val++) {
            Card::cSuits suit = static_cast<Card::cSuits>(s);
            Card newcard(suit,val);
            deck.push_back(newcard);
        }
     }
}

// shuffle the cards in 52-card deck
void Deck::shuffleDeck()
{
    //Take deck and rearrange cards in different order
    Card temp;
    for (int i = deck.size()-1; i>= 1;
            i--) {
        int j = rand() % (i+1);
        temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

// return a card from the tail of the deck
Card Deck::deal_a_card()
{
    Card store = deck.back();
    deck.pop_back();
    return store;
}


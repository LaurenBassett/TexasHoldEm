/* File: card.h
 * Course: CS216-00x
 * Project: Project 1
 * Purpose: the implementation of member functions for the Card class.
 *** DO NOT CHANGE THIS FILE ***
 *
 */

#include "card.h"

// Default constructor marks card as invalid
Card::Card() {
    suit = Invalid ;
    point = 0 ;
}

// Alternate constructor
Card::Card(cSuits s, cPoints p) 
{
    suit = s;
    point = p;
}

// compare with another Card object passed in as parameter: other
// if the object your are working on has higher point than other, return 1;
// if the object your are working on has lower point than other, return -1;
// otherwise, return 0
int Card::compareTo(Card other)
{
    if (this->point < other.point)
        return -1;
    if (this->point > other.point)
        return 1;
    return 0;
}

// Display a description of the Card object to standard output
// The output should look like:
//   
void Card::print() 
{
    // map the point to card face
    // 11 -->J, 12 -->Q, 13 -->K, 14 --> A
    char face;
    char space=' ';
    switch (point)
    {
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            face = '0'+ point;
            break;
        case 10:
            face = '0';
            space = '1';
            break;
        case 11:
            face = 'J';
            break;
        case 12:
            face = 'Q';
            break;
        case 13:
            face = 'K';
            break;
        case 14:
            face = 'A';
            break;
        default:
            face = '\0';
            break;
    }

    if (face =='\0')
    {
        cout << "Invalid card value!" << endl;
        return;
    }

    switch (suit)
    {
        case Spade:
            cout << endl << SPADE << space << face << SPADE << endl;
            break;
        case Club:
            cout << endl << CLUB << space << face << CLUB << endl;
            break;
        case Heart:
            cout << endl << HEART << space << face << HEART << endl;
            break;
        case Diamond:
            cout << endl << DIAMOND << space << face << DIAMOND << endl;
            break;
        default:
            cout << "Invalid suit!" << endl;
            break;
    }
}

// access the card point value
Card::cPoints Card::getPoint() const
{
    return point;
}
// access the card suit value
Card::cSuits Card::getSuit() const
{
    return suit;
}

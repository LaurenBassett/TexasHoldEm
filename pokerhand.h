/* File: pokerhand.h
 * Course: CS216-00x
 * Project: Programming Project 1
 * Purpose: the declaration for the PokerHand class.
 **** YOU MAY ADD MEMBER FUNCTIONS OR HELPER FUNCIONS ***
 **** DO NOT CHANGE OTHER PARTS OF THIS FILE ***
 */

#ifndef POKERHAND_H
#define POKERHAND_H

#include "card.h"
#include "rank.h"

using namespace std;

class PokerHand 
{
    public:
        // Avoiding magic numbers.
        // Note: must use PokerHand::FIVE outside member functions.
        static const int CARDS_IN_HAND = 5 ;

        // Default constructor.
        // We allow a blank PokerHand to be created.
        // However, the default constructor should make sure
        // that hand_rank is (Rank::NoRank, 0).
        PokerHand();

        // It should store the FIVE cards
        // given as parameters in the cards[] array.
        // if size is not FIVE, display "Invalid number of cards!"
        // It should also immediately evaluate the hand, determine
        // its rank: ranking kind and the card value
        void setPokerHand(Card in_hand[], int size);


        // Compare this hand versus otherHand according
        // to the rules of poker. 
        // Returns a negative number (< 0) 
        // if this hand loses to the otherHand.
        // Returns a positive number (> 0) 
        // if this hand beats the otherHand.
        // Returns zero if it's a tie.
        //
        // An invalid hand loses to any hand. If both hands
        // are invalid, the result is undefined (could be
        // negative, zero or positive).
        //
        int compareHand(const PokerHand &otherHand);


        // Prints out the five cards and its rank to standard output.
        // It should look like:
        // Five cards:
        // one card per line
        // then followed by "Its rank is: rank"
        void print();
        
        // Return the rank of this hand
        Rank getRank() const;


        // The following "isXXXX()" functions shoudl all:
        // 1. Assume that the hand is already sorted;
        // 2. If true, store the rank in hand_rank;
        // 3. use the rank if hand_rank is available.
        
        // Returns true if the hand is a StraightFlush
        //              and set the hand_rank (StraightFlush, highest point of the sequence FIVE)
        // otherwise returns false
        bool isStraightFlush();


        // Returns true if the hand is a Four of a Kind
        //              and set the hand_rank (FourOfAKind, highest point of the same FOUR)
        // otherwise returns false
        bool isFourOfAKind();

        // Returns true if the hand is a Full House
        //              and set the hand_rank (FullHouse, highest point of the same THREE)
        // otherwise returns false
        bool isFullHouse();

        // Returns true if the hand is a Flush
        //              and set the hand_rank (Flush, highest point of the FIVE)
        // otherwise returns false
        bool isFlush();

        // Returns true if the hand is a Straight
        //              and set the hand_rank (Straight, highest point of the sequence FIVE)
        // otherwise returns false
        bool isStraight();

        // Returns true if the hand is a Three of a Kind
        //              and set the hand_rank (ThreeOfAKind, highest point of the same THREE)
        // otherwise returns false
        bool isThreeOfAKind();

        // Returns true if the hand is a Pair (we consider one pair or two pairs is a Pair)
        //              and set the hand_rank (Pair, highest point of any pair)
        // otherwise returns false
        bool isPair();

        // Returns true if the hand is a High Card
        //              and set the hand_rank (High Card, highest point of the FIVE)
        // otherwise returns false
        bool isHighCard();

    private:
        Card cards[CARDS_IN_HAND];      // holds 5 cards in this poker hand
        Rank hand_rank;        // stored hand ranking

        // helper functions
        
        // to help sort 5 cards in decreasing order by card points
        void sort();

        // to help decide if 5 cards are all of one suit
        // return true if they are
        // otherwise return false
        bool isAllOneSuit();

        // to help decide if 5 cards are in a continuous sequence
        // return true if they are 
        // otherwise return false
        bool isSequence();
	
        void setRank(Rank r);
};

#endif  /* POKERHAND_H */

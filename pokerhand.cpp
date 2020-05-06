
#include "pokerhand.h"
#include <string>
using namespace std;

//-----------------------------------------------------------------
//              Default constructor - PokerHand::PokerHand();
//Instructions: We allow a blank PokerHand to be created.
//              However, the default constructor should make sure
//              that hand_rank is (Rank::NoRank, 0).
//-----------------------------------------------------------------
PokerHand::PokerHand() {
    //indexToPoint = 0;
    Card in_hand[CARDS_IN_HAND];
    hand_rank = Rank(Rank::NoRank, 0);
}
//------------------------------------------------------------------
//               void setPokerHand(Card in_hand, int size);
// Instructions: It should store the FIVE cards
//               given as parameters in the cards[] array.
//               if size is not FIVE, display "Invalid number of cards!"
//               It should also immediately evaluate the hand, determine
//               its rank: ranking kind and the card value
// inputs:		 array of cards, size indicating number of cards
// outputs:      none, void function
//-----------------------------------------------------------------
void PokerHand::setPokerHand(Card in_hand[], int size){
	if(size != CARDS_IN_HAND) {
		cout << "Invalid Number of Cards";
	}
	else {
		for (int i = 0; i < CARDS_IN_HAND; i++) {
			cards[i] = in_hand[i];		
		}
	}

	sort(); //sort the hand now
	//now we check to see what it is
	if (! isStraightFlush())
	if (! isFourOfAKind())
	if (! isFullHouse())
	if (! isFlush())
	if (! isStraight())
	if (! isThreeOfAKind())
	if (! isPair())
	    isHighCard();
//	print();
}


//-----------------------------------------------------------------
//               int compareHand(const PokerHand &otherHand)
// instructions: Compare this hand versus otherHand according
//				 to the rules of poker. 
//				 Returns a negative number (< 0) 
//				 if this hand loses to the otherHand.
//				 Returns a positive number (> 0) 
//				 if this hand beats the otherHand.
//				 Returns zero if it's a tie.
//
//				 An invalid hand loses to any hand. If both hands
//				 are invalid, the result is undefined (could be
//				 negative, zero or positive).
//------------------------------------------------------------------
int PokerHand::compareHand(const PokerHand &otherHand){
	if (getRank().kind > otherHand.getRank().kind) {return 1; }
	else {
		if (getRank().kind < otherHand.getRank().kind) {return -1;}
  			else {
				if(getRank().point > otherHand.getRank().point) {return 1;}
					else {
						if (getRank().point < otherHand.getRank().point) {return -1;}
						else {return 0;}}
	}	}
}

//-----------------------------------------------------------------
//               void print();
// Instructions: Prints out the five cards and its rank to standard output.
//				 It should look like:
//				 Five cards:
//				 one card per line
//				 then followed by "Its rank is: rank"
//-----------------------------------------------------------------
void PokerHand::print(){
	cout << "Five cards in order: " << endl;
	for (int i = 0; i < CARDS_IN_HAND; i++) {
		cards[i].print();
		cout << endl;
	}
    Rank theRank = getRank();
	cout << "Its rank is: ";
	theRank.print();
}
//------------------------------------------------------------------
//				 Rank getRank();
// Instructions: Return the rank of this hand
//------------------------------------------------------------------

Rank PokerHand::getRank() const{
	//So What are the ranks anyway???
	/*
	Straight Flush  - 9
	4 Of A Kind     - 8
	Full House      - 7
	Flush           - 6
	Straight        - 5
	Three of a Kind - 4
	Two Pair        - 3
	One Pair        - 2
	High Card       - 1
	Invalid (Loser) - 0
	*/

	return hand_rank;
}


//---------------------------------------------------------------------------
// isXXXX() FUNCTIONS  BELOW THIS POINT!!!!
//---------------------------------------------------------------------------
// The following "isXXXX()" functions should all:
// 1. Assume that the hand is already sorted;
// 2. If true, store the rank in hand_rank;
// 3. use the rank if hand_rank is available.
//---------------------------------------------------------------------------      

//---------------------------------------------------------------------------
//				 isStraightFlush();
// Instructions: Returns true if the hand is a StraightFlush
//				 and set the hand_rank (StraightFlush, highest point of the sequence FIVE)
//				 otherwise returns false
//---------------------------------------------------------------------------
bool PokerHand::isStraightFlush(){
	if (isAllOneSuit() && isSequence()) {
		setRank(Rank(Rank::StraightFlush,cards[0].getPoint()));
		return true;
	}
	return false;
}

//--------------------------------------------------------------------------
//               isFourOfAKind();
//Instructions:  Returns true if the hand is a Four of a Kind
//               and set the hand_rank (FourOfAKind, highest point of the same FOUR)
//				 otherwise returns false
//--------------------------------------------------------------------------
bool PokerHand:: isFourOfAKind(){
	if (cards[0].getPoint() == cards[3].getPoint()) {
		setRank(Rank(Rank::FourOfAKind, cards[0].getPoint()));
		return true;
	}
	else if (cards[1].getPoint() == cards[4].getPoint()) { 
		setRank(Rank(Rank::FourOfAKind, cards[1].getPoint()));
		return true;
	}
	return false;
}
//------------------------------------------------------------------
// isFullHouse()
// Returns true if the hand is a Full House
// and set the hand_rank (FullHouse, highest point of the same THREE)
// otherwise returns false
//------------------------------------------------------------------

bool PokerHand::isFullHouse(){
    //Needs Three of a Kind and Pair
   if((cards[0].getPoint() == cards[1].getPoint()) && (cards[2].getPoint() == cards[4].getPoint())){
       setRank(Rank(Rank::FullHouse,cards[2].getPoint())); 
       return true;
    }
	else if((cards[0].getPoint() == cards[2].getPoint()) && (cards[3].getPoint() == cards[4].getPoint())){
        setRank(Rank(Rank::FullHouse,cards[0].getPoint()));    
        return true;
    }
	else return false;
}

//------------------------------------------------------------------
// isFlush();
// Returns true if the hand is a Flush
//              and set the hand_rank (Flush, highest point of the FIVE)
// otherwise returns false
//------------------------------------------------------------------
bool PokerHand::isFlush(){
	if (isAllOneSuit()) {
		setRank(Rank(Rank::Flush, cards[0].getPoint()));
		return true;
	}
    return false;

}

//------------------------------------------------------------------
// isStraight() 
// Returns true if the hand is a Straight
//              and set the hand_rank (Straight, highest point of the sequence FIVE)
// otherwise returns false
//------------------------------------------------------------------

bool PokerHand::isStraight(){
	if (isSequence()) {
		setRank(Rank(Rank::Straight,cards[0].getPoint()));
		return true;
	}
	return false;
}
//------------------------------------------------------------------
// isThreeOfAKind();
// Returns true if the hand is a Three of a Kind
//              and set the hand_rank (ThreeOfAKind, highest point of the same THREE)
// otherwise returns false
//------------------------------------------------------------------
bool PokerHand::isThreeOfAKind(){
	bool check = false;
	int hold;
	if (cards[0].getPoint() == cards[2].getPoint()) {
		check = true;
		hold = cards[1].getPoint();
	}
	else if (cards[1].getPoint() == cards[3].getPoint()) {
		check = true;
		hold = cards[2].getPoint();
	}
	if (check) {setRank(Rank(Rank::ThreeOfAKind, hold));}
	return check;
}


//------------------------------------------------------------------
// isPair();
// Returns true if the hand is a Pair (we consider one pair or two pairs is a Pair)
//              and set the hand_rank (Pair, highest point of any pair)
// otherwise returns false 
//------------------------------------------------------------------
bool PokerHand::isPair(){
    bool check = false;
    Card to_check = cards[0];
    for(int i =1; i < CARDS_IN_HAND; i++) {
		if (to_check.getPoint() == cards[i].getPoint()) {
            setRank(Rank(Rank::Pair, to_check.getPoint()));
			check = true;
            
        }
        else {
            to_check = cards[i];
        }
    }
    return check;
}


//------------------------------------------------------------------
// Returns true if the hand is a High Card
//              and set the hand_rank (High Card, highest point of the FIVE)
// otherwise returns false
//------------------------------------------------------------------
bool PokerHand::isHighCard() {
	if (!isPair() && !isFlush() && !isFullHouse() && !isStraight()) {
		setRank(Rank(Rank::HighCard, cards[0].getPoint()));
		return true;
	}
	return false;
}

//------------------------------------------------------------------
//void sort()
//------------------------------------------------------------------
void PokerHand::sort(){
    for (int i=0; i < CARDS_IN_HAND; i++){
        for(int j=i+1;j < CARDS_IN_HAND; j++) {
			if(cards[i].getPoint()>cards[j].getPoint()) {
                Card temp = cards[i];
                cards[i] = cards[j];
                cards[j]= temp;
            }        
        }
    }
}
//---------------------------------------------------
// isAllOneSuit();
// to help decide if 5 cards are all of one suit
// return true if they are
        // otherwise return false
//---------------------------------------------------
bool PokerHand::isAllOneSuit(){
    bool check = true;
    for(int i = 0;i<CARDS_IN_HAND-1; i++){
        if(cards[i].getSuit() == cards[i+1].getSuit()){
            check = true & check;
        }
        else check = false;
    }
    return check;
}
//---------------------------------------------------------
// isSequence();
// to help decide if 5 cards are in a continuous sequence
// return true if they are 
// otherwise return false
//--------------------------------------------------------

bool PokerHand::isSequence(){
	
	for(int i =0; i<CARDS_IN_HAND-1;i++) {
			if((cards[i].getPoint() +1 !=cards[i+1].getPoint()))
			return false ;
	}
	return true;
}
//-----------------------------------------------------------
// setRank();
//-----------------------------------------------------------
void PokerHand::setRank(Rank r) {
	hand_rank = r;
}

	

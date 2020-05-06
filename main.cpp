//MAIN FUNCTION 
#include <iostream>
#include "pokerhand.h"
#include "deck.h"
#include <vector>
#include <string>

const int SEVEN = 7;
const int FIVE = 5;
const int TWO = 2;
PokerHand best_five(const vector<Card>&cards);
int main() {
    char qquit = 'a';
    while(qquit !='q'&&qquit!='Q') {
    
        //deal individual cards to the players
        Card player[TWO];
        Card computer[TWO];
        //for the shared deck
        Card shared[FIVE];
        //combine this stuff
        Card full_player_hand[SEVEN];
        Card full_comput_hand[SEVEN];
        vector<Card> s_Play;
        vector<Card> s_Comp;
        Deck the_deck;
        the_deck.createDeck();
        the_deck.shuffleDeck();
        //Give 
        for(int i = 0; i < TWO; i++) {
            player[i] = the_deck.deal_a_card();
            computer[i] = the_deck.deal_a_card();
        }
        for(int j = 0; j<FIVE; j++) {
            shared[j] = the_deck.deal_a_card();
        }
        //two loops used to make arrays full of both the shared hands
        for(int k =0; k<TWO;k++) {
            full_player_hand[k] = player[k];
            full_comput_hand[k] = computer[k];
        }
        for (int l = TWO; l < SEVEN; l++) {
            full_player_hand[l] = shared[l-2];
            full_comput_hand[l] = shared[l-2];
        }
        for(int m =0; m < SEVEN; m++) {
            s_Play.push_back(full_player_hand[m]);
            s_Comp.push_back(full_comput_hand[m]);
        }
    

        cout << "The cards in your hand are:" <<endl;
        for(int i =0; i<TWO;i++) {
            player[i].print();
        }
        cout << endl;
       
       cout << "The FIVE cards on the deck to share are\n";
       cout << "****************\n";
       for(int i =0; i<FIVE; i++) {
           shared[i].print();
       }
       cout << "****************\n";
         cout << "The cards in the computer's hand are:";
       for (int i=0; i<TWO;i++) {
           computer[i].print();
       }
       cout<<"\n";
       PokerHand pHand = best_five(s_Play);
       PokerHand cHand = best_five(s_Comp);
       cout << "Player 1: You\n";
       cout<< "*** Best five-card hand ***\n";
       pHand.print();
       cout << "Player 2: Computer\n";
       cout << "*** Best five-card hand ***\n";
       cHand.print();
       if(pHand.compareHand(cHand) > 0) cout << "You win!\n";
       else if (pHand.compareHand(cHand) < 0) cout << "Sorry, the computer wins the game!\n";
       else cout << "It's a tie!\n";

       cout << "Do you want to play poker game again (Press \"q\" or \"Q\" to quit the program)\n";
       cin>>qquit;
    }
}
PokerHand best_five(const vector<Card>& cards)
{
    int TOTAL_CARDS_TO_CHOOSE = 7;
    int CARDS_IN_HAND = 5;
    PokerHand bestH;
    PokerHand cardsH;

    // check if the parameter is valid
    if (cards.size() != TOTAL_CARDS_TO_CHOOSE)
    {
        cout << "Invalid Cards, we need SEVEN cards!" << endl;
        return cardsH; // return a PokerHand object by default constructor
    }

    // Consider all possible ways of dropping two cards
    // from the seven card hand. 
    // i is the index of the first card dropped
    // and j is the index of the second card dropped.
    // There are 21 different way to pick 5 cards out of 7
    for (int i=0; i < TOTAL_CARDS_TO_CHOOSE; i++)
    {
        for (int j=i+1; j < TOTAL_CARDS_TO_CHOOSE; j++)
        {
            Card pick[CARDS_IN_HAND];
            int index = 0;

            // Iterate over all seven cards and assign them to the pick[] array
            // exclude cards with index numbers of #i and #j.
            for (int k=0 ; k < TOTAL_CARDS_TO_CHOOSE ; k++)
            {
                if (k == i || k == j)
                    continue;
                pick[index] = cards[k];
                index++;
            }

            // create a PokerHand with pick[]
            cardsH.setPokerHand(pick, CARDS_IN_HAND);

            // Check to see if current pick is better than
            // the best you have seen so far
            if (bestH.compareHand(cardsH) < 0)
            {
                bestH = cardsH ;
            }
        }
    }
	return bestH;
}

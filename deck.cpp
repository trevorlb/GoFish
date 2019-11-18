//deck.cpp
//Author: Trevor Barrett
//Date: 11/11/2019
//Implements the functions declared in the card.h file

#include "card.h"
#include "deck.h"
#include <ctime>
#include <cstdlib>
using namespace std;    
    
   int Deck::getIndex() const{
      return myIndex;
   }
 
   Deck::Deck(){           // pristine, sorted deck
      myIndex = 0;
      int cardCount = 0;
      for (int j = 0; j < 4; j++){
         for (int k = 0; k < 13; k++){
            Card c1(k+1,(Card::Suit) j);
            myCards[cardCount] = c1;
            //cout << cardCount << endl;
            //cout << c1 << endl;
            //cout << myCards[cardCount];
            cardCount++;
         }
      //cout << endl;
      }
   } 

   void Deck::shuffle(){   // shuffle the deck, all 52 cards present
      unsigned int currentTime = (unsigned)time(0);
      srand(currentTime);
      Card swap;
      int rand1 = 0;
      int rand2 = 0;
      int numCards = size();
      //cout << numCards << '\n';
      for (int k = 0; k < (5*numCards); k++){
         rand1 = rand() % numCards;
         rand2 = rand() % numCards;
         swap = myCards[rand1];
         myCards[rand1] = myCards[rand2];
         myCards[rand2] = swap;     
      }  
   }

   Card Deck::dealCard(){   // get a card, after 52 are dealt, fail 
      myIndex++;
      if (myIndex == 53){
      }   
      else{
      return myCards[getIndex() - 1];
      }
 
   }

   int  Deck::size() const{ // # cards left in the deck
      return (52 - getIndex());
   }
   void Deck::showDeck(){
      for (int k = getIndex(); k < 52; k++){
         cout << myCards[k];
      }
   }

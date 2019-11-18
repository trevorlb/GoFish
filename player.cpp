//Author: Trevor Barrett
//Date: 11/11/2019
//This program implements the functions from the player.h file

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "player.h"
#include "card.h"
#include "deck.h"

using namespace std;

   Player::Player(){
      myName = "";   
   }

   void Player::addCard(Card c){  //adds a card to the hand
      myHand.push_back(c); 
   }
   void Player::bookCards(Card c1, Card c2){
      myBook.push_back(c1);
      myBook.push_back(c2);
      //removeCardFromHand(c1);
      //removeCardFromHand(c2);  
   }

   /*//OPTIONAL    
   //comment out if you decide to not use it
   //this function will check a players hand for a pair. 
   bool checkHandForBook(Card &c1, Card &c2);
   */
   //OPTIONAL
   //comment out if you decide to not use it    
   //Does the player have a card with the same rank as c in her hand?
   bool Player::rankInHand(Card c) const{
      int numCards = myHand.size();
      for (int k = 0; k < numCards; k++){
         if (myHand.at(k).getRank() == c.getRank()){
            return true;
         }
      }
      return false;  
   }
   
   Card Player::sameRankInHand(Card c) const{
      int numCards = myHand.size();
      for (int k = 0; k < numCards; k++){
         if (myHand.at(k).getRank() == c.getRank()){
            Card c = myHand.at(k);
            return c;
         }
      }
   }
   

   //uses some stretegy to choose one card from the player's 
   //hand so they can say "Do you have a 4?"
   Card Player::chooseCardFromHand() const{
      static unsigned int currentTime = (unsigned)time(0);
      currentTime+=10;
      srand(currentTime);
      int rand1 = 0;
      //for (int k = 0; k < (5*myHand.size());k++){
         rand1 = rand() % myHand.size();
         //cout << rand1 << '\n';  
     // }
      return myHand.at(rand1);
   }

   //does the player have the card c in her hand?
   bool Player::cardInHand(Card c) const{
      int numCards = myHand.size();
      for (int k = 0; k < numCards; k++){
         if (myHand.at(k) == c){
            return true;
         }
      }
      return false;
   }

   //Remove the card c from the hand and return it to the caller
   Card Player::removeCardFromHand(Card c){
      int cIndex = 0;
      for(vector<Card>::iterator it = myHand.begin(); it != myHand.end(); it++){
         if ((*it) == c){
            myHand.erase(it);
            return c;
         }
      }
      return c;
   }

   string Player::showHand() const{
      //cout << myHand.size() << '\n';
      Card c;
      string hand = "";  
      for (int k = 0; k < myHand.size(); k++){
         c = myHand.at(k);
         hand += c.rankString(c.getRank());
         hand += c.getSuit(); 
         hand += " "; 
      }
      return hand;
   }

   string Player::showBooks() const{
      for (int k = 0; k < myBook.size(); k++){
         cout << myBook.at(k) << " ";
      }
   } 
    
   int Player::getHandSize() const{
      return myHand.size();
   }
   int Player::getBookSize() const{
      return myBook.size();
   }



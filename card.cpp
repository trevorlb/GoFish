//card.cpp
//Author: Trevor Barrett
//Date: 11/11/2019
//This programs implements all of the empty functions in the card.h file
//
#include "card.h"
#include <iostream>
#include <string>

using namespace std;
   //creates ace of spades when constructor is called empty.
   Card::Card(){          // default, ace of spades
      myRank = 1;
      mySuit = spades;
   }
   
   //constructor when attributes of a card are included 
   Card::Card(int rank, Suit s){
      myRank = rank;
      mySuit = s;
   }

   //uses the rankString and suitString functions to convert the card attributes
   //to a string, and it then returns that string
   string Card::toString() const{  // return string version e.g. Ac 4h Js
      string s;
      s = rankString(myRank);
      s = s + suitString(mySuit);
      return s;
           
   }
   
   //returns true if the two cards have the same suit
   bool Card::sameSuitAs(const Card& c) const{  // true if suit same as c
      return (mySuit == c.mySuit);  
   }

   //returns the rank of a card
   int  Card::getRank() const{  // return rank, 1..13
      return myRank;
   }
   //returns the suit of the card as a string
   string Card::getSuit() const{
      return suitString(mySuit);
   }
   
   //checks each suit individually, then returns the corresponding letter for the suit
   string Card::suitString(Suit s) const{  // return "s", "h",...
      string suit;
      if (s == spades){
         suit = "s";
      }    
      else if (s == hearts){
         suit = "h";
      }
      else if (s == diamonds){
         suit = "d";
      }
      else {
         suit = "c";
      }
      return suit;
   }
   
   //uses string class functions to_string to convert the rank interger to 
   //a string 
   string Card::rankString(int r) const{  // return "A", "2", ..."Q"  
      string rankList[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
      return rankList[r-1];
   }
    
   //checks each attribute of a card object to determine if they are all equal
   bool Card::operator == (const Card& rhs) const{
      return (myRank == rhs.myRank && mySuit == rhs.mySuit);
   }

   //checks each attribute of a card object to determine if any are not equal
   bool Card::operator != (const Card& rhs) const{
      return (myRank == rhs.myRank && mySuit == rhs.mySuit);
   }
   
   //overloads the << of cout to print a card object
   ostream& operator << (ostream& out, const Card& c){
      out << c.rankString(c.getRank()) << c.getSuit() << " ";// << '\n';
      return out;  
   }





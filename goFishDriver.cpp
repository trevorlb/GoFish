//goFishDriver.cpp

#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <fstream>
#include <ctime>

using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void showDeck(Deck &d);

int main( )
{
    ofstream ofile;
    ofile.open("output.txt");
    //oFile << "ryan is dumb" << endl;
    int numCards = 7;
    unsigned int currentTime = (unsigned)time(0);
    //cout << "current: " << currentTime1 << '\n';
    srand(currentTime);   
    Player p1("A");
    Player p2("B");
    
    Deck d;  //create a deck of cards
    d.shuffle();
    //d.showDeck();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    Card c;
    Card c1;
    Card swap; 
    Card temp;  
    //cout << p1.showHand() << endl;
    //cout << p2.showHand() << endl;
    int count = 0;
    while (1){
        ofile << p1.getName() << " holds " << p1.showHand() << '\n';
        ofile << p2.getName() << " holds " << p2.showHand() << '\n' << '\n';
        c = p1.chooseCardFromHand();
        ofile << p1.getName() << " asks - Do you have a " << c.rankString(c.getRank()) << '\n';
        ofile << p2.getName() << " says - ";
        if (p2.rankInHand(c)){
            swap = p2.sameRankInHand(c);
            ofile << "Yes. I have a " << c.rankString(c.getRank()) << '\n';
            (p2.removeCardFromHand(swap));      
            p1.bookCards(c,swap);
            //cout << "made it\n";
            //cout << c << '\n';
            p1.removeCardFromHand(c);
            //cout << swap << '\n';
        }
        else {
            ofile << "Go Fish" << '\n';
            if (d.size() != 0){
               temp = d.dealCard();
               if (p1.rankInHand(temp)){ 
               }
               else {
                  p1.addCard(temp);
               }
            }
        }
        ofile << '\n';

        ofile << p1.getName() << " holds " << p1.showHand() << '\n';
        ofile << p2.getName() << " holds " << p2.showHand() << '\n' << '\n';
        c1 = p2.chooseCardFromHand();
        ofile << p2.getName() << " asks - Do you have a " << c1.rankString(c1.getRank()) << '\n';
        ofile << p1.getName() << " says - ";
        if (p1.rankInHand(c1)){
            swap = p1.sameRankInHand(c1);
            ofile << "Yes. I have a " << c1.rankString(c1.getRank()) << '\n';
            (p1.removeCardFromHand(swap));
            p2.bookCards(c1,swap);
            //cout << "made it\n";
            //cout << c1 << '\n';
            c1 = p2.removeCardFromHand(c1);
            //cout << swap << '\n';
            //p2.removeCardFromHand(swap);
        }
        else {
            ofile << "Go Fish" << '\n';
            if (d.size() != 0){
               temp = d.dealCard();
               if (p2.rankInHand(temp)){ 
               }
               else {
                  p2.addCard(temp);
               }
           }
        }
        ofile << '\n';
        count++;  
    }
    ofile.close();
    return EXIT_SUCCESS;  
}

void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++){
      Card temp = d.dealCard();
      if (p.rankInHand(temp)){}
      else{
      p.addCard(temp);
      }

   }
}

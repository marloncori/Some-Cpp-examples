
#include <iostream>

enum class Suit { Diamonds, Hearts, Clubs, Spades };

void attemptConversions(){
    Suit hand;
    hand = Clubs; // error C2065: 'Clubs' : undeclared identifier
    hand = Suit::Clubs; //Correct.
    int account_num = 135692;
    hand = account_num; // error C2440: '=' : cannot convert from 'int' to 'Suit'
    hand = std::static_cast<Suit>(account_num); // OK, but probably a bug!!!

    account_num = Suit::Hearts; // error C2440: '=' : cannot convert from 'Suit' to 'int'
    account_num = std::static_cast<int>(Suit::Hearts); // OK
 }

int main(){
  
  attemptConversions();
  
  return 0;
}

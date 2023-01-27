#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MIN_RANK  0
#define MAX_RANK  11

#define MIN_SUIT  0
#define MAX_SUIT  3

#define MAX_CARDS 52

enum class Rank { ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum class Suit { SPADES, HEARTS, DIAMONDS, CLUBS};

struct Card {
    Rank rank;
    Suit suit;
};

class Deck {
    private:
        std::vector<Card> cards;
        std::string cardBack;

    public:
        void create();
        void shuffle();
        std::string getSuit(Card& card);
        std::string getRank(Card& card);
        void show();
        void showSome(int qty);
        Card Deck::takeOne();
};

void Deck::create(){
    for(int suit = MIN_SUIT; suit < MAX_SUIT; suit++){
        for(int rank = MIN_RANK; rank < MAX_RANK; rank++){
       
            Card card;
            card.suit = static_cast<Suit>(suit);
            card.rank = static_cast<Rank>(rank);
            cards.push_back(card);
        }
    }
    std::cout << " Deck of cards has been successfully created!\n";
}

std::string Deck::getSuit(Card& card){
    return (card.suit == Suit::SPADES ? "SPADES" : 
             card.suit == Suit::HEARTS ? "HEARTS" :
              card.suit == Suit::CLUBS ? "CLUBS" : "DIAMONDS");
}

std::string Deck::getRank(Card& card){
    return card.rank == Rank::JACK ? "JACK" :
             card.rank == Rank::QUEEN ? "QUEEN" :
                card.rank == Rank::KING ? "KING" : std::to_string(card.rank);
}
void Deck::show(){
    std::cout << " This is how your deck looks like now:\n";
    for (Card& card : cards){
        std::cout << "\t Suit: " << getSuit(card)
           << "\tValue: " << getRank(card) << "\n\t";
    }
}

void Deck::shuffle(){
    std::random_shuffle(cards.begin(), cards.end());
    std::cout << " Deck of cards has been successfully usffled!\n";
}

void Deck::showSome(int qty){
    std::cout << " These are the " << qty << " you wanted me to show you:\n\t";
    for(int card=0; card<qty; card++){
        if(qty > 0 && qty < MAX_CARDS){
            std::cout << "\t Suit: " << getSuit(cards.at(card))
                << "\tValue: " << getRank(cards.at(card)) << "\n\t";
                shuffle();
        }
    }
}

Card Deck::takeOne(){
    shuffle();
    return cards.pop_back();
}
//class Game {
//
//};

int main(){

    Deck* deck = new Deck();
    deck->create();
    deck->shuffle();
    deck->show();
    deck->showSome(15);
    auto card = deck->takeOne();
    std::cout << " Have a look at this card: a " << deck->getSuit(card.suit) << "\t" << deck->getRank(card.rank) << std::endl;

    delete deck;
    return 0;
}
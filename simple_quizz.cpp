#include <iostream>
#include <cstdlib>
#include <fstream>
#include <memory>
#include <array>
#include <vector>
#include <string>
#include <algorithm>

constexpr int MAX_SIZE = 5;

class ErrorMsg {
    private:
        std::string arrayMsg;
        std::string fileMsg;
    public:
        ErrorMsg();
        std::string warning();
        std::string get();
};

ErrorMsg::ErrorMsg(){
    fileMsg = "\n An error happened while \n trying to read file. \n Make sure it exists!";
    arrayMsg = "\n Index out of bounds! The number you provided is larger than the array length!";
}

std::string ErrorMsg::warning(){
    return arrayMsg;
}

std::string ErrorMsg::get(){
    return fileMsg;
}

class Parser {
    private:
        std::string result;
    public:
        Parser();
        void parse(std::string answer);
        std::string getResult();
};

Parser::Parser(){
    result = "";
}
    
void Parser::parse(std::string answer){
    std::transform(answer.begin(),
      answer.end(), answer.begin(), ::tolower);
      result = answer;
}

std::string Parser::getResult(){
    return result;
}

class Contents{
    private:
        std::unique_ptr<ErrorMsg> errorMsg;
        std::string theme;
        std::string nick;
        std::string body[MAX_SIZE];
    public:
        Contents();
        void setBody(int idx, std::string line);
        std::string getBody(int idx);
        std::string getTheme();
        void setTheme(std::string line);
        std::string getNick();
        void setNick(std::string line);
};

Contents::Contents(){
    theme = "";
    nick = "";
    errorMsg = std::make_unique<ErrorMsg>(ErrorMsg());
}

std::string Contents::getBody(int idx){
    if(idx > MAX_SIZE){
        std::cerr << errorMsg->warning() << std::endl;
        idx = 0;
    }
    return body[idx];
}

void Contents::setBody(int idx, std::string line){
    if(idx > MAX_SIZE){
        std::cerr << errorMsg->warning() << std::endl;
        idx = 0;
    }
    body[idx] = line;
}

std::string Contents::getTheme(){
    return theme;
}

void Contents::setTheme(std::string lineNumber){
    theme = lineNumber;
}

std::string Contents::getNick(){
    return nick;
}

void Contents::setNick(std::string lineNumber){
    nick = lineNumber;
}


class Number {
    private:
        int val;
    public:
        Number();
        int takeOne();
        void increment();
};

Number::Number(){
    val = 0;
}

int Number::takeOne(){
    return val;
}

void Number::increment(){
    val++;
}

enum State {
    WRONG,
    RIGHT
};

class Answer {
    private:
        int index;
        std::unique_ptr<ErrorMsg> errorMsg;
        std::string value[MAX_SIZE];
        State state;
    public:
        Answer();
        State getState();
        void solve();
        void store(int idx, std::string line);
        std::string showContents(int idx);
};

Answer::Answer(){
    state = State::WRONG;
    index = 0;
}

State Answer::getState(){
    return state;
}
 
void Answer::solve(){
    state = State::RIGHT;
}

void Answer::store(int idx, std::string line){
    value[idx] = line;
    index++;
    if(index > MAX_SIZE){
        std::cerr << errorMsg->warning() << std::endl;
        index = 0;
   }
}

std::string Answer::showContents(int idx){
    return value[idx];
}


class Handler {
    private:
        std::unique_ptr<Contents> contents;
        std::unique_ptr<ErrorMsg> errorMsg;
        std::unique_ptr<Number> number;
        std::unique_ptr<Parser> validate;
        Answer* answers[MAX_SIZE];
        std::fstream file;
        std::string thisLine;
        int lineNumber;
    public:
        Handler();
        void tryAndLoad();
        std::string displayBody(int index);
        std::string loadAnswer(int idx1, int idx2);
        std::string parse(std::string word);
};

Handler::Handler(){
    file.open("cpp_quizz.txt", std::ios::in);
    contents = std::make_unique<Contents>(Contents());
    for(int i=0; i<5; i++){
        answers[i] = new Answer();
    }
    number = std::make_unique<Number>(Number());
    validate = std::make_unique<Parser>(Parser());
}

void Handler::tryAndLoad(){
    if(!file.good()){
        std::cerr << errorMsg->get() << std::endl;
        exit(0);
    }
    while(std::getline(file, thisLine)){
        switch(lineNumber){
            case 1:
                contents->setTheme(thisLine);
                std::cout << thisLine << std::endl;
                break;
            case 2: 
                contents->setNick(thisLine);
                std::cout << thisLine << std::endl;
                break;
            case 3:
                contents->setBody(number->takeOne(),thisLine);
                std::cout << thisLine << std::endl;
                                std::cout << number->takeOne() << std::endl;
                break;
            case 4: 
                answers[0]->store(number->takeOne(),thisLine);
                std::cout << thisLine << std::endl;
                            std::cout << number->takeOne() << std::endl;
                break;
            case 5:
                answers[1]->store(number->takeOne(), thisLine);
                std::cout << thisLine << std::endl;
                           std::cout << number->takeOne() << std::endl;
                break;
            case 6:
                answers[2]->store(number->takeOne(), thisLine);
                std::cout << thisLine << std::endl;
                         std::cout << number->takeOne() << std::endl;
                break;
            case 7:
                answers[3]->store(number->takeOne(), thisLine);
                std::cout << thisLine << std::endl;
                        std::cout << number->takeOne() << std::endl;
                break;
            case 8:
                answers[4]->store(number->takeOne(), thisLine);
                std::cout << thisLine << std::endl;
                        std::cout << number->takeOne() << std::endl;
                answers[4]->solve();
                break;
        }
        if(lineNumber == 8){
            lineNumber = 2;
            number->increment();
        }
        lineNumber++;
    }
    file.close();
}

std::string Handler::displayBody(int index){
    return contents->getBody(index);
}

std::string Handler::loadAnswer(int idx1, int idx2){
    return answers[idx1]->showContents(idx2);
}

std::string Handler::parse(std::string word){
    validate->parse(word);
    return validate->getResult();
}

class Score {
    private:
        int value;
    public:
        Score();
        int getValue();
        void incrementValue();
};

Score::Score(){
    value = 0;
}

void Score::incrementValue(){
    value++;
}

int Score::getValue(){
    return value;
}

class Quizz {
    private:
        std::unique_ptr<Handler> fileHandler;
        std::unique_ptr<Answer> playerAnswer;
        std::unique_ptr<Score> playerScore;
    public:
        Quizz();
        void init();
        bool load();
        void run();
};

Quizz::Quizz(){
    fileHandler = std::make_unique<Handler>(Handler());
    playerAnswer = std::make_unique<Answer>(Answer());
    playerScore =  std::make_unique<Score>(Score());
}

void Quizz::init(){
    fileHandler->tryAndLoad();
}

bool Quizz::load(){
    bool end = false;
    std::string answer;
     for(int i=0; i<=4; i++){ 
         std::cout << "\n" << fileHandler->displayBody(i) << std::endl;
         for(int k=0; k<=4; k++){
             std::cout << "\n" << fileHandler->loadAnswer(k, i) << std::endl;
        }

        std::cout << "\n What is your answer? " << std::endl;
        std::cin >> answer;
        answer = fileHandler->parse(answer);
        playerAnswer->store(i, answer);
        
        if(answer.compare(fileHandler->loadAnswer(i, 4)) == 0){
            std::cout << "\n Cogratulations!" << std::endl;
             playerScore->incrementValue();
            std::cout << "\n  Your score up to now: " 
              << playerScore->getValue() << " points." << std::endl;
        } else{
            std::cerr << " Your answer was not right..." << std::endl;
        }
       if(i == 4){
         end = true;
       }
    }
   return end;
}

void Quizz::run(){
    bool finish = load();
    if(finish){
        std::cout << "\n\t The quiz has finished. \n" <<
         "        Thank you for playing with us." << std::endl;
    }
}

int main(){
     
     std::cout << "   :::::::::::::::::::::::::: \n    TESTING PROGRAM....\n";
     
     std::unique_ptr<Quizz> quizz = 
        std::make_unique<Quizz>(Quizz());
     
     quizz->init();  
     quizz->run();
    
 return 0;   
}
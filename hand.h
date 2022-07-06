//
//  hand.h
//  RPS
//
//  Created by Tej Thambi on 7/5/22.
//

#ifndef hand_h
#define hand_h
#include <string>
using namespace std;

class hand {
public:
    void setLeft(string choice) {
        left = choice;
    };
    void setRight(string choice) {
        right = choice;
    };
    void setFinal(string choice) {
        finalHand = choice;
    }
    void setName(string username) {
        name = username;
    }
    string getLeft(){
        return left;
    };
    string getRight(){
        return right;
    };
    string getFinal() {
        return finalHand;
    }
    string getName(){
        return name;
    };
private:
    string left, right, finalHand, name;
};



#endif /* hand_h */

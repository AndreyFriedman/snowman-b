// perfect
#include "snowman.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <array>

const int maxNumber = 44444444;
const int minNumber = 11111111;
const int tens = 10;
const int hundred = 100;
const int thousand = 1000;
const int tenThousend = 10000;
const int hundredThousen = 100000;
const int milion = 1000000;
const int tenMilion = 10000000;
const int hunredMilion = 100000000;


using namespace std;
namespace ariel{
    string snowman(int num){
    string man;

    array<string,4> hats = {"\n _===_","  ___\n .....","   _ \n  /_\\","  ___ \n (_*_)"};
    array<string,4> noses = {",",".","_"," "};
    array<string,4> eyes = {".","o","O","-"};
    array<string,4> leftArms = {"<","\\","/"," "};
    array<string,4> rightArms = {">","/","\\"," "};
    array<string,4> torsos = {"( : )","(] [)","(> <)","(   )"};
    array<string,4> bases = {"( : )","(\" \")","(___)","(   )"};

    if(num > maxNumber || num < minNumber){
        throw invalid_argument("Invalid Code");
    }

    
    int base = num%tens;
    int torso = num%hundred / tens;
    int righthand = num%thousand / hundred;
    int lefthand = num%tenThousend / thousand;
    int righteye = num%hundredThousen / tenThousend;
    int lefteye = num%milion / hundredThousen;
    int nose = num%tenMilion / milion;
    int hat = num%hunredMilion / tenMilion;

    if(base>4||torso>4||righthand>4||lefthand>4||righteye>4||lefteye>4||nose>4||hat>4
    ||base<1||torso<1||righthand<1||lefthand<1||righteye<1||lefteye<1||nose<1||hat<1){
        throw invalid_argument("Invalid Code");
    }
    man = man + hats.at(hat-1) + "\n";

    if(lefthand == 1 || lefthand == 3 || lefthand == 4){man = man + " ";}
    else{man = man + leftArms.at(lefthand-1);}
    
    man = man + "(" + eyes.at(lefteye-1) + noses.at(nose-1) + eyes.at(righteye-1) + ")";

    if(righthand == 1 || righthand == 3 || righthand == 4){man = man + " \n";}
    else{man = man + rightArms.at(righthand-1) + "\n";}
    
    if(lefthand == 2 || lefthand == 4){man = man + " ";}
    else{man = man + leftArms.at(lefthand-1);}
    
    man = man + torsos.at(torso-1);

    if(righthand == 2 || righthand == 4){man = man + " \n";}
    else{man = man + rightArms.at(righthand-1) + "\n";}

    man = man + " " + bases.at(base-1);
    
    return man;
    }
}
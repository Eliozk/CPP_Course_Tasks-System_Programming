#ifndef HEXAGON_HPP
#define HEXAGON_HPP

#include <string>
#include <iostream>



namespace ariel {

using namespace std;

class Hexagon {
private:
    int number;
    string tileName;

public:
    // קונסטרקטור שמקבל מספר ושם אריח 
    Hexagon(int num, const string& tile) : number(num), tileName(tile) {}
    // פונקציה להדפסת המשושה
    void printHexagon() const {
        string topBottom = "  _____  ";
        string midTop = " /     \\ ";
        string midUpper = "/       \\";
        string midMiddle = "\\       /";
        string midBottom = " \\_____/ ";
        
        // התאמת השורות כך שהן יכללו את המשאב והמספר בצורה יפה
        string resourceLine = " " + tileName + " ";
        string numberLine = "    " + to_string(number) + "    ";
        
        // הדפסת המשושה
        cout << topBottom << endl;
        cout << midTop << endl;
        cout << "|" << resourceLine << "|" << endl;
        cout << midMiddle << endl;
        cout << "|" << numberLine << "|" << endl;
        cout << midBottom << endl;
    }
};

} // namespace ariel

#endif // HEXAGON_HPP

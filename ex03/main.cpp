#include <iostream>
#include <fstream>
#include <string>
#include "Coordinate.hpp"

using namespace std;

bool gcode(string arg, Coordinate& coordinate)
{
    ifstream fin;
    string str;
    size_t pos1, pos2;

    fin.open(arg);
    if (!fin.good())
    {
        cerr << "Can\'t open file\n";
        return false;
    }
    getline(fin, str);    
    pos1 = str.find_first_of(" ");
    pos2 = str.find_last_of(" ");
    if (pos1 == string::npos || pos2 == string::npos || pos1 == pos2)
        return false;
    coordinate.set(std::atoi(str.substr(0, pos1).c_str()), std::atoi(str.substr(pos1 + 1, pos2 - pos1).c_str()), std::atoi(str.substr(pos2).c_str()));
    while (getline(fin, str))
    {
        if (!coordinate.change(str))
            return false;
    }
    fin.close();
    return true;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Wrong number of arguments! Please, input filename as an argument.\n";
        return -1;
    }
    Coordinate coordinate;
    bool res;
    
    res = gcode(argv[1], coordinate);
    cout << coordinate << endl;
    if (!res)
    {
        cerr << "ERROR SCRIPT\n";
        return -1;
    }
    return 0;
}
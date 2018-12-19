#include <iostream>
#include <fstream>

#include "Reader.h"
#include "TypeList.h"



int main() {
    
//    std::string path = "/Users/irinadmitrieva/Documents/7_semestr/metaprogramming-7-sem/task3/task3/input.txt";
    std::string path = "input.txt";
    typedef TypeList<int, double, char, std::string> TList;
    Reader<TList> reader(path);
    reader.readAndPrintAllLines();
    return 0;
}

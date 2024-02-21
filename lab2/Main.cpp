//
// Created by youngliqui on 21.02.2024.
//


#include "Line.h"
#include "GroupOfLines.h"
#include "Point.h"
#include "iostream"

using namespace std;

int main() {
    Line* line1 = new Line(2, -2, 4);
    Line* line2 = new Line(4, -4, 8);
    Line* line3 = new Line(1, 5, -1);

    GroupOfLines* lines = new GroupOfLines();
    lines->addLine(*line1);
    lines->addLine(*line2);
    lines->addLine(*line3);

    cout << "Lines: ";
    cout << *lines;

}
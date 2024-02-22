//
// Created by youngliqui on 21.02.2024.
//


#include "Line.h"
#include "GroupOfLines.h"
#include "Point.h"
#include "iostream"

using namespace std;

int main() {
    Line *line1 = new Line(2, -2, 4);
    Line *line2 = new Line(4, -4, 8);
    Line *line3 = new Line(1, 5, -1);

    GroupOfLines *lines = new GroupOfLines();
    lines->addLine(*line1);
    lines->addLine(*line2);
    lines->addLine(*line3);

    cout << "Lines: ";
    cout << *lines << endl;

    cout << "Operations:" << endl
         << "line1 + line2: " << *(*line1 + *line2) << endl
         << "line1 - line2: " << *(*line1 - *line2) << endl
         << "line1 * 2: " << *(*line1 * 2.0) << endl
         << "line1 / 2: " << *(*line1 / 2.0) << endl;

    cout << "Lines parallel to line1: ";
    vector<Line> parallel = lines->getParallelLines(*line1);
    for (const auto& line: parallel) {
        cout << line << " ";
    }
    cout << endl;

    cout << "Intersection with OX for line3: " << line3->intersectionWithOX()->toString() << endl;
    cout << "Intersection with OY for line3: " << line3->intersectionWithOY()->toString() << endl;

    cout << "Intersection of line2 and line3: " << line2->intersectionWithLine(*line3)->toString() << endl;

    delete line1, line2, line3, lines;

    return 0;
}
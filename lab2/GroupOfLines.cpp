//
// Created by youngliqui on 21.02.2024.
//
#include "GroupOfLines.h"

void GroupOfLines::addLine(const Line &line) {
    lines.push_back(line);
}

std::vector<Line> GroupOfLines::getParallelLines(const Line &compLine) const {
    std::vector<Line> parallelLines;
    for (const Line &line: lines) {
        if (line.getA() * compLine.getB() - line.getB() * compLine.getA() == 0) {
            parallelLines.push_back(line);
        }
    }

    return parallelLines;
}

GroupOfLines::GroupOfLines() = default;

GroupOfLines::GroupOfLines(const std::vector<Line> &lines) : lines(lines) {}

const std::vector<Line> &GroupOfLines::getLines() const {
    return lines;
}

void GroupOfLines::setLines(const std::vector<Line> &lines) {
    this->lines = lines;
}

std::ostream &operator<<(std::ostream &os, const GroupOfLines &group) {
    os << "lines: ";
    for (int i = 0; i < group.lines.size(); i++) {
        os << group.lines[i] << " ";
    }

    return os;
}




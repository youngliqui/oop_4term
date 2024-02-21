//
// Created by youngliqui on 21.02.2024.
//

#ifndef OOP_4TERM_GROUPOFLINES_H
#define OOP_4TERM_GROUPOFLINES_H

#endif //OOP_4TERM_GROUPOFLINES_H

#include <ostream>
#include "vector"
#include "Line.h"

class GroupOfLines {
public:
    GroupOfLines();

    // explicit - указывает на то, что конструктор класса не может быть использован для неявного преобразования типов.
    // Это означает, что конструктор может быть вызван только явно, с использованием ключевого слова new
    // или при создании объекта класса.
    explicit GroupOfLines(const std::vector<Line> &lines);

    void addLine(const Line& line);
    std::vector<Line> getParallelLines(const Line& compLine) const;

    const std::vector<Line> &getLines() const;

    void setLines(const std::vector<Line> &lines);

    friend std::ostream &operator<<(std::ostream &os, const GroupOfLines &lines);

private:
    std::vector<Line> lines;
};
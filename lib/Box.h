//
// Created by tsb on 1/9/2023.
//

#ifndef BDJ_VACATION_BOX_H
#define BDJ_VACATION_BOX_H


#include <vector>
#include <string>

class Box {
    std::string name;
    std::vector<std::string> souveniers;
    std::vector<Box> boxes;
    Box *parent;

public:
    Box(std::string name, std::vector<Box> boxes, Box *parent);

    explicit Box(std::ifstream &in);

    Box *searchBoxByNameInTree(std::string query);

    void print();
};


#endif //BDJ_VACATION_BOX_H

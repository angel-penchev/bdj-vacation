//
// Created by tsb on 1/9/2023.
//

#include "Box.h"

#include <utility>
#include <fstream>
#include <iostream>

Box::Box(std::string name, std::vector<Box> boxes, Box *parent) : name(std::move(name)), boxes(std::move(boxes)),
                                                                                parent(parent) {}

Box::Box(std::ifstream &in) : name(), boxes(), parent() {
    size_t boxesCount;
    in >> boxesCount;

    for (size_t i = 0; i < boxesCount; i++) {
        std::string boxName;
        in >> boxName;

        Box *boxInTree = this->searchBoxByNameInTree(boxName);
        if (boxInTree == nullptr) {
            this->boxes.push_back(Box(boxName, std::vector<Box>(), this));
            boxInTree = &this->boxes.back();
        }

        size_t souvenirsCount;
        in >> souvenirsCount;

        for (size_t j = 0; j < souvenirsCount; j++) {
            std::string souvenirName;
            in >> souvenirName;

            boxInTree->souveniers.push_back(souvenirName);
        }

        size_t boxBoxesCount;
        in >> boxBoxesCount;

        for (size_t j = 0; j < boxBoxesCount; j++) {
            std::string boxBoxName;
            in >> boxBoxName;

            boxInTree->boxes.push_back(Box(boxBoxName, std::vector<Box>(), boxInTree));
        }
    }
}

Box *Box::searchBoxByNameInTree(std::string query) {
    if (this->name == query) {
        return this;
    }

    for (size_t i = 0; i < this->boxes.size(); i++) {
        Box *box = this->boxes[i].searchBoxByNameInTree(query);
        if (box != nullptr) {
            return box;
        }
    }

    return nullptr;
}

void Box::print() {
    std::cout << this->name << std::endl;
    for (auto & souvenir : this->souveniers) {
        std::cout << souvenir << std::endl;
    }
    for (auto & boxe : this->boxes) {
        boxe.print();
    }
}

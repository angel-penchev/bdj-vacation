#include <iostream>
#include <map>
#include <fstream>
#include "lib/SkipList.h"
#include "lib/Box.h"

int main() {
    // Part A
    size_t citiesCount;
    std::cout << "Брой на градовете през които преминава пътническия влак: ";
    std::cin >> citiesCount;

    std::vector<std::string> cities;
    std::cout << "Имена на градовете: ";
    for (size_t i = 0; i < citiesCount; ++i) {
        std::string city;
        std::cin >> city;
        cities.push_back(city);
    }

    size_t directConnectionsCount;
    std::cout << "Брой на директните връзки между градовете: ";
    std::cin >> directConnectionsCount;

    std::map<std::string, std::string> directConnections;
    std::cout << "Директни връзки: ";
    for (size_t i = 0; i < directConnectionsCount; ++i) {
        std::string city1, city2;
        std::cin >> city1 >> city2;
        directConnections[city1] = city2;
    }

    size_t wishlistCitiesCount;
    std::cout << "Брой на желаните градове: ";
    std::cin >> wishlistCitiesCount;

    std::queue<std::string> wishlistCities;
    std::cout << "Имена на желаните градове: ";
    for (size_t i = 0; i < wishlistCitiesCount; ++i) {
        std::string city;
        std::cin >> city;
        wishlistCities.push(city);
    }

    SkipList citiesList = SkipList(cities, directConnections);
    std::vector<std::string> path = SkipList::findQuickest(citiesList.getFirst(), wishlistCities);

    for (const std::string &city : path) {
        std::cout << city << " ";
    }
    std::cout << std::endl;


    // Part C
    std::ifstream boxesListFile("boxesList.txt", std::ios::in);
    if (!boxesListFile) {
        throw std::runtime_error("Could not open boxesList.txt for reading!");
    }

    Box globalBox = Box(boxesListFile);
//    globalBox.reorder();
    globalBox.print();

    boxesListFile.close();

    return 0;
}

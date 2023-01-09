#include <iostream>
#include <vector>

int main() {
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

    std::vector<std::pair<std::string, std::string>> directConnections;
    std::cout << "Директни връзки: ";
    for (size_t i = 0; i < directConnectionsCount; ++i) {
        std::string city1, city2;
        std::cin >> city1 >> city2;
        directConnections.push_back(std::make_pair(city1, city2));
    }

    size_t wishlistCitiesCount;
    std::cout << "Брой на желаните градове: ";
    std::cin >> wishlistCitiesCount;

    std::vector<std::string> wishlistCities;
    std::cout << "Имена на желаните градове: ";
    for (size_t i = 0; i < wishlistCitiesCount; ++i) {
        std::string city;
        std::cin >> city;
        wishlistCities.push_back(city);
    }

    return 0;
}

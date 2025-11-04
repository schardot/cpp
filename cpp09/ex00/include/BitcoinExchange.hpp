#pragma once
#include <string>
#include <map>
#include <iostream>
class BitcoinExchange
{
private:
    std::map<std::string, float> exchange;

    void loadCSV(std::string csvFile);
    float findValue(const std::string &date);
    void parseInput(std::string inputFile);
    bool validateDate(const std::string &date);

public:
    BitcoinExchange();
    BitcoinExchange(std::string filename);
    BitcoinExchange(const BitcoinExchange &obj);
    BitcoinExchange &operator=(const BitcoinExchange &obj);
    ~BitcoinExchange();

    std::map<std::string, float> getMap() { return exchange; }
};

std::ostream &operator<<(std::ostream &os, BitcoinExchange &obj);
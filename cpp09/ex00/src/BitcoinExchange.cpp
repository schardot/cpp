#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string filename) {
    loadCSV("src/data.csv");
    parseInput(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) : exchange(obj.exchange) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) {
    if (this != &obj) {
        exchange = obj.exchange;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadCSV(std::string csvFile) {
    std::ifstream data(csvFile);
    if (!data)
        throw std::runtime_error("Error, could not open file: " + csvFile);

    std::string line;
    while(std::getline(data, line)) {
        if (line.empty() || (line.find("date") != std::string::npos))
            continue;

        std::replace(line.begin(), line.end(), ',', ' ');
        std::istringstream iss(line);
        std::string date;
        float price;

        if (!(iss >> date >> price)) {
            throw std::runtime_error("loadCsv(): Error bad line: " + line);
        }
        exchange[date] = price;
    }
    data.close();
}

void BitcoinExchange::parseInput(std::string inputFile)
{
    std::ifstream data(inputFile);
    if (!data)
        throw std::runtime_error("Error, could not open file: " + inputFile);

    std::string line;
    while (std::getline(data, line))
    {
        if (line.empty() || (line.find("date") != std::string::npos))
            continue;

        if (line.find('|') == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::replace(line.begin(), line.end(), '|', ' ');
        std::istringstream iss(line);

        std::string date;
        float amount;

        if (!(iss >> date >> amount)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!validateDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (amount < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (amount >= 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        try {
            float price = findValue(date);
            //std::cout << std::fixed << std::setprecision(2);
            std::cout << date << " => " << amount
                      << " = " << price * amount
                      <<  std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    data.close();
}

float BitcoinExchange::findValue(const std::string &date) {
    std::map<std::string, float>::iterator it = exchange.find(date);
    if (it != exchange.end()) {
        return (it->second);
    }

    it = exchange.lower_bound(date);
    if (it == exchange.begin()) {
        throw std::runtime_error("Error: no available date for " + date);
    }
    it--;
    return it->second;
}

bool BitcoinExchange::validateDate(const std::string &fullDate)
{
    std::string date = fullDate;
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;

    std::string yStr = date.substr(0, 4);
    std::string mStr = date.substr(5, 2);
    std::string dStr = date.substr(8, 2);

    int year = std::atoi(yStr.c_str());
    int month = std::atoi(mStr.c_str());
    int day = std::atoi(dStr.c_str());
    if (year == 0 || month == 0 || day == 0)
        return false;

    if (!(month <= 12 && month >= 1) || !(day <= 31 && day >= 1) || year < 2009)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day > daysInMonth[month - 1])
        return false;
    return true;
}

std::ostream &operator<<(std::ostream &os, BitcoinExchange &obj) {
    std::map<std::string, float> map = obj.getMap();
    std::map<std::string, float>::iterator it = map.begin();
    while (it != map.end())
    {
        std::cout << it->first << ", " << it->second << std::endl;
        ++it;
    }
    return os;
}
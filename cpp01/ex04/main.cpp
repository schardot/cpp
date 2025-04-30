#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>
#include <cstring>

std::string replaceIt(std::string line, std::string find, std::string change) {
    size_t pos = 0;
    while (pos != std::string::npos)
    {
        pos = line.find(find);
        if (pos != std::string::npos)
        {
            line.erase(pos, find.length());
            line.insert(pos, change);
        }
    }
    return (line);
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Correct usage: ./replace <filename> <find> <replace> " << std::endl;
        return (1);
    }

    if (std::string(av[2]).empty() || std::string(av[3]).empty())
    {
        std::cout << "Error: <find> and <replace> strings must not be empty." << std::endl;
        return (1);
    }

    std::fstream myFile;

    myFile.open(av[1]);

    std::string line;
    if (myFile.is_open())
    {
        std::string repName = av[1];
        repName.append(".replace");

        std::ofstream replaceFile;
        replaceFile.open(repName.c_str());
        while (std::getline(myFile, line))
        {
            line = replaceIt(line, av[2], av[3]);
            replaceFile << line << std::endl;
        }
        replaceFile.close();
    } else {
        std::cerr << "Failed to open file.\n";
        std::cerr << "Error: " << std::strerror(errno) << "\n";
    }

    myFile.close();
    return (0);
}

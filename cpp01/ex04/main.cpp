#include <iostream>
#include <fstream>
#include <string>

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
        std::cout << "wrong ac: " << ac << std::endl;
        return (1);
    }
    std::string repName = av[1];
    repName.append(".replace");

    std::fstream myFile;
    std::ofstream replaceFile;

    myFile.open(av[1]);
    replaceFile.open(repName.c_str());

    std::string line;
    if (myFile.is_open())
    {
        while (std::getline(myFile, line))
        {
            line = replaceIt(line, av[2], av[3]);
            replaceFile << line << std::endl;
        }
    }

    myFile.close();
    replaceFile.close();
    return (0);
}

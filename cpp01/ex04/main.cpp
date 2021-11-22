#include <fstream>
#include <iostream>

void PrintUsage()
{
    std::cout << "Usage: ./replace [filename] [before string] [after string]" << std::endl;
}

std::string ReadFile(std::string const filename)
{
    std::ifstream ifs(filename);
    if (ifs.fail())
    {
        std::cout << "Failed to open file" << std::endl;
        std::exit(1);
    }
    std::string data = "";
    std::string line;
    while (getline(ifs, line))
    {
        data += (line + '\n');
    }
    return (data);
}

void ReplaceString(std::string &data, std::string const &s1, std::string const &s2)
{
    size_t pos;
    const size_t s1_len = s1.length();
    while (true)
    {
        pos = data.find(s1);
        if (pos == std::string::npos)
        {
            break;
        }
        else
        {
            data.erase(pos, s1_len);
            data.insert(pos, s2);
        }
    }

}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        PrintUsage();
        return (1);
    }
    std::string const filename = argv[1];
    std::string const s1 = argv[2];
    std::string const s2 = argv[3];
    std::string data = ReadFile(filename);
    ReplaceString(data, s1, s2);
    std::ofstream ofs(filename + ".replace");
    ofs << data;
    return (0);
}

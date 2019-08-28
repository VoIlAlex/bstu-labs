#include <fstream>
#include <windows.h>
#include <random>
#include <iostream>

void fillRandomly(std::fstream& stream);
size_t findSize(std::fstream& stream);
void inverse(std::fstream& stream);

int main()
{
    std::fstream fsTrash {"Y:/trash", std::ios::out | std::ios::in| std::ios::binary };
    if (!fsTrash)
    {
        std::cout << "Error while opening!" << std::endl;
    }
    std::cout << "Size of file: " << findSize(fsTrash);
    fillRandomly(fsTrash);
    inverse(fsTrash);
    fillRandomly(fsTrash);
    system("pause");
}

size_t findSize(std::fstream& stream)
{
    auto init_pos = stream.tellg();
    stream.seekg(0, std::ios::end);
    size_t end = stream.tellg();
    stream.seekg(0, std::ios::beg);
    size_t begin = stream.tellg();
    stream.seekg(init_pos);
    return end - begin;
}

void fillRandomly(std::fstream& stream)
{
    size_t size = findSize(stream);
        
    stream.seekp(stream.end);
    char random_byte;
    std::default_random_engine gen;
    for(size_t i = 0; i < size; i++)
    {
        random_byte = gen();
        stream.write(&(random_byte), sizeof(char));
    }
}

void inverse(std::fstream& stream)
{
    size_t size = findSize(stream);
    char symbol;
    stream.seekg(stream.beg);
    stream.seekp(stream.beg);
    for(size_t i = 0; i < size; i++)
    {
        stream.read(&symbol, sizeof(char));
        symbol = ~symbol;
        stream.write(&symbol, sizeof(char));
    }    
}
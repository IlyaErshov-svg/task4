#include <iostream>
#include <vector>
//#include "stdlib. h"


/// Генерируем путь с ответвлениями
/// \param map
void make_path(std::vector<std::vector<int>>& map)
{
    map[1][0] = 0;
    map[map.size() - 1][map[0].size() - 2] = 0;
    int i = 1; int j = 1;
    while(i !=  map.size() - 1 || j != map[0].size() - 2)
    {
        map[i][j] = 0;
        int ran = rand() % 4;
        if(ran == 0 && map[i + 1][j] != 2 && i < map.size())
        {
            i++;
        }else if(ran == 1 && map[i - 1][j] != 2 && i >= 0) {
            i--;
        }else if(ran == 2 && map[i][j - 1] != 2 && j >= 0){
            j--;
        }else if(ran == 3 && map[i][j + 1] != 2 && j < map[0].size()){
            j++;
        }
    }
}


/// Генерация карты
/// \param w ширина
/// \param h длина
/// \return карта
std::vector<std::vector<int>> generate_lab(std::size_t w, std::size_t h)
{
    std::vector<std::vector<int>> result;
    for(int i = 0; i < w; ++i)
    {
        std::vector<int> temp;
        for(int j = 0; j < h; ++j)
        {
            if(i == 0 || j == 0 || i == w - 1|| j == h - 1)
            {
                temp.push_back(2);
            }else{
                temp.push_back(1);
            }
        }
        result.push_back(temp);
    }
    make_path(result);
    return result;
}


/// Вывод карты
/// \param map карта
void print_map(std::vector<std::vector<int>> map)
{
    for(int i = 0; i < map.size(); ++i)
    {
        for(int j = 0; j < map[0].size(); ++j)
        {
            if(map[i][j] == 0)
            {
                std::cout << ' ';
            }else{
                std::cout << '#';
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    std::size_t i, j;
    std::cin >> i >> j;
    if(i < 6 || j < 6 || i % 2 == 0 || j % 2 == 0){
        std::cerr << "Invalid parameters";
        return 0;
    }
    std::vector<std::vector<int>> map = generate_lab(i, j);
    print_map(map);
    return 0;
}

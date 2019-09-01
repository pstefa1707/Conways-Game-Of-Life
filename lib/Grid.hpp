#include <vector>
#include "SFML/Graphics.hpp"
#include <iostream>

class Cell;
class Grid
{
    private:
        int _width;
        int _height;
        sf::Vector2f _cell_size;
        int _get_neighbours(int& x_pos, int& y_pos);
    public:
        void step();
        int width();
        int height();
        sf::Vector2f cell_size();
        enum class status{dead, alive};
        std::vector<status> cells;
    private:
        std::vector<status> _temp;
    public:
        Grid(int& width, int& height, float& screen_width, float& screen_height)
        {
            _width = width;
            _height = height;
            cells.resize(width * height);
            _temp.resize(width * height);
            _cell_size = sf::Vector2f(screen_width/width, screen_height/height);

        }
        void populate();
};
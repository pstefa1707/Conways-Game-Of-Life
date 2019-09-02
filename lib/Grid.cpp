#include "Grid.hpp"
#include "SFML/Graphics.hpp"

class Cell;
void Grid::populate()
{
    for (int x = 0; x < this->_width; x++)
    {
        for (int y = 0; y < this->_height; y++)
        {
            if (rand()%100 < 20)
            {
                this->cells[y * this->_width + x] = status::alive;
            }
            else
            {
                this->cells[y * this->_width + x] = status::dead;
            }
            
        }
    }
}

int Grid::height()
{
    return this->_height;
}

int Grid::width()
{
    return this->_width;
}

sf::Vector2f Grid::cell_size()
{
    return this->_cell_size;
}

int Grid::_get_neighbours(int& x_pos, int& y_pos)
{
    unsigned int count = 0;
    for (int x = -1; x < 2; x++)
    {
        for (int y = -1; y < 2; y++)
        {
            int new_x = x_pos + x;
            int new_y = y_pos + y;
            if (new_x == x_pos && new_y == y_pos) continue;
            if (new_x < 0) new_x = this->_width + new_x;
            if (new_y < 0) new_y = this->_height + new_y;
            if (new_x >= this->_width) new_x = new_x % this->_width;
            if (new_y >= this->_height) new_y = new_y % this->_height;

            if (this->cells[new_y * this->_width + new_x] == status::alive) count++;
        }
    }
    return count;
}

void Grid::step()
{
    this->_temp = this->cells;
    #pragma omp parallel for
    for (int x = 0; x < this->_width; x++)
    {
        for (int y = 0; y < this->_height; y++)
        {
            unsigned int neighbours = this->_get_neighbours(x, y);
            if (neighbours <= 1 && this->cells[y * this->_width + x] == status::alive)
            {
                this->_temp[y * this->_width + x] = status::dead;
            }
            else if (neighbours >= 4 && this->cells[y * this->_width + x] == status::alive)
            {
                this->_temp[y * this->_width + x] = status::dead;
            }
            else if (neighbours == 3 && this->cells[y * this->_width + x] == status::dead)
            {
                this->_temp[y * this->_width + x] = status::alive;
            }
        }
    }
    this->cells = this->_temp;
}

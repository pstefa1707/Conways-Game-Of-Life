#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "lib/Grid.hpp"


class Grid;
int main()
{
    float window_width = 800;
    float window_height = 800;
    int grid_width = 400;
    int grid_height = 400;

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Pstefa's Game of Life");
    //window.setFramerateLimit(144);
    Grid grid(grid_width, grid_height, window_width, window_height);
    grid.populate();
    sf::Event event;

    sf::Clock CLOCK;
    CLOCK.restart();

    window.clear(sf::Color::White);
    
    while(true)
    {
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            grid.populate();
            window.clear(sf::Color::White);
        }

        for (sf::Vector2i index: grid.step())
        {
            sf::RectangleShape rect;
            if (grid.cells[index.y * grid.width() + index.x] == Grid::status::alive) rect.setFillColor(sf::Color::Black);
            else rect.setFillColor(sf::Color::White);
            rect.setSize(grid.cell_size());
            rect.setPosition(sf::Vector2f(grid.cell_size().x * index.x, grid.cell_size().y * index.y));
            window.draw(rect);
        }

        std::cout << "Frame rate: " << std::to_string(1 / CLOCK.restart().asSeconds()) << std::endl;

        window.display();
    }
}

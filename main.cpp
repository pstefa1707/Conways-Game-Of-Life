#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "lib/Grid.hpp"


class Grid;
int main()
{
    float window_width = 800;
    float window_height = 800;
    int grid_width = 200;
    int grid_height = 200;
	sf::Font arial;
	arial.loadFromFile("./lib/arial.ttf");
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Pstefa's Game of Life");
    //window.setFramerateLimit(144);
    Grid grid(grid_width, grid_height, window_width, window_height);
    grid.populate();
    sf::Event event;

    sf::Clock CLOCK;
    CLOCK.restart();

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) grid.populate();
        window.clear(sf::Color::White);
        for (int x = 0; x < grid.width(); x++)
        {
            for (int y = 0; y < grid.height(); y++)
            {
                if (grid.cells[y * grid.width() + x] == Grid::status::alive)
                {
                    sf::RectangleShape rect;
                    rect.setFillColor(sf::Color::Black);
                    rect.setSize(grid.cell_size());
                    rect.setPosition(sf::Vector2f(grid.cell_size().x * x, grid.cell_size().y * y));
                    window.draw(rect);
                }
            }
        }
        
	    std::string fps = "FPS: " + std::to_string(1 / CLOCK.restart().asSeconds());
	    sf::Text FPS(fps, arial, 30);
        FPS.setFillColor(sf::Color::Black);
        FPS.setPosition(sf::Vector2f(window_width - 200, window_height - 35));
        window.draw(FPS);

        grid.step();
        window.display();
    }
}

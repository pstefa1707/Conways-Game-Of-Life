# Conways-Game-Of-Life
Conway's Game of Life, written in c++ SFML

Makes use of OpenMp parallel processing of for loops.

Can simulate 40k cells at ~ 800 generations per second, 1 million cells at ~ 40 generations per second. **i7 8700k**

[PROOF](https://i.ibb.co/tmJgdNp/1m-cells.png)

## Dependancies

**Linux** - `sudo apt install libsfml-dev` 

**Windows** - Link SFML libraries and compile.

## How to compile

**Linux** navigate to directory and use `make` command. Compilation is done automatically.

## Usage
Set number of cells wide/high in main.cpp

Set width of render window in pixels wide/high in main.cpp

`Space` Re-populates the grid randomly

## Screenshot
![Screenshot](https://i.ibb.co/VV7CHnn/Game-of-Life.png)

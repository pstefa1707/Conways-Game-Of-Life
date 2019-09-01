#include "Cell.hpp"

Cell::Type Cell::get_type()
{
    return this->_type;
}

void Cell::set_type(Cell::Type type)
{
    this->_type = type;
}
#include "Coordinate.h"

Coordinate::Coordinate(int row, int col) : row(row), col(col) {}

int Coordinate::getRow() const { return row; }

int Coordinate::getCol() const { return col; }

string Coordinate::toString() const {
    ostringstream rowConvert;
    ostringstream colConvert;
    rowConvert << row;
    colConvert << col;
    return rowConvert.str() + ", " + colConvert.str();
}


Coordinate Coordinate::sum(Coordinate *col) const {
    return Coordinate(this->getRow() + col->getRow(), this->getCol() + col->getCol());
}

Coordinate *Coordinate::getDirectionTo(Coordinate *to) const {
    int fromRow = this->getRow();
    int fromCol = this->getCol();
    return new Coordinate(to->getRow() - fromRow, to->getCol() - fromCol);
}

bool Coordinate::operator==(const Coordinate& coord2) {
    return (getRow() == coord2.getRow()) && (getCol() == coord2.getCol());
}

bool Coordinate::operator !=(const Coordinate& coord2) {
    return !this->operator==(coord2);
}

Coordinate *Coordinate::clone() const {
    return new Coordinate(this->getRow(), this->getCol());
}

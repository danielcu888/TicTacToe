#include "Player.hpp"
#include <vector>
#include <cstddef>
#include "constants.hpp"
#include <stdexcept>

using std::vector;
using std::size_t;
using std::out_of_range;
using std::logic_error;

Player::Player(bool c, vector<vector<int> >& v)
  : token(c), ptrGrid(&v)
{}

void Player::select(size_t x, size_t y)
{
  if(x >= Constants::DIMENSION ||
     y >= Constants::DIMENSION)
    throw logic_error("Player::select() - selected coordinates out of range!");
  else if((*ptrGrid)[x][y] != -1)
    throw logic_error("Player::select() - selected coordinate already occupied!");
  else
    (*ptrGrid)[x][y] = token == 0 ? 0 : 1;
}


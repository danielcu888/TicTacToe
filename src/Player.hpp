#ifndef GUARD_PLAYER_HPP
#define GUARD_PLAYER_HPP

#include <vector>
#include <cstddef>

class Player
{
public:
  explicit Player(bool, std::vector<std::vector<int> >&);

  void select(std::size_t, std::size_t);

private:
  bool token;
  std::vector<std::vector<int> >* ptrGrid;
};

#endif

#ifndef GUARD_TOKEN_HPP
#define GUARD_TOKEN_HPP

#include <string>
#include <vector>

class Nought
{
public:
  static Nought getInstance()
  {
    return Nought();
  }

  const std::string getLine(std::vector<std::string>::size_type);

private:
  Nought();
 
  std::vector<std::string> v;
};

class Cross
{
public:
  static Cross getInstance()
  {
    return Cross();
  }

  const std::string getLine(std::vector<std::string>::size_type);

private:
  Cross();

  std::vector<std::string> v;
};

#endif

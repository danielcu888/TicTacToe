#include "token.hpp"
#include <vector>
#include <string>
#include <stdexcept>

using std::vector; using std::string;
using std::out_of_range;

Nought::Nought()
  : v(vector<string>())
{
  v.push_back("  xxx  ");
  v.push_back(" x   x ");
  v.push_back(" x   x ");
  v.push_back(" x   x ");
  v.push_back("  xxx  ");
}

const string Nought::getLine(vector<string>::size_type i)
{
  if(i > v.size())
    throw out_of_range("Token::getLine() - index out of range!");
  return v[i];
}

Cross::Cross()
  : v(vector<string>())
{
  v.push_back(" x   x ");
  v.push_back("  x x  ");
  v.push_back("   x   ");
  v.push_back("  x x  ");
  v.push_back(" x   x ");
}

const string Cross::getLine(vector<string>::size_type i)
{
  if(i > v.size())
    throw out_of_range("Token::getLine() - index out of range!");
  return v[i];
}

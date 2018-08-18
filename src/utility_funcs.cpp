#include "constants.hpp"
#include "token.hpp"
#include <vector>
#include <iostream>
#include "utility_funcs.hpp"
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <string>

using std::ostream;
using std::ifstream;
using std::vector;
using std::max;
using std::logic_error;
using std::endl;
using std::string;

string::size_type max_wd(const vector<string>& v)
{
  string::size_type m = 0;
  for(vector<string>::size_type i = 0; i != v.size(); ++i)
    m = max(m, v[i].size());
  return m;
}

vector<string> centre(const vector<string>& v)
{
  vector<string> ret;
  string::size_type wd = max_wd(v);
  for(vector<string>::size_type i = 0; i != v.size(); ++i)
    {
      string spaces1((wd - v[i].size())/2, ' '), spaces2(wd - v[i].size() - spaces1.size(), ' ');
      ret.push_back(spaces1 + v[i] + spaces2);
    }
  return ret;
}

vector<string> frame(const vector<string>& v, char c)
{
  vector<string> ret;
  string::size_type wd = max_wd(v);
  ret.push_back(string(wd + 4, c));
  for(vector<string>::size_type i = 0; i != v.size(); ++i)
    ret.push_back(string(1, c) + " " + v[i] + " " + string(1, c));
  ret.push_back(string(wd + 4, c));
  return ret;
}

std::vector<std::vector<int> > construct_grid(std::size_t dim)
{
  vector<vector<int> > ret;
  for(vector<vector<int> >::size_type i = 0; i != dim; ++i)
      ret.push_back(vector<int>(dim, -1));
  return ret;
}

void display_message(ostream& os, const char* filename)
{
  os << endl;
  os << endl;
  ifstream infile(filename);
  if(!infile) throw logic_error("file not found!");
  vector<string> message;
  string line;
  while(getline(infile, line))
    message.push_back(line);
  message = centre(message);
  message = frame(message, '*');
  for(vector<string>::size_type i = 0; i != message.size(); ++i)
    os << message[i] << endl;
  os << endl;
  os << endl;
}

void display_grid(ostream& os, const vector<vector<int> >& grid)
{
  static const vector<string>::size_type num_rows = 1 + Constants::DIMENSION*(Constants::HEIGHT + 3);
  static const string::size_type num_cols = 1 + Constants::DIMENSION*(Constants::WIDTH + 3);
  static const string border(num_cols, '-');
  static const string empty(Constants::WIDTH + 2, ' ');
  string tmp;
  for(int i = 0; i != Constants::DIMENSION; ++i)
    tmp += "|" + empty;
  tmp += "|";
  static const string innerborder(tmp);
 
  vector<string> ret;

  for(vector<vector<int> >::size_type i = 0; i != Constants::DIMENSION; ++i) //1,2,3 rows of grid
    {
      ret.push_back(border); //top border of each row
      ret.push_back(innerborder); //inner border for each row
      for(vector<string>::size_type j = 0; j != Constants::HEIGHT; ++j) //each row of token
        {
          string line;
          for(vector<int>::size_type k = 0; k != Constants::DIMENSION; ++k) //1,2,3 cols of grid
            {
              if(grid[i][k] == 0)
                line += "|" + Nought::getInstance().getLine(j);
              else if(grid[i][k] == 1)
                line += "|" + Cross::getInstance().getLine(j);
              else
                line += "|" + empty;
            }
          line += "|";
          ret.push_back(line);
        }
      ret.push_back(innerborder);
    }
  ret.push_back(border);

  for(vector<string>::size_type i = 0; i != ret.size(); ++i)
    os << ret[i] << endl;
  os << endl;
}

bool is_draw(const vector<vector<int> >& v)
{
  for(vector<vector<int> >::size_type i = 0; i != v.size(); ++i)
    for(vector<int>::size_type j = 0; j != v[i].size(); ++j)
      if(v[i][j] == -1) return false;
  return true;
}

int status(const vector<vector<int> >& v)
{
  for(vector<vector<int> >::size_type i = 0; i != v.size(); ++i)
    {
      for(vector<int>::size_type j = 0; j != v[i].size(); ++j)
	{
	  int row = i, col = j;
	  int val = v[row][col];
	  if(val == -1) continue;
	  
	  int count = 1;
	  
	  //check left
	  while(count < 3) 
	    {
	      --row;
	      if(row >= 0 && v[row][col] == val) 
		++count;
	      else
		{
		  row = i;
		  count = 1;
		  break;
		}
	    }
	  if(count == 3) return val;

	  //check right
	  while(count < 3)
	    {
	      ++row;
	      if(row < Constants::DIMENSION && v[row][col] == val)
		++count;
	      else
		{
		  row = i;
		  count = 1;
		  break;
		}
	    }
	  if(count == 3) return val;

	  //check down
	  while(count < 3)
	    {
	      ++col;
	      if(col < Constants::DIMENSION && v[row][col] == val)
		++count;
	      else
		{
		  col = j;
		  count = 1;
		  break;
		}
	    }
	  if(count == 3) return val;

	  //check up
	  while(count < 3)
	    {
	      --col;
	      if(col >= 0 && v[row][col] == val)
		++count;
	      else
		{
		  col = j;
		  count = 1;
		  break;
		}
	    }
	  if(count == 3) return val;

	  //check left down
	  while(count < 3)
	    {
	      --row;
	      ++col;
	      if(row >= 0 && col < Constants::DIMENSION && v[row][col] == val)
		++count;
	      else
		{
		  row = i;
		  col = j;
		  count = 1;
		  break;
		}
	    }
	  if(count == 3) return val;

	  //check right down
	  while(count < 3)
	    {
	      ++row;
	      ++col;
	      if(row < Constants::DIMENSION && col < Constants::DIMENSION && v[row][col] == val)
		++count;
	      else
		{
		  row = i;
		  col = j;
		  count = 1;
		  break;
		}
	    }
	  if(count == 3) return val;

	  //check left up
	  while(count < 3)
	    {
	      --row;
	      --col;
	      if(row >= 0 && col >= 0 && v[row][col] == val)
		++count;
	      else
		{
		  row = i;
		  col = j;
		  count = 1;
		  break;
		}
	    }
	  if(count == 3) return val;

	  //check right up
	  while(count < 3)
	    {
	      ++row;
	      --col;
	      if(row < Constants::DIMENSION && col >= 0 && v[row][col] == val)
		++count;
	      else
		{
		  row = i;
		  col = j;
		  count = 1;
		  break;
		}
	    }
	  if(count == 3) return val;
	}
    }
  return -1;
}

int stringToInteger(const string& s)
{
  if(s.size() == 0) return -1;
  string::size_type idx = 0;
  int result = 0;
  while(idx < s.size())
    {
      result *= 10;
      int inc = static_cast<int>(s[idx++]) - 48;
      if(inc > 9) return -1;
      result += inc;
    }
  return result;
}

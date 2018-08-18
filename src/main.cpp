#include "utility_funcs.hpp"
#include <iostream>
#include "constants.hpp"
#include "Player.hpp"
#include <vector>
#include <string>
#include <stdexcept>
#include "token.hpp"

using std::cout; using std::cin;
using std::endl; using std::vector;
using std::string; using std::logic_error;

int main(int argc, char** argv)
{
  display_message(cout, "messages/welcome_message.txt");

  vector<vector<int> > grid(construct_grid(Constants::DIMENSION));
  Player p1(true, grid);
  Player p2(false, grid);

  bool p1Turn = true;
  display_grid(cout, grid);

  do {
    string x_coor_str, y_coor_str;
    string curr_player = p1Turn ? "Player 1" : "Player 2";

    cout << curr_player << ", please specify x, y coordinate (1 <= [x, y] <= " << Constants::DIMENSION << "),\n"
      "separated by a space and followed by RETURN: ";
    cin >> x_coor_str >> y_coor_str;

    int x_coor = stringToInteger(x_coor_str), y_coor = stringToInteger(y_coor_str);
    while(x_coor < 1 || x_coor > Constants::DIMENSION || 
	  y_coor < 1 || y_coor > Constants::DIMENSION)
      {
	cout << "invalid entry, please try again: ";
	cin >> x_coor_str >> y_coor_str;
	x_coor = stringToInteger(x_coor_str);
	y_coor = stringToInteger(y_coor_str);
      }

    if(p1Turn)
      {
	try {
	  p1.select(y_coor-1, x_coor-1);
	} catch(logic_error) {
	  cout << "selected coordinate already occupied, please try again..." << endl;
	  continue;
	}
      }
    else
      {
	try {
	  p2.select(y_coor-1, x_coor-1);
	} catch(logic_error) {
	  cout << "selected coordinate already occupied, please try again..." << endl;
	  continue;
	}
      }
    system("clear");
    display_grid(cout, grid);
    p1Turn = (!p1Turn);
  } while(!is_draw(grid) && status(grid) == -1);

  if(is_draw(grid))
      display_message(cout, "messages/Draw.txt");
  else if(!p1Turn)
    display_message(cout, "messages/P1Wins.txt");
  else
    display_message(cout, "messages/P2Wins.txt");
  
  display_message(cout, "messages/goodbye_message.txt");

  return 0;
}

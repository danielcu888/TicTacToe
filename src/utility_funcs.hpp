#include <vector>
#include <iostream>
#include <string>
#include <cstddef>

std::string::size_type max_wd(const std::vector<std::string>&);
std::vector<std::string> centre(const std::vector<std::string>&);
std::vector<std::string> frame(const std::vector<std::string>&, char);
std::vector<std::vector<int> > construct_grid(std::size_t);
void display_message(std::ostream&, const char*);
void display_grid(std::ostream&, const std::vector<std::vector<int> >&);
int status(const std::vector<std::vector<int> >&);
bool is_draw(const std::vector<std::vector<int> >&);
int stringToInteger(const std::string&);

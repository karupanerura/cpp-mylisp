#include <iostream>
#include <string>
#include "parser.hpp"

int main (void) {
  std::string src;
  std::cin >> src;

  mylisp::parser::lexer l (src);
  l.tokenize();

  std::cout
    << "OK"
    << std::endl;

  return 0;
}

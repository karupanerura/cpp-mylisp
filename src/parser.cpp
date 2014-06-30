#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "parser.hpp"
#include "parser/exception.hpp"

using namespace mylisp::parser;

lexer::lexer (std::string& src)
  : c(std::make_shared<context::interface>(new context::global()))
  , src(src)
  , p(src.begin()) {
}

std::vector<token::interface> lexer::tokenize () {
  std::vector<token::interface> tokens;
  while (auto token = this->scan()) {
    tokens->push_back(token);
  }
  return tokens;
}

token::interface lexer::scan () {
  auto start = this->p;
  auto end   = this->src.end();
  if (start == end) {
    return std::make_shared<context::interface>(nullptr);
  }

  try {
    return this->c->scan(this->c, start, end);
  }
  catch (mylisp::parser::exception::unexpected_token e) {
    std::cerr << e.what() << std::endl;
    abort();
  }
}

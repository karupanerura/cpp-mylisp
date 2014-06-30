#pragma once
#include "exception.hpp"
#include <sstream>

using namespace mylisp::parser::exception;

unexpected_token::unexpected_token (const std::string& token_str) {
  std::ostringstream stream;
  stream << "unexpected token: '" << token_str << "'";
  this->msg = stream.str();
}

unexpected_token::~unexpected_token () {
}

const char* unexpected_token::what () {
  return this->msg.c_str();
}

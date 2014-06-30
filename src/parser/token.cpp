#include <string>
#include "token.hpp"

using namespace mylisp::parser::token;

// c
base::base (const std::string& token_str) : value(token_str) {}

// space
const std::string space::expected (" ");
bool space::is_match() {
  return this->expected.compare(this->value) == 0;
}

// new_line
const std::string new_line::expected ("\n");
bool new_line::is_match() {
  return this->expected.compare(this->value) == 0;
}

// quote
const std::string quote::expected ("'");
bool quote::is_match() {
  return this->expected.compare(this->value) == 0;
}

// list::begin
const std::string list::begin::expected ("(");
bool list::begin::is_match() {
  return this->expected.compare(this->value) == 0;
}

// list::end
const std::string list::end::expected (")");
bool list::end::is_match() {
  return this->expected.compare(this->value) == 0;
}

// atom::integer
bool atom::integer::is_match() {
  try {
    std::stoi(this->value);
    return true;
  }
  catch (std::invalid_argument e) {
    return false;
  }
}

// atom::symbol
bool atom::symbol::is_match() {
  return true;
}

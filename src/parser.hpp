// #pragma once
#include <string>
#include <vector>
#include <memory>
#include "parser/context.hpp"
#include "parser/token.hpp"

namespace mylisp {
  namespace parser {
    class lexer
    {
    protected:
      std::shared_ptr<mylisp::parser::context::interface> c;
      const std::string& src;
      std::string::iterator p;

      mylisp::parser::token::interface scan ();

    public:
      lexer (std::string& src);

      std::vector<mylisp::parser::token::interface> tokenize ();
    };
  }
}


#include <string>
#include "token.hpp"
#include "context.hpp"
#include "exception.hpp"

using namespace mylisp::parser::context;

// base
base::base (std::shared_ptr<base> super_context)
  : super_context(super_context) {
}

// TODO: more better code...
mylisp::parser::token::interface global::scan(
  std::shared_ptr<interface> &self,
  std::string::iterator &i,
  const std::string::iterator &end) {
  std::string::iterator start = i;

  while (i++ != end) {
    const std::string str (start, i);
    {
      mylisp::parser::token::new_line token (str);
      if (token.is_match()) {
        start = i;
        continue;
      }
    }

    {
      mylisp::parser::token::space token (str);
      if (token.is_match()) {
        start = i;
        continue;
      }
    }

    {
      mylisp::parser::token::quote token (str);
      if (token.is_match()) {
        self = std::make_shared(new quote(std::make_shared(this)));
        return token;
      }
    }

    {
      mylisp::parser::token::list::begin token (str);
      if (token.is_match()) {
        self = std::make_shared(new list(std::make_shared(this)));
        return token;
      }
    }

    throw mylisp::parser::exception::unexpected_token(str);
  }

  return 0;
}

// TODO: more better code...
mylisp::parser::token::interface quote::scan(
  std::shared_ptr<interface> &self,
  std::string::iterator &i,
  const std::string::iterator &end) {
  std::string::iterator start = i++;

  const std::string str (start, i);
  {
    mylisp::parser::token::new_line token (str);
    if (token.is_match()) {
      throw mylisp::parser::exception::unexpected_token(str);
    }
  }

  {
    mylisp::parser::token::space token (str);
    if (token.is_match()) {
      throw mylisp::parser::exception::unexpected_token(str);
    }
  }

  {
    mylisp::parser::token::list::begin token (str);
    if (token.is_match()) {
      self = std::make_shared(new list(this->super_context));
      return token;
    }
  }

  while (i != end) {
    const std::string s (1, *i++);
    {
      mylisp::parser::token::new_line token (s);
      if (token.is_match()) {
        break;
      }
    }

    {
      mylisp::parser::token::space token (s);
      if (token.is_match()) {
        break;
      }
    }
  }

  if (i != end) {
    const std::string str (i, --j);
    mylisp::parser::token::atom::symbol token (str);
    if (token.is_match()) {
      self = this->super_context;
      return token;
    }
  }

  return 0;
}

// TODO: more better code...
mylisp::parser::token::interface list::scan(
  std::shared_ptr<interface> &self,
  std::string::iterator &i,
  const std::string::iterator &end) {
  std::string::iterator start = i;

  while (i++ != end) {
    const std::string str (start, i);
    {
      mylisp::parser::token::new_line token (str);
      if (token.is_match()) {
        start = i;
        continue;
      }
    }

    {
      mylisp::parser::token::space token (str);
      if (token.is_match()) {
        start = i;
        continue;
      }
    }

    {
      mylisp::parser::token::list::begin token (str);
      if (token.is_match()) {
        self = std::make_shared(new list(this->super_context));
        return token;
      }
    }

    {
      mylisp::parser::token::list::end token (str);
      if (token.is_match()) {
        self = this->super_context;
        return token;
      }
    }

    while (i != end) {
      const std::string s (1, *i++);
      {
        mylisp::parser::token::new_line token (s);
        if (token.is_match()) {
          break;
        }
      }

      {
        mylisp::parser::token::space token (s);
        if (token.is_match()) {
          break;
        }
      }
    }

    if (i != end) {
      const std::string str (i, --j);
      mylisp::parser::token::atom::symbol token (str);
      if (token.is_match()) {
        self = this->super_context;
        return token;
      }
    }

    return 0;
  }

  return 0;
}

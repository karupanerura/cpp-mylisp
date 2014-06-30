#pragma once
#include <string>
#include <exception>

namespace mylisp {
  namespace parser {
    namespace exception {
      class unexpected_token : public std::exception {
      protected:
        std::string msg;
      public:
        unexpected_token  (const std::string& token_str);
        virtual ~unexpected_token () throw ();
        const char* what () const throw ();
      };
    }
  }
}



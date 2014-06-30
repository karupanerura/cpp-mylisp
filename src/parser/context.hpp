#ifndef INTERNAL_CONTEXT_GURAD
#define INTERNAL_CONTEXT_GURAD
#include <string>
#include <exception>
#include "token.hpp"

namespace mylisp {
  namespace parser {
    namespace context {

      class interface {
      public:
        virtual mylisp::parser::token::interface scan(
          std::shared_ptr<interface> &self,
          std::string::iterator &i,
          const std::string::iterator &end
        ) = 0;
      };

      class global : public interface {
      public:
        mylisp::parser::token::interface scan(
          std::shared_ptr<interface> &self,
          std::string::iterator &i,
          const std::string::iterator &end
        );
      };

      class base : public interface {
      protected:
        std::shared_ptr<base> super_context;
      public:
        base (std::shared_ptr<base> super_context);
      };

      class list : public base {
      public:
        mylisp::parser::token::interface scan(
          std::shared_ptr<interface> &self,
          std::string::iterator &i,
          const std::string::iterator &end
        );
      };

      class quote : public base {
      public:
        mylisp::parser::token::interface scan(
          std::shared_ptr<interface> &self,
          std::string::iterator &i,
          const std::string::iterator &end
        );
      };
    }
  }
}

#endif

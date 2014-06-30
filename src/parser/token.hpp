#pragma once
#include <string>

namespace mylisp {
  namespace parser {
    namespace token {
      class interface {
      public:
        virtual bool is_match() = 0;
      };

      class base : public interface {
      protected:
        const std::string& value;
      public:
        base (const std::string& token_str);
      };

      class space : public base
      {
      private:
        static const std::string expected;
      public:
        bool is_match();
      };

      class new_line : public base
      {
      private:
        static const std::string expected;
      public:
        new_line (const std::string& token_str);
        bool is_match();
      };

      class quote : public base
      {
      private:
        static const std::string expected;
      public:
        bool is_match();
      };

      namespace list {
        class begin : public base
        {
        private:
          static const std::string expected;
        public:
          bool is_match();
        };

        class end : public base
        {
        private:
          static const std::string expected;
        public:
          bool is_match();
        };
      }

      namespace atom {
        class symbol : public base
        {
        public:
          bool is_match();
        };
      }
    }
  }
}

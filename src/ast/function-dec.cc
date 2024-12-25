#include "function-dec.hh"

namespace ast {
  FunctionDec::FunctionDec(const Location& location,
                           std::string name,
                           std::vector<VariableDec*>* args,
                           Statement* body,
                           bool is_async)
    : Dec(location, name)
    , args_(args)
    , body_(body)
    , is_async_(is_async) {}

  void FunctionDec::accept(Visitor& v) const {
    v(*this);
  }
} // namespace ast

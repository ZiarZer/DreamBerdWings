#pragma once

namespace ast {
  class Ast;
  class Exp;
  class NullExp;
  class NumberExp;
  class StringExp;
  class AwaitExp;
  class BinaryOpExp;
  class Punctuation;
  class UndefinedExp;
  class SimpleVar;
  class SubscriptVar;
  class PropertyVar;
  class Statement;
  class ExpStatement;
  class VarDecStatement;
  class CompoundStatement;
  class IfStatement;
  class WhenStatement;
  class ReturnStatement;
  class DeleteStatement;
  class ReverseStatement;
  class EmptyStatement;
  class VariableDec;

  class Visitor;
} // namespace ast

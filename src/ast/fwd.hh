#pragma once

namespace ast {
  class Ast;
  class Exp;
  class NullExp;
  class NumberExp;
  class StringExp;
  class ArrayExp;
  class ObjectExp;
  class AwaitExp;
  class BinaryOpExp;
  class Punctuation;
  class UndefinedExp;
  class SimpleVar;
  class SubscriptVar;
  class PropertyVar;
  class TimeWatchVar;
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

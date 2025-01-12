#pragma once

namespace ast {
  class Ast;
  class Exp;
  class NullExp;
  class NumberExp;
  class BoolExp;
  class StringExp;
  class ArrayExp;
  class ObjectExp;
  class AwaitExp;
  class BinaryOpExp;
  class UnaryOpExp;
  class AssignExp;
  class Punctuation;
  class UndefinedExp;
  class SimpleVar;
  class SubscriptVar;
  class TimeWatchVar;
  class CallExp;
  class Statement;
  class ExpStatement;
  class VarDecStatement;
  class FunDecStatement;
  class CompoundStatement;
  class IfStatement;
  class WhenStatement;
  class ReturnStatement;
  class DeleteStatement;
  class ReverseStatement;
  class EmptyStatement;
  class VariableDec;
  class GlobalConstantDec;
  class FunctionDec;

  class Visitor;
} // namespace ast

#include "cli-printer.hh"
#include "all.hh"

namespace runtime {
  CLIPrinter::CLIPrinter(std::ostream& stream)
    : Visitor()
    , stream_(stream) {}

  void CLIPrinter::operator()(const NullValue&) {
    stream_ << "\033[1mnull\033[0m";
  }

  void CLIPrinter::operator()(const UndefinedValue&) {
    stream_ << "\033[31mundefined\033[0m";
  }

  void CLIPrinter::operator()(const NumberValue& e) {
    stream_ << "\033[32m" << e.value_get() << "\033[0m";
  }

  void CLIPrinter::operator()(const StringValue& e) {
    stream_ << "\033[32m'" << e.value_get() << "'\033[0m";
  }

  void CLIPrinter::operator()(const ObjectValue& e) {
    stream_ << '{';

    std::map<std::string, Value*> properties = e.properties_get();
    for (auto it = properties.begin(); it != properties.end(); it++) {
      stream_ << it->first << ": ";
      it->second->accept(*this);
    }

    stream_ << '}';
  }

  std::ostream& operator<<(std::ostream& stream, const Value& val) {
    CLIPrinter print(stream);
    print(val);
    return stream;
  }
} // namespace runtime

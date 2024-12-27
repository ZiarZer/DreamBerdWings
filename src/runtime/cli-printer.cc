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
    stream_ << (e.is_array_get() ? '[' : '{');

    bool is_first_keyval = true;
    std::map<std::string, Value*> properties = e.properties_get();
    if (!properties.empty()) {
      stream_ << ' ';
    }

    for (auto it = properties.begin(); it != properties.end(); it++) {
      if (is_first_keyval) {
        is_first_keyval = false;
      } else {
        stream_ << ", ";
      }

      if (!e.is_array_get() || !utils::is_number(it->first)) {
        stream_ << it->first << ": ";
      }
      it->second->accept(*this);
    }

    if (!properties.empty()) {
      stream_ << ' ';
    }
    stream_ << (e.is_array_get() ? ']' : '}');
  }

  std::ostream& operator<<(std::ostream& stream, const Value& val) {
    CLIPrinter print(stream);
    print(val);
    return stream;
  }
} // namespace runtime

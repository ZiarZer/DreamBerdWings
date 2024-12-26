#include "dreamberd-driver.hh"

using namespace parse;

DreamBerdDriver::DreamBerdDriver()
  : scanner_(*this)
  , parser_(scanner_, *this)
  , location_()
  , ast_(nullptr)
  , terminated_(false) {}

int DreamBerdDriver::parse() {
  std::cout << "> ";
  return parser_.parse();
}

int DreamBerdDriver::run_cli() {
  runtime::Evaluator evaluator = runtime::Evaluator();
  int res = parse();
  while (!terminated_) {
    if (ast_) {
      evaluator(*ast_);
      std::cout << *(evaluator.current_value_get()) << std::endl;
    }
    res = parse();
  }
  return res;
}

void DreamBerdDriver::step_location(unsigned int loc) {
  location_.step();
  location_.columns(loc);
}

void DreamBerdDriver::location_next_line() {
  location_.step();
  location_.lines();
}

parse::location DreamBerdDriver::get_location() const {
  return location_;
}

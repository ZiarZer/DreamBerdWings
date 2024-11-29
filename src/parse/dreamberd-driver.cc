#include "dreamberd-driver.hh"

using namespace parse;

DreamBerdDriver::DreamBerdDriver()
  : scanner_(*this)
  , parser_(scanner_, *this)
  , location_() {}

int DreamBerdDriver::parse() {
  std::cout << "> ";
  return parser_.parse();
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

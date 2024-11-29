#include "parse/dreamberd-driver.hh"

int main(void) {
  parse::DreamBerdDriver driver;

  int res = driver.parse();
  return res;
}

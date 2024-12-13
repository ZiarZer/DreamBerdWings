#include "ast/pretty-printer.hh"
#include "parse/dreamberd-driver.hh"

int main(void) {
  parse::DreamBerdDriver driver;

  int res = driver.parse();
  std::cout << *(driver.ast_get());
  return res;
}

#pragma once

#include "utils.hh"

namespace utils {
  inline bool is_number(std::string str) {
    bool has_floating_point = false;
    for (char c : str[0] == '-' ? str.substr(1) : str) {
      if (c == '.') {
        if (has_floating_point) {
          return false;
        } else {
          has_floating_point = true;
        }
      } else if (c < '0' || c > '9') {
        return false;
      }
    }
    return true;
  }
} // namespace utils

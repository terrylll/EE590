#include "object.hh"

class exception : public std::runtime_error {
public:
  exception(const char msg[]) : std::runtime_error(msg) { }
};

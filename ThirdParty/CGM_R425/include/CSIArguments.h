#ifndef CSIArguments_h
#define CSIArguments_h

#include "CSICommandBinderModule.h"

#include <string_view>
#include <vector>

namespace EK
{
class Context;
}

namespace CSI
{
class Commands;

class ExportedByCSIBinderModule Arguments
{
public:
  Arguments();
  Arguments(int argc, char** argv, const EK::Context& context, Commands& commands);
  ~Arguments() = default;

  Arguments(const Arguments& other) = delete;
  Arguments& operator=(const Arguments& other) = delete;

  int GetArgc() const;
  char** GetArgv() const;
  const EK::Context& GetContext() const;
  Commands& GetCommands() const;

  std::vector<std::string_view> GetUserArgs() const;

private:
  class ExportedByCSIBinderModule Iterator
  {
  public:
    Iterator(const Arguments& args, int index);
    Iterator& operator=(const Iterator&);
    Iterator operator++();
    bool operator!=(const Iterator& other) const;
    const char* operator*() const;
  private:
    const Arguments& args_;
    int index_;
  };

public:
  Iterator begin() const;
  Iterator end() const;

private:
  int argc_;
  char** argv_;
  const EK::Context* context_;
  Commands* commands_;
};
}

#endif

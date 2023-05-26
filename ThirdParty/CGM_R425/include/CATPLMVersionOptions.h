#ifndef CATPLMVersionOptions_H
#define CATPLMVersionOptions_H


namespace CATPLMVersionOptions
{
  enum KeepOrReset
  {
    DEFAULT = 0, //stay with what is defined from the intent
    OWNERSHIP = 1 << 0,
    ORGANIZATION = 1 << 1,
    RESERVED = 1 << 2,
    CONFIGURATION = 1 << 3,
    EIN = 1 << 4, //engineering item number
    COLLABSPACE = 1 << 5,
    MATURITY = 1 << 6
  };

  inline KeepOrReset operator|(const KeepOrReset& a, const KeepOrReset& b)
  {
    return KeepOrReset((int)a | (int)b);
  }
};

#endif

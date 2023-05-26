#ifndef __ScalarFieldsTraits_h
#define __ScalarFieldsTraits_h


#include "ScalarFields.h"

#include <string>
#include <iostream>
#include <fstream>

namespace SF {
  
  class Serializer {
  public:
    virtual HRESULT ToStream(std::ofstream& iDstStream) = 0;
    virtual HRESULT FromStream(std::ifstream& iSrcStream) = 0;
  private:
  };

  template <typename T>
  class TSerializer : public Serializer, T // Serializer is pure abstract thus multiple inheritance not really an issue
  {
  public:
    TSerializer(T& iT) : T(iT) {}
    virtual HRESULT ToStream(std::ofstream& iDstStream) { /* Nothing force specialization */ }
    virtual HRESULT FromStream(std::ifstream& iSrcStream) { /* Nothing force specialization */ }
  };
};
#endif // ScalarFieldsTraits

#ifndef CATTabIndex_h
#define CATTabIndex_h
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2005
//

#include "MathAdvMarsh.h"


class ExportedByMathAdvMarsh CATTabIndex
{

  private:

    double _Value;
    int _Index;
  

  public:
    CATTabIndex(double val, int ind);
    CATTabIndex();
    static int compare(const void* val1, const void* val2);
    double GetValue();
    int GetIndex();
    ~CATTabIndex();

};
#endif



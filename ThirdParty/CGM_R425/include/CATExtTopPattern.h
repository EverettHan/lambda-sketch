#ifndef CATExtTopPattern_H_
#define CATExtTopPattern_H_

#include "CATExtTopOperator.h"
#include "BODYNOPE.h"
#include "CATMathInline.h"

class ExportedByBODYNOPE CATExtTopPattern : public CATExtTopOperator
{
public : 
  CATExtTopPattern();
  ~CATExtTopPattern();

  void SetPatternFacesResultMode ( const int iFullResultMode );

  INLINE int GetPatternFacesResultMode () { return _PatternFacesResultMode; };

  CATCGMNewClassArrayDeclare; // Pool allocation

private :

  int _PatternFacesResultMode;

};

#endif


/**
 * @level Protected
 * @usage U1
 */
/* */
/* dereferencement de LS en utilisant un objet de type late  */
/* CPI/DAD/CMI  Dec.97 */
#ifndef CATLateNaming_H_
#define CATLateNaming_H_


#include "CATObject.h"
#include "CATOmcBase.h"

class ExportedByCATOmcBase CATLateNaming : public CATObject
{
 public:
  CATLateNaming(CATUnicodeString, CATBaseUnknown*);
  ~CATLateNaming();
  
  
  CATBaseUnknown* GetData();
  void* SetData(CATBaseUnknown* );
  
 private:
  CATBaseUnknown* _data;  
};


#endif

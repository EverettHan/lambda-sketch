// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATSystemTextFormat_H
#define CATSystemTextFormat_H
////////////////////////////////////////////////////////////////////////////////////////
// Didier LARUEL
// 23/05/97
//
// Purpose: CATSystemTextFormat
//
//          A Text System Format May provide system dependant means
//          to encode or decode data for exchange beetween to process
//          based onto NT Text Format for NT Implementation
//
// Remark, Data Transfert are assynchronous, and may concern such data
// as Text, RTF, METAFILEPIC, GEOMETRICAL, MECHANICAL, ...
// those data can either be provided by CATIA to CATIA, either
// comes from other application or goes to other application
// (e.g. Text, ...). Then the tranfer protocol used by the system
// should be stricly respected
//
////////////////////////////////////////////////////////////////////////////////////////

/**
 * @level Protected
 * @usage U1
 */

#include<CATSystemFormat.h>
#include<CATUnicodeString.h>

#include<CP0CLIP.h>

class ExportedByCP0CLIP CATSystemTextFormat: public CATSystemFormat
{
 public:
  CATSystemTextFormat(CATFormat* for_fmt=NULL);
  virtual ~CATSystemTextFormat();

  //not to derivate, because a default implementation ensure system dependant management
  virtual int ProvideTempoData(CATBaseUnknown_ptr, LPFORMATETC& system_format, LPSTGMEDIUM& system_medium);
  virtual int ReleaseTempoData(LPSTGMEDIUM provided_system_medium);
  virtual int ProvideTempoObject(LPFORMATETC system_format, LPSTGMEDIUM system_medium, CATBaseUnknown_ptr& tempo_object);
  virtual int ReleaseTempoObject(CATBaseUnknown_ptr& tempo_object);
};

#endif


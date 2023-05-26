// COPYRIGHT DASSAULT SYSTEMES 2000

/**
  * @level Private
  * @usage U1
  */

//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************

#ifndef CATSystemFormat_H
#define CATSystemFormat_H
////////////////////////////////////////////////////////////////////////////////////////
// Didier LARUEL
// 23/02/97
//
// Purpose: CATSystemFormat
//                             A System Format May provide system dependant means
//                             to encode or decode data for exchange beetween to process
//
//                             By default no communication is enabled
//
// Remark, Data Transfert are assynchronous, and may concern such data
// as Text, RTF, METAFILEPIC, GEOMETRICAL, ...,
// those data can either be provided by CATIA to CATIA, either
// comes from other application or goes to other application
// (e.g. Text, ...). Then the tranfer protocol used by the system
// should be stricly respected
//
// Remark to implementers:
// ======================
// Subject to change, because the implementation is system dependant
// the implementation of system format can be the same for a range of
// format, depending only the interfaces used onto the object.
//
// For derivation:
// if defining the format, it will be considered an ad hoc system format
// then the way the data are exchanged should be derivated. The file
// method has only to return 0 (not supported).
//
// Otherwise it will be allocated by the system as an application
// proprietary format, and the basic exchange is supposed to be a file
// one. It could be enhanced in the future to suppose a IStream Ole compatible one
// but this was not possible at the time the interface was defined...
//
////////////////////////////////////////////////////////////////////////////////////////

//forward to avoid compilation errors
//include a virer,
//des que les ressources necessaire seront definies par un include systeme ad hoc
#ifdef _WINDOWS_SOURCE
# include<ole2.h>
#else
struct FORMATETC;
typedef FORMATETC* LPFORMATETC;
struct STGMEDIUM;
typedef STGMEDIUM* LPSTGMEDIUM;
#endif

#include<CATFormat.h>
#include<CP0CLIP.h>

class ExportedByCP0CLIP CATSystemFormat
{
 public:
  //if needed,
  //used for inter-process communication
  //System dependant part, to reimplement either on windows or unix
  CATSystemFormat(CATFormat* for_fmt=NULL );
  virtual ~CATSystemFormat();

  virtual int ProvideTempoData(CATBaseUnknown_ptr, LPFORMATETC& system_format, LPSTGMEDIUM& system_medium);
  virtual int ReleaseTempoData(LPSTGMEDIUM provided_system_medium);
  virtual int ProvideTempoObject(LPFORMATETC system_format, LPSTGMEDIUM system_medium, CATBaseUnknown_ptr& tempo_object);
  virtual int ReleaseTempoObject(CATBaseUnknown_ptr& tempo_object);

  virtual LPFORMATETC  SystemFormat() const;

  void SetFormat(CATFormat* fmt);
  CATFormat* Format() const;

  //Default implementation allocate a new application system format
  void SetSystemFormat(LPFORMATETC system_format);

 protected:
  LPFORMATETC _system_format; // deleted at end

 private:
  CATFormat*  _fmt; // only a reference

};

#endif

#ifndef CATCVMAttrRef_h
#define CATCVMAttrRef_h

// 07:08:20 FDN refonte de la gestion des attr ref : voir CATCVMContainer.h
//-------------------------------------------------------------------------------------

#include "CATCVMSysObjects.h"
#include "CATCVMSysStream.h"
#include "CATCVMAttribute.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfInt.h"
#include "CATListPV.h"
#include "ListPOfCATCVMAttrRef.h"
#include "CATCGMNewArray.h"

// This class is parent of all Attribute References

class ExportedByCATCVMSysObjects CATCVMAttrRef : public CATBaseUnknown 
{
  //------------------------------------------------------------------------------
  // Component declaration for ObjectModeler
  //------------------------------------------------------------------------------
public:
  CATDeclareClass;

public:
  CATCVMAttrRef(CATCVMContainer * iContainer);
  
  CATCGMNewClassArrayDeclare;
 
  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMAttrRef();
  
  public:
  // Stream/Unstream
  virtual void Stream(CATCVMSysStream * iStream) = 0;
  virtual void Unstream(CATCVMSysStream * iStream, CATCVMContainer * iContainer) = 0; 

  CATULONG32 GetType();

  HRESULT GetID(CATUnicodeString & oID);
  HRESULT SetID(CATUnicodeString iID);
  static void InitString(CATUnicodeString & chaine);

  virtual CATBoolean IsEqualTo(CATCVMAttrRef * iAttrRef) = 0;

  CATULONG32 GetNbUser();
  // iContainer is mandatory, exept for CATCVMImage
  CATULONG32 AddUser(CATCVMContainer * iContainer = NULL);
  CATULONG32 RemoveUser(CATCVMContainer * iContainer = NULL);
  CATULONG32 IsUsedBy(CATCVMContainer * iContainer);

  void SetPosInStreamList(CATULONG32 iPos);
  CATULONG32 GetPosInStreamList();

  virtual CATULONG32 GetRef(ListPOfCATCVMAttrRef * ioListe);

private:
  CATCVMAttrRef(const CATCVMAttrRef &);//Necessary to prevent unwanted automatic creation by compiler
  void operator = (const CATCVMAttrRef &);

  CATUnicodeString _ID;
  CATULONG32 _UseCount; // Usecount global, cumul des valeurs des _UseCountValue
  CATListOfInt _UseCountValue; // En phase avec la liste suivante !
  CATListPV    _UseCountContainer; // En phase avec la liste précédente !
  CATULONG32 _PosInList; // usage local only : position de cet AttrRef dans un container donne. 
                         // Attention, ce n'est pas la position dans dans _AttrRefList de CATCVMContainer
  //CATCVMContainer * _Container;

protected:
  CATULONG32 _Type;

};
#endif


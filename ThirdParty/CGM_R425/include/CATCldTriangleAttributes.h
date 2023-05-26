//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES 2014
//==============================================================================================================
// CATCldTriangleAttributes.h
//==============================================================================================================
// 17-Sep-2014 - JLH - Correction des bugs IR-306340 et IR-306429 :
//                     Prise en compte des attributs applicatifs persistants dans la m�thode DuplicateInside
//                     D'o� la n�cessit� de deux nouvelles m�thodes CreateOfSameType et CopyAttribute
// 28-apr-2014 - JLH - Creation
//==============================================================================================================

#ifndef CATCldTriangleAttributes_H
#define CATCldTriangleAttributes_H

#include "CATCGMStreamAttribute.h"

#include "YP00IMPL.h"

class ExportedByYP00IMPL CATCldTriangleAttributes : public CATCGMStreamAttribute
{
  CATCGMDeclareAttribute (CATCldTriangleAttributes, CATCGMStreamAttribute) ;

public:

  CATCldTriangleAttributes() ;
  virtual ~CATCldTriangleAttributes() ;

  virtual CATCldTriangleAttributes * CreateOfSameType() ;

  // Clone management from CATCGMAttribute
  virtual int IsClonableAttribute() ;
  virtual CATCGMAttribute * ReportClonableAttributes (CATExtClonableManager * iClonableManager,
                                                      CATICGMObject         * iOrigin,
                                                      CATICGMObject         * iDestination) ;

  // Stream/unstream management from CATCGMStreamAttribute
  virtual void Stream   (CATCGMStream &ioStream) const ;
  virtual void UnStream (CATCGMStream &ioStream) ;

  // Callbacks for CATCldPolygon
  virtual boolean AddAttribute() ;
  virtual boolean RemoveAttribute (const int iNoAttr) ;
  virtual boolean MoveAttribute   (const int iFrom, const int iTo) ;
  virtual boolean SetNbAttributes (const int iNbAttributes) ;
  virtual boolean CopyAttribute   (const CATCldTriangleAttributes * iOther, const int iFrom, const int iTo) ;

} ;

#endif

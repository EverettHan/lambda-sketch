/* -*-C++-*- */

#ifndef CATRibContactCouple_H
#define CATRibContactCouple_H


// COPYRIGHT DASSAULT SYSTEMES 1999

//===================================================================
//===================================================================
//
// CATRibContactCouple
//
// Contact vertex sur un ruban
//
//===================================================================

//===================================================================
// Jan 2002     Creation                         JHG 
//===================================================================
//===================================================================
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATTopRibObject.h"

#include "CATRibContact.h"
//#include "ListPOfCATRlmRibs.h"
#include "ListPOfCATTopRibs.h"

#include "CATCGMNewArray.h"


class CATRibContact;
class CATTopRibMacroTool;

class ExportedByRIBLight CATRibContactCouple : public CATTopRibObject
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation

//------------------------------------------------------------------------------
// Constructor
//------------------------------------------------------------------------------
  CATRibContactCouple(CATRibContact *iContact1, CATRibContact *iContact2);

  CATRibContactCouple(CATTopRib *iLeftRib, CATTopRib *iRightRib, CATSupContact *iContact, int iNumLeft, int iNumRight);

  CATRibContactCouple(const CATRibContactCouple & iToCopy);

  int FillInContactArrays(ListPOfCATSupContact  &iExitContact, 
                                          ListPOfCATTopRibs     &iLeftRibs, 
                                          ListPOfCATTopRibs     &iRightRibs, 
                                          CATListOfInt          &iNumLeft, 
                                          CATListOfInt          &iNumRight,
                                          CATTopRibMacroTool *iMacroTool);

//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
  virtual ~CATRibContactCouple();

//------------------------------------------------------------------------------
// Data access
//------------------------------------------------------------------------------
  CATRibContact *GetContact(int iContactIndex);
  //CATRibContact *GetContactWithSameRibAs(CATRibContact *iContact);

  CATBoolean HasSameRibs(CATRibContactCouple *iOtherCouple);
  CATBoolean HasSameNuplets(CATRibContactCouple *iOtherCouple);

  double DistanceTo(CATRibContactCouple *iOtherCouple);

  void GetCurveIfPCircle(CATEdge * pEdge, CATCurve * &ioCurve);  
  CATBoolean CheckIfConfused(CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig, CATCurve * iCurve1, CATCurve * iCurve2);

  CATBoolean IsUsingVertex(CATVertex *iVertex);

protected:
  CATRibContact *_Contacts[2];
};
#endif


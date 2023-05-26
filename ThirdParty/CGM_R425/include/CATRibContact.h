/* -*-C++-*- */

#ifndef CATRibContact_H
#define CATRibContact_H


// COPYRIGHT DASSAULT SYSTEMES 1999

//===================================================================
//===================================================================
//
// CATRibContact
//
// Contact vertex sur un ruban
//
//===================================================================

//===================================================================
// Jan 2002     Creation                         JHG 
//===================================================================
//===================================================================
#include "ExportedByRIBLight.h"
#include "CATTopRibObject.h"

#include "CATSupContact.h"
#include "CATCrvParam.h"
#include "CATTopRibNuplet.h"
#include "CATMathPoint.h"
#include "CATMathInline.h"
#include "CATCGMNewArray.h"


class CATTopRib;

class ExportedByRIBLight CATRibContact : public CATTopRibObject
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation

//------------------------------------------------------------------------------
// Constructor
//------------------------------------------------------------------------------
  CATRibContact(CATTopRib *iRib, int iNumNuplet, CATSupContact &iContact, int iSupport);

  CATRibContact();

//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
  virtual ~CATRibContact();

//------------------------------------------------------------------------------
// Data access
//------------------------------------------------------------------------------
  INLINE void SetNupletIndex(int iNuplet);
  INLINE int GetNupletIndex();
  CATTopRib *GetRib();
  void SetRib(CATTopRib* iRib);
  CATVertex *GetVertex();
  CATTopRibNuplet *GetNuplet();
  void GetSupContact(CATSupContact &oContact);

  void GetMathPoint(CATMathPoint &oPoint);

  void SetSupport(int iSupport) { _Support = iSupport; }
  int GetSupport() { return _Support; }

//------------------------------------------------------------------------------
// Renvoie le parametre sur la track
//------------------------------------------------------------------------------

  void GetParam(CATCrvParam &oCrvParam);

  CATFace *GetFace(int iNumSupp);
  CATShell *GetSupportShell();

  int CompareWithContact(CATRibContact *iContactVs, int iDirection, double iTol);

//------------------------------------------------------------------------------
// Fait le merge avec un autre contact
//------------------------------------------------------------------------------
  void MergeInto(CATRibContact *iContactVs, CATTopologicalOperator *iTopOp);


protected:

  CATTopRib *_Rib;
  int        _NumNuplet;
  CATSupContact _Contact;
  int  _Support;
};

//------------------------------------------------------------------------------
// INLINE implementations
//------------------------------------------------------------------------------
INLINE void CATRibContact::SetNupletIndex(int iNuplet) { _NumNuplet = iNuplet; };
INLINE int CATRibContact::GetNupletIndex() { return _NumNuplet; };
//------------------------------------------------------------------------------
#endif


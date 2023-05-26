/* -*-c++-*- */
#ifndef CATFilletRadius_h_
#define CATFilletRadius_h_

//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 1997

//===================================================================
//===================================================================
//
// Classe definissant un rayon de ruban pour fillet 
//
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// March. 98  Recuperation de TopologicalPrimitives      J-M.Guillard
//===================================================================
//===================================================================

#include "Fillet.h"
#include "CATMathDef.h"
#include "CATMathInline.h"

class CATCell;
class CATCGMJournalList;

#ifndef NULL
#define NULL 0
#endif

#include "CATCGMNewArray.h"
#include "CATSafe.h"
CATSafeDefine(CATFilletRadius);

class ExportedByFillet CATFilletRadius
{
  public :
  CATFilletRadius(CATPositiveLength radius, 
		              CATCell         * location, // CATVextex or CATEdge only
                  double          * ratio=NULL,
                  CATAngle        * Direction=NULL); // slope
  CATFilletRadius(); 
  CATCGMNewClassArrayDeclare;        // Pool allocation

  ~CATFilletRadius();
  
  INLINE CATPositiveLength  GetRadius()   const { return _radius; };
  INLINE CATCell*           GetLocation() const { return _location; };
    
  double     GetRatio()  const;
  CATBoolean HasRatio()  const;

  void       SetRatio(const double iRatio);
  
  CATAngle   GetDirection() const;
  CATBoolean HasDirection() const;
  
  void UpdateWithJournal(CATCGMJournalList* iJournal);

  private:
  CATPositiveLength  _radius;
  double             _ratio;     
  CATAngle           _direction; 
  CATCell*           _location;  
  int                _HasRatio;
  int                _HasDirection;
};


#endif

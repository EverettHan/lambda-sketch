/* -*-C++-*-*/
#ifndef CATTessInCell_h
#define CATTessInCell_h

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 20001
//
// CATTessInCell
//
// DESCRIPTION :
// 
// Maillage d'un element type "Body"
//
// Main Methods :
//  
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Fev. 2001 TPD Mise en place nouvel interface MAILLAGE
// Mars 2004 TPD On chaine les Points Bords de faces entre eux par les CATTessPoints correspondants
//
//=============================================================================

// For Windows NT
#include "TessTopology.h"

#include "CATMathDef.h"
#include "CATCGMNewArray.h"
#include "CATCGMVirtual.h"

class CATTessStore;
class CATGeoFactory;

class ExportedByTessTopology CATTessInCell: public CATCGMVirtual
{
public:

  //=============================================================================
  // Constructors  and desctructor
  //=============================================================================
  /**
   * CONSTRUCTOR
   */
  CATTessInCell();
  
  /**
   *  Destructor
   */
  virtual ~CATTessInCell();

  /** @nodoc */
  CATCGMNewClassArrayDeclare;

  //=============================================================================
  // METHODS
  //=============================================================================
  /** Get the Tag de la Cell
   */
  virtual CATLONG32 GetTag();

  /** Get the Resolution 
    * Sortie = 0 : Ok
    *        <>0 : Pb arrete le calcul
   */
  virtual CATLONG32 GetResolution( double & oResolution ); //WMNTOLIGNORE

  /** Get du nombre de domaines
   */
  virtual CATLONG32 GetNbDomains();

  /** Veut-on mailler la Cell ?
    */
  virtual CATBoolean DoYouNeed( CATTessStore * iStorage );

  /** Pour XScale, besoin dans ::Run d'acceder a la factory d'origine contenant la CATSurface de la classe fille
    */
  virtual CATGeoFactory * GetFactory() const;

};

#endif

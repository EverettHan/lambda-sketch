/* -*-C++-*- */

#ifndef CATTopXSimplif_H
#define CATTopXSimplif_H

// COPYRIGHT DASSAULT SYSTEMES 2016

/**
 * @nocgmitf (do not create phase 2 interface)
 */ 


//=============================================================================
//=============================================================================
//
// CATTopXSimplif : Operateur de simplification par intersections
//
//=============================================================================

//=============================================================================
// Mar  2016  Creation (sharp vertex only)                       P. Rossignol
// Jan  2018  Mode global (sharp vertex)                         P. Rossignol
//          
//=============================================================================
//=============================================================================

// Def ExportedBy
//#include "TopExtLight.h"
#include "FlexibleBRep.h"

// Includes de base
#include "CATTopOperator.h"
#include "CATExtCGMReplay.h"

//
#ifndef NULL
#define NULL 0
#endif

//
class CATBody;
class CATShell;

// Classes de base
class CATGeoFactory;
class CATTopData;
class CATSoftwareConfiguration;

// Basique
#include "CATBoolean.h"

// Topolo
class CATBody;
class CATShell;
class CATVertex;

// Listes
#include "ListPOfCATVertex.h"


class ExportedByFlexibleBRep CATTopXSimplif : public CATTopOperator
{

  CATCGMVirtualDeclareClass(CATTopXSimplif);

public: 
//===========================================================================================================

  //------------------------------------------------------------------------------
  // Types
  //------------------------------------------------------------------------------   
  enum XSGlobalMode
  {
    GLO_NONE = 0,           // Mode non global
    GLO_SHARP,              // Simplif des sommets vifs seulement
    GLO_SMOOTH,             // Simplif des sommets morts seulement
    GLO_BOTH                // Simplif de tous les sommets
  };

  enum XSLocalMode
  {    
    LOC_NONE  = 0,          // Mode non local
    LOC_SHARP,              // Simplif des sommets vifs seulement
    LOC_SMOOTH,             // Simplif des sommets morts seulement
    LOC_BOTH                // Simplif de tous les sommets
  };

public: 
//===========================================================================================================
  
  //------------------------------------------------------------------------------
  // Ctor/Dtor  
  // 
  // Virtual constructor of a <tt>CATTopXSimplif</tt> operator.<br>
  // Do not call this constructor, instead use the <tt>CATCreateTopXSimplif</tt> 
  // global function
  // to create a CATTopXSimplif operator.
  //------------------------------------------------------------------------------    
  CATTopXSimplif ( CATGeoFactory*     iFactory,
                   CATTopData*        iData,                    
                   CATExtTopOperator* iExtensible = NULL);

  virtual ~CATTopXSimplif();

  //------------------------------------------------------------------------------
  // Input
  //------------------------------------------------------------------------------     
  void AddVertex( CATVertex* iVertex );    // Vertex bounded by two sharp edges are handled, others are ignored

  void SetGlobalMode(XSGlobalMode iMode) ; // iMode == GLO_SHARP only is yet supported

  void SetLocalMode (XSLocalMode  iMode) ; // iMode == LOC_SHARP only is yet supported

  void SetDoNotAllowGapReport();

  void SetCanonicMode();                   // Pour restreindre la simplification aux aretes entre 2 geom rep canoniques - ne s'applique qu'au mode global

  void SetTangentMode();                   // Pour test, en cours de dev - ne s'applique qu'au mode global

  void SetPartialMode();                   // Pour test, en cours de dev - ne s'applique qu'au mode global

  //------------------------------------------------------------------------------
  // Methodes d'acces aux resultats
  //------------------------------------------------------------------------------
  int          GetNbSimplifiedVertex();  
  
private :
//===========================================================================================================

  //------------------------------------------------------------------------------
  // CGM internal
  //------------------------------------------------------------------------------     
  virtual int RunOperator();

  //------------------------------------------------------------------------------
  // CGM internal - Replay
  //------------------------------------------------------------------------------     
  virtual CATExtCGMReplay * IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  virtual const CATString * GetOperatorId();
  virtual const CATString * GetDefaultOperatorId();
  virtual void RequireDefinitionOfInputAndOutputObjects();
  virtual void WriteInput(CATCGMStream &Str);
  virtual void Dump( CATCGMOutput& os );

};

/**
 * Creates a <tt>CATTopXSimplif</tt> operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
 * @param iBody
 * The pointer to the body where the recognition will be performed.
 * @param iShell
 * The pointer to the shell where the recognition will be performed.
 * @return
 * The pointer to the created operator. To delete after use with the usual C++ <tt>delete</tt> operator.
 */
ExportedByFlexibleBRep CATTopXSimplif* CATCreateTopXSimplif 
  ( CATGeoFactory*     iFactory,                                                                                     
    CATTopData*        iData,                                                                              
    CATBody*           iBody,
    CATShell*          iShell);


#endif

// Ne rien ecrire sous cette ligne
//===========================================================================================================



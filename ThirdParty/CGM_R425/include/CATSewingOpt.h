/* -*-C++-*- */

#ifndef CATSewingOpt_H
#define CATSewingOpt_H

// COPYRIGHT DASSAULT SYSTEMES 2021

//=============================================================================
//=============================================================================
//
// CATSewingOpt : Options pour le sewing
//
//=============================================================================

//=============================================================================
// Apr  2021  Creation                                                    PRL
//=============================================================================
//=============================================================================


/**
 * @nocgmitf (do not create phase 2 interface)
 */ 



// Derivation
#include "CATCGMVirtual.h"
#include "RibbonLight.h"

// Basiques
#include "CATBoolean.h" 

// 
//


class ExportedByRibbonLight CATSewingOpt : public CATCGMVirtual
{

public: 
//===========================================================================================================


  //------------------------------------------------------------------------------
  // Ctor/Dtor
  //------------------------------------------------------------------------------   
  CATSewingOpt ();

  virtual ~CATSewingOpt();

  //------------------------------------------------------------------------------
  // Pool allocation
  //------------------------------------------------------------------------------   
  CATCGMNewClassArrayDeclare;        

  //------------------------------------------------------------------------------
  // Get/Set du type d'angle pour AddRemove
  //------------------------------------------------------------------------------   
  void       SetAngleTypeForAddRemCase(int iType);
  int        GetAngleTypeForAddRemCase();
  


protected :
//===========================================================================================================
      
  // Les options stockees
  int       _AngleTypeForAddRemCase;          // pour Draft
  

  
private:
//===========================================================================================================
  
  //------------------------------------------------------------------------------
  // Juste pour eviter que le compilo ne definisse par lui-meme ces operateurs
  //------------------------------------------------------------------------------    
  //CATSewingOpt();
  CATSewingOpt(CATSewingOpt& iObj);
  CATSewingOpt& operator=(const CATSewingOpt & iObj);

};
#endif

// Ne rien ecrire sous cette ligne
//===========================================================================================================


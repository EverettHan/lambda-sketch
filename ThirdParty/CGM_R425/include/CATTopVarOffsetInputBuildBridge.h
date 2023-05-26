/* -*-C++-*- */

#ifndef CATTopVarOffsetInputBuildBridge_H
#define CATTopVarOffsetInputBuildBridge_H

// COPYRIGHT DASSAULT SYSTEMES 2003

// Class and functions are @nodoc and will soon be destroyed : Do not use

//=============================================================================
//=============================================================================
//
// CATTopVarOffsetInputBuildInputBuildBridge : Pile "Topo" du Pont logiciel
//                             permettant l'utilisation du VarOffsetInputBuild
//                             dans le fw Topo.
//
// Classe abstraite qui permet d'appeler les fonctions du VarOffsetInputBuild
// via le pont
// + definition de la fonction de chargement dynamique de la librairie
//
//=============================================================================

//=============================================================================
// Nov  2003  Creation                                        L. Marini
// Juil 2004  Add methode GetSewBody                          L. Marini
//=============================================================================
//=============================================================================

// Pour le ExportBy
#include "Thick.h"

// Includes 
#include "CATCGMVirtual.h"

#include "ListPOfCATBody.h"
#include "ListPOfCATFace.h"
#include "CATListOfDouble.h"
#include "CATBoolean.h"


//--------------------------------------------------------------------
// Signature CallBack de Nettoyage
//--------------------------------------------------------------------
class CATTopVarOffsetInputBuildBridge;
class CATGeoFactory;
class CATTopData;
class CATBody;


typedef CATTopVarOffsetInputBuildBridge*  (*CATTopVarOffsetInputBuildCreator)  
       (CATGeoFactory *iFactory, CATTopData *iTopData, CATBody* iSupportShell,
                                                       CATBody* iVarOffShell,
	                                                     const ListPOfCATBody&  iConstantShells,
	                                                     const CATListOfDouble& iInputOffsetLaw,
	                                                     const ListPOfCATBody&  iVariableShells);

typedef CATTopVarOffsetInputBuildBridge*  (*CATTopVarOffsetInputBuildCreator2)  
       (CATGeoFactory *iFactory, CATTopData *iTopData, CATBody* iSupportShell,
	                                                     const ListPOfCATBody&  iConstantShells,
	                                                     const CATListOfDouble& iInputOffsetLaw,
	                                                     const ListPOfCATBody&  iVariableShells,
	                                                     const ListPOfCATBody&  iConstantWires,
	                                                     const CATListOfDouble& iInputOffsetLawWire,
	                                                     const ListPOfCATBody&  iVariableWires);
                                                       

typedef CATTopVarOffsetInputBuildBridge*  (*CATTopVarOffsetInputBuildCreator3) 
       (CATGeoFactory *iFactory, CATTopData *iTopData,	CATBody*               iSupportShell,
																											const ListPOfCATBody&  iConstantShells,
																											const CATListOfDouble& iInputOffsetLaw,
																											const CATListOfInt&    iConstantOrient,
																											const ListPOfCATBody&  iVariableShells,
																											const CATListOfInt&    iVariableOrient,
																											const ListPOfCATBody&  iConstantWires,
																											const CATListOfDouble& iInputOffsetLawWire,
																											const ListPOfCATBody&  iVariableWires); 

class ExportedByThick CATTopVarOffsetInputBuildBridge : public CATCGMVirtual
{

public :
//===========================================================================================================

  //------------------------------------------------------------------------------
  // Creation d'un objet cree comme un CATSurfTopVarOffsetInputBuildBridge 
  //                     & vu comme un CATTopVarOffsetInputBuildBridge 
  //------------------------------------------------------------------------------

  // Nouvelle version avec l'orientation des shells par rapport au SupportShell
  static CATTopVarOffsetInputBuildBridge * Create(CATGeoFactory*   iFactory, 
                                            CATTopData*            iTopData,
                                            CATBody*               iSupportShell,
																						const ListPOfCATBody&  iConstantShells,
																						const CATListOfDouble& iInputOffsetLaw,
																						const CATListOfInt&    iConstantOrient,
																						const ListPOfCATBody&  iVariableShells,
																						const CATListOfInt&    iVariableOrient,
																						const ListPOfCATBody&  iConstantWires,
																						const CATListOfDouble& iInputOffsetLawWire,
																						const ListPOfCATBody&  iVariableWires); 

  //------------------------------------------------------------------------------
  // Destructeur
  //------------------------------------------------------------------------------
  virtual ~CATTopVarOffsetInputBuildBridge() {};


  //-------------------------------------------------------------
  // RUN Method
  //------------------------------------------------------------- 
  virtual int Run() = 0;

  //-------------------------------------------------------------
  // SET Method
  //------------------------------------------------------------- 

  //-------------------------------------------------------------
  // GET Methods
  //------------------------------------------------------------- 
  virtual void GetListOfWireCst(ListPOfCATBody* ioListOfBody, CATListOfDouble* ioOffsetLaw,
	                              int iVarShellIndex = 0) = 0;

	virtual void GetListOfWireVar(ListPOfCATBody* ioListOfBody, CATListOfDouble* ioOffsetLawFirst,
	                                                            CATListOfDouble* ioOffsetLawEnd,
	                              int iVarShellIndex = 0) = 0;

  // ioUseOfConstBodies has to be initialized to a CATBoolean[iConstantShells.Size()]
	virtual void GetListOfUsedConstBodies(CATBoolean* ioUseOfConstBodies) const = 0;
	
	
	// Set Methods
	// Init value is TRUE :
	virtual void SetErrorConstraintNoUse(const CATBoolean iConstraintNoUse = FALSE) = 0;

  // For Developpement R15: Healing
  // ------------------------------
  virtual CATBody * GetSewBody() = 0;
  // return the SewBody's Faces with constant offset
	virtual void GetListOfConstFaces(ListPOfCATFace& ioListOfFace) const = 0;



private:
//===========================================================================================================

};

#endif


#ifndef CATICmdSwitchAgentModel_H
#define CATICmdSwitchAgentModel_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 2000
// protected CATCmdDialogAgents.m

//===========================================================================
//  Abstract of the class:
//  ----------------------
//
//  Interface to handle the model of a CATCmdSwitchAgent
//
//===========================================================================

// System Framework
#include "IUnknown.h"

#include "CATBoolean.h" 
#include "CATListOfCATString.h"

// Global Unique IDentifier defined in .cpp 
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATDialogEngine IID IID_CATICmdSwitchAgentModel;
#else
extern "C" const IID IID_CATICmdSwitchAgentModel;
#endif

class ExportedByCATDialogEngine CATICmdSwitchAgentModel : public IUnknown
{

public:

/**
 * @param oList
 * Renvoi une reference sur une liste constante de @href CATString qui represente 
 * le nom de ressource associees de chacun des etats possible de l'enumeration.
 * La taille de la liste donne le nombre d'etat possible pour l'enumeration et
 * l'index de chaque @href CATString dans la liste est equivalent a l'index
 * identifiant un switch.
 * @return 
 * <dl>
 * <dt><tt>S_OK</tt> : the list is not empty
 * <dt><tt>S_FALSE </tt>: the list is empty
 * </dl> 
 */
  virtual HRESULT GetSwitches (const CATListOfCATString * & oList) const = 0;

/**
 * 
 * @param
 *   iIdx is the index of the switch.
 * @return
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> The switch is locked.
 * <dt> <tt>S_FALSE</tt>  <dd> The switch is unlocked.
 * <dt> <tt>E_FAIL</tt>   <dd> iIdx is wrong.
 * </dl> 
 */
  virtual HRESULT IsLocked (int iIdx) const = 0;

};

#endif


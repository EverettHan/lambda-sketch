#ifndef CATICmdSwitchAgentValuation_H
#define CATICmdSwitchAgentValuation_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 2000
// protected CATCmdDialogAgents.m

// System Framework
#include "IUnknown.h"

// Global Unique IDentifier defined in .cpp 
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATDialogEngine IID IID_CATICmdSwitchAgentValuation;
#else
extern "C" const IID IID_CATICmdSwitchAgentValuation;
#endif

class ExportedByCATDialogEngine CATICmdSwitchAgentValuation : public IUnknown
{

  public:

/**
 * Value au sens @href CATDialogAgent#Accept l'enveloppe de <tt>this</tt>. Cette
 * valuation declenche des transitions dans la @href CATStateCommand associe a
 * l'enveloppe de <tt>this</tt>. Cette methode est le princial message utilise par
 * les extensions de l'enveloppe de <tt>this</tt> qui la font adherer a une interface
 * derivee de @href CATIDecoderAgent.
 * @param <tt>int iIdx</tt>
 * [in] L'index correspondant au switch que l'on veut activer lors de la valuation
 * de l'agent.
 * @return
 * Un <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> Valuation reussit.
 * <dt> <tt>E_FAIL</tt>   <dd> Aucune valuation n'a pu etre effectuee.
 * </dl>
 */
  virtual HRESULT Valuate (int iIdx) = 0;

/**
 * Restore le precedent etat de valuation de l'agent.
 * @return
 * Un <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> Undo reussit.
 * <dt> <tt>E_FAIL</tt>   <dd> On a atteint la fin de la pile d'undo disponible.
 * </dl>
 */
  virtual HRESULT Undo () = 0;

/**
 * Annule le dernier Undo effectue. Cette methode peut etre appellee plusieurs fois
 * de suite mais jamais plus de fois que la methode Undo.
 * @return
 * Un <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> Redo effectue
 * <dt> <tt>E_FAIL</tt>   <dd> On a atteint la fin de la pile de redo, pas de redo
 * possible.
 * </dl>
 */
  virtual HRESULT Redo () = 0;

/**
 * Reinitialise la pile de gestion de Undo/Redo. Apres un appel a cette methode aucun
 * appel aux methode Undo ou Redo n'a de sens jusqu'a la prochaine valuation de l'agent.
 */
  virtual HRESULT Reset () = 0;

};

#endif


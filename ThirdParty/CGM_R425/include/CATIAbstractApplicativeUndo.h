/**
 * @level Private
 * @usage U3
 */
// COPYRIGHT Dassault Systemes 2002
#ifndef CATIAbstractApplicativeUndo_H
#define CATIAbstractApplicativeUndo_H

//System.  inherited class 
#include "CATBaseUnknown.h"

// forward declaration
class CATIUndoVisitor;


#include "CATObjectModelerItf.h"

/**   
 * Abstract C++ interface which defines a class of CNEXT interfaces dedicated to manage Undo/Redo applicative management.
 *
 * <b>Role</b>:
 *  Set of template methods dedicated to defer some parts of a @href CATIUndoTransaction global implementation
 *  to an applicative object inheriting this adhesion. One component <tt>A</tt>that implement @href CATIUndoTransaction
 *  can delegate some specific applicative treatment by exposing of a new CNEXT interface inheriting from
 *  <tt>CATIAbstractApplicativeUndo</tt>> A component <tt>B</tt> CNEXT inheriting from <tt>A</tt> can then implement
 *  this interface to define a set of visitor dedicated to operate some specific treatments on the modifications
 *  recorded by the mean of @href CATIUndoTransaction by <tt>A</tt> component.
 *  @see CATIUndoTransaction for global mechanism
 */
class ExportedByCATObjectModelerItf CATIAbstractApplicativeUndo: public CATBaseUnknown
{
  public:

/**
 * Provide the applicative visitor when aborting a transaction.
 * @see CATIUndoTransaction#AbortTransaction
 * @param oVisitor Applicative visitor. May be a composite of visitors
 * @param iTransID : ID of the transaction to be aborted
 * @return S_OK if the visitor is created successfully, E_FAIL if not.
 */ 
	virtual HRESULT   GetVisitorForAbort      (CATIUndoVisitor** oVisitor,int iTransID )=0;
/**
 * Provide the applicative visitor when redoing a transaction
 * @see CATIUndoTransaction#RedoTransaction
 * @param oVisitor Applicative visitor.  May be a composite of visitors
 * @param iTransID : ID of transaction to be redone
 * @return S_OK if the visitor is created successfully, E_FAIL if not.
 */ 
	virtual HRESULT   GetVisitorForRedo      (CATIUndoVisitor** oVisitor,int iTransID )=0;

/**
 * Transfert le contenu d'une transaction dans une autre transaction.
 * Les transaction commitees peuvent ne jamais avoir ete impliquee dans un undo.
 * La transaction <tt>iResultID</tt> peut ne pas avoir ete impliquee dans un undo alors que
 * Cette methode doit donc forcement etre implementee si des donnees relatives aux contenus
 * des transaction traitees dans <tt>GetVisitorForAbort</tt> et <tt>GetVisitorForRedo</tt>
 * sont bufferisees.
 * <tt>iToCommitID</tt> l'a ete. Dans ce cas, toute donnee relative a <tt>iToCommitID</tt>
 * doit etre invalidé (c.f. ForgetTransaction).
 * @param <tt>int iToCommitID</tt>
 * [in] La transaction dont le contenu doit etre tranfere.
 * @param <tt>int iResultID</tt>
 * [in] La transaction qui recoit le contenu de <tt>iToCommitID</tt>.
 */
	virtual HRESULT   CommitTransaction       ( int iToCommitID, int iResultID )=0;

/**
 * Previent que les donnees associees a une transaction ne seront plus utilisees.
 * L'identificateur de transaction <tt>iForgetID</tt> pourra etre utilise par la suite pour
 * identifier une autre transaction.
 * Cette methode doit donc forcement etre implementee si des donnees relatives aux contenus
 * des transaction traitees dans <tt>GetVisitorForAbort</tt> et <tt>GetVisitorForRedo</tt>
 * sont bufferisees.
 */
	virtual HRESULT   ForgetTransaction       ( int iForgetID )=0;
};

#endif

/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2004
//=============================================================================


#ifndef CATVVSTransaction_H
#define CATVVSTransaction_H

#include "VVSCoreStructure.h"
//#include "IUnknown.h"
#include "CATUuid.h"

class CATUnicodeString;

/**
 * This interface represents a generic table used to describe a Vault server session.
 * The semantic is completely out of scope of the object implementing this interface;
 * the implementation is supposed to be a simple commodity to enable stateful behavior
 * of a Vault server.
 */
class ExportedByVVSCoreStructure CATVVSTransaction
{
public:

  /**
  * Add a parameter to the Vault server session.
  *
  *	@param  iParamName [in]
  *			Parameter identifier
  * @param  iParamValue [in]
  *     Parameter value
  */
  virtual void PutParameter (const CATUnicodeString iParamName, const CATUnicodeString iParamValue) = 0;

  /**
  * Output the first parameter of the session.
  *
  * Use this before using Next.
  *
  *	@param  oParamName [out]
  *			Parameter identifier
  * @param  oParamValue [out]
  *     Parameter value
  */
  virtual void FirstParameter (CATUnicodeString &oParamName, CATUnicodeString &oParamValue) = 0;

  /**
  * Output the next parameter of the session.
  *
  *	@param  oParamName [out]
  *			Parameter identifier
  * @param  oParamValue [out]
  *     Parameter value
  * @return
  *     S_OK if there is a next parameter.
  *     S_FALSE otherwise.
  */
  virtual HRESULT NextParameter (CATUnicodeString &oParamName, CATUnicodeString &oParamValue) = 0;

  /**
  * Query a parameter from its identifier.
  *
  *	@param  iParamName [in]
  *			Parameter identifier
  * @param  oParamValue [out]
  *     Parameter value
  */
  virtual void QueryParameter (const CATUnicodeString iParamName, CATUnicodeString &oParamValue) = 0;

  /**
  * Compares two CATVVSTransactions.
  *
  * @param iTransaction [in]
  *     Transaction to compare
  */
  int operator== (const CATVVSTransaction& iTransaction) const;

  int operator!= (const CATVVSTransaction& iTransaction) const;

  CATUuid GetIdent() const {return _ident;};

  enum eTransactionType {eUndefinedTransaction,eSaveTransaction,eImportTransaction};

  void SetTransactionType(eTransactionType iTransactionType);

  eTransactionType GetTransactionType() const;

  CATVVSTransaction();

  virtual ~CATVVSTransaction();

private:
  eTransactionType _TransactionType;

  CATUuid _ident;

};

#endif





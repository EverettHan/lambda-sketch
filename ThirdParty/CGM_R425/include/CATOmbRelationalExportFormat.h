/**
* @level Private
* @usage U2
*/
#ifndef _CATOmbRelationalExportFormat_H
#define _CATOmbRelationalExportFormat_H

#include "IUnknown.h"
#include "CATOmbLinkTraderForRestrictedAccess.h"
#include "CATOmxIter.h"

class CATOmbRelationExport;
class CATOmbRelationImpl;
class CATOmbComponentTablesMediator;
class CATComponentId;

/**
* Abstract class providing export protocol for relations
*/
class ExportedByCATOmbLinkTraderForRestrictedAccess CATOmbRelationalExportFormat
{
public:

  /**
  * Opens export format
  *
  * @return
  *     S_OK    : if succeeded.
  *     E_FAIL  : if failed.
  */
  virtual HRESULT Open() = 0;

  /**
  * Exports all relations
  *
  * @param iSRImpl
  *        The first relation
  *
  *
  * @return
  *     S_OK    : if succeeded.
  *     E_FAIL  : if failed.
  */
  virtual HRESULT ExportRelations(CATOmxIter<CATOmbRelationImpl>& relations, CATOmbComponentTablesMediator & iMediator, const CATComponentId & iComponent) = 0;

  /**
  * Closes export format
  *
  * @return
  *     S_OK    : if succeeded.
  *     E_FAIL  : if failed.
  */
  virtual HRESULT Close() = 0;

  /**
  * Aborts export format
  *
  * @return
  *     S_OK    : if succeeded.
  *     E_FAIL  : if failed.
  */
  virtual void Abort() = 0;

protected:
  CATOmbRelationalExportFormat() {};
  ~CATOmbRelationalExportFormat() {};

private:
  /* forbidden operations */
  CATOmbRelationalExportFormat(CATOmbRelationalExportFormat &);
  CATOmbRelationalExportFormat& operator=(CATOmbRelationalExportFormat&);
};

#endif

//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2016
//===================================================================
#ifndef CATVidMdlRootTreeItem_H
#define CATVidMdlRootTreeItem_H

#include <VisuDialog.h>
#include <CATVidMdlTreeItem.h>
#include <CATLISTV_CATBaseUnknown.h>
// Declaration of a list of pointers on CATVidMdlRootTreeItem
class CATVidMdlStandardTree;
class CATBaseUnknown_var;
class CATSysWeakRef;

/** 
 * This specific tree item is aimed to be set as Root of a StandardModelTree to allow the 
 * CATVidMdlStandardTree#SetDispatchDataModifiedEventFlag method to work correctly.
 * Basically it has a backpointer on the model that allows the TreeItem to send through it an event when 
 * the dataBlock send a DataChanged event.
 */
class ExportedByVisuDialog CATVidMdlRootTreeItem : public CATVidMdlTreeItem
{
  CATDeclareClass;
public:
  /** Constructor*/
  CATVidMdlRootTreeItem(CATVidMdlStandardTree* i_pModel);
  /** Constructor*/
  CATVidMdlRootTreeItem(CATVidMdlStandardTree* i_pModel, const CATBaseUnknown_var & i_data);
  /** Constructor*/
  CATVidMdlRootTreeItem(CATVidMdlStandardTree* i_pModel, CATLISTV(CATBaseUnknown_var) & i_datas);
  /** Destructor */
  virtual ~CATVidMdlRootTreeItem();
protected:
  virtual CATVidMdlStandardTree* GetTreeModel();
private:
  CATSysWeakRef* _pModelWeakRef;
};

//-----------------------------------------------------------------------

#endif

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES  95
//=============================================================================
//
// class CATContainerExtension :
//
//=============================================================================
// Usage Notes:
//
// implemente les interfaces CATINavigContainer et CATINavigElement
// les TIE_xxx sont dans Graph/ON0GRAPH.m/src/CATExtGRViewer
//=============================================================================
// Dec. 95   Creation
// Jul. 99   perfos modif					mbv                   
//=============================================================================
#ifndef CATContainerExtension_H_
#define CATContainerExtension_H_

// NB : les forward suivants seraient plus judicieux   
//      s'ils distingaient les macros des vraies classes :
// ====================================================

/**
 * @level Private
 * @usage U1
 */

#include <CATOmnExt.h>

#include "CATBaseUnknown.h"
#include "CATINavigElement.h"

class CATNavigController;
class CATINavigContainer;
class CATDlgContextualMenu;
class CATNavigInstance;
class CATListValCATBaseUnknown_var;
class CATINavigElement_var;
class CATSysSimpleHashTable;


class ExportedByCATOmnExt CATContainerExtension : public CATBaseUnknown
{
 public:
  CATDeclareClass;
  
  CATContainerExtension();
  virtual ~CATContainerExtension();

  // Methodes de l'interface CATINavigElement
  virtual void Update();
  virtual void Remove(int index);
  virtual CATINavigContainer* GetFatherContainer();
  virtual const CATNavigController* GetController();
  virtual void ProcessAfterSelect();
  virtual void ProcessAfterExtSelect();
  virtual void ProcessAfterAction();
  virtual void ProcessAfterExpand();
  virtual void ProcessAfterMethod();
  virtual CATNavigInstance* GetAssociatedInstance();
  virtual void SetMarked(int mark=1);
  virtual int  GetMarked();
  
  // Methodes de l'interface CATINavigContainer  
  virtual void AddRoot(const CATBaseUnknown_var& obj);
  virtual void RemoveRoot(const CATBaseUnknown_var& obj);
  virtual void RemoveAllRoots();
  virtual CATListValCATBaseUnknown_var* GetAllRoots();

  virtual void SetController(const CATNavigController* controller);
  virtual void UpdateAll();
  
  protected:
  virtual void UpdateIfNotDone(const CATINavigElement_var& navig_elem);
  virtual void SetNoMarkedTree(const CATINavigElement_var& navig_elem);
  void InternalSetNoMarkedTree(const CATINavigElement_var& navig_elem, CATSysSimpleHashTable &htab);

// these datas are usefull for the graph implemented in CNext windows
// if you to implement a list management with the Cnext interfaces use the
// the private datas of CATNavigAdaptor
private :
  CATContainerExtension(const CATContainerExtension &iObject); // Prohibited
  CATContainerExtension &operator=(const CATContainerExtension &iObject); // Prohibited

  CATNavigController*		_controller;
  int						_mark;
};

#endif

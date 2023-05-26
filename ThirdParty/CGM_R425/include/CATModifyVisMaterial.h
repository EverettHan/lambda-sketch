/* -*-c++-*- */

#ifndef CATModifyVisMaterial_H
#define CATModifyVisMaterial_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "CATModify.h"

#include "SGInfra.h"
#include "list.h"

#include "CATMaterialApplication.h"

enum ActionToDo { ADDING_MATERIAL, MODIFYING_MATERIAL, REMOVING_MATERIAL };

class ExportedBySGInfra CATModifyVisMaterial : public CATModify
{
  CATDeclareClass;

public:
  CATModifyVisMaterial(CATBaseUnknown               * iObject,
                       CATGraphicMaterial           * iMat,
                       unsigned int					          iInheritance = 1/*MATERIAL_INHERIT*/);

  CATModifyVisMaterial(CATBaseUnknown               * iObject,
                       CATGraphicMaterial           * iMat,
                       CATBaseUnknown               * iSubElement,
                       unsigned int					          iInheritance = 1/*MATERIAL_INHERIT*/);

  CATModifyVisMaterial(CATBaseUnknown               * iObject,
                       CATGraphicMaterial           * iMat,
                       list<CATBaseUnknown>&          iSubElements,
                       unsigned int					          iInheritance = 1/*MATERIAL_INHERIT*/);

  CATModifyVisMaterial(CATBaseUnknown               * iObject,
                       CATGraphicMaterial           * iMat,
                       list<CATBaseUnknown>&          iSubElements,
                       unsigned int					          iInheritance,
                       unsigned int                   iLayer,
                       ActionToDo                     iAction);

  CATModifyVisMaterial(CATBaseUnknown               * iObject,
                       const CATMaterialApplication & iMatApp,
                       list<CATBaseUnknown>&          iSubElements,
                       ActionToDo                     iAction);

  virtual ~CATModifyVisMaterial();

  inline CATGraphicMaterial* GetMaterial() const;
  inline const CATMaterialApplication& GetMaterialApplication() const;
  inline CATBaseUnknown* GetSubElement(unsigned int iPos);
  inline unsigned int    GetSubElementSize();
  unsigned int GetInheritance();
  unsigned int GetLayer();
  ActionToDo   GetActionToDo();

  virtual CATModelNotification * Clone();

protected:
  CATMaterialApplication  _matApp;
  list<CATBaseUnknown>    _subElements;
  ActionToDo              _action;
};

inline CATGraphicMaterial*      CATModifyVisMaterial::GetMaterial() const
{
  return _matApp.GetGraphicMaterial();
};

inline const CATMaterialApplication& CATModifyVisMaterial::GetMaterialApplication() const
{
  return _matApp;
}

inline CATBaseUnknown* CATModifyVisMaterial::GetSubElement(unsigned int iPos)
{
  return _subElements[iPos];
}

inline unsigned int CATModifyVisMaterial::GetSubElementSize()
{
  return _subElements.length();
}


#endif 

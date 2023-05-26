// COPYRIGHT DASSAULT SYSTEMES 2002

#ifndef CATVisContextualManager_H
#define CATVisContextualManager_H

#include "SceneGraphManager.h"
#include "CATIPathElementCustomFilter.h"


class CATPathElement;
class CATBaseUnknown;


class ExportedBySceneGraphManager CATVisContextualManager
{
  friend class CATViewer;

public :
	static CATVisContextualManager * GetContextualManager();
	CATVisContextualManager();
  ~CATVisContextualManager();
	
	CATPathElement * GetSelection();
	void SetSelection(CATPathElement * iPath);

  int IsBackgroundSelected();
  
	CATBaseUnknown* GetSelectedObjectInTree();
	void SetSelectedObjectInTree(CATBaseUnknown * iObj);

  void SetPathElementCustomFilter(CATIPathElementCustomFilter* iCustomFilter);
  void RemovePathElementCustomFilter(CATIPathElementCustomFilter* iCustomFilter);


private:
  CATVisContextualManager(CATVisContextualManager &iCopy);
  CATVisContextualManager & operator = (const CATVisContextualManager &);

  void SetBackgroundSelected(int iOnOff);

  CATPathElement * _SelectionPath;
  CATBaseUnknown * _SelectedObject;
  int              _backgroundSelected;
  static CATVisContextualManager * _TheContextualManager;
  CATIPathElementCustomFilter* _pCustomFilter;
};

#endif

// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidCtlCombo.h
// Header definition of CATVidCtlCombo
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2005  Creation: Code generated by the CAA wizard  jov
//===================================================================
#ifndef CATVidCtlCombo_H
#define CATVidCtlCombo_H

#include <CATVidCtlBaseCombo.h>
#include <CATBoolean.h>
#include <CATUnicodeString.h>
#include <CATVidEnum.h>
#include <VisuDialog.h>

/**
 * @ingroup VIDControls
 * 
 * @deprecated This class is deprecated ; use the CATVidCtlCustomCombo class instead.
 */
class ExportedByVisuDialog CATVidCtlCombo : public CATVidCtlBaseCombo
{
  CATDeclareClass;

public:

  // Standard constructors and destructors
  CATVidCtlCombo();
  CATVidCtlCombo(CATCommand *i_pParent, const CATString & i_pIdentifier);

  int SetLine(CATVidWidget* i_pWidget, int i_index=-1, CATBoolean i_modifyFlag = 0);
  const CATVidWidget* GetLine( int i_index) const;

  void SetTopLine( CATVidWidget* i_pWidget);
  CATVidWidget* GetTopLine() const;

  // Returns the event notification sent whenever a value is preselected in the list.
  CATNotification *GetComboPreselectNotification() const;

protected:

  virtual ~CATVidCtlCombo();

  // Overriden methods
  virtual void OnPreselect();
  virtual void ClearModel();

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlCombo (CATVidCtlCombo &);
  CATVidCtlCombo& operator=(CATVidCtlCombo& original);
};

//-----------------------------------------------------------------------

#endif

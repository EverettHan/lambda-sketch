#ifndef CATVidFraBoxProperties_H
#define CATVidFraBoxProperties_H

// COPYRIGHT Dassault Systemes 2006

#include <VisuDialog.h>
#include <CATUnicodeString.h>
#include <CATVidEnum.h>

class ExportedByVisuDialog CATVidFraBoxProperties
{
public:
  // Standard constructors and destructors
  // -------------------------------------
  CATVidFraBoxProperties ();
  CATVidFraBoxProperties (const CATUnicodeString& i_title, CATVidStyle i_dialogStyle);
  virtual ~CATVidFraBoxProperties ();

  // Copy constructor and equal operator
  // -----------------------------------
  CATVidFraBoxProperties (const CATVidFraBoxProperties& i_fraLayoutData);
  CATVidFraBoxProperties& operator=(const CATVidFraBoxProperties& i_fraLayoutData);

  void SetTitle(const CATUnicodeString& i_title);
  const CATUnicodeString& GetTitle() const;

  void SetIconName(const CATUnicodeString& i_iconName);
  const CATUnicodeString& GetIconName() const;

  void SetDialogType(CATVidDialogType i_dialogType);
  CATVidDialogType GetDialogType() const;

  void SetDialogLifeCycle(CATVidLifeCycle i_dialogLifeCycle);
  CATVidLifeCycle GetDialogLifeCycle() const;

  void SetDialogStyle(CATVidStyle i_dialogStyle);
  CATVidStyle GetDialogStyle() const;

  void SetVisibility(CATBoolean i_visibility);
  CATBoolean GetVisibility() const;

  void SetDiscretionLevel(const unsigned int& i_discretionLevel);
  const unsigned int GetDiscretionLevel() const;

  void SetAllowDialogTypeSwitchFlag(CATBoolean i_allowDialogTypeSwitchFlag);
  CATBoolean GetAllowDialogTypeSwitchFlag() const;

  void SetActivableFlag(CATBoolean i_activableFlag);
  CATBoolean GetActivableFlag() const;

  void SetLook(const CATUnicodeString& i_look);
  const CATUnicodeString& GetLook() const;

  void SetActivateInDockFlag(CATBoolean i_activateInDockFlag);
  CATBoolean GetActivateInDockFlag() const;

  void SetHorizontallyStretchableFlag(CATBoolean i_stretchableFlag);
  CATBoolean GetHorizontallyStretchableFlag() const;

  void SetVerticallyStretchableFlag(CATBoolean i_stretchableFlag);
  CATBoolean GetVerticallyStretchableFlag() const;

  /**
   * Specifies whether the position of the window is limited to its viewer bounding rectangle,
   * whatever its contraints are, or not (in which case the window may be clipped).
   * By default the ConstraintUpdateAllowedFlag property is set to TRUE.
   */
  void SetConstraintUpdateAllowedFlag(CATBoolean i_constraintUpdateAllowedFlag);
  CATBoolean GetConstraintUpdateAllowedFlag() const;

private:

  CATUnicodeString _title;
  CATUnicodeString _iconName;
  CATUnicodeString _look;
  CATVidDialogType _dialogType;  
  CATVidLifeCycle  _dialogLifeCycle;
  CATVidStyle      _dialogStyle;  
  unsigned int     _discretionLevel;
  CATBoolean       _visibility;
  CATBoolean       _allowDialogTypeSwitchFlag;
  CATBoolean       _activableFlag;
  CATBoolean       _activateInDockFlag;
  CATBoolean       _horizontallyStretchableFlag;
  CATBoolean       _verticallyStretchableFlag;
  CATBoolean       _constraintUpdateAllowedFlag;
};

#endif

#ifndef CATVidLayDockConstraints_h
#define CATVidLayDockConstraints_h

// COPYRIGHT Dassault Systemes 2005

// VisuImmersiveDialog framework
#include "VisuDialog.h"
#include "CATVidLayConstraints.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"

/**
 * @ingroup VIDLayout
 * Layout constraints used by the CATVidLayDock class to position the embedded widgets.
 * @see CATVidLayDock
 */
class ExportedByVisuDialog CATVidLayDockConstraints : public CATVidLayConstraints
{
  CATDeclareClass;

public:

  // Standard constructors and destructors
  CATVidLayDockConstraints();
  virtual ~CATVidLayDockConstraints();

  // Copy constructor and equal operator
  CATVidLayDockConstraints (const CATVidLayDockConstraints &);
  CATVidLayDockConstraints& operator=(const CATVidLayDockConstraints&);

  virtual CATBoolean IsEqualTo(const CATVidLayConstraints& i_constraints) const;

  /**
   * Copy the given constraints values.
   */
  virtual void CopyFrom(const CATVidLayConstraints& i_constraints);

  virtual CATVidLayConstraints* Clone() const; 

  /**
   * Specifies that the associated widget must be attached on the left side of the dock layout.
   */
  void SetLeftAttach(CATBoolean i_leftAttach);
  CATBoolean GetLeftAttach() const;

  /**
   * Specifies that the associated widget must be attached on the right side of the dock layout.
   */
  void SetRightAttach(CATBoolean i_rightAttach);
  CATBoolean GetRightAttach() const;

  /**
   * Specifies that the associated widget must be attached on the top side of the dock layout.
   */
  void SetTopAttach(CATBoolean i_topAttach);
  CATBoolean GetTopAttach() const;

  /**
   * Specifies that the associated widget must be attached on the bottom side of the dock layout.
   */
  void SetBottomAttach(CATBoolean i_bottomAttach);
  CATBoolean GetBottomAttach() const;

  /**
   * Specifies that the associated widget must be attached on the center area of the dock layout.
   */
  void SetCenterAttach(CATBoolean i_centerAttach);
  CATBoolean GetCenterAttach() const;

  /**
   * Sets the docking priority of the associated widget.
   * This priority is used to compute the order of the docked widgets in the CATVidLayDock layout.
   * The smaller the priority is, the closer to the center area the docked widget is.
   * If two widgets docked in the same area have the same priority, the last docked widget will be
   * placed closer to the center area than the first one.
   * For example, if two widgets are docked in the Left area, the widget with the higher priority
   * will be placed on the Left of the other one.
   * By default, the Priority property is set to 0.
   */
  void SetPriority(int i_priority);
  int GetPriority() const;

private:

  void ResetAttachment();

private:

  int _priority;
  CATBoolean _leftAttach;
  CATBoolean _rightAttach;
  CATBoolean _topAttach;
  CATBoolean _bottomAttach;
  CATBoolean _centerAttach;
   
  friend inline int operator == (const CATVidLayDockConstraints &i_constaints1, const CATVidLayDockConstraints &i_constaints2);
};

extern "C" ExportedByVisuDialog 
HRESULT CATSYPCATVidLayDockConstraintsSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

inline int operator == (const CATVidLayDockConstraints &i_constraints1, const CATVidLayDockConstraints &i_constraints2)
{
	return (i_constraints1._priority == i_constraints2._priority && i_constraints1._leftAttach == i_constraints2._leftAttach &&
		i_constraints1._rightAttach == i_constraints2._rightAttach && i_constraints1._topAttach == i_constraints2._topAttach &&
		i_constraints1._bottomAttach == i_constraints2._bottomAttach && i_constraints1._centerAttach == i_constraints2._centerAttach );
}

#endif // CATVidLayDockConstraints_h

#ifndef CATVidFraLayoutData_h
#define CATVidFraLayoutData_h

// COPYRIGHT Dassault Systemes 2006

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidLaySideAttachConstraints.h>
#include <CATVidLayDockConstraints.h>
#include <CATVidLay2DSyncToViewpointConstraints.h>

// UIVCoreTools framework
#include <UIVCoreToolsInline.h>

/**
 * Layout information used by the VID windows.
 * @see CATVidFraWindow
 */
class ExportedByVisuDialog CATVidFraLayoutData
{
public:

  // Standard constructors and destructors
  CATVidFraLayoutData ();
  virtual ~CATVidFraLayoutData ();

  // Copy constructor and equal operator
  CATVidFraLayoutData(const CATVidFraLayoutData& i_fraLayoutData);
  CATVidFraLayoutData& operator=(const CATVidFraLayoutData& i_fraLayoutData);

  INLINE void SetSideAttachConstraints(const CATVidLaySideAttachConstraints& i_sideAttachConstraints)
  {
    _sideAttachConstraints = i_sideAttachConstraints;
  }
  INLINE const CATVidLaySideAttachConstraints& GetSideAttachConstraints() const
  {
    return _sideAttachConstraints;
  }

  INLINE void SetDockConstraints(const CATVidLayDockConstraints& i_dockConstraints)
  {
    _dockConstraints = i_dockConstraints;
  }
  INLINE const CATVidLayDockConstraints& GetDockConstraints() const
  {
    return _dockConstraints;
  }
  
  INLINE void SetLabelConstraints(const CATVidLay2DSyncToViewpointConstraints& i_labelConstraints)
  {
    _labelConstraints = i_labelConstraints;
  }
  INLINE const CATVidLay2DSyncToViewpointConstraints& GetLabelConstraints() const
  {
    return _labelConstraints;
  }

private:

  CATVidLaySideAttachConstraints _sideAttachConstraints;
  CATVidLay2DSyncToViewpointConstraints _labelConstraints;
  CATVidLayDockConstraints _dockConstraints;
};

#endif

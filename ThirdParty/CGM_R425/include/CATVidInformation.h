#ifndef CATVidInformation_H
#define CATVidInformation_H

// Local framework
#include <VisuDialog.h>

// UIVCoreTools framework
#include <UIVCoreToolsInline.h>

// System framework
#include <CATBoolean.h>

// SpecialAPI framework
#include <CATSysDataType.h>


// CATVidInformation-----------------------------------------------------------------
enum CATVidInformationType {
    CATVidViewerChange
  , CATVidMainColorsChange
  , CATVidFatherPositionChange
  , CATVidClippingUse
  , CATVidConnectionChange
  , CATVidResetView
};

/**
 * Class used in the CATVidWidget::TunnelInformation method to broadcast information to the widget children.
 */
class ExportedByVisuDialog CATVidInformation 
{
public:

  /**
   * Constructor
   * @param i_type
   * Type of the broadcasted information
   * @param i_pData
   * Optional arguments corresponding to the  broadcasted information.
   * For example, if the information is of type CATVidConnectionChange, the i_pData will be of type CATVidConnectionChangeArgs *.
   * No pointer on the data must be kept. It may be deleted immediately after the broadcast.
   */
  INLINE CATVidInformation(CATVidInformationType i_type, void * i_pData = NULL) : _type(i_type), _pData(i_pData) {};
  INLINE ~CATVidInformation() {};

  INLINE operator int() const {return (int) _type;};

  INLINE CATVidInformationType GetType() const {return _type;}

  INLINE void* GetData() const {return _pData;}

private:

  CATVidInformationType _type;
  void * _pData;
};

/**
 * Class used as argument when CATVidWidget::TunnelInformation(CATVidConnectionChange) is called.
 */
class ExportedByVisuDialog CATVidConnectionChangeArgs 
{
public:

  INLINE CATVidConnectionChangeArgs(CATBoolean i_connectedState) : _connectedState(i_connectedState) {};
  INLINE ~CATVidConnectionChangeArgs() {};

  INLINE CATBoolean GetConnectedState() const {return _connectedState;}

private:

  CATBoolean _connectedState;
};

enum CATVidTextValidationState
{
	 TXT_VALID
	,TXT_INTERMEDIATE
	,TXT_INVALID
};

#endif

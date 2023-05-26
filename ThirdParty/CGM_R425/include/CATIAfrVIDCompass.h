//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/05/27
//===================================================================
// CATIAfrVIDCompass.cpp
// Header definition of class CATIAfrVIDCompass
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/05/27 Creation
//===================================================================
#ifndef CATIAfrVIDCompass_H
#define CATIAfrVIDCompass_H

#include "CATAfrItf.h"
#include "CATString.h"
#include "CATCommand.h"
#include "CATPLMCompassMode.h"

class CATCSO;
class CATVizViewer;
class CATMathPointf;
class CATRepPath;
//class CATAfrPLMCompassAnimState;
class CATNotification;
class CATIAfrPLMCompassModel;
class CATIAfrCompassLabelView;

enum CATAfrPLMCompassAnimState
{
  ForcePlayAnim  =  1,
  ForcePauseAnim =  2
};

enum CATPLMCompassMaxiPlayerStyle
{ 
  CATPLMCompassMaxiPlayerStyleUndef = 1, 
  CATPLMCompassMaxiPlayerStyleAnimation = 2, 
  CATPLMCompassMaxiPlayerStyleProgram = 3, 
  CATPLMCompassMaxiPlayerStyleTimeMachine = 4, 
  CATPLMCompassMaxiPlayerStyleLast = 5, 
  CATPLMCompassMaxiPlayerStyleAnimationNoText = 6,
  CATPLMCompassMaxiPlayerStyleProgramExtended = 7
};

enum CATPLMCompassMaxiPlayerLoopMode
{
  CATPLMCompassMaxiPlayerLoopRunOnce = 1,
  CATPLMCompassMaxiPlayerLoopRunContinuously = 2,
  CATPLMCompassMaxiPlayerLoopRunContinuouslyBackAndForth = 3,
  CATPLMCompassMaxiPlayerLoopRunReverse = 4,
  CATPLMCompassMaxiPlayerLoopLast
};


//The speed mode define the drop down menu for speed selection.
//There is 2 ways to define speed control
//1st speed mode: SpeedA is for 1/32,1/16, 1/8, ¼, ½, 1, 2, 4, 8, 16, 32
//Other modes may be defined in the future
//When the mode is userdefined the boundaries and step are defined by user:
//Step 10 and boundary 30 will make a choice for 1/30, 1/20, 1/10, 1, 10, 20, 30
enum CATPLMCompassMaxiPlayerSpeedMode 
{ 
  CATPLMCompassMaxiPlayerSpeedUndef = 1, 
  CATPLMCompassMaxiPlayerSpeedUserDefined = 2, 
  CATPLMCompassMaxiPlayerSpeedTypeA = 3, 
  CATPLMCompassMaxiPlayerSpeedLast
};

enum CATPLMCompassMaxiPlayerTimeControlType
{
  CATPLMCompassMaxiPlayerSpeed = 1,
  CATPLMCompassMaxiPlayerFps = 2,
  CATPLMCompassMaxiPlayerDuration = 3,
  CATPLMCompassMaxiPlayerMaximum = 4
};

#define AFR_Temp_CATPLMCompassMaxiPlayerButtonStyle
// The style combinations for Maxi Player
typedef unsigned long CATPLMCompassMaxiPlayerButtonStyle;

const unsigned long NextButtonHidden = (1 << 0);
const unsigned long BackButtonHidden = (1 << 1);
const unsigned long FirstButtonHidden = (1 << 2);
const unsigned long LastButtonHidden = (1 << 3);
const unsigned long PlaybackModeHidden = (1 << 4);
const unsigned long StopButtonHidden = (1 << 5);
const unsigned long ExportButtonHidden = (1 << 6);
const unsigned long OptionsButtonHidden = (1 << 7);
const unsigned long SpeedOptionHidden = (1 << 8);
const unsigned long DurationOptionHidden = (1 << 9);
const unsigned long FpsOptionHidden = (1 << 10);
const unsigned long MaximumOptionHidden = (1 << 11);
const unsigned long LoopRunOnceButtonHidden = (1 << 12);
const unsigned long LoopRunContinuouslyButtonHidden = (1 << 13);
const unsigned long LoopRunContinuouslyBackAndForthButtonHidden = (1 << 14);

extern ExportedByCATAfrItf  IID IID_CATIAfrVIDCompass ;

class ExportedByCATAfrItf CATAfrCompassModel
{ 
public:
  CATAfrCompassModel(CATCSO * i_CSO, const CATBaseUnknown_var & i_filter) : 
  _CSO(i_CSO),
  _filter(i_filter)
  {};

  ~CATAfrCompassModel()
  {
	_CSO = NULL;
  }
public:
 
  CATCSO * _CSO;
  CATBaseUnknown_var _filter;
 }; 

class ExportedByCATAfrItf CATIAfrVIDCompass: public CATBaseUnknown
{
  CATDeclareInterface;

public:



  /**
  * Implements a function from an interface.
  * @href CATIAfrVIDCompass#CreateVIDCompass
  */
  virtual HRESULT CreateVIDCompass(CATVizViewer * iViewer, const CATString &iName,  CATCSO *iCSO = NULL, const CATBaseUnknown_var & iFilter = NULL_var, int iStyle=0)=0;

  /**
  * Request delayed destruction
  */
  virtual void RequestDelayedDestruction()=0;

  /**
  * Change parent. Implementation calls CATCommand::SetParent.
  **/
  virtual void Reparent(CATCommand * i_pParent)=0;
  /**
  * Change current mode
  **/
  virtual void SetMode(const CATPLMCompassMode &iMode)=0;
  /**
  * Get current mode
  **/
  virtual const CATPLMCompassMode & GetMode() const=0;
	/**
	 * Change current LiveShape mode
	 **/
	virtual void SetModeDesign( const CATPLMCompassMode &iMode ) =0;
  /**
  *
  * <br><b>Role</b>: Return the associated viewer
  * @return the viewer
  * 
  */
  virtual CATVizViewer * GetViewer() const=0;

  /**
  * Change in PlayOnly Mode
  **/
  virtual void SetPlayerOnlyDesign() = 0 ;
  /**
  * Get PlayerOnly mode
  **/
  virtual const CATBoolean GetPlayerOnlyDesign() = 0 ;

  /**
  * Set player position and play mode
  * iPosition is between 0.0 and 1.0
  * iPlay is 0 for pause, 1 for play
  **/
  virtual void SetPlayer(  const float &  iPosition,  const int &  iPlay ) = 0 ;
  /**
  * Get player position and play mode
  **/
  virtual void GetPlayer( float &oPosition, int &oPlay ) const = 0;
  /**
  * Set plm compass visibility 
  **/
  virtual void SetCompassVisibility( const int & iVisibility ) = 0 ;
  /**
  * Get plm compass visibility
  **/
  virtual int GetCompassVisibility( void ) const = 0;
  /**
  * Set toolbar visibility (toolbar will show only if enabled)
  **/
  virtual void SetToolbarVisibility(  const int & iVisibility ) = 0 ;
  /**
  * Get toolbar visibility
  **/
  virtual int GetToolbarVisibility( void ) const = 0;
  /**
  * Make toolbar visible
  **/
  virtual void MakeToolbarVisible() = 0 ;

  /**
   * Set refinement panel visibility
   **/
  virtual void SetRefinementPanelVisibility(  const int & iVisibility ) = 0 ;
  /**
   * Get refinement panel visibility
   **/
  virtual int GetRefinementPanelVisibility( void ) const = 0;

  //-----------------------------********************---------------------------
  // Développement TPC 
  //-----------------------------********************---------------------------

  /**
  * Attach the compass to a 3D point.
  * iPath is the rep path that will be used to compute transformation to apply to iPoint
  * iPoint is the 3D point coordinate in the axis system defined by the transformation matrix
  * computed by CATRepPath. Most commonly the bounding sphere center of the rep of the object
  * to which the compass is attached to.
  * Sample:
  *
  CATPLMCompass *compass= CATPLMCompass::GetCompass( CAT3DNFrmWindow::GetCurrentWindow() ) = 0 ;
  if( compass && iPathElement )
  {
  CATRepPath rp;
  for( int i= 0; i<iPathElement->GetSize()  ; i++ )
  {
  CATI3DGeoVisu_var visu( (*iPathElement)[i] )  ;
  if( !!visu )
  {
  CATRep *rep= visu->GetRep()  ;
  if( rep )
  {
  rp.AddRep( *rep )  ;
  }
  }
  }
  compass->SetAnchor( rp, CATMathPointf() )  ;
  compass->SetPosition( CATPLMCompass::Anchored )  ;
  }
  *
  **/
  virtual HRESULT SetAnchor( const CATRepPath &iPath, const CATMathPointf &iPoint ) = 0 ;
  /**
  * Detach the compass from 3D point, and put it back to its normal position
  **/
  virtual HRESULT UnsetAnchor( void ) = 0 ;


  //-----------------------------********************---------------------------
  // Développement TPC 
  //-----------------------------********************---------------------------

  /**
  * Get/Set to know if the compass is painted grey
  **/
  // Every compasses will be greyed
  virtual void SetCompassGrey(bool isGreyed = true) = 0 ;

  // Only this compass will be greyed
  virtual void SetThisCompassGrey(bool isGreyed = true) = 0 ;

  // Return true if this compass is greyed (or if every compass is greyed)
  virtual bool IsCompassGrey() = 0 ;


  /**
  * Set state of the animation
  **/
  virtual void SetPlayerState(CATAfrPLMCompassAnimState iStyle, CATBoolean iNotify) = 0 ;

  /**
  * Attach to an object
  **/
  virtual void Attach( CATBaseUnknown *iObject ) = 0;
  /**
  * Detach from an object
  **/
  virtual void Detach( CATBaseUnknown *iObject ) = 0;

  /**
  * Adds a callback when PLM Compass mode change published by a given command.
  *
  * N.B : So as to avoid problems using the interface as data member in the scope 
  * of the method, you have to give as iUsefulData (the second parameter) this pointer casted.
  * ex : ... ->AddModeChangeNotificationCB( (CATCommandMethod)&MyClass::MyMethodCalledOnCB.., 
  (CATCommandClientData*)this) = 0 ;
  *
  * Then in the method MyMethodCalledOnCB, you need to do for retrieving the pointer _piCompass
  * on CATIAfrVIDCompass  to do : 
  *
  * ex : 
  * MyClass * pMyClassptr = (MyClass *) iUsefulData
  * if (pMyClassptr)
  * { 
  *   CATIAfrVIDCompass * piCompass = pMyClassptr -> _piCompass; // or for CATFrmWindow type use GetCompassPtrItf() to retrieve the compass
  *   if (piCompass)
  *   {
  *    // Finally , I can now do my treatment by using the class pointer.
  *
  * @param iMethodToExecute
  *   The method to execute 
  * @param iUsefulData
  *   Data to pass to <tt>iMethodToExecute</tt> and that can be useful
  *   to this method
  * @return
  *   The added callback
  */
  virtual CATCallback AddModeChangeNotificationCB(CATCommandMethod iMethodToExecute, CATCommandClientData iUsefulData) = 0;
  /**
  * Remove the previously Callback got by AddModeChangeNotificationCB
  *
  * 
  * @param callback
  *   The callback
  */
  virtual void RemoveModeChangeNotificationCB(CATCallback callback) = 0;
  /**
  * Sets the model
  **/
  virtual HRESULT SetModel( CATIAfrPLMCompassModel* ipiModel ) = 0 ;


  /**
  * Sets the model
  **/
  virtual HRESULT SetCompassModel( CATAfrCompassModel * ipModel ) = 0 ;

  /**
  * Sets the model anchored
  **/
  virtual HRESULT SetCompassModelAnchored( CATAfrCompassModel * ipModel ) = 0 ;
  /**
  * Sets the label view
  **/
  virtual HRESULT SetLabelView( CATIAfrCompassLabelView* ipiModel ) = 0 ;

  /**
  * Gets the label view
  **/
  virtual HRESULT GetLabelView( CATIAfrCompassLabelView** ipiModel ) = 0 ;
};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIAfrVIDCompass, CATBaseUnknown );
#endif

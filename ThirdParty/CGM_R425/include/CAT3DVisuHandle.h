#ifndef CAT3DVisuHandle_H
#define CAT3DVisuHandle_H

//******************************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1998
//******************************************************************************
//  Abstract:
//  ---------
//    Visual representation of a 3D transformation applied to an object   
//******************************************************************************
//  Usage:
//  ------
//      
//******************************************************************************
//  Inheritance:
//  ------------
//                  CAT3DVisuHandle (FW Visualisation)
//                        CATVisuHandle (FW Visualisation).
//                          CATCommand (FW system) 
//******************************************************************************
//  Main Methods:
//  -------------
//  CATRep * GetRep   : returns the handle's representation 
//  void SetStyle     : allows the modification of style 1 and 2 during the handle's lifecycle 
//  void SetPosition  : sets the handle's Rep and manipulator position
//  CATMathAxis GetPosition : returns the current position
//******************************************************************************

#include "CATVisController.h"
#include "CATVisuHandle.h"
#include "CAT3DManipulator.h"
#include "CATMathAxis.h"

class CAT3DRep;
class CAT3DBagRep;
class CATRepWeakRef;
//History : modification on March 2001 by srx.
//New construstor taking into account the new flags of CATVisuHandle.
//This constructor is good for both father and son VisuHandle.

/**
* A CAT3DVisuHandle allows object manipulation. 
* It has its own representation and its own manipulator.
*/
class ExportedByCATVisController CAT3DVisuHandle : public CATVisuHandle
{
   
   CATDeclareClass; // pour IsKindOF
   
   
public:
   
   /** @nodoc */
   // Construction methods:
   
   // Construction method for a father handle
   // Only _HandleRep is created. This Handle will only be able to emit 
   // events through its children which will be attached to it
   // with their constructor
   // by default this handle updates its rep  
   // and displays its children
   CAT3DVisuHandle( CATCommand *iFather, const CATString &iName,
      const int iUpdateRep=1 ,const int iUpdatePos=1,
      const int switchableVisibility=0, CAT3DRep *iUserStyleRep = NULL,
      const CAT3DManipulator::ManipulationStyle iFirstStyle = CAT3DManipulator::NoManipulation, CATManipulator* iManipulator = NULL);
   
   /** @nodoc */
   // this constructor builds default elementary Handles
   // UserRepStyle1 and UserRepStyle2 won't be destroyed at the destruction
   // except if they are created by the handle itself using default style
   // if iFather is a CAT3DVisuHandle its rep will only be automatically
   // updated through its father
   CAT3DVisuHandle(
      CATCommand *iFather, 
      const CATString &iName,
      const int iUpdateFlag,
      const CAT3DManipulator::ManipulationStyle iFirstStyle = CAT3DManipulator::NoManipulation, CAT3DRep *iUserStyle1Rep = NULL, 
      const CAT3DManipulator::ManipulationStyle iSecondStyle=CAT3DManipulator::NoManipulation,
      CAT3DRep *iUserStyle2Rep = NULL, CATManipulator* iManipulator = NULL);
   
      /**
      * @nodoc
      */
      CAT3DVisuHandle(
      CATCommand *iFather, 
      const CATString &iName,
      const CATVisuHandle::UpdateFlag iUpdateFlag,
      const CAT3DManipulator::ManipulationStyle iFirstStyle = CAT3DManipulator::NoManipulation, CAT3DRep *iUserStyle1Rep = NULL, 
      const CAT3DManipulator::ManipulationStyle iSecondStyle=CAT3DManipulator::NoManipulation,
      CAT3DRep *iUserStyle2Rep = NULL, CATManipulator* iManipulator = NULL);

      /**
      * Constructor
      * @param iFather
      *    a pointer to the father command of the handle (it can be a CAT3DVisuHandle)
      * @param iName 
      *    the handle name
      * @param iUpdateFlag 
      *    see the options in @href CATVisuhandle. 
      * @param iInvisible
      *     if iInvisible = 1 then the handle has NO representation of its own
      *                       the representation given as an argument in the constructor
      *                       is the representation of the object the handle manipulates.
      *                       1 is the default value.
      *     if iInvisible = 0 then the handle has a representation of its own
      *                       the representation given as an argument in the constructor
      *                       is the representation of the handle (for instance a little square)
      * @param iFirstStyle 
      *    first manipulation style. Default value NoManipulation.
      * @param iUserStyle1Rep 
      *    the representation of the handle associated with the first manipulation style.
      *    Default Value NULL.
      *    NB : if iUserStyle1Rep is NULL and the flag SwitchVisSon is activated then the handle
      *    builds a default representation.
      * @param iSecondStyle 
      *    second manipulation style. Not implemented. Default value NoManipulation.
      * @param iUserStyle2Rep 
      *    the representation of the handle associated with the second manipulation style. 
      *    Default Value NULL.
      * @param iManipulator 
      *    manipulator. Default Value NULL.
      *    NB : if no manipulator is given as an argument, the handle builds its own manipulator.
      */
   CAT3DVisuHandle(
      CATCommand *iFather, 
      const CATString &iName,
      const CATVisuHandle::UpdateFlag iUpdateFlag,
      const int iInvisible = 1,
      const CAT3DManipulator::ManipulationStyle iFirstStyle = CAT3DManipulator::NoManipulation, CAT3DRep *iUserStyle1Rep = NULL, 
      const CAT3DManipulator::ManipulationStyle iSecondStyle=CAT3DManipulator::NoManipulation,
      CAT3DRep *iUserStyle2Rep = NULL, CATManipulator* iManipulator = NULL);
   
      /**
      * Destructor
      */
   virtual ~CAT3DVisuHandle(void);
   
   virtual HRESULT LogicalDeath();
   
   virtual void CleanRep();
   
   /**
   *Gets the handle representation :
   */
   virtual CAT3DBagRep * GetRep()  ;
   
   /**
   * Gets bag where the reps are attached.
   * In case of a handle with switchable visibility (_switchableVisibility = 1 or SwitchSonVis activated),
   * returns _VisibilityRep otherwise returns same thing as GetRep()
   */
   virtual CAT3DBagRep *GetVisibleRep() ; 
   
   /**
   * @nodoc
   * to warn the command that its handled rep is being destroyed
   */
   
   virtual void UnreferenceHandledRep() ;
   
   /**
   * Modification of the handle manipulation style
   * with possibility to change its representation
   * Method not implemented.
   * @param iRangStyle : PrimaryStyle, Secondary...... 
   * @param iManipStyle is propagated to the manipulator
   * @param iRequestDefaultStyleRep : allows to request default rep
   * @param iUserStyleRep : User's rep if  iRequestDefaultStyleRep = 0
   */
   
   virtual void SetStyle(
      RangeStyle  iRangeStyle,
      const CAT3DManipulator::ManipulationStyle iManipStyle=CAT3DManipulator::NoManipulation,
      int iRequestDefaultStyleRep = 1,
      CAT3DRep *iUserStyleRep = NULL);
   
      /**
      * Positions explicitly the Rep of the handle
      * This position is transmitted to its manipulator
      * and its children manipulators. The rep is midified by the CATVisManager only 
      * if flag UpdateRepVisuEvent or SwitchSonVis are activated, which is the right thing to do.
      */
   virtual void SetPosition( const CATMathAxis &iPosition);
   
   /**
   * Gets handle position
   */
   virtual CATMathAxis GetPosition() const;
   
   
   // Geometry invariants :
   
   
   /**
   * Sets the invariant point of PointRotation 
   * @param iPoint the new invariant rotation point
   */
   virtual void SetRotationPoint( const CATMathPoint &iPoint);
   /**
   * Gets the invariant point of PointRotation 
   */
   virtual CATMathPoint GetRotationPoint();
   
   /** 
   * Sets the invariant direction of Translation 
   * @param iWAxis the new invariant translation direction
   */
   virtual void SetTranslationDirection( const CATMathDirection &iWAxis);
   
   /** 
   * Gets the invariant direction of Translation 
   */
   virtual CATMathDirection GetTranslationDirection();
   
   
   /**
   * Sets the invariant line of LineRotation and PlaneMovement
   * @param iLine : the new invariant line of LineRotation and PlaneMovement.
   */
   virtual void SetRotationLine(const CATMathLine &iLine);
   
   /**
   * Gets the invariant line of LineRotation and PlaneMovement
   */
   virtual CATMathLine GetRotationLine();
   
   /**
   * Sets the invariant plane of PlaneTranslation and PlaneMovement
   * @param iPlane : the new invariant plane of PlaneTranslation and PlaneMovement.
   */
   virtual void SetTranslationPlane( const CATMathPlane &iPlane);
   
   /**
   * Gets the invariant plane of PlaneTranslation and PlaneMovement
   */
   virtual CATMathPlane GetTranslationPlane();
   
   /**
   *Decode of notification (for elementary transformation)
   */
   virtual void * SendCommandSpecificObject ( const char *, CATNotification *);
   
   void SwitchRepOn();
   void SwitchRepOff();

   
protected:
   
/**
*Interpretation of notifications :
* Only the event (system) CATManipulate is caught.
* A visu event is sent to CATVisManager and CATVisManager handles the visu events 
* (for instance CATModifyMatrix, CATDelete, etc...)
*/
   virtual void InterpretNotification(CATCommand *iCommand,
      CATNotification *iNotif,
      CATCommandClientData iData);
   
  /**
   * Method used to switch the handle visibility on when it is preactivated
   * We switch from _NoVisibilityRep to _VisibilityRep.
   */
   void SwitchVisibilityOn(CATCommand *iCommand,
      CATNotification *iNotif,
      CATCommandClientData iData);

      
  /**
   * This method is called whenever the user changes from handle. It is called to
   * "depreactivate" the handle the user has just left.
   */
   void SwitchVisibilityOff();
   
   /**
   * Representation associated to the Handle which is returned by GetRep :
   */
   CAT3DBagRep *_HandleRep;
   /**
   * Representation of the handle when flag SwitchSonVis is activated and when the handle is not preactivated.
   * NB : _NoVisibilityRep is added in the children list of _VisibilityRep.
   */
   CAT3DRep    *_NoVisibilityRep; 
   /**
   * Representation of the handle when flag SwitchSonVis is activated and when the handle is preactivated.
   */
   CAT3DBagRep *_VisibilityRep;   
   
   /**
   * Representations associated to the manipulator's style :
   */
   
   CAT3DBagRep *_StyleRep[2];
   
   /**
   * flags type construction of the Rep style used by the handle
   * this flags are used in the destructor to know who constructed the Rep
   * and so who has to destroy it
   * 0 : default the handle destroys the rep 
   * 1 : users the rep is not destroyed by the handle
   */
   int _TypeBuildStyle[2];
   
   /**
    * indicates if the current handle has a switchable visibility.
    * If 0, the handle does not have a switchable visibility, it displays all its children
    * If 1, the handle has a switchable visibility, displays its children only when preactivated
    */
   int _switchableVisibility;
   int _visibilityMode; // to know which mode we are currently in
   
   //-----------------------------------------------------------------------------//
   //-----------------------------------------------------------------------------//    
private:
   
   
   virtual CAT3DRep *BuildDefaultRepStyle(CAT3DManipulator::ManipulationStyle iManipStyle);
   int _fatherRepCreated;

   CATRepWeakRef* _pVisibilityRepWeakRef;
   CATRepWeakRef* _pStyleRepPrimaryStyleWeakRef;
   CATRepWeakRef* _pStyleRepSecondaryStyleWeakRef;
};


#endif

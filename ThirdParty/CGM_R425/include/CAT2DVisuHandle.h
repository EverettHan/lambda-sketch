#ifndef CAT2DVisuHandle_H
#define CAT2DVisuHandle_H

//******************************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1998
//******************************************************************************
//  Abstract:
//  ---------
//    Representation visuelle de transformation 2D applicable a un objet  
//******************************************************************************
//  Usage:
//  ------
//      
//******************************************************************************
//  Inheritance:
//  ------------
//                  CAT2DVisuHandle (FW Visualisation)
//                        CATVisuHandle (FW Visualisation).
//                          CATCommand (FW system) 
//******************************************************************************
//  Main Methods:
//  -------------
//  CATRep * GetRep   : returns the handle representation 
//  void SetStyle     : allows the modification of style 1 and 2 during the handle's lifecycle
//  void SetPosition  : sets the handle's Rep and manipulator position
//  CATMathAxis2D GetPosition : eturns the current position
//******************************************************************************

#include "CATVisController.h"
#include "CATVisuHandle.h"
#include "CAT2DManipulator.h"
#include "CATMathAxis2D.h"

class CAT2DRep;
class CAT2DBagRep;

//History : modification on March 2001 by srx.
//New construstor taking into account the new flags of CATVisuHandle.
//This constructor is good for both father and son VisuHandle.

/**
* A CAT3DVisuHandle allows object manipulation. 
* It has its own representation and its own manipulator.
*/

class ExportedByCATVisController CAT2DVisuHandle : public CATVisuHandle
{
   
   CATDeclareClass; // pour IsKindOF
   
   
public:
   
   // Construction and destruction methods:
   // -------------------------------------
    /** @nodoc */     
   // le constructeur d'un handle parent pret pour recevoir des Handles fils,
   // seul sa represenation _HandleRep est cree. Ce Handle ne pourra emettre
   // que des evenement via ses fils qui lui seront rattaches ensuite de maniere
   // implicite via leur constructeur (loosque iFather IsAKindOf CATVisuHandle
   // par defaut ce type de handle demande update de sa rep 

   CAT2DVisuHandle( CATCommand *iFather, const CATString &iName,
      const int iUpdateRep=1,const int iUpdatePos=1,
      const int switchableVisibility=0,CAT2DRep *iUserStyleRep = NULL,
      const CAT2DManipulator::ManipulationStyle iFirstStyle=CAT2DManipulator::NoManipulation);
   
   /** @nodoc */
   // le constructeur de Handle elementaire, les UserRepStyle1 et UserRepStyle2
   // seront detruites a la destruction du Handle 
   // Si iFather est un CAT2DVisuHandle alors sa Rep ne sera plus updatee
   // de maniere automatique ce sera via son pere
   CAT2DVisuHandle(
      CATCommand *iFather, 
      const CATString &iName,
      const int iUpdateFlag,
      const CAT2DManipulator::ManipulationStyle iFirstStyle ,
      CAT2DRep *iUserStyle1Rep = NULL, 
      const CAT2DManipulator::ManipulationStyle iSecondStyle=CAT2DManipulator::NoManipulation,
      CAT2DRep *iUserStyle2Rep = NULL);

      /**
      * @nodoc
      */
   CAT2DVisuHandle(
      CATCommand *iFather, 
      const CATString &iName,
      const CATVisuHandle::UpdateFlag iUpdateFlag,
      const CAT2DManipulator::ManipulationStyle iFirstStyle=CAT2DManipulator::NoManipulation ,
      CAT2DRep *iUserStyle1Rep = NULL, 
      const CAT2DManipulator::ManipulationStyle iSecondStyle=CAT2DManipulator::NoManipulation,
      CAT2DRep *iUserStyle2Rep = NULL);
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
      *     if iInvisible = 0 then the handle has a representation of its own
      *                       the representation given as an argument in the constructor
      *                       is the representation of the handle (for instance a little square)
      * @param iFirstStyle
      *     first manipulation style. Default value NoManipulation.
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
      * 
      */
   CAT2DVisuHandle(
      CATCommand *iFather, 
      const CATString &iName,
      const CATVisuHandle::UpdateFlag iUpdateFlag,
      int iInvisible=1,
      const CAT2DManipulator::ManipulationStyle iFirstStyle=CAT2DManipulator::NoManipulation ,
      CAT2DRep *iUserStyle1Rep = NULL, 
      const CAT2DManipulator::ManipulationStyle iSecondStyle=CAT2DManipulator::NoManipulation,
      CAT2DRep *iUserStyle2Rep = NULL);

  /**
   * Destructor
   */
   virtual ~CAT2DVisuHandle(void);
   
   virtual HRESULT LogicalDeath();
   
   virtual void  CleanRep();
   
   
   
   /**
   *Gets the handle representation :
   */
   virtual CAT2DBagRep * GetRep()  ;
   
   /**
   * Gets bag where the reps are attached.
   * In case of a handle with switchable visibility (_switchableVisibility = 1 or SwitchSonVis activated),
   * returns _VisibilityRep otherwise returns same thing as GetRep()
   */
   virtual CAT2DBagRep *GetVisibleRep() ;
   
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
      const CAT2DManipulator::ManipulationStyle iManipStyle=CAT2DManipulator::Translation,
      int iRequestDefaultStyleRep = 1,
      CAT2DRep *iUserStyleRep = NULL);
   
   /**
   * Positions explicitly the Rep of the handle
   * This position is transmitted to its manipulator
   * and its children manipulators. The rep is midified by the CATVisManager only 
   * if flag UpdateRepVisuEvent or SwitchSonVis are activated, which is the right thing to do.
   */
   
   virtual void SetPosition( const CATMathAxis2D &iPosition);
   
   /**
   * Gets handle position
   */
   virtual CATMathAxis2D GetPosition() const;
   
   // Geometry invariants :
   //---------------------
   
   /** 
   * Sets the invariant direction of Translation 
   * @param iWAxis the new invariant translation direction
   */
   virtual void SetTranslationDirection( const CATMathDirection2D &iAxis);
  /** 
   * Gets the invariant direction of Translation 
   */
   virtual CATMathDirection2D GetTranslationDirection();
   
   /**
   * Sets the invariant point of PointRotation 
   * @param iPoint the new invariant rotation point
   */
   virtual void SetRotationPoint( const CATMathPoint2D &iPoint);
   /**
   * Gets the invariant point of PointRotation 
   */
   virtual CATMathPoint2D GetRotationPoint();
   
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
   * We switch from NoVisibilityRep to VisibilityRep.
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
   CAT2DBagRep *_HandleRep;

   /**
   * Representation of the handle when flag SwitchSonVis is activated and when the handle is not preactivated.
   * NB : _NoVisibilityRep is added in the children list of _VisibilityRep.
   */
   CAT2DRep    *_NoVisibilityRep; 

   /**
   * Representation of the handle when flag SwitchSonVis is activated and when the handle is preactivated.
   */
   CAT2DBagRep *_VisibilityRep;  
   
   
   
   /**
   * Representations associated to the manipulator's style :
   */
   CAT2DBagRep *_StyleRep[2];
   
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
   
   
   virtual CAT2DRep *BuildDefaultRepStyle(CAT2DManipulator::ManipulationStyle iManipStyle);
   int _fatherRepCreated;
};


#endif

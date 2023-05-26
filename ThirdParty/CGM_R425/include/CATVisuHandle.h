#ifndef CATVisuHandle_H
#define CATVisuHandle_H

//******************************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1998
//******************************************************************************
//  Abstract:
//  ---------
//    Visual representation allowing to manipulate an object  
//******************************************************************************
//  Usage:
//  ------
//    CAT3DHandle CAT2DHandle  inherit from CATVisuHandle
//******************************************************************************
//  Inheritance:
//  ------------
//                  CATVisuHandle (FW Visualisation)
//                        CATCommand (SYSTEM Framework).
//******************************************************************************
//  Main Methods:
//
// void AddChild
// void RemoveChild
//******************************************************************************

#include "CATVisController.h"
#include "CATCommand.h"
#include "list.h"
#include "CATMathDef.h"

#define NbStyle 2; // number of styles for the manipulator
// voir RangeStyle

class CATRep;
class CATManipulator;
/**
* A CATVisuHandle allows object manipulation. 
* It has its own representation and its own manipulator.
*/
// CATVisuHandle now implements CATIModelEvents through its extension CATExtIMEventsForVHandle.
// See new flags all the way down.

class ExportedByCATVisController CATVisuHandle : public CATCommand
{
   
   CATDeclareClass; // pour IsKindOF
   
   
public:
   
   
   /* Constructor 
    * 
    * @param Father : CATCommand father
    * @param iName : Name of the VisuHandle
    */
   CATVisuHandle(CATCommand *Father, const CATString &iName);
   // Destructors
   virtual ~CATVisuHandle(void);

   virtual HRESULT LogicalDeath();
   virtual void CleanRep();
   CATManipulator * GetManipulator() const;

protected:
   
   /** 
    * @nodoc
    * Manipulator associated to the handle.
    */
   CATManipulator *_Manipulator;
   
   /** 
    * @nodoc
    * Handle children list.
    */
   list<CATVisuHandle> _ChildrenHandles;
   
   /**
    * Flag for automatic update of the handle Rep. Used in InterpretNotification.
    * Default Value 1
    */
    
   int _AutoUpdateRep;
   
   /**
    * Flag for automatic update of the handle matrix position. Used in SetPosition.
    * Default Value 1
    */
   
   int _AutoUpdatePos;
   
   /**
    * Updates representations by sending a visu event to CATVisManager.
    * This flag allows the VisuHandle to implement CATIModelEvents.
    */
  
   int _AutoUpdateRepVisuEvent;
   
   
   /**
    * Adds one handle to the children handles list.
    * <br>
    * The child transmits Visu events to its father.
    * @param iHandle The handle to add.
    */  
   virtual void AddChild(CATVisuHandle *iHandle);
   /**
   * Removes one handle to the children handles list.
   * <br>
   * The child stops transmiting Visu events to its father.
   * @param iHandle The handle to remove
   */  
   virtual void RemoveChild(CATVisuHandle *iHandle);
   
   
private:
public:
   
  /*
   * Different types of manipulation for the handle
   * @param PrimaryStyle 
   *     First manipulation style
   * @param SecondaryStyle
   *     Second manipulation style
   */
   enum RangeStyle {
         PrimaryStyle,    // First manipulation style
         SecondaryStyle }; // Second manipulation style
  /*
   * Behaviors of the CATVisuHandle. Used in CAT2DVisuHandle and CAT3DVisuHandle
   * @param NoUpdate 
   *     the handle does not move
   * @param UpdateRep 
   *     automatic Update of the handle
   * @param UpdatePos 
   *     Update of the handle position using the method SetPosition
   * @param UpdateRepPos 
   *     Update of the handle and its position
   * @param UpdateRepVisuEvent 
   *     Flag that allows the implementation of CATIModelEvents
   *     Also activates UpdateRepPos.
   * @param SwitchSonVis 
   *     allows the CAT3DVisuHandle to have a switchable visibility.
   *     Also activates UpdateRepVisuEvent.
   */  
   enum UpdateFlag {
            NoUpdate,  // pas d'update Rep et Pos
            UpdateRep, // update automatique de Rep au manipulate
            UpdatePos, // update position au moment du setPosition
            UpdateRepPos, // update Rep et Pos 
            UpdateRepVisuEvent, // update Rep using an event sent to the VisManager
            SwitchSonVis, //to allow a VisuHandle of type "son" to have switchable visibility
            NoUpdateRepVisuEvent, //the rep will not be updated through the method InterpretNotification
            SwNoUpdateRepVisuEvent};//same as before but with switchable visibility.
};


#endif

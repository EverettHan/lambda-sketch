#ifndef CATShowNotif_h
#define CATShowNotif_h


// COPYRIGHT DASSAULT SYSTEMES 1999


/**
  * Class representing a visualization event aimed at warning anybody else than the VisManager that
  * one component is actually put in noshow or show state.
  *
  * For instance the TreeGraph of the CATIAV5 version should listen to this visualization event to 
  * dim the node of the component when it is put into noshow state.
  *
  ******************************************************************************
  * Inheritance
  * ------------
  *            - CATShowNotif
  *               - CATNotification
  *
  ******************************************************************************
  * Comment
  * ---------
  *             This notification directly derived from CATNotification in order not to be treated by the VisManager
  *              as every other visualization evetn. Because this event is aimed at warning components different from 
  *              the VisManager, and because VisManager processes only real visualization event deriving from 
  *              CATModelNotification,  deriving directly from CATNotification (the basic system event) is a tricky
  *              way to tell to VisManager not to take it into account.
  *
  */


// Visualization FrameWork
#include "CATVisItf.h"
#include "CATNotification.h"
#include "CATShowAttribut.h"


class ExportedByCATVisItf CATShowNotif : public CATNotification
{
   /** @nodoc */
  CATDeclareClass;

  public:
     /** Constructs the class from a component and a show attribuyt */
    CATShowNotif(CATBaseUnknown *iObject, CATShowAttribut iShowAttr);
    ~CATShowNotif();
  
    /** Returns the show/noshow attribut of the component */
    CATShowAttribut GetShowAttribut() const;

    /** Returns a pointer to clone of the current  notification*/
    CATBaseUnknown* GetObject ();

  private:
     /** Show/Noshow state */
     CATShowAttribut _ShowAttr;

     /** a pointer to the object */
     CATBaseUnknown * _pObject;
};

#endif

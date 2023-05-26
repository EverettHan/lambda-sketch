#ifndef CATModify_h
#define CATModify_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATModelEntityNotification.h"
#include "CATBaseUnknown.h"

/**
  * Class representing basic type of visualization event concerning any type of modification of one object.
  * 
  * <b>Role</b>: this event describes the object you want to modify and also the way you want it to processed thru
  * the IID of a given interface. When one object is modified and needs to regenerate its graphical representations, it just
  * has to send a @href CATModify event to warn all its visualized graphical representations. And the visualization 
  * architecture provides two ways to process any @href CATModify event:
  * <ul>
  *  <li>A default one whose result is that all its graphical representations will be destroyed and then rebuilt thru 
  * the @href CATIVisu#BuildRep method of the visualization extensions of the object </li>
  *  <li>A customized one: before any processing of a CATModify event, each visualization extension of the object is first called  thru the @href CATExtIVisu#ModifyRep method. If no processing is done by this method, the default processing is performed. Then you can take hand within the @href CATExtIVisu#ModifyRep method of your visualization extension to process the object
  * the way you want and take advantage of the IID enclosed in the @href CATModify event to distinguish your specific event from the other @href CATModify events. </li>
  * </ul>
  * @see CATExtIVisu, CATIVisu 
  */

class ExportedByCATVisItf CATModify : public CATModelEntityNotification
{
   /** @nodoc */
  CATDeclareClass;

  public:
     /**
       * Constructs the class from a pointer.
       * @param iModelId
       *    the pointer.
       * @param iRepWillDie
       * <br><b> Legal Values </b> : 
       * <ol>
       * <li> 0 : if no graphical representation will be destroyed </li>
       * <li> 1 : if one or several graphical representations will be destroyed when the current event is processed</li>
       *</ol>
       *    
       */
    CATModify(void *iModelId, int iRepWillDie = 1 );


    /**
       * Constructs the class from a pointer to one object and an IID.
       * 
       * @param iObject
       *   the pointer to one object.
       *
       * @param iInterfaceName
       *   the interface iid.
       *
       * @param iRepWillDie
       * an integer using to optimize the processing of this event if no graphical representations are to be destroyed.
       * Default value is 1.
       * <br><b> Legal Values </b> : 
       * <ol>
       * <li> 0 : if no graphical representation will be destroyed </li>
       * <li> 1 : if one or several graphical representations will be destroyed when the current event is processed</li>
       *</ol>
       *
       */
    CATModify(CATBaseUnknown *iObject, const IID &iInterfaceName=CATBaseUnknown::ClassId(),
                        int iRepWillDie = 1 );


    virtual ~CATModify();
    
    /**
      * Returns the interface IID.
      */
    const IID &GetInterfaceIID() const;

    /**
      * Returns an integer used to optimize the processing of this event
      * if no graphical representations are to be destroyed.
      * <br><b> Legal Values </b> : 
      * <ol>
      * <li> 0 : if no graphical representation will be destroyed </li>
      * <li> 1 : if one or several graphical representations will be destroyed when the current event is processed</li>   
      *</ol>
      */
    int IsRepWillDie () const;

   /** 
     * Returns a pointer to a new CATModify event which is the clone of the current one.
     */
    virtual CATModelNotification* Clone ();

  protected:
     /** interface IID. */
    const IID &_interfaceIID;

    /** integer  used to optimize the processing of this event if no graphical representations are to be destroyed.*/
    int        _repWillDie;
};

#endif

#ifndef CATSelector_h
#define CATSelector_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CATVisController.h"
#include "CATManipulator.h"

class CATRep;
class CATNotification;
class CATGraphicPathElement;
class CATPathElement;


/**
*
* Class to select representations.
*
* This class is to be able to interract on a representation of a model
* <br>It main purpose is to be able to answer to the @href CATManipulator#SendCommandSpecificObject
* after an user action (Select/Pick/Drag...) and especially to decode a
* <br>@href CATPathElement that is in the object model equivalent to the selected
* <br>representation.
*
**/
class ExportedByCATVisController CATSelector : public CATManipulator
{
    /** @nodoc  */
    CATDeclareClass;
  
public:
    
    /**
    *
    * Default constructor.
    * @param iFather
    *   a pointer to the father command of the manipulator
    * @param iName
    *   a name for the manipulator
    * @param iRepresentation
    *   a pointer to the manipulated representation 
    **/
    CATSelector( CATCommand *iFather, const CATString &iName, CATRep *iRepresentation);
  
    /**
    * @nodoc
    */
    virtual ~CATSelector();
    

    /**
    * @nodoc
    * Gets a desired object provided a notification.
    *
    * @param iUuid
    *  The desired object, given by the ClassName method.
    *  In addition to @href CATManipulator, this class can give a CATPathElement object.
    *  <br>This mean that asking a CATPathElement launch the mecanism of decode that
    *  <br>will return the equivalent for the model of the selected representation.
    *
    * @param iGraphicNotification
    *  The notification which caused the need for that object
    *  Usually, you ask a command for more information when that
    *  command calls you back. Use pass the notification you receive
    *  in your callback.
    *
    * @return
    *  An object of the type given iUuid parameter. 
    * <br>You have to release this object by yourself.
    */
//    virtual void * SendCommandSpecificObject(const char *iUuid, CATNotification *iGraphicNotification);

    /**
    * @nodoc
    */
    void SemanticMove (int delta);

    /**
    * @nodoc
    */
    void GotoSemanticPosition (CATPathElement& pathElement);

	/**
	* @nodoc
	*/
	  void GetSemanticData(int* position, int* size);

};

#endif

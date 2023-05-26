#ifndef CATModelEntityNotification_h
#define CATModelEntityNotification_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATModelNotification.h"
#include "CATSysAllocator.h"

class CATBaseUnknown;

/**
 * Class representing basic visualization events concerning one object.
 * 
 * <b>Role</b>: providing a visualization event basic class aimed at defining events sent by objects. Whenever objects' change happens, 
 * objects send a specialized visualization event @href CATModelNotification to warn the "<tt>Visualization world</tt>". 
 * That means the way provided in CATIAV5 to update the graphical representations of one object is to send
 * a visualization event, which is defined by the @href CATModelNotification class.
 * <p>
 * That 's the reason why when one object's color is changed or when its shape is modified , it sends a visu event.
 *  Refer to the @href CATIModelEvents interface to have details about the management of the visualization events 
 *  and their mechanism.
 * <p>
 * Examples of visualization  events are @href CATCreate, @href CATDelete and @href CATModify.
 * 
 */
class ExportedByCATVisItf CATModelEntityNotification : public CATModelNotification
{
    /** @nodoc */
  CATDeclareClass;

  
  public:
	  
	  /** @nodoc */
	  void *operator new(size_t iSize,void *iAllocType=NULL,
		  void *iAddr=NULL,int iReservedSize=0);
	  
	  /** @nodoc */
	  void operator delete(void *iAddr);
	  
#ifdef _WINDOWS_SOURCE
	  /** @nodoc */
	  void operator delete(void *iAddr,void *iAllocType,
		  void *iRefAddr,int iReservedSize);
#endif
	  
    /**
      * Constructs the class from a generic pointer to one object.
      * @param iModelId
      *    the pointer.
      */
    CATModelEntityNotification(void *iModelId);

    /**
      * Constructs the class from a pointer to one object.
      * @param iObject
      *   a pointer to the object.
      */
    CATModelEntityNotification(CATBaseUnknown *iObject);


    virtual ~CATModelEntityNotification();

    /** 
      * Returns a pointer to a new CATModelEntityNotification event which is the
      *  clone of the current one.
      */
    virtual CATModelNotification* Clone ();


    /**
      * Returns a generic pointer to the enclosed object.
      */
    void * GetModelId() const;


    /**
      * Returns a pointer to the enclosed object.
      */
    CATBaseUnknown * GetObject() const;


  protected:

    /**
      * Pointer to the enclosed object.
      */
    CATBaseUnknown * _object;
};

#endif

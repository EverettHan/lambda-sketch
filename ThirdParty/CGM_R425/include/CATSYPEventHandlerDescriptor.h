#ifndef CATSYPEventHandlerDescriptor_H
#define CATSYPEventHandlerDescriptor_H

#include <CATBaseUnknown.h>
#include <IntroInfra.h>
#include <CATUnicodeString.h>
#include <CATSYPDescriptorBase.h>

class CATSYPEventHandler;
class CATMetaClass;

/**
 * Factory object to build/retrieve an event handler for a given
 * object.
 *
 * An object of this type must be AddRef when you get a copy and
 * Release as soon as you doesn't need it anymore in order to be shared
 * among all the CATSYPEventHandlerDescriptor that describes the same
 * event handler.
 *
 * This class acts as an interface. So to use it, you need to derive
 * it and then implement the GetEventHandler member function.
 */
class ExportedByIntroInfra CATSYPEventHandlerGetter : public CATBaseUnknown
{
  CATDeclareClass;

public:
  /** Default constructor */
  CATSYPEventHandlerGetter();

  /** Destructor */
  virtual ~CATSYPEventHandlerGetter();

  /**
   * Returns the event handler for @a i_pObj object.
   *
   * This function may return the same instance of @ref
   * CATSYPEventHandler or a new one each time it is called for the
   * same @a i_pObj. Nevertheless the returned object should always
   * have the same behavior. For example if the returned handler calls
   * a member function, it should always call the same function even
   * if a different handler instance is returned each time this
   * function is called.
   *
   * @param i_pObj a pointer on the object for which the handler is
   * requested. Can't be @c NULL.
   *
   * @return [IUnknown#Release] return an instance of event
   * handler. @c AddRef has been called on the returned pointer. Note
   * that a new instance of event handler may be returned each time
   * the function is called. Return @c NULL in case of error.
   */
  virtual CATSYPEventHandler * GetEventHandler(CATBaseUnknown * i_pObj) = 0;

private:
  // Copy constructor and assignement operator are disabled
  CATSYPEventHandlerGetter(const CATSYPEventHandlerGetter & i_toCopy);
  CATSYPEventHandlerGetter & operator= (const CATSYPEventHandlerGetter & i_toCopy);
};

/** @copydoc CATSYPEventHandlerGetter#GetEventHandler */
typedef CATSYPEventHandler * (* CATSYPGetEventHandlerFunc)(CATBaseUnknown *i_pObj);

/**
 * Implements @ref CATSYPEventHandlerGetter interface by using a
 * pointer on a regular/static function.
 *
 * This class is mainly used by the introspection mechanism as the standard
 * way to get an event handler.
 */
class ExportedByIntroInfra CATSYPStaticEventHandlerGetter : public CATSYPEventHandlerGetter
{
  CATDeclareClass;
public:
  /**
   * Construct a CATSYPStaticEventHandlerGetter object by filling it
   * with a pointer on a function that is able to perform the get
   * operation.
   *
   * @param i_pHandlerGetterFunc a pointer on a function that is able
   * to perform the get operation. Can't be @c NULL.
   */
  CATSYPStaticEventHandlerGetter(CATSYPEventHandler * (* i_pHandlerGetterFunc)(CATBaseUnknown *));

  /** Destructor */
  virtual ~CATSYPStaticEventHandlerGetter();

  /** @copydoc CATSYPEventHandlerGetter#GetEventHandler */
  virtual CATSYPEventHandler * GetEventHandler(CATBaseUnknown * i_pObj);

private:
  // Copy constructor and assignement operator are disabled
  CATSYPStaticEventHandlerGetter(const CATSYPStaticEventHandlerGetter & i_toCopy);
  CATSYPStaticEventHandlerGetter & operator= (const CATSYPStaticEventHandlerGetter & i_toCopy);

  /**
   * A pointer on a function that is able to perform the get operation.
   * This function takes in parameter a pointer on the object on which the get
   * operation must be performed and must return the event handler get.
   * It must call @c AddRef on its returned value.
   */
  CATSYPEventHandler * (* _pHandlerGetterFunc)(CATBaseUnknown *);
};


/**
 * Data class containing the description of an event.
 * <b>Role</b>: Used by introspection mechanisms. 
 * Recovered from a CATISYPIntrospectable.
 */
class ExportedByIntroInfra CATSYPEventHandlerDescriptor : public CATSYPDescriptorBase
{
public:
  /** Constructor*/
  CATSYPEventHandlerDescriptor();

  /**
   * Constructor
   *
   * @param i_name name of the event handler.
   *
   * @param i_pArgsType the type of arguments (i.e. the specialization
   * of @ref CATSYPEventArgs) that can be handled by the
   * handler. Can't be @c NULL.
   * 
   * @param i_pEventHandlerObj an object that can instantiate an
   * event handler for a given object. Can't be @c NULL.
   * You do not have to Release this pointer after giving it to CATSYPEventHandlerDescriptor
   * since CATSYPEventHandlerDescriptor takes the ownership of it.
   */
  CATSYPEventHandlerDescriptor(const CATUnicodeString& i_name, 
                               CATMetaClass *i_pArgsType,
                               CATSYPEventHandlerGetter *i_pEventHandlerObj,
                               const CATUnicodeString& i_className);

  /**
   * Copy Constructor
   * @param i_toCopy the CATSYPEventHandlerDescriptor to copy
   */
  CATSYPEventHandlerDescriptor(const CATSYPEventHandlerDescriptor & i_toCopy);

  /**
   * Destructor
   */
  ~CATSYPEventHandlerDescriptor();

  /** Operator */
  CATSYPEventHandlerDescriptor& operator=(const CATSYPEventHandlerDescriptor & i_toCopy);

  /**
   * @return the name of the event handler.
   */
  const CATUnicodeString& GetName () const;

  /**
   * Get the type of arguments (i.e. the specialization of 
   * @ref CATSYPEventArgs) that can be handled by the handler.
   *
   * @return the type of the arguments. Can be @c NULL if the object
   * was built with the default constructor. If not @c NULL it is a
   * specialization of @ref CATSYPEventArgs.
   *
   * @see CATSYPEventArgs
   */
  CATMetaClass *GetArgsType() const;

  /**
   * Get the event handler factory object.
   *
   * @return the event handler factory. @c NULL if this object was
   * built with the default constructor (i.e. when it does not
   * represent a valid value) or if a severe error occured.
   *
   * @see CATSYPEventHandlerGetter
   */
  CATSYPEventHandlerGetter * GetEventHandlerObject() const;
private:
  CATUnicodeString _name;
  /** the type of arguments that can be handled by the handler */
  CATMetaClass *_pArgsType;
  /** factory that can return an event handler for an object */
  CATSYPEventHandlerGetter * _pEventHandlerObj;
};

#endif

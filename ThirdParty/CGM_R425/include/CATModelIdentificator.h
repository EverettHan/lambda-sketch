#ifndef CATModelIdentificator_H
#define CATModelIdentificator_H
//Ia64+
#include "CATDataType.h"
//Ia64-

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


/**
  * Class to create a model identifier.
  * <b>Role</b>:
  * This class is dedicated to be the only link between the graphical representations and 
  * their corresponding objects. Refer to @href CATIVisu to understand how one object can be visualized.
  * This identifier is designed to make graphical representations (that is the "visualization world") independent
  * from their object  (that is the "applicative world") and make the link consistent. 
  * <p>
  * The identifier can be seen either as an integer, or as a pointer to one object, or as a generic pointer .
  * <p>
  * Such an identifier is set on each graphical representation built from the @href CATIVisu#BuildRep() method .
  * The enclosed identifier refers to the object that implements a 
  * specialized visualization interface so as to find out the "model" associated with the graphical representation.
  * 
  *
  * @see CATIVisu
  */

#include "SGInfra.h"
#include "CATBaseUnknown.h"


class ExportedBySGInfra CATModelIdentificator : public CATBaseUnknown 
{
  /** @nodoc */
  CATDeclareClass;

  /** @nodoc */
  friend class CATMarshallableModelIdentificator;

  public:

    /**
      * Default constructor.
      */
       CATModelIdentificator();

     /**
       * Constructs an identifier from an integer.
       * @param iV
       *    the number.
       */
//Ia64C         CATModelIdentificator(int iV );
//Ia64+
        CATModelIdentificator(CATINTPTR iV );
//Ia64-

     /**
       * Constructs an identifier from a pointer.
       * @param iP
       *    the pointer.
       */
       CATModelIdentificator(void *iP);

    /**
      * Constructs an identifier from a pointer to one object.
      * @param iObj
      *    the pointer to one object.
      */
      CATModelIdentificator(CATBaseUnknown *iObj);

    /**
      * Copy constructor.
      * @param iIdentifier
      *   the model identifier to clone.
      */
      CATModelIdentificator(const CATModelIdentificator &iIdentifier);


  ~CATModelIdentificator();
   
   /**
     * Returns the identifier as a number.
     */
//Ia64C      int  GetIntId( ) const ;
//Ia64+
     CATINTPTR  GetIntId( ) const ;
//Ia64-


   /**
     * Returns the identifier as a pointer.
     */
     void * GetVoidId() const;


   /**
     * Returns the identifier as a pointer to one object.
     */
    CATBaseUnknown * GetId() const;

   

   /**
     * Sets the identifier from a number.
     * @param iId
     * the number.
     */
//Ia64C      void SetModelId(int iId);
//Ia64+
     void SetModelId(CATINTPTR iId);
//Ia64-

   /**
     * Sets the identifier from a pointer.
     * @param iId
     * the pointer.
     */
    void SetModelId(void *iId);
  
   /**
     * Sets the identifier from a pointer to one object.
     * @param iId
     * the pointer to one object.
     */
     void SetModelId(CATBaseUnknown *iId); 

  protected:

   /** @nodoc */ 
   union 
  {
//Ia64C      int val;
//Ia64+
     CATINTPTR val;
//Ia64-
     void *pval;
     CATBaseUnknown *object;
   } _Identificator;

};
#endif 










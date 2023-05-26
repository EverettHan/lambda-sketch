// COPYRIGHT Dassault Systemes 2008

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#ifndef CATAfrCommandHeaderArgsIterator_H
#define CATAfrCommandHeaderArgsIterator_H

#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATAfrCommandHeaderArg.h"

class CATAfrCommandHeaderArgs;

/**
* Class representing an iterator for a command header argument list.
* <br>See @href CATAfrCommandHeaderArgs class.
*/

class ExportedByCATAfrFoundation CATAfrCommandHeaderArgsIterator: public CATBaseUnknown
{
  CATDeclareClass;

  friend class CATAfrCommandHeaderArgs;

  public:

    /**
     * Please use only CATAfrCommandHeaderArgs::CreateIterator to create and Release to delete.
     */
    virtual ~CATAfrCommandHeaderArgsIterator ();

    /**
     * Get the first element in the list.
     * <br>
     * @return 
     *  The argument to set.
     */
    CATAfrCommandHeaderArg * First ();

    /**
     * Get the next element in the list.
     * <br>
     * @return 
     *  The argument to set.
     */
    CATAfrCommandHeaderArg * Next();

    /**
     * Get the current element in the list.
     * <br>
     * The current element is the element returned by the last call to First or Next method.
     * @return 
     *  The argument to set.
     */
    CATAfrCommandHeaderArg * Current();

    /**
     * Get the first element in the list (obsolete).
     * <br>
     *  Use CATAfrCommandHeaderArg * First () instead.
     */
    HRESULT First (CATAfrCommandHeaderArg & oFirst);

    /**
     * Get the next element in the list (obsolete).
     * <br>
     *  Use CATAfrCommandHeaderArg * Next () instead.
     */
    HRESULT Next(CATAfrCommandHeaderArg & oNext);

    /**
     * Get the current element in the list (obsolete).
     * <br>
     *  Use CATAfrCommandHeaderArg * Current () instead.
     */
    HRESULT Current(CATAfrCommandHeaderArg & oNext);

    /**
     * Remove the current element in the list.
     * <br>Returns E_ACCESSDENIED if the list is unusable.
     * <br>Returns E_FAIL if the pointer is not well positionned.
     * <br>Special notice on removal: if several iterators concurrently scan the same argument list,
     * removing an argument in one iterator might impact the scan in the others.
     * Next, Remove and Set methods will have to check the current element still exists before doing their job
     * and return an error if it does not exist. As soon as an iterator removes an argument,
     * all the other existing iterators that reference this argument as the current element become unusable
     * until you call its First method again.
     * @param 
     *  The argument to remove.
     */
    HRESULT Remove();

    /**
     * Change the value of the current element.
     * <br>Returns E_ACCESSDENIED if the list is unusable.
     * <br>Returns E_INVALIDARG if the new value type is not compatible with the old value type.
     * <br>Returns E_FAIL if the pointer is not well positionned.
     * @param 
     *  The value.
     */
    HRESULT Set (CATBaseUnknown_var ihValue);


  private:

    // used only by CATAfrCommandHeaderArgs::CreateIterator
    CATAfrCommandHeaderArgsIterator (CATAfrCommandHeaderArgs * piArgs);

    // Not implemented
    CATAfrCommandHeaderArgsIterator ();
    CATAfrCommandHeaderArgsIterator (CATAfrCommandHeaderArgsIterator &);
    CATAfrCommandHeaderArgsIterator& operator=(CATAfrCommandHeaderArgsIterator&);

    CATBoolean IsUsable();

    CATAfrCommandHeaderArgs * _pArgs;
    int _currentIndex;
    CATAfrCommandHeaderArg * _currentArg;
};

#endif

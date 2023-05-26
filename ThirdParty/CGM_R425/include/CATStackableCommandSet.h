#ifndef __CATStackableCommandSet_h
#define __CATStackableCommandSet_h

// COPYRIGHT DASSAULT SYSTEMES 2000
/**
* @CAA2Level L1
* @CAA2Usage U1
*/

#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATString.h"
#include "CATAfrFoundation.h"

class CATFrmEditor;
class CATSortedArrayPV;

/**
* Class to store a list of command header instance name.
*/
class ExportedByCATAfrFoundation CATStackableCommandSet: public CATBaseUnknown {

  CATDeclareClass;

public:

  /**
  * Constructs a default list of command header name.
  * <br><b>Role</b>:This method constructs a list with some command header 
  * names. 
  */
  CATStackableCommandSet ();

  /**
  * Constructs a list of command header name from an other one.
  * <br><b>Role</b>: This method duplicates a list of command header name.
  * @param iFrom
  *    The list to duplicate
  */
  CATStackableCommandSet (CATStackableCommandSet * iFrom);
	
  virtual ~CATStackableCommandSet ();

  /**
  * Adds a set of command header name.
  * <br><b>Role</b>: Each name of the input set is added to the list thanks to the
  * @href #AddCommand method. It means that there is no duplicate element in the
  * resulting list.
  * @param iSet
  *  The list to merge.
  * @return 
  *   always TRUE
  */
  CATBoolean AddSet        (CATStackableCommandSet & iSet);

  /**
  * Adds a name to the list.
  * @param iCommandHdrName
  *    The name of the command header to add. 
  * @return 
  *    If <tt>TRUE</tt> the name has been added in the list, otherwise <tt>FALSE</tt>
  */
  CATBoolean AddCommand    (const CATString & iCommandHdrName);

  /**
  * Adds a name to the list.
  * @param iCommandHdrName
  *    The name of the command header to add. 
  * @return 
  *   If <tt>TRUE</tt> the name has been added in the list, <tt>FALSE</tt> otherwise.
  */
  CATBoolean AddCommand    (const char * iCommandHdrName);

  /**
  * Removes a name from the list.
  * @param iCommandHdrName
  *    The name of the command header to remove. 
  * @return 
  *  If <tt>TRUE</tt> the name has been removed from the list, <tt>FALSE</tt> otherwise.
  */
  CATBoolean RemoveCommand (const CATString & iCommandHdrName);

  /**
  * Removes a name from the list.
  * @param iCommandHdrName
  *    The name of the command header to remove. 
  * @return 
  *  If <tt>TRUE</tt> the name has been removed from the list, <tt>FALSE</tt> otherwise.
  */

  CATBoolean RemoveCommand (const char * iCommandHdrName);
                      
  /**
  * @nodoc 
  */
  CATBoolean FirstCommand (unsigned long *);

  /**
  * @nodoc 
  */
  CATBoolean NextCommand  (CATString &, unsigned long *);

  /**
  * Checks if a name exists in the list.
  * @param iCommandHdrName
  *    The name of the command header to find out. 
  * @param oPos
  *    The position of iCommandHdrName in the list. The range of the value is
  *    between <tt>0</tt> and @href #GetSize -1 if the returned 
  *    value is <tt>TRUE</tt>, otherwise the value is not significant.
  * @return 
  *  If <tt>TRUE</tt> the name has been found in the list, <tt>FALSE</tt> otherwise.
  */
  CATBoolean Contains (const CATString & iCommandHdrName, unsigned long * oPos = 0);

  /**
  * Returns the count of name in the list. 
  * @return
  *   The size of the list. 
  */
  unsigned long GetSize () const;
	
protected:

  static int  CompareString (void *, void *);
  static void DestroyString (void *);

  CATSortedArrayPV  * _set;

};

#endif//__CATStackableCommandSet_h

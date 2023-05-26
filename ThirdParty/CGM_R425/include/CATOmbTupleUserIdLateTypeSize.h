#ifndef CATOmbTuple_UserId_LateType_Size_H
#define CATOmbTuple_UserId_LateType_Size_H

#include "CATUnicodeString.h"
#include "AC0XXLNK.h"


/**
* @level  Protected
* @usage   U1
*/


/**
* This class defines a tuple of UserId, LateType, Size. 
* <b>Role</b> 
* This class has been designed for containers. 
* <ul>
*   <li> UserId is the Unique id of the container of the document.
*   <li> LateType : late type used to instancaite the container.  
* </ul>
* 
*/

class ExportedByAC0XXLNK CATOmbTupleUserIdLateTypeSize
{

public:
  /**
  * Creates a new CATOmbTupleUserIdLateTypeSize.
  * @param <tt> CATUnicodeString </tt> iUserId
  *   the user id of the container. 
  * @param <tt> CATUnicodeString </tt> iLateType
  *   the late type of the container
  * @param <tt> int </tt> Size
  *   the size of the container  
  */
  CATOmbTupleUserIdLateTypeSize(const CATUnicodeString iUserId, const CATUnicodeString iLateType, const int Size);
  
  /**
  * Desctructor. 
  * frees the memory used by the instance of CATOmbTupleUserIdLateTypeSize object. 
  */
  ~CATOmbTupleUserIdLateTypeSize();

  /**
  * Gets the User Id stored in the tuple.
  * @return 
  *   The UserId
  */
  const CATUnicodeString& GetUserId() const;
  
  /**
  * Gets the LateType stored in the tuple.
  * @return 
  *   The LateType
  */
  const CATUnicodeString& GetLateType() const;
  
  /**
  * Gets the container size stored in the tuple.
  * @return 
  *   The container size
  */
  int GetContainerSize() const;
  
  /**
  * Operator == for CATOmbTupleUserIdLateTypeSize object. 
  */
  int operator==( const CATOmbTupleUserIdLateTypeSize&	iOpD ) const;
	
  /**
  * Operator != for CATOmbTupleUserIdLateTypeSize object. 
  */
  int operator!=( const CATOmbTupleUserIdLateTypeSize&	iOpD ) const;
	
private:
  CATUnicodeString _UserId;
  CATUnicodeString _LateType;
  int _Size;

};
#endif


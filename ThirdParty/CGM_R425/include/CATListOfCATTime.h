/**  
 *  @level  Protected  
 *  @usage  U1  
*/  
#ifndef        CATListOfCATTime_H  
#define        CATListOfCATTime_H  

#include  "CATTime.h"  

#include  "CATLISTV_Clean.h"    

#define  CATLISTV_Append  
#define  CATLISTV_RemoveAll  

#include  "CATLISTV_Declare.h"  

#include  "CATOMY.h"  
#undef  CATCOLLEC_ExportedBy  
#define  CATCOLLEC_ExportedBy  ExportedByCATOMY

/**  
 *  @collection  CATListValCATTime  
 *  Collection  class  for  system  class  <code>CATTime</code>.  
 *  <br>The  following  collection  class  methods  are  provided:  
 *  <ul>  
 *      <li><tt>Append</tt></li>  
 *      <li><tt>AppendList</tt></li>  
 *      <li><tt>Locate</tt></li>  
 *      <li><tt>RemoveAll</tt></li>  
 *      <li><tt>RemovePosition</tt></li>  
 *      <li><tt>RemoveValue</tt></li>  
 *  </ul>  
 *  <br>Refer  to  the  articles  dealing  with  collections  in  the  CAA  encyclopedia.  
 *  
 *  @see  CATTime  
*/  
CATLISTV_DECLARE(CATTime);  

typedef        class  CATLISTV(CATTime)                CATListOfCATTime  ; 
#endif  

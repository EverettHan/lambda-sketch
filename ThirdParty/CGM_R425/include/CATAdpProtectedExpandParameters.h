#ifndef CATAdpProtectedExpandParameters_H
#define CATAdpProtectedExpandParameters_H

/**
* @level Protected
* @usage U1  
*/

/**
  * Defines a mode of data completion for open services through a enum definition.
  *  <br><b>Role:</b>Description of the available modes defining the type of components which 
  *  will be retrieved through an open/expand request, together with the depth of expand query.
  *  Please refer to @href CATAdpProtectedCompletionParameters for option on gathered relations.
  *  <dt> <code><b>NoExpand</b></code>     <dd> The components are opened. No expand done. </dd>
  *  <dt> <code><b>OneLevelExpand</b></code>     <dd> The components are expanded on one level, and are opened 
  *    Please refer to @href CATAdpProtectedCompletionParameters for option on gathered relations.</dd>
  *  <dt> <code><b>FullExpand</b></code>   <dd> The components are expanded on their full depth, and opened 
  *    Please refer to @href CATAdpProtectedCompletionParameters for option on gathered relations.</dd>
  *     
  */

 namespace CATAdpProtectedExpandParameters { 
  enum ExpandMode 
  {
     NoExpand=0,
     OneLevelExpand=1,
     FullExpand=2
  };
 }

#endif

#ifndef CATAdpProtectedRepresentationMode_H
#define CATAdpProtectedRepresentationMode_H

/**
* @level Protected
* @usage U1  
*/

/**
  * Choose which representation to retrieve.
  *  <br><b>Role:</b>Description of the available modes defining the type of representations which 
  *  will be retrieved through an open/expand request.
  *  Please refer to @href CATAdpProtectedCompletionParameters for options/usage.
  *  <dt> <code><b>IntegrityReps</b></code>     <dd> Only mandatory representations are retrieved </dd>
  *  <dt> <code><b>Shape3DReps</b></code>       <dd> Mandatory and 3DShapes are retrieved  </dd>
  *  <dt> <code><b>AllReps</b></code>           <dd> Every representation is retrieved</dd>
  *     
  */
namespace CATAdpProtectedRepresentationMode
{
  enum RepresentationMode
  {
    IntegrityReps = 0,
    Shape3DReps = 1,
    AllReps = 2
  };
}

#endif

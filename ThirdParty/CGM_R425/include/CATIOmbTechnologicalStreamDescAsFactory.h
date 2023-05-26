// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIOmbTechnologicalStreamDescAsFactory.h
// Define the CATIOmbTechnologicalStreamDescAsFactory interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jul 2006  Creation: Code generated by the CAA wizard  ycm
//===================================================================

/**
* @level Protected
* @usage U3
*/

#ifndef CATIOmbTechnologicalStreamDescAsFactory_H
#define CATIOmbTechnologicalStreamDescAsFactory_H

#include "CATOmbTechnologicalRep.h"
#include "CATBaseUnknown.h"

class CATIOmbTechnologicalSet;
class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOmbTechnologicalRep IID IID_CATIOmbTechnologicalStreamDescAsFactory;
#else
extern "C" const IID IID_CATIOmbTechnologicalStreamDescAsFactory ;
#endif

//------------------------------------------------------------------
/**        
 *  Factory  for  creating  sets  within  a  Technological Stream Desc .    
 *  <b>Role</b>:  It  is  a  factory  for  Technological Stream Desc sets.  It  includes  a  method  to  instanciate  sets  implemented  using  standard  containers.<br>  
 */  


class ExportedByCATOmbTechnologicalRep CATIOmbTechnologicalStreamDescAsFactory: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**  
  *  Creates  a  new  set  implemented  using  standard  containers.  
  *  <br><b>Role:</b>This  method  creates  a  new  set  in  the  component  and  instanciates  the  associated  container.    
  *  The  role  and  type  of  the  set  are  text  labels  specified  by  the  application  creating  the  set  in  order  to    
  *  classify  its  sets  within  the  Technological Stream Desc.<br>  
  *  <br><i>NOTE:  The  Technological Stream Desc  data  will  be  loaded  if  not  already  in  memory.</i>  
  *  
  *  @param  iRole  
  *          The  role  of  the  set.  
  *  @param  iContainerType    
  *          The  type  of  the  container  to  be  created,  which  is  also  the  cluster  set  type  
  *  @param  iContainerSuperType  
  *          The  supertype  of  the  container  to  be  created.  
  *  @param  oSet  
  *          A  CATIOmbTechnologicalSet  interface  pointer  on  the  created  set.  
  *  
  *  @return  
  *      <br><b>Legal  values</b>:  
  *      <dl>  
  *          <dt>S_OK</dt>  
  *          <dd>The  set  and  the  associated  container  were  succesfully  created.</dd>  
  *          <dt>E_FAIL</dt>  
  *          <dd>The  set  could  not  be  created.  The  following  list  of  error  classes  can  be  associated  with  this  error.  Test  error  code  with  @href  TestClusterErrorCode</dd>  
  *      </dl>  
  *  @error  CATTestTechnologicalStreamDescError  Internal_ClusterDataRetrievalFailed    
  *                The  Technological Stream Desc   data  could  not  be  loaded  in  memory  
  *  @error  CATTestTechnologicalStreamDescError  Internal_ContainerCreationFailed  
  *                The  container  could  not  be  instanciated  for  the  given  type  and  supertype.  
  **/  


	  virtual HRESULT CreateContBasedSet( const  CATUnicodeString  &iRole,
													  const  CATUnicodeString  &iContainerType,
                                         const  CATUnicodeString  &iContainerSuperType,  
													  CATIOmbTechnologicalSet *  &oSet  )  =  0;  


  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif
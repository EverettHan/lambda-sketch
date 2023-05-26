#ifndef CATOmbDocCompositeData_h
#define CATOmbDocCompositeData_h

/**
 * @level Private
 * @usage U1
 */

/**
* Defines the kind of behavior followed by a slave document. 
* <b> Role:</b>
* The same implementation of a document may behave differently depending on the 
* type of its master. 
*@param 
* 	CATNotSlave : Internal value used only by OMB. 
*@param 
* 	CATSlaveCluster_MasterProduct : TP embedded in a CATProduct
*@param 
* 	CATSlaveProduct_MasterPart : Product embedded in a CATPart
*/
// enum CATOmbSlaveType
// {
//	CATNotSlave = 0,
//    CATSlaveCluster_MasterProduct =  1,
//     CATSlaveProduct_MasterPart =  2,
// };


/**
* Defines the persistence type of a Persistency Unit. 
* <b> Role </b>
* The persistency type is used by OMB to determine how the document should be streamed. 
* In a composite context, it is used to decide whether composite document should be streamed 
* in only one persistency unit. 
* It defines the way a user has decided to stream its data. 
*@param 
*	CATPLMPersistencyType : Defined for Enovia and VPM
*@param 
*	CATBlobPersistencyType : Defined for Enovia, VPM, File, and SMARTEAM.
*/
enum CATOmbPersistencyType
{
	CATPLMPersistencyType = 0,
	CATBlobPersistencyType = 1,	
};

#endif



#ifndef CATListOfCATSYPModelTag_h
#define CATListOfCATSYPModelTag_h
     
// COPYRIGHT DASSAULT SYSTEMES 2000
    
    
#include  <CATSYPModelTag.h>
    
#define	CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll
#define	CATLISTP_Locate
    
#include  <CATLISTP_Declare.h>
    
class CATSYPModelTag;
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATStyleProcessor
    
CATLISTP_DECLARE(CATSYPModelTag);
   
typedef CATLISTP(CATSYPModelTag) _ModelTagList;
#endif



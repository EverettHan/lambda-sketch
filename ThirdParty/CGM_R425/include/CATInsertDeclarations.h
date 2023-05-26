/**
 * @level Private 
 * @usage U1
 */

// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATInsertDeclarations_h
#define CATInsertDeclarations_h




// TYPES OF INSERTION
#define CATEmbed "CNEXT Embed"
#define OLEEmbed "OLE Embed"
#define OLELink "OLE Link"
//


//
//	Enum Required To Define The Type Of Content Object: Linked Or Embedded
//

enum CATContentObjectType	
{
	CATOleLinkedObject	 = 1,
	CATOleEmbeddedObject = 2,
	CATCNextEmbeddedObject = 3
};





#endif

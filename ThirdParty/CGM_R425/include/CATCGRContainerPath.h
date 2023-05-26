#ifndef CATCGRContainerPath_h
#define CATCGRContainerPath_h

#include "SGInfra.h"

#include "CATVizBaseIUnknown.h"
#include "CATListOfCATUnicodeString.h"

// COPYRIGHT DASSAULT SYSTEMES 2003

class CATCGRContainer;
class CATStorage;
class CATStreamer;

class ExportedBySGInfra CATCGRContainerPath : public CATVizBaseIUnknown
{
   CATDeclareClass_Deprec;

public :
   
   // Constructor
   CATCGRContainerPath();
   // Copy constructor
   CATCGRContainerPath(const CATCGRContainerPath & iPath);
   
   // Destructor
   virtual ~CATCGRContainerPath();
   
   void     AppendContainer(CATUnicodeString iName);
   void     InsertContainer(CATUnicodeString iName, int iIndex);
   void     RemoveContainer(CATUnicodeString iName);

   int      Size() const { return _path.Size(); }
   void     Stream(CATStorage * iStorage);
   static   CATCGRContainer * UnStream(CATStorage * iStorage, CATUnicodeString iName, int recursive = 1);
   static   CATCGRContainerPath ParsePath(const CATUnicodeString & iString);
   static   CATCGRContainerPath ParsePath(const CATUnicodeString & iString, const CATUnicodeString & iSeparator);


   void Dump();

   /**
	 * Subscripting operator.
    * @param iIndex
    * The index of the element.
    * @return 
    * The <tt>CATUnicodeString</tt> at index <tt>iIndex</tt>.
	 */
   const CATUnicodeString& operator[] ( int iIndex ) const;

protected :
   
   CATListOfCATUnicodeString  _path;

private :

};

#endif

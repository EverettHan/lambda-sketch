// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATFormat_H
#define CATFormat_H
/**
  * @CAA2Required                   
  */

////////////////////////////////////////////////////////////////////////////////////////
// Virtual Format definition to support Windows Interoperability
//
// For all recognized formats: A Format may match another Format
//
//                             A Format may provide system-dependent means
//                             to encode or decode data for exchange
//
//                             A Format must correspond to one and only one
//                             proprietary CATIA Object Interface for which
//                             data can be passed to or produced from the system
//
//                             A Format should be declared once in a
//                             session with the appropriate definition
//
// To avoid derivation of this class, chose one
// already derived for implementing your format.
// Pre-existing classes may implement some system-dependent formats
// e.g. Text, MetafilePict, ...
//
////////////////////////////////////////////////////////////////////////////////////////

/** Link format name. */
#define CATIA_LINK_FORMAT "CATLink"

/** Print format name. */
#define PRT_FORMAT "CATIA_PRT"

/** Draw format name. */
#define DRW_FORMAT "CATIA_DRW"

/** Geometry format name. */
#define GEOM_FORMAT "CATIA_GEOM"

/** Text format name. */
#define TEXT_FORMAT "Text"

/** Representation format name. */
#define REP_FORMAT  "Rep"

/** Metafile picture format name. */
#define METAFILEPIC_FORMAT "Metafile_Picture"

/** CGR format name. */
#define CGR_FORMAT  "CATIA_CGR"

/** Electrical format name. */
#define ELECTRICAL_FORMAT  "Electrical"

/** Electric format name. */
#define ELECTRIC_FORMAT  "Electric"
//
/** OLE embedded source format name. */
#define OLE_EMBED_FORMAT  "Embed Source"

/** OLE link source format name. */
#define OLE_LINK_FORMAT "Link Source"

#include "CATUnicodeString.h"

/**
  * Format identifier.
  */
typedef const char* IdFormat;

/** Compare formats. */
#define COMPARE_FORMAT(id1, id2) (id1 && id2 && strcmp(id1,id2)==0)

#include<stdlib.h>
#include<CATBaseUnknown.h>

class CATFormat;
class CATSystemFormat;

#include<CATFormats.h>


#include<CP0CLIP.h>

/**
* Interface to manage formats.
* <b> Role:</b> this interface is used during cut, copy and paste operations in order to
*               test formats needed for specific actions.
*/


class ExportedByCP0CLIP CATFormat 
{
 public:

   /** @nodoc */
   static const CATFormat* GetRegisteredFormat(IdFormat);

   /** @nodoc */
   virtual ~CATFormat();
   /**
	* Returns the name of a CATFormat object.
	*/
   virtual IdFormat Name()const;
   /**
	* Compares the name of the current CATFormat object with the value passed as input.
	* @param iFormatName 
	*        A declared format name.
	* @return 
	*        1 if the two format names are not equal.
	*   <br> 0 otherwise
	*/
   virtual int Match(IdFormat iFormatName)const;

   /** @nodoc */
   // log a new registered format, without communication capability
   CATFormat(IdFormat name);

   /** @nodoc */
   static const CATLISTP(CATFormat)& GetAllRegisteredFormats();
   /** @nodoc */
   CATSystemFormat* GetImpl() const;

   /** @nodoc */
   //for purify
   static int OpenSession();
   /** @nodoc */
   static int CloseSession();

   /** @nodoc */
   CATUnicodeString	GetFullName()	{return _fullName;}
   /** @nodoc */
   void	SetFullName(CATUnicodeString name);

 protected:
   int SetImpl(CATSystemFormat*);
   CATFormat(); // cannot create unmeaningfull format
 private:       //  unmeaningfull operation
   CATFormat(const CATFormat&);
   CATFormat& operator =(const CATFormat&);
   friend class CATSystemFormat;
 protected:  
   IdFormat _name;
   CATSystemFormat* _impl; // deleted at the end

 private :
	 CATUnicodeString	_fullName;
};


#endif


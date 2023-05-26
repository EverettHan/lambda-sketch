// Copyright Dassault Systemes 2000
#ifndef CATCkeStream_h
#define CATCkeStream_h
//////////////////////////////////////////////////////////////////////////
//
//
//	Cke Implementation Adapters
// 	declaration of output Streams
//
//
//////////////////////////////////////////////////////////////////////////
/*
$Log: CATCkeStream.h,v $
 * Revision 1.8  1997/06/20  07:38:06  frh
 * *** empty log message ***
 *
 * Revision 1.7  1997/06/06  14:24:45  frh
 * bug NT
 *
 * Revision 1.6  1997/05/15  15:52:46  frh
 * remplacement de endl par myendl pour eviter bug de surcharge HP
 *
 * Revision 1.6  1997/05/15  15:52:46  frh
 * remplacement de endl par myendl pour eviter bug de surcharge HP
 *
 * Revision 1.5  1997/04/28  08:07:39  frh
 * *** empty log message ***
 *
 * Revision 1.4  1997/04/25  09:17:45  frh
 * exported by NT
 *
 * Revision 1.3  1997/04/18  09:40:32  frh
 * special NT include strstrea.h au lieu de strstream.h
 *
 * Revision 1.2  1997/04/15  08:52:09  frh
 * *** empty log message ***
 *
 * Revision 1.1  1997/04/03  15:02:59  aal
 * Initial revision
 *
 * Revision 1.3  1997/02/03  16:39:02  obt
 * color
 *
 * Revision 1.2  1997/01/29  10:09:33  obt
 * revue_types_de_base
 *
 * Revision 1.1  1997/01/20  16:39:36  obt
 * portage_brackets_include
 *
*/
// module
#include "CATLifSpecs.h"
//#include "CATCkeContext.h"
#include "CATCke.h"
//#include "CATCkeDefs.h"
class CATCkeStream;

/*
//no include of strstream : jni/xpa11/02/01

#include <fstream.h>
#ifdef _WINDOWS_SOURCE
#include <strstrea.h>
#else
#include <strstream.h>
#endif
*/

/** @c++ansi fbq 2004-08-05.10:18:26 [Replace forward declaration by #include <iosfwd.h>] **/
#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ofstream;
class ostrstream;
class ostream;
#endif

//////////////////////////////////////////////////////////////////////////
//
//	base class
//
//////////////////////////////////////////////////////////////////////////
ExportedByCATLifSpecs CATCkeStream& myendl (CATCkeStream&); // std stream function
ExportedByCATLifSpecs CATCkeStream& Black  (CATCkeStream&); // std stream function
ExportedByCATLifSpecs CATCkeStream& Red    (CATCkeStream&); // std stream function
ExportedByCATLifSpecs CATCkeStream& Green  (CATCkeStream&); // std stream function
ExportedByCATLifSpecs CATCkeStream& Yellow (CATCkeStream&); // std stream function
ExportedByCATLifSpecs CATCkeStream& Purple (CATCkeStream&); // std stream function
ExportedByCATLifSpecs CATCkeStream& Pink   (CATCkeStream&); // std stream function
ExportedByCATLifSpecs CATCkeStream& Blue   (CATCkeStream&); // std stream function
ExportedByCATLifSpecs CATCkeStream& White  (CATCkeStream&); // std stream function

class ExportedByCATLifSpecs CATCkeStream : public CATCke
{

   friend CATCkeStream ExportedByCATLifSpecs & myendl (CATCkeStream&);

//   friend CATCkeStream ExportedByKnowledgeItfCPP & Black  (CATCkeStream&);
//   friend CATCkeStream ExportedByKnowledgeItfCPP & Red    (CATCkeStream&);
//   friend CATCkeStream ExportedByKnowledgeItfCPP & Green  (CATCkeStream&);
//   friend CATCkeStream ExportedByKnowledgeItfCPP & Yellow (CATCkeStream&);
//   friend CATCkeStream ExportedByKnowledgeItfCPP & Purple (CATCkeStream&);
//   friend CATCkeStream ExportedByKnowledgeItfCPP & Pink   (CATCkeStream&);
//   friend CATCkeStream ExportedByKnowledgeItfCPP & Blue   (CATCkeStream&);
//   friend CATCkeStream ExportedByKnowledgeItfCPP & White  (CATCkeStream&);

 public:

   CATCkeStream ();
   virtual ~CATCkeStream () ;

   int    Margin    () const { return _tab; }
   void   SetMargin (unsigned int n) { _tab = n; } 
   void   AddMargin (int);

//   virtual void     SetColor  (CATUnicodeString) ;
   virtual ostream& Stream () = 0;

   CATCkeStream& operator << (const char*);
   CATCkeStream& operator << (char);
   CATCkeStream& operator << (int);
   CATCkeStream& operator << (short);
   CATCkeStream& operator << (double);
#ifndef PLATEFORME_DS64
   CATCkeStream& operator << (CATLONG32);
#endif
   CATCkeStream& operator << (float); 
   CATCkeStream& operator << (CATCkeStream& (*f)(CATCkeStream&));
   CATCkeStream& operator << (CATCkeStream&);


 protected:

   void  Align ();
   virtual void Endl  () =0;

   static  CATUnicodeString  black;
   static  CATUnicodeString  red;
   static  CATUnicodeString  green;
   static  CATUnicodeString  yellow;
   static  CATUnicodeString  purple;
   static  CATUnicodeString  pink;
   static  CATUnicodeString  blue;
   static  CATUnicodeString  white;

   int     _tab;
   Boolean _nl ;

 private :

   CATCkeStream  (CATCkeStream&) {}
};

//////////////////////////////////////////////////////////////////////////
//
//	standard Formated Ouputs 
//
//////////////////////////////////////////////////////////////////////////

class ExportedByCATLifSpecs CATCkeOStream : public CATCkeStream
{

 public:

//   CATCkeOStream  (ostream& os = cout);
   CATCkeOStream  (ostream& os);
   CATCkeOStream  (); //jni-xpa11/02/01

   ~CATCkeOStream () {}

   ostream& Stream () { return *_ostream; }
//   void     SetColor (CATUnicodeString);

   
#include "CATCkeStreamDefs.h"

 protected :

   ostream*     _ostream;

   void     Endl   ();

 private :

   CATCkeOStream  (CATCkeOStream&) {}

};

//////////////////////////////////////////////////////////////////////////
//
//	standard Formated File Ouputs 
//
//////////////////////////////////////////////////////////////////////////

class ExportedByCATLifSpecs CATCkeOfStream : public CATCkeStream
{

 public:

//   CATCkeOfStream  (CATUnicodeString);
//   ~CATCkeOfStream ();

//   void     Flush  (); //jni/xpa { _ostream->flush(); }
   //jni/xpaostream& Stream () { return *_ostream; }
   ostream& Stream () { return *((ostream *)_ostream); }

 protected :

   ofstream* _ostream;

//   void     Endl   ();

 private :

//   CATCkeOfStream  (CATCkeOfStream&) {}
};


//////////////////////////////////////////////////////////////////////////
//
//	standard Formatted Buffer Ouputs 
//
//////////////////////////////////////////////////////////////////////////

class ExportedByCATLifSpecs CATCkeOstrStream : public CATCkeStream
{

 public:

   CATCkeOstrStream  (CATUnicodeString);
   CATCkeOstrStream  ();
   ~CATCkeOstrStream ();//jni/xpa { delete _ostream; }

   //jni/xpa ostream& Stream () { return *_ostream; } // pipo
	 ostream& Stream () { return *((ostream *)_ostream); } // pipo
   void     Flush  ();
   CATUnicodeString   Get    ();

 protected :

   ostrstream* _ostream;

   void     Endl   ();

 private :

   CATCkeOstrStream  (CATCkeOstrStream&) {}
};


#endif





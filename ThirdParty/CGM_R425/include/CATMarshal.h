/*===========================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                          */
/*===========================================================================*/
/*                                                                           */
/*  CATMarshal                                                               */
/*                                                                           */
/*  Usage Notes:                                                             */
/*  Marshalling interfaces                                                   */
/*===========================================================================*/
/*  Creation September 1996                                                  */
/*===========================================================================*/
#ifndef __CATMarshal
#define __CATMarshal
#include "JS0MRSHL.h"
#include "CATMacForIUnknown.h"
#include "CATBaseUnknown.h"
#include "CATCORBATypes.h"
#include "CATString.h"
#include "CATSerialize.h"
#include "CATMarshallableCorba.h"
#include "CATCreateCorba.h"
#include "CATUnicodeString.h"

//-----------------------------------------------------------------------------
//CATMarshal: Storing and Loading  Marshalling Object
//-----------------------------------------------------------------------------
enum CATMarshalMode {CATMarshalStore       = 1,
		     CATMarshalLoad        = 2,
		     CATMarshalBufferStore = 3,
		     CATMarshalBufferLoad  = 4,
		     CATMarshalStoreFlush  = 5};

enum CATMarshalBufferDeleteMode  {  CATMarshalBufferDeleteOFF=1,
				    CATMarshalBufferDeleteON =2 };

class ExportedByJS0MRSHL CATMarshal
{
   public:
      //Constructor and Destructor
      CATMarshal(CATMarshalMode);
      virtual ~CATMarshal();

      //Beginning an Ending Marshalling Methods
      int OpenArchiving  ( );
      int CloseArchiving ( );

      //Marshalling File and Buffer Access Methods
      int OpenArchiveBuffer (const char *, const char * );
      int OpenMemoryBuffer ( char * , int = -1 );
      int CloseArchiveBuffer ( );
      int FlushArchiving ( );
      int FlushBufferLength ( );
      int FlushMarshalBuffer ( char * , int = -1);
      int FlushDataLength ( );
      int FlushMarshalData ( char * , int  = -1 );
      int FlushHeaderLength ( );
      int FlushMarshalHeader ( char * , int = -1 );
      int FlushTailerLength ( );
      int FlushMarshalTailer ( char * , int = -1 );
      int CleanArchiving ( );

      //Buffer and File Descriptor Access Method
      int GetFileDesc();
      int GetBufferDesc();

      //Get Last Operation Status
      int GetLastStatus() ;

      //Get if conversion LittleEndian BigEndian needed
      int NeedConvert() ;
      //Set Machine Type;
      int SetMachineType(char);
      //Get Machine Type;
      int GetMachineType(char &);
      //Set Machine Type and marshal File version;
      int SetMarshalFile(char,int);
      //Get Machine Type and marshal File version;
      int GetMarshalFile(char &,int &);

      //Data Transfert to the Buffer Descriptor Methods
      CATMarshal& operator<<(const char *);
      CATMarshal& operator<<(const unsigned char *);
      CATMarshal& operator<<(const short *);
      CATMarshal& operator<<(const unsigned short *);
      CATMarshal& operator<<(const int *);
      CATMarshal& operator<<(const unsigned int *);
      CATMarshal& operator<<(const long *);
      CATMarshal& operator<<(const unsigned long *);
      CATMarshal& operator<<(const float *);
      CATMarshal& operator<<(const double *);
      CATMarshal& operator<<(const stroct *);
      CATMarshal& WriteMemoryBuffer(const char *, int);
      CATMarshal& Write(const char *, int);
      CATMarshal& Write(const unsigned char *, int);
      CATMarshal& Write(const short *, int);
      CATMarshal& Write(const unsigned short *, int);
      CATMarshal& Write(const int *, int);
      CATMarshal& Write(const unsigned int*, int);
      CATMarshal& Write(const long *, int);
      CATMarshal& Write(const unsigned long *, int);
      CATMarshal& Write(const float *, int);
      CATMarshal& Write(const double *, int);
      CATMarshal& Write(const stroct *, int);

      //Data Transfert from the Buffer Descriptor Methods
      CATMarshal& operator>>(char *);
      CATMarshal& operator>>(unsigned char *);
      CATMarshal& operator>>(short *);
      CATMarshal& operator>>(unsigned short *);
      CATMarshal& operator>>(int *);
      CATMarshal& operator>>(unsigned int *);
      CATMarshal& operator>>(long *);
      CATMarshal& operator>>(unsigned long *);
      CATMarshal& operator>>(float *);
      CATMarshal& operator>>(double *);
      CATMarshal& operator>>(stroct *);
      CATMarshal& Read(char *, int *);
      CATMarshal& Read(unsigned char *, int *);
      CATMarshal& Read(short *, int *);
      CATMarshal& Read(unsigned short *, int *);
      CATMarshal& Read(int *, int *);
      CATMarshal& Read(unsigned int *, int *);
      CATMarshal& Read(long *, int *);
      CATMarshal& Read(unsigned long *, int *);
      CATMarshal& Read(float *, int *);
      CATMarshal& Read(double *, int *);
      CATMarshal& Read(stroct *, int *);

      CATMarshal& ReadHeader();
      CATMarshal& ReadTailer();
      CATMarshal& InitHeader();
      int         ReadNextLength ();

   private:
      int _BufferDesc;
      int _FileDesc;
      CATMarshalMode _Mode;
      int _LastStatus;
};


  //--------------------------------------------------------------
  // acces au fichier de marhaling
  //--------------------------------------------------------------

 ExportedByJS0MRSHL int  OpenMarshalBuffer (const char *, const char * );
 ExportedByJS0MRSHL int  OpenMemoryBuffer ( char *, int = -1 );
 ExportedByJS0MRSHL int  CloseMarshalBuffer ( int );
 ExportedByJS0MRSHL int  CGRFileAnalyse (char*,int,int,int,int);


  //--------------------------------------------------------------
  // Collecte des datas
  //--------------------------------------------------------------

 ExportedByJS0MRSHL int ExportMarshalBuffer (int, const char *, int,
		CATMarshalBufferDeleteMode = CATMarshalBufferDeleteOFF);
 ExportedByJS0MRSHL int ExportMarshalBuffer (int, const unsigned char *, int);
 ExportedByJS0MRSHL int ExportMarshalBuffer (int, const short *, int);
 ExportedByJS0MRSHL int ExportMarshalBuffer (int, const unsigned short *, int);
 ExportedByJS0MRSHL int ExportMarshalBuffer (int , const int *, int);
 ExportedByJS0MRSHL int ExportMarshalBuffer (int , const unsigned int *, int);
 ExportedByJS0MRSHL int ExportMarshalBuffer (int , const long *, int);
 ExportedByJS0MRSHL int ExportMarshalBuffer (int , const unsigned long *, int);
 ExportedByJS0MRSHL int ExportMarshalBuffer (int , const float *   , int);
 ExportedByJS0MRSHL int ExportMarshalBuffer (int , const double *  , int);
 ExportedByJS0MRSHL int ExportMarshalBuffer (int , const stroct *  , int);

  //--------------------------------------------------------------
  // Recuperation des data
  //--------------------------------------------------------------

 ExportedByJS0MRSHL int ImportMarshalBuffer (int , int *, char *, int *);
 ExportedByJS0MRSHL int ImportMarshalBuffer (int , int *,unsigned char *,int *);
 ExportedByJS0MRSHL int ImportMarshalBuffer (int , int *, short *, int *);
 ExportedByJS0MRSHL int ImportMarshalBuffer (int ,int *,unsigned short *,int *);
 ExportedByJS0MRSHL int ImportMarshalBuffer (int , int *, int *, int *);
 ExportedByJS0MRSHL int ImportMarshalBuffer (int , int *, unsigned int*, int *);
 ExportedByJS0MRSHL int ImportMarshalBuffer (int , int *, long *, int *);
 ExportedByJS0MRSHL int ImportMarshalBuffer (int , int *,unsigned long *,int *);
 ExportedByJS0MRSHL int ImportMarshalBuffer (int , int *, float *   , int *);
 ExportedByJS0MRSHL int ImportMarshalBuffer (int , int *, double *  , int *);
 ExportedByJS0MRSHL int ImportMarshalBuffer (int , int *, stroct *  , int *);
 ExportedByJS0MRSHL int ReadHeader (int);
 ExportedByJS0MRSHL int CATSysMshSetMachine (char);
 ExportedByJS0MRSHL int CATSysMshGetMachine (char &);
 ExportedByJS0MRSHL int SetMarshalFileInfo (int,char,int);
 ExportedByJS0MRSHL int GetMarshalFileInfo (int,char &,int *);

  //--------------------------------------------------------------
  // Gestion du buffers descriptor
  //--------------------------------------------------------------

 ExportedByJS0MRSHL int OpenMarshalling  ( );     // Ouverture d'un file descriptor
 ExportedByJS0MRSHL int CloseMarshalling ( int ); // Fermeture d'un file descriptor
 ExportedByJS0MRSHL int CleanMarshalling ( int ); // Clear zone gestion demarshalling
 ExportedByJS0MRSHL int PutMarshalArchive ( CATMarshal * );
 ExportedByJS0MRSHL CATMarshal& GetMarshalArchive ( int );

  //--------------------------------------------------------------
  // Envoi des donnees marshallees
  //--------------------------------------------------------------

 ExportedByJS0MRSHL int FlushMarshalling  (int , int , char * ) ; // Transfert des donnees
 ExportedByJS0MRSHL int FlushMarshallingTailer  (int , int , char * , int = -1 ) ;
 ExportedByJS0MRSHL int FlushBufferLength (int);
 ExportedByJS0MRSHL int FlushMarshalBuffer (int, char *, int = -1 );
 ExportedByJS0MRSHL int FlushDataLength (int);
 ExportedByJS0MRSHL int FlushMarshalData (int, char *, int = -1 );
 ExportedByJS0MRSHL int FlushHeaderLength ();
 ExportedByJS0MRSHL int FlushMarshalHeader (char *, int = -1 );
 ExportedByJS0MRSHL int FlushTailerLength ();
 ExportedByJS0MRSHL int FlushMarshalTailer (char *, int = -1 );

  //--------------------------------------------------------------
  // Gestion de la Pile Data pour le marshalling
  //
  // Utilisation : Interne uniquement
  // -----------
  //
  //--------------------------------------------------------------


  //--------------------------------------------------------------
  // Gestion de la Pile Identificateurs pour le marshalling
  //
  // Utilisation : Interne uniquement
  // -----------
  //
  //--------------------------------------------------------------

 ExportedByJS0MRSHL int DeleteMarshalIdent ();

  //--------------------------------------------------------------
  // Gestion de la pile des identificateurs pt pour le demarshalling
  //
  // Utilisation : Interne uniquement
  // -----------
  //
  //--------------------------------------------------------------

 ExportedByJS0MRSHL void CreateUnmarshalIdent    ( int , void * );
 ExportedByJS0MRSHL void * FindUnmarshalIdent ( int )         ;
 ExportedByJS0MRSHL int DeleteUnmarshalIdent      ( );
 ExportedByJS0MRSHL int StatusUnmarshalIdent  ( );


  //--------------------------------------------------------------
  // Gestion du debug interne
  //
  // Utilisation : Interne uniquement
  // ------------
  //
  //--------------------------------------------------------------

 ExportedByJS0MRSHL int GetMarshalIdentObject ( int , void * , int * );
 ExportedByJS0MRSHL int CATMakeMarshalIdent(int,int,CATClassId,CATBaseUnknown *);
 ExportedByJS0MRSHL int CATMakeMarshalEnd(CATClassId,CATBaseUnknown *,int);
 ExportedByJS0MRSHL int CATMakeUnmarshalEnd(int);
 ExportedByJS0MRSHL int CATMarshalReference(CATBaseUnknown *,int);
 ExportedByJS0MRSHL int CATUnmarshalGetClassName(int, char**, int* );
 ExportedByJS0MRSHL int CATMarshalBaseClass();
 //ExportedByJS0MRSHL int CATMarshalAggregate();
 ExportedByJS0MRSHL CATBaseUnknown * CATCreateBegin(int,int,CATBaseUnknown *,int &,int &);

  //Initialisation des parametres
 ExportedByJS0MRSHL int CATSysMshInitMode (int);



 //--------------------------------------------------------------------------
 //  Pour la gestion des cgr et autres types de fichiers associe au modele
 //             Path donne le path du fichier modele concerne
 //             type donne le type du fichier a creer
 //--------------------------------------------------------------------------

 ExportedByJS0MRSHL int OpenReadCache( const char* Path, const char* Type);
 ExportedByJS0MRSHL int OpenWriteCache( const char* Path, const char* Type);

 //-----------------------------------//
 // Interne pour migration CATString  //
 //-----------------------------------//

 ExportedByJS0MRSHL int GetMarshalIdentObject ( int id_paquet, void *ident_objet, int *internal );
 ExportedByJS0MRSHL void ClassNameTable( int buffer_id, char* ClassName ) ;
 ExportedByJS0MRSHL int CATMakeMarshalEnd(int);
 ExportedByJS0MRSHL void * CATCreateBegin(int,int,void *,int &,int &);
 ExportedByJS0MRSHL int CATMarshalReference(CATString *,int);
 ExportedByJS0MRSHL int CATMarshalReference(CATUnicodeString *,int);
 ExportedByJS0MRSHL int CATMarshalAggregate(int,CATString*,CATBaseUnknown*);
 ExportedByJS0MRSHL int CATMarshalAggregate(int,CATUnicodeString*,CATBaseUnknown*);
 ExportedByJS0MRSHL int CATMarshalAggregate(int,CATBaseUnknown*,CATBaseUnknown*);
 ExportedByJS0MRSHL int CATUnmarshalCallAg(int,CATMarshallableCorba*,void*);
 ExportedByJS0MRSHL int CATUnmarshalCallAg(int,CATSerialize*,void*);
 ExportedByJS0MRSHL int CATUnmarshalCallAg(int,CATBaseUnknown*,void*);
 ExportedByJS0MRSHL int CATUnmarshalCallAg(int,CATString*,void*);
 ExportedByJS0MRSHL int CATUnmarshalCallAg(int,CATUnicodeString*,void*);
 ExportedByJS0MRSHL int CATUnmarshalCreateAg(int,CATCreateCorba*,void*,int);
 
// ++IK8 - 14:04:23
    ExportedByJS0MRSHL int CATStringMarshalling(CATString &iThis, int bd, int internal);
    ExportedByJS0MRSHL CATString* CATStringUnmarshalling(CATString &iThis, int bd, CATString *pt, int internal);
    CATString* CATStringUnmarshal(CATString &iThis, int bd, CATString *pt, int internal);
    
    ExportedByJS0MRSHL int CATUnicodeStringMarshalling(CATUnicodeString &iThis, int bd, int internal);
    ExportedByJS0MRSHL CATUnicodeString *CATUnicodeStringUnmarshalling(CATUnicodeString &iThis, int bd, CATUnicodeString *pt, int internal);
// --IK8 - 14:04:23
 
#endif


// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATSystemFileFormat_H
#define CATSystemFileFormat_H
////////////////////////////////////////////////////////////////////////////////////////
// Didier LARUEL
// 23/05/97
//
// Purpose: CATSystemFileFormat
//
//          A File System Format May provide system dependant means
//          to encode or decode data for exchange beetween to process
//          based onto temporary files.
//
//          File Format, take in account the allocation of a temporary
//          file space, and the desallocation of this file when the
//          assynchronous exchange is over. No persistant files remains
//          from the echange, so no data compatibility should be acheived
//          for this.
//
//          File Format, also take in account the LPFORMATETC & LPSTGMEDIUM
//          system information encodage (send information), and decodage
//          (receive information).
//
//          for this purpose, the implementers has only to overload
//          3 new entry points:
//            ObjectToTempoFile, TempoObjectFromFile, ReleaseTempoObject
//
//          This could easyly be done for streamable object (mainly containers or document, today)
//          but this could be as well implemented for any other object witch has not
//          usually a persistant state, and has not persistant storage implementation
//
//          The file must contains sufficient data to produce a temporary object from the file
//
//
//
// Remark, Data Transfert are assynchronous, and may concern such data
// as Text, RTF, METAFILEPIC, GEOMETRICAL, MECHANICAL, ...
// those data can either be provided by CATIA to CATIA, either
// comes from other application or goes to other application
// (e.g. Text, ...). Then the tranfer protocol used by the system
// should be stricly respected
//
////////////////////////////////////////////////////////////////////////////////////////

/**
 * @level Private
 * @usage U1
 */

#include<CATSystemFormat.h>
#include<CATUnicodeString.h>

#include<CP0CLIP.h>

class ExportedByCP0CLIP CATSystemFileFormat: public CATSystemFormat
{
 public:
  CATSystemFileFormat(CATFormat* for_fmt=NULL);
  virtual ~CATSystemFileFormat();

  //not to derivate, because a default implementation ensure system dependant management
  virtual LPFORMATETC  SystemFormat() const;
  virtual int ProvideTempoData(CATBaseUnknown_ptr, LPFORMATETC& system_format, LPSTGMEDIUM& system_medium);
  virtual int ReleaseTempoData(LPSTGMEDIUM provided_system_medium);
  virtual int ProvideTempoObject(LPFORMATETC system_format, LPSTGMEDIUM system_medium, CATBaseUnknown_ptr& tempo_object);

  //to derivate
  virtual int ReleaseTempoObject(CATBaseUnknown_ptr& tempo_object);

  virtual int ObjectToTempoFile(CATBaseUnknown_ptr object_to_save, CATUnicodeString& system_file_location)
		{return 0;}
  virtual int FileToTempoObject(const CATUnicodeString& system_file_location, CATBaseUnknown_ptr& object_to_provide)
		{return 0;}

  //use carrefully or do not use!!!
  virtual int ReleaseFile();
  const char* HoldedFile() const;

  char* AllocateDefaultSpace();  // no extension managed, string must be desallocated by free
  int HoldFile(const char*); // release the previous file and hold the file
 private:
  char* _nom_fic;
};

#endif


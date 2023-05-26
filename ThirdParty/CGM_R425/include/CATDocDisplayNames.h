/* -*-c++-*- */
#ifndef CATDocDisplayNames_h
#define CATDocDisplayNames_h

// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @level Private
 * @usage U1
 */

#include "AD0XXBAS.h"
#include "CATUnicodeString.h"

class CATIDocId;

/**
 * Display names of a document in an environment.
 */
class ExportedByAD0XXBAS CATDocDisplayNames
{
public:
  CATDocDisplayNames(CATIDocId &iDocId);
  ~CATDocDisplayNames();

  /**
   * ReInitializes the object in order to reuse it instead of creating a new one.
   */
  void Reinitialize(CATIDocId &iDocId);

  // ----- Bit mask for querying names -----

  static const unsigned int QueryDocName;
  static const unsigned int QueryDocShortName;
  static const unsigned int QueryDocRepositoryName;
  static const unsigned int QueryDocSaveAsFileName;

  // ----- Access the data members -----

  /**
   * Gets the document identifier in its environment.
   * @param opDocId
   *   The identifier. You have to run <tt>opDocId->Release()</tt>.
   */
  void GetDocId(CATIDocId *&opDocId);

  /**
   * Retrieves the display name of the document.
   * @param oDocName
   *  The name of the document to display, for example in the document's window.
   */
  const CATUnicodeString &GetDocName() const;

  /**
   * Retrieves the display short name of the document
   * @param oDocShortName
   *  The short name of the document to display.<br>
   *  For example in a file based environment, this is the filename, without the directory.
   */
  const CATUnicodeString &GetDocShortName() const;

  /**
   * Retrieves the display name of the repository of the document
   * @param oDocRepositoryName
   *  The name of the document repository.<br>
   *  For example in a file based environment, this is the directory name. With ENOVIA VPM persistency, this is the environment name.
   */
  const CATUnicodeString &GetDocRepositoryName() const;

  /**
   * Retrieves the default name of the document for Save As File
   * @param oDocSaveAsFileName
   *  The default name of the document, to be provided within Save As dialog box.
   */
  const CATUnicodeString &GetDocSaveAsFileName();

  // ----- Set the names -----

  /**
   * Clear the names
   */
  void ClearNames();

  /**
   * Sets the display name of the document.
   * @param iDocName
   *  The name of the document to display, for example in the document's window.
   */
  void SetDocName(const CATUnicodeString &iDocName);

  /**
   * Sets the display short name of the document
   * @param iDocShortName
   *  The short name of the document to display.<br>
   *  For example in a file based environment, this is the filename, without the directory.
   */
  void SetDocShortName(const CATUnicodeString &iDocShortName);

  /**
   * Sets the display name of the repository of the document
   * @param iDocRepositoryName
   *  The name of the document repository.<br>
   *  For example in a file based environment, this is the directory name. With ENOVIA VPM persistency, this is the environment name.
   */
  void SetDocRepositoryName(const CATUnicodeString &iDocRepositoryName);

  /**
   * Sets the default name of the document for Save As File
   * @param iDocSaveAsFileName
   *  The default name of the document, to be provided within Save As dialog box.
   */
  void SetDocSaveAsFileName(const CATUnicodeString &iDocSaveAsFileName);

private:
  CATDocDisplayNames(const CATDocDisplayNames &iObject); // Prohibited
  CATDocDisplayNames &operator=(const CATDocDisplayNames &iObject); // Prohibited

  CATIDocId *_pDocId;

  CATUnicodeString _DocName;
  CATUnicodeString _DocShortName;
  CATUnicodeString _DocRepositoryName;
  CATUnicodeString _DocSaveAsFileName;
};

/**
 * @collection CATLISTP(CATDocDisplayNames)
 * Collection class for pointers to CATDocDisplayNames.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */
#include "CATLISTP_Clean.h"

#define CATLISTP_Append
#define CATLISTP_RemoveAll

#include "CATLISTP_Declare.h"

#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByAD0XXBAS

CATLISTP_DECLARE(CATDocDisplayNames)

#endif

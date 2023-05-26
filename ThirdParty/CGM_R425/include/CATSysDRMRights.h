/* COPYRIGHT DASSAULT SYSTEMES 2006 */
/**
 * @CAA2Level L0
 * @CAA2Usage U5
 */

#ifndef CATSYSDRMRIGHTS_H
#define CATSYSDRMRIGHTS_H


/**
 * DRM Right to read a document.
*/
#define CATDRM_READ		0x00000001L

/**
 * DRM Right to edit the rights of a given document.
*/
#define CATDRM_EDITRIGHT	0x00000002L

/**
 * DRM Right to save a document.
 * <br><b>Role</b>: DRM Right to save a document after modifications.
*/ 
#define CATDRM_SAVE		0x00000010L

/**
 * DRM Right to save a document under a new name.
 * <br><b>Role</b>: DRM Right to save a document after modifications as a new V5 
 * document. This right enables the decryption of the document, if no the user exit
 * allows the saving without encryption.
*/
#define CATDRM_SAVEAS		0x00000020L

/**
 * DRM Right to save a document under a new name with DRM inheritance.
 * <br><b>Role</b>: DRM Right to save a document after modifications as a new V5 
 * document, but in contrary to the @href CATDRM_SAVEAS the new document will
 * inherit all the DRM properties of the original document, from which it is
 * created. It is impossible to decrypt a document with only this right. If the user
 * exit is not active for encryption at the moment of the save, then the saving will
 * be forbidden.
*/
#define CATDRM_INHERIT_SAVEAS	0x00000040L

/**
 * DRM Right to export a document to an external format.
 * <br><b>Role</b>: DRM Right to allow the export of a V5 document under a non V5
 * format such as STEP, IGES...and all other formats that do not allow to embed 
 * DRM.
*/
#define CATDRM_EXPORT		0x00000080L

/**
 * DRM Right to export the specs of a document.
 * <br><b>Role</b>: DRM Right to export the specs of a document with power copy and
 * user feature.
*/
#define CATDRM_DUPLICATE_SPECS	0x00000100L


/**
 * DRM Right to use the collaboration with a document.
*/
#define CATDRM_COLLABORATION	0x00000200L

/**
 * DRM Right to use Cut/Paste command.
 * <br><b>Role</b>: DRM Right to use the Cut/Paste and Drag/Drop feature on the current
 * document
*/
#define CATDRM_COPY		0x00000400L

/**
 * DRM Right to copy the geometry.
 * <br><b>Role</b>: DRM Right to copy the geometry of a document with commands like
 * Copy/Paste as Result.
*/
#define CATDRM_COPY_GEOMETRY	0x00000800L


/**
 * DRM Right to export a document to another DRMenabled format 
 * <br><b>Role</b>: DRM Right to allow the export of a V5 document to a
 * different V5 format that supports DRM, such as cgr and 3dxml for CATProduct.
 * This right will control for example the export of CATPart and CATProduct to 
 * cgr, the export of CATProduct to 3dxml format.
*/
#define CATDRM_EXPORT_TO_DRM_FORMAT		0x00001000L

/**
 * DRM Right to export a document to another DRMenabled format 
 * <br><b>Role</b>: DRM Right to allow the export of a V5 document to a
 * different V5 format that supports DRM, such as cgr and 3dxml for CATProduct,
 * but in contrary to the @href CATDRM_EXPORT_TO_DRM_FORMAT the new document will
 * inherit all the DRM properties of the original document,from which it is
 * created.  This right will control for example the export of CATPart and 
 * CATProduct to cgr, the export of CATProduct to 3dxml format.
*/
#define CATDRM_INHERIT_EXPORT_TO_DRM_FORMAT	0x00002000L

enum           
{
   DRMRightRead        =0x01,
   DRMRightInvalidMax
};

#endif

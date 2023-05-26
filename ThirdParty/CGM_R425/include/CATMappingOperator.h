#ifndef CATMappingOperator_H
#define CATMappingOperator_H

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//
// Copyright Dassault Systemes 1996
//----------------------------------------------------------------
// Abstract : This Class allow to compute Texture Coordinates
//            An operator is attached to one or several CATGraphicMaterial 
//
// ----------------------------------------------------------------
//  Usage :   
//
//  MappingOperator attached to a CATGraphicMaterial 
//
//       When you attach an operator you increase the reference's number
//       of this operator. The management of the operator's destruction
//       is done by the material. An Operator is deleted when
//       it number of links is zero.
//
//  Organization of data for ComputeTextureCoordinates Method
//
//     -Vertices are organized : (x,y,z)   (x,y,z) ....
//     -Normales are organized : (nx,ny,nz)(nx,ny,nz) ....
//      the number of normals is the number of vertices or 1
//      if the number is 1, all vertices have the same normal
//     -Texture Coordinates are organized : (s,t,0) (s,t,0) ...
//      for a 1D texture t is 0
//
//  Send A notification to the material attach 
//
//      You have make a modification in your mapping, You can 
//      call the material to worn it about this modification. After
//      the material send a notification to the elements attach to it.
//      In general case the modification is about the texture coordinates
//      regeneration. In your method use :
//      SendMaterialNotification( CATUpdateTCNotification) 
//
//   UV Necessary
//
//      If our method ComputeTextureCoordinates if you need of the UV 
//      mesh, you must overload the method NeedUVMesh. The default behavior
//      is No NeedUVMesh. This method will be used to ask the mesh 
//
// ----------------------------------------------------------------
//  Inheritance : - -
// ----------------------------------------------------------------
//  Main Methods :
//
//    manage Computing
//  
//       ComputeTextureCoordinates
//       SendMaterialNotification    ( protected to use in derivation )
//       NeedUVMesh()
//                 
//    manage attachment of a mapping operator
//       AddRef
//       Release
//
// ----------------------------------------------------------------

// interfaces

// TIEs

// others
#include "CATEventSubscriber.h"
#include "CATMaterialNotification.h"
#include "SGInfra.h"
#include "CATIAV5Level.h"

/** Base class to create a mapping operator to apply textures.
 * Derive from this class and overload the method ComputeTextureCoordinates. */
class ExportedBySGInfra CATMappingOperator : public CATEventSubscriber
{
public:
  // macros
  /** @nodoc */
  CATDeclareClass;

  // 'tors
  /** Constructs an empty mapping operator. */

  CATMappingOperator(); 

  /** Copy contructor */
  CATMappingOperator(const CATMappingOperator & iOper);

#ifdef ADDREFERENCE_MIGRATION
#else
  /** @deprecated R424
    * Use rather Release method
    * Deletes the mapping operator. 
    */
  virtual int Destroy();

  /** @deprecated R424
    * Use rather AddRef method
    * Increments the reference counter of the mapping operator.
    */
  void AddReference();

  /** @deprecated R424
    * Use rather Release method
    * Decrements the reference counter of the mapping operator.
    */
  void SubReference();

  /** @deprecated R424
    * Returns the reference counter value of the mapping operator.
    */
  int  GetReferenceNumber() const;

#endif

  /** Computes the texture coordinates for all vertices.
   * @param iVertex
   * Array containing the coordinates of every vertices,as a succession
   * of (x,y,z) sets.
   * @param iNbVertex
   * Number of vertices in <tt>iVertex</tt>.
   * @param iNormals
   * Array containing the coordinates of the normals at every vertices, as
   * a succession of (Nx,Ny,Nz) sets.
   * If the surface is plane, the only given set is valid for all vertices.
   * @param iNormals
   * Number of normal sets in <tt>iNormals</tt>.
   * @param iTuv
   * Array containing the parameters in of every vertices in the surface parametrization space,
   * as a succession of (u,v) sets.
   * This array must be required by the mapping operator through the method <tt>NeedUVMesh</tt>.
   * @param iNbuv
   * Number of parameter sets in <tt>iNbuv</tt>.
   * @param oTexture
   * Array containing the coordinates of texture coordinates for every vertices,
   * as a succession of (s,t,0) sets. <br>
   * (0,0,0) always indicates the lower-left corner of the texture image. <br>
   * (1,1,0) always indicates the upper-right corner of the texture image.
   */
  virtual void ComputeTextureCoordinates(const float iVertex[],
                                         const int   iNbVertex,
                                         const float iNormals[],
                                         const int   iNbNormals,
                                         const float iTuv[],
                                         const int   iNbuv,
                                         float       oTexture[]) const;

  /** Computes the texture coordinates for all vertices. Overload this method only if you need
   * access to the topological cell. Otherwise, use other method.
   * @param iVertex
   * Array containing the coordinates of every vertices,as a succession
   * of (x,y,z) sets.
   * @param iNbVertex
   * Number of vertices in <tt>iVertex</tt>.
   * @param iNormals
   * Array containing the coordinates of the normals at every vertices, as
   * a succession of (Nx,Ny,Nz) sets.
   * If the surface is plane, the only given set is valid for all vertices.
   * @param iNormals
   * Number of normal sets in <tt>iNormals</tt>.
   * @param iTuv
   * Array containing the parameters in of every vertices in the surface parametrization space,
   * as a succession of (u,v) sets.
   * This array must be required by the mapping operator through the method <tt>NeedUVMesh</tt>.
   * @param iNbuv
   * Number of parameter sets in <tt>iNbuv</tt>.
   * @param oTexture
   * Array containing the coordinates of texture coordinates for every vertices,
   * as a succession of (s,t,0) sets. <br>
   * (0,0,0) always indicates the lower-left corner of the texture image. <br>
   * (1,1,0) always indicates the upper-right corner of the texture image.
   * @param iCell
   * Topological cell for which we are calculating the textures coordinates.
   */
  virtual void ComputeTextureCoordinates(const float            iVertex[],
                                         const int              iNbVertex,
                                         const float            iNormales[],
                                         const int              iNbNormales,
                                         const float            iTuv[],
                                         const int              iNbuv,
                                         float                  oTexture[],
                                         const CATBaseUnknown * iCell) const;

  /** @nodoc
   * This method is only made to test temporalry the new mapping
   * operators which need the indices of the faces
   */
  virtual void ComputeTextureCoordinates(const float            iVertex[],
                                         const int              iNbVertex,
                                         const float            iNormales[],
                                         const int              iNbNormales,
                                         const int              iTriangleIndices[],
                                         const int              iNbTriangles,
                                         const int              iTriangleStripIndices[],
                                         const int              iNbTrianglesStrip,
                                         const int              iNbVertexPerStrip[],
                                         const int              iTriangleFanIndices[],
                                         const int              iNbTrianglesFan,
                                         const int              iNbVertexPerFan[],
                                         const float            iTuv[],
                                         const int              iNbuv,
                                         float                  oTexture[],
                                         const CATBaseUnknown * iCell) const;

  /** Indicates the need for surface parameters array <tt>iTuv</tt>.
   * <ul>
   * <li>0 : no need for surface parameters. </li>
   * <li>1 : require calculation of surface parameters. </li>
   * </ul>
   */
  virtual int NeedUVMesh() const;

#ifdef CATIAV5R8
  /** Return the id of the mapping operator.
   * This id is not persistent. It only serves to index different sets
   * of mapping coordinates on CATGraphicPrimitives.
   */
  inline unsigned short GetId() const;
#endif // ifdef CATIAV5R8


  /**
   * Increments the reference count for the given interface.
   * @return The reference count value.
   * <br>This information is meant to be used for diagnostic/testing purposes only, because, in certain situations, the value may be unstable.
   */
  virtual ULONG   __stdcall AddRef();

  /**
   * Decrements the reference count for the given interface.
   * @return The reference count value.
   * <br>This information is meant to be used for diagnostic/testing purposes only, because, in certain situations, the value may be unstable.
   */
  virtual ULONG   __stdcall Release();

protected:

  /* @nodoc */
  virtual ~CATMappingOperator();

  /** Updates the display after a modification of the mapping operator.
   * <ul>
   * <li>CATRedrawNotification : redraw the window.</li>
   * <li>CATUpdateTCNotification : recalculate texture coordinates and redraw the window.</li>
   * </ul>
   */
  virtual void SendMaterialNotification(CATMaterialNotificationType iType);

private:
  int _ReferenceNumber;
  
#ifdef CATIAV5R8
  static unsigned short ms_usNbOperator;
  unsigned short m_usId;
#endif // ifdef CATIAV5R8
};

#ifdef CATIAV5R8
inline unsigned short CATMappingOperator::GetId() const
{
   return m_usId;
}
#endif // ifdef CATIAV5R8



#endif // CATMappingOperator_H

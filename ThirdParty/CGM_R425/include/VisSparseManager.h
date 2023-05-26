#ifndef VISSPARSEMANAGER_H_
#define VISSPARSEMANAGER_H_

#include <stdint.h>
#include <vector>

#include "CATVisFoundation.h"
#include "VisSparseTexture.h"

/** Structure which defines the sparse texture prepass resul
*   mipLevel is the mipmap level computed for a given pixel
*   {u,v,w} are the texel coordinates associated to the pixel
*   
*   Note: used with GetLastFeedbackElements function described below
*/
struct ExportedByCATVisFoundation VisFeedbackLayout
{
  typedef std::pair<const VisFeedbackLayout*, std::size_t> Range_t;

  float  mipLevel;
  float  u;
  float  v;
  float  w;
};

/** Structure which defines the user requirement to create a sparse texture
*   format is the format of the texture the user would wants to create
*   arraySize specifies if the texture would be an array: 1 if this is a classic texture, more if this is an array
*
*   Note: used with GetLastFeedbackElements function described below
*/
struct ExportedByCATVisFoundation VisSparseRequirement
{
  IVisTextureFormat::Type format;
  unsigned int            arraySize;
};

/** Class which represents the user entry point to:
*   
*   - Get sparse texture information
*   - Get sparse texture prepass result
*/
class ExportedByCATVisFoundation VisSparseManager
{

public :

  typedef unsigned int SparseTextureAlgoID;

  static const SparseTextureAlgoID WrongID = SparseTextureAlgoID(-1);


  static VisSparseManager * GetInstance();


  /** Function not used yet
  */
  virtual SparseTextureAlgoID RequestSparseID();

  /** Function to get the last sparse prepass result information
  *   @param iAlgoID must be set to 0, will be used later to specifies which pass result information you want
  *   @param oSize is the number of VisFeedbackLayout instance the prepass buffer contains, so not in byte
  */
  unsigned int GetLastFeedbackElementCount(const SparseTextureAlgoID& iAlgoID) const;
  // @deprecated
  void GetLastFeedbackELementCount(const SparseTextureAlgoID& iAlgoID, unsigned int& oSize) const;

  /** Function to get the last sparse prepass result
  *   @param iAlgoID must be set to 0, will be used later to specifies which pass result information you want
  *   @param oData specifies the memory we will write on, must have been allocated
  *   @param iEllementOffset specifies the starting offset for oData
  *   @param iElementCount specifies the number of VisFeedbackLayout instance you want to retrieve
  *   @param oElementCount specifies the number of VisFeedbackLayout instance you have retrieved. Optional Parameter
  */
  void GetLastFeedbackElements(const SparseTextureAlgoID& iAlgoID, VisFeedbackLayout* oData, unsigned int iElementOffset, unsigned int iElementCount, unsigned int* oElementCount = 0) const;
  VisFeedbackLayout::Range_t GetLastFeedbackElements(const SparseTextureAlgoID& iAlgoID) const;
  
  /** Function to get available sparse texture page layout
  *   @param iRequirement specifies the characteristics of the texture you would want to create
  *   @param oPages specifies the available pages layout you can use for the given requirement
  */
  virtual bool GetAvailablePageLayout(const VisSparseRequirement& iRequirement, std::vector<VisSparseTexture::Page>& oPages) const;

  virtual unsigned int GetMaxNumberOfLayer() const;

protected :

  virtual unsigned int _GetLastFeedbackElementCount(const SparseTextureAlgoID& iAlgoID) const = 0;
  virtual void _GetLastFeedbackElements(const SparseTextureAlgoID& iAlgoID, VisFeedbackLayout* oData, unsigned int iEllementOffset, unsigned int iElementCount, unsigned int* oElementCount = 0) const = 0;
  virtual VisFeedbackLayout::Range_t _GetLastFeedbackElements(const SparseTextureAlgoID& iAlgoID) const = 0;

  VisSparseManager() = default;
  virtual ~VisSparseManager() = default;


private :

  static VisSparseManager * s_instance;

};



#endif //VISSPARSEMANAGER_H_


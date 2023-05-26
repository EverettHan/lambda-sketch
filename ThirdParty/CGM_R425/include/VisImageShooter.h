#ifndef VISIMAGESHOOTER_H_
#define VISIMAGESHOOTER_H_

#include "VisSphericalVideo.h"
#include "CATUnicodeString.h"

class VisImageShooterImpl;
class CATSupport;

/** This class is used to shoot image. This can be 360 or normal image. */
class ExportedByVisSphericalVideo VisImageShooter
{
public :
  struct ExportedByVisSphericalVideo Parameters
  {
    Parameters();    
    
    struct ImageRes
    {
      unsigned int m_Width;  ///< Shoot resolution
      unsigned int m_Height;
    }m_Image;

    CATSupport * m_Support; ///< This support will be used for the shoot. Set correct viewpoint, environment...
    CATUnicodeString m_OutputImage; ///< The image name    
    bool m_Mode360; ///< Set to true if you want 360 image.
  };

  /** Construct the objects with all the parameters. */
  VisImageShooter(const Parameters & iParameters);
  ~VisImageShooter();

  /** Used to shoot a single frame. We use the support set in the parameters.  */
  void ShootImage();

private :
  VisImageShooterImpl * m_impl;
};

#endif //VISIMAGESHOOTER_H_

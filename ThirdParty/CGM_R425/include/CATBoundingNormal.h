#ifndef CATBoundingNormal_H
#define CATBoundingNormal_H
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATMathDef.h"

#define CULLINFO_ALL_FRONT   0x1
#define CULLINFO_ALL_BACK    0x2
#define CULLINFO_UNSURE      0x4

#define MAX_ANGLE_FOR_TEST  1.0   // dont even bother with big angles

class CAT3DBoundingNormal
{
public :
  // tests groups of normals for front or back facing
  inline int  test_bounding_normal( float *eye_in_mc_ ) const;
  inline void set_bounding_normal(float *normal, float bounding_angle,
	      		          float max_dist, float min_dist );

private:
  float  normal[3];
  float  bounding_angle;
  float  max_dist;
  float  min_dist; 
};




inline void CAT3DBoundingNormal::set_bounding_normal( float *base_normal,
						float new_bounding_angle,
						float new_max_dist,
						float new_min_dist)
{
  if (new_bounding_angle > 1.f) new_bounding_angle = 1.f;
  else if (new_bounding_angle < -1.f) new_bounding_angle = -1.f;
  normal[0] = base_normal[0];  
  normal[1] = base_normal[1];  
  normal[2] = base_normal[2];  
  bounding_angle = (float)acos((double)new_bounding_angle);
  max_dist = new_max_dist;
  min_dist = new_min_dist;
}


inline int CAT3DBoundingNormal::test_bounding_normal
                                    ( float * view_direction ) const
{



  // the cull test here is  plane_eye doted with plane_triangle
  //  if the result is greater than zero the triangle is front facing
  //  this breaks down to 
  //    PlaneEye =  E,   PlaneTriangle = T
  //      TaEa + TbEb + TcEc + Td*Ed > 0 
  //     (  T  dot   E     ) + Td*Ed > 0
  //     |T|*|E|*cos(angle) + Td*Ed > 0
  //   if T and E are normalized  |T|=|E|=1
  //      cos(angle) > -Td*Ed

  // perform cull test on group of points
  float angle_to_eye;
  int   result;  
  float max_d, min_d;
  
  if ( bounding_angle < MAX_ANGLE_FOR_TEST ) 
    {

    // take dot product to find angle to eye
    angle_to_eye = ( normal[0] * view_direction[0] ) +
                   ( normal[1] * view_direction[1] ) +
	           ( normal[2] * view_direction[2] );

    // scale by w term 
    max_d = (max_dist * view_direction[3]);

    if ( fabs(max_d) < 0.02 ) {
	// distance from eye not a factor
	max_d = min_d = (float)CATPIBY2;
	

    } else {
	// possibly distance will change answer 
        min_d = (min_dist * view_direction[3]);	

        if (max_d > 1.f) max_d = 1.f;
        else if (max_d < -1.f) max_d = -1.f;
        max_d = (float)acos((double) max_d );

        if (min_d > 1.f) min_d = 1.f;
        else if (min_d < -1.f) min_d = -1.f;
        min_d = (float)acos((double) min_d );
      }
    


    // quicker acos.. dont need a lot of accuracy here ? 
      if (angle_to_eye > 1.f) angle_to_eye = 1.f;
      else if (angle_to_eye < -1.f) angle_to_eye = -1.f;
      angle_to_eye = (float)acos((double) angle_to_eye );


#define BOUNDING_FUDGE  0.1  // with all the normalization and acos its
                             //  not a good idea to look for an exact result
    
    if ( angle_to_eye < min_d ) 
      {  // back facing.. make sure it stays that way
	 if ( (angle_to_eye + bounding_angle) < ( max_d - BOUNDING_FUDGE ))
	   result = CULLINFO_ALL_BACK;
	 else
	   result = CULLINFO_UNSURE;
       } else 
	 {  // front facing
	   if ((angle_to_eye - bounding_angle) > (min_d + BOUNDING_FUDGE ))
	     result = CULLINFO_ALL_FRONT;
	    else
	      result = CULLINFO_UNSURE;
	 }
   } else 
    {
      // bounding angle too big.. don't bother trying to test 
      result = CULLINFO_UNSURE;
      
    }
    return( result );  
}


#endif

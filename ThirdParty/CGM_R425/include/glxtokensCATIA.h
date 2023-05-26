#ifndef GLXTOKENSCATIA_H
#define GLXTOKENSCATIA_H

// COPYRIGHT DASSAULT SYSTEMES 2002

#ifdef __cplusplus
extern "C" {
#endif

/*
** Names for attributes to glXGetConfig.
*/
#define GLX_USE_GL		1	/* support GLX rendering */
#define GLX_BUFFER_SIZE		2	/* depth of the color buffer */
#define GLX_LEVEL		3	/* level in plane stacking */
#define GLX_RGBA		4	/* true if RGBA mode */
#define GLX_DOUBLEBUFFER	5	/* double buffering supported */
#define GLX_STEREO		6	/* stereo buffering supported */
#define GLX_AUX_BUFFERS 	7	/* number of aux buffers */
#define GLX_RED_SIZE		8	/* number of red component bits */
#define GLX_GREEN_SIZE		9	/* number of green component bits */
#define GLX_BLUE_SIZE		10	/* number of blue component bits */
#define GLX_ALPHA_SIZE		11	/* number of alpha component bits */
#define GLX_DEPTH_SIZE		12	/* number of depth bits */
#define GLX_STENCIL_SIZE	13	/* number of stencil bits */
#define GLX_ACCUM_RED_SIZE	14	/* number of red accum bits */
#define GLX_ACCUM_GREEN_SIZE	15	/* number of green accum bits */
#define GLX_ACCUM_BLUE_SIZE	16	/* number of blue accum bits */
#define GLX_ACCUM_ALPHA_SIZE	17	/* number of alpha accum bits */

/*
** Error return values from glXGetConfig.  Success is indicated by
** a value of 0.
*/
#define GLX_BAD_SCREEN		1	/* screen # is bad */
#define GLX_BAD_ATTRIBUTE	2	/* attribute to get is bad */
#define GLX_NO_EXTENSION	3	/* no glx extension on server */
#define GLX_BAD_VISUAL		4	/* visual # not known by GLX */
#define GLX_BAD_CONTEXT         5
#define GLX_BAD_VALUE           6
#define GLX_BAD_ENUM            7

/* Property values for visual_type */
#define GLX_TRUE_COLOR     	  0x8002
#define GLX_DIRECT_COLOR          0x8003
#define GLX_PSEUDO_COLOR          0x8004
#define GLX_STATIC_COLOR          0x8005
#define GLX_GRAY_SCALE    	  0x8006
#define GLX_STATIC_GRAY    	  0x8007

/* Property values for transparent pixel */
#define GLX_NONE     	          0x8000
#define GLX_TRANSPARENT_RGB    	  0x8008
#define GLX_TRANSPARENT_INDEX     0x8009

/* Property values for visual_rating */
#define GLX_SLOW_CONFIG		  0x8001
#define GLX_NON_CONFORMANT_CONFIG 0x800D

#define GLX_WIDTH                               0x801D
#define GLX_HEIGHT                              0x801E


#define GLX_DAMAGED                             0x8020
#define GLX_SAVED                               0x8021

#define GLX_WINDOW                              0x8022

#define GLX_FRONT_LEFT_BUFFER_BIT               0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT              0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT                0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT               0x00000008
#define GLX_AUX_BUFFERS_BIT                     0x00000010
#define	GLX_DEPTH_BUFFER_BIT                    0x00000020
#define	GLX_STENCIL_BUFFER_BIT                  0x00000040
#define	GLX_ACCUM_BUFFER_BIT                    0x00000080
#define	GLX_SAMPLE_BUFFERS_BIT                  0x00000100

#define GLX_VENDOR		1
#define GLX_VERSION		2
#define GLX_EXTENSIONS		3

#ifdef __cplusplus
}
#endif

#endif /* !__GLX_glxtokens_h__ */

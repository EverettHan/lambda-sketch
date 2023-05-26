#ifndef CATRenderingAttribut_h
#define CATRenderingAttribut_h

/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 2003

//-----------------------------------------------------
//	CATRenderingAttribut (fbj)
//
// Cet enum sert pour differencier les differents type
// de rendu graphique pour une rep
// CATRSNone:         aucun rendu specifique
// CATRSTransparent : la rep n'est pas dessinee mais 
//                    elle reste pickable 
// CATRSEdge :        On dessine les edges et lines
// CATRSMesh :        On dessine les faces
// CATRSMaterial :    On force le mode materiau
// 
// NB: ces modes peuvent s'utiliser a plusieurs
//   ex : value.SetRenderingStyle(CATRSEdge | CATRSMesh);
//
//-----------------------------------------------------

typedef int CATRenderingAttribut;
     
#define CATRSNone          0x00
#define CATRSTransparent   0x01
#define CATRSEdge          0x02
#define CATRSMesh          0x04
#define CATRSMaterial      0x08

#endif

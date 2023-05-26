
/**
 * @level Private
 * @usage U1
 */

/* structTOLER.h : COPYRIGHT DASSAULT SYSTEMES 1995 */
#ifndef structTOLER_h
#define structTOLER_h

//----------------------------------------------------------------
//                     TOLER
//----------------------------------------------------------------

 struct TOLER {

   double tol[5];
      /*
      ..  tol[0] : tolerances pour courbes identiques (0.1mm)
      ..  tol[1] : tolerances pour intersections et projections (0.001mm)
      ..  tol[2] : infiniment grand (100m)
      ..  tol[3] : tol[2]*tol[2] sert a tester des carres de distance
      ..  tol[4] : tolerance angulaire (1.D-6 radian)
      */

    double   fleche; /* fleche maximum entre 2 points   : (0.03mm) */
    double   pas;   /* distance maximum entre 2 points : (20mm)   */

    double   toc[5];
      /*
      ..   toc[0] : tolerance de constructions sur les points (0.01mm)
      ..   toc[1] : tolerance de constructions sur les tangentes
      ..            (0.1 radian)
      ..   toc[2] : tangentes confondues (0.004 radian)
      ..   toc[3] : tolerance algorithme polyedre (0.001)
      ..   toc[4] : tolerance divide check (1.D-12)
      */

     double  dens;        /* densite (1.0)                        */

     double  xtoler[10];
      /*
      ..   xtoler[0] : nombre de mm par unite modele
      ..   xtoler[1] : encombrement du modele
      ..   xtoler[2] : largeur standard d'un plotting
      ..   xtoler[3] : hauteur standard d'un plotting
      */

     int   ideu;        /* degre standard en U des polynomes(=5) */
     int   idev;        /* degre standard en V des polynomes(=5) */
     int   itoler[10];  /* degre standard des coniques(=9)       */

};

#endif




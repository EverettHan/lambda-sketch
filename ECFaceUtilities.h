#ifndef ECFaceUtilities_H
#define ECFaceUtilities_H

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATFace;
class CATCell;

class  ECFaceUtilities
{
public:
    static void ExtractOneConnectedFaceGroup
                (
                    CATBody* inBody, // the body
                    CATLISTP(CATFace)& ioFaces, // input faces; one (the first) or more (connected) faces will be removed
                    CATLISTP(CATFace)& outConnectedFaces, // one (the first input face) or more (connected) faces
                    CATListOfInt & outOrientations // result faces orientations in a shell
                    );

    static CATBody* MakeSheetFromFaces(CATBody* iBody, const CATListPtrCATFace& iFaces, bool iNewVersion=false);
    static CATBody* MakeSheetFromFaces(CATLISTP(CATCell)& iFaces, CATGeoFactory* iGeoFactory, CATTopData* iTopData);
    static CATBody* MakeSheetFromFaces(CATTopData *iTopData, CATGeoFactory* iGeoFactory, CATLISTP(CATFace)& iCells, CATListOfInt& iOrientList);
    static CATShell* GetShell(CATFace* iFace, CATBody* iBody);
};
#endif //ECFaceUtilities_H
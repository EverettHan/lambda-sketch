# lambda-sketch
In this project, we try to archive the following:
## Parse input sketch 
sketch data is passed in as json string. We will parse it and create a c++ object.
## Solve sketch relations
if the sketch has any constraints defined and the solving status is NOT up-to-date, we will set up the CDS solver, solve, and update the sketch data and status based on the solving results.
## Create sketch contours
Sketch contours are extracted as CGM faces, and saved as NCGM binary data buffers. The contour faces are to be consumed by other modeling functions (such as extrusion) for 3D geometry creation.
# lambda-sketch
In this project, we try to archive the following:
## Parse input sketch 
sketch data is passed in as json string. We will parse it and create a c++ object.
## Solve sketch relations
if the sketch has any constraints defined and the solving status is NOT up-to-date, we will set up the CDS solver, solve, and update the sketch data and status based on the solving results.
## Create sketch contours
Sketch contours are extracted as CGM faces. The contour faces are to be consumed by other modeling functions (such as extrusion) for 3D geometry creation.
## Save sketch contours body in NCGM file
Sketch contours are saved as NCGM binary data buffers. The contour faces are to be consumed by other modeling functions (such as extrusion) for 3D geometry creation.


## Build the Actual C++ Lambda Function
```bash
cd ~
ssh-keygen -t rsa -b 4096
cat ~/.ssh/id_rsa.pub
#add public access key to github repos
git config --global user.email "huili_han@yahoo.com"
git config --global user.name "everetthan"
mkdir ~/git
cd ~/git
git clone git@github.com:everetthan/lambda-sketch.git
cd ~/git/lambda-sketch
mkdir build
cd build
cmake3 .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/home/zhn/install
make
make aws-lambda-package-demo
```
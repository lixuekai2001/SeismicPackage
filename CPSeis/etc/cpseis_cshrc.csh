#!/bin/csh
#<license>
#-------------------------------------------------------------------------------
# Copyright (c) 2011 Weinman Geoscience
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#-------------------------------------------------------------------------------
#</license>
# Set these environment variables up in your .bashrc file
# CPSEIS_INSTALL_DIR
# THIRDPARTY_DIR
# INTEL_DIR
# --- and Source this file using two arguments:
# ARG1 = your version of mpi (use either "lam" or "mpich2" for now)
# ARG2 = your compiler (use either "gfortran" or "intel91" for now)
# CPSeis expects you to have a version of fftw 2.1.5, mpi, and java
# in your thirdparty directory.  See install_cpseis.sh script in the
# scripts directory for help on where these go.  To install cpseis,
# run "install_cpseis" located in the scripts directory.
# --------------------------------------------------------------------
setenv CPSEIS_HOME $CPSEIS_INSTALL_DIR
setenv CPSEIS_WRAPPERS $CPSEIS_HOME/wrappers
if ( $# == 0 ) then
        echo "Enter which mpi to use in arg 1 (either lam or mpich2)"
        exit 1
endif
setenv MPI $1
#echo $MPI
shift
if ( $# == 0 ) then
        echo "Enter which compiler to use in arg 2 (either gfortran or intel91)"
        exit 1
endif
setenv CPSEIS_COMPILER $1
shift

setenv MACHINE_ARCH `uname -m`
setenv ARCHITECTURE $MACHINE_ARCH
setenv HOSTNAME `uname -n`
setenv HOST $HOSTNAME
setenv CPSEIS_ARCH ${MACHINE_ARCH}_${CPSEIS_COMPILER}_${MPI}
#echo $CPSEIS_ARCH
if ( ! $?LD_LIBRARY_PATH ) then
        setenv LD_LIBRARY_PATH ${CPSEIS_INSTALL_DIR}/platforms/${CPSEIS_ARCH}/lib
else
        setenv LD_LIBRARY_PATH ${CPSEIS_INSTALL_DIR}/platforms/${CPSEIS_ARCH}/lib:$LD_LIBRARY_PATH
endif
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:/${CPSEIS_INSTALL_DIR}/wrappers/platforms/${CPSEIS_ARCH}/lib

# set up fftw environment
setenv FFTW_DIR ${THIRDPARTY_DIR}/fftw-2.1.5/platforms/${MACHINE_ARCH}_${CPSEIS_COMPILER}
	#---------- no binaries in fftw package --- setenv PATH $PATH:${FFTW_DIR}/bin
        setenv LD_LIBRARY_PATH ${FFTW_DIR}/lib:$LD_LIBRARY_PATH

#set up compiler environment
#echo $CPSEIS_COMPILER
if ( ${CPSEIS_COMPILER} == intel || $CPSEIS_COMPILER == intel91 ) then
        setenv LD_LIBRARY_PATH ${CPSEIS_INSTALL_DIR}/intel_${MACHINE_ARCH}:${LD_LIBRARY_PATH}
endif
# set up mpi environment
if ( ! $?MPI ) then
	echo "NO MPI"
endif
if ( $MPI == mpich2 ) then
	# set up mpich2 environment
        setenv MPICH_DIR ${THIRDPARTY_DIR}/mpich2-1.1/platforms/${MACHINE_ARCH}_${CPSEIS_COMPILER}
        setenv PATH ${MPICH_DIR}/bin:$PATH
        setenv LD_LIBRARY_PATH ${MPICH_DIR}/lib:$LD_LIBRARY_PATH
        setenv CPSEIS_C_COMPILER mpicc
        setenv CPSEIS_F90_COMPILER mpif90
endif
if ( $MPI == lam ) then
	# set up lam-mpi environment
        setenv LAM_DIR ${THIRDPARTY_DIR}/lam-7.0.6/platforms/${MACHINE_ARCH}_${CPSEIS_COMPILER}
        setenv PATH ${LAM_DIR}/bin:$PATH
        setenv LD_LIBRARY_PATH ${LAM_DIR}/lib:$LD_LIBRARY_PATH
        if ( $CPSEIS_COMPILER == intel91 ) then
                setenv CPSEIS_C_COMPILER icc
                setenv CPSEIS_F90_COMPILER ifort
        else
                setenv CPSEIS_C_COMPILER gcc
                setenv CPSEIS_F90_COMPILER gfortran
        endif
endif

# set up java environment
setenv JAVA_DIRECTORY ${THIRDPARTY_DIR}/jdk/platforms/${CPSEIS_ARCH}
setenv PATH ${JAVA_DIRECTORY}/bin:$PATH
setenv JAVA_HOME ${JAVA_DIRECTORY}

#setenv CPSEIS_INSTALL_DIR ${HOME}/cpseis
setenv CPSEIS_PLATFORM ${CPSEIS_INSTALL_DIR}/platforms/${CPSEIS_ARCH}

if ( -e ${CPSEIS_INSTALL_DIR}/etc/setup_cpseis_environment.csh ) then
	#echo "Found setup"
	source ${CPSEIS_INSTALL_DIR}/etc/setup_cpseis_environment.csh
endif

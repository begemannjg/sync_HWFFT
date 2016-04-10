/* -*- c++ -*- */

#define SYNC_FFT_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "sync_fft_swig_doc.i"

%{
#include "sync_fft/hwfft.h"
%}


%include "sync_fft/hwfft.h"
GR_SWIG_BLOCK_MAGIC2(sync_fft, hwfft);

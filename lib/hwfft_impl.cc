/* -*- c++ -*- */
/* 
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include <cstdio>
#include "hwfft_impl.h"
#include "fft.c"
static const int MIN_IN = 1;	// mininum number of input streams
static const int MAX_IN = 1;	// maximum number of input streams
static const int MIN_OUT = 1;	// minimum number of output streams
static const int MAX_OUT = 1;	// maximum number of output streams

namespace gr {
  namespace sync_fft {

    hwfft::sptr
    hwfft::make(int fft_size, bool direction, int scale)
    {
      return gnuradio::get_initial_sptr
        (new hwfft_impl(fft_size, direction, scale));
    }

    /*
     * The private constructor
     */
    hwfft_impl::hwfft_impl(int fft_size, bool direction, int scale)
      : gr::sync_block("hwfft",
            gr::io_signature::make(MIN_IN, MAX_IN, sizeof(float)), //float input
            gr::io_signature::make(MIN_OUT, MAX_OUT, sizeof(float))), //float output
			fftsizeIN(fft_size), dirIN((int)direction), scaleIN(scale) //get user input and save for input to function
    {}
    /*
     * Our virtual destructor.
     */
    hwfft_impl::~hwfft_impl()
    {
    }

    int
    hwfft_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      float *in = (float *) input_items[0];
      float *out = (float *) output_items[0];
	  int retval; // test that fft func is successful 
	  
      // Do signal processing for N output
      for(int i = 0; i < noutput_items; i++) {
		fft(in, out, fftsizeIN, dirIN, scaleIN); 
			//printf("Return = %d\n", retval); //return 0 for succesful and 2 for mmap failures
			//printf("FFT SIZE %d\n", fftsizeIN);
			//printf("DIRECTION %d\n", dirIN);
			//printf("SCALE %d\n", scaleIN); 
      }//end loop
	
      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace sync_fft */
} /* namespace gr */


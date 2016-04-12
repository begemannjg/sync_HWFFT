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


#ifndef INCLUDED_SYNC_FFT_HWFFT_H
#define INCLUDED_SYNC_FFT_HWFFT_H

#include <sync_fft/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace sync_fft {

    /*!
     * \brief <+description of block+>
     * \ingroup sync_fft
     *
     */
    class SYNC_FFT_API hwfft : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<hwfft> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of sync_fft::hwfft.
       *
       * To avoid accidental use of raw pointers, sync_fft::hwfft's
       * constructor is in a private implementation
       * class. sync_fft::hwfft::make is the public interface for
       * creating new instances.
       */
      static sptr make(int fft_size, bool direction, int scale);
    };

  } // namespace sync_fft
} // namespace gr

#endif /* INCLUDED_SYNC_FFT_HWFFT_H */


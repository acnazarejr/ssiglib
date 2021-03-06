/*L*****************************************************************************
*
*  Copyright (c) 2015, Smart Surveillance Interest Group, all rights reserved.
*
*  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
*
*  By downloading, copying, installing or using the software you agree to this
*  license. If you do not agree to this license, do not download, install, copy
*  or use the software.
*
*                Software License Agreement (BSD License)
*             For Smart Surveillance Interest Group Library
*                         http://ssig.dcc.ufmg.br
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*    1. Redistributions of source code must retain the above copyright notice,
*       this list of conditions and the following disclaimer.
*
*    2. Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*
*    3. Neither the name of the copyright holder nor the names of its
*       contributors may be used to endorse or promote products derived from
*       this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************L*/


#ifndef _SSIG_DESCRIPTORS_LBP_FEATURES_HPP_
#define _SSIG_DESCRIPTORS_LBP_FEATURES_HPP_

#include "descriptors_defs.hpp"
#include "descriptor_2d.hpp"

namespace ssig {

class LBP : public Descriptor2D{
 public:
  DESCRIPTORS_EXPORT LBP(const cv::Mat& input);
  DESCRIPTORS_EXPORT LBP(const cv::Mat& input, const LBP& descriptor);
  DESCRIPTORS_EXPORT LBP(const LBP& descriptor);
  DESCRIPTORS_EXPORT virtual ~LBP(void) = default;


  DESCRIPTORS_EXPORT cv::Mat_<int> getKernel() const;

  DESCRIPTORS_EXPORT void setKernel(const cv::Mat_<int>& kernel);

  DESCRIPTORS_EXPORT void getLbpImage(cv::Mat& output) const;

 protected:
  DESCRIPTORS_EXPORT void read(const cv::FileNode& fn) override;
  DESCRIPTORS_EXPORT void write(cv::FileStorage& fs) const override;
  DESCRIPTORS_EXPORT void beforeProcess() override;
  DESCRIPTORS_EXPORT void extractFeatures(
    const cv::Rect& patch,
    cv::Mat& output) override;

  DESCRIPTORS_EXPORT bool inValidRange(const int i, const int j) const;

 private:
  DESCRIPTORS_EXPORT void setDefaultKernel();
  // private members
cv::Mat_<uchar> mBinaryPattern;
cv::Mat_<int> mKernel;
};

}  // namespace ssig

#endif  // !_SSIG_DESCRIPTORS_LBP_FEATURES_HPP_

/*
 * Software License Agreement (BSD License)
 *
 *  Point Cloud Library (PCL) - www.pointclouds.org
 *  Copyright (c) 2010-2011, Willow Garage, Inc.
 *
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id$
 *
 */
#ifndef PCL_REGISTRATION_TRANSFORMATION_VALIDATION_H_
#define PCL_REGISTRATION_TRANSFORMATION_VALIDATION_H_

#include <pcl/correspondence.h>
#include <pcl/features/feature.h>
#include <pcl/common/transforms.h>
#include <pcl/registration/correspondence_types.h>

namespace pcl
{
  namespace registration
  {
    /** \brief TransformationValidation represents the base class for methods
      * that validate the correctness of a transformation found through \ref TransformationEstimation.
      *
      * The inputs for a validation estimation can take any or all of the following:
      *
      *   - source point cloud
      *   - target point cloud
      *   - estimated transformation between source and target
      *
      * The output is in the form of a score or a confidence measure.
      *
      * \author Radu B. Rusu
      * \ingroup registration
      */
    template <typename PointSource, typename PointTarget>
    class TransformationValidation
    {
      public:
        TransformationValidation () {};
        virtual ~TransformationValidation () {};

        /** \brief Validate the given transformation with respect to the input cloud data, and return a score.
          *
          * \param[in] cloud_src the source point cloud dataset
          * \param[in] cloud_tgt the target point cloud dataset
          * \param[out] transformation_matrix the resultant transformation matrix
          *
          * \return the score or confidence measure for the given
          * transformation_matrix with respect to the input data
          */
        virtual double
        validateTransformation (
            const pcl::PointCloud<PointSource> &cloud_src,
            const pcl::PointCloud<PointTarget> &cloud_tgt,
            const Eigen::Matrix4f &transformation_matrix) = 0;


        typedef boost::shared_ptr<TransformationValidation<PointSource, PointTarget> > Ptr;
        typedef boost::shared_ptr<const TransformationValidation<PointSource, PointTarget> > ConstPtr;
    };
  }
}

#endif /* PCL_REGISTRATION_TRANSFORMATION_VALIDATION_H_ */
/******************************************************************************
Copyright (c) 2021, Farbod Farshidian. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

 * Neither the name of the copyright holder nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

#pragma once

#include <array>
#include <cstddef>

#include <ocs2_core/Types.h>

namespace ocs2 {
namespace legged_robot {

template <typename T>
using feet_array_t = std::array<T, 4>;

using contact_flag_t = feet_array_t<bool>;

using vector3_t = Eigen::Matrix<scalar_t, 3, 1>;
using vector5_t = Eigen::Matrix<scalar_t, 5, 1>;
using vector6_t = Eigen::Matrix<scalar_t, 6, 1>;

using matrix3_t = Eigen::Matrix<scalar_t, 3, 3>;
using matrix35_t = Eigen::Matrix<scalar_t, 3, 5>;
using matrix65_t = Eigen::Matrix<scalar_t, 6, 5>;
using matrix56_t = Eigen::Matrix<scalar_t, 5, 6>;
using quaternion_t = Eigen::Quaternion<scalar_t>;

using vectorf_t = Eigen::Matrix<float, Eigen::Dynamic, 1>;
using vector3f_t = Eigen::Matrix<float, 3, 1>;
using vector5f_t = Eigen::Matrix<float, 5, 1>;
using vector6f_t = Eigen::Matrix<float, 6, 1>;

using matrixf_t = Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic>;
using matrix3f_t = Eigen::Matrix<float, 3, 3>;
using matrix35f_t = Eigen::Matrix<float, 3, 5>;
using matrix65f_t = Eigen::Matrix<float, 6, 5>;

}  // namespace legged_robot
}  // namespace ocs2

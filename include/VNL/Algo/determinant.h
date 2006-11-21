// This is vxl/VNL/algo/determinant.h
#ifndef vnl_algo_determinant_h_
#define vnl_algo_determinant_h_
/**
* \file
* \brief calculates the determinant of a matrix

* \author fsm@robots.ox.ac.uk
*
*  Evaluation of determinants of any size. For small
*  matrices, will use the direct routines (no netlib)
*  but for larger matrices, a matrix decomposition
*  such as SVD or QR will be used.
*
   \verbatim
   Modifications
    dac (Manchester) 26/03/2001: tidied up documentation
     Feb.2002 - Peter Vanroose - brief doxygen comment placed on single line
   \endverbatim
*/

#include <VNL/matrix.h>


namespace VNL {

/** direct evaluation for 2x2 matrix.
*/
  template <class T> T Determinant(T const *row0,
				   T const *row1);
  
/** direct evaluation for 3x3 matrix.
*/
  template <class T> T Determinant(T const *row0,
				   T const *row1,
				   T const *row2);
  
/** direct evaluation for 4x4 matrix.
*/
  template <class T> T Determinant(T const *row0,
				   T const *row1,
				   T const *row2,
				   T const *row3);
  
/** evaluation using direct methods for sizes of 2x2, 3x3, and 4x4 or qr decompostion for other matrices.
*/
  template <class T>
  T Determinant(VNL::Matrix<T> const &M, bool balance = false);

}; // End namespace VNL

#define VNL_DETERMINANT_INSTANTIATE(T) \
extern "you must include VNL/algo/determinant.t first"

#endif // vnl_algo_determinant_h_
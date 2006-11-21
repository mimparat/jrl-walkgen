// This is vxl/VNL/matrix_ref.h
#ifndef vnl_matrix_ref_h_
#define vnl_matrix_ref_h_
#ifdef VCL_NEEDS_PRAGMA_INTERFACE
#pragma interface
#endif
/**
* \file
* \brief vnl_matrix reference to user-supplied storage.

*
* \author Andrew W. Fitzgibbon, Oxford RRG
* \date   04 Aug 96
*
   \verbatim
   Modifications:
    Documentation updated by Ian Scott 12 Mar 2000
     Feb.2002 - Peter Vanroose - brief doxygen comment placed on single line
   \endverbatim
*
*/

#include <new>
#include <VNL/matrix.h>

namespace VNL {

/** vnl_matrix reference to user-supplied storage.
*    vnl_matrix_ref is a vnl_matrix for which the data space has been
*    supplied externally.  This is useful for two main tasks:
*    (a) Treating some row-based "C" matrix as a vnl_matrix in order to
*    perform vnl_matrix operations on it.
*    (b) Declaring a vnl_matrix that uses stack-based storage for the
*    matrix (See MatrixFixed).  Note however that the rows are still allocated
*    on the heap.  See MatrixFixed for a fully stack-based solution.
*
*    This is a dangerous class.  I believe that I've covered all the bases, but
*    it's really only intended for interfacing with the Fortran routines.
*
*    The big warning is that returning a vnl_matrix_ref pointer will free non-heap
*    memory if deleted through a vnl_matrix pointer.  This should be
*    very difficult though, as vnl_matrix_ref objects may not be constructed using
*    operator new, and are therefore unlikely to be the unwitting subject
*    of an operator delete.
*/
template <class T>
class MatrixRef : public VNL::Matrix<T>
{
  typedef VNL::Matrix<T> Base;

 public:
  // Constructors/Destructors--------------------------------------------------
  MatrixRef(int m, int n, T *datablck) {
    Base::data = VNL::CVector<T>::AllocateTptr(m);
    for (int i = 0; i < m; ++i)
      Base::data[i] = datablck + i * n;
    Base::num_rows = m;
    Base::num_cols = n;
  }
  ~MatrixRef() {
    Base::data[0] = 0; // Prevent base dtor from releasing our memory
  }

 private:
  // Private operator new because deleting a pointer to
  // one of these through a baseclass pointer will attempt
  // to free this in-class memory.
  // Therefore disallow newing of these -- if you're paying for
  // one malloc, you can afford three.
// fsm: This was wrong for two reasons:
//  1. operator new may not return a null pointer.
//  2. it should be enabled for compilers that need it,
//     not disabled for compilers that don't need it.
//#if !defined(VCL_GCC_295)
//  void* operator new(size_t) { return 0; }
//#endif

 private:
/** Resizing is disallowed.
*/
  bool resize (unsigned int, unsigned int) { return false; }


/** Copy constructor from vnl_matrix<T> is disallowed.
* (because it would create a non-const alias to the matrix)
*/
  MatrixRef(VNL::Matrix<T> const &) {}


/** Copy constructor and assignment operator are disallowed.
* You can't assign one of these from a matrix, cos' you don't have any space
*/
  MatrixRef(MatrixRef<T> const &) {}
  MatrixRef<T>& operator=(VNL::Matrix<T> const &) { return *this; }
};


}; // End namespace VNL

#endif // MatrixRef_h_
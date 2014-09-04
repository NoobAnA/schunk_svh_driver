// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Klaus Uhl <uhl@fzi.de>
 * \date    2011-05-31
 *
 */
//----------------------------------------------------------------------
#ifndef ICL_CORE_THREAD_T_RWLOCK_H_INCLUDED
#define ICL_CORE_THREAD_T_RWLOCK_H_INCLUDED

#include <icl_core/Deprecate.h>

#include "icl_core_thread/RWLock.h"

namespace icl_core {
namespace thread {

typedef ICL_CORE_VC_DEPRECATE RWLock tRWLock ICL_CORE_GCC_DEPRECATE;

}
}

#endif
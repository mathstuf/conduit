//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Copyright (c) 2014-2015, Lawrence Livermore National Security, LLC.
// 
// Produced at the Lawrence Livermore National Laboratory
// 
// LLNL-CODE-666778
// 
// All rights reserved.
// 
// This file is part of Conduit. 
// 
// For details, see: http://scalability-llnl.github.io/conduit/.
// 
// Please also read conduit/LICENSE
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
// * Redistributions of source code must retain the above copyright notice, 
//   this list of conditions and the disclaimer below.
// 
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the disclaimer (as noted below) in the
//   documentation and/or other materials provided with the distribution.
// 
// * Neither the name of the LLNS/LLNL nor the names of its contributors may
//   be used to endorse or promote products derived from this software without
//   specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL LAWRENCE LIVERMORE NATIONAL SECURITY,
// LLC, THE U.S. DEPARTMENT OF ENERGY OR CONTRIBUTORS BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
// DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
// IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//-----------------------------------------------------------------------------
///
/// file: Core.cpp
///
//-----------------------------------------------------------------------------
#include "Core.hpp"


//-----------------------------------------------------------------------------
// conduit includes
//-----------------------------------------------------------------------------
#include "Node.hpp"

// Note: This header is only needed a compile time.
#include "Conduit_License.hpp"

//-----------------------------------------------------------------------------
// -- begin conduit:: --
//-----------------------------------------------------------------------------
namespace conduit
{


//---------------------------------------------------------------------------//
std::string
about()
{
    Node n;
    about(n);
    return n.to_json();
}

//---------------------------------------------------------------------------//
void
about(Node &n)
{
    n.reset();
    n["version"] = "{alpha}";
    n["license"] = CONDUIT_LICENSE_TEXT;
    
    // TODO: include compiler info, etc ?

    // Type Info Map
    Node &nn = n["native_typemap"];

    // ints
#ifdef CONDUIT_INT8_NATIVE_TYPENAME
    nn["int8"] = CONDUIT_INT8_NATIVE_TYPENAME;
#else
    nn["int8"] = "<unmapped>";
#endif
#ifdef CONDUIT_INT16_NATIVE_TYPENAME
    nn["int16"] = CONDUIT_INT16_NATIVE_TYPENAME;
#else
    nn["int16"] = "<unmapped>";
#endif
#ifdef CONDUIT_INT32_NATIVE_TYPENAME
    nn["int32"] = CONDUIT_INT32_NATIVE_TYPENAME;
#else
    nn["int32"] = "<unmapped>";
#endif
#ifdef CONDUIT_INT64_NATIVE_TYPENAME
    nn["int64"] = CONDUIT_INT64_NATIVE_TYPENAME;
#else
    nn["int64"] = "<unmapped>";
#endif

    // unsigned ints
#ifdef CONDUIT_UINT8_NATIVE_TYPENAME
    nn["uint8"] = CONDUIT_UINT8_NATIVE_TYPENAME;
#else
    nn["uint8"] = "<unmapped>";
#endif
#ifdef CONDUIT_UINT16_NATIVE_TYPENAME
    nn["uint16"] = CONDUIT_UINT16_NATIVE_TYPENAME;
#else
    nn["uint16"] = "<unmapped>";
#endif
#ifdef CONDUIT_UINT32_NATIVE_TYPENAME
    nn["uint32"] = CONDUIT_UINT32_NATIVE_TYPENAME;
#else
    nn["uint32"] = "<unmapped>";
#endif
#ifdef CONDUIT_UINT64_NATIVE_TYPENAME
    nn["uint64"] = CONDUIT_UINT64_NATIVE_TYPENAME;
#else
    nn["uint64"] = "<unmapped>";
#endif

    // floating points numbers
#ifdef CONDUIT_FLOAT32_NATIVE_TYPENAME
    nn["float32"] = CONDUIT_FLOAT32_NATIVE_TYPENAME;
#else
    nn["float32"] = "<unmapped>";
#endif
#ifdef CONDUIT_FLOAT64_NATIVE_TYPENAME
    nn["float64"] = CONDUIT_FLOAT64_NATIVE_TYPENAME;
#else
    nn["float64"] = "<unmapped>";
#endif

}


}
//-----------------------------------------------------------------------------
// -- end conduit:: --
//-----------------------------------------------------------------------------


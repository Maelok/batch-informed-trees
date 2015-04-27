/*********************************************************************
* Software License Agreement (BSD License)
*
*  Copyright (c) 2014, University of Toronto
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
*   * Neither the name of the University of Toronto nor the names of its
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
*********************************************************************/

/* Authors: Jonathan Gammell */

#ifndef OMPL_GEOMETRIC_PLANNERS_BITSTAR_DATASTRUCTURES_IDGENERATOR_
#define OMPL_GEOMETRIC_PLANNERS_BITSTAR_DATASTRUCTURES_IDGENERATOR_

//For locking the ID generator:
#include <boost/thread/mutex.hpp>

//I am member class of the BITstar class, so I need to include it's definition to be aware of the class BITstar. It has a forward declaration to me.
#include "ompl/geometric/planners/bitstar/BITstar.h"


namespace ompl
{
    namespace geometric
    {
        /** @anchor IdGenerator
        @par Short description
        A class to generate unique IDs for the \ref gVertex "Vertex" and
        \ref gMultigraphVertex "MultigraphVertex" classes.
        */

        /** \brief An ID generator class for vertex IDs.*/
        class BITstar::IdGenerator
        {
        public:
            /** \brief Generator a new id and increment the global/static counter of IDs. */
            static BITstar::vid_t getNewId()
            {
                //STATIC variables:
                //The next ID to be returned:
                static BITstar::vid_t nextId = 0u;
                //The mutex
                static boost::mutex idMutex;

                //Create a scoped mutex copy of idMutex that unlocks when it goes out of scope:
                boost::lock_guard<boost::mutex> lockGuard(idMutex);

                //Return the next id, purposefully post-decrementing:
                return nextId++;
            }
        };
    } //geometric
} //ompl
#endif //OMPL_GEOMETRIC_PLANNERS_BITSTAR_DATASTRUCTURES_IDGENERATOR_

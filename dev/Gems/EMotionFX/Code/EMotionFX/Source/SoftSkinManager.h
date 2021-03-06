/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/

#pragma once

// include the required headers
#include "EMotionFXConfig.h"
#include "BaseObject.h"
//#include "Mesh.h"
//#include "SoftSkinDeformer.h"


namespace EMotionFX
{
    // forward declarations
    class Actor;
    class Mesh;
    class SoftSkinDeformer;

    /**
     * The softskin manager.
     * This manager allows to create optimized softskin deformers, which will run as fast as possible
     * on the hardware of the user. In other words, specialised version of softskin deformers can be
     * created using this class. For example: if the hardware supports SSE, an SSE optimized softskin deformer
     * will be returned, instead of the normal C++ version.
     */
    class EMFX_API SoftSkinManager
        : public BaseObject
    {
        MCORE_MEMORYOBJECTCATEGORY(SoftSkinManager, EMFX_DEFAULT_ALIGNMENT, EMFX_MEMCATEGORY_GEOMETRY_DEFORMERS);

    public:
        /**
         * The constructor.
         * When constructed, the class checks if SSE is available on the hardware.
         */
        static SoftSkinManager* Create();

        /**
         * Creates the softskin deformer, by looking at the hardware capabilities.
         * If SSE is present, an SSE optimized softskinner will be returned, otherwise a normal
         * C++ version.
         * @param mesh The mesh that will be deformed.
         * @result A pointer to the created skin deformer.
         */
        SoftSkinDeformer* CreateDeformer(Mesh* mesh);

    private:
        //bool  mDetectedSSE;   /**< Does the cpu support SSE instructions? */

        /**
         * The constructor.
         * When constructed, the class checks if SSE is available on the hardware.
         */
        SoftSkinManager();
    };
} // namespace EMotionFX

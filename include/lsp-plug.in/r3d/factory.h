/*
 * factory.h
 *
 *  Created on: 24 апр. 2019 г.
 *      Author: sadko
 */

#ifndef LSP_PLUG_IN_R3D_FACTORY_H_
#define LSP_PLUG_IN_R3D_FACTORY_H_

#include <lsp-plug.in/r3d/base.h>
#include <lsp-plug.in/r3d/version.h>
#include <lsp-plug.in/r3d/types.h>

namespace lsp
{
    namespace r3d
    {
        typedef struct factory_t
        {
            /**
             * Get backend metadata
             * @param id backend identifier, starting with 0
             * @return status of operation or NULL if there is no such backend
             */
            const backend_metadata_t        *(* metadata)(factory_t *_this, size_t id);

            /**
             * Create backend
             * @param id backend identifier
             * @return status of operation
             */
            backend_t                       *(* create)(factory_t *_this, size_t id);

        } factory_t;

        /**
         * Factory function prototype
         * @return pointer to the factory function
         */
        typedef factory_t *(* factory_function_t)();
    }
}

#endif /* LSP_PLUG_IN_R3D_FACTORY_H_ */

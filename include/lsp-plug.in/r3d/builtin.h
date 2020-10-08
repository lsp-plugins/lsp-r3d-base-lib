/*
 * Copyright (C) 2020 Linux Studio Plugins Project <https://lsp-plug.in/>
 *           (C) 2020 Vladimir Sadovnikov <sadko4u@gmail.com>
 *
 * This file is part of lsp-r3d-base-lib
 * Created on: 8 окт. 2020 г.
 *
 * lsp-r3d-base-lib is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * lsp-r3d-base-lib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with lsp-r3d-base-lib. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef LSP_PLUG_IN_R3D_REGISTER_H_
#define LSP_PLUG_IN_R3D_REGISTER_H_

#include <lsp-plug.in/r3d/factory.h>

namespace lsp
{
    namespace r3d
    {
        /**
         * This class allows to register built-in factory
         */
        class LSP_SYMBOL_HIDDEN Factory
        {
            private:
                Factory & operator = (const Factory &);

            private:
                static Factory *pList;

                factory_t      *pFactory;
                Factory        *pNext;

            public:
                explicit Factory(factory_t *factory);
                ~Factory();

            public:
                static inline Factory      *list() { return pList;  }
                inline Factory             *next() { return pNext;  }
        };

        /**
         * Macro for simplifying definition of factory export
         */
        #define BUILTIN_FACTORY(symbol, factory)   \
            LSP_SYMBOL_HIDDEN \
            ::lsp::r3d::Factory symbol(factory);
    }
}

#endif /* LSP_PLUG_IN_R3D_REGISTER_H_ */

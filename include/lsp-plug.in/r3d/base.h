/*
 * base_backend.h
 *
 *  Created on: 18 апр. 2019 г.
 *      Author: sadko
 */

#ifndef LSP_PLUG_IN_R3D_BASE_H_
#define LSP_PLUG_IN_R3D_BASE_H_

#include <lsp-plug.in/common/types.h>
#include <lsp-plug.in/r3d/version.h>
#include <lsp-plug.in/r3d/backend.h>

namespace lsp
{
    namespace r3d
    {
        typedef struct base_backend_t: public backend_t
        {
            mat4_t   matProjection;
            mat4_t   matView;
            mat4_t   matWorld;

            color_t     colBackground;

            ssize_t     viewLeft;
            ssize_t     viewTop;
            ssize_t     viewWidth;
            ssize_t     viewHeight;

            static void init_matrix_identity(mat4_t *m);
            static void matrix_mul(mat4_t *r, const mat4_t *s, const mat4_t *m);

            explicit base_backend_t();

            static status_t init(backend_t *handle);
            static void destroy(backend_t *handle);

            static status_t locate(backend_t *handle, ssize_t left, ssize_t top, ssize_t width, ssize_t height);
            static status_t set_matrix(backend_t *handle, matrix_type_t type, const mat4_t *m);
            static status_t get_matrix(backend_t *handle, matrix_type_t type, mat4_t *m);
            static status_t set_bg_color(backend_t *handle, const color_t *color);
            static status_t get_bg_color(backend_t *handle, color_t *color);
            static status_t get_location(backend_t *handle, ssize_t *left, ssize_t *top, ssize_t *width, ssize_t *height);

        } base_backend_t;
    }
}

#endif /* LSP_PLUG_IN_R3D_BASE_H_ */

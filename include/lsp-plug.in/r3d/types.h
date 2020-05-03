/*
 * types.h
 *
 *  Created on: 18 апр. 2019 г.
 *      Author: sadko
 */

#ifndef LSP_PLUG_IN_R3D_TYPES_H_
#define LSP_PLUG_IN_R3D_TYPES_H_

#include <lsp-plug.in/r3d/version.h>
#include <lsp-plug.in/common/types.h>

#define LSP_R3D_FACTORY_FUNCTION_NAME       "lsp_r3d_factory"
#define LSP_R3D_FACTORY_VERSION_NAME        "lsp_r3d_version"

namespace lsp
{
    namespace r3d
    {
        enum window_handle_t
        {
            R3D_WND_HANDLE_X11,
            R3D_WND_HANDLE_WINNT
        };

        enum pixel_format_t
        {
            R3D_PIXEL_RGBA,
            R3D_PIXEL_BGRA,
            R3D_PIXEL_RGB,
            R3D_PIXEL_BGR
        };

        enum matrix_type_t
        {
            R3D_MATRIX_PROJECTION,  /* Projection matrix */
            R3D_MATRIX_VIEW,        /* View matrix */
            R3D_MATRIX_WORLD        /* World matrix for additional transformations if view matrix is not enough */
        };

        enum light_type_t
        {
            R3D_LIGHT_NONE,
            R3D_LIGHT_POINT,
            R3D_LIGHT_DIRECTIONAL,
            R3D_LIGHT_SPOT
        };

        enum primitive_type_t
        {
            R3D_PRIMITIVE_TRIANGLES,
            R3D_PRIMITIVE_WIREFRAME_TRIANGLES,
            R3D_PRIMITIVE_LINES,
            R3D_PRIMITIVE_POINTS,
        };

        enum buffer_flags_t
        {
            R3D_BUFFER_BLENDING     = 1 << 0,
            R3D_BUFFER_LIGHTING     = 1 << 1,
            R3D_BUFFER_NO_CULLING   = 1 << 2
        };

        #pragma pack(push, 1)
        /**
         * The point in the space
         */
        typedef struct dot4_t
        {
            float       x, y, z, w;
        } dot4_t;

        /**
         * The vector
         */
        typedef struct vec4_t
        {
            float       dx, dy, dz, dw;
        } vec4_t;

        /**
         * The color
         */
        typedef struct color_t
        {
            float       r, g, b, a;
        } color_t;

        typedef struct mat4_t
        {
            float       m[16];
        } mat4_t;
        #pragma pack(pop)

        // Basic type: backend
        struct backend_t;

        // Light parameters
        typedef struct light_t
        {
            light_type_t        type;           /* Light type */
            dot4_t              position;       /* Light position */
            vec4_t              direction;      /* Light direction */
            color_t             ambient;        /* Ambient color */
            color_t             diffuse;        /* Diffuse color */
            color_t             specular;       /* Specular color */
            float               constant;       /* Constant attenuation parameter */
            float               linear;         /* Linear attenuation parameter */
            float               quadratic;      /* Quadratic attenuation parameter */
            float               cutoff;         /* Spot cutoff angle */
        } light_t;

        typedef struct buffer_t
        {
            /* Properties */
            primitive_type_t        type;       // Type of primitive
            size_t                  flags;      // Additional flags, see r3d_buffer_flags_t
            float                   width;      // Point size or line width
            size_t                  count;      // Number of elements in buffer

            /* Vertices */
            struct {
                const dot4_t       *data;
                size_t              stride;
            } vertex;

            /* Normals  */
            struct {
                const vec4_t       *data;
                size_t              stride;
            } normal;

            /* Colors */
            struct {
                const color_t      *data;
                size_t              stride;
                color_t             dfl;        // Default color used if color array is not specified
            } color;

            /* Vertex indices (always packed) */
            struct {
                const uint32_t     *data;
            } index;
        } buffer_t;

        /**
         * Export function definition
         * @param dst destination type
         * @param src source type
         */
        template <typename D, typename S>
            inline void export_func(D &dst, const S &src)
            {
                union { D xdst; S xsrc; } uni;
                uni.xsrc    = src;
                dst         = uni.xdst;
            }
    }
}

#endif /* LSP_PLUG_IN_R3D_TYPES_H_ */

/*
 * Copyright (c) 2024, Nico Weber <thakis@chromium.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include "Boxes.h"

namespace Gfx::ISOBMFF {

struct JPEG2000HeaderBox final : public SuperBox {
    BOX_SUBTYPE(JPEG2000HeaderBox);
};

// I.5.3.1 Image Header box
struct JPEG2000ImageHeaderBox final : public Box {
    BOX_SUBTYPE(JPEG2000ImageHeaderBox);

    u32 height { 0 };
    u32 width { 0 };
    u16 num_components { 0 };
    u8 bits_per_component { 0 };
    u8 compression_type { 0 };
    u8 is_colorspace_unknown { 0 };
    u8 contains_intellectual_property_rights { 0 };
};

// I.5.3.3 Colour Specification box
struct JPEG2000ColorSpecificationBox final : public Box {
    BOX_SUBTYPE(JPEG2000ColorSpecificationBox);

    u8 method { 0 };
    i8 precedence { 0 };
    u8 approximation { 0 };
    u32 enumerated_color_space { 0 }; // Only set if method == 1
    ByteBuffer icc_data;              // Only set if method == 2
};

// I.5.3.7 Resolution box
struct JPEG2000ResolutionBox final : public SuperBox {
    BOX_SUBTYPE(JPEG2000ResolutionBox);
};

// I.5.3.7.1 Capture Resolution box
struct JPEG2000CaptureResolutionBox final : public Box {
    BOX_SUBTYPE(JPEG2000CaptureResolutionBox);

    u16 vertical_capture_grid_resolution_numerator { 0 };
    u16 vertical_capture_grid_resolution_denominator { 0 };
    u16 horizontal_capture_grid_resolution_numerator { 0 };
    u16 horizontal_capture_grid_resolution_denominator { 0 };
    i8 vertical_capture_grid_resolution_exponent { 0 };
    i8 horizontal_capture_grid_resolution_exponent { 0 };
};

struct JPEG2000SignatureBox final : public Box {
    BOX_SUBTYPE(JPEG2000SignatureBox);

    u32 signature { 0 };
};

// I.7.3 UUID Info boxes (superbox)
struct JPEG2000UUIDInfoBox final : public SuperBox {
    BOX_SUBTYPE(JPEG2000UUIDInfoBox);
};

// I.7.3.1 UUID List box
struct JPEG2000UUIDListBox final : public Box {
    BOX_SUBTYPE(JPEG2000UUIDListBox);

    Vector<Array<u8, 16>> uuids;
};

}

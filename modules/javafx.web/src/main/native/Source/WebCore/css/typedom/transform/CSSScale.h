/*
 * Copyright (C) 2021 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#if ENABLE(CSS_TYPED_OM)

#include "CSSNumericValue.h"
#include "CSSTransformComponent.h"

namespace WebCore {

template<typename> class ExceptionOr;

class CSSScale : public CSSTransformComponent {
    WTF_MAKE_ISO_ALLOCATED(CSSScale);
public:
    static Ref<CSSScale> create(CSSNumberish&& x, CSSNumberish&& y, std::optional<CSSNumberish>&& z);

    String toString() const final;
    ExceptionOr<Ref<DOMMatrix>> toMatrix() final;

    CSSNumberish x() { return m_x; }
    CSSNumberish y() { return m_y; }
    CSSNumberish z() { return m_z ? *m_z : 0.0; }

    void setX(CSSNumberish&& x) { m_x = WTFMove(x); }
    void setY(CSSNumberish&& y) { m_y = WTFMove(y); }
    void setZ(CSSNumberish&& z) { m_z = WTFMove(z); }

    CSSTransformType getType() const final { return CSSTransformType::Scale; }

private:
    CSSScale(CSSNumberish&& x, CSSNumberish&& y, std::optional<CSSNumberish>&& z);

    CSSNumberish m_x;
    CSSNumberish m_y;
    std::optional<CSSNumberish> m_z;
};

} // namespace WebCore

SPECIALIZE_TYPE_TRAITS_BEGIN(WebCore::CSSScale)
    static bool isType(const WebCore::CSSTransformComponent& transform) { return transform.getType() == WebCore::CSSTransformType::Scale; }
SPECIALIZE_TYPE_TRAITS_END()

#endif

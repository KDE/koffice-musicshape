/*
 *  Copyright (c) 2006 Cyrille Berger <cberger@cberger.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
*/

#ifndef KIS_STRATEGY_COLORSPACE_CMYK_U16_H_
#define KIS_STRATEGY_COLORSPACE_CMYK_U16_H_

#include <KoLcmsColorSpace.h>
#include <KoColorSpaceTraits.h>

#include <pigment_cmyk_u16_export.h>

typedef KoColorSpaceTrait<quint16, 5, 4> CmykU16Traits;

class PIGMENT_CMYK_U16_EXPORT KisCmykU16ColorSpace : public KoLcmsColorSpace<CmykU16Traits>
{
    public:
        KisCmykU16ColorSpace(KoColorSpaceRegistry * parent, KoColorProfile *p);
        virtual bool willDegrade(ColorSpaceIndependence independence) const;
};

class KisCmykU16ColorSpaceFactory : public KoLcmsColorSpaceFactory
{
    public:
        KisCmykU16ColorSpaceFactory() : KoLcmsColorSpaceFactory(TYPE_CMYK5_16, icSigCmykData)
        {
        }
        virtual QString id() const { return "CMYKA16"; }
        virtual QString name() const { return i18n("CMYK (16-bit integer/channel)"); }

        virtual KoColorSpace *createColorSpace(KoColorSpaceRegistry * parent, KoColorProfile *p) { return new KisCmykU16ColorSpace(parent, p); }

        virtual QString defaultProfile() { return "Adobe CMYK"; }
};


#endif

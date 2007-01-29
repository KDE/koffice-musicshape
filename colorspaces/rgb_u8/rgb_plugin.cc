/*
* rgb_plugin.cc -- Part of Krita
*
* Copyright (c) 2004 Boudewijn Rempt (boud@valdyas.org)
*
*  This program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/
#include <stdlib.h>
#include <vector>

#include <QPoint>

#include <klocale.h>
#include <kiconloader.h>
#include <kmessagebox.h>
#include <kstandarddirs.h>
#include <kgenericfactory.h>
#include <KoColorSpaceRegistry.h>
#include <KoBasicHistogramProducers.h>

#include "rgb_plugin.h"
#include "kis_rgb_colorspace.h"

typedef KGenericFactory<RGBPlugin> RGBPluginFactory;
K_EXPORT_COMPONENT_FACTORY( kritargbplugin, RGBPluginFactory( "krita" ) )


RGBPlugin::RGBPlugin(QObject *parent, const QStringList &)
    : QObject(parent)
{
    KoColorSpaceRegistry * f = KoColorSpaceRegistry::instance();

    KoColorSpaceFactory * csFactory = new KisRgbColorSpaceFactory();
    f->add(csFactory);

    KoColorSpace * colorSpaceRGBA = new KisRgbColorSpace(f,
            KoColorSpaceRegistry::instance()->profileByName(csFactory->defaultProfile()) );
    KoHistogramProducerFactoryRegistry::instance()->add(
    new KoBasicHistogramProducerFactory<KoBasicU8HistogramProducer>
                (KoID("RGB8HISTO", i18n("RGB8 Histogram")), colorSpaceRGBA) );
}

RGBPlugin::~RGBPlugin()
{
}

#include "rgb_plugin.moc"

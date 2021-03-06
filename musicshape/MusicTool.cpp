/* This file is part of the KDE project
 * Copyright 2007 Marijn Kruisselbrink <m.Kruisselbrink@student.tue.nl>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */
#include <QPainter>
#include <KTabWidget>

#include <kdebug.h>
#include <klocale.h>
#include <kiconloader.h>

#include <KCanvasBase.h>
#include <KShapeManager.h>

#include "MusicShape.h"

#include "MusicTool.h"
#include <MusicTool.moc>

#include "dialogs/PartsWidget.h"

MusicTool::MusicTool(KCanvasBase* canvas)
    : KToolBase(canvas),
      m_musicshape(0)
{
    setFlags(ToolDoesntHandleMouseEvents);
}

MusicTool::~MusicTool()
{
}

void MusicTool::activate(ToolActivation toolActivation, const QSet<KShape*> &shapes)
{
    Q_UNUSED(toolActivation);
    //kDebug() ;

    foreach (KShape *shape, shapes) {
        m_musicshape = dynamic_cast<MusicShape*>(shape);
        if (m_musicshape)
            break;
    }
    if (!m_musicshape)
    {
        emit done();
        return;
    }
    emit shapeChanged(m_musicshape);
    setCursor(Qt::ArrowCursor);
}

void MusicTool::deactivate()
{
  //kDebug()<<"MusicTool::deactivate";
  m_musicshape = 0;
}

void MusicTool::paint(QPainter& painter, const KViewConverter& viewConverter)
{
    Q_UNUSED(painter);
    Q_UNUSED(viewConverter);
}

void MusicTool::addCommand(QUndoCommand* command)
{
    canvas()->addCommand(command);
}


QWidget * MusicTool::createOptionWidget()
{
    KTabWidget *widget = new KTabWidget();

    PartsWidget *pw = new PartsWidget(this, widget);
    widget->addTab(pw, i18n("Parts"));

    connect(this, SIGNAL(shapeChanged(MusicShape*)), pw, SLOT(setShape(MusicShape*)));

    if (m_musicshape) pw->setShape(m_musicshape);

    return widget;

}

MusicShape* MusicTool::shape()
{
    return m_musicshape;
}


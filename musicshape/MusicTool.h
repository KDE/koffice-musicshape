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
#ifndef MUSIC_TOOL
#define MUSIC_TOOL

#include <KToolBase.h>
class MusicShape;
class QUndoCommand;

class MusicTool : public KToolBase
{
  Q_OBJECT
public:
  explicit MusicTool(KCanvasBase* canvas);
  ~MusicTool();

  virtual void paint(QPainter& painter, const KViewConverter& converter);

    virtual void activate(ToolActivation toolActivation, const QSet<KShape*> &shapes);
  void deactivate();

  void addCommand(QUndoCommand* command);
    MusicShape* shape();
protected:
  /*
   * Create default option widget
   */
    virtual QWidget * createOptionWidget();

protected slots:
signals:
    void shapeChanged(MusicShape* shape);
private:
   MusicShape *m_musicshape;
};

#endif

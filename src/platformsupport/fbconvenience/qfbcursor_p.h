/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QFBCURSOR_P_H
#define QFBCURSOR_P_H

#include <qpa/qplatformcursor.h>

QT_BEGIN_NAMESPACE

class QFbScreen;

class QFbCursor : public QPlatformCursor
{
public:
    QFbCursor(QFbScreen *screen);

    // output methods
    QRect dirtyRect();
    virtual QRect drawCursor(QPainter &painter);

    // input methods
    virtual void pointerEvent(const QMouseEvent &event);
    virtual void changeCursor(QCursor *widgetCursor, QWindow *window);

    virtual void setDirty() { mDirty = true; /* screen->setDirty(QRect()); */ }
    virtual bool isDirty() const { return mDirty; }
    virtual bool isOnScreen() const { return mOnScreen; }
    virtual QRect lastPainted() const { return mPrevRect; }

private:
    void setCursor(const uchar *data, const uchar *mask, int width, int height, int hotX, int hotY);
    void setCursor(Qt::CursorShape shape);
    void setCursor(const QImage &image, int hotx, int hoty);
    QRect getCurrentRect();

    QFbScreen *mScreen;
    QRect mCurrentRect;      // next place to draw the cursor
    QRect mPrevRect;         // last place the cursor was drawn
    bool mDirty;
    bool mOnScreen;
    QPlatformCursorImage *mGraphic;
};

QT_END_NAMESPACE

#endif // QFBCURSOR_P_H


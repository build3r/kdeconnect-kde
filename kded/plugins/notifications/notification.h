/**
 * Copyright 2013 Albert Vaca <albertvaka@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QObject>
#include <QString>

#include "../../networkpackage.h"

class Notification
    : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.kde.kdeconnect.device.notifications.notification")
    Q_PROPERTY(QString internalId READ internalId)
    Q_PROPERTY(QString appName READ appName)
    Q_PROPERTY(QString ticker READ ticker)
    Q_PROPERTY(QString iconPath READ iconPath)
    Q_PROPERTY(bool dismissable READ dismissable)

public:
    Notification(const NetworkPackage& np, const QString& iconPath, QObject* parent);
    virtual ~Notification();

    QString internalId() { return mId; }
    QString appName() { return mAppName; }
    QString ticker() { return mTicker; }
    QString iconPath() { return mIconPath; }
    bool dismissable() { return mDismissable; }

public Q_SLOTS:
    Q_SCRIPTABLE void dismiss();

Q_SIGNALS:
    void dismissRequested(Notification* self);

private:
    QString mId;
    QString mAppName;
    QString mTicker;
    QString mIconPath;
    bool mDismissable;

};

#endif

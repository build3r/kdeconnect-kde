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

#ifndef NOTIFICATIONSDBUSINTERFACE_H
#define NOTIFICATIONSDBUSINTERFACE_H

#include <QDBusAbstractAdaptor>
#include <QHash>
#include <QString>
#include <QStringList>
#include <QDir>

#include "../../device.h"
#include "notification.h"

class NotificationsDbusInterface
    : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.kde.kdeconnect.device.notifications")

public:
    explicit NotificationsDbusInterface(Device* device, QObject *parent);
    virtual ~NotificationsDbusInterface();

    void processPackage(const NetworkPackage& np);

public Q_SLOTS:
    Q_SCRIPTABLE QStringList activeNotifications();
    void dismissRequested(Notification* notification);

Q_SIGNALS:
    Q_SCRIPTABLE void notificationPosted(const QString& publicId);
    Q_SCRIPTABLE void notificationRemoved(const QString& publicId);

private /*methods*/:
    void addNotification(Notification* noti);
    void removeNotification(const QString& internalId);
    QString newId(); //Generates successive identifitiers to use as public ids

private /*attributes*/:
    Device* mDevice;
    QHash<QString, Notification*> mNotifications;
    QHash<QString, QString> mInternalIdToPublicId;
    int mLastId;
    QDir imagesDir;

};

#endif

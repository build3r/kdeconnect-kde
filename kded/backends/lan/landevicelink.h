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

#ifndef LANDEVICELINK_H
#define LANDEVICELINK_H

#include <QObject>
#include <QString>
#include <QTcpSocket>

#include "../devicelink.h"

class SocketLineReader;

class LanDeviceLink
    : public DeviceLink
{
    Q_OBJECT

public:
    LanDeviceLink(const QString& d, LinkProvider* a, QTcpSocket* socket);

    bool sendPackage(NetworkPackage& np);
    bool sendPackageEncrypted(QCA::PublicKey& key, NetworkPackage& np);

private Q_SLOTS:
    void dataReceived();

private:
    SocketLineReader* mSocketLineReader;

};

#endif

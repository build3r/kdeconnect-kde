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

#ifndef BATTERYDBUSINTERFACE_H
#define BATTERYDBUSINTERFACE_H

#include <QDBusAbstractAdaptor>

class BatteryDbusInterface
    : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.kde.kdeconnect.device.battery")

public:
    explicit BatteryDbusInterface(QObject *parent);
    virtual ~BatteryDbusInterface();
    
    Q_SCRIPTABLE int charge() { return mCharge; }
    Q_SCRIPTABLE bool isCharging() { return mIsCharging; }

    void updateValues(bool isCharging, int currentCharge);

Q_SIGNALS:
    Q_SCRIPTABLE void stateChanged(bool charging);  
    Q_SCRIPTABLE void chargeChanged(int charge);

private:
    int mCharge;
    bool mIsCharging : 1;

};

#endif

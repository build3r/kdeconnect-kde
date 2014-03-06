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

#ifndef BATTERYPLUGIN_H
#define BATTERYPLUGIN_H

#include "../kdeconnectplugin.h"

#define PACKAGE_TYPE_BATTERY QLatin1String("kdeconnect.battery")

class BatteryDbusInterface;

class BatteryPlugin
    : public KdeConnectPlugin
{
    Q_OBJECT

public:
    explicit BatteryPlugin(QObject *parent, const QVariantList &args);
    virtual ~BatteryPlugin();

public Q_SLOTS:
    virtual bool receivePackage(const NetworkPackage& np);
    virtual void connected();

private:
    // Keep these values in sync with THRESHOLD* constants in
    // kdeconnect-android:BatteryPlugin.java
    // see README for their meaning
    enum ThresholdBatteryEvent {
        ThresholdNone       = 0,
        ThresholdBatteryLow = 1
    };

    BatteryDbusInterface* batteryDbusInterface;
};

#endif

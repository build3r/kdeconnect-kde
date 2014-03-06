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

#ifndef KDECONNECTKCM_H
#define KDECONNECTKCM_H

#include <QStandardItemModel>
#include <QDBusConnection>

#include <kcmodule.h>
#include <ksharedconfig.h>

#include "libkdeconnect/devicesmodel.h"

class QModelIndex;
class AccountsModel;
class AccountWidget;
class QStackedLayout;
class QItemSelectionModel;
class QDBusInterface;
class DeviceDbusInterface;
class DevicesSortProxyModel;

namespace Ui {
    class KdeConnectKcmUi;
}

class KdeConnectKcm
    : public KCModule
{
    Q_OBJECT
public:
    KdeConnectKcm(QWidget *parent, const QVariantList&);
    virtual ~KdeConnectKcm();

private:
    virtual void save();

private Q_SLOTS:
    void deviceSelected(const QModelIndex& current);
    void requestPair();
    void pluginsConfigChanged();
    void sendPing();
    void browseFilesystem();
    void resetSelection();
    void pairingSuccesful();
    void pairingFailed(const QString& error);
    void unpaired();

private:
    Ui::KdeConnectKcmUi* kcmUi;
    DevicesModel* devicesModel;
    DevicesSortProxyModel* sortProxyModel;
    DeviceDbusInterface* currentDevice;
    QModelIndex currentIndex;

public Q_SLOTS:
    void unpair();
};

#endif

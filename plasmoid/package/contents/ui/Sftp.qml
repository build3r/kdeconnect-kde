/**
 * Copyright 2014 Samoilenko Yuri <kinnalru@gmail.com>
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

import QtQuick 1.1
import org.kde.plasma.core 0.1 as PlasmaCore
import org.kde.plasma.components 0.1 as PlasmaComponents
import org.kde.kdeconnect 1.0

QtObject {

    id: root

    property string deviceId: ""
    property variant device: DeviceDbusInterfaceFactory.create(deviceId)
    property bool available: false

    property bool isMounted: false
    property variant sftp: null
    property variant nested: DBusAsyncResponse {
        id: startupCheck
        onSuccess: (result) ? root.mounted() : root.unmounted()
        onError: root.error(message)
    }

    signal mounted
    signal unmounted
    signal error(string message)

    onMounted: isMounted = true
    onUnmounted: isMounted = false

    function browse() {
        startupCheck.setPendingCall(sftp.startBrowsing())
    }
    
    function unmount() {
        sftp.unmount()
    }

    Component.onCompleted: {
        device.pluginsChanged.connect(pluginsChanged)
        device.pluginsChanged()
    }

    /* Note: magically called by qml */
    onAvailableChanged: {
        if (available) {
            sftp = SftpDbusInterfaceFactory.create(deviceId)

            sftp.mounted.connect(mounted)
            sftp.unmounted.connect(unmounted)

            startupCheck.setPendingCall(sftp.isMounted())
        }
        else {
            sftp = null
        }
    }
    
    function pluginsChanged() {
        var result = DBusResponseWaiter.waitForReply(device.hasPlugin("kdeconnect_sftp"))

        if (result && result != "error") {
            available = true
        }
        else {
            available = false
        }
    }

}

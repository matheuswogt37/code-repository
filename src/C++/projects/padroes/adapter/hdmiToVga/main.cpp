#include "devices/Computer.hpp"
#include "devices/OldMonitor.hpp"
#include "devices/TV.hpp"
#include "interfaces/HDMI.hpp"
#include "interfaces/VGA.hpp"
#include "adapter/HDMItoVGAadapter.hpp"


int main() {

    Computer pc;
    // HDMI *tv = new TV;
    // pc.connectPort(tv);
    VGA *oldMonitorVga = new OldMonitor;
    HDMI *oldMonitor = new HDMItoVGAadapter(oldMonitorVga);
    pc.connectPort(oldMonitor);


    return 0;
}

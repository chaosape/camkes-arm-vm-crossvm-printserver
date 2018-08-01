This application demonstrations a cross vm write from a guest vm to a
seL4 component. The mechanism for communication has been implemented
manually in the vmm using fault handlers. Due to this, the
camkes-vm-arm repository maintained by Data61 must be modified. A repo
manifest to run this application can be found here:
https://github.com/chaosape/camkes-arm-vm-manifest/tree/tk1_ps

The tools directory contains a single c file that provides a
convenient way to communicate a string, through the fault handlers
installed in the vmm, to an seL4 component that echo's the data.
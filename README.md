#**Early alpha version!**

##What is this:
Node-gpu lets you use AMD ADL3 SDK (currently only it) bindings in node.js.
An example application creates online charts of temperature, activity,
fanspeed, core clock and memory clock.

##Build:
    node-waf configure build
    git submodule update --init

##How it works:
Master connects to each Slave and query its either for info (getInfo) or
data (getData), Slave is responding with everything what it can gets,
Master rewrites the response and sends it back to the caller - a Browser.
Browser asks Master every x (default 500) ms for data and draws it on
canvas using flot (https://github.com/flot/flot) charts library.

##About:
Since its early alpha version most of code is going to be rewriten!
If you want to request a feature post an issue.

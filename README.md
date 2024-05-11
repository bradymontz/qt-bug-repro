Repro of a Qt bug on Fedora 40, Qt 6.7.0. 

The rubberband widget leaves pixels behind when these three conditions are true:
1. running on Wayland
2. The display is scaled to 125%
3. the window is maximized (full-screen).

This doesn't happen when scaled 100%, 150%, 175%, or 200%, when the window is any other size (it has to be full-screen). 
It doesn't happen on MacOS (at any scaling factor). 
It doesn't happen on X11 (tested at scaling factor 100% and 200%, I don't have a setup where I can try 125% on X11)

See video Video_2024-05-10_22-33-52.mp4 in this package for a screen capture of it happening. 
